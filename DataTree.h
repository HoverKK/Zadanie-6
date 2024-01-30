#ifndef DATATREE_H
#define DATATREE_H

#include <map>
#include <vector>
#include <functional>
#include "DataPoint.h"
class DataTree {
public:
    std::map<int, std::map<int, std::map<int, std::map<int, std::vector<DataPoint>>>>> tree;
    void addDataPoint(const DataPoint& dataPoint);
    void parseDateTime(const std::string& dateTime, int& year, int& month, int& day, int& quarter);
    int getQuarter(int hour, int minute);
    double sumAutokonsumpcja(const std::string& startDateTime, const std::string& endDateTime);
    double sumEksport(const std::string& startDateTime, const std::string& endDateTime);
    double sumImport(const std::string& startDateTime, const std::string& endDateTime);
    double sumPobor(const std::string& startDateTime, const std::string& endDateTime);
    double sumProdukcja(const std::string& startDateTime, const std::string& endDateTime);
    void processTimeRange(const std::string& startDateTime, const std::string& endDateTime, const std::function<void(const DataPoint&)>& func);
};
#endif