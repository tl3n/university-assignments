#ifndef LAB1_ADJACENCYLISTGRAPH_H
#define LAB1_ADJACENCYLISTGRAPH_H

#include "Graph.h"

template <typename VertexT, typename EdgeT>
class AdjacencyListGraph : public Graph<VertexT, EdgeT>
{
public:
    explicit AdjacencyListGraph() : Graph<VertexT, EdgeT>()
    {
    }

    explicit AdjacencyListGraph(std::initializer_list<std::pair<int, VertexT>> vertices) : Graph<VertexT, EdgeT>(vertices)
    {
        for (const auto& vertex : vertices)
        {
            m_vertices[vertex.first] = vertex.second;
        }
    }

    ~AdjacencyListGraph() = default;

    void addVertex(int vertexNumber, VertexT vertexData) override
    {
        if (m_vertices.find(vertexNumber) == m_vertices.end() && vertexNumber >= 0)
        {
            m_vertices[vertexNumber] = vertexData;
        }
        else
        {
            std::cout << "CAN NOT ADD THIS VERTEX\n";
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

    bool isConnected()
    {
        typename std::map<int, VertexT>::iterator it = m_vertices.begin();

        if (it != m_vertices.end())
        {
            std::vector<int> visited;
            DepthFirstSearch(it->first, visited);

            if (visited.size() != m_vertices.size())
            {
                return false;
            }
        }

        return true;
    }

    bool isWeaklyConnected() override
    {
        AdjacencyListGraph<VertexT, EdgeT>* transposed = getTransposed();
        
        return isConnected() || transposed->isConnected();
    }

    bool isStronglyConnected() override
    {
        for (auto& vertex : m_vertices)
        {
            std::vector<int> visited;
            DepthFirstSearch(vertex.first, visited);

            if (visited.size() != m_vertices.size())
            {
                return false;
            }
        }

        return true;
    }

    int findDistance(int firstVertexNumber, int secondVertexNumber) override
    {
        // BFS
        std::map<int, int> distance;
        distance[firstVertexNumber] = 0;

        std::vector<int> visited;
        visited.push_back(firstVertexNumber);

        std::queue<int> queue;
        queue.push(firstVertexNumber);

        while (!queue.empty())
        {
            firstVertexNumber = queue.front();
            queue.pop();

            for (auto& adjacent: m_adjacencyList[firstVertexNumber])
            {
                bool found = false;
                for (auto& vertex : visited)
                {
                    if (vertex == adjacent.first)
                    {
                        found = true;
                    }
                }

                if (!found)
                {
                    visited.push_back(adjacent.first);
                    queue.push(adjacent.first);

                    distance[firstVertexNumber] = distance[firstVertexNumber] + 1;
                }

                /*if (!visited[adjacent.first])
                {
                    visited[adjacent.first] = true;
                    queue.push(adjacent.first);

                    distance[adjacent.first] = distance[firstVertexNumber] + 1;
                }*/
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

    void DepthFirstSearch(int vertexNumber, std::vector<int>& visited) override
    {
        visited.emplace_back(vertexNumber);

        for (auto& adjacent: m_adjacencyList[vertexNumber])
        {   
            bool found = false;
            for (auto& vertex : visited)
            {
                if (vertex == adjacent.first)
                {
                    found = true;
                }
            }

            if (!found)
            {
                DepthFirstSearch(adjacent.first, visited);
            }
        }
    }

    AdjacencyListGraph<VertexT, EdgeT>* getTransposed()
    {
        AdjacencyListGraph* transposed = new AdjacencyListGraph{};
        for (auto& vertex : m_vertices)
        {
            transposed->m_vertices[vertex.first] = vertex.second; 
        }

        for (auto& adjacent: m_adjacencyList)
        {
            for (auto& edge : adjacent.second)
            {
                transposed->m_adjacencyList[edge.first].emplace_back(adjacent.first, edge.second);
            }
        }
    
        return transposed;
    }

    std::map<int, VertexT>& getVertices()
    { 
        return m_vertices; 
    }
    std::map<int, std::vector<std::pair<int, EdgeT>>>& getAdjacencyList()
    { 
        return m_adjacencyList;
    }

private:
    std::map<int, VertexT> m_vertices;
    std::map<int, std::vector<std::pair<int, EdgeT>>> m_adjacencyList;
};

#endif