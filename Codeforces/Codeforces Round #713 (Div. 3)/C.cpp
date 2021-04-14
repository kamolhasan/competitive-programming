#include <bits/stdc++.h>
using namespace std;


int t, a, b, ca, cb;
string s;


int opposite(int x) {
	return ca + cb - x - 1;
}

bool isPalinedrome() {
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[opposite(i)]) {
			return false;
		}
	}

	if (s.size() & 1 && s[s.size() / 2] == '?') {
		return false;
	}

	return true;
}


int main() {
	cin >> t;
	while (t--) {
		cin >> a >> b;
		ca = a; cb = b;
		cin >> s;


		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '0') a--;
			else if (s[i] == '1')b--;
		}

		for (int j, i = 0; i < (s.size() / 2); i++) {
			j = opposite(i);


			if ((s[i] == '?' || s[j] == '?') && !(s[i] == '?' && s[j] == '?')) {
				if (s[i] == '?') {
					if (s[j] == '0') {
						s[i] = '0';
						a--;
					} else {
						s[i] = '1';
						b--;
					}
				} else {
					if (s[i] == '0') {
						s[j] = '0';
						a--;
					} else {
						s[j] = '1';
						b--;
					}
				}
			}
		}


		for (int j, i = 0; i < s.size() / 2; i++) {
			j = opposite(i);
			if (s[i] == '?' && s[j] == '?') {
				if (a > 1) {
					s[i] = s[j] = '0';
					a -= 2;
				} else if (b > 1) {
					s[i] = s[j] = '1';
					b -= 2;
				}
			}
		}


		if (s.size() & 1 && s[s.size() / 2] == '?') {
			if (a > 0) {
				s[s.size() / 2] = '0'; a--;
			} else if (b > 0) {
				s[s.size() / 2] = '1'; b--;
			}
		}


		if (a==0 && b==0 && isPalinedrome()){
			cout<<s<<endl;
		}else {
			cout<<-1<<endl;
		}

	}


}