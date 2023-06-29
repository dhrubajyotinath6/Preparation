// Sample Input

// 5
// 1 6 10 8 4
// Sample Output

// 1 4 6 8 10
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT   
    int n;
    cin >> n;
    
    vector<int>v;
    int number;
    
    while(cin >> number){
        v.push_back(number);
    }
    
    sort(v.begin(),v.end()); 
    
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    
    
    return 0;
}
*/

// Input (stdin)

// Download
// 6
// 1 4 6 2 8 9
// 2
// 2 4
// Your Output (stdout)
// 3
// 1 8 9 
// Expected Output

// Download
// 3
// 1 8 9
/*

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    // Enter your code here. Read input from STDIN. Print output to STDOUT 
    int n, x, b, c;
    cin >> n;
    
    vector<int>v;
    
    int a;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        v.push_back(a);
    }
    
    cin >> x >> b >> c;
    
    v.erase(v.begin()+ x-1);
   
    v.erase(v.begin()+ b-1, v.begin()+ c-1);
    
    cout << v.size() << endl;
    
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << " ";
    }
    return 0;
    
}
*/

// pointer
/*
// void update(int *a,int *b) {
//     int sum = *a + *b;
//     int absDifference = *a - *b > 0 ? *a - *b : -(*a - *b);
//     *a = sum;
//     *b = absDifference; 
// }   
4 5
9 1        */


// classes and Obj
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Student{
    
    int scores[5];
    int total = 0;
    public:
    void input(){
        for(int i=0; i<5; i++){
            cin >> scores[i];
        }
    }
    int calculateTotalScore(){
        
        for(int i=0; i<5; i++){
            total += scores[i];
        }
        return total;
    }
    
};


int main() {
    int n; // number of students
    cin >> n;
    Student *s = new Student[n]; // an array of n students
    
    for(int i = 0; i < n; i++){
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0; 
    for(int i = 1; i < n; i++){
        int total = s[i].calculateTotalScore();
        if(total > kristen_score){
            count++;
        }
    }

    // print result
    cout << count;
    
    return 0;
}
*/

