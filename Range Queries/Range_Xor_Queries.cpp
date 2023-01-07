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
#define endl "\n"
const ll size = 1000000;
ll arr[size], tree[4*size];
int lchild(int node){
    return (2 * node + 1);
}
int rchild(int node){
    return (2 * node + 2);
}

void build(int node, int s, int e){
    if(s == e){
        tree[node] = arr[s];
        return;
    }
    int mid = s + (e - s)/2;
    build(lchild(node), s, mid);
    build(rchild(node), mid + 1, e);
    tree[node] = tree[lchild(node)] ^ tree[rchild(node)];
}

ll query(int node, int s, int e, int l, int r){
    if(s > r or e < l)
        return 0;
    if(s >= l and e <= r)
        return tree[node];
    int mid = s + (e - s)/2;
    ll left = query(lchild(node), s, mid, l, r);
    ll right = query(rchild(node), mid + 1, e, l, r);
    return (ll)(left ^ right);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    input(arr, 0, n-1);
    build(0, 0, n-1);
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(0, 0, n-1, l-1, r-1) << endl;
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