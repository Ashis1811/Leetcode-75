/* 238. Product of Array Except Self

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int prefix = 1;
        for(int i = 0; i < n; i++)
        {
            ans[i] *= prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for(int i = n - 1; i >= 0; i--)
        {
            ans[i] *= postfix;
            postfix *= nums[i];
        }
        return ans;
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
    vector<int> result = solution.productExceptSelf(arr);
    cout <<"The product except self is : " ;
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
 return 0;
}