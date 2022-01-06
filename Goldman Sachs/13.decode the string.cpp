// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) 
        {
            // When ']' is encountered, we need to start
            // decoding
            if (s[i] == ']') 
            {
                string temp;
                while (!st.empty() && st.top() != '[') 
                {
                    // st.top() + temp makes sure that the
                    // string won't be in reverse order eg, if
                    // the stack contains 12[abc temp = c + "" =>
                    // temp = b + "c" => temp = a + "bc"
                    temp = st.top() + temp;
                    st.pop();
                }
                // remove the '[' from the stack
                st.pop();
                string num;
                // remove the digits from the stack
                while (!st.empty() && isdigit(st.top())) 
                {
                    num = st.top() + num;
                    st.pop();
                }
                int number = stoi(num);
                string repeat;
                for (int j = 0; j < number; j++)
                    repeat += temp;
                for (char c : repeat)
                    st.push(c);
            }
            // if s[i] is not ']', simply push s[i] to the stack
            else
                st.push(s[i]);
        }
        string res;
        while (!st.empty()) 
        {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends