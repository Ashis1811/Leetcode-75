/* 334. Increasing Triplet Subsequence

Given an integer array nums, return true if there exists a triple of indices (i, j, k) such that i < j < k and nums[i] < nums[j] < nums[k]. 
If no such indices exists, return false.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini1 = INT_MAX;
        int mini2 = INT_MAX;
        for(auto n : nums)
        {
            if(n <= mini1) mini1 = n; //first small num
            else if(n <= mini2) mini2 = n; //second small num
            else return true;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    int n;
    cout <<"Enter array length " << endl;
    cin >>n;
    vector<int> arr(n);
    cout << "Enter elements ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool result = solution.increasingTriplet(arr);
    cout <<"Result is : " << (result ? "True " : "False") << endl; 
return 0;
}