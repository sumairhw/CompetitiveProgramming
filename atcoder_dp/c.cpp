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

	int days; cin >> days;
	vector<vector<int>> dp(days + 1, vector<int>(3, 0));

	for (int i = 1; i <= days; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		dp[i][0] = a + max(dp[i - 1][1], dp[i - 1][2]);
		dp[i][1] = b + max(dp[i - 1][0], dp[i - 1][2]);
		dp[i][2] = c + max(dp[i - 1][0], dp[i - 1][1]);

	}
	cout << max(dp[days][0], max(dp[days][1], dp[days][2]));
	return 0;
}
