//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
    static bool comp(pair<int,int> a,pair<int,int> b){
        int diff1=abs(a.first-a.second);
        int diff2=abs(b.first-b.second);
        if(diff1 != diff2){
            return diff1 > diff2;
        }
        else{
            return a.first > b.first;
        }
    }
  public:
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        // code here
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            a.push_back({arr[i],brr[i]});
        }
        sort(a.begin(),a.end(),comp);
        long long ans=0;
        for(int i=0;i<n;i++){
            if(x>0 && a[i].first>=a[i].second){
                ans+=a[i].first;
                x--;
            }
            else if(y>0 && a[i].first<=a[i].second){
                ans+=a[i].second;
                y--;
            }
            else if(x>0){
                ans+=a[i].first;
                x--;
            }
            else if(y>0){
                ans+=a[i].second;
                x--;
            }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends