/*
2352. Equal Row and Column Pairs
Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.
A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int equalPairs(vector<vector<int>>& grid) {
            int n = grid.size();
            int count = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    bool isEqual = true;
                    for(int k = 0; k < n; k++)
                    {
                        if(grid[i][k] != grid[k][j])
                        {
                            isEqual = false;
                            break;
                        }
                        if(isEqual)
                        {
                            count++;
                        }
                    }
                }
            }
            
            return count;
        }
    };

    int main()
    {
        Solution solution;
        int n;
        cout << "Enter grid size (n x n) : ";
        cin >>n;
        vector<vector<int>> grid(n, vector<int>(n));
        cout<<"Grid elements are : ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }  
        }
        int result = solution.equalPairs(grid);
        cout <<"The result is : "<< result;
        return 0;
    }
    