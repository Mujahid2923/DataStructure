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
#define          PI                     3.141592653589793238462643
#define          zero(a)                memset(a,0,sizeof a)
#define          all(v)                 v.begin(),v.end()
#define          Upper(c,x)           (upper_bound(c.begin(),c.end(),x)-c.begin())
#define          Lower(c,x)           (lower_bound(c.begin(),c.end(),x)-c.begin())
#define          Unique(X)             (X).erase(unique(all(X)),(X).end())

///priority_queue<int,vector<int>,greater<int> >pq;
///string str = "abcdefghijklmnopqrstuvwxyz";
///string s2 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ;

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
///sort( all( v ) ) ;

vl v, v1, v2 ;
vector < pll > vec ;
map < ll, ll > Mp ;
map < char, int > Mp2 ;
set < ll > st ;
vector < double > VEC ;
stack < char > Stack ;
stack < int > Stack2 ;

bool higher( char a, char b )
{
    Mp2[ '-' ] = 1 ;
    Mp2[ '+' ] = 2 ;
    Mp2[ '*' ] = 3 ;
    Mp2[ '/' ] = 4 ;
    if( Mp2[ a ] > Mp2[ b ] )
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

void calculation( string s )
{
    for ( int i = 0 ; i < s.size() ; i ++ )
    {
        if( s[ i ] >= '1' && s[ i ] <= '9' )
        {
            Stack2.push( s[ i ] - '0' ) ;
        }
        else
        {
            if( s[ i ] == '+' )
            {
                int a = Stack2.top() ;
                Stack2.pop() ;
                int b = Stack2.top() ;
                Stack2.pop() ;
                Stack2.push( b + a ) ;
            }
            else if( s[ i ] == '-' )
            {
                int a = Stack2.top() ;
                Stack2.pop() ;
                int b = Stack2.top() ;
                Stack2.pop() ;
                Stack2.push( b - a ) ;
            }
            else if( s[ i ] == '*' )
            {
                int a = Stack2.top() ;
                Stack2.pop() ;
                int b = Stack2.top() ;
                Stack2.pop() ;
                Stack2.push( b * a ) ;
            }
            else if( s[ i ] == '/' )
            {
                int a = Stack2.top() ;
                Stack2.pop() ;
                int b = Stack2.top() ;
                Stack2.pop() ;
                Stack2.push( b / a ) ;
            }
        }
    }
    cout << Stack2.top() << endl ;
}

int main()
{
    CIN ;
    string s, str = "" ;
    getline( cin, s ) ;

    for ( int i = 0 ; i < s.size() ; i ++ )
    {
        if( s[ i ] == ' ' || s[ i ] == ',' )
        {
            continue ;
        }
        else if( s[ i ] >= '1' && s[ i ] <= '9' )
        {
            str += s[ i ] ;
        }
        else if( s[ i ] == '+' || s[ i ] == '-' || s[ i ] == '*' || s[ i ] == '/' )
        {
            while( !Stack.empty() && s[ i ] != '(' && higher( Stack.top(), s[ i ] ) )
            {
                str += Stack.top() ;
                Stack.pop() ;
            }
            Stack.push( s[ i ] ) ;
        }
        else if( s[ i ] == '(' )
        {
            Stack.push( s[ i ] ) ;
        }
        else if( s[ i ] == ')' )
        {
            while( !Stack.empty() && Stack.top() != '(' )
            {
                str += Stack.top() ;
                Stack.pop() ;
            }
            Stack.pop() ;
        }
    }

    while( !Stack.empty() )
    {
        str += Stack.top() ;
        Stack.pop() ;
    }
    cout << str << endl ;
    calculation( str ) ;


    return 0 ;
}

///(( 6 / ( 3 - (1 + 1) ) ) * 3 ) - ( 2 + ( 1 * 1 ) )
///((A+B)*C-D)*E
///A+B*C-D*E
