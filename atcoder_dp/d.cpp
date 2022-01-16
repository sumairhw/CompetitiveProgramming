#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll mod = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n, capacity; cin >> n >> capacity;
	vi weights(n + 1), values(n + 1);
	for (int i = 1; i <= n; ++i) cin >> weights[i] >> values[i];

	vector<vector<ll>> knapsack(n + 1, vector<ll>(capacity + 1, 0));
	for (ll i = 1; i <= n; ++i) {
		for (ll j = 0; j <= capacity ; ++j) {
			if (j < weights[i]) knapsack[i][j] = knapsack[i - 1][j];
			else knapsack[i][j] = max(knapsack[i - 1][j], values[i] + knapsack[i - 1][j - weights[i]]);
		}
	}
	cout << knapsack[n][capacity];
	return 0;
}
