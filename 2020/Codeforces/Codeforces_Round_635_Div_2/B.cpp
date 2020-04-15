// B. Kana and Dragon Quest game solution
// Link: https://codeforces.com/contest/1337/problem/B

#include<bits/stdc++.h>
using namespace std;

int t, x, n, m;

int main()
{
	cin >> t;
	while (t--) {
		cin >> x >> n >> m;
		while ((x / 2) + 10 < x && n) {
			x = (x / 2) + 10;
			n--;
		}
		x -= (m * 10);
		if (x <= 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}