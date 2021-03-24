#ifndef MEASURE_H_
#define MEASURE_H_

/*
  +---------------------------------------+
  | BETH YW? WELSH GOVERNMENT DATA PARSER |
  +---------------------------------------+

  AUTHOR: <991129>

  This file contains the decalaration of the Measure class.

  TODO: Read the block comments with TODO in measure.cpp to know which
  functions and member variables you need to declare in this class.
 */

#include <string>
#include <map>
#include <ostream>

/*
  The Measure class contains a measure code, label, and a container for readings
  from across a number of years.

  TODO: Based on your implementation, there may be additional constructors
  or functions you implement here, and perhaps additional operators you may wish
  to overload.
*/
class Measure {
    std::string code;
    std::string label;
    std::map<unsigned int, double> readings;


public:
    Measure(std::string code, const std::string &label);
    const std::string &getCodename() const;

    void setCodename(const std::string &code);
    void setLabel(const std::string& label);
    const std::string &getLabel() const;

    const std::string &getCode() const;

    const std::map<unsigned int, double> &getReadings() const;
    const std::map<unsigned int, double> getReadings();
    void setReadings(const std::map<unsigned int, double> &readings);
    unsigned int size() const;
    double getValue(unsigned int key) const;
    double getDifference() const;
    void setValue(unsigned int key, double value);
    double getDifferenceAsPercentage();
    double getAverage() const;
    ~Measure();

    friend bool operator==(const Measure &lhs,  const Measure &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Measure &measure);


};

#endif // MEASURE_H_