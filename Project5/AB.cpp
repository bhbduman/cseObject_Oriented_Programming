#include<iostream>
#include<string>
#include "fstream"

#include"AB.h"


using namespace std;
namespace
{

}

namespace BHB
{   
    void AbstractBoard::setterlastmove(char x){
        lastmove=x;
    }
    bool AbstractBoard::isValidMove(char move_direction)const
    {
        if((move_direction == 'U' || move_direction == 'u') && blank_x > 0 && this->operator()(blank_x-1,blank_y)!=0)
            return true;
        if((move_direction == 'D' || move_direction == 'd') && blank_x < row-1 && this->operator()(blank_x+1,blank_y)!=0)
            return true;
        if((move_direction == 'L' || move_direction == 'l') && blank_y > 0 && this->operator()(blank_x,blank_y-1)!=0)
            return true;
        if((move_direction == 'R' || move_direction == 'r') && blank_y < colum-1 && this->operator()(blank_x,blank_y+1)!=0)
            return true;
        return false;
    }
    bool AbstractBoard::operator==(const AbstractBoard & currentboard)const{
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < colum; j++)
            { 
                if (!(this->operator()(i,j)==currentboard.operator()(i,j)))
                    return false;            
            }
            
        }
       // if(this->lastmove!= currentboard.lastmove)
         // return false;
        //else if(this->numberOfMove != currentboard.numberOfMove)
         //   return false;
        //else if(this->blank_x!=currentboard.blank_x ||this->blank_y!=currentboard.blank_y)
         //  return false;
        //else
            return true;
            
                
        
    }
    AbstractBoard::AbstractBoard(int r=3,int c=3): row(r),colum(c),lastmove('S'),numberOfMove(0)
    {
        numberOfBoards++;
    }
    int AbstractBoard::NumberOfBoards(){
        return numberOfBoards;
    }
    int AbstractBoard::numberOfMoves()const{
        return numberOfMove;
    }
    char AbstractBoard::lastMove(){
        return lastmove;
    }
    void AbstractBoard::writeToFile(string filename){
        ofstream savefile;
        savefile.open(filename);
        for(int i=0; i<row; i++){
                for(int j=0; j<colum; j++){
        
                    if( this->operator()(i,j)==-1 )
                        savefile<<"bb";
                    else if(this->operator()(i,j)==0)
                        savefile<<"00";
                    else if(this->operator()(i,j) != 0 && this->operator()(i,j) <10 )
                        savefile<<"0"<<this->operator()(i,j);					
                    else	
                        savefile<<this->operator()(i,j);
                    if (j!=colum-1)
                    {
                        savefile<<" ";
                    }
                }
                savefile<<endl;	
        }
        savefile.close();
    }
    void AbstractBoard::readFromFile(string filename){
        string each;
        fstream inputstream;
        fstream rowcol;
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
                    
                    setSize(row,colum);
        
            inputstream.open(filename);

            for(int i=0; i<row; i++){
                for(int j=0; j<colum; j++){
                    inputstream >> each;
                    if( !(each[0]>=48 && each[0]<=57) )
                        this->operator()(i,j)=-1;
                    else if(each[0] == 0 && each[1] == 0)
                        this->operator()(i,j)=0;
                    else if(each[0] == 0 && each[1]>48 && each[1]<=57 )
                        this->operator()(i,j)=	(static_cast<int>(each[1]))-48;
                    else//if it has two digits it converts first digit and multiply by 10 and add the last digit so thats how i convert them to integer 
                        this->operator()(i,j)=((static_cast<int>(each[0]))-48)*10+(static_cast<int>(each[1])-48);
                }
            }
        inputstream.close();

        for (int i = 0; i <row; i++)
            for (int j = 0; j <colum; j++)
                if (this->operator()(i,j) == -1)
                    blank_x=i,blank_y=j;
            return;
    }
    AbstractBoard::AbstractBoard():row(3),colum(3),blank_x(2),blank_y(2),lastmove('S'),numberOfMove(0),repeat(9){
        numberOfBoards++;
        setSize(row,colum);}
    void AbstractBoard::setSize(const int & sizevalue_row,const int& sizevalue_colum){
        row=sizevalue_row; colum=sizevalue_colum;
        return ;
    }
    int AbstractBoard::move(const char move_direction){
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
            int temp = this->operator()(blank_x,blank_y);
            this->operator()(blank_x,blank_y) = this->operator()(blank_x+targetX,blank_y+targetY);
            this->operator()(blank_x+targetX,blank_y+targetY) = temp;

            blank_x += targetX;
            blank_y += targetY;
            lastmove = move_direction;
            numberOfMove++;
            lastmove=move_direction;
            return true;
        }
        return false;
    }
    bool AbstractBoard::isSolved()const{
        int compare=1;
        int flag =0;
        int i=0,j=0;
        bool check=false;

        for(i=0; i<row && flag==0; i++){
            for(j=0; j<colum && (flag==0); j++){
                if( this->operator()(i,j) == 0 )
                    flag=0;
                else if(this->operator()(i,j) != 0 && this->operator()(i,j) == compare){
                    check=true;
                    flag=0;
                    compare++;
                    if(this->operator()(row-1,colum-1)== -1){
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
    void AbstractBoard::print()const{
        for (int i = 0; i < row; i++){
            for (int j = 0; j < colum; j++){
                if (this->operator()(i,j) > 0)
                    cout <<this->operator()(i,j)<<"\t";
                else if(this->operator()(i,j)==-1)
                    cout <<"bb"<<"\t";
                else if(this->operator()(i,j)==0)
                    cout <<"  "<<"\t";
                else	
                    cout <<"xx"<<"\t";
            }
            cout << "\n\n\n";
        }

        return;
    }
    void AbstractBoard::reset(){
        int fill=1;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < colum; j++) {
                    if(this->operator()(i,j) != 0){
                        this->operator()(i,j)=fill;
                        fill++;
                    }	
                }
            }
            this->operator()(row-1,colum-1)=-1;

            blank_x=row-1; blank_y=colum-1;
        return ;
    }
    AbstractBoard::~AbstractBoard(){
        numberOfBoards--;
    }
    bool myglobalCheckFo(AbstractBoard* boardPtr[],int size){
        char nextmove='S';
        int i;
        int roww  = boardPtr[0] -> getrow();
        int columm = boardPtr[0] -> getcolum();
        int firstx,firsty,secondx,secondy;
        int tot;
        int difcounter=0;
        if(!(boardPtr[size-1]->isSolved()))
        {
            //cout<<"yazacagin kodun"<<endl;
            return false;
        }

        
        while( i < 0 )
        {   
            i = size - 1;
            difcounter =0;
            for ( int i = 0; i < roww; i++)
            {
                for (int j = 0; j < columm ; j++)
                {
                    if(boardPtr[i]-> operator()(i,j) != boardPtr[i-1]-> operator()(i,j) )
                        difcounter++;
                    
                    if(boardPtr[i]-> operator()(i,j) ==-1)
                        firstx=i;firsty=j;
                    if(boardPtr[i-1]-> operator()(i,j) ==-1)
                        secondx=i;secondy=j;

                    tot=firstx-secondx+firsty-secondy;
                    if( difcounter != 2 || (tot!=1 || tot!=-1))
                        return false;

                }
                
            }
        }
            return true;
 }
}
using namespace BHB;
int AbstractBoard::numberOfBoards=0;
