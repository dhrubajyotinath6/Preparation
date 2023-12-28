#include <bits/stdc++.h>
using namespace std;


int dfs(int index, int n, vector<vector<int>> &edges, vector<int> &vis, int cnt){
    
    
    if(index == n){
        return cnt;
    }
    
    // donot pick
    int x =  dfs(index + 1, n, edges, vis, cnt);
    int y = -1;
    
    
    vector<int> edge = edges[index];
    int a = edge[0];
    int b = edge[1];
    
    if(vis[a] == 0 && vis[b] == 0){
        vis[a] = 1;
        vis[b] = 1;
        cnt += 2;
        
        y = dfs(index + 1, n, edges, vis, cnt);
        vis[a] = 0;
        vis[b] = 0;
    } 
    
    return max(x,y);
    
}

void solve(){
    int n;
    cin >> n;
    
 
    
    vector<vector<int>> edges(n-1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a;
        cin >> b;
        vector<int> edge {a, b};
        edges[i] = edge;
    }
    
    vector<int> vis(n+1, 0);
    cout << dfs(0, edges.size(), edges, vis, 0)/2 << endl;
    
}

int main(){
    
    solve();
    
    return 0;
}