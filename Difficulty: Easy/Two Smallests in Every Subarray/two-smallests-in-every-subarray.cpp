//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int pairWithMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        if(n<2){
            return -1;
        }
        int i =0,j=0 ;
      int ans =0 ;
       
       while(j<n){
           
           int len = j-i+1;
            
            int sum = arr[i]+arr[j] ;
          
          if( len>=2){
              ans=max(sum,ans);
               sum-=arr[i];
               i++;
                
          }
           
           j++;
            
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();

    while (tc--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> a;
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        int res = obj.pairWithMaxSum(a);
        cout << res << endl;
    }
}
// } Driver Code Ends