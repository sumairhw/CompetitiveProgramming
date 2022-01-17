#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vll = vector<ll>;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define PI 3.1415926535897932384626
#define MOD 1000000007

vi primes;
vii primepairs;
void sieve(ll upperbound) {
	ll _sieve_size = upperbound + 1;
	bitset<10000010> bs;
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
			for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
			if (primes.size() && primes[primes.size() - 1] == (int)i - 2) primepairs.pb({i - 2, i});
			primes.push_back((int)i);
		}
}

void segmentedSieve(ll L, ll R) {
	if (L == 1) L++;
	ll maxN = R - L + 1;
	vector<bool> arr(maxN, false);

	for (ll p : primes) if (p * p <= R) {
			ll i = (L / p) * p; if (i < L) i += p;
			for (; i <= R ; i += p)
				if (i != p) arr[i - L] = true;
		}

	for (int i = 0; i < maxN; ++i)
		if (i + 2 < maxN && !arr[i] && !arr[i + 2]) {
			primepairs.pb({i + L, i + L + 2});
		}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	sieve(10000000);
	segmentedSieve(10000000, 20000000);
	ll n ;
	while (cin >> n) {
		cout << "(" << primepairs[n - 1].fi << ", " << primepairs[n - 1].se << ")\n";
	}
	return 0;
}
