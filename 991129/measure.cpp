


/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <991129>

  This file contains the implementation of the Measure class. Measure is a
  very simple class that needs to contain a few member variables for its name,
  codename, and a Standard Library container for data. The data you need to
  store is values, organised by year. I'd recommend storing the values as
  doubles.

  This file contains numerous functions you must implement. Each function you
  must implement has a TODO block comment.
*/

#include <stdexcept>
#include <string>
#include <cmath>
#include "measure.h"

/*
  TODO: Measure::Measure(codename, label);

  Construct a single Measure, that has values across many years.

  All StatsWales JSON files have a codename for measures. You should convert
  all codenames to lowercase.

  @param codename
    The codename for the measure

  @param label
    Human-readable (i.e. nice/explanatory) label for the measure

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);
*/
Measure::Measure(std::string codename, const std::string &label) : code(codename),
                                                                   label(label),
                                                                   readings(std::map<unsigned int, double>()) {
    //throw std::logic_error("Measure::Measure() has not been implemented!");
}

/*
  TODO: Measure::getCodename()

  Retrieve the code for the Measure. This function should be callable from a
  constant context and must promise to not modify the state of the instance or
  throw an exception.

  @return
    The codename for the Measure

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    ...
    auto codename2 = measure.getCodename();
*/
const std::string &Measure::getCodename() const {
    return code;
}

/*
  TODO: Measure::getLabel()

  Retrieve the human-friendly label for the Measure. This function should be
  callable from a constant context and must promise to not modify the state of
  the instance and to not throw an exception.

  @return
    The human-friendly label for the Measure

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    ...
    auto label = measure.getLabel();
*/
const std::string &Measure::getLabel() const {
    return this->label;
}

/*
  TODO: Measure::setLabel(label)

  Change the label for the Measure.

  @param label
    The new label for the Measure

  @example
    Measure measure("pop", "Population");
    measure.setValue(1999, 12345678.9);
    ...
    measure.setLabel("New Population");
*/
void Measure::setLabel(const std::string &label) {
    this->label = label;
}

/*
  TODO: Measure::getValue(key)

  Retrieve a Measure's value for a given year.

  @param key
    The year to find the value for

  @return
    The value stored for the given year

  @throws
    std::out_of_range if year does not exist in Measure with the message
    No value found for year <year>

  @return
    The value

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    ...
    auto value = measure.getValue(1999); // returns 12345678.9
*/
double& Measure::getValue(unsigned int key) const {
    if (this->readings.find(key) == this->readings.end()) {
        throw std::out_of_range("No value found matching " + key);
    }
    std::map<unsigned int, double> values = this->getReadings();
    return values.at(key);
}

const std::map<unsigned int, double> &Measure::getReadings() const {
    return readings;
}

void Measure::setReadings(const std::map<unsigned int, double> &readings) {
    Measure::readings = readings;
}

const std::string &Measure::getCode() const {
    return code;
}


/*
  TODO: Measure::setValue(key, value)

  Add a particular year's value to the Measure object. If a value already
  exists for the year, replace it.

  @param key
    The year to insert a value at

  @param value
    The value for the given year

  @return
    void

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
*/
void Measure::setValue(unsigned int key, double value) {
    // if the key isn't found then insert as a new key:
    if (this->getReadings().find(key) == this->getReadings().end()) {
        this->readings.insert({key, value});
    } else {
        //erase the current key and then update with new one.
        this->readings.erase(key);
        this->readings.insert({key, value});
    }
}


/*
  TODO: Measure::size()

  Retrieve the number of years data we have for this measure. This function
  should be callable from a constant context and must promise to not change
  the state of the instance or throw an exception.

  @return
    The size of the measure

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    auto size = measure.size(); // returns 1
*/
//get the reading map size.
unsigned int Measure::size() const {
    return this->getReadings().size();
}


