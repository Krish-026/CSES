// input
// 3
// 3 5
// 4 9
// 5 8
// output
// 2
// Here,we sort the pair according to the ending time.Now if there is no overlaps then we increase the count.Always temp value updated to pair second element.
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
bool sort_by_second(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
    return a.second < b.second;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> a;
    rep(i, 0, n - 1)
    {
        ll num1, num2;
        cin >> num1 >> num2;
        a.pb(mp(num1, num2));
    }
    ll j = 0, ans = 0;
    sort(all(a), sort_by_second);
    rep(i, 1, n - 1)
    {
        if (a[i].first >= a[j].second)
        {
            ++ans;
            j = i;
        }
    }
    cout << ans + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}