#include <iostream>
#include <ctime>
#include <cstdlib>
#include  <string>
#include <fstream>

using namespace std;

#define ROW 9
#define COLOUMN 9
//these are max size as the given homework the max size 9*9 so i declared an 9x9 array after that
//i operates  according to given puzzle's row column number

void playing(int puzzleAr[ROW][COLOUMN],int row,int colum);
inline void printPuzzle(int puzzleAr[ROW][COLOUMN],int row,int colum);
void playing(int puzzleAr[ROW][COLOUMN],int row,int colum);
bool shiftLeft(int puzzleAr[ROW][COLOUMN],int row,int colum);
bool shiftRight(int puzzleAr[ROW][COLOUMN],int row,int colum);
bool shiftUp(int puzzleAr[ROW][COLOUMN],int row,int colum);
bool shiftDown(int puzzleAr[ROW][COLOUMN],int row,int colum);
void load_puzzle(int puzzleAr[ROW][COLOUMN],string filename,int row, int colum);
int shufflePuzzle(int puzzleAr[ROW][COLOUMN],int row,int colum);
bool check_puzzle(int puzzleAr[ROW][COLOUMN],int row,int colum);
int save_puzzle(int puzzleAr[ROW][COLOUMN],string filename,int row,int colum);
int inversionCounter(int puzzleAr[ROW][COLOUMN],int size);
void arrangePuzzle(int puzzleAr[ROW][COLOUMN],int size);
bool checkSolvability(int puzzleAr[ROW][COLOUMN],int size);
int whereisblank(int puzzleAr[ROW][COLOUMN],int size);
int intelligence(int puzzleAr[ROW][COLOUMN],int row,int colum);
int check_bound(int puzzleAr,int row,int colum);
int findnum(int puzzleAr[ROW][COLOUMN],int y,int x);
int distancesum(int orig_i,int orig_j,int goal_i,int goal_j);
int isequal(int manh_ar[4]);



int main(int argc, char const *argv[]){
	int size;
	srand (time(NULL));		
    int puzzleAr[ROW][COLOUMN];
	auto row=0;
	auto colum=0;
	//if argc that means the user entered an file name
	if(argc==2){
		string filename;
		ifstream rowcol;
		char x;
		rowcol.open(argv[1]);
		//if the file couldn't open give an error message and terminate program
		if(rowcol.fail()){
			cout<<"Enter a VALID name!!!"<<endl;
			exit(-1);
		}	
		else{	
		//it counts number of row and column if user entered an file			
			rowcol.get(x);
			while( rowcol){
				if(x==' ')
					colum++;
				if(x=='\n'){
					row++;
				}
					
			
				rowcol.get(x);
			}
			colum=colum/row+1;//to find column
			
		
			load_puzzle(puzzleAr,argv[1],row,colum);
		}	
		
	}//if arg counter is 1 that means it starts as hw1 puzzle
	else if(argc==1){
		cout <<"Please enter the problem size\n";
		cin>> size;
		row=size;colum=size;
		arrangePuzzle(puzzleAr,size);
			while (checkSolvability(puzzleAr,size) || (check_puzzle(puzzleAr,size,size) == true)) {
				arrangePuzzle(puzzleAr,size);
			}

	}
	
	else if (argc>2)
		cout<<"Enter just one valid file"<<endl;
	
	playing(puzzleAr,row,colum);	

	return 0;


}

