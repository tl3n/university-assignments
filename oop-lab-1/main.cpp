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
}
   