package bhb;

/**
 * 
 */

/**
 * @author Baran_Hasan_Bozduman_171044036
 *
 */
public class GTUIterator<T>  {
	private Object[] _keepadr;
	private int index;
	private int size;
		
	/**
	 * 
	 * @param o takes object 
	 * @param indexx indicates the index
	 */
	public GTUIterator(Object[] o,int indexx) {
		_keepadr=o;
		size=o.length;
		index=indexx;
		
		
	}
	/**
	 * 
	 * @return returns the value of the given index
	 */
	@SuppressWarnings("unchecked")
	public  T next() {
		return (T)_keepadr[index++];
	}
	/**
	 * checks the container doess it have next element
	 * @return if has next element returns true
	 */
	public boolean hasNext() {
		if((++index)>=size)
			return false;	
		else
			return true;
	}
	/**
	 * iterator to string method
	 */
	@Override
	@SuppressWarnings("unchecked")
	public String toString() {
		String mystr=" ";
		mystr +=(T)_keepadr[index];
		return mystr;
		
		
	}
	
}
