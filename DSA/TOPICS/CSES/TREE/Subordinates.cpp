//https://cses.fi/problemset/task/1674/
/*
Given the structure of a company, your task is to calculate for each employee the number of 
their subordinates.
Input
The first input line has an integer n: the number of employees. The employees are numbered 1,2,\dots,n, 
and employee 1 is the general director of the company.
After this, there are n-1 integers: for each employee 2,3,\dots,n their direct boss in the company.
Output
Print n integers: for each employee 1,2,\dots,n the number of their subordinates.


Example
Input:
5
1 1 2 3

Output:
4 1 1 0 0
*/

#include <bits/stdc++.h>
using namespace std;


int dfs(int currNode, vector<int> &ans, unordered_map<int, vector<int>> &tree){
    
    int cnt = 0;
    
    if(tree[currNode] == vector<int>()){
        return 1;
    }
    
    for(auto& child : tree[currNode]){
        cnt += dfs(child, ans, tree);
    }
    
    ans[currNode-1] = cnt;
    return cnt + 1;
}

void solve(){
    int n;
    cin  >> n;
    
    vector<int> boss(n+1);
    
    for(int i = 2; i <= n; i++){
        cin >> boss[i];
    }
    
    unordered_map<int, vector<int>> tree;
    
    for(int i = 0; i <= n; i++){
        tree[i] = vector<int>();
    }
    
    for(int i = 2; i <= n; i++){
        int parent = boss[i];
        int child = i;
        
        tree[parent].push_back(child);
    }
    
    vector<int> ans(n,0);
    
    dfs(1,ans, tree);
    
    for(auto& x : ans){
        cout << x << endl;
    }
}

int main(){
    
    solve();
    
    return 0;
}