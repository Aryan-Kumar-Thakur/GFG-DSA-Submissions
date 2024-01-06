//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    // bool f=0;
    // void allprime(vector<int> &prime){
    //     if(f) return;
    //     f=1;
    //     prime[0]=0;
    //     prime[1]=0;
    //     for(int i=2;i<=2e5;i++){
    //         if(prime[i]){
    //             for(int j=2*i;j<=2e5;j+=i){
    //                 prime[j]=0;
    //             }
    //         }
    //     }
    // }
    int solve(int n){
        int cnt=0;
        while(n%2==0){
            cnt++;
            n/=2;
        }
        for(int i=3;i<=sqrt(n);i=i+2){
            while(n%i==0){
                cnt++;
                n/=i;
            }
        }
        if(n>2) cnt++;
        return cnt;
    }
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    int ans=0;
	   // vector<int> prime(2e5+10,1);
	   // allprime(prime);
	    for(int i=a;i<=b;i++){
	        ans+=solve(i);
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends