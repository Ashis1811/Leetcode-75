/*
1466. Reorder Routes to Make All Paths Lead to the City Zero
There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.

This year, there will be a big event in the capital (city 0), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.

It's guaranteed that each city can reach city 0 after reorder.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int minReorder(int n, vector<vector<int>>& connections) {
            vector<vector<int>> adj(n);
            unordered_set<string> edge;
            vector<bool> visited(n, false);
            for(auto curr : connections)
            {
                int from = curr[0], to = curr[1];
                adj[from].push_back(to);
                adj[to].push_back(from);
                edge.insert(to_string(from) + "," + to_string(to));
            }
            int change = 0;
            queue<int>q;
            q.push(0);
            visited[0] = true;
            while(! q.empty())
            {
                int city = q.front();
                q.pop();
                for(auto neighbor : adj[city])
                {
                    if(! visited[neighbor])
                    {
                        if(edge.count(to_string(city) + "," + to_string(neighbor)))
                        {
                            change++;
                        }
                        visited[neighbor] = true;
                        q.push(neighbor);
                    }
                }
            }
            return change;
        }
    };

int main()
{
    Solution sol;
    int n, m;
    cout<<"Enter total cities ";
    cin >> n;
    cout<<"Enter total roads ";
    cin >> m;
    vector<vector<int>> connection(m, vector<int>(2));
    cout<<"Enter roads : ";
    for (int i = 0; i < m; i++)
    {
        cin >> connection[i][0] >> connection[i][1];
    }
    int result = sol.minReorder(n, connection);

    cout<<"The answer is : "<<result;
    return 0;
}
