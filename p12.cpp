/* 11. Container With Most Water

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;
        while (left < right) {
            int l = height[left];
            int h = height[right];
            int len = (right - left);
            int curr_area = min(l, h) * len;
            max_area = max(max_area, curr_area);
            if (l < h)
                left++;
            else
                right--;
        }
        return max_area;
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
    int result = solution.maxArea(arr);
    cout << "Result is : " << result;
return 0;
}