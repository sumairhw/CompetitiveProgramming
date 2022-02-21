#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	ll n;
	while (cin >> n && n) {
		if (n < 0) n *= -1;
		ll counter = 0; ll answer = -1;

		for (ll i = 2; i * i <= n; ++i) {
			while (n % i == 0) {
				n /= i;
				answer = i;
			}

			if (answer == i) {
				counter++;
			}
		}

		if (n != 1 && answer != -1) answer = n;
		else if (counter == 1) answer = -1;
		cout << answer << "\n";
	}
	return 0;
}