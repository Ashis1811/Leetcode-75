/*
1657. Determine if Two Strings Are Close

Two strings are considered close if you can attain one from the other using the following operations:

Operation 1: Swap any two existing characters.
For example, abcde -> aecdb
Operation 2: Transform every occurrence of one existing character into another existing character, and do the same with the other character.
For example, aacabb -> bbcbaa (all a's turn into b's, and all b's turn into a's)
You can use the operations on either string as many times as necessary.

Given two strings, word1 and word2, return true if word1 and word2 are close, and false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool closeStrings(string word1, string word2) {
            if(word1.size() != word2.size()) return false;
            unordered_map<char, int> freq1, freq2; // {char, count}
            for(auto it : word1)
            {
                freq1[it]++;
            }
            for(auto it : word2)
            {
                freq2[it]++;
            }
            if(freq1.size() != freq2.size())
            {
                return false;
            }
            for(auto it : word1)
            {
                if(freq2.find(it) == freq2.end())
                {
                    return false;
                }
            }
            vector<int> freqC1, freqC2;
            for(auto entry : freq1)
            {
                freqC1.push_back(entry.second);
            }
            for(auto entry : freq2)
            {
                freqC2.push_back(entry.second);
            }
            sort(freqC1.begin(), freqC1.end());
            sort(freqC2.begin(), freqC2.end());
            return freqC1 == freqC2;
        }
    };

    int main()
    {
        
        Solution solution;
        string word1, word2;
        cout<<"Enter word1 & word 2"<<endl;
        cin >> word1 >> word2;
        bool result = solution.closeStrings(word1, word2);
        cout<<"The result is "<<(result ? "True" : "False") << endl;
        return 0;
    }
    