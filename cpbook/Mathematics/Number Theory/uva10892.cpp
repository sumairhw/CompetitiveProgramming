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
#define all(a) begin(a),end(a)

vi factors;
void factorization(ll n) {
	factors.clear();
	for (int i = 1; i * i <= n ; ++i) if (n % i == 0) {
			factors.pb(i);
			if (i != n / i) factors.pb(n / i);
		}
}

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	ll n ;
	while (cin >> n) {
		if (n == 0) break;
		factorization(n);
		int count = 0;

		for (int i = 0; i < factors.size(); ++i) {
			for (int j = i; j < factors.size(); ++j) {
				if (lcm(factors[i], factors[j]) == n) count++;
			}
		}

		cout << n << " " << count << "\n";
	}
	return 0;
}
