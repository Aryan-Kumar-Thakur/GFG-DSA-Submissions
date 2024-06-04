//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int s1=0,s2=0;
        for(int i=0;i<n;i++){
            s1+=a[i];
        }
        for(int i=0;i<m;i++){
            s2+=b[i];
        }
        int sum=abs(s1-s2);
        if(sum==0){
            return 1;
        }
        sort(a,a+n);
        sort(b,b+m);
        int i=0,j=m-1;
        while(i<n && j>=0){
            if(2*abs(a[i]-b[j])<sum){
                i++;
            }
            else if(2*abs(a[i]-b[j]) > sum){
                j--;
            }
            else if(2*abs(a[i]-b[j]) == sum){
                return 1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends