#ifndef LAB1_ADJACENCYMATRIXGRAPH_H
#define LAB1_ADJACENCYMATRIXGRAPH_H

#include "Graph.h"

template <typename VertexT, typename EdgeT>
class AdjacencyMatrixGraph : public Graph <VertexT, EdgeT>
{
public:
    explicit AdjacencyMatrixGraph() {}

    explicit AdjacencyMatrixGraph(std::initializer_list<std::pair<int, VertexT>> vertices) : Graph<VertexT, EdgeT>(vertices) {}

    ~AdjacencyMatrixGraph() = default;

    void addVertex(int vertexNumber, VertexT vertexData) override
    {
        if (this->m_vertices.find(vertexNumber) == this->m_vertices.end() && vertexNumber >= 0)
        {
            this->m_vertices[vertexNumber] = vertexData;
        }
        else
        {
            std::cout << "CAN NOT ADD THIS VERTEX\n";
        }
    }
    
    void deleteVertex(int vertexNumber) override
    {
        if (this->m_vertices.find(vertexNumber) != this->m_vertices.end())
        {
            this->m_vertices.erase(vertexNumber);
            m_adjacencyMatrix[vertexNumber].erase(vertexNumber);
            m_adjacencyMatrix.erase(vertexNumber);
        }
    }

    void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData) override
    {
        if (this->m_vertices.find(firstVertexNumber) != this->m_vertices.end() && this->m_vertices.find(secondVertexNumber) != this->m_vertices.end())
        {
            m_adjacencyMatrix[firstVertexNumber][secondVertexNumber] = edgeData;
        }
        else
        {
            std::cout << "CAN NOT ADD SUCH AN EDGE\n";
        }
    }

    void deleteEdge(int firstVertexNumber, int secondVertexNumber) override
    {
        if (this->m_vertices.find(firstVertexNumber) != this->m_vertices.end() && this->m_vertices.find(secondVertexNumber) != this->m_vertices.end())
        {
            m_adjacencyMatrix[firstVertexNumber].erase(secondVertexNumber);
        }
        else
        {
            std::cout << "CAN NOT FIND SUCH AN EDGE\n";
        }
    }

    void DepthFirstSearch(int vertexNumber, std::vector<int>& visited) override
    {
        visited.emplace_back(vertexNumber);

        for (auto& edges: m_adjacencyMatrix[vertexNumber])
        {
            int adjacent = edges.first;
            if (std::find(visited.begin(), visited.end(), adjacent) == visited.end())
            {
                DepthFirstSearch(adjacent, visited);
            }
        }
    }

    AdjacencyMatrixGraph<VertexT, EdgeT>* getTransposed()
    {
        AdjacencyMatrixGraph* transposed = new AdjacencyMatrixGraph;
        for (auto& vertex : this->m_vertices)
        {
            int vertexNumber = vertex.first;
            VertexT vertexData = vertex.second;

            transposed->addVertex(vertexNumber, vertexData);
        }

        for (auto& edges : m_adjacencyMatrix)
        {
            int adjacent = edges.first;
            for (auto& edge : edges.second)
            {
                int vertexNumber = edge.first;
                EdgeT edgeData = edge.second;

                transposed->addEdge(vertexNumber, adjacent, edgeData);
            }
        }

        return transposed;
    }

    bool isWeaklyConnected() override
    {
        AdjacencyMatrixGraph<VertexT, EdgeT>* transposed = getTransposed();

        return this->isConnected() || transposed->isConnected();
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
            int currentVertex = queue.front();
            queue.pop();

            for (auto& edge: m_adjacencyMatrix[currentVertex])
            {
                int adjacent = edge.first;
                if (std::find(visited.begin(), visited.end(), adjacent) == visited.end())
                {
                    visited.push_back(adjacent);
                    queue.push(adjacent);

                    distance[adjacent] = distance[currentVertex] + 1;
                }
            }
        }

        if (distance.find(secondVertexNumber) != distance.end())
        {
            return distance[secondVertexNumber];
        }

        return 0;
    }

    std::map<int, std::map<int, EdgeT>> getAdjacencyMatrix()
    {
        return m_adjacencyMatrix;
    }
private:
    std::map<int, std::map<int, EdgeT>> m_adjacencyMatrix;
};

#endif