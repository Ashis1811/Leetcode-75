/*1456. Maximum Number of Vowels in a Substring of Given Length
Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool isVowel(char c)
        {
            return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
        }
        int maxVowels(string s, int k) {
            int n = s.size();
            int vowel = 0;
            int count = 0;
            int i = 0, j = 0;
            while(j < n)
            {
                if(isVowel(s[j]))
                {
                    count++;
                }
                if(j - i + 1 == k)
                {
                    vowel = max(vowel, count);
                    if(isVowel(s[i]))
                    count--;
                    i++;
                }
                j++;
            }
            return vowel;
        }
    };
    int main()
    {
        Solution solution;
        string s;
        cout<<"Enter string "<<endl;
        cin >> s;
        int k;
        cout<<"Enter sub-str length"<<endl;
        cin >> k;
        int result = solution.maxVowels(s, k);
        cout<<"The sub-str is" << result;
        return 0;
    }
    