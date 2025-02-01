/*1768. Merge Strings Alternately

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, 
append the additional letters onto the end of the merged string.

Return the merged string. */

#include<iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int maxLen = max(word1.size(), word2.size());
        for(int i = 0; i < maxLen; i++)
        {
            if(i < word1.size())
            {
                ans += word1[i];
            }
            if(i < word2.size())
            {
                ans += word2[i];
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    string word1, word2;
    cout << "Enter 1st and 2nd string " << endl;
    cin >> word1 >> word2;
    string result = solution.mergeAlternately(word1, word2);
    cout <<"Merge string : " << result << endl;
return 0;
}