#include <iostream>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "parser.h"

using std::unordered_map;
using std::cout;
using std::endl;
using std::make_unique;
using std::make_shared;
using std::unique_ptr;
using std::shared_ptr;
using std::ifstream;
using std::getline;
using std::string;
using std::runtime_error;
using std::vector;
using std::stringstream;

int main(int argc, char** argv) {
	if(argc != 3) {
		cout << "usage: parse x.gr x.sen" << endl;
		return 1;
	}

	unique_ptr<parser> p;

	try {
		p = make_unique<parser>(argv[1]);
	} catch (runtime_error& e) {
		cout << "error opening " << argv[1] << endl;
		return 1;
	}
		
	ifstream file(argv[2]);
	if(!file.good()) {
		cout << "error opening " << argv[2] << endl;
		return 1;
	}
	string line;
	getline(file, line);
	while(file.good()) {
		if(line != "" && line != " ") {
			vector<string> sentence;
			stringstream ss(line);
			while(ss.good()) {
				string token;
				ss >> token;
				sentence.push_back(token);
			}

			if(sentence.size() != 0)
				cout << p->parse(sentence) << endl;
		}
		getline(file, line);
	}
	return 0;
}

