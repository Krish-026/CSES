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
    long size, target_sum;
    cin >> size >> target_sum;
    vector<pair<long, long>> vp;
    rep(i, 0, size - 1)
    {
        ll num;
        cin >> num;
        vp.pb(mp(num, i + 1));
    }
    sort(all(vp));
    long i = 0, j = size - 1;
    pair<int, int> ans;
    while (i < j)
    {
        if (vp[i].first + vp[j].first == target_sum)
        {
            ans.first = vp[i].second;
            ans.second = vp[j].second;
            break;
        }
        else if (vp[i].first + vp[j].first > target_sum)
            --j;
        else if (vp[i].first + vp[j].first < target_sum and i != j)
            ++i;
    }
    if (i < j)
        cout << ans.first << " " << ans.second << endl;
    else
        cout << "IMPOSSIBLE" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}

// int main()
// {
//     int n, x;
//     cin >> n >> x;
//     vi a(n);
//     map<int, int> vals;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (vals.count(x - a[i]))
//         {
//             cout << i + 1 << " " << vals[x - a[i]] << "\n";
//             return 0;
//         }
//         vals[a[i]] = i + 1;
//     }
//     cout << "IMPOSSIBLE" << '\n';
// }