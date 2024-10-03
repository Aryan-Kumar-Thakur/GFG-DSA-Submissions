//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        int n=nums.size();
        int a=nums[0],b=nums[1];
        int cnt1=1,cnt2=1;
        for(int i=2;i<n;i++){
            if(nums[i]==a){
                cnt1++;
            }
            else if(nums[i]==b){
                cnt2++;
            }
            else if(cnt1==0 && nums[i]!=b){
                a=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=a){
                b=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        // cout<<a<<" "<<b<<endl;
        cnt1=0,cnt2=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]==a){
                cnt1++;
            }
            else if(nums[i]==b){
                cnt2++;
            }
        }
        // cout<<cnt1<<" "<<cnt2<<endl;
        int x=n/3;
        if(cnt1>x){
            ans.push_back(a);
        }
        if(cnt2>x){
            ans.push_back(b);
        }
        if(ans.size()==0){
            return {-1};
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends