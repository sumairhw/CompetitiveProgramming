#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll mod = 1000000007;

void solve();
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		ld d, v, u;
		cin >> d >> v >> u;

		/*	    /|
			 u / | v
			  /__|
		*/

		if (v >= u || u == 0 || v == 0) cout << "Case " << i << ": " << "can't determine\n";
		else {
			ld t1 = d / u;
			ld t2 = d / sqrt(u * u - v * v);
			cout << "Case " << i << ": " << std::fixed << setprecision(3) << t2 - t1 << "\n";
		}
	}
	return 0;
}
