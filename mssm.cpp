#include <iostream>

#include "mssm.h"

using namespace std;



randomGenerator::randomGenerator(int seed) : mersenneTwister(randDevice())
{
   if (seed)
   {
       mersenneTwister.seed(seed); // fixed seed to get repeatable pseudorandom values for testing
   }
   else
   {
       mersenneTwister.seed((std::chrono::system_clock::now().time_since_epoch()).count());
   }
}

int randomGenerator::getInt(int minVal, int maxVal)
{
   std::uniform_int_distribution<int> dist(minVal, maxVal);
   return dist(mersenneTwister);
}

double randomGenerator::getDouble(double minVal, double maxVal)
{
   std::uniform_real_distribution<double> dist(minVal, maxVal);
   return dist(mersenneTwister);
}

randomGenerator rnd;

int randomInt(int minVal, int maxVal)
{
    return rnd.getInt(minVal, maxVal);
}

double randomDouble(double minVal, double maxVal)
{
    return rnd.getDouble(minVal, maxVal);
}
