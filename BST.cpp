
/**

        12
       /  \
      5    15 <- have to delete this
     / \   / \
    3   7 13 17
           \   \
            14  20

    After delation

        12
       /  \
      5    17
     / \   / \
    3   7 13  20
           \
            14

**/

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

----------------------------------------

node* Search( node* root, int data )
{
    if( root == nullptr ) return nullptr ;
    else if( root -> data == data ) return root ;
    else if( data <= root -> data ) return Search( root -> left, data ) ;
    else return Search( root -> right, data ) ;
}
-------------------------------------------
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

----------------------------------------------
int Height( node * root )
{
    if( root == nullptr ) return -1 ;
    return 1 + max( Height( root -> left ), Height( root -> right ) ) ;
}


int Diameter( node* root )
{
    if( root == nullptr ) return 0 ;
    int Lheight = Height( root -> left ) ;
    int Rheight = Height( root -> right ) ;
    return max( Lheight + Rheight + 2, max( Diameter( root -> left ), Diameter( root -> right ) ) ) ;
}

---------------------------------------

void bfs( node* root )
{
    if( root == nullptr ) return ;
    queue < node* > Q ;
    Q.push( root ) ;
    while( !Q.empty() )
    {
        node* curr = Q.front() ;
        cout << curr -> data << " " ;
        Q.pop() ;
        if( curr -> left != nullptr ) Q.push( curr -> left ) ;
        if( curr -> right != nullptr ) Q.push( curr -> right ) ;
    }
    cout << endl ;
}

----------------------------------

void Preorder( node *root )
{
    if( root == nullptr ) return ;
    cout << root -> data << " " ;
    Preorder( root -> left ) ;
    Preorder( root -> right ) ;
}

void Inorder( node *root )
{
    if( root == nullptr ) return ;
    Inorder( root -> left ) ;
    cout << root -> data << " " ;
    Inorder( root -> right ) ;
}

void Postorder( node *root )
{
    if( root == nullptr ) return ;
    Postorder( root -> left ) ;
    Postorder( root -> right ) ;
    cout << root -> data << " " ;
}

-----------------------------
bool IsBstUtil( node *root, int L, int R )
{
    if( root == nullptr ) return true ;
    if( root -> data > L && root -> data < R && IsBstUtil( root -> left, L, root -> data ) && IsBstUtil( root -> right, root -> data, R ) ) return true ;
    else return false ;
}

bool IsBinaryTree( node *root )
{
    return IsBstUtil( root, INT_MIN, INT_MAX ) ;
}

--------------------------------

node* FindAddressMin( node *root )
{
    if( root == nullptr ) return nullptr ;
    while( root -> left != nullptr ) root = root -> left ;
    return root ;
}


node* Delete( node *root, int val )
{
    if( root == nullptr ) return root ;
    else if( val < root -> data ) root -> left = Delete( root -> left, val ) ;
    else if( val > root -> data ) root -> right = Delete( root -> right, val ) ;
    else
    {
        if( root -> left == nullptr && root -> right == nullptr )
        {
            delete root ;
            root = nullptr ;
        }
        else if( root -> left == nullptr )
        {
            node* temp = root ;
            root = root -> right ;
            delete temp ;
        }
        else if( root -> right == nullptr )
        {
            node* temp = root ;
            root = root -> left ;
            delete temp ;
        }
        else
        {
            node *temp = FindAddressMin( root -> right ) ;
            root -> data = temp -> data ;
            root -> right = Delete( root -> right, temp -> data ) ;
        }
    }
    return root ;
}
-----------------------------------------------

node* Getsuccessor( node* root, int data )
{
    node* curr = Search( root, data ) ;
    if( curr == nullptr ) return nullptr ;
    if( curr -> right != nullptr )
    {
        return FindAddressMin( curr -> right ) ;
    }
    else
    {
        node* successor = nullptr ;
        node* ancestor = root ;
        while( ancestor != curr )
        {
            if( curr -> data < ancestor -> data )
            {
                successor = ancestor ;
                ancestor = ancestor -> left ;
            }
            else
            {
                 ancestor = ancestor -> right ;
            }
        }
        return successor ;
    }
}
-------------------------------------

int main()
{
    node* root = nullptr ;
    root = Insert( root, 12 ) ;
    root = Insert( root, 5 ) ;
    root = Insert( root, 3 ) ;
    root = Insert( root, 7 ) ;
    root = Insert( root, 15 ) ;
    root = Insert( root, 13 ) ;
    root = Insert( root, 14 ) ;
    root = Insert( root, 17 ) ;
    root = Insert( root, 20 ) ;

    root = Delete( root, 15 ) ;

    cout << "Preorder : " ;
    Preorder( root ) ;
    cout << endl ;
    cout << "Inorder : " ;
    Inorder( root ) ;
    cout << endl ;
    cout << "Postorder : " ;
    Postorder( root ) ;
    cout << endl ;

    cout << "Is Binary Tree : " ;
    cout << IsBinaryTree( root ) ;
    cout << endl ;

    cout << "get Successor : " ;
    node* temp = Getsuccessor( root, 7 ) ;
    cout << temp -> data ;
    cout << endl ;


    bfs( root ) ;
    cout << "Min : " << FindMin( root ) << endl ;
    cout << "Height : " << Height( root ) << endl ;
    cout <<"Diameter : " << Diameter( root ) << endl ;


    if( Search( root, 10 ) != nullptr ) cout << "Found" << endl ;
    else cout << "Not Found" << endl ;
    return 0 ;
}



**********************---------------Merge two binary tree and get therir sum----------------------*****************
    
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) 
    {
        if( t1 == nullptr ) return t2 ;
        if( t2 == nullptr ) return t1 ;
        t1 -> val += t2 -> val ;
        t1 -> left = mergeTrees( t1 -> left, t2 -> left ) ;
        t1 -> right = mergeTrees( t1 -> right, t2 -> right ) ;
        return t1 ;
    }
};

//https://leetcode.com/problems/merge-two-binary-trees/

********************************------------------Invert the binary tree----------------------******************************
    
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if( root == nullptr ) return nullptr ;
        TreeNode *Left, *Right ;
        Left = invertTree( root -> right ) ;
        Right = invertTree( root -> left ) ;
        root -> left = Left ;
        root -> right = Right ;
        //if( Left && Right )cout << Left -> val << " " << Right -> val << endl ;
        return root ;
    } 
};
//https://leetcode.com/problems/invert-binary-tree/
