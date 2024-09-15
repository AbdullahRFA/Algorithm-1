#include<bits/stdc++.h>
using namespace std;
int ara[3][3][10];
void input()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<10; k++)
            {
                cin>>ara[i][j][k];
            }
        }
    }
}
void display()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            for(int k=0; k<10; k++)
            {
                cout<<ara[i][j][k]<<" ";
            }
            cout<<endl;
        }
    }
}
void operation()
{
    for(int i=0; i<10; i++ )
    {
        if(ara[0][0][i]==1)
        {
            continue;
        }
        else
        {

            for(int j=0; j<3; j++)
            {
                for(int k=0; k<10; k++)
                {
                    if(j==0&&k==0)
                    {
                        continue;
                    }
                    else
                    {
                        for(int m=0; m<10; m++)
                        {
                            if(ara[j][k][m]==1)
                            {
                                swap(ara[0][0][i],ara[j][k][m]);
                            }
                        }
                    }
                }
            }
        }

    }
}

int main()
{
    input();
    cout<<"Before searching : \n";
    display();
    operation();
    cout<<"After searching : \n";
    display();

    return 0;
}
/*
1 5 9 3 5 7 4 5 6 2
7 8 9 3 6 9 1 2 3 4
2 5 8 9 6 3 1 4 7 5
1 5 9 3 6 2 5 8 7 4
1 5 9 8 5 2 3 6 4 7
1 5 8 4 5 6 9 3 2 5
1 2 5 3 6 9 5 4 2 8
2 5 6 9 3 2 5 1 5 9
1 5 9 3 2 5 8 7 4 2
OUTPUT:
1 1 1 1 1 1 1 1 1 1
7 8 9 3 6 9 5 2 3 4
2 5 8 9 6 3 9 4 7 5
3 5 9 3 6 2 5 8 7 4
5 5 9 8 5 2 3 6 4 7
7 5 8 4 5 6 9 3 2 5
4 2 5 3 6 9 5 4 2 8
2 5 6 9 3 2 5 5 5 9
6 5 9 3 2 5 8 7 4 2
*/
