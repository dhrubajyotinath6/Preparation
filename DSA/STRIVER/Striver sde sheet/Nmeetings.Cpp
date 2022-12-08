/*
There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where 
start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room 
when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting
*/

struct meeting {
    int start;
    int end;
    int pos; 
}; 
bool comparator(struct meeting m1, meeting m2) 
{ 
    if (m1.end < m2.end) return true; 
    else if(m1.end > m2.end) return false; 
    else if(m1.pos < m2.pos) return true; 
    return false; 
} 
void maxMeetings(int s[], int e[], int n) {
    struct meeting meet[n]; 
    for(int i = 0;i<n;i++) {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1; 
    }
    
    sort(meet, meet+n, comparator); 
    
    vector<int> answer;
    
    int limit = meet[0].end; 
    answer.push_back(meet[0].pos); 
    
    for(int i = 1;i<n;i++) {
        if(meet[i].start > limit) {
            limit = meet[i].end; 
            answer.push_back(meet[i].pos); 
        }
    }
    for(int i = 0;i<answer.size();i++) {
        cout << answer[i] << " "; 
    }
    
}

