#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const ll mod = 1000000007;
ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound) {
	_sieve_size = upperbound + 1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
			for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back((int)i);
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int n ;
	sieve(1000000);
	while (cin >> n) {
		if (n == 0) break;
		int p2 = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
		int p1 = 0, sum = primes[p1] + primes[p2];
		while (sum != n) {
			if (sum < n) p1++;
			else p2--;
			sum = primes[p1] + primes[p2];
		}
		cout << n << " = " << primes[p1] << " + " << primes[p2] << "\n";
	}
	return 0;
}
