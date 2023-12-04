//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{
    string sum(string s1,string s2){
        int i=s1.size()-1,j=s2.size()-1;
        string ans="";
        int carry=0;
        while(i>=0 && j>=0){
            int a=s1[i--]-'0';
            int b=s2[j--]-'0';
            int x=a+b+carry;
            ans+=(x%10)+'0';
            carry=x/10;
        }
        while(i>=0){
            int a=s1[i--]-'0';
            int x=a+carry;
            ans+=(x%10)+'0';
            carry=x/10;
        }
        while(j>=0){
            int a=s2[j--]-'0';
            int x=a+carry;
            ans+=(x%10)+'0';
            carry=x/10;
        }
        while(carry > 0){
            ans+=(carry%10)+'0';
            carry/=10;
        }
        string t="";
        reverse(ans.begin(),ans.end());
        i=0;
        while(i<ans.size() && ans[i]=='0'){
            i++;
        }
        while(i<ans.size()){
            t+=ans[i];
            i++;
        }
        // cout<<ans<<endl;
        if(t==""){
            t+='0';
        }
        return t;
    }
    bool solve(string &s,int start,int len1,int len2,int n){
        string s1=s.substr(start,len1);
        string s2=s.substr(start+len1,len2);
        string s3=sum(s1,s2);
        if(s3.size()+start+len1+len2 > n){
            return 0;
        }
        if(s.substr(start+len1+len2,s3.size())==s3){
            if(start+len1+len2+s3.size() == n){
                return 1;
            }
            return solve(s,start+len1,len2,s3.size(),n);
        }
        return false;
    }
public:
    int isSumString(string S){
        // code here 
        int n=S.size();
        for(int i=1;i<n;i++){
            for(int j=1;j+i<n;j++){
                if(solve(S,0,i,j,n)){
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.isSumString(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends