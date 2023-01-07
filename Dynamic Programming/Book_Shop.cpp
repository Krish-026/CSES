#include <bits/stdc++.h>
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
#define rep(a, b, c) for (long long a = b; a <= c; ++a)
#define repr(a, b, c) for (long long a = b; a >= c; --a)
#define input(a, b, n)                 \
    for (long long i = b; i <= n; ++i) \
        cin >> a[i];
#define output(a, b, n)                \
    for (long long i = b; i <= n; ++i) \
        cout << a[i] << " ";
#define Mod 1000000007
using namespace std;

void solve()
{
    int n, x;
    cin >> n >> x;
    int arr[n], dp[n+1][x+1], pages[n];
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    for(int i = 0; i < n; ++i) 
        cin >> pages[i];
    for(int i = 0; i <= x; ++i) dp[0][i] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= x; ++j){
            dp[i][j] = dp[i-1][j];
            int prev = j - arr[i-1] ;
            if(prev >= 0)
                dp[i][j] = max(dp[i][j], dp[i-1][prev] + pages[i-1]);
        }
    }
    cout << dp[n][x];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}