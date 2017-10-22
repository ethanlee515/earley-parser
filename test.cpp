#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include "entry.h"
#include "rule.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::unordered_map;

int main() {
	unordered_map<entry, double> testMap;

	vector<string> rhs = {"asdf", "Zxcv"};

	rule r1 = {1.5, "LHS", rhs};
	entry e1 = {5, r1, 2};

	testMap[e1] = 3.5;
	cout << testMap[e1] << endl;

	//cout << (string) e1 << endl;

	return 0;
}
