/*
1004. Max Consecutive Ones III
Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int zero = 0, maxLen = 0;
            int left = 0;
            for(int right = 0; right < n; right++)
            {
                if(nums[right] == 0)
                {
                    zero++;
                }
                while(zero > k)
                {
                    if(nums[left] == 0)
                    {
                        zero--;
                    }
                    left++;
                }
                maxLen = max(maxLen, right - left + 1);
            }
            return maxLen;
        }
    };

    int main()
    {
        Solution solution;
        int n, k;
        cout<<"Enter array length : ";
        cin >> n;
        vector<int> nums(n);
        cout<<"Enter elements : ";
        for(int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        cout<<"Enter k value ";
        cin >> k;
        int result = solution.longestOnes(nums, k);
        cout<<"The longest subarray is : "<<result;
        return 0;
    }
    