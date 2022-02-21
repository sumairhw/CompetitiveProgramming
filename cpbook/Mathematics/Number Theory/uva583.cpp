#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> primeFactorization(ll n) {
	vector<ll> factors;
	if (n < 0) {
		factors.push_back(-1);
		n = -n;
	}

	for (ll i = 2; i * i <= n ; ++i) {
		while (n % i == 0) {
			factors.push_back(i);
			n /= i;
		}
	}
	if (n > 1) factors.push_back(n);
	return factors;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	ll n;
	while (cin >> n) {
		if (n == 0) break;
		vector<ll> factors = primeFactorization(n);
		cout << n << " = ";
		for (int i = 0; i < factors.size(); ++i) {
			cout << factors[i];
			if (i != factors.size() - 1) cout << " x ";
		}
		cout << "\n";
	}
	return 0;
}
