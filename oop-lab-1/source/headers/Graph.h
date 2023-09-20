#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H

#include <iostream>

template <typename vertexT, typename edgeT>
class Graph
{
public:
    Graph(int numberOfVertices = 1)
    {
        if (numberOfVertices < 1)
        {
            std::cout << "CANNOT CREATE SUCH A GRAPH\n";
        }
        else
        {
            m_numberOfVertices = numberOfVertices;
        }
    }
    // Додавання вершини
    virtual void addVertex(int vertexNumber, vertexT vertexData) = 0;

    // Вилучення вершини
    virtual void deleteVertex(int vertexNumber) = 0; // #TODO: При видаленні деякої вершини, також видаляти всі пов'язані з нею ребра.

    // Додавання ребра
    virtual void addEdge(int firstVertexNumber, int secondVertexNumber, edgeT edgeData) = 0;

    // Вилучення ребра
    virtual void deleteEdge(int firstVertexNumber, int secondVertexNumber) = 0;

    // Перевірка на зв'язність
    virtual bool isConnected() = 0;

    // Знаходження відстані між двома вершинами
    virtual int findDistance(int firstVertexNumber, int secondVertexNumber) = 0;

protected:
    int m_numberOfVertices{};
};   

#endif