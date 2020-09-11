 #include"GTUVEC.h"
  namespace BHB
 {
   
    template<class T>
    GTUVector<T>::GTUVector(int numallocate):_size(0),_capacity(numallocate*2){
        _dynar=(make_shared<T>(_capacity));     
    }
    template<class T>
    GTUVector<T> GTUVector<T>::operator=(GTUVector<T>& outter){
        _size=outter.size();
        _capacity=outter._capacity;
        shared_ptr<T>bigger(new T[_capacity],deleter<T>);
            for(int i=0; i<_size; i++)
               *(bigger.get()+i)=*(outter._dynar.get()+i);  
                
            //_dynar=nullptr;
            _dynar=bigger;
            return *this;       
    }   
    template<class T>
    GTUVector<T>::GTUVector():_size(0),_capacity(1){
        _dynar=(make_shared<T>(_capacity)); 
    }
    template<class T>
    GTUVector<T>::GTUVector(GTUVector<T>& outter):_size(outter.size()),_capacity(outter._capacity){
        shared_ptr<T>bigger(new T[_capacity],deleter<T>);
            for(int i=0; i<_size; i++)
               *(bigger.get()+i)=*(outter._dynar.get()+i);  
                
            //_dynar=nullptr;
            _dynar=bigger;       
    }

    /*void GTUVector::insert(GTUIterator& insrtaddr,T data){
        shared_ptr<T>secondpart(new T[_capacity+1]);
        
        for(int i=0; insrtaddr!=this->end(); i++)
               *(secondpart.get()+i)=*(insrtaddr.getadr().get()+i);
        cerr<<*(secondpart.get())<<endl;      
    }*/
    template<class T>
    bool GTUVector<T>::empty() const{
        if(_size==0)
            return true;

        return false;    
    }
    template<class T>
    int GTUVector<T>::size() const{
        return _size;
    }
    template<class T>
    int GTUVector<T>::max_size() const{
        return _maxsize;
    }
    template<class T>
    GTUIterator<T> GTUVector<T>::begin(){
        GTUIterator<T> begin(this->_dynar);
        return begin;
    }

    template<class T>
    GTUIterator<T> GTUVector<T>::end(){
        shared_ptr<T> ennd(this->_dynar.get()+this->_size, deleter<T>);
        GTUIterator<T> end(ennd);
        //GTUIterator end(this->_dynar+this->size());
        return end;
    }
    template<class T>
    GTUIterator<T> GTUVector<T>::erase(GTUIterator<T> willdeleted){
        int  i;
        for (  i = 0; willdeleted.getadr().get()+i!=end().getadr().get(); i++)
        {
            *(willdeleted.getadr().get()+i)=*(willdeleted.getadr().get()+i+1);
            //cerr<<"::::::::::::\n";
        }
        _size--;

        //shared_ptr<T> dupl(this->_dynar.get()+i,/*[](T *p){}*/ deleter<T>);
        //*(willdeleted.getadr().get()+i)=nullptr;
        return willdeleted;
        
    }
    template<class T>
    void GTUVector<T>::clear(){
        this->makenull();
        _size=0;
    }
    template<class T>
    void GTUVector<T>::insert(T data){
        if(_size>=_capacity){
            _capacity*=9;
            shared_ptr<T>bigger(new T[_capacity]);
            for(int i=0; i<_size; i++)
               *(bigger.get()+i)=*(_dynar.get()+i);  
                
            //_dynar=nullptr;
            _dynar=bigger;
        }
        *(_dynar.get()+_size)=data;
        _size++;
    }
    template<class T>
    T GTUVector<T>::operator[](int index){
        if(index<0 || index>_size){
            throw("You are out of limits");
        }    
        else    
            return *(_dynar.get()+index); 
    }
    template<class T>
    GTUVector<T>::~GTUVector(){}

 }
