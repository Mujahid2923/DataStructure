void init( int node, int b, int e )
{
    if( b == e )
    {
        Tree[ node ] = arr[ b ] ;
        return ;
    }
    segment_tree ;
    init( Lnode, b, mid ) ;
    init( Rnode, mid + 1, e ) ;
    Tree[ node ] = Tree[ Lnode ] + Tree[ Rnode ] ;
}

void update( int node, int b, int e, int i, int newvalue )
{
    if( i > e || i < b ) return ;
    if( b >= i && e <= i )
    {
        Tree[ node ] = newvalue ;
        return ;
    }

    segment_tree ;
    update( Lnode, b, mid, i, newvalue ) ;
    update( Rnode, mid + 1, e, i, newvalue ) ;
    Tree[ node ] = Tree[ Lnode ] + Tree[ Rnode ] ;
}

int query( int node, int b, int e, int i, int j )
{
    if( b > j || e < i ) return 0 ;
    if( b >= i && e <= j ) return Tree[ node ] ;
    segment_tree ;
    return query( Lnode, b, mid, i, j ) + query( Rnode, mid + 1, e, i, j ) ;
}


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

#define mx 100005

int arr[ mx ];
int Tree[ mx * 4 ];

int query( int node, int b, int e, int i, int j )
{
    if( b > j || e < i )
    {
        return 0 ;
    }

    if( b >= i && e <= j )
    {
        return Tree[ node ] ;
    }

    int Lnode = node * 2 ;
    int Rnode = node * 2 + 1 ;

    int mid = ( b + e ) / 2 ;
    int s1 = query( Lnode, b, mid, i, j ) ;
    int s2 = query( Rnode, mid + 1, e, i, j ) ;

    return s1 + s2 ;
}

void update( int node, int b, int e, int i, int newvalue )
{
    if( i > e || i < b )
    {
        return ;
    }

    if( b >= i && e <= i )
    {
        Tree[ node ] = newvalue ;
        return ;
    }

    int Left = node * 2 ;
    int Right = node * 2 + 1 ;

    int mid = ( b + e ) / 2 ;
    update( Left, b, mid, i, newvalue ) ;
    update( Right, mid + 1, e, i, newvalue ) ;

    Tree[ node ] = Tree[ Left ] + Tree[ Right ] ;
}


void init( int node, int b, int e )
{
    if( b == e )
    {
        Tree[ node ] = arr[ b ] ;
        return ;
    }

    int Left = node * 2 ;
    int Right = node * 2 + 1 ;
    int mid = ( b + e ) / 2 ;

    init( Left, b, mid ) ;
    init( Right, mid + 1, e ) ;
    Tree[ node ] = Tree[ Left ] + Tree[ Right ] ;
}

int main()
{
    int n;
    cin >> n ;

    for( int i = 1 ; i <= n ; i ++ )
    {
        cin >> arr[ i ] ;
    }

    int a, b ;
    cin >> a >> b ;
    init( 1, 1, n ) ;  ///For transforming array into segment tree usable array

    int ans1 = query( 1, 1, n, a, b ) ;    ///Where add will be occur
    cout <<"Normal sum before update :"<<endl<<ans1<<endl;
    update( 1, 1, n, 8, -10 ) ;
    int ans2 = query( 1, 1, n, a, b ) ;
    cout << "Sum after update :" << endl << ans2 << endl ;
    return 0;

}
/*
8
2 1 4 2 1 3 2 -1
1 8
ans=14
after update:5
*/