//my puzzle arrange function first  fill all array with -1 after that it choses random coordinates
void arrangePuzzle(int puzzleAr[ROW][COLOUMN],int size){
	int fill=1,i=0 ,j=0;
	for ( i=0; i<size; i++){
		for ( j=0; j<size; j++){
			puzzleAr[i][j]=-1;
		}
	}
	
	for (int k = 1; k < size*size; k++) {
		i=(rand()%size);
		j=(rand()%size);
		if(puzzleAr[i][j] == -1){
			puzzleAr[i][j] = fill;
			fill+=1;
		}
		else
			k-=1;
	}

	return ;
}
/*to check solvabilitiy first takes size according to rule
if size is odd
	its solvable if the inversion is even
the inversion number is basically when we put two dimensional array to one d array
we count by start the number by number lower nnumbers (except blank tile) we make it for every nnumber
if size is even
		then the blank is on an even row (counting from bottom) and the number of inversion is odd  is solvable
		and blank is on an odd row (counting from bottom) and number of inversion is even also solvable
*/
bool checkSolvability(int puzzleAr[ROW][COLOUMN],int size){
	int inv_counter = inversionCounter(puzzleAr,size);
	int blankplace=whereisblank(puzzleAr,size);
	if (size%2==1 && inv_counter%2!=0)
		return 1;
	else if(size%2==0 && ((blankplace%2==0 && inv_counter%2==0) || (blankplace%2==1 && inv_counter%2==1)) )
			return 1;
	else
		return 0;
}
//to find blank tile coordinate from whether is it on even-odd row
int whereisblank(int puzzleAr[ROW][COLOUMN],int size){
	int rowcounter=0,flag=0;
	for (int i = size-1; i >= 0 && flag==0; i--) {
		for (int j = size-1; j >= 0 && flag==0; j--) {
			if (puzzleAr[i][j]==-1)
				flag=1;
		}
		rowcounter++;
	}
	return rowcounter;
}
//to convert 2d array to 1d array then it counts the how many number comes (smaller than the number) after that number
//and that process is made for each number except blank tile 
int inversionCounter(int puzzleAr[ROW][COLOUMN],int size){
	int *inversAr = (int*)malloc((size*size)*sizeof(int));
	int counter=0, inverse_counter=0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			inversAr[counter]=puzzleAr[i][j];
			counter++;
		}
	}

	for (int i = 0; i < counter-1; i++) {
		for (int j = i+1; j < counter; j++) {
			if (inversAr[i]&& inversAr[j]&& inversAr[i] > inversAr[j] )
				inverse_counter+=1;
		}
	}
	return inverse_counter;
}
//this fuction makes suffle basically fisr fill all available places start by one then makes random moves
int shufflePuzzle(int puzzleAr[ROW][COLOUMN],int row,int colum){
	int randAction=0,fill=1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colum; j++) {
			if(puzzleAr[i][j] != 0){
				puzzleAr[i][j]=fill;
				fill++;
			}	
		}
	}
	puzzleAr[row-1][colum-1]=-1;

	for (int i = 0; i < row*colum; i++) {
		randAction = (rand()%4)+1;

		if (randAction == 1){
			if (shiftLeft(puzzleAr,row,colum) != true)
				shiftRight(puzzleAr,row,colum);
		}
		else if (randAction == 2){
			if (shiftRight(puzzleAr,row,colum) != true)
				shiftLeft(puzzleAr,row,colum);
		}
		else if (randAction == 3){
			if (shiftUp(puzzleAr,row,colum) != true)
				shiftDown(puzzleAr,row,colum);
		}
		else if (randAction == 4){
			if (shiftDown(puzzleAr,row,colum) != true)
			 shiftUp(puzzleAr,row,colum);
		}
		else
			cout << "May be shuffle has a problem" << '\n';

	}
	/*to check after shuffle there is a solved puzzle :)*/
	if (check_puzzle(puzzleAr,row,colum) == true)
	 	return shufflePuzzle(puzzleAr,row,colum);
	else
		return 0;
}//i read file with ifstream it takes until space and i iput it in a string after that i compare with ascii values and converts them to integer
void load_puzzle(int puzzleAr[ROW][COLOUMN],string filename,int row,int colum){
    string each;
    ifstream inputstream;
	
		
		inputstream.open(filename);

		for(int i=0; i<row; i++){
			for(int j=0; j<colum; j++){
				inputstream >> each;
				if( !(each[0]>=48 && each[0]<=57) )
					puzzleAr[i][j]=-1;
				else if(each[0] == 0 && each[1] == 0)
					puzzleAr[i][j]=0;
				else if(each[0] == 0 && each[1]>48 && each[1]<=57 )
					puzzleAr[i][j]=	(static_cast<int>(each[1]))-48;
				else//if it has two digits it converts first digit and multiply by 10 and add the last digit so thats how i convert them to integer 
					puzzleAr[i][j]=((static_cast<int>(each[0]))-48)*10+(static_cast<int>(each[1])-48);
			}
		}
	inputstream.close();

    return;
}
//it prints puzzle according to row column number
inline void printPuzzle(int puzzleAr[ROW][COLOUMN],int row,int colum){
	for(int i=0; i<row; i++ ){
		for (int j=0; j<colum; j++){
			if (puzzleAr[i][j] > 0)
				cout <<puzzleAr[i][j]<<"\t";
			else if(puzzleAr[i][j]==-1)
				cout <<"bb"<<"\t";
			else if(puzzleAr[i][j]==0)
				cout <<"  "<<"\t";
			else	
				cout <<"xx"<<"\t";
		}
		cout << "\n\n\n";
	}

	return;
}
void playing(int puzzleAr[ROW][COLOUMN],int row, int colum){
    cout <<"Your initial random board is\n";
	string filename;
	ifstream rowcol;
	char move ='k';
	int quit=0;
	int move_counter=0;
	bool check_limit=false;// this variable to check puzzle limits and if user try an invalid move it  dont add to number of moves
	bool check=false;
	/*the loop above for the get an valid puzzle to solve*/



	printPuzzle(puzzleAr,row,colum);
	while (quit != 1 && check==false ) {
		cout <<"Your move: ";
		cin >> move;
		check_limit=0;
		switch (move) {
			case 'L':
			case 'l':
				check_limit=shiftLeft(puzzleAr,row,colum);
				printPuzzle(puzzleAr,row,colum);
				break;
			case 'R':
			case 'r':
				check_limit=shiftRight(puzzleAr,row,colum);
				printPuzzle(puzzleAr,row,colum);
				break;
			case 'U':
			case 'u':
				check_limit=shiftUp(puzzleAr,row,colum);
				printPuzzle(puzzleAr,row,colum);
				break;
			case 'D':
			case 'd':
				check_limit=shiftDown(puzzleAr,row,colum);
				printPuzzle(puzzleAr,row,colum);
				break;
			case 'I':
			case 'i':
			  check_limit=intelligence(puzzleAr,row,colum);
				printPuzzle(puzzleAr,row,colum);
				break;
			case 'S':
			case 's':
				shufflePuzzle(puzzleAr,row,colum);
				printPuzzle(puzzleAr,row,colum);
				break;
			case 'Y':
			case 'y':
				cout<<"Enter file name that you want to open"<<endl;
				cin>>filename;
				
				
				rowcol.open(filename);
				char x;
				row=0;
				colum=0;
				rowcol.get(x);
				while( rowcol){
					if(x==' ')
						colum++;
					if(x=='\n'){
						row++;
					}
						
				
					rowcol.get(x);
				}
				colum=colum/row+1;
				rowcol.close();
				
					
    			load_puzzle(puzzleAr,filename,row,colum);
				printPuzzle(puzzleAr,row,colum);
				break;
			case 'E':
			case 'e':
				cout<<"Enter a file name that you want to save current positions"<<endl;
				cin >> filename;
				save_puzzle(puzzleAr,filename,row,colum);
				break;	
			case 'T':
			case 't':
				cout<<"Total number of valid moves "<<move_counter<<endl;
				break;
			case 'V':
			case 'v':
				while(check_puzzle(puzzleAr,row,colum)==false){
					check_limit=intelligence(puzzleAr,row,colum);
					printPuzzle(puzzleAr,row,colum);
				}
				break;		
			case 'Q':
			case 'q':
				quit = 1;
				break;
			default:
				cout << "!INVALID action!!" << '\n';
				break;
		}//it counts number of valid moves
		if (((move == 'L' || move =='l') || (move == 'R' || move =='r') || (move == 'U' || move =='u') || (move == 'D' || move =='d')) && check_limit== true ) {
			move_counter++;
		}
		check =check_puzzle(puzzleAr,row,colum);
		if(check==true)	
			cout<<"Total number of moves "<<move_counter<<endl;
	}
	//below end of the move check the puzzle solved or not

	return;
}//i write with ofstreamand if -1 thatmeans its blank tile if 0 it writer 00 and if itsnot last column it put whitespace after each string
//and if it has one digit it add 0 the first index of sring thats how i save puzzle
int save_puzzle(int puzzleAr[ROW][COLOUMN],string filename,int row,int colum){
	ofstream savefile;
	savefile.open(filename);
	for(int i=0; i<row; i++){
			for(int j=0; j<colum; j++){
				if( puzzleAr[i][j]==-1 )
					savefile<<"bb";
				else if(puzzleAr[i][j]==0)
					savefile<<"00";
				else if(puzzleAr[i][j] != 0 && puzzleAr[i][j] <10 )
					savefile<<"0"<<puzzleAr[i][j];					
				else	
					savefile<<puzzleAr[i][j];
				if (j!=colum-1)
				{
					savefile<<" ";
				}
			}
			savefile<<endl;	
	}
	savefile.close();
	return 0;

}//the direction movement functions if the move is not available they returns false
bool shiftLeft(int puzzleAr[ROW][COLOUMN],int row,int colum){
	int flag=0,i=0,j=0;
	for (i = 0; i < row && flag == 0; i++) {
		for (j = 0; j < colum && flag == 0; j++) {
			if (puzzleAr[i][j]==-1)
				flag =1;
		}
	}
	i-=1;
	j-=1;
	if((puzzleAr[i][j-1] != 0) && j != 0){
		puzzleAr[i][j]=puzzleAr[i][(j-1)];
		puzzleAr[i][(j-1)]=-1;
	}
	else{
			cout << "!Wrong move!!" << '\n';
			return false;
	}
	return true;
}
bool shiftRight(int puzzleAr[ROW][COLOUMN],int row,int colum){
	int flag=0,i=0,j=0;
	for (i = 0; i < row && flag == 0; i++) {
		for (j = 0; j < colum && flag == 0; j++) {
			if (puzzleAr[i][j]==-1)
				flag =1;
		}
	}
	i-=1;
	j-=1;
	if((puzzleAr[i][j+1] != 0) && j != colum-1){
		puzzleAr[i][j]=puzzleAr[i][(j+1)];
		puzzleAr[i][(j+1)]=-1;
	}
	else{
			cout << "!Wrong move!!" << '\n';
			return false;
	}
	return true;
}
bool shiftUp(int puzzleAr[ROW][COLOUMN],int row,int colum){
	int flag=0,i=0,j=0;
	for (i = 0; i < row && flag == 0; i++) {
		for (j = 0; j < colum && flag == 0; j++) {
			if (puzzleAr[i][j]==-1)
				flag =1;
		}
	}
	i-=1;
	j-=1;
	if((puzzleAr[i-1][j] != 0) && i != 0){
		puzzleAr[i][j]=puzzleAr[i-1][j];
		puzzleAr[i-1][j]=-1;
	}
	else{
			cout << "!Wrong move!!" << '\n';
			return false;
	}
	return true;
}
bool shiftDown(int puzzleAr[ROW][COLOUMN],int row,int colum){
	int flag=0,i=0,j=0;
	for (i = 0; i < row && flag == 0; i++) {
		for (j = 0; j < colum && flag == 0; j++) {
			if (puzzleAr[i][j]==-1)
				flag =1;
		}
	}
	i-=1;
	j-=1;
	if((puzzleAr[i+1][j] != 0) && i!= row-1){
		puzzleAr[i][j]=puzzleAr[i+1][j];
		puzzleAr[i+1][j]=-1;
	}
	else{
			cout << "!Wrong move!!" << '\n';
			return false;
	}
	return true;
}//it checks puzzle i keep  a value if it see a number other than zero and -1 it increases 1 and compare with number in puzzle 
bool check_puzzle(int puzzleAr[ROW][COLOUMN],int row,int colum){
	int compare=1;
	int flag =0;
	int i=0,j=0;
	bool check=false;
	for(i=0; i<row && flag==0; i++){
		for(j=0; j<colum && flag==0; j++){
			if( puzzleAr[i][j] == 0 )
				flag=0;
			else if( puzzleAr[i][j] != 0 && puzzleAr[i][j] == compare){
				check=true;
				flag=0;
				compare++;
				if(puzzleAr[row-1][colum-1]== -1){
					flag==1;
					check=true;
				}	
			}
			else if(i==row-1 && j==colum-1)
				flag=1;	
			else{
				check=false;
				flag=1;
			}	
		}
	}
	if(i==row && j==colum)
		cout<<"Problem Solved!"<<endl;
	return check;
}
/*following 100 row to determine what numbers are side of the blank tile and find the numbers then find the numbers final coordinates which they are should be
and it substracts final position coordinates and original coordinates
then it calculates how many (min)number of move makes to go final place */
int intelligence(int puzzleAr[ROW][COLOUMN],int row,int colum){
	int flag=0;
	int randshift=0;
	int manh_ar[4];
	int arraycounter=1;
	int down_i=0,down_j=0,up_i=0,up_j=0,left_i=0,left_j=0,right_i=0,right_j=0;
	int goaldown_i=0,goaldown_j=0,goalup_i=0,goalup_j=0,goalleft_i=0,goalleft_j=0,goalright_i=0,goalright_j=0;
	int downnum=0,upnum=0,leftnum=0,rightnum=0;
	int manh_d=0,manh_u=0,manh_l=0,manh_r=0;
	int i = 0,j = 0;
	int temp;
	int fill=1;
	int goalPuzzle[ROW][COLOUMN];
	int motionx=0,motiony=0;
	int firstx,firsty;

		for (int i = 0; i < row; i++) {
		for (int j = 0; j < colum; j++) {
			if(goalPuzzle[i][j] != 0){
				goalPuzzle[i][j]=fill;
				fill++;
			}	
		}
	}
	goalPuzzle[row-1][colum-1]=-1;
		for ( i = 0; i < row && flag==0; i++) {
			for ( j = 0; j < colum &&flag==0; j++) {
				if(puzzleAr[i][j]==-1)
					flag=1;

			}
		}
		i-=1;j-=1;
		firstx=i;firsty=j;
		flag=0;
		down_i=i+1; up_i=i-1; left_i=i; right_i=i;
		down_j=j; up_j=j; left_j=j-1; right_j=j+1;

		if (down_i != row)
			downnum=findnum(puzzleAr,down_i,down_j);

		if (up_i != -1)
			upnum=findnum(puzzleAr,up_i,up_j);

		if (left_j != -1)
			leftnum=findnum(puzzleAr,left_i,left_j);

		if (right_j != colum)
			rightnum=findnum(puzzleAr,right_i,right_j);

	for ( i = 0; i < row && flag == 0 && downnum!=0; i++) {
		for ( j = 0; j < colum && flag == 0; j++) {
			if (goalPuzzle[i][j]==downnum)
			flag=1;
		}
	}
	i-=1;	j-=1;
	goaldown_i=i;goaldown_j=j;
	flag=0;
	for ( i = 0; i < row && flag == 0 && upnum!=0; i++) {
		for ( j = 0; j < colum && flag == 0; j++) {
			if (goalPuzzle[i][j]==upnum)
			flag=1;
		}
	}
	i-=1;j-=1;
	goalup_i=i;goalup_j=j;
	flag=0;
	for ( i = 0; i < row && flag == 0 && leftnum!=0; i++) {
		for ( j = 0; j < colum && flag == 0; j++) {
			if (goalPuzzle[i][j]==leftnum)
			flag=1;
		}
	}
	i-=1;j-=1;
	goalleft_i=i;goalleft_j=j;
	flag=0;
	for ( i = 0; i < row && flag == 0 && rightnum!=0; i++) {
		for ( j = 0; j < colum && flag == 0; j++) {
			if (goalPuzzle[i][j]==rightnum)
			flag=1;
		}
	}
	i-=1;j-=1;
	goalright_i=i;goalright_j=j;
	flag=0;
	if(downnum != 0)
		manh_d=distancesum(down_i,down_j,goaldown_i,goaldown_j);

	if(upnum != 0)
		manh_u=distancesum(up_i,up_j,goalup_i,goalup_j);

	if(leftnum != 0)
		manh_l=distancesum(left_i,left_j,goalleft_i,goalleft_j);

	if(rightnum != 0)
		manh_r=distancesum(right_i,right_j,goalright_i,goalright_j);

	if (downnum == 0 && manh_d==0) 
		manh_ar[0]=manh_d+row*row*row;
	
	if (leftnum == 0 && manh_l==0) 
		manh_ar[1]=manh_l+row*row*row;
	
	if (rightnum == 0 && manh_r==0)
		manh_ar[2]=manh_r+row*row*row;
	
	if (upnum == 0 && manh_u==0) 
		manh_ar[3]=manh_u+row*row*row;
	



/*after that it makes move min manhattandistance and if the distances are equal more then one tile
it makes move randomly i find the manhattan distance algorithm but i couldnt implement it well*/
	arraycounter=isequal(manh_ar);
	if(arraycounter < 2){
		if (manh_r<manh_l && manh_r<manh_u && manh_r<manh_d && rightnum !=0)
			shiftRight(puzzleAr, row,colum);

		if (manh_l<manh_r && manh_l<manh_u && manh_l<manh_d && leftnum !=0)
			shiftLeft(puzzleAr, row,colum);

		if (manh_u<manh_r && manh_u<manh_l && manh_u<manh_d && upnum !=0)
			shiftUp(puzzleAr, row,colum);

		if (manh_d<manh_r && manh_d<manh_l && manh_d<manh_u && downnum !=0)
			shiftDown(puzzleAr,row,colum);

	}
	else if(arraycounter>1){
		
			if (manh_d > manh_l ){
				
				if (shiftDown(puzzleAr,row,colum)==false)
					shiftLeft(puzzleAr,row,colum);
			}
		
			else if (manh_d >manh_r ){
			
				if (shiftDown(puzzleAr,row,colum)==false)
					shiftRight(puzzleAr,row,colum);
			}

		
			else if (manh_d > manh_u){
			
				if (shiftDown(puzzleAr,row,colum)== false)
					shiftUp(puzzleAr,row,colum);
			}
		
			else if (manh_l>manh_r ){
			
				if (shiftLeft(puzzleAr,row,colum)==false)
					shiftRight(puzzleAr,row,colum);
			}
		
			else if (manh_u < manh_l ){
			
				if (shiftLeft(puzzleAr,row,colum)==false)
					shiftUp(puzzleAr,row,colum);
			}
		
			else if (manh_u < manh_r ){
				
				if (shiftRight(puzzleAr,row,colum)==false)
					shiftUp(puzzleAr,row,colum);
			}
	
	}
	else{
		randshift=(rand()%4)+1;
		switch (randshift)
		{
		case 1:
			shiftDown(puzzleAr,row,colum);
			break;
		case 2:
			shiftLeft(puzzleAr,row,colum);
			break;
		case 3:
			shiftUp(puzzleAr,row,colum);
			break;
		case 4:
			shiftRight(puzzleAr,row,colum);
			break;			
		
		default:
			cout<<"sorry there is nothing to do with intelligence";
			break;
		}
	
	}




//put them in an array and sort them so i can know is there an equal moves
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3-i; j++) {
			if (manh_ar[j]>manh_ar[j+1]) {
				temp=manh_ar[j];
				manh_ar[j]=manh_ar[j+1];
				manh_ar[j+1]=temp;
			}
		}
	}


	for ( i = 0; i < row && flag==0; i++) {
			for ( j = 0; j < colum &&flag==0; j++) {
				if(puzzleAr[i][j]==-1)
					flag=1;

			}
		}
		i-=1;j-=1;
	cout<<"Intelligence chosed: "<<endl;
	motionx=firstx-i;	
	motiony=firsty-j;
		if(motionx==1)
			cout<<"U"<<endl;
		else if(motionx==-1)
			cout<<"D"<<endl;
		else if(motiony==1)
			cout<<"L"<<endl;
		else if(motiony==-1)
			cout<<"R"<<endl;

	
	return 0;

}
//to find is there any equal distances more than one
int isequal(int manh_ar[4]){
	int counter=1;
	for (int i = 0; i < 2; i++) {
		if (manh_ar[i]==manh_ar[i+1]) {
				counter++;
		}
	}
	return counter;

}
//to find manhattan distance substract of mixed puzzle coordinates and final coordinates to find distance how its far away  from target
int distancesum(int orig_i,int orig_j,int goal_i,int goal_j){
	int sum=0,i=0,j=0;
		i=orig_i-goal_i;
		j=orig_j-goal_j;

		if (i<0)
			i=i*(-1);
{
		if (j<0)
			j=j*(-1);
}
			sum=i+j;
	return sum;
}
/*according to given coordinates which is side of blank tile it finds the up down left right tiles number*/
int findnum(int puzzleAr[ROW][COLOUMN],int y,int x){
	int num=0;
	for (int i = 0; i < y+1; i++) {
		for (int j = 0; j < x+1; j++) {
			num= puzzleAr[i][j];
		}
	}
	return num;
}
