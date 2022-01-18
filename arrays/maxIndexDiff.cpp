// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int N) 
    { 
        // Your code here
        int minIndexFromLeft[N];
        int maxIndexFromRight[N];
        
        minIndexFromLeft[0] = 0;
        maxIndexFromRight[N-1] = N-1;
        
        for(int i=1;i<N;i++)
        {
            if(arr[i] < arr[minIndexFromLeft[i-1]])
                minIndexFromLeft[i] = i;
            else
                minIndexFromLeft[i] = minIndexFromLeft[i-1];
        }
        
        for(int i=N-2;i>=0;i--)
        {
            if(arr[i] > arr[maxIndexFromRight[i+1]])
                maxIndexFromRight[i] = i;
            else
                maxIndexFromRight[i] = maxIndexFromRight[i+1];
        }
        
        int leftPtr = 0;
        int rightPtr = 0;
        
        int maxDiff = 0;
        while(true)
        {
            int i = minIndexFromLeft[leftPtr];
            int j = maxIndexFromRight[rightPtr];
            
            if(arr[i] <= arr[j])
            {
                //stretch rightPointer
                maxDiff = max(maxDiff,j-i);
                if(rightPtr == N-1)
                    break;
                rightPtr += 1;
            }
            else
            {
                //stretch leftPointer
                if(leftPtr == N-1)
                    break;
                leftPtr += 1;
            }
        }
        
        return maxDiff;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends