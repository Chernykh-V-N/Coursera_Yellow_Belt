#include "database.h"

using namespace std;

void Database::Add(const Date& date, const std::string& event) {
    auto added = db[date].data_set.insert(event);
    if (added.second)
        db[date].data_vector.push_back(event);
}

void Database::Print(ostream& out) const {
    for (const auto& date : db) {
        for (const auto& event : date.second.data_vector) {
            out << date.first << " " << event << endl;
        }
    }
}


string Database::Last(const Date& date) const {
    auto last = db.upper_bound(date);
    if (last == db.begin()) {
        return "No entries";
    }
    else {
        last = prev(last);

        
            
        return to_string(last->first.GetYear()) + "-" + to_string(last->first.GetMonth()) + "-" + to_string(last->first.GetDay()) + " " + last->second.data_vector.back();
    }
}