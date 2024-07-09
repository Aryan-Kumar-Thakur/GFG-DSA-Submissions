//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int ans=-1;
        int mindiff=INT_MAX;
        for(int i=0;i<n;i++){
            int j=i+1,k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                int diff=abs(sum-target);
                if(diff < mindiff){
                    mindiff=diff;
                    ans=sum;
                }
                else if(diff == mindiff){
                    ans=max(ans,sum);
                }
                if(sum > target){
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    return  target;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends