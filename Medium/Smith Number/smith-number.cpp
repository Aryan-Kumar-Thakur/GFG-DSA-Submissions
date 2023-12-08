//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    bool isprime(int n){
        for(int i=2;i<n;i++){
            if(n%i == 0){
                return false;
            }
        }
        return true;
    }
  public:
    int smithNum(int n) {
        // code here
        // vector<int> prime(1e5+1,1);
        // sieve(prime);
        if(isprime(n)){
            return 0;
        }
        int sumofdigit=0;
        int x=n;
        while(x){
            sumofdigit+=(x%10);
            x=x/10;
        }
        int sumprimefactor=0;
        vector<int> arr;
        for(int i=2;i<=n;i++){
            while(!(n%i)){
                arr.push_back(i);
                n/=i;
            }
        }
        for(int i=0;i<arr.size();i++){
            x=arr[i];
            while(x){
            sumprimefactor+=(x%10);
            x=x/10;
        }
        }
        return (sumprimefactor == sumofdigit);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends