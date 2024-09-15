#include<bits/stdc++.h>
using namespace std;

struct Minheapnode{
    char data;
    int freq;
    Minheapnode *left, *right;

    Minheapnode(char data,int freq)
    {
        this->data=data;
        this->freq=freq;
        left=right=NULL;
    }
};

struct compare{
    bool operator()(Minheapnode* l,Minheapnode* r)
    {
        return(l->freq>r->freq);
    }
};

void print(struct Minheapnode* root, string str)
{
    if(!root)
        return;
    if(root->data!='#'){
        cout<<root->data<<" : "<<str<<endl;
    }

    print(root->left,str + "0");
    print(root->right,str+ "1");
}

void Huffmancode(char data[],int freq[],int n){
    struct Minheapnode *left, *right, *top;
    priority_queue<Minheapnode*, vector<Minheapnode*>,compare>minhp;
    for(int i=0;i<n;i++){
        minhp.push(new Minheapnode(data[i],freq[i]));
    }
    while(minhp.size()!=1){
        left=minhp.top();
        minhp.pop();

        right=minhp.top();
        minhp.pop();

        top= new Minheapnode('#', left->freq + right-> freq);
        top->left=left;
        top->right=right;
        minhp.push(top);
    }

    print(minhp.top()," ");
}
int main()
{
    int n;
    cin>>n;
    char arr[n+5];
    int freq[n+5];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i++)
        cin>>freq[i];
    Huffmancode(arr,freq,n);
}
