#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data ;
    node* left ;
    node* right ;
};

node* GetNewNode( int data )
{
    node* newnode = new node() ;
    newnode -> data = data ;
    newnode -> left = nullptr ;
    newnode -> right = nullptr ;
    return newnode ;
}

node* Insert( node* root, int data )
{
    if( root == nullptr )
    {
        root = GetNewNode( data ) ;
        return root ;
    }

    if( data <= root -> data ) root -> left = Insert( root -> left, data ) ;
    else root -> right = Insert( root -> right, data ) ;

    return root ;
}

bool Search( node* root, int data )
{
    if( root == nullptr ) return false ;
    else if( root -> data == data ) return true ;
    else if( data <= root -> data ) return Search( root -> left, data ) ;
    else return Search( root -> right, data ) ;
}
/*
int FindMin( node* root )
{
    if( root == nullptr ) return -1 ;
    while( root -> left != nullptr ) root = root -> left ;
    return root -> data ;
}
*/
int FindMin( node* root )
{
    if( root == nullptr ) return -1 ;
    else if( root -> left == nullptr ) return root -> data ;
    else return FindMin( root -> left ) ;
}

int Height( node * root )
{
    if( root == nullptr ) return -1 ;
    return 1 + max( Height( root -> left ), Height( root -> right ) ) ;
}

int main()
{
    node* root = nullptr ;
    root = Insert( root, 15 ) ;
    root = Insert( root, 10 ) ;
    root = Insert( root, 20 ) ;

    cout << FindMin( root ) << endl ;
    cout << Height( root ) << endl ;

    int n ;
    cin >> n ;
    if( Search( root, n ) ) cout << "Found" << endl ;
    else cout << "Not Found" << endl ;
    return 0 ;
}
