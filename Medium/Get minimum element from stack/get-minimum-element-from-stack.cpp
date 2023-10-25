//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int mini=0;
    stack<int> st;
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(st.empty()){
               return -1;
           }
           return mini;
           
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
          if(st.empty()){
            return -1;
        }
        int y =st.top();
        if(y>mini){
            st.pop();
        }
        else{
            y=mini;
            mini=2*mini-st.top();
            st.pop();
        }
        return y;
       }
       
       /*push element x into the stack*/
       void push(int val){
           
           //Write your code here
           if(st.empty()){
            st.push(val);
            mini=val;
        }
        else if(val > mini){
            st.push(val);
        }
        else{
            st.push(2*val-mini);
            mini=val;
        }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends