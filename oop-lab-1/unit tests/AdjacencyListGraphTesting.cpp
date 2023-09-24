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

TEST_CASE("testing isWeaklyConnected()")
{
    AdjacencyListGraph<int, int> notWeaklyConnected;
    
    notWeaklyConnected.addVertex(1, 69);
    notWeaklyConnected.addVertex(2, 420);
    notWeaklyConnected.addVertex(3, 228);

    notWeaklyConnected.addEdge(2, 3, 96);

    REQUIRE(!notWeaklyConnected.isWeaklyConnected());

    AdjacencyListGraph<int, int> weaklyConnected;

    weaklyConnected.addVertex(1, 69);
    weaklyConnected.addVertex(2, 420);
    weaklyConnected.addVertex(3, 228);

    weaklyConnected.addEdge(1, 2, 96);
    weaklyConnected.addEdge(2, 3, 96);

    REQUIRE(weaklyConnected.isWeaklyConnected());

}

TEST_CASE("testing isStronglyConnected()")
{
    AdjacencyListGraph<int, int> notStronglyConnected;
    
    notStronglyConnected.addVertex(1, 69);
    notStronglyConnected.addVertex(2, 420);
    notStronglyConnected.addVertex(3, 228);

    notStronglyConnected.addEdge(1, 2, 1984);
    notStronglyConnected.addEdge(2, 3, 96);

    REQUIRE(!notStronglyConnected.isStronglyConnected());

    AdjacencyListGraph<int, int> stronglyConnected;

    stronglyConnected.addVertex(1, 69);
    stronglyConnected.addVertex(2, 420);
    stronglyConnected.addVertex(3, 228);

    stronglyConnected.addEdge(1, 2, 96);
    stronglyConnected.addEdge(2, 3, 42);
    stronglyConnected.addEdge(3, 1, 1984);

    REQUIRE(stronglyConnected.isStronglyConnected());
}

TEST_CASE("testing findDistance()")
{
    AdjacencyListGraph<int, int> graph;
    
    graph.addVertex(1, 69);
    graph.addVertex(2, 420);
    graph.addVertex(3, 228);
    graph.addVertex(4, 1984);
    graph.addVertex(5, 42);

    graph.addEdge(1, 2, 1);
    graph.addEdge(2, 3, 2);
    graph.addEdge(2, 5, 2);
    graph.addEdge(3, 4, 3);
    graph.addEdge(4, 5, 4);

    REQUIRE(graph.findDistance(1, 2) == 1);
    REQUIRE(graph.findDistance(1, 4) == 3);
    REQUIRE(graph.findDistance(4, 3) == 0);
}