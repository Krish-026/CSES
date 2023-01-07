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

void build(vll& Tree, vll&arr, ll node, ll start, ll end){
    if(start == end){
        Tree[node] = arr[end];
        return;
    }
    ll mid = start + (end - start)/2;
    build(Tree, arr, 2 * node + 1, start, mid);
    build(Tree, arr, 2 * node + 2, mid + 1, end);
    Tree[node] = (Tree[2 * node + 1] + Tree[2 * node + 2]);
}

void update(vll& Tree, vll&arr, ll node, ll start, ll end, ll pos, ll val){
    if(start == end){
        arr[pos] = val;
        Tree[node] = val;
        return;
    }
    ll mid = start + (end - start)/2;
    if(pos <= mid)
        update(Tree, arr, 2 * node + 1, start, mid, pos, val);
    else
        update(Tree, arr, 2 * node + 2, mid + 1, end, pos, val);
    Tree[node] = (Tree[2 * node + 1] + Tree[2 * node + 2]);
}

ll query(vll&Tree, ll node, ll start, ll end, ll l, ll r){
    if(start > r or end < l)
        return 0;
    if(start >= l and end <= r)
        return Tree[node];
    ll mid = start + (end - start)/2;
    ll left = query(Tree, 2 * node + 1, start, mid, l, r);
    ll right = query(Tree, 2 * node + 2, mid + 1, end, l, r);
    return (left + right);
}

void solve()
{
    ll n, q;
    cin >> n >> q;
    vll arr(n), Tree(4*n, 0);
    input(arr, 0, n-1);
    build(Tree, arr, 0, 0, n-1);
    while(q--){
        ll l, r, c;
        cin >> c >> l >> r;
        if(c == 2)
            cout << query(Tree, 0, 0, n-1, l-1, r-1) << endl;
        else
            update(Tree, arr, 0, 0, n-1, l-1, r);
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