#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* head = nullptr ;


void display()
{
    node* A = head ;
    while( A != nullptr )
    {
        cout << A -> data << " " ;
        A = A -> next ;
    }
    cout << endl ;
}

/*
void Reverse()
{
    node *pre = nullptr , *post = nullptr, *cur = head ;
    while( cur )
    {
        post = cur -> next ;
        cur -> next = pre ;
        pre = cur ;
        cur = post ;
    }
    head = pre ;
}
*/

void Reverse( node* p )
{
    if( p -> next == nullptr )
    {
        head = p ;
        return ;
    }

    Reverse( p -> next ) ;
    node *q = p -> next ;
    q -> next = p ;
    p -> next = nullptr ;
}

void insert_position( int pos, int value )
{
    node *temp = new node() ; // new node created
    node *pre = nullptr, *cur = head ;

    if( pos == 1 )
    {
        temp -> data = value ;
        temp -> next = head ;
        head = temp ;
    }
    else
    {
        for( int i = 1 ; i < pos ; i ++ )
        {
            pre = cur ;
            cur = cur -> next ;
        }
        temp -> data = value ;
        temp -> next = pre -> next ;
        pre -> next = temp ;
    }
}

void delete_position( int pos )
{
    node *cur = head, *pre = nullptr ;

    if( pos == 1 )
    {
        head = cur -> next ;
        free( cur ) ;
    }
    else
    {
        for( int i = 1 ; i < pos ; i ++ )
        {
            pre = cur ;
            cur = cur -> next;
        }
        pre -> next = cur -> next ;
        free( cur ) ;
    }
}


int main()
{
    int t, x, pos, position, value;
    cin >> t ;
    while( t-- )
    {
        cin >> x ;
        insert_position( 1, x ) ;
    }

    display() ;
    //Reverse() ;
    Reverse( head ) ;
    cout << "After Reverse : " << endl ;
    display() ;

    cout << "Insert in any what position and what value : " << endl ;
    cin >> pos >> value ;
    insert_position( pos, value ) ;

    display() ;

    cout << "Delete in any what position : " << endl ;
    cin >> position ;
    delete_position( position ) ;

    display() ;

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
Linked list is : 88 -> 75 -> 46 -> 35 -> 10 -> nullptr
Insert in any what position and what value : 2 1
88 -> 1 -> 75 -> 46 -> 35 -> 10 -> nullptr
Delete in any what position : 4
88 -> 1 -> 75 -> 35 -> 10 -> nullptr

*/


-----------****Old****----------


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
