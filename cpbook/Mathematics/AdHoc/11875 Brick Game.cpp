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
	ll i = 1;
	while (testcases--) {
		ll n;
		cin >> n;
		ll arr[n];
		for (int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		cout << "Case " << i++ << ": " << arr[n / 2] << "\n";
	}
	return 0;
}
