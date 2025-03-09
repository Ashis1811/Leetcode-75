/*
2390. Removing Stars From a String

You are given a string s, which contains stars *.

In one operation, you can:

Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Note:
The input will be generated such that the operation is always possible.
It can be shown that the resulting string will always be unique.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        string removeStars(string s) {
            int n = s.size();
            stack<char> st;
            for(int i = 0; i < n; i++)
            {
                  if(s[i] == '*')
                {
                    st.pop();
                    continue;
                }
                st.push(s[i]);
            }
            string ans = "";
            while(! st.empty())
            {
                ans += st.top();
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };

    int main()
    {
        Solution solution;
        string s;
        cout<<"Enter the string "<<endl;
        cin >> s;
        string result = solution.removeStars(s);
        cout<<"Updated string is : "<<result;
        return 0;
    }
    