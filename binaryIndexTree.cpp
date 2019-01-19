#include<bits/stdc++.h>
using namespace std;

int query(int tree[],int idx)
{
    idx+=1;
    int sum=0;
    while(idx>0)
    {
        sum += tree[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

void update(int tree[],int n,int idx,int x)
{
    idx+=1;
    while(idx<=n)
    {
        tree[idx] += x;
        idx += (idx & (-idx));
    }
}

int main()
{
    int n,d;
    cin>>n;
    int arr[n+1];
    for(int i=0; i<=n; i++)
    {
        cin>>arr[i];
    }
    ///Sum
    cout<<"Till how you want to get the sum:"<<endl;
    cin>>d;
    int ans1=query(arr,d);
    cout<<"Sum is :"<<ans1<<endl;

    ///Update
   // arr[10]+=20;
    update(arr,n,10,20);//arr,index,number to add
    int ans2=query(arr,d);
    cout<<"Now the sum is :"<<ans2<<endl;
}

/*
12
2 1 1 3 2 3 4 5 6 7 8 9
5
sum is 12

13
1 2 3 4 5 6 7 8 9 10 11 12 13
13
sum is 91
sum is 111
*/


