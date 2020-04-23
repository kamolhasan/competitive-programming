// A. Candies solution
// Link: https://codeforces.com/contest/1343/problem/A

#include <bits/stdc++.h>
using namespace std;

long long t, n, pre[40], ccum[40];

void preCal() {
	pre[0] = 1;
	for (int i = 1; i < 40; i++) {
		pre[i] = pre[i - 1] * 2;
	}
	ccum[0] = 1;
	for (int i = 1; i < 40; i++) {
		ccum[i] = pre[i] + ccum[i - 1];
	}
}

int main() {
	preCal();

	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i < 40; i++) {
			if (n % ccum[i] == 0) {
				cout << n / ccum[i] << endl;
				break;
			}
		}
	}
}