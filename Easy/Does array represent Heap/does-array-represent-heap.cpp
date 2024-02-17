//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
        for(int i=1;i<n;i+=2){
            if(i<n && (i & 1)){
                if(arr[i] > arr[(i-1)/2]){
                    return 0;
                }
            }
            else if(i<n && (i%2==0)){
                if(arr[i] > arr[(i-2)/2] && arr[i] < arr[i-1]){
                    return 0;
                }
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
       int n;
       cin >> n;
       int a[4*n]={0};
       for(int i =0;i<n;i++){
           cin >> a[i];
       }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends