#ifndef MSSM_H
#define MSSM_H

#include <random>
#include <chrono>
#include <vector>
#include <sstream>

class randomGenerator
{
private:
   std::random_device randDevice;
   std::mt19937 mersenneTwister;
public:
   randomGenerator(int seed = 0); // seed == 0 will use system clock for seed
   int getInt(int minVal, int maxVal);
   double getDouble(double minVal, double maxVal);
};

int randomInt(int minVal, int maxVal);
double randomDouble(double minVal, double maxVal);

template<typename T>
std::string toString(T value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

template<typename T>
std::string toString(std::vector<T> values)
{
    std::string retval;

    retval.append("{");

    if (values.size() > 0) {
        retval.append(toString(values[0]));
        for (unsigned int i = 1; i < values.size(); ++i) {
            retval.append(", ");
            retval.append(toString(values[i]));
        }
    }

    retval.append("}");

    return retval;
}

template<typename T>
void printVector(std::vector<T> values)
{
    std::cout << toString(values) << std::endl;
}


#endif // MSSM_H
