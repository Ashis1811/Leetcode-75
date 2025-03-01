/* 443. String Compression

Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that
are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;
        int n = chars.size();
        while(read < n)
        {
            char currChar = chars[read];
            int count = 0;
            while(read < n && chars[read] == currChar)
            {
                read++;
                count++;
            }
            chars[write] = currChar;
            write++;
            if(count > 1)
            {
                string str = to_string(count);
                for(char ch : str)
                {
                    chars[write] = ch;
                    write++;
                }
            }
        }
        return write;
    }
};

int main()
{
    Solution solution;
     int n;
    cout <<"Enter array length " << endl;
    cin >>n;
    vector<char> arr(n);
    cout << "Enter elements ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int result = solution.compress(arr);
    cout <<"Result is : ";
    for(int i = 0; i < result; i++)
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
return 0;
}