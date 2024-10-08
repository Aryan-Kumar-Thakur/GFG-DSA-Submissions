//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++

# define PII pair<int,pair<int,int>>

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        priority_queue<PII,vector<PII>,greater<PII>> pq;
        int n=K*K;
        vector<int> ans(n,0);
        for(int i=0;i<K;i++){
            pq.push({arr[i][0],{i,0}});
        }
        int ind=0;
        while(ind<n){
            auto t=pq.top();
            pq.pop();
            ans[ind++]=t.first;
            int i=t.second.first,j=t.second.second;
            if(j<K-1){
                pq.push({arr[i][j+1],{i,j+1}});
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends