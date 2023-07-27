/*
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes 
numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. 
You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists 
an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node 
(i.e. the starting node's value should be the maximum value along the path).

Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 - 1 is considered to be 
the same as 1 -> 0. A single node is also considered as a valid path.

 

Example 1:


Input: vals = [1,3,2,1,3], edges = [[0,1],[0,2],[2,3],[2,4]]
Output: 6
Explanation: There are 5 good paths consisting of a single node.
There is 1 additional good path: 1 -> 0 -> 2 -> 4.
(The reverse path 4 -> 2 -> 0 -> 1 is treated as the same as 1 -> 0 -> 2 -> 4.)
Note that 0 -> 2 -> 3 is not a good path because vals[2] > vals[0].
Example 2:


Input: vals = [1,1,2,2,3], edges = [[0,1],[1,2],[2,3],[2,4]]
Output: 7
Explanation: There are 5 good paths consisting of a single node.
There are 2 additional good paths: 0 -> 1 and 2 -> 3.
Example 3:


Input: vals = [1], edges = []
Output: 1
Explanation: The tree consists of only one node, so there is one good path.
 

Constraints:

n == vals.length
1 <= n <= 3 * 104
0 <= vals[i] <= 105
edges.length == n - 1
edges[i].length == 2
0 <= ai, bi < n
ai != bi
edges represents a valid tree.

*/



class UnionFind{
    
private:
    vector<int> parent, rank;
    
public:
    UnionFind(int size) {
        
        parent.resize(size);
        rank.resize(size, 0);
        
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    
    int find(int u) {
        if(u == parent[u]) return u; 
        return parent[u] = find(parent[u]); 
    }
    
    void union_set(int u, int v) {
        
        u = find(u);
        v = find(v);
        
        //same parent
        if(u == v){
            return;
        }else if(rank[u] < rank[v]) {
            parent[u] = v;
        } else if(rank[v] < rank[u]) {
            parent[v] = u; 
        }else {
            parent[v] = u;
            rank[u]++; 
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        
       int n = vals.size();
        vector<vector<int>> adj(n);
        
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        map<int, vector<int>> valuesToNodes;
        for(int node = 0; node < n; node++){
            valuesToNodes[vals[node]].push_back(node);
        }
        
        UnionFind dsu(n);
        int goodPaths = 0;
        
        for(auto& [value, nodes] : valuesToNodes){
            
            for(int node : nodes){
                for(int neighbor : adj[node]){
                    if(vals[node] >= vals[neighbor]){
                        dsu.union_set(node, neighbor);
                    }
                }
            }
            
            unordered_map<int,int> group;
            
            for(auto& u : nodes){
                group[dsu.find(u)]++;
            }
            
            for(auto& [_, size] : group){
                goodPaths += (size*(size+1)/2);
            }
        }
        
        return goodPaths;
    }
};



/*
An intuitive approach would be to start from a node and traverse to its neighbors, which have a lower value 
than the node. From the neighbors, we move to their neighbors. If we find another node with a value similar 
to the start node, we have one good path. We can repeat the same process for every node in the tree. 
In such a way, we traverse the tree, moving to neighbors with lower values for every node, 
and count the total number of good paths. We can choose BFS or DFS for the graph traversal. 
Each graph traversal takes 
O(n) time, and since we would do a complete traversal starting from every node, we would take 
O(n2) time. This approach would indicate that the time limit has been exceeded (TLE).

Let's think of a faster way by making some observations.

There is no point in traversing from a node to its neighbor where the vals[neighbor] > vals[node]. 
It violates the good path constraints. So, for any node, the only nodes that matter are the ones that 
have values less than vals[node]. Intuitively, this does give some hints about sorting the nodes 
according to their values, starting with the smallest value first and then going to higher values.

Let's look at an example. Consider a node with the value X in a tree T. 
Let's try to find the number of good paths that start and end with the value X. 
The nodes having values greater than X are of no use, so let's remove them and 
form a new subgraph of all the nodes (and edges in T connected to these nodes) having values less than 
or equal to X. Note that the new subgraph could be a connected tree, or there could be multiple connected 
trees separated from each other.

Let's say we have two existing trees (components) c1 and c2 which are subgraphs of T.

Imagine if there were 6 nodes with the value X, say a, b, c, d, e, and f. We want to add all of them to the 
subgraph and find the number of good paths starting and ending with X. Let's say a, b, and c connect with 
some nodes in c1. Nodes d and e connect with some nodes in c2. Node f does not connect with any existing 
component and creates a new component c3 with just the node f.

Let's compute the number of good paths. In component c1, if we start with node a we get three good paths. 
The a node itself as well as the paths from a to b and a to c. For node b, we have the node itself and the 
path to c (the path to a is already covered). And for node c, we just have the node itself. So, there are 
six good paths formed in component c1. What if there were N nodes in place of three? Starting from the first 
node, we would have N good paths: the node itself and N - 1 paths to other nodes with the same value. 
For the second node, we would have N - 1 options (since the first node is already covered), and so on. 
So, if N nodes having the same value connect in a component, 
the good paths would be N + N - 1 + N - 2 + .. + 1 = N * (N + 1) / 2.

Similarly, we can count three good paths forming in component c2. We can also use the same formula with 
N = 2 which gives (2 * (2 + 1) / 2) = 3 good paths.

For the component c3, there is one good path for node f, the node itself. It needs nodes with higher values 
to connect to other nodes in the original tree T, which do not lead to the formation of a good path. 
Here, N = 1, so using the formula gives us one good path.

Having added all the nodes with the value X, how can we compute the good paths with starting nodes having a 
value X + 1 (or next higher value)? To the subgraph formed above, we add all the nodes having the value 
X + 1 and repeat the same process to compute all the good paths starting with the value X + 1. 
The nodes with the value X can serve as intermediate nodes in a good path starting and ending with the value 
X + 1.

We can extend the above to start with value 1 first, then add nodes with value 2, then add nodes with 
value 3, and so on, to the subgraph formed in the previous iteration. We should begin from the lowest 
and move to the higher values of the nodes. For each value, we should add all the nodes with the same value 
to the existing subgraph and calculate the number of good paths formed in each component. This way, 
we build the complete tree at the end by adding nodes of the same value at each step.

This approach can be implemented with a disjoint-set data structure, also called a union-find data structure. 
It is a data structure that stores a collection of disjoint (non-overlapping) sets. Equivalently, it stores 
a partition of a set into disjoint subsets. It provides operations for adding new sets, merging sets 
(replacing them by their union), and finding a representative member of a set. It implements two useful 
operations:

*/