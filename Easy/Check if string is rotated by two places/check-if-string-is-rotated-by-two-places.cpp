//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size()!=str2.size()){
            return 0;
        }
        int n=str1.size();
        string x(n,'$');
        for(int i=0;i<n;i++){
            x[(i+2)%n]=str1[i];
        }
        string y(n,'$');
        for(int i=0;i<n;i++){
            if(i==0){
                y[n-2]=str1[i];
            }
            else if(i==1){
                y[n-1]=str1[i];
            }
            else{
                y[i-2]=str1[i];
            }
        }
        // cout<<x<<" "<<y<<endl;
        return (str2==x || str2==y);
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends