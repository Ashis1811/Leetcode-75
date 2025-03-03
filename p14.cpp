/* 643. Maximum Average Subarray I

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation 
error less than 10-5 will be accepted.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        double avg = 0;
        int sum = 0;
        int n = nums.size();
        for(int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        avg = sum * 1.0 / k;
        ans = avg;
        for(int i = k; i < n; i++)
        {
            sum += nums[i] - nums[i - k];
            avg = sum * 1.0 / k;
            ans = max(ans, avg);
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
    int k;
    cout <<"Enter k value : ";
    cin >> k;
    double result = solution.findMaxAverage(arr, k);
    cout << "Maximum Average Subarray : " << result << endl;
    
return 0;
}