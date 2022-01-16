#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n; cin >> n;
	vi arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	vector<ll> dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j : {i + 1, i + 2}) {
			dp[j] = min(dp[i] + abs(arr[i] - arr[j]), dp[j]);
		}
	}
	cout << dp[n - 1];
	return 0;
}
