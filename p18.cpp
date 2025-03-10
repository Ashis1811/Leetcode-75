/*
1732. Find the Highest Altitude
There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.
You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int alt = 0;
            int sum = 0;
            for(int i = 0; i < gain.size(); i++)
            {
                sum += gain[i];
                alt = max(alt, sum);
            }
            return alt;
        }
    };
    int main()
    {
        Solution solution;
        int n;
        cout<<"Enter array length : ";
        cin >> n;
        vector<int> gain(n);
        cout<<"Enter elements : ";
        for(int i = 0; i < n; i++)
        {
            cin >> gain[i];
        }
        int result = solution.largestAltitude(gain);
        cout<<" The altitudes are : "<<result;
        return 0;
    }
    