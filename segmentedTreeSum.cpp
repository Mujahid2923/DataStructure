#include<bits/stdc++.h>
using namespace std;

#define mx 1000
int arr[mx];
int tree[mx*3];

int query(int node,int b,int e,int i,int j)
{
    if(b > j || e < i)
    {
        return 0;
    }

    if(b >= i && e <= j)
    {
        return tree[node];
    }


    int Lnode=node*2;
    int Rnode=node*2+1;

    int mid=(b+e)/2;
    int s1=query(Lnode,b,mid,i,j);
    int s2=query(Rnode,mid+1,e,i,j);
    return s1+s2;
}

void update(int node,int b,int e,int i,int newvalue)
{
    if(i>e || i<b)
    {
        return;
    }
    if(b>=i && e<=i)
    {
        tree[node]=newvalue;
        return;
    }

    int Left=node*2;
    int Right=node*2+1;

    int mid=(b+e)/2;
    update(Left,b,mid,i,newvalue);
    update(Right,mid+1,e,i,newvalue);

    tree[node]=tree[Left]+tree[Right];
}


void init(int *arr,int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }

    int Left=node*2;
    int Right=node*2+1;

    int mid=(b+e)/2;

    init(arr,Left,b,mid);
    init(arr,Right,mid+1,e);
    tree[node]=tree[Left]+tree[Right];
}

int main()
{
    int n;
    cin>>n;
    int arr[n+1];

    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
    }

    int a,b;
    cin>>a>>b;
    init(arr,1,1,n);///For transforming array into segment tree usable array

    int ans1=query(1,1,n,a,b);///Where add will be occur
    cout<<"Normal sum before update :"<<endl<<ans1<<endl;
    update(1,1,n,8,-10);
    int ans2=query(1,1,n,a,b);
    cout<<"Sum after update :"<<endl<<ans2<<endl;
    return 0;

}
/*
8
2 1 4 2 1 3 2 -1
1 8
ans=14
after update:5
*/
