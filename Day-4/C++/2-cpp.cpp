#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> split(const string &s, char delim) {
	vector<int> result;
	stringstream ss(s);
	string item;

	while (getline(ss, item, delim)) {
		result.push_back(stoi(item));
	}

	return result;
}

int score(const int v[5][5]) {
	int s = 0;
	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (v[x][y] != -1) s += v[x][y];
		}
	}
	return s;
}

bool isSolved(const int v[5][5], const int posX, const int posY) {
	bool solved = true;
	for (int x = 0; x < 5; x++) {
		if (v[x][posY] != -1) solved = false;
	}
	if (solved) return true;

	solved = true;
	for (int x = 0; x < 5; x++) {
		if (v[posX][x] != -1) solved = false;
	}
	return solved;
}

int currScore(const vector<int> &nums, int v[5][5], int &minTurns) {
	int i;
	for (i = 0; i < nums.size(); i++) {
		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				if (v[x][y] == nums[i]) {
					v[x][y] = -1;
					if (i >= 5 && isSolved(v, x, y)) {
						if (i > minTurns) {
							minTurns = i;
							return nums[i] * score(v);
						}
						return -1;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	ifstream in("Day-4\\input.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());

	string nums;
	cin >> nums;

	vector<int> n = split(nums, ',');

	int score, numCards = 0, minTurns = 5;
	while (true) {
		int v[5][5];
		int currentScore;

		for (int x = 0; x < 5; x++) {
			for (int y = 0; y < 5; y++) {
				cin >> v[x][y];
			}
		}

		if (!cin) break;

		currentScore = currScore(n, v, minTurns);
		if (currentScore != -1) score = currentScore;
	}

	cout << score << " in " << minTurns << " turns\n";
}