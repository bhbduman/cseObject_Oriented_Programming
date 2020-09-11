package bhb;

/**
 * 
 */

/**
 * @author Baran_Hasan_Bozduman_171044036
 *
 */
public abstract class GTUContainer<T>{

	/**
	 * 
	 */
	public abstract boolean empty();//
	public abstract int size();//
	public abstract int max_size();//
	public abstract boolean insert(T a);//
	public abstract T erase(int index) throws Exception;//
	public abstract void clear();//
	public abstract GTUIterator<T> iterator();//
	public abstract boolean contains(Object o);
	
	

}
