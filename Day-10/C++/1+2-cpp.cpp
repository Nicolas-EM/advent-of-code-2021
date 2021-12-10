#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

bool equal(const char a, const char b) {
	switch (a){
	case '(':
		return b == ')';
	case '[':
		return b == ']';
	case '{':
		return b == '}';
	case '<':
		return b == '>';
	default:
		cout << "error\n";
		return false;
	}
}

bool closing(const char a) {
	switch (a) {
	case ')':
	case ']':
	case '}':
	case '>':
		return true;
	default:
		return false;
	}
}

int main() {
	ifstream in("Day-10\\input.txt");
	auto cinbuf = cin.rdbuf(in.rdbuf());

	multiset<char> illegalChars;
	vector<long long> scores;
	while (true) {
		vector<char> v;
		string l;
		bool foundIllegal = false;

		cin >> l;

		if (!cin) break;

		for (int i = 0; i < l.length() && !foundIllegal; i++) {
			if (v.size() >= 1) {
				int t = v.back();
				if (closing(l[i])) {
					if (equal(t, l[i])) v.pop_back();
					else {
						illegalChars.insert(l[i]);
						foundIllegal = true;
					}
				}
				else v.push_back(l[i]);
			}
			else v.push_back(l[i]);
		}

		long long completionScore = 0;
		if (!foundIllegal) {
			for (int i = v.size() - 1; i >= 0; i--) {
				completionScore *= 5;
				switch (v[i]) {
				case '(':
					completionScore += 1;
					break;
				case '[':
					completionScore += 2;
					break;
				case '{':
					completionScore += 3;
					break;
				case '<':
					completionScore += 4;
					break;
				default:
					break;
				}
			}
			scores.push_back(completionScore);
		}

	}

	cout << ") - " << illegalChars.count(')') << "\n] - " << illegalChars.count(']') << "\n} - " << illegalChars.count('}') << "\n> - " << illegalChars.count('>') << "\n";
	int points = (3 * illegalChars.count(')')) + (57 * illegalChars.count(']')) + (1197 * illegalChars.count('}')) + (25137 * illegalChars.count('>'));
	cout << "Illegal points: " << points << "\n";

	sort(scores.begin(), scores.end());
	cout << "Completion points: " << scores[scores.size() / 2] << "\n";
}