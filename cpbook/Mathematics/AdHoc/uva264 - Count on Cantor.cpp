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
	ll number ;
	while (cin >> number) {
		ll sum = 0; ll d = 0;
		while (sum < number) {
			sum += ++d;
		}
		if (sum == number) {
			if (d % 2 == 0) cout << "TERM " << number << " IS " << d << "/" << 1 << "\n";
			else cout << "TERM " << number << " IS " << 1 << "/" << d << "\n";
		} else {
			ll num = 1; ll denom = 1;
			sum -= d; sum++;
			if (d % 2 == 0) {
				num = 1; denom = d;
				while (sum < number) {
					sum++; denom--; num++;
				}
			} else {
				num = d; denom = 1;
				while (sum < number) {
					sum++; denom++; num--;
				}
			}
			cout << "TERM " << number << " IS " << num << "/" << denom << "\n";
		}
	}
	return 0;
}
