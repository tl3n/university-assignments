#include <iostream>
#include "source/headers/AdjacencyListGraph.h"
#include "source/headers/AdjacencyMatrixGraph.h"
#include "source/headers/DateTime.h"

#define DOCTEST_CONFIG_IMPLEMENT
#include "unit-tests/doctest.h"
#include "unit-tests/AdjacencyListGraphTesting.cpp"
#include "unit-tests/AdjacencyMatrixGraphTesting.cpp"
#include "unit-tests/DateTimeTesting.cpp"

int main(int argc, char** argv)
{
    doctest::Context context;
    int res = context.run();
    if (context.shouldExit())
    {
        return res;
    }

    //DateTime other(2023, 1, 1, 0, 0, 0);
    //DateTime date(2022, 12, 31, 23, 59, 59);

    //other.decreaseBy(0, 0, 0, 0, 0, 1);
    //std::cout << other.getYear() << " " << other.getMonth() << " " << other.getDay() << " " << other.getHour() << " " << other.getMinute() << " " << other.getSecond();
}