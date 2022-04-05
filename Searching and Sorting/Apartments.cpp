// Two Pointer Approach
// Two pointer technique-If apartment size is greater than x+k then upper pointer will increase or less than x-k then lower pointer will increase otherwise both the pointer increase along with counter. NB.Don't forget to sort both the arrays.

//  https://codeforces.com/blog/entry/83295
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
    ll n, m, k;
    cin >> n >> m >> k;
    vll a(n), b(m);
    input(a, 0, n - 1);
    input(b, 0, n - 1);
    sort(all(a));
    sort(all(b));
    ll i = 0, j = 0, ans = 0;
    while (i < n and j < m)
    {
        if (a[i] >= b[j] - k and a[i] <= b[j] + k)
        {
            ans++;
            ++i;
            ++j;
        }
        else if (a[i] > b[j] + k)
            ++j;
        else
            ++i;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}