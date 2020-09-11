package bhb;

/**
 * 
 */

/**
 * @author Baran_Hasan_Bozduman_171044036
 *
 */
public class GTUVector<T> extends Extra<T>{
	/**
	 *@see #super()
	 */
	public GTUVector() {
		super();
	}
	public GTUVector(int c) {
		super(c);
	}
	/**
	 * copy constructor of vector
	 * @param copy the object which will be copy
	 */
	public GTUVector(GTUVector<T> copy) {
		this.capacity = copy.capacity;
		this.size = copy.size();
		this.maxsize = copy.maxsize;
		for(int i= 0; i<size; i++)
			this.myarray[i] = copy.myarray[i];
	}
	/**
	 * clone for vector
	 */
	@Override
	public GTUVector<T> clone() {
		GTUVector<T> neww = new GTUVector<T>(this.size());
		for(int i=0; i<size; i++) {
			neww.myarray[i]= myarray[i];
		}
		return neww;
	}
	/**
	 * override equals method for vector
	 * @param out the object which will be compared
	 * @return true if they are equal
	 */
	//@Override
	public boolean equals(GTUVector<T> out) {
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
	

}
