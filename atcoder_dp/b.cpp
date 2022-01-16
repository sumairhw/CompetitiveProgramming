#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

const ll MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll n, k; cin >> n >> k;
	vi arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	vi dp(n, INT_MAX);
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= i + k; ++j) {
			if (j < n) dp[j] = min(dp[i] + abs(arr[i] - arr[j]), dp[j]);
		}
	}
	cout << dp[n - 1] ;
	return 0;
}
