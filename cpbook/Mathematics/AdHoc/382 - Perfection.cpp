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
	cout << "PERFECTION OUTPUT\n";
	while (cin >> n) {
		if (n == 0) break;
		ll k = sqrt(n);
		ll sum = 1;
		for (int i = 2; i <= k; ++i) {
			if (n % i == 0) {
				sum += i;
				if (i != n / i) sum += n / i;
			}
		}
		if (n == 1) sum = 0;
		if (sum == n) cout << std::right << setw(5) << n << "  " << "PERFECT\n";
		else if (sum < n) cout << std::right << setw(5) << n << "  " << "DEFICIENT\n";
		else cout << std::right << setw(5) << n << "  " << "ABUNDANT\n";
	}
	cout << "END OF OUTPUT\n";
	return 0;
}
