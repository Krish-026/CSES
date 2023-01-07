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

// int fun(vll arr, ll index, ll target, ll count){
//     if(target == 0) return count;
//     if(target < 0 or index < 0)
//         return INT_MAX;
//     ll notPick = fun(arr, index - 1, target, count);
//     ll pick = fun(arr, index, target - arr[index], count+1);

//     return min(notPick, pick);
// }

// void solve()
// {
//     ll n, x;
//     cin >> n >> x;
//     vll arr(n);
//     input(arr, 0, n - 1);
//     ll ans = fun(arr, n-1, x, 0LL);
//     if(ans == INT_MAX)
//         cout << -1;
//     else
//         cout << ans;   

// }

void solve(){
    ll n, target;
    cin >> n >> target;
    vll arr(n);
    input(arr, 0, n-1);
    vll dp(target+1, 1e9);
    dp[0] = 0;
    rep(i, 1, target){
        rep(j, 0, n-1){
            if(i - arr[j] >= 0){
                dp[i] = min(dp[i], dp[i-arr[j]]+1);
            }
        }
    }
    cout << (dp[target] == 1e9 ? -1 : dp[target]) << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}