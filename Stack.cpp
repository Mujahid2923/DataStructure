(1) find the previous less element of each element in a vector with O(n) time:
What is the previous less element of an element?
For example:
[3, 7, 8, 4]
The previous less element of 7 is 3.
The previous less element of 8 is 7.
The previous less element of 4 is 3.
There is no previous less element for 3.
For simplicity of notation, we use abbreviation PLE to denote Previous Less Element.
---------------------------------------------------
C++ code (by slitghly modifying the paradigm):
Instead of directly pushing the element itself, here for simplicity, we push the index.
We do some record when the index is pushed into the stack.
// previous_less[i] = j means A[j] is the previous less element of A[i].
// previous_less[i] = -1 means there is no previous less element of A[i].
vector<int> previous_less(A.size(), -1);
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
    in_stk.pop();
  }
  previous_less[i] = in_stk.empty()? -1: in_stk.top();
  in_stk.push(i);
}
---------------------------------------------------------
(2) find the next less element of each element in a vector with O(n) time:
What is the next less element of an element?
For example:
[3, 7, 8, 4]
The next less element of 8 is 4.
The next less element of 7 is 4.
There is no next less element for 3 and 4.
For simplicity of notation, we use abbreviation NLE to denote Next Less Element.
------------------------------------------------------------
C++ code (by slighly modifying the paradigm):
We do some record when the index is poped out from the stack.
// next_less[i] = j means A[j] is the next less element of A[i].
// next_less[i] = -1 means there is no next less element of A[i].
vector<int> previous_less(A.size(), -1);
for(int i = 0; i < A.size(); i++){
  while(!in_stk.empty() && A[in_stk.top()] > A[i]){
    auto x = in_stk.top(); in_stk.pop();
    next_less[x] = i;
  }
  in_stk.push(i);
}
------------------------------------------------------------
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
        ans = ( ans + ( left[ i ] * right[ i ] * v[ i ] ) % MOD ) % MOD ; // left[ i ] distance from the i element to left sammler element
                                                                          // right[ i ] distance from the i element to right sammler element
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

