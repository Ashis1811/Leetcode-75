/*
841. Keys and Rooms
There are n rooms labeled from 0 to n - 1 and all the rooms are locked except for room 0. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.

When you visit a room, you may find a set of distinct keys in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.

Given an array rooms where rooms[i] is the set of keys that you can obtain if you visited room i, return true if you can visit all the rooms, or false otherwise.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void dfs(int curr, vector<bool>& visit, vector<vector<int>>& rooms)
        {
            if(visit[curr] == true) return;
            visit[curr] = true;
            for(auto key : rooms[curr])
            {
                dfs(key, visit, rooms);
            }
        }
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size();
            vector<bool> visit(n, false);
            dfs(0, visit, rooms);
            for(int i = 0; i < n; i++)
            {
                if(visit[i] == false)
                {
                    return false;
                }
            }
            return true;
        }
    };

int main()
{
    Solution sol;
    int n;
    cout<<"Enter total room No ";
    cin>>n;
    vector<vector<int>> room(n);
    for(int i = 0; i < n; i++)
    {
        int k;
        cout<<"Enter each room No ";
        cin >> k;
        room[i].resize(k);
        for(int j = 0; j < k; j++)
        {
            cin >> room[i][j];
        }
    }
    bool result = sol.canVisitAllRooms(room);
    cout<<"The result is : "<<result ? "True" : "False"; 
    return 0;
}
