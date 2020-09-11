 #include"GTUSet.h"
  namespace BHB
 {
    template<class T>
    GTUSet<T>::GTUSet(int numallocate):_size(0),_capacity(numallocate*2){
        _dynar=(make_shared<T>(_capacity));     
    }
    template<class T>
    GTUSet<T>::GTUSet():_size(0),_capacity(1){
        _dynar=(make_shared<T>(_capacity)); 
    }
    template<class T>
    GTUSet<T> GTUSet<T>::operator=(GTUSet<T>& outter){
        _size=outter.size();
        _capacity=outter._capacity;
        shared_ptr<T>bigger(new T[_capacity],deleter<T>);
            for(int i=0; i<_size; i++)
               *(bigger.get()+i)=*(outter._dynar.get()+i);
            _dynar=bigger;
            return *this;       
    }
    template<class T>
    GTUSet<T>::GTUSet(GTUSet& outter):_size(outter.size()),_capacity(outter._capacity){
        shared_ptr<T>bigger(new T[_capacity],deleter<T>);
            for(int i=0; i<_size; i++)
               *(bigger.get()+i)=*(outter._dynar.get()+i);  
                
            //_dynar=nullptr;
            _dynar=bigger;       
    }
    template<class T>
    bool GTUSet<T>::empty() const{
        if(_size==0)
            return true;

        return false;    
    }
    template<class T>
    int GTUSet<T>::size() const{
        return _size;
    }
    template<class T>
    int GTUSet<T>::max_size() const{
        return _maxsize;
    }
    template<class T>
    GTUIterator<T> GTUSet<T>::begin(){
        GTUIterator<T> begin(this->_dynar);
        return begin;
    }
    template<class T>
    GTUIterator<T> GTUSet<T>::end(){
        shared_ptr<T> ennd(this->_dynar.get()+this->_size-1,deleter<T>);
        GTUIterator<T> end(ennd);
        //GTUIterator end(this->_dynar+this->size());
        return end;
    }
    template<class T>
    GTUIterator<T> GTUSet<T>::erase(GTUIterator<T> willdeleted){
        int  i;
        for (  i = 0; willdeleted.getadr().get()+i!=end().getadr().get(); i++)
        {
            *(willdeleted.getadr().get()+i)=*(willdeleted.getadr().get()+i+1);
           // cerr<<"::::::::::::\n";
        }
        _size--;

        //shared_ptr<T> dupl(this->_dynar.get()+i,/*[](T *p){}*/ deleter<T>);
        //*(willdeleted.getadr().get()+i)=nullptr;
        return willdeleted;
        
    }
    template<class T>
    void GTUSet<T>::clear(){
        this->makenull();
        _size=0;
    }
    template<class T>
    void GTUSet<T>::insert(T data){
        for (int i = 0; i < this->size(); i++)
        {
            if(*(_dynar.get()+i)==data){
                throw bad_pafram("The data already exist!!!!!");
               // cout<<"Already there is a member which named is '"<<data<<"'"<<endl;
                return;
            }
        }
        

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
    GTUSet<T>::~GTUSet(){}

 }
