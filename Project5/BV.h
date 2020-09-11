#ifndef BV_H
#define BV_H

#include <string>
#include<vector>

#include "AB.h"

using  std::vector;
using std::string;

namespace BHB
{
    class BoardVector : public AbstractBoard
    {
    public:    
        BoardVector();
        BoardVector(int,int);
        ~BoardVector();
        int operator ()(int, int)const;
        int &operator ()(int, int);
        void setSize(const int&, const int&);
    private:
        vector<vector<int> >puzzle;    

    };
}
#endif