// B. Construct the String solution
// Link: https://codeforces.com/contest/1335/problem/B

#include <bits/stdc++.h>
using namespace std;


int main() {
	int t, a, n, b;
	string s;
	cin >> t;
	while (t--) {
		cin >> n >> a >> b;
		s = "";
		while (s.size() < n) {
			for (char ch = 'a'; ch < 'a' + b; ch++) {
				s += ch;
			}
		}

		for (int i = 0; i < n; i++) {
			cout << s[i];
		}
		cout << endl;
	}
}