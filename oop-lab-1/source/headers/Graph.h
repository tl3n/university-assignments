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

    // Перевірка на слабку зв'язність
    virtual bool isWeaklyConnected() = 0;

    // Перевірка на сильну зв'язність
    virtual bool isStronglyConnected() = 0;

    // Знаходження відстані між двома вершинами
    virtual int findDistance(int firstVertexNumber, int secondVertexNumber) = 0;

    // DFS обхід графа
    virtual void DepthFirstSearch(int vertexNumber, std::vector<int>& visited) = 0;

protected:
    std::map<int, VertexT> m_vertices;
};   

#endif