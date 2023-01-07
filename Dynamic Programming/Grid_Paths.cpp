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

// int path(vector<string>s, int i, int j, vvi& dp){
//     if(i < 0 or j < 0 or s[i][j] == '*')
//         return 0;
//     if(i == 0 and j == 0 and s[i][j] != '*')
//         return 1;
//     if(dp[i][j] != -1)
//         return dp[i][j];
//     int up = path(s, i-1, j, dp);
//     int left = path(s, i, j-1, dp);

//     return dp[i][j] = (up % Mod + left % Mod) % Mod;
// }

// void solve()
// {
//     int n;
//     cin >> n;
//     vector<string>s(n);
//     for(int i = 0; i < n; ++i)
//         cin >> s[i];

//     vector<vi>dp(n, vi(n, -1));
//     // for(int i = 0; i < n; ++i)
//     //     cout << s[i] << endl;
//     cout << path(s, n-1, n-1, dp);
// }

void solve(){
    int n;
    cin >> n;
    vvi dp(n, vi(n,0));
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        for(int j = 0; j < n; ++j){
            if(s[j] == '.'){
                //up
                if(i > 0) dp[i][j] = dp[i-1][j]%Mod;
                //left
                if(j > 0) (dp[i][j] += dp[i][j-1]) %= Mod;
            }
            else dp[i][j] = 0;
        }
    }
    cout << dp[n-1][n-1];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
