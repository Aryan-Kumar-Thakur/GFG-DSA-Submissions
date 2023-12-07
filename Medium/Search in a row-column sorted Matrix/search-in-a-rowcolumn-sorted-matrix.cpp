//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends


class Solution
{
    bool find(vector<int> &arr,int n,int m,int x){
        int lo=0,hi=m-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(arr[mid]==x){
                return true;
            }
            else if(arr[mid] < x){
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
            // cout<<matrix[sr][sc]<<endl;
        }
        return false;
    }
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) 
    {
        // code here 
        for(int i=0;i<n;i++){
            if(find(matrix[i],n,m,x)){
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() 
{ 
	int t;
    cin>>t;
    while(t--)
    {

 		int n, m;
    	cin>> n>> m;
        vector<vector<int> > matrix(n);
            
        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        int x;
        cin>>x;
        Solution obj;
        if (obj.search(matrix,n,m,x)) 
            cout << "1\n"; 
        else
            cout << "0\n"; 
    }
	return 0; 
} 


// } Driver Code Ends