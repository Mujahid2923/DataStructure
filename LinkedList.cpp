#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* next;
};

struct node* head=NULL;

void Insert(int new_data)
{
    struct node* temp=new node();
    temp->data=new_data;
    temp->next=head;
    head=temp;
}

void display()
{
    struct node* tail;
    tail=head;
    while(tail!=NULL)
    {
        printf("%d -> ",tail->data);
        tail=tail->next;
    }
}

void insert_position(int pos, int value)
{
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1; i<pos; i++)
    {
        pre=cur;
        cur=cur->next;
    }
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
}

void delete_position(int pos)
{
    node *current=new node;
    node *previous=new node;
    current=head;
    for(int i=1; i<pos; i++)
    {
        previous=current;
        current=current->next;
    }
    previous->next=current->next;
}


int main()
{
    int n,a,pos,position,value;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&a);
        Insert(a);
    }
    printf("Linked list is : ");
    display();
    printf("\nInsert in any what position and what value :");

    scanf("%d %d",&pos,&value);
    insert_position(pos,value);
    display();

    printf("\nDelete in any what position :");
    scanf("%d",&position);
    delete_position(position);
    display();

    printf("\n");
    return 0;
}

/*
5
10 35 46 75 88
2 1
4


Output:
5
10 35 46 75 88
Linked list is : 88 -> 75 -> 46 -> 35 -> 10 ->
Insert in any what position and what value :2 1
88 -> 1 -> 75 -> 46 -> 35 -> 10 ->
Delete in any what position :4
88 -> 1 -> 75 -> 35 -> 10 ->
*/
