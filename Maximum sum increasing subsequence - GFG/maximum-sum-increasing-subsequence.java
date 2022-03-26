// { Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    int Arr[] = new int[n];
                    for(int i = 0;i<n;i++)
                        Arr[i] = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.maxSumIS(Arr,n));
                }
        }
}    // } Driver Code Ends


//User function Template for Java

class Solution
{
	public int maxSumIS(int arr[], int n)  
	{  
	    //using recursionusing recursion
	    int[][] dp = new int[n + 1][n + 1];
	    return helper(arr, n, 0, -1, dp);
	}
	
	int helper(int arr[], int n, int index, int prev, int[][] dp) {
	    if(index == n) return 0;
	    
	    if(prev != -1 && dp[prev][index] != 0) return dp[prev][index];
	    
	    int res1 = 0;
	    if(prev == -1 || arr[prev] < arr[index])
	        res1 = arr[index] + helper(arr, n, index + 1, index, dp);
	    int res2 = helper(arr, n, index + 1, prev, dp);
	    
	    if(prev != -1)
	        dp[prev][index] = Math.max(res1, res2);
	    return Math.max(res1, res2);
	}
}