#include <iostream>
#include<ctime>
#include<cstdlib>
#include <string>
#include <fstream>
#include<istream>

using std::cin;
using std::cerr;
using std::endl;
using std::cout;


using std::ofstream;
using std::ifstream;
using std::string;


class NPuzzle
{   
    public:
		//to print function
        void print()const;
		// to load a file
        void readFromFile(const string &filename);
		//to save file
        void writeToFile(const string & filename);
        void setsize(const int & sizevalue_row,const int & sizevalue_colum);
		//makes random moves
        void moveRandom();
		//to show how many move that user did
		inline void printReport(int);
		//my constructor i determine size of array or if user wants to open a file here where i load  
		NPuzzle(string filename="XX", int argc=3){
			int size;
					//if argc that means the user entered an file name
					if(argc==2){
						ifstream rowcol;

						rowcol.open(filename);
						//if the file couldn't open give an error message and terminate program
						if(rowcol.fail()){
							cout<<"Enter a VALID name!!!"<<endl;
							exit(-1);
						}
						else{		
							gamein.readFromFile(filename);
						}	
						
					}//if arg counter is 1 that means it starts as hw1 puzzle
					else if(argc==1){

						cout <<"Please enter the problem size\n";
						cin>> size;
						while(!(size>=3 && size<=9)){
							cin>> size;
						}
						gamein.setsize(size,size);						
						gamein.reset();
						while (gamein.checkSolvability()==false || gamein.isSolved()) {
							gamein.reset();
						}

					}
					
					else if (argc>2){
						cout<<"Enter just one valid file"<<endl;
						exit(-1);
					}	
					else
						cout<<"There might be a problem";
		
		}
        int shuffle(int repeat);
        int move (const char move_direction);
		//my reset function arrange puzzle which is solvable
        void reset();
		//fallowing 3 functions to create a solvable puzzle you can see below detail how it generates
        bool checkSolvability()const;
        int whereisblank()const;
        int inversionCounter()const;
		//to check the puzzle solved or not
		bool isSolved()const;
		//order function using to fill 2d array in numbr order after that i shuffle it
		void order();
		//to get size*size to send shuffle as a parameter
		inline int gettrepeat()const;
		// the following  3 fuctions to calculate manhattan distance and intelligence function but my intelligence function cannot work properly
		int distancesum(int orig_i,int orig_j,int goal_i,int goal_j);
		int findnum(int y,int x);
		int moveIntelligent();
		int solvePuzzle(){
			int numberOFmove=0;
			while(isSolved()==false){
				moveIntelligent();
				print();
				numberOFmove++;
				for (int i = 0; i < 5 && isSolved()==false; i++)
				{
					if(isSolved()==false){
						moveRandom();
						numberOFmove++;
					}		
				}
				
				print();
			}
			return numberOFmove;
		}
        
    private:
		int orig_i,orig_j,goal_i,goal_j;
		
