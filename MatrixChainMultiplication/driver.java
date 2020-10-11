package MatrixChainMultiplication;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class driver {

    public static void main(String[] args) throws IOException
	{
        //creating object for matrixMultiplication
        MatrixChainMultiplication_Class obj = new MatrixChainMultiplication_Class();

        File dims = new File("MatrixChainMultiplication_Input.txt");
        List<Integer> lines = new ArrayList<Integer>();

        Scanner in=new Scanner(dims);

        //reading integers
        while(in.hasNextInt())
        {
            lines.add(in.nextInt());
        }

        in.close();
    
        //converting list of Integer to array of int
        int size = lines.size();
        int[] dsMat = new int[size];
        Integer[] temp = lines.toArray(new Integer[size]);
        for (int n = 0; n < size; ++n) {
            dsMat[n] = temp[n];
        }


		// memoization table
		int[][] T = new int[dsMat.length][dsMat.length];

		System.out.print(obj.multiplication(dsMat, 1, dsMat.length - 1, T));

	}
}
