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

// void preProcess(vvll& pre, vll& arr){
//     ll n = arr.size();
//     for(ll i = 1; i < n; ++i){
//         pre[i][i] = i;
//     }

//     for(ll i = 1; i < n; ++i){
//         for(ll j = i + 1; j < n; ++j){
//             if(arr[pre[i][j-1]] < arr[j])
//                 pre[i][j] = pre[i][j-1];
//             else
//                 pre[i][j] = j;
//         }
//     }

// }

// void solve()
// {
//     ll n, q;
//     cin >> n >> q;
//     vll arr(n + 1, 0);
//     vector<vector<long long>>pre(n + 1, vector<long long>(n + 1, 0));
//     input(arr, 1, n);
//     preProcess(pre, arr);
//     while(q--){
//         ll l, r;
//         cin >> l >> r;
//         cout << arr[pre[l][r]] << endl;
//     }

// }
vll Tree(1000000, 0);

void build(vll& arr, ll node, ll l, ll r){
    if(l == r){
        Tree[node] = arr[l];
        return;        
    }
    ll mid = l + (r-l)/2;
    build(arr, 2*node + 1, l, mid);
    build(arr, 2*node + 2, mid + 1, r);
    Tree[node] = min(Tree[2*node + 1], Tree[2*node + 2]);
}


ll query(ll node, ll s, ll e, ll l, ll r){
    if(s > r or e < l)
        return INT_MAX;
    if(s >= l and  e <= r)
        return Tree[node];
    ll mid = s + (e-s)/2;
    ll left = query(2*node + 1, s, mid, l, r);
    ll right = query(2*node + 2, mid+1, e, l, r);
    return min(left, right);
}

void solve(){
    ll n, q;
    cin >> n >> q;
    vll arr(n);
    input(arr, 0, n-1);
    build(arr, 0, 0, n-1);
    while(q--){
        ll l, r;
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



