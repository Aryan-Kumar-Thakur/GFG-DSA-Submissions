//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	long long int countOnes , countZeroes;
        long long int res = 0;
        int temp = 1;
        for(int i = 0 ; i<32 ; i++){
            countOnes = 0;
            countZeroes = 0;
            for(int j = 0 ; j<n ; j++){
                if(((temp<<i) & arr[j]) != 0){ // Dont use == 1 in the check its decimal check buddy//
                    countOnes++;
                }
                else{
                    countZeroes++;
                }
            }
            
            res += (countOnes * countZeroes) * pow(2 , i);
        }
        return res;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends