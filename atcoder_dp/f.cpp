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

	string s, t; cin >> s >> t;
	s = "0" + s; t = "0" + t;
	vector<vector<int>> subseq(t.length(), vector<int>(s.length(), 0));
	string ans;
	for (int i = 1; i < t.length(); ++i) {
		for (int j = 1; j < s.length(); ++j) {
			if (s[j] == t[i]) subseq[i][j] = subseq[i - 1][j - 1] + 1;
			else subseq[i][j] = max(subseq[i - 1][j], subseq[i][j - 1]);
		}
	}

	int i = t.length() - 1, j = s.length() - 1;
	while (i && j) {
		if (s[j] == t[i]) {
			ans += s[j];
			i--; j--;
		} else if (subseq[i - 1][j] > subseq[i][j - 1]) i--;
		else j--;
	}
	reverse(begin(ans), end(ans));
	cout << ans;
	// cout << subseq[t.length() - 1][s.length() - 1];
	return 0;
}
