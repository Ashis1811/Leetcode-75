/* 1679. Max Number of K-Sum Pairs

You are given an integer array nums and an integer k.

In one operation, you can pick two numbers from the array whose sum equals k and remove them from the array.

Return the maximum number of operations you can perform on the array.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int n = nums.size();
        int i = 0, j = n - 1;
        while(i < j)
        {
            int sum = nums[i] + nums[j];
            if(sum == k)
            {
                count++;
                i++;
                j--;
            } 
            else if(sum > k)
            {
                j--;
            }  
            else
            {
                i++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    int n;
    cout <<"Enter array length " << endl;
    cin >>n ;
    vector<int> arr(n);
    cout << "Enter elements ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout <<"Enter K value ";
    cin >> k;
    int result = solution.maxOperations(arr, k);
    cout << "Max operations : "<< result;
return 0;
}