#include<bits/stdc++.h>
using namespace std;
int ara[100];
void WriteFile()O
{
    freopen("Input.txt","w",stdout);

    int n =10;
    cout<<n<<endl;
    for(int i=0; i<n; i++)
    {
        int x = rand();
        cout<<x<<" ";
    }
    cout<<endl;

}
void InsertionSort(int ara[],int n)
{
    for(int i=1; i<n; i++)
    {
        int j=i-1;
        int temp=ara[i];
        while(j>=0 && ara[j]>temp)
        {
            ara[j+1]=ara[j];
            j--;
        }
        ara[j+1]=temp;
    }
}
void BubbleSort(int ara[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if(ara[j]>ara[j+1])
            {
                swap(ara[j],ara[j+1]);
            }
        }
    }
}
void SelectionSort(int ara[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        int temp;
        for(int j=i+1; j<n; j++)
        {
            if(ara[i]>ara[j])
            {
                temp=j;
            }
        }
        if(temp!=i)
        {
            swap(ara[temp],ara[i]);
        }
    }
}
int Merge(int ara[],int left,int mid,int right,int n)
{
    int temp[n];
    int i=left;
    int   j=mid+1;
    int k=left;
    while(i<=mid && j<=right)
    {
        if(ara[i]<=ara[j])
        {
            temp[k]=ara[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=ara[j];
            j++;
            k++;
        }
    }
    if(i>mid)
    {
        while(j<=right)
        {
            temp[k]=ara[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i<=mid)
        {
            temp[k]=ara[i];
            i++;
            k++;
        }
        for(int k=left; k<=right; k++)
        {
            ara[k]=temp[k];
        }
    }

}
void MergeSort(int ara[],int left,int right,int n)
{
    if(left<right)
    {
        int mid=(left+right)/2;
        MergeSort(ara,left,mid,n);
        MergeSort(ara,mid+1,right,n);
        Merge(ara,left,mid,right,n);
    }
}
int Partition(int ara[],int left,int right)
{
    int i,j,pivot;
    i=left;
    j=right;
    pivot=ara[left];
    while(i<j)
    {
        while(ara[i]<=pivot)
        {
            i++;
        }
        while(ara[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(ara[i],ara[j]);
        }
    }
    swap(ara[left],ara[j]);
    return j;
}
void QuickSort(int ara[],int left,int right)
{
    if(left>=right)
    {
        return ;
    }
    int p=Partition(ara,left,right);
    QuickSort(ara,left,p-1);
    QuickSort(ara,p+1,right);
}
int main()
{
//    WriteFile();
//    return 0;
    freopen("Input.txt","r",stdin);
    freopen("output.txt","w",stdout);
//    int N;
//    scanf("%d",&N);
//    for(int i=0; i<N; i++)
//    {
//        scanf("%d",&ar[i]);
//    }
    int n;
    cin>>n;
    int ara[n];
    for(int i=0; i<n; i++)cin>>ara[i];
//    InsertionSort(ara,n);
//    for(int i=0;i<n;i++)cout<<ara[i]<<" ";
//   BubbleSort(ara,n);
//    for(int i=0;i<n;i++)cout<<ara[i]<<" ";
//   SelectionSort(ara,n);
//    for(int i=0;i<n;i++)cout<<ara[i]<<" ";
//    MergeSort(ara,0,n-1,n);
//    for(int i=0; i<n; i++)cout<<ara[i]<<" ";
QuickSort(ara,0,n-1);
for(int i=0; i<n; i++)cout<<ara[i]<<" ";
}
