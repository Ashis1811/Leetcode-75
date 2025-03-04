/*
1493. Longest Subarray of 1's After Deleting One Element
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int longestSubarray(vector<int>& nums) {
            int n = nums.size();
            int zero = 0, maxLen = 0;
            int left = 0;
            for(int right = 0; right < n; right++)
            {
                if(nums[right] == 0)
                {
                    zero++;
                }
                while(zero > 1)
                {
                    if(nums[left] == 0)
                    {
                        zero--;
                    }
                    left++;
                }
                maxLen = max(maxLen, right - left);
            }
            return maxLen;
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
        int result = solution.longestSubarray(nums);
        cout<<" size of the longest non-empty subarray "<<result;
        return 0;
    }
    