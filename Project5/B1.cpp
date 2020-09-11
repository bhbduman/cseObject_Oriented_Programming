#include <iostream>
#include <string>

#include "B1.h"
using namespace std;

namespace BHB
{
    Board1D::Board1D(int row,int colum):AbstractBoard(row,colum){
     setSize(row,colum);   
    }
    Board1D::Board1D():AbstractBoard(){
        setSize(3,3);
    }
    void Board1D::setSize(const int & sizevalue_row,const int& sizevalue_colum){
            row=sizevalue_row; colum=sizevalue_colum;
            repeat=row*colum;
            puzzle =new  int[sizevalue_row*sizevalue_colum]/*(-1)*/;
            
            for (int i = 0; i < repeat; i++)
                puzzle[i]=-1;
            

            reset();
           return ; 
    }
    Board1D::Board1D(const Board1D& copy){
        repeat=copy.repeat;
        row=copy.row;
        colum=copy.colum;
        blank_x=copy.blank_x;
        blank_y=copy.blank_y;
       puzzle =new  int[row*colum];
        for (int i = 0; i < copy.repeat; i++)
            puzzle[i]=copy.puzzle[i];   
    }
    int Board1D::operator()(int i, int j)const{
        if((i<row && i>=0) && (j<colum && j>=0))
            return puzzle[colum*i+j];
        else
        {
            cout<<"Indexes are not valid"<<endl;
            exit(-1);
        }
    }
    int & Board1D::operator()(int i,int j){
        if((i<row && i>=0) && (j<colum && j>=0))
            return puzzle[colum*i+j];
        else
        {
            cout<<"Indexes are not valid"<<endl;
            exit(-1);
        }
    }
    Board1D::~Board1D(){
        delete [] puzzle;
    }
    
    Board1D &Board1D::operator=(const Board1D & copy){
        if(repeat != copy.repeat){
            delete [] puzzle;
            puzzle =new int[copy.repeat];
        }
        repeat=copy.repeat;
        row=copy.row;
        colum=copy.colum;
        blank_x=copy.blank_x;
        blank_y=copy.blank_y;
        for (int i = 0; i < copy.repeat; i++)
            puzzle[i]=copy.puzzle[i];
        
        return *this;
        
    }

}