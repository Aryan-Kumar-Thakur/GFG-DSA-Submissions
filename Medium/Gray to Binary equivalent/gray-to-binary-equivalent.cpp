//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        
        // Your code here
        vector<int> temp;
        while(n){
            temp.push_back(n%2);
            n/=2;
        }
        reverse(temp.begin(),temp.end());
        int x=temp.size()-1;
        int ans=0;
        for(int i=0;i<temp.size();i++){
            if(i>0){
                temp[i]=(temp[i]^temp[i-1]);
            }
            if(temp[i]==1){
                ans+=pow(2,x);
            }
            x--;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends