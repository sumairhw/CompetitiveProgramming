#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;

const ll mod = 1000000007;

vi primes;
vll primesegment;
void sieve(ll upperbound) {
	ll _sieve_size = upperbound + 1;
	bitset<10000010> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
			for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			primes.push_back((int)i);
		}
}

void segmentedSieve(ll L, ll R) {
	primesegment.resize(0);
	if (L == 1) L++;
	ll maxN = R - L + 1;
	vector<bool> arr(maxN, false);

	for (ll p : primes) if (p * p <= R) {
			ll i = (L / p) * p; if (i < L) i += p;
			for (; i <= R ; i += p)
				if (i != p) arr[i - L] = true;
		}

	for (int i = 0; i < maxN; ++i)
		if (!arr[i]) primesegment.push_back(i + L);

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);

	sieve(sqrt(2147483647));
	ll r, u;
	while (cin >> r >> u) {
		segmentedSieve(r, u);
		ll highd = 0, lowd = 1e12;
		pair<ll, ll> highpair;
		pair<ll, ll>lowpair;
		for (int i = 0; i < primesegment.size(); ++i) if (i + 1 < primesegment.size()) {
				ll d = primesegment[i + 1] -  primesegment[i];
				if (d > highd) {
					highd = d;
					highpair = {primesegment[i], primesegment[i + 1]};
				}
				if (d < lowd) {
					lowd = d;
					lowpair = {primesegment[i], primesegment[i + 1]};
				}
			}

		if (primesegment.size() == 1 || primesegment.size() == 0) cout << "There are no adjacent primes.\n";
		else cout << lowpair.first << "," << lowpair.second << " are closest, " << highpair.first << "," << highpair.second << " are most distant.\n";
	}
	return 0;
}