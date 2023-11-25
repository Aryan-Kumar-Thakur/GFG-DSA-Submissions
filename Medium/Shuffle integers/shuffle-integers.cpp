//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	int mx=1e5;
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	    int s=1,e=n/2;
	    for(int i=1;i<n;i++){
	        if(i&1){
	            arr[i]=(arr[e++]%mx)*mx + (arr[i]%mx);
	        }
	        else{
	            arr[i]=(arr[s++]%mx)*mx + (arr[i]%mx);
	        }
	    }
	    for(int i=1;i<n;i++){
	        arr[i]=arr[i]/mx;
	    }
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
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends