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

ll c = 0, pre = 0;

void merge(vll a,ll l,ll m,ll r){
    ll n1=m+1-l;
    ll n2=r-m;
    ll a1[n1],a2[n2];
    for(ll i = 0; i < n1; i++){
        a1[i] = a[l+i];
    }
    for(ll i = 0; i < n2; i++){
        a2[i] = a[m+1+i];
    }
    ll i = 0, j = 0,k = l;
    while(i<n1 && j<n2){
        if(a1[i]<=a2[j]){
            a[k++]=a1[i++];
        }
        else{
            a[k++]=a2[j++];
        c+=n1-i;
        }
    }
    while(i<n1){
        a[k++]=a1[i++];

    }
    while(j<n2){
        a[k++]=a2[j++];
    }

}

void mergeSort(vll& arr, ll l, ll r){
    if(l < r){
        ll mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

ll insertion_sort(vll arr, ll n){
    ll count = 0;
    mergeSort(arr, 0, n-1);
    rep(i, 0, n-1)
        count = c - pre;
    pre = c;
    return count;

}

void solve()
{
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vll arr(n);
        input(arr,0, n-1);
        ll count = insertion_sort(arr, n);
        cout << count << endl;
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