        class Board
        {   
            public:
				int findnum(int y,int x);
                void print()const;
                void readFromFile(string filename);
            	void writeToFile(string filename);
                void reset();
                void setsize(const int & sizevalue_row,const int& sizevalue_colum);
                int move (const char move_direction);
                bool checkSolvability()const;
                int whereisblank()const;
                int inversionCounter()const;
                bool shiftLeft();
                bool shiftRight();
                bool shiftUp();
                bool shiftDown();
				bool isSolved()const;
				void order();
				//following are my getter functions too access datas
				int getrow(){
					return row;
				}
				int getcol(){
					return colum;
				}
				inline int gettrepeat()const{
					return repeat;
				}
				int getx(){
					return blank_x;
				}
				int gety(){
					return blank_y;
				}
            private:
			//max puzzle size
				static const int ROW=9;
				static const int COLOUMN=9;
                int puzzleAr[ROW][COLOUMN];
                int row,colum;
                int repeat;
				int y, x;
				//to find blank tiles x and y coordinates
				void findblank(){
					int i,j;
					int flag=0;
					for ( i = 0; i < row && flag==0; i++) {
						for ( j = 0; j < colum &&flag==0; j++) {
							if(puzzleAr[i][j]==-1)
								flag=1;

						}
					}
					i-=1;j-=1;
					blank_x=i;blank_y=j;
					
					return ;
				}
				int blank_x;
				int blank_y;


        };
		//to access board functions i have a game in board object
        Board gamein;
       
        

};
int main(int argc, char const *argv[]){

    srand (time(NULL));
    char movement ='k';
	//since we cannot assign a number to string if user dont enter any file name we get a run time terminatet so
	//so if the user didnt give a file name i have to assign something(empty) string in argv
	if (argc==1){
		argv[1]=" ";
	}
    NPuzzle game(argv[1],argc);

	int repeatt=game.gettrepeat();
    bool check=false;
    bool check_limit=false;
	string filename;
    cout <<"Your initial random board is\n";
     game.print();
     int quit=0;
    int move_counter=0;
	while (quit != 1 && check==false ) {
		cout <<"Your move: ";
		cin >> movement;
		check_limit=0;
		switch (movement) {
			case 'L':
			case 'l':
				check_limit=game.move(movement);
				game.print();
				break;
			case 'R':
			case 'r':
				check_limit=game.move(movement);
				game.print();
				break;
			case 'U':
			case 'u':
				check_limit=game.move(movement);
				game.print();
				break;
			case 'D':
			case 'd':
				check_limit=game.move(movement);
				game.print();
				break;
			case 'I':
			case 'i':
			  check_limit=game.moveIntelligent();
				game.print();
				break;
			case 'S':
			case 's':
				game.shuffle(repeatt);
				game.print();
				break;
			case 'O':
			case 'o':
				cout<<"Enter file name that you want to open"<<endl;
				cin>>filename;	
    			game.readFromFile(filename);				
				game.print();
				break;
			case 'E':
			case 'e':
				cout<<"Enter a file name that you want to save current positions"<<endl;
				cin >> filename;
				game.writeToFile(filename);
				break;	
			case 'T':
			case 't':
				game.printReport(move_counter);
				break;
			case 'V':
			case 'v':
				move_counter=move_counter+ game.solvePuzzle();
				break;		
			case 'Q':
			case 'q':
				quit = 1;
				break;
			default:
				cout << "!INVALID action!!" << '\n';
				break;
		}//it counts number of valid moves
		if (((movement == 'L' || movement =='l') || (movement == 'R' || movement =='r') || (movement == 'U' || movement =='u') || (movement == 'D' || movement =='d') || (movement == 'i' || movement == 'I' )) && check_limit== true ) {
			move_counter++;
		}
		check =game.isSolved();
		if(check==true)	
			cout<<"Total number of moves "<<move_counter<<endl;
	}     

    return 0;
}
inline void NPuzzle::printReport(int move_counter){
	cout<<"Total number of valid moves "<<move_counter<<endl;
	return ;
}
inline int NPuzzle::gettrepeat()const{
	return gamein.gettrepeat();
}
void NPuzzle::writeToFile(const string &filename){
	gamein.writeToFile(filename);
	return ;
}
void NPuzzle::Board::writeToFile(string filename){
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
}
void NPuzzle::setsize(const int& row,const int &colum){
    gamein.setsize(row,colum);
    return ;
}
void NPuzzle::Board::setsize(const int &sizevalue_row,const int &sizevalue_colum) {
	row=sizevalue_row;colum=sizevalue_colum;
	repeat=sizevalue_row*sizevalue_colum;
	
	return;
}
int NPuzzle::move(const char move_direction){

    return gamein.move(move_direction);
     
}
int NPuzzle::Board::move(const char move_direction){
    bool check_limit=false;
    switch(move_direction){
        case 'L':
		case 'l':
            check_limit=shiftLeft();
            break;
        case 'r':
		case 'R':
            check_limit=shiftRight();
            break;
        case 'u':
		case 'U':
            check_limit=shiftUp();
            break;
        case 'd':
		case 'D':
            check_limit=shiftDown();
            break;  
        default:
            cout<<"there is a problem with moves";
            break;              
    }
    return check_limit;
}
void NPuzzle::readFromFile(const string  &filename){
	gamein.readFromFile(filename);
	return ;
}
void NPuzzle::Board::readFromFile(string filename){
	string each;
    ifstream inputstream;
    ifstream rowcol;
	int row,colum;
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
				
				setsize(row,colum);
	 
		
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
void NPuzzle::print()const{
    gamein.print();
    return ;
}
void NPuzzle::Board::order(){
	int fill=1;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colum; j++) {
			if(puzzleAr[i][j] != 0){
				puzzleAr[i][j]=fill;
				fill++;
			}	
		}
	}
	puzzleAr[row-1][colum-1]=-1;
	return ;
}
int NPuzzle::shuffle(int repeat){
	gamein.order();
	for (int i = 0; i < repeat; i++) {
		moveRandom();
	}
	/*to check after shuffle there is a solved puzzle :)*/
	if (isSolved() == true)
		return shuffle(repeat);
	else
		return 0;

}
void NPuzzle::moveRandom(){
	int randAction=0;
	randAction = (rand()%4)+1;

		if (randAction == 1){
			if (gamein.move('L') != true)
				gamein.move('R');
		}
		else if (randAction == 2){
			if (gamein.move('R') != true)
				gamein.move('L');
		}
		else if (randAction == 3){
		if (gamein.move('u') != true)
		 		gamein.move('D');
		}
		else if (randAction == 4){
			if (gamein.move('D') != true)
			 gamein.move('U');
		}
	return ;
}
bool NPuzzle::isSolved()const{
	return gamein.isSolved();
	
}
bool NPuzzle::Board::isSolved()const{
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
void NPuzzle::Board::print()const{
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
bool NPuzzle::Board::shiftLeft(){
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
bool NPuzzle::Board::shiftRight(){
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
bool NPuzzle::Board::shiftUp(){
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
bool NPuzzle::Board::shiftDown(){
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
}
void NPuzzle::reset(){
    gamein.reset();
    return ;
}
void NPuzzle::Board::reset(){
    int fill=1,i=0 ,j=0;
	for ( i=0; i<row; i++){
		for ( j=0; j<colum; j++){
			puzzleAr[i][j]=-1;
		}
	}
	
	for (int k = 1; k < row*colum; k++) {
		i=(rand()%row);
		j=(rand()%colum);
		if(puzzleAr[i][j] == -1){
			puzzleAr[i][j] = fill;
			fill+=1;
		}
		else
			k-=1;
	}

	return ;
}
bool NPuzzle::checkSolvability()const{
    return gamein.checkSolvability();
    
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
bool NPuzzle::Board::checkSolvability()const{
    int inv_counter = inversionCounter();
	int blankplace=whereisblank();
	if (row%2==1 && inv_counter%2==0)
		return true;
	else if(row%2==0 && ((blankplace%2==0 && inv_counter%2==1) || (blankplace%2==1 && inv_counter%2==0)) )
			return true;
	else
		return false;

}
int NPuzzle::whereisblank()const{
    return gamein.whereisblank();
}
int NPuzzle::Board::whereisblank()const{
    int rowcounter=0,flag=0;
	for (int i = row-1; i >= 0 && flag==0; i--) {
		for (int j = colum-1; j >= 0 && flag==0; j--) {
			if (puzzleAr[i][j]==-1)
				flag=1;
		}
		rowcounter++;
	}
	return rowcounter;

}
int NPuzzle::inversionCounter()const{
    return gamein.inversionCounter();
    
    
}
int NPuzzle::Board::inversionCounter()const{
    int *inversAr = (int*)malloc((row*colum)*sizeof(int));
	int counter=0, inverse_counter=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colum; j++) {
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
int NPuzzle::moveIntelligent(){
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
	int row=gamein.getrow();
	int colum=gamein.getcol();

	int goalPuzzle[9][9];
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
		i=gamein.getx();
		j=gamein.gety();
		firstx=i;firsty=j;
		flag=0;
		down_i=i+1; up_i=i-1; left_i=i; right_i=i;
		down_j=j; up_j=j; left_j=j-1; right_j=j+1;

		if (down_i != row)
			downnum=gamein.findnum(down_i,down_j);

		if (up_i != -1)
			upnum=gamein.findnum(up_i,up_j);

		if (left_j != -1)
			leftnum=gamein.findnum(left_i,left_j);

		if (right_j != colum)
			rightnum=gamein.findnum(right_i,right_j);

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

	if (manh_d>manh_r && move('r'))
		cout<<"Intelligence chosed R"<<endl;
	else if (manh_d<=manh_r && move('d'))
		cout<<"Intelligence chosed R"<<endl;
	else if (manh_l>manh_u && move('u'))
		cout<<"Intelligence chosed R"<<endl;
	else if (manh_l<=manh_u && move('l'))
		cout<<"Intelligence chosed R"<<endl;
	else if (manh_d>manh_u && move('u'))
		cout<<"Intelligence chosed R"<<endl;
	else if (manh_d<=manh_u && move('d'))
		cout<<"Intelligence chosed R"<<endl;
	else if (manh_l>manh_r&& move('r'))
		cout<<"Intelligence chosed R"<<endl;
	else if (manh_l<=manh_r && move('l'))
		cout<<"Intelligence chosed R"<<endl;

	return 1;
}
//to find manhattan distance substract of mixed puzzle coordinates and final coordinates to find distance how its far away  from target
int NPuzzle::distancesum(int orig_i,int orig_j,int goal_i,int goal_j){
	int sum=0,i=0,j=0;
		i=orig_i-goal_i;
		j=orig_j-goal_j;

		if (i<0)
			i=i*(-1);

		if (j<0)
			j=j*(-1);

			sum=i+j;
	return sum;
}
int NPuzzle::findnum(int y,int x){
	return gamein.findnum(y,x);
}
/*according to given coordinates which is side of blank tile it finds the up down left right tiles number*/
int NPuzzle::Board::findnum(int y,int x){
	int num=0;
	for (int i = 0; i < y+1; i++) {
		for (int j = 0; j < x+1; j++) {
			num= puzzleAr[i][j];
		}
	}
	return num;
}