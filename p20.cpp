/*
2215. Find the Difference of Two Arrays
Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:
answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
answer[1] is a list of all distinct integers in nums2 which are not present in nums1.
Note that the integers in the lists may be returned in any order.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
            set<int> s1, s2;
            vector<vector<int>> ans(2);
            for(auto i : nums1)
            {
                s1.insert(i);
            }
            for(auto i : nums2)
            {
                s2.insert(i);
            }
            for(auto i : s1)
            {
                if(s2.find(i) == s2.end())
                {
                    ans[0].push_back(i);
                }
            }
            for(auto i : s2)
            {
                if(s1.find(i) == s1.end())
                {
                    ans[1].push_back(i);
                }
            }
            return ans;
        }
    };

    int main()
    {
        Solution solution;
        int n1, n2;
        cout<<"Enter nums1 length : ";
        cin >> n1;
        vector<int> nums1(n1);
        cout<<"Enter elements : ";
        for(int i = 0; i < n1; i++)
        {
            cin >> nums1[i];
        }
        cout<<"Enter nums2 length : ";
        cin >> n2;
        vector<int> nums2(n2);
        cout<<"Enter elements : ";
        for(int i = 0; i < n2; i++)
        {
            cin >> nums2[i];
        }
        vector<vector<int>> result  = solution.findDifference(nums1, nums2);
        cout<<"The unique elements are : "<<endl;
        cout<<"Present in nums1 not in nums2 ";
        for(auto num : result[0])
        {
            cout << num << " ";
        }
        cout<<endl;
        cout<<"Present in nums2 not in nums1 ";
        for(auto num : result[1])
        {
            cout << num << " ";
        }
        cout<<endl;
        return 0;
    }
    