//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    int n=paths.size();
	    vector<int> arr(n,0);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(paths[i][j]==1){
	                arr[i]++;
	            }
	        }
	    }
	    for(auto it:arr){
	        if(it&1){
	            return 0;
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>paths(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++)
				cin >> paths[i][j];
		}
		Solution obj;
		int ans = obj.isPossible(paths);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends