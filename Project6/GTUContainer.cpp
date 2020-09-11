#include "GTUC.h"
namespace BHB
{
    template <class T>
    GTUIterator<T> find (GTUIterator<T> first, GTUIterator<T> last, const T& val){
        while(first.getadr().get()!=last.getadr().get()){
            if(*(first.getadr().get())==val)
                return first;
            ++first;    
        }
        return last;
    }
    template <class T,class B>
    GTUIterator<T> find_if(GTUIterator<T> first, GTUIterator<T> last,B foo){
        while (first.getadr().get()!=last.getadr().get())
        {
            if(foo(*(first.getadr().get())))
                return first;
               
            ++first;
        }
        return last;

    }
    template <class T ,class F>
    F for_each(GTUIterator<T> first,GTUIterator<T> last, F foo){
        while (first!=last){
            foo(*(first.getadr().get()));
            ++first;
        }
        return foo;
        
    }

     template<class T>
    void deleter(T *ptr);   
}