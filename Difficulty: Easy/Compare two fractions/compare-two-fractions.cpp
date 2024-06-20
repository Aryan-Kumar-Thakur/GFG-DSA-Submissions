//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        int p = str.find(',');
        
        string num1 = str.substr(0,p);
        string num2 = str.substr(p+2,str.size());
        
        int i = num1.find('/');
        int j = num2.find('/');
        
        double ans1 = (double)stoi(num1.substr(0,i))/(double)stoi(num1.substr(i+1,num1.size()));
        double ans2 = (double)stoi(num2.substr(0,j))/(double)stoi(num2.substr(j+1,num2.size()));
        
        if(ans1 == ans2) return "equal";
        else if(ans1 > ans2) return num1;
        else return num2;
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends