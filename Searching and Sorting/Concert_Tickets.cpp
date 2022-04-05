// multiset
// Here we need the lower bound of the multiset(as the values can be duplicate) each time and erase it from the set. If the iterator points to the end of set that means there is no value to satisfy the condition.
// https://codeforces.com/blog/entry/83295
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
// CODE BEGINS;
void solve()
{
    ll n, m, ans = 0;
    cin >> n >> m;
    multiset<ll> s;
    rep(i, 0, n - 1)
    {
        cin >> ans;
        s.insert(ans);
    }
    rep(i, 0, m - 1)
    {
        cin >> ans;
        auto it = s.upper_bound(ans);
        if (it == s.begin())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << *(--it) << endl;
            s.erase(it); // remove tickets which is already selected
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}