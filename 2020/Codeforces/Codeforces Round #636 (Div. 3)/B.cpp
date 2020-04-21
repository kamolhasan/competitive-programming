// B. Balanced Array solution
// Link: https://codeforces.com/contest/1343/problem/B

#include <bits/stdc++.h>
using namespace std;

int t, n, half, i, j;

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		if ((n / 2) & 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			half = n / 2;
			for ( i = 0, j = 2; i < half; i++, j += 2) {
				cout << j << ' ';
			}
			for ( i = 0, j = 1; i < half - 1; i++, j += 2) {
				cout << j << ' ';
			}
			cout << j + half << endl;
		}
	}
}