/*
  TODO: Measure::getDifference()

  Calculate the difference between the first and last year imported. This
  function should be callable from a constant context and must promise to not
  change the state of the instance or throw an exception.

  @return
    The difference/change in value from the first to the last year, or 0 if it
    cannot be calculated

  @example
    Measure measure("pop", "Population");
    measure.setValue(1999, 12345678.9);
    measure.setValue(1999, 12345679.9);
    auto diff = measure.getDifference(); // returns 1.0
*/
double Measure::getDifference() const {
    // if the map is empty - then we cannot get a difference as there is nothing to get a
    // difference of
    if (this->getReadings().empty()) {
        return 0.0;
    } else {
        double first = this->getReadings().begin()->second;

        double second = std::prev(this->getReadings().end())->second;
        double diff = (first - second);
        if (diff < 0) { // we want the absolute difference so don't let it get -ve.
            return second - first;
        } else {
            return diff;
        }
    }
}


/*
  TODO: Measure::getDifferenceAsPercentage()

  Calculate the difference between the first and last year imported as a
  percentage. This function should be callable from a constant context and
  must promise to not change the state of the instance or throw an exception.

  @return
    The difference/change in value from the first to the last year as a decminal
    value, or 0 if it cannot be calculated

  @example
    Measure measure("pop", "Population");
    measure.setValue(1990, 12345678.9);
    measure.setValue(2010, 12345679.9);
    auto diff = measure.getDifferenceAsPercentage();
*/
double Measure::getDifferenceAsPercentage(){
    double difference = this->getDifference();
    return difference*100;

}


/*
  TODO: Measure::getAverage()

  Calculate the average/mean value for all the values. This function should be
  callable from a constant context and must promise to not change the state of
  the instance or throw an exception.

  @return
    The average value for all the years, or 0 if it cannot be calculated

  @example
    Measure measure("pop", "Population");
    measure.setValue(1999, 12345678.9);
    measure.setValue(1999, 12345679.9);
    auto diff = measure.getDifference(); // returns 1
*/
double Measure::getAverage() const{
    if(this->getReadings().size()==0){
        return 0;
    }
    double total =0;
    for(auto const& x : this->getReadings()){
        total += x.second;
    }
    return total/this->getReadings().size();

}

Measure::~Measure() {

}



const std::map<unsigned int, double> Measure::getReadings() {
    return std::map<unsigned int, double>();
}

/*
  TODO: operator<<(os, measure)

  Overload the << operator to print all of the Measure's imported data.

  We align the year and value outputs by padding the outputs with spaces,
  i.e. the year and values should be right-aligned to each other so they
  can be read as a table of numerical values.

  Years should be printed in chronological order. Three additional columns
  should be included at the end of the output, correspodning to the average
  value across the years, the difference between the first and last year,
  and the percentage difference between the first and last year.

  If there is no data in this measure, print the name and code, and
  on the next line print: <no data>

  See the coursework specification for more information.

  @param os
    The output stream to write to

  @param measure
    The Measure to write to the output stream

  @return
    Reference to the output stream

  @example
    std::string codename = "Pop";
    std::string label = "Population";
    Measure measure(codename, label);

    measure.setValue(1999, 12345678.9);
    std::cout << measure << std::end;
*/
//reference: https://riptutorial.com/cplusplus/example/7878/map-iterator 25/03/2021 00:00
std::ostream &operator<<(std::ostream &os, const Measure &measure) {
    for(auto it = measure.readings.begin(); it!= measure.readings.end(); ++it){
        os << "code: " << measure.code << " label: " << measure.label << " readings: " << it->first << it->second;
    }
    return os;
}

/*
  TODO: operator==(lhs, rhs)

  Overload the == operator for two Measure objects. Two Measure objects
  are only equal when their codename, label and data are all equal.

  @param lhs
    A Measure object

  @param rhs
    A second Measure object

  @return
    true if both Measure objects have the same codename, label and data; false
    otherwise
*/
bool operator==(const Measure &lhs, const Measure &rhs) {
    return (lhs.code == rhs.code &&
            lhs.label == rhs.label &&
            lhs.readings == rhs.readings);
}



