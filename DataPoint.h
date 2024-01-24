#ifndef DATAPOINT_H
#define DATAPOINT_H

#include <string>

class DataPoint {
public:
    std::string date_time;
    double autokonsumpcja;
    double eksport;
    double import_;
    double pobor;
    double produkcja;

    DataPoint(std::string date_time, double autokonsumpcja, double eksport, double import_, double pobor, double produkcja);
};