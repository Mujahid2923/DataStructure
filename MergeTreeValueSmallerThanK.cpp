///https://www.spoj.com/problems/MKTHNUM/

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
#define          DBG                    cout << endl << "---------------" << endl ;
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

#define mx 200005
vector < int > v ;
vector < int > Tree[ 4 * mx ] ;

void buildTree( int node, int b, int e )
{
    int Lnode = node << 1 ;
    int Rnode = Lnode + 1 ;
    int mid = ( b + e ) >> 1 ;

    if( b == e )
    {
        Tree[ node ].pb( v[ b ] ) ;
        return ;
    }

    buildTree( Lnode, b, mid ) ;
    buildTree( Rnode, mid + 1, e ) ;

    sort( all( Tree[ Lnode ] ) ) ;
    sort( all( Tree[ Rnode ] ) ) ;
    merge( all( Tree[ Lnode ] ), all( Tree[ Rnode ] ), back_inserter( Tree[ node ] ) ) ;
}

int query( int node, int b, int e, int i, int j, int k )
{
    int Lnode = node << 1 ;
    int Rnode = Lnode + 1 ;
    int mid = ( b + e ) >> 1 ;

    if( e < i || b > j )
    {
        return 0 ;
    }

    if( i <= b && e <= j )
    {
        return Upper( Tree[ node ], k ) ;
    }

    int r1 = query( Lnode, b, mid, i, j, k ) ;
    int r2 = query( Rnode, mid + 1, e, i, j, k ) ;

    return r1 + r2 ;

}

int main()
{
    int t ,n, m, a, x, y, k ;
    scin2( n, m ) ;
    for( int i = 0 ; i < n ; i ++ )
    {
        scin( a ) ;
        v.pb( a ) ;
    }

    buildTree( 1, 0, n - 1 ) ;

    for( int i = 0 ; i < m ; i ++ )
    {
        scin2( x, y ) ;
        -- x ;
        -- y ;
        scin( k ) ;
        int ans = query( 1, 0, n - 1, x, y, k ) ;
        printf( "%d\n", ans ) ;
    }


    return 0 ;
}

///https://discuss.codechef.com/t/merge-sort-tree-tutorial/14277
///https://www.commonlounge.com/discussion/fe6ac441785c44d6a959eab662f15adc



