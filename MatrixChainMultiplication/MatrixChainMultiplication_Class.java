package MatrixChainMultiplication;

public class MatrixChainMultiplication_Class
{
	public int multiplication(int[] dsMat, int i, int j, int[][] T)
	{
		// base case if only one matrix is there
		if (i == j) {
			return 0;
		}

		// variable to store cost of scalar multiplications
		int min = Integer.MAX_VALUE;

		// if this value is calculted for first time
		if (T[i][j] == 0)
		{
            /*            M[i,j]
                           /\
                          /  \
                         /    \
                   M[i,k]      M[k+1,j]                
            */

			for (int k = i ; k < j; k++)
			{
				            // recur for i x k matrix           // recur for k+1 x j matrix              
                int cost = multiplication(dsMat, i, k, T)  +  multiplication(dsMat, k+1, j, T);

                // cost to multiply two (i x k) and (k+1 x j) matrix
                cost+= dsMat[i-1] * dsMat[k] * dsMat[j];
                
                // take minimum possible cost
				if (cost < min)
					min = cost;
            }
            
            // put in table for future reference
			T[i][j] = min;
		}

		// return min cost to multiply M[i,j]
		return T[i][j];
	}
}