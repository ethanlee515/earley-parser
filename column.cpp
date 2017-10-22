#include "column.h"
#include <stdexcept>
#include <tuple>
#include <utility>
#include "entry.h"
#include <map>
#include <memory>
#include <sstream>
#include <iostream>

using std::string;
using std::shared_ptr;
using std::runtime_error;
using std::make_pair;
using std::tuple;
using std::get;
using std::map;
using std::stringstream;
using std::endl;
using std::make_tuple;
using std::make_shared;
using std::ostream;

void column::insert(shared_ptr<entry> e) {
	entries.push_back(e);
	toAttach.insert(make_pair(e->nextItem(), e));
}

shared_ptr<entry> column::next() {
	return entries.at(loc++);
}

bool column::hasNext() {
	return loc < entries.size();
}

column::operator string() const {
	stringstream ss;
	for(shared_ptr<entry> e : entries) {
		ss << *e << endl;
	}
	return ss.str();
}

void column::combine(shared_ptr<entry> finished, shared_ptr<entry> past) {
	double newWeight = past->weight + finished->weight;
	shared_ptr<entry> newEntry = make_shared<entry>(past->begin, past->r, past->dot + 1, newWeight);
	
	string index = newEntry->index();

	auto it = backPtrs.find(index);

	if(it == backPtrs.end() || newWeight < (get<0>((*it).second))->weight) {
		backPtrs[index] = make_tuple(newEntry, finished, past);
		pending.insert(make_pair(newWeight, newEntry));
	}

}

void column::moveMin() {
	if(pending.size() == 0)
		throw runtime_error("col.pending is empty");
	auto it = pending.begin();
	shared_ptr<entry> e = (*it).second;
	pending.erase(it);

	if(*e == *(get<0>(backPtrs[e->index()])))
		insert(e);
}

ostream& operator<<(ostream& o, column& c) {
	return o << (string) c;
}

