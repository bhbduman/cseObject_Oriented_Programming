#ifndef B1_H
#define B1_H

#include "AB.h"

namespace BHB{
    class Board1D :public AbstractBoard
    {
    public:
        Board1D(int,int);
        Board1D();
        Board1D(const Board1D&);
        Board1D& operator=(const Board1D &);
        int operator()(int,int)const;
        int &operator()(int,int);
        void setSize(const int & sizevalue_row,const int& sizevalue_colum);
        ~Board1D();
    private:    
        int* puzzle;
    };
}

#endif
