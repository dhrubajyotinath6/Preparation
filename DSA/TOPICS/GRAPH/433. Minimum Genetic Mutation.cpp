A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.

Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.

For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.

Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.

Note that the starting point is assumed to be valid, so it might not be included in the bank.

 

Example 1:

Input: startGene = "AACCGGTT", endGene = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1
Example 2:

Input: startGene = "AACCGGTT", endGene = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2
 

Constraints:

0 <= bank.length <= 10
startGene.length == endGene.length == bank[i].length == 8
startGene, endGene, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].

//https://leetcode.com/problems/minimum-genetic-mutation/discuss/2762144/C%2B%2Bor-Simple-BFS-w-DETAILED-EXPLANATION-and-COMMENTED-CODE-or-Easy-To-Understand

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int size = bank.size(); // extract size
        
        unordered_set<string> dictionary; // make dictionary set 
        for(int i = 0; i < size; i++) // insert every word of bank into the set
        {
            dictionary.insert(bank[i]);
        }
        
        // if end word is not present into the dictionary,
        // will return false from here
        if(dictionary.find(end) == dictionary.end())
        {
            return -1;
        }
        
        // choices that are availble to us
        vector<char> available = {'A', 'C', 'G', 'T'};
        
        // make vis set, to find out whether for a particular word, 
        // either we previously encountered or not
        unordered_set<string> vis;
        
        int ans = 0; // declare ans variable 
        
        queue<string> q; // define queue to start bfs
        q.push(start); // push starting word into the queue
        vis.insert(start); // insert into vis
        
        // starting bfs
        while(!q.empty())
        {
            int n = q.size(); // extract size of queue
            while(n--)
            {
                string curr = q.front(); // curr word 
                q.pop(); // pop from queue
                
                if(curr == end) // if curr word equals to end, return ans from here
                {
                    return ans;
                }
                
                // now for every index of curr word
                for(int i = 0; i < 8; i++)
                {
                    char orig = curr[i]; 
                    
                    // we will try to replace every available choice
                    for(int j = 0; j < 4; j++) 
                    {   
                        curr[i] = available[j]; // replace character
                        
                        // if it is present into the dictionary
                        if(dictionary.find(curr) != dictionary.end())
                        {
                            // also we haven't seen it previously
                            if(vis.find(curr) == vis.end())
                            {
                                q.push(curr); // then push into queue
                                vis.insert(curr); // and also put into vis
                            }
                        }
                    }
                    // now replace with again original character,
                    // for further check
                    curr[i] = orig;
                }
            }
            ans++; // increment answer
        }
        
        return -1; // still we will not able to find end word, return -1
    }
};