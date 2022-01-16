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
	for (int i = 1; ; ++i) {
		ll r, n;
		cin >> r >> n;
		if (r == 0 && n == 0) break;
		if (n * 27 < r) cout << "Case " << i << ": " << "impossible\n";
		else if (n >= r)cout << "Case " << i << ": " << 0 << "\n";
		else if (r % n == 0)cout << "Case " << i << ": " << r / n - 1 << "\n";
		else cout << "Case " << i << ": " << r / n << "\n";
	}
	return 0;
}
