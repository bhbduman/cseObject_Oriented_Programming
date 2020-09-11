#include <iostream>
#include <string>

#include "BV.h"
using namespace std;

namespace BHB
{
    BoardVector::BoardVector(int row,int colum) :AbstractBoard(row,colum)
    {
        setSize(row,colum);
    }
    BoardVector::BoardVector():AbstractBoard(){
        setSize(3,3);
    }
    void BoardVector::setSize(const int & sizevalue_row,const int& sizevalue_colum){
            puzzle.resize(sizevalue_row);
        for(int i=0; i<sizevalue_row; i++)
		    puzzle[i].resize(sizevalue_colum,-1);

        row=sizevalue_row; colum=sizevalue_colum;
        repeat=row*colum;
        reset();
    }

    int BoardVector::operator()(int i,int j)const{
       if((i<row && i>=0) && (j<colum && j>=0))
            return puzzle[i][j];
        else
        {
            cout<<"INdexes are not valid"<<endl;
            exit(-1);
        }
            
    }
    int &BoardVector::operator()(int i,int j){
       if((i<row && i>=0) && (j<colum && j>=0))
            return puzzle[i][j];
        else
        {
            cout<<"Indexes are not valid"<<endl;
            exit(-1);
        }
         
    }

        BoardVector::~BoardVector(){}
} 