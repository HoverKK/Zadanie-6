
#include "DataTree.h"
#include <iostream>

void DataTree::addDataPoint(const DataPoint& dataPoint) {
    int year, month, day, quarter;
    parseDateTime(dataPoint.date_time, year, month, day, quarter);
    tree[year][month][day][quarter].push_back(dataPoint);
}

void DataTree::parseDateTime(const std::string& dateTime, int& year, int& month, int& day, int& quarter) {
}

int DataTree::getQuarter(int hour, int minute) {
}

double DataTree::sumAutokonsumpcja(const std::string& startDateTime, const std::string& endDateTime) {
    return 0.0;
}

double DataTree::sumEksport(const std::string& startDateTime, const std::string& endDateTime) {
    return 0.0;
}

double DataTree::sumImport(const std::string& startDateTime, const std::string& endDateTime) {
    return 0.0;
}

double DataTree::sumPobor(const std::string& startDateTime, const std::string& endDateTime) {
    return 0.0;
}

double DataTree::sumProdukcja(const std::string& startDateTime, const std::string& endDateTime) {
    return 0.0;
}

void DataTree::processTimeRange(const std::string& startDateTime, const std::string& endDateTime, const std::function<void(const DataPoint&)>& func) {
}