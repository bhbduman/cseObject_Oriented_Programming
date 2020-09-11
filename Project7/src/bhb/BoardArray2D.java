package bhb;
// File: BoardArray2D.java
// BoardArray2D class with the cell, cellPlace and setSize methods
/**
 * This class inherited from AbstractBoard class
 * It provides you to prepare a puzzle which uses one dimensional arrays
 */

/**
 * @author BARAN_HASAN_BOZDUMAN-171044036
 *
 */
public class BoardArray2D extends AbstractBoard{


	private int puzzle[][];
	
	/**
	    * No-argument constructor set the row and column variables for 3 to 3 board 
	    * @see #setSize(int, int)
	    */
	public BoardArray2D() {
		setSize(3,3);
	}/*
	public BoardArray2D(BoardArray2D copy) {
		this.row=copy.row;				
		this.colum=copy.colum;			
		this.blank_x=copy.blank_x;		
		this.blank_y=copy.blank_y;			
		this.repeat=copy.repeat;
		System.err.println(repeat);
		for(int i=0; i<repeat-1; i++)
			this.puzzle[i]=copy.puzzle[i];
	}
	public BoardArray2D clone() {
		BoardArray2D temp =new BoardArray2D();
		temp.row=row;				
		temp.colum=colum;			
		temp.blank_x=blank_x;		
		temp.blank_y=blank_y;			
		temp.repeat=repeat;
		for(int i=0; i<repeat; i++)
			temp.puzzle[i]=puzzle[i];
		return temp;
	}*/
	/**
	    * Board2D constructor
	    * @param row  row number
	    * @param colum column number
	    * @see #setSize(int, int)
	    */
	public BoardArray2D(int row, int colum) {
		super(row,colum);
		setSize(row,colum);
	}
	
	/**
	    * setSize method
	    * It takes the row and column number and set them by given parameters
	    * @param sizevalue_row row number
	    * @param sizevalue_colum column number
	    * @see #reset()
	    */
	public void setSize(int sizevalue_row,int sizevalue_colum) {
		row=sizevalue_row; colum=sizevalue_colum;
        repeat=row*colum;
        puzzle =new  int[sizevalue_row][sizevalue_colum]/*(-1)*/;
        
        for (int i = 0; i < row; i++) {
        		for(int j =0; j<colum; j++)
        			puzzle[i][j]=-1;
        }
            
        
      reset();
	}
	
	/**
	  * {@inheritDoc}
	  */
	@Override
	protected int cellPlace(int i, int j, int setNumber) {
		puzzle[i][j]=setNumber;
		return setNumber;
	}
	
	/**
	  * {@inheritDoc}
	  */
	@Override
	public int cell(int i, int j) {
		if((i<row & i>=0) & (j<colum & j>=0))
            return puzzle[i][j];
        else
        {
        	System.out.println("Indexes are not valid");
            System.exit(-1);
        }
		return 0;
	}
	
}
