// Two pointer technique-First sort the array. Then we have to minimize the number .So if the pointers value over flow the limit then we decrease the upper pointer. otherwise decrease the number.
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

void solve()
{
    ll n, x, ans = 0;
    cin >> n >> x;
    vll a(n);
    input(a, 0, n - 1);
    sort(all(a));
    ll i = 0, j = n - 1;
    while (i <= j)
    {
        if (a[i] + a[j] <= x)
        {
            ++ans;
            ++i;
            --j;
        }
        if (a[j] + a[i] > x)
        {
            ++ans;
            --j;
        }
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