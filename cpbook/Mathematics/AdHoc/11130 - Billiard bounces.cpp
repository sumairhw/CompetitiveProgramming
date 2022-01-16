#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

const ll MOD = 1000000007;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin.tie(0);
	ios::sync_with_stdio(0);
	ld a, b, v, A, s;
	const ld pi = acos(-1);
	while (cin >> a >> b >> v >> A >> s) {
		if (!a && !b && !v && !A && !s) break;
		ld len = (v * s) / 2;
		ld y = len * sin(A / 180 * pi);
		ld x = len * cos(A / 180 * pi);
		cout << round(x / a) << " " << round(y / b) << "\n";
	}
	return 0;
}
