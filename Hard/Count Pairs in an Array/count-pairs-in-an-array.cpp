//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    int merge(int arr[],int lo,int mid,int hi){
        int inv=0;
        int l1=mid-lo+1;
        int l2=hi-mid;
        int *left=new int[l1];
        int *right=new int[l2];
        int mind=lo;
        for(int i=0;i<l1;i++){
            left[i]=arr[mind++];
        }
        mind=mid+1;
        for(int i=0;i<l2;i++){
            right[i]=arr[mind++];
        }
        int ind1=0,ind2=0;
        mind=lo;
        while(ind1<l1 && ind2<l2){
            if(left[ind1] <= right[ind2]){
                arr[mind++]=left[ind1++];
            }
            else{
                inv+=(l1-ind1);
                arr[mind++]=right[ind2++];
            }
        }
        while(ind1<l1){
            arr[mind++]=left[ind1++];
        }
        while(ind2<l2){
            arr[mind++]=right[ind2++];
        }
        return inv;
    }
    int mergesort(int arr[],int lo,int hi){
        int inv=0;
        if(lo<hi){
        int mid=lo+(hi-lo)/2;
        inv+=mergesort(arr,lo,mid);
        inv+=mergesort(arr,mid+1,hi);
        inv+=merge(arr,lo,mid,hi);
        }
        return inv;
    }
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here  
        for(int i=0;i<n;i++){
            arr[i]=i*arr[i];
        }
        int inv = mergesort(arr,0,n-1);
        return inv;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends