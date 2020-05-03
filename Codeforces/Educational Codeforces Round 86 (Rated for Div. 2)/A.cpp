#include <bits/stdc++.h>
using namespace std;

long long t, ans, mn, n, a, b, x, y;

int main() {
	cin >> t;
	while (t--) {
		cin >> x >> y;
		cin >> a >> b;
		ans = 0;
		if (2 * a > b) {
			mn = min(x, y);
			ans += (mn * b);
			x -= mn;
			y -= mn;
		}

		if (x) {
			ans += (a * x);
		}
		if (y) {
			ans += (a * y);
		}

		cout << ans << endl;
	}
}