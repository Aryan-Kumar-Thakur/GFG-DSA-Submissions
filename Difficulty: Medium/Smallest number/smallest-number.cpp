//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
          if(s > d*9){
            return "-1";
        }
        vector<int> vec(d);
        vec[0] = 1;
        int sum = 1,i = d-1;
        while(sum < s && i>=0){
            if(sum + 9 <= s){
                sum += 9;
                vec[i]+=9;
            }else{
                while(sum < s){
                    sum++;
                    vec[i]++;
                }
            }
            i--;
        }
        if(sum < s) return "-1";
        
        string str = "";
        for(int digit : vec){
            str += (char)digit + '0';
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends