//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    static bool comp(pair<int,int> a,pair<int,int> b){
        double x=a.first/(double)(a.second);
        double y=b.first/(double)(b.second);
        return (x > y);
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;i++){
            a[i]={arr[i].value,arr[i].weight};
        }
        sort(a.begin(),a.end(),comp);
        double ans=0;
        for(int i=0;i<n;i++){
            if(a[i].second <= W){
                ans+=(double)a[i].first;
                W-=a[i].second;
            }
            else if(W>0){
                ans+=(double)(double(W)/(double)a[i].second)*a[i].first;
                W=0;
                break;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends