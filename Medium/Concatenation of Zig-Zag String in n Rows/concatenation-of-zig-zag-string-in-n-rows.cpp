//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    string convert(string s, int n) {
        //code
        if(n==1){
            return s;
        }
        int m=s.size();
        int st=(n+(n-2));
        int k=0;
        string ans="";
        for(int i=st;i>=0 && k<n;i-=2){
            bool f=1;
            int j=k;
            if(i==st || i==0){
                while(j<m){
                    ans+=s[j];
                    j+=st;
                }
            }
            else{
                bool f=1;
                while(j<m){
                    if(f){
                        ans+=s[j];
                        j+=i;
                        f=0;
                    }
                    else{
                        ans+=s[j];
                        j+=(st-i);
                        f=1;
                    }
                }
            }
            k++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while (t--){
        string str;
        cin>>str;
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.convert(str, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends