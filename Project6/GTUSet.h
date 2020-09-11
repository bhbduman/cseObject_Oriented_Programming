#ifndef GTUSET_H
#define GTUSET_H

#include <iostream>
#include "GTUC.h"
#include <memory>
//#include"GTUIT.h"
#include "GTUIT.h"

using namespace std;
namespace BHB
{
    template<class T>
    class GTUSet :public GTUContainer<T>
    {
        public:
            GTUSet();//
            GTUSet(GTUSet& );
            GTUSet operator=(GTUSet&);
            ~GTUSet();
            GTUSet(int numallocate);//
            bool empty()   const;//
            int  size()    const;//
            int  max_size() const;//
            void insert(T data);//
            //void insert(GTUIterator& ,T);
            void clear();
            GTUIterator<T> begin();
            GTUIterator<T> end();
            GTUIterator<T> erase(GTUIterator<T>);
            shared_ptr<T> getadr(){return _dynar;}
        private:
            shared_ptr<T> makenull(){return _dynar=nullptr;}
            int _maxsize=10000;
            int _size;
            int _capacity;
            shared_ptr<T> _dynar;
    };
}





#endif