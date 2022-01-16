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
	ll testcases;
	cin >> testcases;
	while (testcases--) {
		ll n;
		cin >> n;
		string anss;
		for (int i = 1; i <= n; ++i) {
			anss += to_string(i);
		}
		for (int i = 0; i < 10; ++i) {
			char k = i + 48;
			cout << count(anss.begin(), anss.end(), k);
			if (i != 9) cout << " ";
		}
		cout << "\n";
	}
	return 0;

}
