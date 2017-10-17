#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include "parser.h"

using std::cout;
using std::endl;
using std::make_unique;
using std::make_shared;
using std::unique_ptr;
using std::shared_ptr;
using std::ifstream;
using std::getline;
using std::string;

int main(int argc, char** argv) {
	if(argc != 3) {
		cout << "usage: parse x.gr x.sen" << endl;
		return 1;
	}
	unique_ptr<parser> p = make_unique<parser>(argv[1]);
	ifstream file(argv[2]);
	string line;
	getline(file, line);
	while(file.good()) {
		if(line != "")
			cout << p->parse(line) << endl;
		getline(file, line);
	}
	return 0;
}

