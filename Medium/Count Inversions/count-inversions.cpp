//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long merge(long long arr[], int low, int mid, int high)
    {
        long long count = 0; //for keep track of count inversion
        vector<long long> temp;
        int i = low;
        int j = mid + 1;
        while(i <= mid && j <= high)
        {
            if(arr[i] > arr[j])
            {
                count = count + (mid - i + 1);
                temp.push_back(arr[j]);
                j++;
            }
            else
            {
                temp.push_back(arr[i]);
                i++;
            }
        }
        while(i <= mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= high)
        {
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i = low; i <= high; i++)
        {
            arr[i] = temp[i - low];
        }
        
        return count;
    }
    
    long long mergesort(long long arr[], int low, int high)
    {
        long long count = 0;
        
        if(low < high)
        {
            int mid = low + (high - low)/2;
            count = count + mergesort(arr, low, mid);
            count = count + mergesort(arr, mid + 1, high);
            count = count + merge(arr, low, mid, high);
        }
        return count;
    }
    
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        int low = 0;
        int high = N-1;
        long long int ans = mergesort(arr, low, high);
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends