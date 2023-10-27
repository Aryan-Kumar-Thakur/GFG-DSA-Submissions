//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        long long cnt=0;
        for(int i=0;i<n;i++){
            A[i]=A[i]%K;
        }
        map<long long,long long> mp;
        for(int i=0;i<n;i++){
            mp[A[i]]++;
        }
        for(int i=0;i<=K/2;i++){
            if(i==0){
                cnt+=(mp[i]*(mp[i]-1))/2;
            }
            else if(K%2==0 && i==K/2){
                cnt+=(mp[i]*(mp[i]-1))/2;
            }
            else{
                cnt+=(mp[i]*mp[K-i]);
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}

// } Driver Code Ends