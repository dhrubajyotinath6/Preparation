#include <bits/stdc++.h>
using namespace std;

int arr[10][10], arr1[10], num, total = 0;

void values()
{
    int i, j;

    cout << "Enter the number of cities: " << endl;
    cin >> num;
   
    cout << "Enter the city distances" << endl;
    
    for (i = 0; i < num; i++)
    {
        cout << "Enter distance of city: " << i+1 << endl;
       
        for (j = 0; j < num; j++){
              cin >> arr[i][j];
              
        }
       arr1[i] = 0;
            
    }
    cout << "The distances are: " << endl;
    
    for (i = 0; i < num; i++)
    {
        cout << endl;
        
        for (j = 0; j < num; j++){
          cout << arr[i][j] << endl;
        }
           
    }
}
void minimum(int citynum)
{
    int i, citynum;
    arr1[citynum] = 1;

    cout <<  total + 1 << "-->" << endl;
    
    citynum = minimumdistance(total);

    if (citynum == 99)
    {
        citynum = 0;
        cout << citynum + 1 << endl;
        total += arr[total][citynum];
        return;
    }
    minimum(citynum);
}
int minimumdistance(int dist)
{
    int i, d1 = 99;
    int min = 99, min1;
    for (i = 0; i < num; i++)
    {
        if ((arr[dist][i] != 0) && (arr1[i] == 0))
            if (arr[dist][i] + arr[i][dist] < min)
            {
                min = arr[i][0] + arr[dist][i];
                min1 = arr[dist][i];
                d1 = i;
            }
    }
    if (min != 99)
        total += min1;
    return d1;
}
int main()
{
    values();
    cout << endl;
    cout << endl;
    cout << "The Path is: "<< endl;
    
    minimum(0);

    cout << endl;
    cout << "Minimum distance is: "  << total << endl;
    
    return 0;
}
