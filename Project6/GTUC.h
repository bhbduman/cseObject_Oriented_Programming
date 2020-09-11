#ifndef GTUC_H
#define GTUC_H
#include<iostream>
#include "GTUIT.h"
#include <string>
#include <exception>
#include<string>

using namespace std;

namespace BHB
{
    template<class T>
    class GTUContainer
    {
        public:
            virtual bool empty() const=0;
            virtual int size() const=0;
            virtual int max_size() const=0;
            virtual void insert(T data) =0;
            virtual GTUIterator<T> erase(GTUIterator<T>)=0;
            virtual void clear()=0;
            virtual GTUIterator<T> begin()=0;
            virtual GTUIterator<T> end()=0;
    };
    template <class T>
    GTUIterator<T> find (GTUIterator<T>, GTUIterator<T>, const T&);
    template <class T,class B>
    GTUIterator<T> find_if(GTUIterator<T> first, GTUIterator<T> last,B foo);
    template <class T ,class F>
    F for_each(GTUIterator<T> first,GTUIterator<T> last, F foo); 
    /*If we specified the shared ptr constructur it uses  normally default delete function adn i create a function for delete but i
    dont make delete in my delete function an when we send my delete function instead default delete function it doesnt make delete 
    so we can use it with ++ or -- operator and  thus it can not delete twice */
    template <class T>
    void deleter(T *ptr);
    
} 
namespace std
{
    class bad_pafram{
        public:
            bad_pafram( string take):error(take){};
            void geterror()const{ cout<<error;}
        private:
            string error;

    };
}   

#endif