/*
 GEEKSFORGEEKS PROBLEM: Given an array arr[] of N positive integers. Find maximum value of |arr[i] – arr[j]| + |i – j|,
  (0 <= i, j <= N – 1)

*/


#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int maxValue(int arr[], int N) {
        
        /*
        Mod(arr[i]-arr[j]) + mod(i - j) gives four cases:
        1. (arr[i] + i) - (arr[j] + j)
        2. (arr[j] - j) - (arr[i] - i)
        3. (arr[i] - i) - (arr[j] - j)
        4. (arr[j] + j) - (arr[i] + i)
        
        */
        
        //Minimum and Maximum value of (arr[i] - i)
        int el_minus_ind_min = INT_MAX;
        int el_minus_ind_max = INT_MIN;
        
        
        //Minimum and maximum value of (arr[i] + i)
        int el_plus_ind_min = INT_MAX;
        int el_plus_ind_max = INT_MIN;
        
        for(int i=0;i<N;i++)
        {
            el_minus_ind_max = max(el_minus_ind_max,arr[i]-i);
            el_minus_ind_min = min(el_minus_ind_min,arr[i]-i);
            
            el_plus_ind_max = max(el_plus_ind_max,arr[i]+i);
            el_plus_ind_min = min(el_plus_ind_min,arr[i]+i);
        }
        
        int caseOneMax = el_plus_ind_max - el_plus_ind_min; // for subcases 1 and 4
        int caseTwoMax = el_minus_ind_max - el_minus_ind_min; //for subcases 2 and 3
        
        int maxDiffValue = max(caseOneMax,caseTwoMax);
        
        return maxDiffValue;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int arr[N];
        
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution ob;
        cout << ob.maxValue(arr,N) << endl;
    }
    return 0;
}  // } Driver Code Ends