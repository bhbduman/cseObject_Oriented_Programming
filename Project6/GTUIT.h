#ifndef GTUIT_H
#define GTUIT_H

#include<iostream>
#include<memory>

using namespace std;
namespace BHB{
    template <class T>
    class GTUIterator
    {
        public:
            GTUIterator();
            GTUIterator(shared_ptr<T>);
            GTUIterator(const GTUIterator&);
            GTUIterator operator++();
            GTUIterator operator++(int );
            GTUIterator operator--(int );
            GTUIterator operator--();
            GTUIterator operator+(int num);
            GTUIterator operator-(int num);
            bool operator==(const GTUIterator&)const;
            bool operator!=(const GTUIterator&)const;
            //GTUIterator operator=(int);
            T& operator*();
            T* operator->();
            //GTUIterator operator=(GTUIterator &);
            shared_ptr<T> getadr(){return _keepadr;}
        private:
            shared_ptr<T> _keepadr;

    };
}    
#endif