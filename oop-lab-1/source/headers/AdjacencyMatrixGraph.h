#ifndef LAB1_ADJACENCYMATRIXGRAPH_H
#define LAB1_ADJACENCYMATRIXGRAPH_H

#include "Graph.h"

template <typename VertexT, typename EdgeT>
class AdjacencyMatrixGraph : public Graph <VertexT, EdgeT>
{
public:
    explicit AdjacencyMatrixGraph()
    {
    }
    explicit AdjacencyMatrixGraph(std::initializer_list<std::pair<int, VertexT>> vertices)
    {
    }

    ~AdjacencyMatrixGraph() = default;

    virtual void addVertex(int vertexNumber, VertexT vertexData)
    {

    }
    
    virtual void deleteVertex(int vertexNumber)
    {

    }

    virtual void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData)
    {

    }

    virtual void deleteEdge(int firstVertexNumber, int secondVertexNumber)
    {

    }

    virtual bool isWeaklyConnected()
    {

    }

    virtual bool isStronglyConnected()
    {

    }

    virtual int findDistance(int firstVertexNumber, int secondVertexNumber)
    {

    }

    virtual void DepthFirstSearch(int vertexNumber, std::vector<int>& visited)
    {

    }
private:
    std::map<int, VertexT> m_vertices;
    std::map<int, std::map<int, EdgeT>> m_adjacencyMatrix;
}

#endif