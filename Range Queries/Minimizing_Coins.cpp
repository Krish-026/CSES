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

int fun(vi arr, int target, int index, int& count){
    if(target < 0 or index < 0)
        return INT_MAX;
    if(target == 0) return 1;
    int pick = fun(arr, target - arr[index], index, count);
    int notPick = fun(arr, target, index - 1, count);
    return min(pick, notPick);
}

void solve()
{
    int n, target;
    cin >> n >> target;
    vi arr(n);
    input(arr, 0, n-1);
    int ans = fun(arr, target, n-1, 0);
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