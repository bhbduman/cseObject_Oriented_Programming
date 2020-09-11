#ifndef B2_H
#define B2_H
#include <string>

#include "AB.h"

namespace BHB
{
    class Board2D :public AbstractBoard
    {
    public:    
        Board2D(int,int);
        Board2D();
        Board2D(const Board2D&);
        Board2D &operator=(const Board2D & );
        ~Board2D();
        void setSize(const int & sizevalue_row,const int& sizevalue_colum);
        int  operator ()(int i,int j)const;
        int & operator()(int i,int j);
    private:
        int** puzzle;
    };
}
#endif