/*
724. Find Pivot Index
Given an array of integers nums, calculate the pivot index of this array.
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
Return the leftmost pivot index. If no such index exists, return -1.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int pivotIndex(vector<int>& nums) {
            int n = nums.size();
            int sum = 0;
            for(int i = 0; i < n; i++)
            {
                sum += nums[i];
            }
            int lSum = 0;
            int rSum = sum;
            for(int i = 0; i < n; i++)
            {
                rSum = rSum - nums[i];
                if(rSum == lSum)
                {
                    return i;
                }
                lSum += nums[i];
            }
            return -1;
        }
    };

    int main()
    {
        Solution solution;
        int n;
        cout<<"Enter array length : ";
        cin >> n;
        vector<int> nums(n);
        cout<<"Enter elements : ";
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        int result = solution.pivotIndex(nums);
        cout<<"The pivot index is : "<<result;
        return 0;
    }
    