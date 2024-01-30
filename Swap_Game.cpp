#include <bits/stdc++.h>
using namespace std;

unordered_set<string> visited;

// Defined globally to be used in process_swap
queue<pair<string, int>> q;
int moves;
string curboard;

// Processing swapping the numbers in x, y positions
void process_swap(int x, int y) {
	swap(curboard[x], curboard[y]);
	// Check whether already visited this potential board
	if (visited.find(curboard) == visited.end()) {
		q.push({curboard, moves + 1});
		visited.insert(curboard);
	}
	// Restore to original board
	swap(curboard[x], curboard[y]);
}

int main() {
	string inp;
	// Rewriting the input as a string
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		inp += to_string(a - 1);
	}

	q.push({inp, 0});
	while (!q.empty()) {
		tie(curboard, moves) = q.front();
		q.pop();
		if (curboard == "012345678") {
			cout << moves << endl;
			return 0;
		}

		// Horizontal swaps
		for (int i = 0; i < 9; i += 3) {
			process_swap(i, i + 1);
			process_swap(i + 1, i + 2);
		}
		// Vertical swaps
		for (int i = 0; i < 3; i++) {
			process_swap(i, i + 3);
			process_swap(i + 3, i + 6);
		}
	}
}