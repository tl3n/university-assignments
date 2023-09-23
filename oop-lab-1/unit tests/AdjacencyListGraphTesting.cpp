#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "..\source\headers\AdjacencyListGraph.h"

TEST_CASE("testing addVertex()")
{
    AdjacencyListGraph<int, int> graph;
    
    graph.addVertex(1, 69);
    graph.addVertex(2, 420);
    graph.addVertex(3, 228);
    std::map<int, int> graphVertices = graph.getVertices();

    std::map<int, int> test {{1, 69}, {2, 420}, {3, 228}};
    for (const auto& pair : test)
    {
        REQUIRE(pair.second == graphVertices[pair.first]);
    }
}

TEST_CASE("testing deleteVertex()")
{
    AdjacencyListGraph<int, int> graph;
    
    graph.addVertex(1, 69);
    graph.addVertex(2, 420);
    graph.addVertex(3, 228);
    std::map<int, int> graphVertices = graph.getVertices();

    graph.deleteVertex(2);
    std::map<int, int> test = graph.getVertices();

    REQUIRE(test.size() != graphVertices.size());
}

TEST_CASE("testing addEdge()")
{
    AdjacencyListGraph<int, int> graph;
    
    graph.addVertex(1, 69);
    graph.addVertex(2, 420);
    graph.addVertex(3, 228);

    graph.addEdge(2, 3, 96);
    
    std::map<int, std::vector<std::pair<int, int>>> adjacencyList = graph.getAdjacencyList();
    
    auto it = adjacencyList[2].begin();
    REQUIRE(it->first == 3);
    REQUIRE(it->second == 96);
}

TEST_CASE("testing deleteEdge()")
{
    AdjacencyListGraph<int, int> graph;
    
    graph.addVertex(1, 69);
    graph.addVertex(2, 420);
    graph.addVertex(3, 228);

    graph.addEdge(2, 3, 96);

    std::map<int, std::vector<std::pair<int, int>>> adjacencyList = graph.getAdjacencyList();
    
    graph.deleteEdge(2, 3);
    
    std::map<int, std::vector<std::pair<int, int>>> test = graph.getAdjacencyList();
    
    REQUIRE(adjacencyList[2].size() != test[2].size());
}