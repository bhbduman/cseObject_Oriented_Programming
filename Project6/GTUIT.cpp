#include"GTUIT.h"
namespace BHB
{

     template<class T>
    void deleter(T *ptr){} 
    template<class T>
    GTUIterator<T>::GTUIterator():_keepadr(nullptr)
    {}
    template<class T>
    GTUIterator<T>::GTUIterator(shared_ptr<T> takeptr):_keepadr(takeptr)
    {}
    template<class T>
    GTUIterator<T>::GTUIterator(const GTUIterator& outiter):_keepadr(outiter._keepadr)
    {}
    template<class T>
    GTUIterator<T> GTUIterator<T>::operator+(int num){
        shared_ptr<T> temp((this->_keepadr.get()+num),[](T *p){p;});
        this->_keepadr=temp;
        return *this;
    }
    template<class T>
    bool GTUIterator<T>::operator==(const GTUIterator& isnequal )const{
        return *(_keepadr.get())==*(isnequal._keepadr.get());
    }
    template<class T>
    bool GTUIterator<T>::operator!=(const GTUIterator& isnequal )const{
        return !(*(_keepadr.get())==*(isnequal._keepadr.get()));
    }
    template<class T>
    T &GTUIterator<T>::operator*(){
        return *(_keepadr.get());
    }
    template<class T>
    GTUIterator<T> GTUIterator<T>::operator++(){
        shared_ptr<T> temp((this->_keepadr.get()+1),deleter<T>);
        this->_keepadr=temp;
        return *this;
    }
    /*GTUIterator GTUIterator::operator=(GTUIterator & newiter){
        this->_keepadr= newiter._keepadr;
        return *this;
    }*/
    template<class T>
    GTUIterator<T> GTUIterator<T>::operator++(int ignorme){
        GTUIterator temp(*this);
        operator++();
        return temp;
    }
    template<class T>
     T* GTUIterator<T>::operator->(){
        return _keepadr.get();
    }
    template<class T>
    GTUIterator<T> GTUIterator<T>::operator--(){
        shared_ptr<T> temp((this->_keepadr.get()-1),deleter<T>);
        this->_keepadr=temp;
        return *this;
    }
    template<class T>
    GTUIterator<T> GTUIterator<T>::operator--(int ignorme){
        GTUIterator temp(*this);
        operator--();
        return temp;
    }
}
