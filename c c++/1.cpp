#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int M, N;

    cin >> M;
    cin >> N;

    vector<int> adj[N];
    vector<int> dist;

    for (int i = 0; i <= M; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back(v);
        adj[u].push_back(cost);

        dist.push_back(cost);
    }

    int sum = 0;

    int mini = INT_MAX;
    for (auto it : dist)
    {
        sum += it;
        mini = min(sum, mini);
        if (sum > 0)
        {
            sum = 0;
        }
    }

    cout << mini << endl;

    return 0;
}