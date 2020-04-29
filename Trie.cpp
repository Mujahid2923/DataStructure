///https://www.techiedelight.com/memory-efficient-trie-implementation-using-map-insert-search-delete/
#include<bits/stdc++.h>
using namespace std;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scln3(x,y,z)           scanf("%lld %lld %lld",&(x),&(y),&(z))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     acos(-1.0)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
#define          DBG                    cout << endl << "---------------" << endl ;
#define segment_tree int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;

#define          siz                    3005



struct Trie
{
    bool isleaf ;
    map < char , Trie* > Mp ;
};

Trie* newnode()
{
    Trie* node = new Trie ;
    node -> isleaf = false ;
    return node ;
}

void Insert( Trie* &head , char* ch )
{
    if( head == nullptr ) head = newnode() ;
    Trie* curr = head ;
    while( *ch )
    {
        if( curr -> Mp.find( *ch ) == curr -> Mp.end() ) curr -> Mp[ *ch ] = newnode() ;
        curr = curr -> Mp[ *ch ] ;
        ch ++ ;
    }
    curr -> isleaf = true ;
}

bool haveChildren( Trie const* curr )
{
    for( auto x : curr -> Mp )
    {
        if( x.second != nullptr ) return true ;
    }
    return false ;
}

bool deletion( Trie* &curr , char* ch )
{
    if( curr == nullptr ) return false ;
    if( *ch )
    {
        if( curr != nullptr && curr->Mp.find( *ch ) != curr-> Mp.end() && deletion( curr-> Mp[ *ch ], ch + 1) && curr-> isleaf == false )
        {
            if( !haveChildren( curr ) )
            {
                delete curr ;
                curr = nullptr ;
                return true ;
            }
            else
            {
                return false ;
            }
        }
    }
    if( *ch == '\0' && curr -> isleaf )
    {
        if( !haveChildren( curr ) )
        {
            delete curr ;
            curr = nullptr ;
            return true ;
        }
        else
        {
            curr -> isleaf = false ;
            return false ;
        }
    }
    return false ;
}

bool Search( Trie* head , char* ch )
{
    if( head == nullptr ) return false ;
    Trie* curr = head ;

    while( *ch )
    {
        curr = curr -> Mp[ *ch ] ;
        if( curr == nullptr ) return false ;
        ch ++ ;
    }
    return curr -> isleaf ;
}

int main()
{
    Trie* head = nullptr ;
    Insert( head , "hello" ) ;
    cout << Search( head, "hello") << endl ;
    Insert( head , "helloworld" ) ;
    cout << Search( head, "helloworld") << endl ;
    cout << Search( head, "hell") << endl ;
    deletion( head, "hello" ) ;
    cout << Search(head, "hello") << endl ;
    if( head == nullptr )
    {
        cout << "Trie empty!!" << endl ;
    }
    cout << Search( head, "hell" ) << endl ;

    return 0 ;
}


------------------------******************---------------------------

struct node
{
    bool endmark ;
    node* next[ 27 ] ;
    node()
    {
        endmark = false ;
        for( int i = 0 ; i < 26 ; i ++ )
        {
            next[ i ] = nullptr ;
        }
    }
} *root ;

void Insert( char* str , int len )
{
    node* curr = root ;
    for( int i = 0 ; i < len ; i ++ )
    {
        int id = str[ i ] - 'a' ;
        if( curr -> next[ id ] == nullptr )
        {
            curr -> next[ id ] = new node() ;
        }
        curr = curr -> next[ id ] ;
    }
    curr -> endmark = true ;
}

bool Search( char* str , int len )
{
    node* curr = root ;
    for( int i = 0 ; i < len ; i ++ )
    {
        int id = str[ i ] - 'a' ;
        if( curr -> next[ id ] == nullptr ) return false ;
        curr = curr -> next[ id ] ;
    }
    return curr -> endmark ;
}

