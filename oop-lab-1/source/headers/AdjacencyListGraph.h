#ifndef LAB1_ADJACENCYLISTGRAPH_H
#define LAB1_ADJACENCYLISTGRAPH_H

#include "Graph.h"

template <typename VertexT, typename EdgeT>
class AdjacencyListGraph : public Graph<VertexT, EdgeT>
{
public:
    AdjacencyListGraph(std::initializer_list<std::pair<int, VertexT>> vertices) : Graph<VertexT, EdgeT>(vertices)
    {
        for (const auto& pair : vertices)
        {
            m_vertices[pair.first] = pair.second;
        }
    }

    void addVertex(int vertexNumber, VertexT vertexData) override
    {
        if (m_vertices.find(vertexNumber) == m_vertices.end())
        {
            m_vertices[vertexNumber] = vertexData;
        }
        else
        {
            std::cout << "THERE IS ALREADY A VERTEX WITH SUCH NUMBER\n";
        }
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
        else
        {
            std::cout << "THERE IS NO VERTEX WITH SUCH A NUMBER\n";
        }
    }

    void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData) override
    {
       if (m_vertices.find(firstVertexNumber) != m_vertices.end() && m_vertices.find(secondVertexNumber) != m_vertices.end())
       {
            m_adjacencyList[firstVertexNumber].emplace_back(secondVertexNumber, edgeData);
       }
       else
       {
            std::cout << "CAN NOT ADD SUCH AN EDGE\n";
       }
    }

    void deleteEdge(int firstVertexNumber, int secondVertexNumber) override
    {
        if (m_vertices.find(firstVertexNumber) != m_vertices.end() && m_vertices.find(secondVertexNumber) != m_vertices.end())
        {
            auto& edges = m_adjacencyList[firstVertexNumber];
            edges.erase(edges.begin() + secondVertexNumber - 1);
        }
        else
        {
            std::cout << "CAN NOT FIND SUCH AN EDGE\n";
        }
    }   

    bool isWeaklyConnected() override
    {
        return true;
    }

    bool isStronglyConnected() override
    {
        for (auto& vertex : m_vertices)
        {
            std::vector visited(m_vertices.size(), false);
            DepthFirstSearch(vertex.first, visited);

            for (int i = 0; i < visited.size(); ++i)
            {
                if (!visited[i])
                {
                    return false;
                }
            }
        }
        
        return true;
    }

    int findDistance(int firstVertexNumber, int secondVertexNumber) override
    {
        // BFS
        std::vector<int> distance(m_vertices.size(), 0);

        std::vector<bool> visited(m_vertices.size(), false);
        visited[firstVertexNumber] = true;

        std::queue<int> queue;
        queue.push(firstVertexNumber);

        while (!queue.empty())
        {
            firstVertexNumber = queue.front();
            queue.pop();

            for (auto& adjacent: m_adjacencyList[firstVertexNumber])
            {
                if (!visited[adjacent.first])
                {
                    visited[adjacent.first] = true;
                    queue.push(adjacent.first);

                    distance[adjacent.first] = distance[firstVertexNumber] + 1;
                }
            }
        }

        return distance[secondVertexNumber];
    }

    void printGraph()
    {
        for (auto& vertex: m_vertices)
        {
            std::cout << vertex.first << ": ";
            for (auto& adjacent : m_adjacencyList[vertex.first])
            {
                std::cout << adjacent.first << ' ';
            }
            std::cout << '\n';
        }
    }

    void DepthFirstSearch(int vertexNumber, std::vector<bool>& visited) override
    {
        visited[vertexNumber] = true;

        for (auto& adjacent: m_adjacencyList[vertexNumber])
        {
            if (!visited[adjacent.first])
            {
                DepthFirstSearch(adjacent.first, visited);
            }
        }
    }
private:
    std::map<int, VertexT> m_vertices;
    std::map<int, std::vector<std::pair<int, EdgeT>>> m_adjacencyList;
};

#endif