//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long cnt=0;
        int maxi=-1e5;
        int st=0;
        int maxindex=0;
        for(int i=0;i<n;i++){
            if(a[i]>=maxi){
                maxi=a[i];
            }
            maxi=max(maxi,a[i]);
            if(maxi >= L && maxi <= R && a[i]>=L){
                cnt+=(i-st+1);
                maxindex=i;
            }
            else if(maxi >= L && maxi <= R && a[i] < L){
                cnt+=(maxindex-st+1);
            }
            else if(maxi > R){
                st=i+1;
                maxi=0;
            }
            // cout<<cnt<<endl;
        }
        return cnt;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends