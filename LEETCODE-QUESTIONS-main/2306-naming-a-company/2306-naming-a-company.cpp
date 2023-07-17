class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        
        unordered_set<string> initialGroup[26];
        
        for(auto& idea : ideas){
            initialGroup[idea[0] - 'a'].insert(idea.substr(1));
        }
        
        long long answer = 0;
        for(int i = 0; i < 25; i++){
            for(int j = i + 1; j < 26; j++){
                
                int numOfMutual = 0;
                
                for(auto& x : initialGroup[i]){
                    if(initialGroup[j].count(x)) numOfMutual++;
                }
                
                answer += 2LL * (initialGroup[i].size() - numOfMutual)*(initialGroup[j].size() - numOfMutual);
            }
        }
        
        return answer;
    }
};

/*
tc -> O(n * m)
sc -> O(n * m)

*/