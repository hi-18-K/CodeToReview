#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <iostream>
#include<string>
#include <cstring> 
#include<map>
#include<queue>
#include <utility>
#include<algorithm>
#include <assert.h>
# include <cstdio> 
# include <vector> 
#include<math.h>
#include<limits>
#include<iomanip>

using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll int
#define  sll stack<ll>
#define  qll queue<ll>
#define  pll pair<ll,ll>
#define  vll vector<ll>
#define  vpi vector<pair<int,int>>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ppb pop_back
# define ln cout << "\n" ;

const int N = (int) 1e5 + 5;
int n, a[N], u[N], ans, d[N];

void Dfs (int v, int f = 0) {
        d[v] = f;
        u[v] = 1;
        if (u[a[v]] == 1) {
                ans += d[v] - d[a[v]] + 1;
        } else if (u[a[v]] == 0) {
                Dfs (a[v], f + 1);
        }
        u[v] = 2;
}

inline void solve () {
        ans = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
                u[i] = 0;
                cin >> a[i];
                a[i] = (i + a[i] + 1) % n;
        }
        for (int i = 0; i < n; i++) {
                if (u[i] == 0) {
                        Dfs (i);
                }
        }
        printf ("%d\n", ans);
}

int main() 
{
	fastio
	ll t; cin >> t; while(t--)
        solve();
	return 0;
}
