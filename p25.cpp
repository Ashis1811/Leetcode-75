/*
735. Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteriod in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            int n = asteroids.size();
            stack<int> st;
            for(int i = 0; i < n; i++)
            {
                if(asteroids[i] > 0)
                {
                    st.push(asteroids[i]);
                }
                else
                {
                    while(! st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
                    {
                        st.pop();
                    }
                    if(! st.empty() && st.top() == abs(asteroids[i]))
                    {
                        st.pop();
                    }
                    else if(st.empty() || st.top() < 0)
                    {
                        st.push(asteroids[i]);
                    }
                }
            }
            vector<int> ans(st.size());
            for(int i = st.size() - 1; i >= 0; i--)
            {
                ans[i] = st.top();
                st.pop();
            }
            return ans;
        }
    };

    int main()
    {
        Solution solution;
        int n;
        cout<<"Enter array length : ";
        cin >> n;
        vector<int> asteroids(n);
        cout<<"Enter elements : ";
        for(int i = 0; i < n; i++)
        {
            cin >> asteroids[i];
        }
        vector<int> result = solution.asteroidCollision(asteroids);
        cout<<"The result is : ";
        for(int num : result)
        {
            cout << num;
        }
        cout<<endl;
        return 0;
    }
    