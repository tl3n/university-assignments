#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H

#include <iostream>
#include <initializer_list>
#include <map>

template <typename VertexT, typename EdgeT>
class Graph
{
public:
    Graph(std::initializer_list<std::pair<int, VertexT>> vertices)
    {
        for (const auto& pair : vertices)
        {
            m_vertices[pair.first] = pair.second;
        }
    }
    // Додавання вершини
    virtual void addVertex(int vertexNumber, VertexT vertexData) = 0;

    // Вилучення вершини
    virtual void deleteVertex(int vertexNumber) = 0; // #TODO: При видаленні деякої вершини, також видаляти всі пов'язані з нею ребра.

    // Додавання ребра
    virtual void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData) = 0;

    // Вилучення ребра
    virtual void deleteEdge(int firstVertexNumber, int secondVertexNumber) = 0;

    // Перевірка на зв'язність
    virtual bool isConnected() = 0;

    // Знаходження відстані між двома вершинами
    virtual int findDistance(int firstVertexNumber, int secondVertexNumber) = 0;
protected:
    std::map<int, VertexT> m_vertices;
};   

#endif