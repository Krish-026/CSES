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
#define INF 0x3f3f3f3f
using namespace std;

// TLE Error

// void build(vll& Tree, vll arr, ll node, ll start, ll end){
//     if(start == end){
//         Tree[node] = arr[start];
//         return;
//     }
//     ll mid = start + (end - start)/2;
//     build(Tree, arr, 2 * node + 1, start, mid);
//     build(Tree, arr, 2 * node + 2, mid + 1, end);
//     Tree[node] = min(Tree[2 * node + 1], Tree[2 * node + 2]);
// }


// ll query(vll& Tree, ll node, ll start, ll end, ll l, ll r){
//     if(start > r or end < l)
//         return 0x3f3f3f3f;
//     if(start >= l and end <= r)
//         return Tree[node];
//     ll mid = start + (end - start)/2;
//     ll left = query(Tree, 2 * node + 1, start, mid, l, r);
//     ll right = query(Tree, 2 * node + 2, mid + 1, end, l, r);
//     return min(left, right);
// }

// void update(vll& Tree, vll&arr, ll node, ll start, ll end, ll pos, ll val){
//     if(start > pos or pos > end)
//         return;

//     if(start == end){
//         arr[pos] = val;
//         Tree[node] = val;
//         return;
//     }
//     ll mid = start + (end - start)/2;
//     if(pos <= mid)
//         update(Tree, arr, 2 * node + 1, start, mid, pos, val);
//     else
//         update(Tree, arr, 2 * node + 2, mid + 1, end, pos, val);
//     Tree[node] = min(Tree[2 * node + 1], Tree[2 * node + 2]);
// }
// void solve()
// {
//     ll n, q;
//     cin >> n >> q;
//     vll arr(n), Tree(4*n);
//     input(arr, 0, n-1);
//     build(Tree, arr, 0, 0, n-1);
//     // output(Tree, 0, 4*n); cout << endl;
//     while(q--){
//         ll c, l, r;
//         cin >> c >> l >> r;
//         if(c == 2)
//             cout << query(Tree, 0, 0, n-1, l-1, r-1) << endl;
//         else
//             update(Tree, arr, 0, 0, n-1, l-1, r);
//     }
// }



const ll size = 1000000;
ll arr[size], tree[size];

void build(int node, int s, int e){
    if(s == e){
        tree[node] = arr[e];
        return;
    }
    int mid = s + (e-s)/2;
    build(2 * node + 1, s, mid);
    build(2 * node + 2, mid + 1, e);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}

ll query(int node, int s, int e, int l, int r){
    if(s > r or e < l)
        return INT_MAX;
    if(s >= l and e <= r)
        return tree[node];
    int mid = s + (e - s)/2;
    ll left = query(2 * node + 1, s, mid, l, r);
    ll right = query(2 * node + 2, mid + 1, e, l, r);
    return min(left, right);
}

void update(int node, int s, int e, int pos, ll val){
    if(s > pos or pos > e)
        return;
    if(s == e){
        arr[pos] = val;
        tree[node] = val;
        return;
    }

    int mid = s + (e - s)/2;
    if(pos <= mid)
        update(2 * node + 1, s, mid, pos, val);
    else 
        update(2 * node + 2, mid + 1, e, pos, val);
    tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
}
void solve(){
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
        cin >> arr[i];
    build(0, 0, n-1);
    // output(tree, 0, 4*n); cout << endl;
    while(q--){
        ll c, l, r;
        cin >> c >> l >> r;
        if(c == 2)
           cout << query(0, 0, n-1, (int)l - 1, (int)r - 1) << "\n";
        else
            update(0, 0, n-1, (int)l-1, r);
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