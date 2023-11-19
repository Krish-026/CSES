#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<long>
#define vvl vector<vl>
#define vll vector<ll>
#define vvll vector<vll>
#define vb vector<bool>
#define pb push_back
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define mp make_pair
#define Mod 1000000007
#define ln endl
#define rep(a, b, c) for (long long a = b; a <= c; ++a)
#define repr(a, b, c) for (long long a = b; a >= c; --a)
#define input(a, b, n)                 \
    for (long long i = b; i <= n; ++i) \
        cin >> a[i];
#define output(a, b, n)                \
    for (long long i = b; i <= n; ++i) \
        cout << a[i] << " ";
#define fastio()            ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
#define tc              ll tc;  cin>>tc;  while(tc--) 
 
const int N = 998244353;
/*--------------------------------------------------------------------------------------------------------------------------*/
 
int gcd(int a,int b){return b?gcd(b,a%b):a;}int lcm(int a,int b){return a/gcd(a,b)*b;}
int add(int a,int b,int m){return (a+b)%m;}
int sub(int a,int b,int m){return ((a-b)%m+m)%m;}
int mul(int a,int b,int m){return ((a%m)*(b%m))%m;}
/*--------------------------------------------------------------------------------------------------------------------------*/
 
void sort_dec(int &a ,int &b , int &c) //to sort a,b,c in decreasing order
{
    if (a<b) swap(a,b);
    if (a<c) swap(a,c);
    if (b<c) swap(b,c);
}
/*--------------------------------------------------------------------------------------------------------------------------*/
 
bool is_prime(int n){// This will check if given n is prime or not 
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5; i*i<=n;i=i+6){
        if (n%i==0 || n%(i+2)==0) return false;
    }
    return true;
}
/*--------------------------------------------------------------------------------------------------------------------------*/
 
// This will give prime factorization of 'n'
// 0(sqrt(n)/log(n))
// count of prime numbers is from 1 to n => (n/log(n))
vector<int> prime_fact(int n){
    vector<int> p,unique_p;
    if(n%2==0){
        unique_p.pb(2);
        while(n%2==0){
            p.pb(2),n/=2;
        }
    }
    for(int i=3;i*i<=n;i+=2){
        if(n%i==0){
            unique_p.pb(i);
            while(n%i==0){
                n/=i,p.pb(i);
            }
        }
    }
    if(n>1) p.pb(n),unique_p.pb(n);
//     return unique_p;
    return p;
}
/*--------------------------------------------------------------------------------------------------------------------------*/
 
ll findGCD(ll arr[], ll n)
{
    ll result = arr[0];
    for (ll i = 1; i<=n; i++)
    {
        result = gcd(arr[i], result);
 
        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}
/*--------------------------------------------------------------------------------------------------------------------------*/
 
ll countDivisors(ll n)
{
    ll cnt = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            // If divisors are equal,
            // count only one
            if (n / i == i)
                cnt++;
 
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
/*--------------------------------------------------------------------------------------------------------------------------*/
 
ll rootSqrt(ll x)
{
    // Base cases
    if (x == 0 || x == 1)
    return x;
 
    // Starting from 1, try all numbers until
    // i*i is greater than or equal to x.
    ll i = 1, result = 1;
    while (result <= x)
    {
      i++;
      result = i * i;
    }
    return i - 1;
}
/*--------------------------------------------------------------------------------------------------------------------------*/


long long binpow(long long a, long long b) {
    a %= Mod;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}


/*--------------------------------------------------------------------------------------------------------------------------*/
 
void solve()
{
    int n, m, ans = 0;
    cin >> n >> m;
    multiset<int> st;
    for (int i = 0; i < n; ++i){
        cin >> ans;
        st.insert(ans);
    }

    for (int i = 0; i < m; ++i){
        cin >> ans;
        auto it = st.upper_bound(ans);

        //next greater element is first value
        if(it == st.begin()){
            cout << -1 << endl;
        }else{
            cout << *(--it) << endl;
            st.erase(it);
        }
    }
}
 
int32_t main()
{
    fastio()
    // tc
    {
        solve();
    }
  return 0;
}