void del( node* cur )
{
    for( int i = 0 ; i < 26 ; i ++ )
    {
        if( cur -> next[ i ] ) del( cur -> next[ i ] ) ;
    }
    delete( cur ) ;
}

int main()
{
    root = new node() ;
    Insert( "hello" , 5 ) ;
    Insert( "good" , 4 ) ;

    cout << Search( "hell" , 4 ) << endl ;
    cout << Search( "hello" , 5 ) << endl ;
    cout << Search( "god" , 3 ) << endl ;
    cout << Search( "good" , 4 ) << endl ;

    delete( root ) ;

    return 0 ;
}



--------------------------*************-----------------------------
///https://www.spoj.com/problems/STRMATCH/fbclid=IwAR1kf4NAPP4xGLs3QwEaafzrPOspahiIHQAbrsu7eI3sjlxzBMc6XzKqtX4

#include<bits/stdc++.h>

using namespace std;

#define          CIN                    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          vi                     vector<int>
#define          vl                     vector<ll>
#define          pb                     push_back
#define          sc                     scanf
#define          pf                     printf
#define          scin(x)                scanf("%d",&(x))
#define          scin2(x,y)             scanf("%d %d",&(x),&(y))
#define          scin3(x,y,z)           scanf("%d %d %d",&(x),&(y),&(z))
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
#define          scln3(x,y,z)           scanf("%lld %lld %lld",&(x),&(y),&(z))
#define          min3(a,b,c)            min(a,min(b,c))
#define          min4(a,b,c,d)          min(d,min(a,min(b,c)))
#define          max3(a,b,c)            max(a,max(b,c))
#define          max4(a,b,c,d)          max(d,max(a,max(b,c)))
#define          ms(a,b)                memset(a,b,sizeof(a))
#define          mp                     make_pair
#define          gcd(a, b)              __gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
#define          input                  freopen("input.txt","rt", stdin)
#define          output                 freopen("output.txt","wt", stdout)
#define          PI                     acos(-1.0)
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Max(v)                 *max_element(all(v))
#define          Min(v)                 *min_element(all(v))
#define          Upper(c,x)             (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)             (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)              (X).erase(unique(all(X)),(X).end())
#define          no                     cout << "NO" << endl ;
#define          yes                    cout << "YES" << endl ;
#define          DBG                    cout << endl << "---------------" << endl ;
#define segment_tree int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;

#define          siz                    3005


int n, q ;
char s[ 500005 ] ;

struct trie
{
    int cnt ;
    trie *next[ 30 ] ;
    trie()
    {
        cnt = 0 ;
        for( int i = 0 ; i < 26 ; i ++ )
        {
            next[ i ] = nullptr ;
        }
    }
} *start ;

void build()
{
    trie* cur = nullptr ;
    for( int i = 0 ; i < n ; i ++ )
    {
        cur = start ;
        for( int j = i ; j < n ; j ++ )
        {
            if( cur -> next[ s[ j ] - 'a' ] == nullptr )
                cur -> next[ s[ j ] - 'a' ] = new trie() ;
            cur = cur -> next[ s[ j ] - 'a' ] ;
            cur -> cnt ++ ;
        }
    }
}

void query()
{
    trie *cur = nullptr ;
    int ans , len ;
    while( q-- )
    {
        scanf( "%s" , s ) ;
        cur = start ;
        bool ck = true ;
        for( int i = 0 ; s[ i ] != '\0' ; i ++ )
        {
            if( cur -> next[ s[ i ] - 'a' ] != nullptr )
            {
                cur = cur -> next[ s[ i ] - 'a' ] ;
            }
            else
            {
                ck = false ;
                break ;
            }
        }

        if( ck )
        {
            pf( "%d\n" , cur -> cnt ) ;
        }
        else
        {
            pf( "0\n" ) ;
        }
    }
}

int main()
{
    start = new trie() ;
    scin2( n , q ) ;
    scanf( "%s" , s ) ;
    build() ;
    query() ;

    return 0 ;
}

