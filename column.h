#ifndef _COLUMN_H
#define _COLUMN_H

#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include <unordered_set>
#include <set>
#include <map>
#include "entry.h"

struct column {
	int loc = 0;

	//this is the actual column
	std::vector<std::shared_ptr<entry>> entries;

	//Nonterminals being predicted or queued to predict
	std::set<std::string> predicting;

	//For attaches; keys are what's right after the dot
	std::unordered_multimap<std::string, std::shared_ptr<entry>> toAttach;


	std::map<std::string, std::set<int>> marks;

	//start attching from the lowest weight
	std::multimap<double, std::shared_ptr<entry>> pending;
	
	//first slot: the one to attach
	//second slot: the one just finished
	//third slot: the one from the past column
	std::map<std::string, std::tuple<std::shared_ptr<entry>, std::shared_ptr<entry>, std::shared_ptr<entry>>> backPtrs;
	

	void insert(std::shared_ptr<entry> e);
	operator std::string() const;
	bool hasNext();
	std::shared_ptr<entry> next();
	friend std::ostream& operator<<(std::ostream& o, column& c);
	void combine(std::shared_ptr<entry> finished, std::shared_ptr<entry> past); //combines into pending
	void moveMin(); //moves the min element from pending to entries

};


#endif
