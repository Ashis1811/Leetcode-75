/* 1431. Kids With the Greatest Number of Candies

There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, 
and an integer extraCandies, denoting the number of extra candies that you have.

Return a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest 
number of candies among all the kids, or false otherwise.

Note that multiple kids can have the greatest number of candies.*/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxEle = *max_element(candies.begin(), candies.end());
        vector<bool> ans;
        for(auto candy : candies)
        {
            int res = candy + extraCandies >= maxEle;
            ans.push_back(res);
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    cout <<" Enter no of test cases "<<endl;
    int t;
    cin >> t;
    while(t--)
    {
        int n, extraCandies;
        cout << "Enter no of kids " << endl;
        cin >> n;
        vector<int> candies(n);
        cout <<"Enter each kids of that array "<<endl;
        for(int i = 0; i < n; i++)
        {
            cin >> candies[i];
        }
        
        cout <<"Enter no of extra candidates " << endl;
        cin >> extraCandies;

        vector<bool> result = solution.kidsWithCandies(candies, extraCandies);
        cout << " Result : ";
        for(bool can : result)
        {
            cout << (can ? "True, " : "False, ");
        }
        cout << endl;
    }

return 0;
}