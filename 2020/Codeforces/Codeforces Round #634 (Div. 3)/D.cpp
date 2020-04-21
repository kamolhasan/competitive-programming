// D. Anti-Sudoku solution
// Link: https://codeforces.com/contest/1335/problem/D

#include <bits/stdc++.h>
using namespace std;

int t;
char ar[9][9];
int main() {
	cin >> t;
	while (t--) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> ar[i][j];
				if (ar[i][j] == '9') {
					ar[i][j] = '8';
				}
			}
		}
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << ar[i][j];
			}
			cout << endl;
		}
		cout << endl;
	}
}