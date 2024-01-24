#include "DataPoint.h"

DataPoint::DataPoint(std::string date_time, double autokonsumpcja, double eksport, double import_, double pobor, double produkcja)
    : date_time(date_time), autokonsumpcja(autokonsumpcja), eksport(eksport), import_(import_), pobor(pobor), produkcja(produkcja) {}
