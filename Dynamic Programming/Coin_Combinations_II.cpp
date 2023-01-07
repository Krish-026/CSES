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

// int fun(vector<int>arr, int target, int index){
//     if(target == 0) return 1;
//     if(target < 0 or index < 0)  return 0;
//     int pick = fun(arr, target - arr[index], index);
//     int notPick = fun(arr, target, index - 1);

//     return (pick + notPick)%Mod;
// }

void solve()
{
    int n, target;
    cin >> n >> target;
    vector<int> arr(n);
    for(int&x : arr)  cin >> x;
    // cout << fun(arr, target, n-1);
    vvi dp(n+1, vi(target+1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j <= target; ++j){
            dp[i][j] = dp[i-1][j];
            int pos = j - arr[i-1];
            if(pos >= 0)
                (dp[i][j] += dp[i][pos]) %= Mod;
        }
    }
    cout << dp[n][target];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}