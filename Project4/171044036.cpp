#include <iostream>
#include<ctime>
#include<cstdlib>
#include <string>
#include <fstream>
#include<istream>
#include<vector>
using namespace std;/*
using std::cin;
using std::cerr;
using std::endl;
using std::cout;
using std::vector;

using std::ofstream;
using std::ifstream;
using std::string;*/


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
			gamein.resize(1);
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
							gamein[0].readFromFile(filename);
						}	
						
					}//if arg counter is 1 that means it starts as hw1 puzzle
					else if(argc==1){
						cout <<"Please enter the problem size\n";
						cin>> size;
						while(!(size>=3 && size<=9)){
							cin>> size;
						}
						gamein[0].setsize(size,size);
						gamein[0].reset();
						while (gamein[0].checkSolvability()==false || gamein[0].isSolved()) {
							gamein[0].reset();
						}
						shuffle(gettrepeat());

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
		int gettrepeat()const;
		//order function using to fill 2d array in numbr order after that i shuffle it
		void order();
		//to get size*size to send shuffle as a parameter
        inline int getrow()const{
			int row =gamein[0].getrow();
			return row;
		}
		inline int getcolum()const{
			int colum =gamein[0].getcolum();
			return colum;
		}
		int solvePuzzle();
		//my >> overloaded operator to print puzzle it returns output stream and takes an npuzzle object as a parameter
		friend ostream & operator >>(ostream &output,const NPuzzle &game);
		//my<< input stream operator it get a file name from user and load the file i used in main
		friend istream & operator <<(istream &input,NPuzzle &game);
    private:
		
        class Board
        {   
            public:
                void print()const;
                void readFromFile(string filename);
            	void writeToFile(string filename);
				//I ASSUME THAT MY RESET FUNCTION IS ARRANGE MY PUZZLE IT CREATES NEW GAME
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
				//IM NOT SURE BUT SOME OF MY FRIENDS SAY MY ORDER FUCTION IS USING INSTEAD OF RESET FUNCTION
				//basically it fills all array starting by 1 and it gives a final state im using it before shuffle
				void order();
				//following are my getter functions too access datas
				inline int gettrepeat()const{
					return repeat;
				}
				int  operator ()(int i,int j)const{
					return puzzle[i][j];
				}
				 int getrow()const{
					return row;
				}
				 int getcolum()const{
					return colum;
				}
				int getblank_x(){
					return blank_x;
				}
				int getblank_y(){
					return blank_y;
				}
				bool operator ==(const NPuzzle::Board & currentboard)const{
					bool equivalent=true;
					if(puzzle==currentboard.puzzle)
						return true;
					else 
						return false;
					
				}
				int numberOfMoves(){
					return numberOFmoves;
				}
				void find_blank(){
					for (int i = 0; i <row; i++)
						for (int j = 0; j <colum; j++)
							if (puzzle[i][j] == -1)
								blank_x=i,blank_y=j;
				}

				bool isValidMove(char move_direction)const;
				char lastMove();
            private:
				string filename;
                int row,colum;
                int repeat;
				int blank_x;
				int blank_y;
				char lastmove;
				int numberOFmoves;
                vector<vector<int> >puzzle;


        };

		bool isThere(const Board& trial);
		//to access board functions i have a game in board object
        vector<Board> gamein;

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
    // game.print();
	
	cout>>game;

     int quit=0;
    int move_counter=0;
	while (quit != 1 && check==false ) {
		cout <<"Your move: ";
		cin >> movement;
		check_limit=0;
		switch (movement){
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
			case 'S':
			case 's':
				game.shuffle(repeatt); 
				game.print();
				break;
			case 'O':
			case 'o':
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
//its for the main im alreadyusing a constructure forthe command line argument 
istream & operator <<(istream &input, NPuzzle &game ){
	string filename;
	cout<<"Enter the file name"<<endl;
	cin>>filename;
	game.readFromFile(filename);
	return input;
}
ostream & operator >>(ostream &output,const NPuzzle &game){
	int row=game.getrow();
	int colum=game.getcolum();

	int number=-1;

	for (int i = 0; i < row ; i++)
	{
        for (int j = 0; j < colum; j++)
		{
			number=game.gamein[0](i,j);
			if (number > 0)
				output <<number<<"\t";
			else if(number==-1)
				output <<"bb"<<"\t";
			else if(number==0)
				output <<"  "<<"\t";
			else{	
				output <<"Invalid content the program will be terminated"<<endl;
				exit(403);
			}	
		}
		output << "\n\n\n";
	}
	return output;

}
void NPuzzle::setsize(const int& row,const int &colum){
    gamein[0].setsize(row,colum);	
	gamein[0].find_blank();
    return ;
}

bool NPuzzle::isThere(const Board& trial)
{
	for(int i=0 ; i<gamein.size()-1 ; i++)
		if(gamein[i] == trial)
			return true;
	return false;
}

char NPuzzle::Board::lastMove()
{
	return lastmove;
}

int NPuzzle::solvePuzzle(){//my solve puzzle i code for the if is solved exit but it doesnt work i couldnt figure out
	int numberOFmove=0,flag=0;
	bool state;
	int i,j,k,l=0;
	char prevmove;
	vector<Board> bestpath;
	for( i=0 ; flag == 0 ; i++){

		gamein.push_back(gamein[i]);
		gamein.back().move('U');
		
		if(gamein.back().isSolved() == true)
			flag = 1;
		else if(isThere(gamein.back()) == true)
			gamein.pop_back();

		if(flag == 0)
		{
			gamein.push_back(gamein[i]);
			gamein.back().move('D');
			
			if(gamein.back().isSolved() == true)
				flag = 1;
			else if(isThere(gamein.back()) == true)
				gamein.pop_back();
		}
		
		if(flag == 0)
		{
			gamein.push_back(gamein[i]);
			gamein.back().move('L');
			
			if(gamein.back().isSolved() == true)
				flag = 1;
			else if(isThere(gamein.back()) == true)
				gamein.pop_back();
		}	

		if(flag == 0)
		{
		
			gamein.push_back(gamein[i]);
			gamein.back().move('R');
			
			if(gamein.back().isSolved() == true)
				flag = 1;
			else if(isThere(gamein.back()) == true)
				gamein.pop_back();
		}
	}
	

	for ( j = (int)gamein.size()-1; j >0 ; j--)
	{
		prevmove=gamein[j].lastMove();
		bestpath.push_back(gamein[j]);
		switch (prevmove)
		{
		case 'L':
		case 'l':
			gamein[j].move('r');	
			break;
		case 'r':
		case 'R':
			gamein[j].move('L');	
			break;
		case 'D':
		case 'd':
			gamein[j].move('U');	
			break;
		case 'U':
		case 'u':
			gamein[j].move('D');	
			break;
		}
		k=j;
		while (!(gamein[j]==gamein.at(k-1)))
		{

			
			
			k--;
			l++;
		}
		j=j-l+1;

		
		

	}
	for(int i=0;i<bestpath.size();i++){
		bestpath[i].print();
	}
	cout<<endl<<"total number of moves "<<gamein[i].numberOfMoves()<<endl;
	

	return numberOFmove;
}


void NPuzzle::Board::setsize(const int &sizevalue_row,const int &sizevalue_colum){
	//puzzle.resize(sizevalue_row); puzzle[i].resize(sizevalue_colum);
	puzzle.resize(sizevalue_row);
	for(int i=0; i<sizevalue_row; i++)
		puzzle[i].resize(sizevalue_colum,-1);

	row=sizevalue_row; colum=sizevalue_colum;
	repeat=sizevalue_row*sizevalue_colum;
	
	return;
}
void NPuzzle::print()const{
    gamein[0].print();
    return ;
}
void NPuzzle::Board::print()const{
    for (int i = 0; i < puzzle.size(); i++){
        for (int j = 0; j < puzzle[i].size(); j++){
			if (puzzle[i][j] > 0)
				cout <<puzzle[i][j]<<"\t";
			else if(puzzle[i][j]==-1)
				cout <<"bb"<<"\t";
			else if(puzzle[i][j]==0)
				cout <<"  "<<"\t";
			else	
				cout <<"xx"<<"\t";
		}
		cout << "\n\n\n";
	}

	return;
}
bool NPuzzle::isSolved()const{
	return gamein[0].isSolved();
	
}
bool NPuzzle::Board::isSolved()const{
	int compare=1;
	int flag =0;
	int i=0,j=0;
	bool check=false;

	for(i=0; i<puzzle.size() && flag==0; i++){
		for(j=0; j<(puzzle[i].size()) && (flag==0); j++){
			if( puzzle[i][j] == 0 )
				flag=0;
			else if( puzzle[i][j] != 0 && puzzle[i][j] == compare){
				check=true;
				flag=0;
				compare++;
				if(puzzle[puzzle.size()-1][puzzle.back().size()-1]== -1){
					flag==1;
					check=true;
				}	
			}
			else if(i==puzzle.size()-1 && j==puzzle.back().size()-1)
				flag=1;	
			else{
				check=false;
				flag=1;
			}	
		}
	}
	if(i==puzzle.size() && j==puzzle.back().size())
		cout<<"Problem Solved!"<<endl;
	return check;
}
bool NPuzzle::checkSolvability()const{
    return gamein[0].checkSolvability();
    
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
	if (puzzle.size()%2==1 && inv_counter%2==0)
		return true;
	else if(puzzle.size()%2==0 && ((blankplace%2==0 && inv_counter%2==1) || (blankplace%2==1 && inv_counter%2==0)) )
			return true;
	else
		return false;
}
int NPuzzle::whereisblank()const{
    return gamein[0].whereisblank();
}
int NPuzzle::Board::whereisblank()const{
    int rowcounter=0,flag=0;
	for (int i = puzzle.size()-1; i >= 0 && flag==0; i--) {
		for (int j = puzzle[i].size()-1; j >= 0 && flag==0; j--) {
			if (puzzle[i][j]==-1)
				flag=1;
		}
		rowcounter++;
	}
	return rowcounter;

}
int NPuzzle::inversionCounter()const{
    return gamein[0].inversionCounter();
    
    
}
int NPuzzle::Board::inversionCounter()const{
    int *inversAr = (int*)malloc((puzzle.size()*puzzle[1].size())*sizeof(int));
	int counter=0, inverse_counter=0;
	for (int i = 0; i < puzzle.size(); i++) {
		for (int j = 0; j < puzzle[i].size(); j++) {
			inversAr[counter]=puzzle[i][j];
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
void NPuzzle::reset(){
    gamein[0].reset();
    return ;
}
void NPuzzle::Board::reset(){
    int fill=1,i=0 ,j=0;
	for ( i=0; i<puzzle.size(); i++){
		for ( j=0; j<puzzle[i].size(); j++){
			puzzle[i][j]=-1;
		}
	}
	
	for (int k = 1; k < puzzle.size()*puzzle[i].size(); k++) {
		i=(rand()%puzzle.size());
		j=(rand()%puzzle[i].size());
		if(puzzle[i][j] == -1){
			puzzle[i][j] = fill;
			fill+=1;
		}
		else
			k-=1;
	}
	find_blank();
	return ;
}
int NPuzzle::move(const char move_direction){
	gamein.resize(1);
    return gamein[0].move(move_direction);
     
}

bool NPuzzle::Board::isValidMove(char move_direction)const
{
	if((move_direction == 'U' || move_direction == 'u') && blank_x > 0 && puzzle[blank_x-1][blank_y] != 0)
		return true;
	if((move_direction == 'D' || move_direction == 'd') && blank_x < row-1 && puzzle[blank_x+1][blank_y] != 0)
		return true;
	if((move_direction == 'L' || move_direction == 'l') && blank_y > 0 && puzzle[blank_x][blank_y-1] != 0)
		return true;
	if((move_direction == 'R' || move_direction == 'r') && blank_y < colum-1 && puzzle[blank_x][blank_y+1] != 0)
		return true;
	return false;
}

int NPuzzle::Board::move(const char move_direction){

	int targetX=0,targetY=0;

	switch(move_direction)
	{
		case 'u':
		case 'U':
			if(isValidMove(move_direction))
				targetX=-1;
			break;
		case 'd':
		case 'D':
			if(isValidMove(move_direction))
				targetX=1;
			break;
		case 'l':
		case 'L':
			if(isValidMove(move_direction))
				targetY = -1;
			break;
		case 'r':
		case 'R':
			if(isValidMove(move_direction))
				targetY=1;
			break;
	}

	if(targetX != 0 || targetY != 0)
	{
		int temp = puzzle[blank_x][blank_y];
		puzzle[blank_x][blank_y] = puzzle[blank_x+targetX][blank_y+targetY];
		puzzle[blank_x+targetX][blank_y+targetY] = temp;

		blank_x += targetX;
		blank_y += targetY;
		lastmove = move_direction;
		numberOFmoves++;
		return true;
	}
	return false;
}
void NPuzzle::readFromFile(const string  &filename){
	gamein.resize(1);
	gamein[0].readFromFile(filename);
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

		for(int i=0; i<puzzle.size(); i++){
			for(int j=0; j<puzzle[i].size(); j++){
				inputstream >> each;
				if( !(each[0]>=48 && each[0]<=57) )
					puzzle[i][j]=-1;
				else if(each[0] == 0 && each[1] == 0)
					puzzle[i][j]=0;
				else if(each[0] == 0 && each[1]>48 && each[1]<=57 )
					puzzle[i][j]=	(static_cast<int>(each[1]))-48;
				else//if it has two digits it converts first digit and multiply by 10 and add the last digit so thats how i convert them to integer 
					puzzle[i][j]=((static_cast<int>(each[0]))-48)*10+(static_cast<int>(each[1])-48);
			}
		}
	inputstream.close();

	find_blank();
    return;
}
void NPuzzle::writeToFile(const string &filename){
	gamein[0].writeToFile(filename);
	return ;
}
void NPuzzle::Board::writeToFile(string filename){
	ofstream savefile;
	savefile.open(filename);
	for(int i=0; i<puzzle.size(); i++){
			for(int j=0; j<puzzle.back().size(); j++){
				if( puzzle[i][j]==-1 )
					savefile<<"bb";
				else if(puzzle[i][j]==0)
					savefile<<"00";
				else if(puzzle[i][j] != 0 && puzzle[i][j] <10 )
					savefile<<"0"<<puzzle[i][j];					
				else	
					savefile<<puzzle[i][j];
				if (j!=colum-1)
				{
					savefile<<" ";
				}
			}
			savefile<<endl;	
	}
	savefile.close();
}
void NPuzzle::Board::order(){
	int fill=1;
	for (int i = 0; i < puzzle.size(); i++) {
		for (int j = 0; j < puzzle.back().size(); j++) {
			if(puzzle[i][j] != 0){
				puzzle[i][j]=fill;
				fill++;
			}	
		}
	}
	puzzle[row-1][colum-1]=-1;

	find_blank();
	return ;
}
inline int NPuzzle::gettrepeat()const{
	return gamein[0].gettrepeat();
}
int NPuzzle::shuffle(int repeat){
	gamein.resize(1);
	gamein[0].order();
	for (int i = 0; i < repeat; i++)
		moveRandom();

	gamein[0].find_blank();

	if (isSolved() == true)
		return shuffle(repeat);
	else
		return 0;

}
void NPuzzle::moveRandom(){
	gamein.resize(1);
	int randAction=0;
	bool state=false;

	while(!state)
	{
		randAction = (rand()%4);
		if (randAction == 0)
			state = gamein[0].move('u');
		if (randAction == 1)
			state = gamein[0].move('d');
		if (randAction == 2)
			state = gamein[0].move('l');
		if (randAction == 3)
			state = gamein[0].move('r');
	}
}
inline void NPuzzle::printReport(int move_counter){
	cout<<"Total number of valid moves "<<move_counter<<endl;
	return ;
}