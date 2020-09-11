#include"GTUIterator_const.h"
namespace BHB
{   

     template<class T>
    void deleter(T *ptr){} 
    template <class T>
    GTUIterator_const<T>::GTUIterator_const():_keepadr(nullptr)
    {}
    template <class T>
    GTUIterator_const<T>::GTUIterator_const(shared_ptr<T> takeptr):_keepadr(takeptr)
    {}
    template <class T>
    GTUIterator_const<T>::GTUIterator_const(const GTUIterator_const& outiter):_keepadr(outiter._keepadr)
    {}
    template <class T>
    GTUIterator_const<T> GTUIterator_const<T>::operator+(int num){
        shared_ptr<T> temp((this->_keepadr.get()+num),[](T *p){p;});
        this->_keepadr=temp;
        return *this;
    }
    template <class T>
    bool GTUIterator_const<T>::operator==(const GTUIterator_const& isnequal )const{
        return *(_keepadr.get())==*(isnequal._keepadr.get());
    }
    template <class T>
    bool GTUIterator_const<T>::operator!=(const GTUIterator_const& isnequal )const{
        return !(*(_keepadr.get())==*(isnequal._keepadr.get()));
    }
    template <class T>
    const T &GTUIterator_const<T>::operator*()const{
        return *(_keepadr.get());
    }
    template <class T>
    GTUIterator_const<T> GTUIterator_const<T>::operator++(){
        shared_ptr<T> temp((this->_keepadr.get()+1),[](T *p){p;});
        this->_keepadr=temp;
        return *this;
    }
    template <class T>
    GTUIterator_const<T> GTUIterator_const<T>::operator=(GTUIterator_const & newiter){
        this->_keepadr=newiter._keepadr;
        return *this;
    }
    template <class T>
    GTUIterator_const<T> GTUIterator_const<T>::operator++(int ignorme){
        GTUIterator_const temp(*this);
        operator++();
        return temp;
    }
    template <class T>
    GTUIterator_const<T> GTUIterator_const<T>::operator--(){
        shared_ptr<T> temp((this->_keepadr.get()-1),[](T *p){p;});
        this->_keepadr=temp;
        return *this;
    }
    template <class T>
    GTUIterator_const<T> GTUIterator_const<T>::operator--(int ignorme){
        GTUIterator_const temp(*this);
        operator--();
        return temp;
    }

}
 
