

int longestStreak(vector<int> &nums){
    set<int> hashSet;

    for(auto &num : nums){
        hashSet.insert(num);
    }

    int longestStreak = 0;

    for(auto &num : nums){
        if(!hashSet.count(num- 1)){
             int currNum = num;
             int currStreak = 1;

             while(hashSet.count(currNum+1)){
                currNum++;
                currStreak++;
             }

             longestStreak = max(longestStreak, currStreak);
        }
    }

    return longestStreak;
}