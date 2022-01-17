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
	ll T ; cin >> T;
	cin.ignore();
	while (T--) {
		string line; getline(cin, line);
		stringstream ss(line);
		vi vec; int k;
		while (ss >> k) vec.pb(k);

		int ans = 0;
		for (int i = 0; i < vec.size(); i++) {
			for (int j = i + 1; j < vec.size(); j++) {
				ans = max(ans, __gcd(vec[i], vec[j]));
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
