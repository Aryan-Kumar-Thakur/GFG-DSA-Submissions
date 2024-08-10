//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool comp(Job a,Job b){
        return (a.profit > b.profit);
    }
    // bool solve(vector<int> &temp,Job a){
    //     int lo=1,hi=a.dead;
    //     while(lo<=hi){
    //         int mid=lo+(hi-lo)/2;
    //         if(temp[mid]==1){
    //             hi=mid-1;
    //         }
    //         else{
    //             lo=mid+1;
    //         }
    //     }
    //     if(temp[lo]==0){
    //         cout<<lo<<endl;
    //         temp[lo]=1;
    //         return true;
    //     }
    //     return false;
    // }
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,comp);
        int cnt=0,profit=0;
        vector<int> temp(1e5,0);
        for(int i=0;i<n;i++){
            // cout<<arr[i].profit<<endl;
            int x=arr[i].dead;
            while(x>0 && temp[x]==1){
                x--;
            }
            if(x>0){
                cnt++;
                profit+=arr[i].profit;
                temp[x]=1;
            }
        }
        return {cnt,profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends