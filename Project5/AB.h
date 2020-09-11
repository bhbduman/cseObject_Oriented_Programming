#ifndef AB_H
#define AB_H


#include<string>
using std::string;

namespace BHB
{
    
    class AbstractBoard
    {
    public:
        void print()const;//+prints the board
        void readFromFile(string filename);//+
        virtual void setSize(const int & sizevalue_row,const int& sizevalue_colum);//+the board resets after this operation
        int move (const char move_direction);//+
        bool isSolved()const;//+
        static int NumberOfBoards();//++
        char lastMove();//+
        int numberOfMoves()const;//+
       // bool isValidMove(char move_direction)const;//+
        void writeToFile(string filename);//+
        virtual int  operator ()(int i,int j)const=0; //+terminates the program if index is not valid
        void reset();//+resets board to the solution
        bool operator ==(const AbstractBoard & currentboard)const;
        AbstractBoard(int row,int colum);//+
        AbstractBoard();//+
        virtual ~AbstractBoard();//++
        void setterlastmove(char);
        bool checkpuzzleEqual(const AbstractBoard &,const AbstractBoard &)const;
        int getrow()const{return row;}
        int getcolum()const{return colum;}
        virtual int & operator()(int i,int j)=0;
    protected:
        bool isValidMove(char)const;
        int row,colum;        
        int blank_x;
        int blank_y;
        string filename="xXx";
        int argc=3;
        int repeat;
    private:
        char lastmove;
        int numberOfMove;
        static int numberOfBoards;
    };

    bool myglobalCheckFo(AbstractBoard* boardPtr[],int size);
}
#endif