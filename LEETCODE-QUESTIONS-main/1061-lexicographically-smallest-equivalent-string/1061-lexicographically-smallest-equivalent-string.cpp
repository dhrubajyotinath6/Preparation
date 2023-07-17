class Solution {
    
public:
    int findPar(int u, vector<int> &parent) {
    if(u == parent[u]) return u; 
    return parent[u] = findPar(parent[u], parent); 
}

void unionn(int u, int v, vector<int> &parent) {
    
    u = findPar(u, parent);
    v = findPar(v, parent);
    
    if(u < v) {
    	parent[v] = u;
    }
    else if(v < u) {
    	parent[u] = v; 
    }
    //this condition will never happen though :)
    else {
    	parent[v] = u; 
    }
}
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
    vector<int> parent(26);
	for(int i = 0;i<26;i++){
        parent[i] = i;
    }	
        
    for(int i = 0; i <s1.size(); i++){
        unionn(s1[i] - 'a', s2[i] - 'a', parent);
    }
        
    string ans;
    for(char c : baseStr){
        ans += (char)(findPar(c-'a', parent) + 'a');
    }
	 
    return ans;
        
    }
};