#include <bits/stdc++.h>
using namespace std;
int store[1000][1000];
int SetOfElement[1000];
int t;
void generate_sub_set(int n, int sum, vector<int> v)
{
    if (sum == 0)
    {
        t++;
        for (auto x : v)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    if (n <= 0)
    {
        return;
    }
    generate_sub_set(n - 1, sum, v);
    v.push_back(SetOfElement[n - 1]);
    generate_sub_set(n - 1, sum - SetOfElement[n - 1], v);
}
int main()
{
    vector<int> v;
    int n;
    cout<<"Enter the number of element : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> SetOfElement[i];
    }
    cout << "Enter the wanting values: ";
    int values;
    cin >> values;
    generate_sub_set(n, values, v);
    cout<<"\n Number of total subset is = "<<t<<endl;
}

