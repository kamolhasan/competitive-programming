// A. Candies and Two Sisters solution
// Link: https://codeforces.com/contest/1335/problem/A

#include <bits/stdc++.h>
using namespace std;


int t, n, ans;
int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		ans = n / 2;
		if (n % 2 == 0) {
			ans--;
		}
		cout << ans << endl;
	}
}