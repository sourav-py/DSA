/*
GEEKSFORGEEKS PROBLEM: Given a binary array arr of size N and an integer M. Find the maximum number of consecutive 1's produced
by flipping at most M 0's.
*/


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    // m is maximum of number zeroes allowed to flip
    // n is size of array
    int findZeroes(int arr[], int n, int m) {
        // code here
        queue<int> flipped;
        int flips = m;
        
        int max_seq_len = 0;
        int curr_seq_len = 0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == 1)
            {
                curr_seq_len += 1;
            }
            else
            {
                if(flips)
                {
                    curr_seq_len += 1;
                    flips -= 1;
                    flipped.push(i);
                }
                else
                {
                    if(flipped.empty())
                    {
                        curr_seq_len = 0;
                    }
                    else
                    {
                        int left_most_flip = flipped.front();
                        flipped.pop();
                        curr_seq_len = i - left_most_flip;
                        flipped.push(i);
                    }
                }
            }
            
            //cout<<"i: "<<i<<"\t"<<curr_seq_len<<endl;
            
            max_seq_len = max(max_seq_len,curr_seq_len);
            
           
        }
        
         return max_seq_len;
        
    }  
};


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, i, m;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> m;
        Solution ob;
        auto ans = ob.findZeroes(arr, n, m);
        cout << ans << "\n";
    }
    
    return 0;
}