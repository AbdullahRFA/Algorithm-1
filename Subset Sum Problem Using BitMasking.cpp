#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of coin  : ";
    cin>>n;
    int ara[n];
    for(int i=0; i<n; i++)cin>>ara[i];
    cout<<"Enter sum: ";
    int sum,count=0;
    cin>>sum;
    for(int i=1; i<(1<<n); i++)
    {
        int subsetsum = 0;
        for(int j=0; j<n; j++)
        {
            if( (i&(1<<j))!=0)
                subsetsum+=ara[j];
        }
        if(sum==subsetsum)
        {
            count++;
        }
    }
    cout<<"Total number of subset : "<<count<<endl;

    return 0;
}

/*
5
1 3 5 7 9
12

2


Input Reading: O(n)
Subset Generation and Sum Calculation: O(2^n * n) (worst-case, considering both loops)
Counting: O(1)
Output: O(1)

So, the overall time complexity of this code is O(2^n * n),

where 'n' is the number of coins in the array.
This complexity grows exponentially with the size of the input
 array and is generally not efficient for large input sizes.
*/
