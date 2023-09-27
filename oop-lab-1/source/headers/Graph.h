#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

template <typename VertexT, typename EdgeT>
class Graph
{
public:
    explicit Graph()
    {
    }
    explicit Graph(std::initializer_list<std::pair<int, VertexT>> vertices)
    {
        for (const auto& vertex : vertices)
        {
            m_vertices[vertex.first] = vertex.second;
        }
    }

    virtual ~Graph() = default;

    // Додавання вершини
    virtual void addVertex(int vertexNumber, VertexT vertexData) = 0;

    // Вилучення вершини
    virtual void deleteVertex(int vertexNumber) = 0;

    // Додавання ребра
    virtual void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData) = 0;

    // Вилучення ребра
    virtual void deleteEdge(int firstVertexNumber, int secondVertexNumber) = 0;

     // DFS обхід графа
    virtual void DepthFirstSearch(int vertexNumber, std::vector<int>& visited) = 0;

    // Перевірка на зв'язність з першої вершини
    virtual bool isConnected()
    {
        typename std::map<int, VertexT>::iterator it = this->m_vertices.begin();

        if (it != this->m_vertices.end())
        {
            std::vector<int> visited;
            DepthFirstSearch(it->first, visited);

            if (visited.size() != this->m_vertices.size())
            {
                return false;
            }
        }

        return true;
    }

    // Перевірка на слабку зв'язність
    virtual bool isWeaklyConnected() = 0;

    // Перевірка на сильну зв'язність
    virtual bool isStronglyConnected()
    {
        for (auto& vertex : this->m_vertices)
        {
            std::vector<int> visited;
            DepthFirstSearch(vertex.first, visited);

            if (visited.size() != this->m_vertices.size())
            {
                return false;
            }
        }

        return true;
    }

    // Знаходження відстані між двома вершинами
    virtual int findDistance(int firstVertexNumber, int secondVertexNumber) = 0;
    
    virtual std::map<int, VertexT> getVertices()
    { 
        return this->m_vertices; 
    }

protected:
    std::map<int, VertexT> m_vertices;
};   

#endif