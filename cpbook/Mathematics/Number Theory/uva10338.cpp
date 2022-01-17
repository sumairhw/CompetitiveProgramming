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

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0)->sync_with_stdio(0);
	ll T; cin >> T;
	int tc = 1;
	while (T--) {
		string s; cin >> s;
		vector<int> vc(26, 0);
		unsigned long long ans = 1;
		for (int i = 0; i < s.length() ; ++i) {
			vc[s[i] - 'A']++;
		}
		sort(vc.rbegin(), vc.rend());
		for (int i = s.length(); i > vc[0]; i--) {
			ans *= i;
		}
		for (int i = 1; i < s.length() ; ++i) {
			if (vc[i]) {
				ll fact = 1;
				for (int j = 2; j <= vc[i] ; ++j) fact *= j;
				ans /= fact;
			}
		}
		cout << "Data set " << tc++ << ": " << ans << "\n";
	}
	return 0;
}
