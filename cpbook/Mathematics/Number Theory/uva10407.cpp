#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI 3.1415926535897932384626
#define MOD 1000000007
#define all(a) begin(a),end(a)

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	ll n ;
	vll seq;
	while (cin >> n) {
		seq.clear();
		if (n == 0) break;
		seq.pb(n);
		while (cin >> n) {
			if (n == 0) break;
			seq.pb(n - seq[0]);
		}
		ll ans = seq[1];
		for (int i = 2; i < seq.size(); ++i) {
			ans = __gcd(ans, seq[i]);
		}
		if (ans < 0) ans = -ans;
		cout << ans << '\n';
	}
	return 0;
}
