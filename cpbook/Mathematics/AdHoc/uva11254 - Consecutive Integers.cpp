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
	ll number;
	while (cin >> number) {
		if (number == -1) return 0;
		ll sum = number;
		ll a = number;
		ll n = sqrt(2 * number);
		for (n ; n > 0 ; n--) {
			if ((2 * sum - (n * n) + n ) % (2 * n) == 0) {
				a = (2 * sum - (n * n) + n ) / (2 * n);
				break;
			}
		}
		cout << number << " = " << a << " + ... + " << a + n - 1 << "\n";
	}
	return 0;
}
