#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class BF
{
public:
    int leastcost(int **edges, int nn)
    {
        int source = 0;
        vector<int> nodes;
        for (int i = 0; i < nn; i++)
        {
            if (i != source)
            {
                nodes.push_back(i);
            }
        }
        int n = nodes.size();
        int hcircuit = INT_MAX;
        while (next_permutation(nodes.begin(), nodes.end()))
        {
            int wt = 0;
            int j = source;
            for (int i = 0; i < n; i++)
            {
                wt += edges[j][nodes[i]];
                j = nodes[i];
            }
            wt += edges[j][source];
            hcircuit = min(hcircuit, wt);
        }
        return hcircuit;
    }
};
int main()
{
    int nn, ne;
    cin >> nn >> ne;
    int **edges = new int *[nn];
    for (int i = 0; i < nn; i++)
    {
        edges[i] = new int[nn];
        for (int j = 0; j < nn; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < ne; i++)
    {
        int wt, start, end;
        cin >> wt >> start >> end;
        edges[start][end] = wt;
        edges[end][start] = wt;
    }
    BF test;
    cout << test.leastcost(edges, nn) << endl;
    return 0;
}