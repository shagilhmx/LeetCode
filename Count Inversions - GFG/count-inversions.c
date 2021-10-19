// { Driver Code Starts
//Initial Template for C

#include <stdio.h>
#include <stdlib.h>


 // } Driver Code Ends
//User function Template for C


// arr[]: Input Array
// N : Size of the Array arr[]
// Function to count inversions in the array.
long long merge(long long arr[], long long temp[], long p, long q, long r){
    long long i = p, j = q, k = p, inv_count=0;
    while((i <= q-1) && (j <= r)){
        if(arr[i] <= arr[j]) temp[k++] = arr[i++];
        else{
            temp[k++] = arr[j++];
            inv_count = inv_count + (q - i);
        }
    }
    while(i <= q-1) temp[k++] = arr[i++];
    while(j <= r) temp[k++] = arr[j++];
    
    for(i=p;i<=r;i++) arr[i] = temp[i];
    
    return inv_count;
}
long long int _mergeSort(long long arr[], long long temp[], long long start, long long end){
    long long inv_count=0;
    if(end > start){
        long long mid = (start + end)/2;
        inv_count += _mergeSort(arr, temp, start, mid);
        inv_count += _mergeSort(arr, temp, mid+1, end);
        inv_count += merge(arr, temp, start, mid+1, end);
    }
    return inv_count;
}
long long int inversionCount(long long arr[], long long N)
{
    long long temp[N];
    return _mergeSort(arr, temp, 0, N-1);
}



// { Driver Code Starts.

int main() {
    
    long long T;
    scanf("%ld", &T);
    
    while(T--){
        long long N;
        scanf("%ld", &N);
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            scanf("%ld", &A[i]);
        }
        
        printf("%ld\n", inversionCount(A,N) );
    }
    
    return 0;
}
  // } Driver Code Ends