package bhb;
/**
 * 
 */

/**
 * @author Baran_Hasan_Bozduman_171044036
 *
 */
public abstract class Extra<T> extends GTUContainer<T>{

	/**
	 * 
	 */
	protected Object[] myarray;
	protected int size;
	protected int capacity;
	protected int maxsize=1000;
	/**
	 * No-parameter constructor
	 * it makes capacity 1
	 */
	public Object getterObj () {
		return myarray;
	}
	public Extra() {
		size=0;
		capacity=1;
		myarray =new Object[capacity]; 
	}
	public Extra(int c) {
		capacity=c;
		myarray =new Object[capacity];
		size=0;
	}
	/**
	 * the empty method checks the is the container is empty or not
	 * @return if its empty returns true
	 */
	//@Override
	public boolean empty() {
		if(size == 0)
			return true;
		return false;
	}
	/**
	 * @return the value of size
	 */
	//@Override
	public int size() {
		return size;
	}
	/**
	 * @return the value of max size
	 */
	//@Override
	public int max_size() {
		return maxsize;
	}
	/**
	 * insert method with a data parameter it add end of the container
	 * @param data the value which will be add
	 */
	@Override
	public boolean insert(T data) {
		int change=size;
		if(myarray==null)
			myarray = new Object[capacity];
		if(size>=this.capacity){
            if(capacity>=maxsize)
            	return false;
            
			capacity*=10;
            Object[] bigger = new Object[capacity];
            
            for(int i=0; i<size; i++)
            	bigger[i] = myarray[i];              
            
            myarray=(Object[]) bigger;
        }
        myarray[size]=data;
        size++;
        if (change<size)
        	return true;
        return false;
        
		
	}
	/**
	 * erase method
	 * @param delete index of the array which will be deleted
	 * @return the deleted value
	 */
	@Override
	@SuppressWarnings("unchecked")
	public T erase(int delete) throws Exception{
		if(delete<0 |delete>this.size())
			throw new Exception("out of bound");
		T  deleted = (T) myarray[delete] ;
        for ( int i = delete; i!=size; i++)
        	myarray[i]=myarray[i+1];
        
        --size;	
        return deleted;
	}
	
	/**
	 * it clear all values from container
	 */
	@Override
	public void clear() {
		myarray=null;
		size=0;
	}
	/**
	 * @return an iterator which is the beginning of the container
	 */
	@Override
	public GTUIterator<T> iterator() {
		GTUIterator<T> iter= new GTUIterator<T>(this.myarray,0);
		return iter;
	}
	/**
	 * @param o takes type of object 
	 * @return true if the there is a object like the given parameter
	 */
	@Override
	@SuppressWarnings("unchecked")
	public boolean contains(Object o) {
		for(int i=0; i<size; i++)
			if((T)o== (T)myarray[i])
				return true;
		return false;
	}
	/**
	 * override toString method which is print the values in the container
	 */
	@Override
	@SuppressWarnings("unchecked")
	public String toString() {
		String mystr="";
		
		for(int i=0; i<size; i++)
			mystr+= " "+((T)myarray[i]);
		return mystr;
	}

}
