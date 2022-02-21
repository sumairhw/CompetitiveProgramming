#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, ll> mfactors;
void factorization(ll n) {
	mfactors.clear();
	for (int i = 2; i * i <= n ; ++i) {
		while (n % i == 0) {
			mfactors[i]++;
			n /= i;
		}
	}
	if (n > 1) mfactors.insert({n, 1});
}

int main() {
	cin.tie(0); ios::sync_with_stdio(0);
	ll n, m ;
	while (cin >> n >> m) {

		factorization(m);
		bool ans = true;
		for (auto it = mfactors.begin(); it != mfactors.end() ; ++it) {
			ll f = it->first;
			ll p = 1;
			ll counter = 0;
			while (true) {
				if (pow(f, p) > n) break;
				counter += n / pow(f, p);
				p++;
			}
			if (counter < it->second) {
				ans = false;
				break;
			}
		}

		if (ans) cout << m << " divides " << n << "!\n";
		else cout << m << " does not divide " << n << "!\n";
	}
	return 0;
}
