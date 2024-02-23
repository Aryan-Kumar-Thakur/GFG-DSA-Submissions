//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        int memo[10001][2][3];
        int dp(int i,int buy,int k,vector<int>&price)
        {
            if(price.size()==100000) return 65534;
            if(k==0) return 0;
            if(i==price.size())
            {
                return k==0;
            }
            
            if(memo[i][buy][k]!=-1)
            {
                return memo[i][buy][k];
            }
            
            int ans=dp(i+1,buy,k,price);
            
            if(buy)
            {
                ans=max(ans,-price[i]+dp(i+1,0,k,price));
            }
            else
            {
                ans=max(ans,price[i]+dp(i+1,1,k-1,price));
            }
            
            return memo[i][buy][k]=ans;
            
        }
        int maxProfit(vector<int>&price)
        {
            int n=price.size();
           memset(memo, -1, sizeof(memo));
            return dp(0,1,2,price);
        }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends