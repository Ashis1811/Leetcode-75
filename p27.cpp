/*
933. Number of Recent Calls

You have a RecentCounter class which counts the number of recent requests within a certain time frame.
Implement the RecentCounter class:

RecentCounter() Initializes the counter with zero recent requests.
int ping(int t) Adds a new request at time t, where t represents some time in milliseconds, and returns the number of requests that has happened in the past 3000 milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range [t - 3000, t].
It is guaranteed that every call to ping uses a strictly larger value of t than the previous call.
*/

#include<bits/stdc++.h>
using namespace std;

class RecentCounter {
    public:
        RecentCounter() {
        }
            queue<int> q;
            int ping(int t) {
            q.push(t);
            while(q.front() < t - 3000)
            {
                q.pop();
            }
            return q.size();
        }
    };

    int main()
    {
        RecentCounter recentCounter;
        vector<int> input = {1, 100, 3001, 3002};
        vector<int> output;
        for(auto t : input)
        {
            output.push_back(recentCounter.ping(t));
        }
        cout <<'[';
        for(int i = 0; i < output.size(); i++)
        {
            cout << output[i];
            if(i != output.size() - 1) cout << ",";
        }
        cout << ']' <<endl;
        return 0;
    }
    