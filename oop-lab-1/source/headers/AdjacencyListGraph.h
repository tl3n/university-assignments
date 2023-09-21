#ifndef LAB1_ADJACENCYLISTGRAPH_H
#define LAB1_ADJACENCYLISTGRAPH_H

#include "Graph.h"

template <typename VertexT, typename EdgeT>
class AdjacencyListGraph : public Graph<VertexT, EdgeT>
{
public:
    AdjacencyListGraph(std::initializer_list<std::pair<int, VertexT>> vertices) : Graph<VertexT, EdgeT>(vertices)    
    {}

    void addVertex(int vertexNumber, VertexT vertexData) override
    {
        m_vertices[vertexNumber] = vertexData;
    }

    void deleteVertex(int vertexNumber) override
    {
        if (m_vertices.find(vertexNumber) != m_vertices.end())
        {
            m_vertices.erase(vertexNumber);
            m_adjacencyList.erase(vertexNumber);

            for (auto& vertex : m_adjacencyList)
            {
                auto& edges = vertex.second;
                edges.erase(std::remove_if(edges.begin(), edges.end(), [vertexNumber](auto& edge) { return edge.first == vertexNumber; }), edges.end());
            }
        }
    }

    void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData) override
    {
       if (m_vertices.find(firstVertexNumber) != m_vertices.end() && m_vertices.find(secondVertexNumber) != m_vertices.end())
       {
            m_adjacencyList[firstVertexNumber].emplace_back(secondVertexNumber, edgeData);
       }
    }

    void deleteEdge(int firstVertexNumber, int secondVertexNumber) override
    {

    }

    bool isConnected() override
    {
        return true;
    }

    int findDistance(int firstVertexNumber, int secondVertexNumber) override
    {
        return 0;
    }

    void printGraph()
    {
        for (auto& x : m_adjacencyList)
        {
            std::cout << x.first << ": ";
            auto edges = x.second;
            for (auto& y : edges)
            {
                std::cout << y.first << '.' << y.second << ", ";
            }
            std::cout << '\n';
        }
    }
private:
    std::map<int, VertexT> m_vertices;
    std::map<int, std::vector<std::pair<int, EdgeT>>> m_adjacencyList;
};

#endif