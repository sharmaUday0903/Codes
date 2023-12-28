// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

#define maxN 200001

// Adjacency List to store the graph
vector<int> adj[maxN];

// Stores the height of each node
int height[maxN];

// Stores the maximum distance of a
// node from its ancestors
int dist[maxN];

void dfs1(int cur, int par)
{
    // Iterate in the adjacency
    // list of the current node
    for (auto u : adj[cur])
    {

        if (u != par)
        {

            dfs1(u, cur);

            height[cur] = max(height[cur], height[u]);
        }
    }

    height[cur] += 1;
}

void dfs2(int cur, int par)
{
    int max1 = 0;
    int max2 = 0;

    for (auto u : adj[cur])
    {

        if (u != par)
        {

            if (height[u] >= max1)
            {
                max2 = max1;
                max1 = height[u];
            }
            else if (height[u] > max2)
            {
                max2 = height[u];
            }
        }
    }

    int sum = 0;

    for (auto u : adj[cur])
    {
        if (u != par)
        {

            // Calculate the maximum distance
            // with ancestor for every node
            sum = ((max1 == height[u]) ? max2 : max1);

            if (max1 == height[u])
                dist[u] = 1 + max(1 + max2, dist[cur]);
            else
                dist[u] = 1 + max(1 + max1, dist[cur]);

            // Calculating for children
            dfs2(u, cur);
        }
    }
}

// Driver Code
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >>x>> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs1(1, 0);

    // Calculate the maximum
    // distance with ancestors
    dfs2(1, 0);

    // Print the maximum of the two
    // distances from each node
    for (int i = 1; i <= n; i++)
        cout << (max(dist[i], height[i]) - 1) << " ";

    return 0;
}
