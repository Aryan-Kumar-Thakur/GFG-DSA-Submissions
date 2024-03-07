//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    vector<int> arr(26,0);
	    int n=s.size();
	    for(int i=0;i<n;i++){
	        arr[s[i]-'a']++;
	    }
	    int maxfreq=0;
	    int del=0;
	    for(int i=0;i<26;i++){
	        if(arr[i]!=0){
	            if(maxfreq==0){
	                maxfreq=arr[i];
	            }
	            else{
	                del+=abs(maxfreq-arr[i]);
	            }
	        }
	    }
	    return (del <= 1);
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends