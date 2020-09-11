#include<iostream>
#include<string>

#include "B2.h"
using namespace std;

namespace BHB
{
    int Board2D::operator ()(int i,int j)const{
        if((i<row && i>=0) && (j<colum && j>=0))
            return puzzle[i][j];
        else
        {
            cout<<"Indexes are not valid"<<endl;
            exit(-1);
        }
    }
    int & Board2D::operator()(int i,int j){
        if((i<row && i>=0) && (j<colum && j>=0))
            return puzzle[i][j];
        else
        {
            cout<<"Indexes are not valid"<<endl;
            exit(-1);
        }
    }
    
    Board2D::Board2D(int row, int colum) :AbstractBoard(row,colum) {
        setSize(row,colum);
    }
    Board2D::Board2D(const Board2D & copy){
        puzzle =new int* [copy.row];
            for(int i=0; i<copy.row; i++)
                puzzle[i]=new int [copy.colum]/*(-1)*/;
    
                // setSize(row,colum);

            for (int i = 0; i < copy.row; i++)
                for (int j = 0; j < copy.colum; j++)
                    puzzle[i][j]=copy.puzzle[i][j];

            repeat=copy.repeat;
            row=copy.row;
            colum=copy.colum;
            blank_x=copy.blank_x;
            blank_y=copy.blank_y;

    }
    void Board2D::setSize(const int & sizevalue_row,const int& sizevalue_colum){
	    row=sizevalue_row; colum=sizevalue_colum;
        repeat=row*colum;
        puzzle =new int* [sizevalue_row];
	    for(int i=0; i<sizevalue_row; i++)
	    	puzzle[i]=new int [sizevalue_colum]/*(-1)*/;

            for (int i = 0; i < row; i++)
                for (int j = 0; j < colum; j++)
                    puzzle[i][j]=-1;                   
            
            

        reset();
    }
    Board2D &Board2D::operator=(const Board2D & copy ){
        bool flag =true;
        cerr<<"here"<<endl;
            for (int i = 0; i < row; i++)
                for (int j = 0; j < colum; j++)
                    cerr<<puzzle[i][j];
            if(row!=copy.row || colum !=copy.colum){
                for (int i=0; i<row; i++){
                    cerr<<i<<endl;
                   delete [] puzzle[i];
                        puzzle[i]=nullptr;
                }
                delete [] puzzle;   
                    puzzle=nullptr;

                    puzzle =new int* [copy.row];
                    for(int i=0; i<copy.row; i++)
                        puzzle[i]=new int [copy.colum]/*(-1)*/;
            }
           // setSize(row,colum);

            for (int i = 0; i < copy.row; i++)
                for (int j = 0; j < copy.colum; j++)
                    puzzle[i][j]=copy.puzzle[i][j];

            repeat=copy.repeat;
            row=copy.row;
            colum=copy.colum;
            blank_x=copy.blank_x;
            blank_y=copy.blank_y;        
           
                return *this; 


    }
    Board2D::Board2D():AbstractBoard(){
        setSize(3,3);
    
    }
    Board2D::~Board2D(){
        for (int i=0; i<row; i++){
            delete [] puzzle[i];
            puzzle[i]=nullptr;
        }
        delete [] puzzle;   
        puzzle=nullptr;
    }
    

}