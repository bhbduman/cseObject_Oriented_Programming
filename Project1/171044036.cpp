#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int arrangePuzzle(int **puzzleAr,int size);
int printPuzzle(int **puzzleAr,int size);
int playing(int **puzzleAr,int size);
int checkPuzzle(int **puzzleAr,int size);
int shiftLeft(int **puzzleAr,int size);
int shiftRight(int **puzzleAr,int size);
int shiftUp(int **puzzleAr,int size);
int shiftDown(int **puzzleAr,int size);
int shufflePuzzle(int **puzzleAr,int size);
int intelligence(int **puzzleAr,int size);
int checkSolvability(int **puzzleAr,int size);
int inversionCounter(int **puzzleAr,int size);
int whereisblank(int **puzzleAr,int size);
int check_bound(int **puzzleAr,int size);
int distancesum(int orig_i,int orig_j,int goal_i,int goal_j);
int findnum(int **puzzleAr,int y,int x);
int isequal(int manh_ar[4]);
int freefoo(int** puzzle,int size);

int main(){
    /*There is a problem with my program i just nocited it ,my intelligence part doesnt work properly and after make i move time when its running after that when you want to q it exits with coredumped error but if you dojust l r u d s and q its working if you read this probably i couldnt fix it and sorry about that*/ 
	int size;
	srand (time(NULL));
		cout <<"Please enter the problem size\n";
		/*to check validity*/
		do {
			cin >>size;
		} while(!(size>=3 && size<=9));
	int** puzzleAr= (int**)malloc(size*sizeof(int*));
		for(int i=0; i <size; i++)
			puzzleAr[i]= (int*)malloc(size* sizeof(int));
		cout <<"Your initial random board is\n";
		playing(puzzleAr,size);
	return 0;


}
//my puzzle arrange function first  fill all array with 0 after that it choses random coordinates
int arrangePuzzle(int **puzzleAr,int size){
	int fill=0,i=0 ,j=0;
	for ( i=0; i<size; i++){
		for ( j=0; j<size; j++){
			puzzleAr[i][j]=0;
		}
	}
	for (int k = 0; k < size*size; k++) {
		i=(rand()%size);
		j=(rand()%size);
		if(puzzleAr[i][j] == 0){
			puzzleAr[i][j] = fill;
			fill+=1;
		}
		else
		k-=1;
	}


	return 0;
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
int checkSolvability(int **puzzleAr,int size){
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
int whereisblank(int **puzzleAr,int size){
	int rowcounter=0,flag=0;
	for (int i = size-1; i >= 0 && flag==0; i--) {
		for (int j = size-1; j >= 0 && flag==0; j--) {
			if (puzzleAr[i][j]==0)
				flag=1;
		}
		rowcounter++;
	}
	return rowcounter;
}
//to convert 2d array to 1d array
int inversionCounter(int **puzzleAr,int size){
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
int printPuzzle(int **puzzleAr,int size){
	for(int i=0; i<size; i++ ){
		for (int j=0; j<size; j++){
			if (puzzleAr[i][j] != 0)
				cout <<puzzleAr[i][j]<<"\t";
			else
				cout <<" "<<"\t";
		}
		cout << "\n\n\n";
	}

	return 0;
}
int playing(int **puzzleAr,int size){
	char move ='k';
	int quit=0;
	int move_counter=0;
	bool check_limit=0;// this variable to check puzzle limits and if user try an invalid move it  dont add to number of moves
	arrangePuzzle(puzzleAr,size);
	while (checkSolvability(puzzleAr,size) || (checkPuzzle(puzzleAr,size) == 0)) {
		arrangePuzzle(puzzleAr,size);
	}
	/*the loop above for the get an valid puzzle to solve*/



	printPuzzle(puzzleAr,size);
	while ((checkPuzzle(puzzleAr,size) == 1) && (quit != 1) ) {
		cout <<"Your move: ";
		cin >> move;
		check_limit=0;
		switch (move) {
			case 'L':
			case 'l':
				check_limit=shiftLeft(puzzleAr,size);
				printPuzzle(puzzleAr,size);
				break;
			case 'R':
			case 'r':
				check_limit=shiftRight(puzzleAr,size);
				printPuzzle(puzzleAr,size);
				break;
			case 'U':
			case 'u':
				check_limit=shiftUp(puzzleAr,size);
				printPuzzle(puzzleAr,size);
				break;
			case 'D':
			case 'd':
				check_limit=shiftDown(puzzleAr,size);
				printPuzzle(puzzleAr,size);
				break;
			case 'I':
			case 'i':
			  check_limit=intelligence(puzzleAr,size);
				printPuzzle(puzzleAr,size);
				break;
			case 'S':
			case 's':
				shufflePuzzle(puzzleAr,size);
				printPuzzle(puzzleAr,size);
				break;
			case 'Q':
			case 'q':
				freefoo(puzzleAr,size);
				quit = 1;
				break;
			default:
				cout << "!INVALID action!!" << '\n';
				break;
		}
		if ((move != 'S' || move !='s' || move != 'q' || move !='q') && check_limit== 0 ) {
			move_counter++;
		}
	}
	//below end of the move check the puzzle solved or not
	if (checkPuzzle(puzzleAr,size) == 0) {
		freefoo(puzzleAr,size);
		cout << "Problem Solved!" << '\n'<<"Total number of moves "<<move_counter<<endl;
	}
	return 0;
}
/*my shift functions returns 0 if its succesfull otherwise it returns 1*/
int shiftLeft(int **puzzleAr,int size){
	int flag=0,i=0,j=0;
	for (i = 0; i < size && flag == 0; i++) {
		for (j = 0; j < size && flag == 0; j++) {
			if (puzzleAr[i][j]==0)
				flag =1;
		}
	}
	i-=1;
	j-=1;
	if(j != 0){
		puzzleAr[i][j]=puzzleAr[i][(j-1)];
		puzzleAr[i][(j-1)]=0;
	}
	else{
			cout << "!Wrong move!!" << '\n';
			return 1;
	}
	return 0;
}
int shiftRight(int **puzzleAr,int size){
	int flag=0,i=0,j=0;
	for (i = 0; i < size && flag == 0; i++) {
		for (j = 0; j < size && flag == 0; j++) {
			if (puzzleAr[i][j]==0)
				flag =1;
		}
	}
	i-=1;
	j-=1;
	if(j != (size-1) ){
		puzzleAr[i][j]=puzzleAr[i][(j+1)];
		puzzleAr[i][(j+1)]=0;
	}
	else{
			cout << "!Wrong move!!" << '\n';
			return 1;
	}
	return 0;
}
int shiftUp(int **puzzleAr,int size){
	int flag=0,i=0,j=0;
	for (i = 0; i < size && flag == 0; i++) {
		for (j = 0; j < size && flag == 0; j++) {
			if (puzzleAr[i][j]==0)
				flag =1;
		}
	}
	i-=1;
	j-=1;
	if(i != 0){
		puzzleAr[i][j]=puzzleAr[i-1][j];
		puzzleAr[i-1][j]=0;
	}
	else{
			cout << "!Wrong move!!" << '\n';
			return 1;
	}
	return 0;
}
int shiftDown(int **puzzleAr,int size){
	int flag=0,i=0,j=0;
	for (i = 0; i < size && flag == 0; i++) {
		for (j = 0; j < size && flag == 0; j++) {
			if (puzzleAr[i][j]==0)
				flag =1;
		}
	}
	i-=1;
	j-=1;
	if(i != (size-1)){
		puzzleAr[i][j]=puzzleAr[i+1][j];
		puzzleAr[i+1][j]=0;
	}
	else{
			cout << "!Wrong move!!" << '\n';
			return 1;
	}
	return 0;
}
/*my shuffle functions and i add extra shifts if the random result is invalid*/
int shufflePuzzle(int **puzzleAr,int size){
	int randAction=0,fill=1;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			puzzleAr[i][j]=fill;
			fill++;
		}
	}
	puzzleAr[size-1][size-1]=0;

	for (int i = 0; i < size*size; i++) {
		randAction = (rand()%4)+1;

		if (randAction == 1){
			if (shiftLeft(puzzleAr,size) != 0)
				shiftRight(puzzleAr,size);
		}
		else if (randAction == 2){
			if (shiftRight(puzzleAr,size) != 0)
				shiftLeft(puzzleAr,size);
		}
		else if (randAction == 3){
			if (shiftUp(puzzleAr,size) != 0)
				shiftDown(puzzleAr,size);
		}
		else if (randAction == 4){
			if (shiftDown(puzzleAr,size) != 0)
			 shiftUp(puzzleAr,size);
		}
		else
			cout << "May be shuffle has a problem" << '\n';

	}
	/*to check after shuffle there is a solved puzzle :)*/
	if (checkPuzzle(puzzleAr,size) == 0)
	 	return shufflePuzzle(puzzleAr,size);
	else
		return 0;
}
/*below checks puzzle is it solved or not*/
int checkPuzzle(int **puzzleAr,int size){
	int count=1;
	int flag=0;
	for (int i = 0; i < size && flag==0; i++) {
		for (int j = 0; j < size && flag==0; j++) {
			if (puzzleAr[i][j] == count)
				count+=1;
			else
			flag = 1;
		}
	}
	if (count == (size*size) )
		return 0;


	return 1;
}
/*following 100 row to determine what numbers are side of the blank tile and find the numbers then find the numbers final coordinates which they are should be
and it substracts final position coordinates and original coordinates
then it calculates how many (min)number of move makes to go final place */
int intelligence(int **puzzleAr,int size){
	int fillGoalpuz=1,flag=0;
	int randshift=0;
	int manh_ar[4];
	int arraycounter=1;
	int down_i=0,down_j=0,up_i=0,up_j=0,left_i=0,left_j=0,right_i=0,right_j=0;
	int goaldown_i=0,goaldown_j=0,goalup_i=0,goalup_j=0,goalleft_i=0,goalleft_j=0,goalright_i=0,goalright_j=0;
	int downnum=0,upnum=0,leftnum=0,rightnum=0;
	int manh_d=0,manh_u=0,manh_l=0,manh_r=0;
	int i = 0,j = 0;
	int temp;
	int** goalPuzzle= (int**)malloc(size*sizeof(int*));
		for( i=0; i <size; i++)
			goalPuzzle[i]=(int*)malloc(size*sizeof(int));

		for ( i = 0; i < size; i++) {
			for ( j = 0; j < size; j++) {
				if(fillGoalpuz != size*size)
					goalPuzzle[i][j]=fillGoalpuz;
				else
					goalPuzzle[i][j]=0;

				fillGoalpuz++;
			}
		}
		for ( i = 0; i < size && flag==0; i++) {
			for ( j = 0; j < size &&flag==0; j++) {
				if(puzzleAr[i][j]==0)
					flag=1;

			}
		}
		i-=1;j-=1;
		flag=0;
		down_i=i+1; up_i=i-1; left_i=i; right_i=i;
		down_j=j; up_j=j; left_j=j-1; right_j=j+1;

		if (down_i != size)
			downnum=findnum(puzzleAr,down_i,down_j);
{
		if (up_i != -1)
			upnum=findnum(puzzleAr,up_i,up_j);
}
		if (left_j != -1)
			leftnum=findnum(puzzleAr,left_i,left_j);
{
		if (right_j != size)
			rightnum=findnum(puzzleAr,right_i,right_j);
}
	for ( i = 0; i < size && flag == 0 && downnum!=0; i++) {
		for ( j = 0; j < size && flag == 0; j++) {
			if (goalPuzzle[i][j]==downnum)
			flag=1;
		}
	}
	i-=1;	j-=1;
	goaldown_i=i;goaldown_j=j;
	flag=0;
	for ( i = 0; i < size && flag == 0 && upnum!=0; i++) {
		for ( j = 0; j < size && flag == 0; j++) {
			if (goalPuzzle[i][j]==upnum)
			flag=1;
		}
	}
	i-=1;j-=1;
	goalup_i=i;goalup_j=j;
	flag=0;
	for ( i = 0; i < size && flag == 0 && leftnum!=0; i++) {
		for ( j = 0; j < size && flag == 0; j++) {
			if (goalPuzzle[i][j]==leftnum)
			flag=1;
		}
	}
	i-=1;j-=1;
	goalleft_i=i;goalleft_j=j;
	flag=0;
	for ( i = 0; i < size && flag == 0 && rightnum!=0; i++) {
		for ( j = 0; j < size && flag == 0; j++) {
			if (goalPuzzle[i][j]==rightnum)
			flag=1;
		}
	}
	i-=1;j-=1;
	goalright_i=i;goalright_j=j;
	flag=0;
	if(downnum != 0)
		manh_d=distancesum(down_i,down_j,goaldown_i,goaldown_j);
{
	if(upnum != 0)
		manh_u=distancesum(up_i,up_j,goalup_i,goalup_j);
}
	if(leftnum != 0)
		manh_l=distancesum(left_i,left_j,goalleft_i,goalleft_j);
{
	if(rightnum != 0)
		manh_r=distancesum(right_i,right_j,goalright_i,goalright_j);
}
	manh_ar[0]=manh_d+1;
	manh_ar[1]=manh_l+1;
	manh_ar[2]=manh_r+1;
	manh_ar[3]=manh_u+1;
/*after that it makes move min manhattandistance and if the distances are equal more then one tile
it makes move randomly i find the manhattan distance algorithm but i couldnt implement it well*/
	if (manh_r<manh_l && manh_r<manh_u && manh_r<manh_d && manh_r !=0)
		shiftRight(puzzleAr, size);
{
	if (manh_l<manh_r && manh_l<manh_u && manh_l<manh_d && manh_l !=0)
		shiftLeft(puzzleAr, size);
}
	if (manh_u<manh_r && manh_u<manh_l && manh_u<manh_d && manh_u !=0)
		shiftUp(puzzleAr, size);
{
	if (manh_d<manh_r && manh_d<manh_l && manh_d<manh_u && manh_d !=0)
		shiftDown(puzzleAr,size);
}
	arraycounter=isequal(manh_ar);

	if(arraycounter>1){
		{
			if (manh_d==manh_l && (downnum != 0 || leftnum != 0)){
				randshift=(rand()%2)+1;
				if (randshift==1)
					shiftDown(puzzleAr,size);
				else
					shiftLeft(puzzleAr,size);
			}
		}
			if (manh_d==manh_r && (downnum != 0 || rightnum != 0)){
				randshift=(rand()%2)+1;
				if (randshift==1)
					shiftDown(puzzleAr,size);
				else
					shiftRight(puzzleAr,size);
			}

		{
			if (manh_d==manh_u && (downnum != 0 || upnum != 0)){
				randshift=(rand()%2)+1;
				if (randshift==1)
					shiftDown(puzzleAr,size);
				else
					shiftUp(puzzleAr,size);
			}
		}
			if (manh_l==manh_r && (rightnum != 0 || leftnum != 0)){
				randshift=(rand()%2)+1;
				if (randshift==1)
					shiftLeft(puzzleAr,size);
				else
					shiftRight(puzzleAr,size);
			}
		{
			if (manh_u==manh_l && (upnum != 0 || leftnum != 0)){
				randshift=(rand()%2)+1;
				if (randshift==1)
					shiftUp(puzzleAr,size);
				else
					shiftLeft(puzzleAr,size);
			}
		}
			if (manh_u==manh_r && (upnum != 0 || rightnum != 0)){
				randshift=(rand()%2)+1;
				if (randshift==1)
					shiftUp(puzzleAr,size);
				else
					shiftRight(puzzleAr,size);
			}
		{
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

	freefoo(goalPuzzle,size);

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
int findnum(int **puzzleAr,int y,int x){
	int num=0;
	for (int i = 0; i < y+1; i++) {
		for (int j = 0; j < x+1; j++) {
			num= puzzleAr[i][j];
		}
	}
	return num;
}
//checks the puzzle limits
int check_bound(int **puzzleAr,int size){
	int flag=0,i=0,j=0;
	for ( i = 0; i < size && flag==0; i++) {
		for ( j = 0; j < size && flag==0; j++) {
				if (puzzleAr[i][j]== 0)
					flag=1;
		}
	}
	i-=1;j-=1;
	return 0;


}
int freefoo(int** puzzle,int size){
	for (int i = 0; i < size; i++) {
		free(puzzle[i]);
	}
	free(puzzle);
	return 0;
}
