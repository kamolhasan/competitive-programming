// A. Little Artem solution
// Link: https://codeforces.com/contest/1333/problem/A

#include <bits/stdc++.h>
using namespace std;

int t, m, n;

int main() {
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1) {
					cout << "W";
				} else {
					cout << "B";
				}
			}
			cout << endl;
		}
	}
}