import bhb.GTUIterator;
import bhb.GTUSet;
import bhb.GTUVector;

/**
 * 
 */

/**
 * @author Baran_Hasan_Bozduman_171044036
 *
 */
public class driver {

	/**
	 * @param args
	 * @throws Exception for the erase
	 */
	public static void main(String[] args) throws Exception {
		try {
System.out.println("////////////////////////////////////////////FOR VECTOR CLASS/////////////////////////////////////////////////////////////");			
		GTUVector<Integer> a = new GTUVector<Integer>();
		System.out.println("I inserted 1,2,3,4,5");
			a.insert(1);
			a.insert(2);
			a.insert(3);
			a.insert(4);
			a.insert(5);
			System.out.printf("\n\n");
		System.out.println("if we print by using toString");
			System.out.println(a);
			System.out.printf("\n\n");
		System.out.println( "I erased 4th index");
			a.erase(4);
		System.out.println(a);
			System.out.printf("\n\n");
		System.out.println( "does it contain 5");
			if(a.contains(5))
				System.out.println("its  ok");
			else
				System.out.println("it doesnt contain 5");
			System.out.printf("\n\n");
		System.out.println( "does it contain 2");
			if(a.contains(2))
				System.out.println("its  ok");
			else
				System.out.println("it doesnt contain 2");
			GTUIterator<Integer> iter = a.iterator();
			System.out.printf("\n\n");
		System.out.println("iterator() method print by using toString method");
			System.out.println(iter);
			System.out.printf("\n\n");
		System.out.println("max  size");
			System.out.println(a.max_size());
			System.out.printf("\n\n");
		System.out.println("size");
			System.out.println(a.size());
			System.out.printf("\n\n");
		System.out.println("iter.next()");
			System.out.println(iter.next());
			System.out.printf("\n\n");
		System.out.println("iter.has next");	
			System.out.println(iter.hasNext());
		GTUIterator<Integer> iter2 = new GTUIterator<Integer>((Object[]) a.getterObj(), 3);	
			System.out.println(iter2);
			System.out.printf("\n\n");
		System.out.println("clear method");
			a.clear();
			System.out.printf("\n\n");
		System.out.println("is EMpty method");
			if(a.empty())
			System.out.printf("\n\n");
				System.out.println("Its empty");
		System.out.println("insert 9,8,7");	
			a.insert(9);
			a.insert(8);
			a.insert(7);
			System.out.printf("\n\n");
		System.out.println(a);
		System.out.println("To test method function and equals method i also oveerride clone and equals function");
			System.out.printf("\n\n");
		GTUVector<Integer> forclone = new GTUVector<Integer>();
		forclone=a.clone();
			System.out.printf("\n\n");
		if(a.equals(forclone))
			System.out.println("They are equal");
		System.out.println("try to erase outh of vector throws exception");	
			//a.erase(10);
			
		
			
			GTUVector<String> b = new GTUVector<String>();
			System.out.println("I inserted 1,2,3,4,5");
				b.insert("cse241");
				b.insert("cse231");
				b.insert("cse233");
				b.insert("cse211");
				b.insert("cse346");
			System.out.printf("\n\n");
			System.out.println("if we print by using toString");
				System.out.println(b);
			System.out.printf("\n\n");
			System.out.println( "I erased 4th index");
				b.erase(4);
			System.out.println(b);
			System.out.printf("\n\n");
			System.out.println( "does it contain cse346");
				if(b.contains("cse346"))
					System.out.println("its  ok");
				else
					System.out.println("it doesnt contain cse346");
			System.out.printf("\n\n");
			System.out.println( "does it contain cse241");
				if(b.contains("cse241"))
					System.out.println("its  ok");
				else
					System.out.println("it doesnt contain cse241");
			System.out.printf("\n\n");
				GTUIterator<String> iter3 = b.iterator();
			System.out.println("iterator() method print by using toString method");
				System.out.println(iter3);
			System.out.printf("\n\n");
			System.out.println("max  size");
				System.out.println(b.max_size());
			System.out.println("size");
				System.out.println(a.size());
			System.out.printf("\n\n");
			System.out.println("iter.next()");
				System.out.println(iter3.next());
			System.out.printf("\n\n");
			System.out.println("iter.has next");	
				System.out.println(iter3.hasNext());
			GTUIterator<String> iter4 = new GTUIterator<String>((Object[]) b.getterObj(), 3);	
				System.out.println(iter4);
			System.out.println("clear method");
			System.out.printf("\n\n");
				b.clear();
			System.out.printf("\n\n");
			System.out.println("is EMpty method");
				if(b.empty())
					System.out.println("Its empty");
			System.out.println("insert eng101,phy150,phy210");	
				b.insert("eng101");
				b.insert("phy150");
				b.insert("phy210");
			System.out.printf("\n\n");
			System.out.println(b);
			System.out.printf("\n\n");
			System.out.println("try to erase outh of vector throws exception");	
				//b.erase(10);	
			
			
			
			
System.out.println("/////////////////////////////////////FOR SET CLASS//////////////////////////////////////////////////////////////");
			GTUSet<Integer> s = new GTUSet<Integer>();
			System.out.println("I inserted 1,2,3,4,5");
				s.insert(1);
				s.insert(2);
				s.insert(3);
				s.insert(4);
				s.insert(5);
			System.out.printf("\n\n");
			System.out.println("if we print by using toString");
				System.out.println(s);
			System.out.printf("\n\n");
			System.out.println( "I erased 4th index");
				s.erase(4);
			System.out.println(s);
			System.out.printf("\n\n");
			System.out.println( "does it contain 5");
				if(s.contains(5))
					System.out.println("its  ok");
				else
					System.out.println("it doesnt contain 5");
			System.out.printf("\n\n");
			System.out.println( "does it contain 2");
				if(s.contains(2))
					System.out.println("its  ok");
				else
					System.out.println("it doesnt contain 2");
				GTUIterator<Integer> iter6 = s.iterator();
			System.out.printf("\n\n");
			System.out.println("iterator() method print by using toString method");
				System.out.println(iter6);
			System.out.printf("\n\n");
			System.out.println("max  size");
				System.out.println(s.max_size());
			System.out.printf("\n\n");
			System.out.println("size");
				System.out.println(s.size());
			System.out.printf("\n\n");
			System.out.println("iter6.next()");
				System.out.println(iter6.next());
			System.out.printf("\n\n");
			System.out.println("iter.has next");	
				System.out.println(iter6.hasNext());
			System.out.printf("\n\n");
			GTUIterator<Integer> iter7 = new GTUIterator<Integer>((Object[]) s.getterObj(), 3);	
				System.out.println(iter7);
			System.out.printf("\n\n");
			System.out.println("clear method");
				s.clear();
			System.out.printf("\n\n");
			System.out.println("is EMpty method");
				if(s.empty())
					System.out.println("Its empty");
			System.out.printf("\n\n");
			System.out.println("insert 9,8,7");	
				s.insert(9);
				s.insert(8);
				s.insert(7);
			System.out.println(s);
			System.out.printf("\n\n");
			System.out.println("try to erase outh of set throws exception");	
				//s.erase(10);
				
			
				
				GTUSet<String> s2 = new GTUSet<String>();
				System.out.println("I inserted 1,2,3,4,5");
					s2.insert("cse241");
					s2.insert("cse231");
					s2.insert("cse233");
					s2.insert("cse211");
					s2.insert("cse346");
			System.out.printf("\n\n");
				System.out.println("if we print by using toString");
					System.out.println(b);
			System.out.printf("\n\n");
				System.out.println( "I erased 4th index");
					s2.erase(4);
				System.out.println(s2);
			System.out.printf("\n\n");
				System.out.println( "does it contain cse346");
					if(s2.contains("cse346"))
						System.out.println("its  ok");
					else
						System.out.println("it doesnt contain cse346");
			System.out.printf("\n\n");
				System.out.println( "does it contain cse241");
					if(s2.contains("cse241"))
						System.out.println("its  ok");
					else
						System.out.println("it doesnt contain cse241");
			System.out.printf("\n\n");
					GTUIterator<String> iter8 = b.iterator();
				System.out.println("iterator() method print by using toString method");
					System.out.println(iter8);
			System.out.printf("\n\n");
				System.out.println("max  size");
					System.out.println(s2.max_size());
			System.out.printf("\n\n");
				System.out.println("size");
					System.out.println(s2.size());
			System.out.printf("\n\n");
				System.out.println("iter.next()");
					System.out.println(iter8.next());
			System.out.printf("\n\n");
				System.out.println("iter.has next");	
					System.out.println(iter8.hasNext());
				GTUIterator<String> iter9 = new GTUIterator<String>((Object[]) s2.getterObj(), 3);	
					System.out.println(iter9);
				System.out.println("clear method");
					s2.clear();
				System.out.println("is EMpty method");
					if(s2.empty())
						System.out.println("Its empty");
				System.out.println("insert eng101,phy150,phy210");	
					s2.insert("eng101");
					s2.insert("phy150");
					s2.insert("phy210");
				System.out.println(b);
			System.out.printf("\n\n");
				System.out.println("try to erase outh of set throws exception");	
					s2.erase(10);
			
	}catch(Exception e) {
		System.out.println(e.getMessage());
	}
		
	}
}
