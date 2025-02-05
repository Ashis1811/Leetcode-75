/* 345. Reverse Vowels of a String

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.*/

#include<iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        string word = s;
        int start = 0;
        int end = s.size();
        string vowel = "aeiouAEIOU";
        while(start < end)
        {
            while(start < end && vowel.find(word[start]) == string :: npos)
            {
                start++;
            }
            while(start < end && vowel.find(word[end]) == string :: npos)
            {
                end--;
            }
            swap(word[start], word[end]);
            start++;
            end--;
        }
        return word;
    }
};

int main()
{
    Solution solution;
    string s;
    cout << "Enter string "<< endl;
    cin >> s;
    string result = solution.reverseVowels(s);
    cout << "The reverse is : " << result << endl;
return 0;
}