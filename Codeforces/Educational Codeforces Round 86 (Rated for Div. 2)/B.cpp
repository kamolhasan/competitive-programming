#include <bits/stdc++.h>
using namespace std;

int t, n, len;
string s, ss;
bool f;


bool equal() {
	char ch = s[0];
	for (int i = 1; i < s.size(); i++) {
		if (ch != s[i])return false;
	}
	return true;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> s;
		len = s.size();
		if (equal()) {
			cout << s << endl;
		} else {
			ss = s[0];
			for (int i = 1; i < s.size(); i++) {
				if (s[i] == s[i - 1]) {
					if (s[i] == '0') {
						ss += "10";
					} else {
						ss += "01";
					}
				} else {
					ss += s[i];
				}
			}
			cout << ss << endl;
		}

	}
}