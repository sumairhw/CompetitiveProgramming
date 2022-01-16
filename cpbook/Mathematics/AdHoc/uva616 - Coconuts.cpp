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
	ll n;
	while (cin >> n) {
		if (n < 0) break;
		ll ans = 0;
		for (ll i = 2; i < 10; ++i) {
			ll temp = n;
			ll counter = 0;
			for (ll j = 0; temp && j < i; ++j) {
				temp--;
				if (temp && temp % i != 0) break;
				counter++;
				if (temp) temp = (i - 1) * temp / i;
			}
			if (counter == i && temp % i == 0) ans = max(ans, i);
		}
		cout << n << " coconuts, ";
		if (!ans) cout << "no solution\n";
		else cout << ans << " people and 1 monkey\n";
	}
	return 0;
}
