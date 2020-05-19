///https://toph.co/arena?practice=5ec37fc941096800011cd46b#!/p/paltu-a-prime-lover
#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define          FaRaBi                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          ull                    unsigned long long int
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          eb                     emplace_back
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
//#define          input                  freopen("input.txt","rt", stdin)
//#define          output                 freopen("output.txt","wt", stdout)
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
#define          segment_tree           int Lnode = node << 1 , Rnode = Lnode + 1 , mid = ( b + e ) >> 1 ;


///--------------------**********----------------------------------

vector < int > v, v1, v2, v3, v4 ;
vector < pair < ll, ll > > vec, vec1 ;
vector < pii > adj[ 100005 ] ;
map < ll, ll > Mp, Mp1, Mp2 ;
set < ll > st, st1,st2 ;
queue < ll > Q ;
stack < ll > Stk ;
multiset < ll > S ;

///---------------------**********--------------------------------

ll q, n ;
string s ;
const int MAXN = 1e8 ;
bitset< MAXN > status ;
void pre()
{
    int rt = sqrt( MAXN ) + 1 ;

    for( int i = 3 ; i < rt ; i += 2 )
    {
        if( !status[ i ] )
        {
            for( int j = i * i ; j < MAXN ; j += ( i << 1 ) )
            {
                status[j] = true;
            }
        }
    }

    v.push_back( 2 ) ;

    for( int i = 3; i < MAXN; i += 2 )
    {
        if( !status[ i ] )
        {
            v.push_back( i ) ;
        }
    }
}

void Reset() {}

int arr[ 100005 ] ;
pair < int , int > Tree[ 400005 ] ;

void init( int node, int b, int e )
{
    if( b == e )
    {
        Tree[ node ].ff = arr[ b ] ;
        Tree[ node ].ss = arr[ b ] ;
        return ;
    }
    segment_tree ;
    init( Lnode, b, mid ) ;
    init( Rnode, mid + 1, e ) ;
    Tree[ node ].ff = min( Tree[ Lnode ].ff , Tree[ Rnode ].ff ) ;
    Tree[ node ].ss = max( Tree[ Lnode ].ss , Tree[ Rnode ].ss ) ;
}

void update( int node, int b, int e, int i, int val )
{
    if( i > e || i < b ) return ;
    if( b >= i && e <= i )
    {
        Tree[ node ].ff = val ;
        Tree[ node ].ss = val ;
        return ;
    }
    segment_tree ;
    update( Lnode, b, mid, i, val ) ;
    update( Rnode, mid + 1, e, i, val ) ;
    Tree[ node ].ff = min( Tree[ Lnode ].ff , Tree[ Rnode ].ff ) ;
    Tree[ node ].ss = max( Tree[ Lnode ].ss , Tree[ Rnode ].ss ) ;
}

pii query( int node, int b, int e, int i, int j )
{
    if( b > j || e < i ) return { 2e8 , -2e8 } ;
    if( b >= i && e <= j ) return { Tree[ node ].ff, Tree[ node ].ss } ;
    segment_tree ;
    pii p1 = query( Lnode, b, mid, i, j ) ;
    pii p2 = query( Rnode, mid + 1, e, i, j ) ;
    return { min( p1.ff, p2.ff ) , max( p1.ss , p2.ss ) } ;
}

void Input()
{
    scln2( n , q ) ;
    for( int i = 1 ; i <= n ; i ++ )
    {
        scin( arr[ i ] ) ;
    }
    init( 1, 1, n ) ;
}


void Calculation()
{
    int a, b, c ;
    while( q-- )
    {
        scin3( a, b, c ) ;
        if( a == 1 )
        {
            update( 1, 1, n, b, c ) ;
        }
        else
        {
            pii it = query( 1, 1, n, b, c ) ;
            int val = Upper( v, it.ss ) - Lower( v, it.ff ) ;
            pf( "%d\n", val ) ;
        }
    }
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    int t ;
    pre() ;
    t = 1 ;
    while( t-- )
    {
        solve() ;
    }

    return 0 ;
}

