#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

const ll mod = 1000000007;

vector<bool> is_prime(1000001, true);
vector <ll> primes;

void Sieve() {
	ll n = 1000000;
	is_prime[0] = is_prime[1] = false;

	for (ll i = 2; i * i <= n; i++) {
		if (is_prime[i]) {
			primes.push_back(i);
			for (ll j = i * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll testcases;
	cin >> testcases;
	Sieve();
	while (testcases--) {
		ll L, H;
		cin >> L >> H;
		pair<ll, ll> p(L, 1);

		for (ll i = L; i <= H ; ++i) {
			ll n = i; ll cnt = 1;

			std::map<ll, ll> mp;
			for (long long d : primes) {
				if (d * d > n) break;
				while (n % d == 0) {
					if (mp.find(d) == mp.end()) mp[d] = 1;
					else mp[d]++;
					n /= d;
				}
			}
			if (n > 1) mp[n] = 1;
			for (auto it = mp.begin(); it != mp.end() ; ++it) {
				cnt *= it->second + 1;
			}

			if (cnt > p.second) p = {i, cnt};
		}
		cout << "Between " << L << " and " << H << ", " << p.first << " has a maximum of " << p.second << " divisors.\n";
	}

	return 0;
}
