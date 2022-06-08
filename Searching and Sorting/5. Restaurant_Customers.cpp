// https://usaco.guide/problems/cses-1619-restaurant-customers/solution
// Co-ordinate Compression
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
    ll n;
    cin >> n;

    vector<pair<ll, ll>> a;
    rep(i, 0, n - 1)
    {
        ll l, r;
        cin >> l >> r;
        a.pb({l, 1});
        a.pb({r, -1});
    }
    sort(all(a));
    ll sum = 0, ans = 0;
    n = a.size();
    rep(i, 0, n - 1)
    {
        sum += a[i].second;
        ans = max(sum, ans);
    }
    cout << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}