#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll mod = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n, k;
	while (cin >> n >> k) {
		ll ans = n;
		ll rem = n;
		while (rem >= k) {
			n = rem / k;
			ans += n;
			rem -= n * k;
			rem += n;
		}
		cout << ans << "\n";
	}
	return 0;
}
