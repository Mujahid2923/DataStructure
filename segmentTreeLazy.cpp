///...................................*****.................................................///
///                  Mujahidul Islam ( mujahidulislam2923@gmail.com )                       ///
///                  Department of Ict                                                      ///
///                  Comilla University , Bangladesh.                                       ///
///...................................*****.................................................///

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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
#define          scln(x)                scanf("%lld",&(x))
#define          scln2(x,y)             scanf("%lld %lld",&(x),&(y))
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
///#define          endl                   '\n'

///bool operator < ( const Node& p ) const{ return cost < p.cost ; }
///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" ;
///string s = std::bitset<64>(n).to_string();
///---------------Order set-------------------
///template<typename T> using orderset =tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
///#include <ext/pb_ds/assoc_container.hpp>
///using namespace __gnu_pbds;
///*os.find_by_order(index) os.order_of_key(value)

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

#define mx 1000

int arr[ mx ];
int Tree[ mx * 4 ];
int Lazy[ mx * 4 ];

int query( int node, int b, int e, int i, int j )
{
    int Lnode = node << 1 ;
    int Rnode = ( node << 1 ) + 1 ;

    int mid = ( b + e ) >> 1 ;
    if( b > e || b > j || e < i )
    {
        return INT_MIN ;
    }

    if( Lazy[ node ] != 0 )
    {
        Tree[ node ] += Lazy[ node ] ;
        if( b != e )
        {
            Lazy[ Lnode ] += Lazy[ node ] ;
            Lazy[ Rnode ] += Lazy[ node ] ;
        }
        Lazy[ node ] = 0 ;
    }

    if( b >= i && e <= j )
    {
        return Tree[ node ] ;
    }

    int s1 = query( Lnode, b, mid, i, j ) ;
    int s2 = query( Rnode, mid + 1, e, i, j ) ;

    return min( s1, s2 ) ;
}

void updateLazy( int node, int b, int e, int i,int j, int value )
{
    int Lnode = node << 1 ;
    int Rnode = ( node << 1 ) + 1 ;

    int mid = ( b + e ) >> 1 ;

    if( Lazy[ node ] != 0 )
    {
        Tree[ node ] += Lazy[ node ] ;
        if( b != e )
        {
            Lazy[ Lnode ] += Lazy[ node ] ;
            Lazy[ Rnode ] += Lazy[ node ] ;
        }
        Lazy[ node ] = 0 ;
    }

    if( b > e || b > j || e < i )
    {
        return ;
    }

    if( b >= i && e <= j )
    {
        Tree[ node ] += value ;
        if( b != e )
        {
            Lazy[ Lnode ] += value ;
            Lazy[ Rnode ] += value ;
        }
        return ;
    }

    updateLazy( Lnode, b, mid, i, j, value ) ;
    updateLazy( Rnode, mid + 1, e, i, j, value ) ;

    Tree[ node ] = min( Tree[ Lnode ], Tree[ Rnode ] ) ;
}


void init( int node, int b, int e )
{
    if( b == e )
    {
        Tree[ node ] = arr[ b ] ;
        return ;
    }

    int Lnode = node << 1 ;
    int Rnode = ( node << 1 ) + 1 ;
    int mid = ( b + e ) >> 1 ;

    init( Lnode, b, mid ) ;
    init( Rnode, mid + 1, e ) ;
    Tree[ node ] = min( Tree[ Lnode ], Tree[ Rnode ] ) ;
}

int main()
{
    int n;
    cin >> n ;

    for( int i = 1 ; i <= n ; i ++ )
    {
        cin >> arr[ i ] ;
    }

    init( 1, 1, n ) ;
    updateLazy( 1, 1, n, 1, 4, 5 ) ;
    int ans = query( 1, 1, 8, 1, 8 ) ;
    cout << ans << endl ;
    updateLazy( 1, 1, n, 5, 8, 12 ) ;
    ans = query( 1, 1, 8, 1, 8 ) ;
    cout << ans << endl ;
    updateLazy( 1, 1, n, 2, 6, -5 ) ;
    ans = query( 1, 1, 8, 1, 8 ) ;
    cout << ans << endl ;

    return 0;

}

/*
8
2 1 4 2 1 3 2 -1
*/

///https://www.youtube.com/watch?v=Uyue53xZf-w
///https://www.youtube.com/watch?v=xuoQdt5pHj0 enough to understand
///http://delower13.blogspot.com/2017/06/blog-post_92.html
