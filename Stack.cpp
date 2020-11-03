#include<bits/stdc++.h>
using namespace std;

#define          Looser                 ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define          ll                     long long int
#define          ld                     long double
#define          pii                    pair < int, int>
#define          pll                    pair < ll, ll>
#define          MOD                    1000000007
#define          ff                     first
#define          ss                     second
#define          pb                     push_back
#define          pf                     printf
#define          mp                     make_pair
#define          gcd(a, b)          	__gcd(a,b)
#define          lcm(a, b)              ((a)*(b)/gcd(a,b))
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

vector < ll > v, v1, v2, v3, v4 ;
vector < pair< ll, ll > > vec ;
vector < ll > adj[ 505 ], adj2[ 505 ] ;
map < ll, ll > Mp, Mp2 ;
set < ll > st, st1, st2 ;
stack < ll > Stk ;

///---------------------**********--------------------------------

ll n, x ;
string s ;

void Reset()
{
    v.clear() ;
}

void Input()
{
    cin >> n ;
    for( int i = 0 ; i < n ; i ++ )
    {
        cin >> x ;
        v.pb( x ) ;
    }
}


void Calculation()
{
    vector< int > left( n ), right( n ) ;
    for( int i = 0 ; i < n ; i ++ ) left[ i ] = i + 1 ;
    for( int i = 0 ; i < n ; i ++ ) right[ i ] = n - i ;

    stack< int > Stk1, Stk2 ;

    for( int i = 0 ; i < n ; i ++ )
    {
        while( !Stk1.empty() && v[ Stk1.top() ] > v[ i ] ) Stk1.pop() ;
        if( !Stk1.empty() ) left[ i ] = i - Stk1.top() ;
        Stk1.push( i ) ;
    }

    for( int i = 0 ; i < n ; i ++ )
    {
        while( !Stk2.empty() && v[ Stk2.top() ] > v[ i ] )
        {
            right[ Stk2.top() ] = i - Stk2.top() ;
            Stk2.pop() ;
        }
        Stk2.push( i ) ;
    }


    int ans = 0 ;
    for( int i = 0 ; i < n ; i ++ )
    {
        ans = ( ans + ( left[ i ] * right[ i ] * v[ i ] ) % MOD ) % MOD ;
    }
    cout << ans << endl ;
}

void solve()
{
    Reset() ;
    Input() ;
    Calculation() ;
}

int main()
{
    Looser ;
    int t ;
    //cin >> t ;
    t = 1 ;
    while( t-- )
    {
        solve() ;
    }
    return 0 ;
}

