Counting permutations

https://www.hackerearth.com/problem/algorithm/count-the-permutations-2-365a19e4/description/

https://img.atcoder.jp/data/agc/005/editorial.pdf (same as d problem)
(Use bipartite graph to check all the permutations that can be formed.)
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
 
using namespace __gnu_pbds;
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
ll MOD=1000000007;
 
#define endl '\n'
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
ll INF = 2000000000000000001;
long double EPS = 1e-9;
ll power(ll a, ll n, ll md){if(n==0){return 1;}else{ll res=power(a,n/2,md);res=(res*res)%md;if(n%2!=0){res=(res*a)%md;}return res;}}
random_device rndm;
mt19937 grndm(rndm());
void mix(ll* a, ll* b){shuffle(a,b,grndm);}
 
const ll MX = 1005;
 
ll n, m;
vector<ll> v;
bool seen[MX];
ll dp[MX][MX];
ll choose[MX][MX];
 
ll ncr(ll n, ll r) {
	if(n < r || r < 0) {
		return 0;
	}
	if(n == r || r == 0) {
		return 1;
	}
	if(choose[n][r] != -1) {
		return choose[n][r];
	} 
	return choose[n][r] = (ncr(n - 1, r) + ncr(n - 1, r - 1)) % MOD; 
}
 
ll solve(ll idx, ll left) {
	if(left < 0) {
		return 0;
	}
	if(idx == v.size()) {
		return (left == 0);
	}
	if(dp[idx][left] != -1) {
		return dp[idx][left];
	}
	ll ans = solve(idx + 1, left);
	for(ll i = 0; i < (v[idx] + 1) / 2; i++) {
		ans = (ans + ncr(v[idx] - i, i + 1) * solve(idx + 1, left - i - 1)) % MOD;
	}
	return dp[idx][left] = ans;
}
 
ll fact[MX];
 
int main(){
	fast_cin();
	// freopen("input.in","r",stdin);
	// freopen("output.out","w",stdout);
	memset(dp, -1, sizeof(dp));
	memset(choose, -1, sizeof(choose));
	cin >> n >> m;
	fact[0] = 1;
	for(ll i = 1; i < MX; i++) {
		fact[i] = (i * fact[i - 1]) % MOD;
	}
	for(ll i = 1; i <= n; i++) {
		if(seen[i]) continue;
		ll len = 0;
		ll j = i;
		seen[j] = true;
		if(j - m >= 1) {
			len++;
		}
		while(j + m <= n) {
			j += m;
			if(!(((j - i) / m) & 1))
				seen[j] = true;
			len++;
		}
		if(len)
			v.push_back(len);
	}
	ll ans = 0;
	for(ll i = 0; i <= n; i++) {
		if(i & 1) {
			ans = (ans - fact[n - i] * solve(0, i) % MOD + MOD) % MOD;
		}
		else {
			ans = (ans + fact[n - i] * solve(0, i) % MOD + MOD) % MOD;
		}
	}
	cout << ans << endl;
	return 0;
}
 
