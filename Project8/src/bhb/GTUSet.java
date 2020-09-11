package bhb;

/**
 * 
 */

/**
 * @author Baran_Hasan_Bozduman_171044036
 *
 */
public class GTUSet<T> extends Extra<T>{

	/**
	 * no-parameter constructor 
	 * calls Extra class constructor 
	 */
	public GTUSet() {
		super();
	}
	/**
	 * 
	 * @param c the capacity size
	 */
	public GTUSet(int c) {
		super(c);
	}
	/**
	 * copy constructor of set
	 * @param copy the object wihich will be copy
	 */	
	public GTUSet(GTUSet<T> copy) {
		this.capacity = copy.capacity;
		this.size = copy.size();
		this.maxsize = copy.maxsize;
		for(int i= 0; i<size; i++)
			this.myarray[i] = copy.myarray[i];
	}
	/**
	 * clone for set
	 */
	@Override
	public GTUSet<T> clone() {
		GTUSet<T> neww = new GTUSet<T>(this.size());
		for(int i=0; i<size; i++) {
			neww.myarray[i]= myarray[i];
		}
		return neww;
	}
	/**
	 * override equals method for set
	 * @param out the object which will be compared
	 * @return true if they are equal
	 */
	//@Override
	public boolean equals(GTUSet<T> out) {
		if (out==null)
			return false;
		if (!(out instanceof Extra))
			return false;		
		for(int i=0; i<size; i++) {
			if(out.myarray[i]!= myarray[i])
				return false;
		if (out ==this)
			return true;	
		}
		return true;
	}
	
	/**
	 * method insert for the set it checks the given data
	 */
	@SuppressWarnings("unchecked")
	@Override
	public boolean insert(T data) {
		for(int i=0; i<size; i++)
		if(data== (T)myarray[i])
			return false;
		super.insert(data);
			return true;
	} 
	/**
	 * takes data to delete it from set
	 * @param data value
	 * @return deleted element
	 */
	@SuppressWarnings("unchecked")
	public T erase(T data)throws Exception {
		int delete=999;
		if(this.contains(data))
			throw new Exception("There is no data "+data);
		for(int i=0; i<size; i++)
			if(data== (T)myarray[i])
				delete=i;
		super.erase(delete);
		return data;
	}

}
