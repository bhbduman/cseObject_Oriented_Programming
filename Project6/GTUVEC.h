#ifndef GTUVEC_H
#define GTUVEC_H

#include <iostream>
#include "GTUC.h"
#include <memory>
//#include"GTUIT.h"
#include "GTUIT.h"

using namespace std;
namespace BHB
{
    template<class T>
    class GTUVector :public GTUContainer<T>
    {
        public:
            GTUVector();//
            GTUVector(int numallocate);//
            GTUVector(GTUVector&);
            GTUVector operator=(GTUVector&);
            bool empty()   const;//
            int  size()    const;//
            int  max_size() const;//
            void insert(T data);//
            //void insert(GTUIterator& ,T);
            void clear();
            T operator[](int index);//
            GTUIterator<T> begin();
            GTUIterator<T> end();
            GTUIterator<T> erase(GTUIterator<T>);
            shared_ptr<T> getadr(){return _dynar;}
            ~GTUVector();
        private:
            shared_ptr<T> makenull(){return _dynar=nullptr;}
            int _maxsize=10000;
            int _size;
            int _capacity;
            shared_ptr<T> _dynar;
    };
}
#endif 

