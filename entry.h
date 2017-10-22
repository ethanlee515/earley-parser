#ifndef _ENTRY_H
#define _ENTRY_H

#include <string>
#include "rule.h"

struct entry {
	const int begin;
	const rule r;
	const int dot;
	const double weight;
	entry(int, rule, int, double);
	operator std::string() const;
	std::string index() const;
	friend std::ostream& operator<<(std::ostream& o, entry e);
	bool operator==(const entry& other) const;
	std::string nextItem() const;
};

namespace std {
	template<>
	struct hash<entry> {
		std::size_t operator()(const entry& e) const {
			std::string str = (std::string) e;
			return std::hash<std::string>()(str);
		}
	};
}

#endif
