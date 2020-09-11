#ifndef GTUITCONST_H
#define GTUITCONST_H

#include<iostream>
#include<memory>

using namespace std;
namespace BHB{
    template <class T>
    class GTUIterator_const
    {
        public:
            GTUIterator_const();
            GTUIterator_const(shared_ptr<T>);
            GTUIterator_const(const GTUIterator_const&);
            GTUIterator_const operator++();
            GTUIterator_const operator++(int );
            GTUIterator_const operator--(int );
            GTUIterator_const operator--();
            GTUIterator_const operator+(int num);
            GTUIterator_const operator-(int num);
            bool operator==(const GTUIterator_const&)const;
            bool operator!=(const GTUIterator_const&)const;
            GTUIterator_const operator=(int);
            const T& operator*()const;
            GTUIterator_const operator->()const;
            GTUIterator_const operator=(GTUIterator_const &);
            shared_ptr<T> getadr(){return _keepadr;}
        private:
            shared_ptr<T> _keepadr;

    };
}    
#endif 
