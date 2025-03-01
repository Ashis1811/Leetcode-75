/* 283. Move Zeroes
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0 || n == 1) return;
        int left = 0, right = 0;
        int temp;
        while(right < n)
        {
            if(nums[right] == 0) right++;
            else {
                temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
                right++;
                left++;
            }
        }
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
    solution.moveZeroes(arr);
    cout << "After moving zeroes" << " ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
return 0;
}