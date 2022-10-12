#pragma once
#include "date.h"
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Database {
public:
	Database() {};
	void Add(const Date& date, const string& event);
	void Print(ostream& out) const;
	string Last(const Date& date) const;

	template <typename Predicate>
	vector<string> FindIf(Predicate predicate) const {
		vector<string> result;
		for (const auto& date : db) {
			for (const auto& event : date.second.data_vector) {
				if (predicate(date.first, event)) {
					string bufer = to_string(date.first.GetYear()) + "-" + to_string(date.first.GetMonth()) + "-" + to_string(date.first.GetDay()) + " " + event;
					result.push_back(bufer);
				}
			}
		}
		return result;
	}

	template <typename Predicate>
	int RemoveIf(Predicate predicate) {
		int count = 0;
		for (auto date = db.begin(); date != db.end(); ) {
			if (predicate(date->first, "")) {
				count += date->second.data_vector.size();
				date = db.erase(date);
			}
			else {
				auto new_predicate = [date, predicate](const string& event) { return !predicate(date->first, event); };
				auto start = stable_partition(date->second.data_vector.begin(), date->second.data_vector.end(), new_predicate);
				if (start == date->second.data_vector.begin()) {
					count += date->second.data_vector.size();
					date = db.erase(date);
				}
				else if (start != date->second.data_vector.end()) {
					for (auto curr = --date->second.data_vector.end(); curr != prev(start); curr--) {
						date->second.data_vector.pop_back();
						date->second.data_set.erase(*curr);
						count++;
					}
					if (date->second.data_vector.empty()) date = db.erase(date);
					else ++date;
				}
				else {
					++date;
				}
			}
		}
		return count;
	}

private:
	struct Events {
		vector<string> data_vector;
		set<string> data_set;
	};
	map<Date, Events> db;
};