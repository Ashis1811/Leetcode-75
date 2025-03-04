/*
1207. Unique Number of Occurrences
Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool uniqueOccurrences(vector<int>& arr) {
            unordered_map<int, int> mp1, mp2; // {element, count}
            for(auto num : arr)
            {
                mp1[num]++;
            }
            for(auto num : mp1)
            {
                int count = num.second;
                mp2[count]++;
                if(mp2[count] > 1)
                {
                    return false;
                }
            }
            return true;
        }
    };
int main()
{
    Solution solution;
    int n;
    cout<<"Enter array length : ";
    cin >> n;
    vector<int> arr(n);
    cout<<"Enter elements : ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bool result = solution.uniqueOccurrences(arr);
    cout<<"The result is : "<<(result ? "True " : "False")<<endl;
    return 0;
}

