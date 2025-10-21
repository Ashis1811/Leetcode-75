/*
547. Number of Provinces
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            int n = isConnected.size();
            vector<bool> visited(n, false);
            int provinces = 0;
            for (int node = 0; node < n; node++) {
                if (!visited[node]) {
                    queue<int> q;
                    q.push(node);
                    visited[node] = true;
    
                    while (!q.empty()) {
                        int curr = q.front();
                        q.pop();
                        for (int neighbor = 0; neighbor < n; neighbor++) {
                            if (isConnected[curr][neighbor] == 1 &&
                                !visited[neighbor]) {
                                visited[neighbor] = true;
                                q.push(neighbor);
                            }
                        }
                    }
                    provinces++;
                }
            }
            return provinces;
        }
    };

int main()
{
    Solution sol;
    int n;
    cout<<"Enter total cities ";
    cin >> n;
    vector<vector<int>> cities(n, vector<int>(n));
    cout<<"Enter adjacency matrix ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >>cities[i][j];
        }
    }
    int ans = sol.findCircleNum(cities);
    cout<<"The number of provinces "<<ans;
    return 0;
}
