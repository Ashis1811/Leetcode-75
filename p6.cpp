/* 151. Reverse Words in a String

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space
separating the words. Do not include any extra spaces. */

#include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        int i = 0;
        int n = s.size();
        while(i < n)
        {
            while(i < n && s[i] == ' ') i++;
            if(i >= n) break;
            int j = i + 1;
            while(j < n && s[j] != ' ') j++;
            string sub = s.substr(i, j - i);
            if(ans.size() == 0) ans = sub;
            else ans = sub + " " + ans;
            i = j + 1;
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    string s;
    cout << "Enter the string " << endl;
    getline(cin, s); // To read the entire string with spaces
    string result = solution.reverseWords(s);
    cout <<"The reverse is : " << result << endl;
return 0;
}