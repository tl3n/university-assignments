#ifndef LAB1_GRAPH_H
#define LAB1_GRAPH_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <map>
#include <queue>
#include <list>
#include <algorithm>

// Шаблон класу дял представлення загального графа
template <typename VertexT, typename EdgeT>
class Graph
{
public:
    // Стандартний конструктор
    explicit Graph()
    {
    }

    // Конструктор за списком ініціалізації для доавання вершин
    explicit Graph(std::initializer_list<std::pair<int, VertexT>> vertices)
    {
        for (const auto& vertex : vertices)
        {
            m_vertices[vertex.first] = vertex.second;
        }
    }

    // Віртуальний деструктор для можливості поліморфізму
    virtual ~Graph() = default;

    // Додавання вершини до графа (метод має бути реалізований у підкласах)
    virtual void addVertex(int vertexNumber, VertexT vertexData) = 0;

    // Вилучення вершини з графа (метод має бути реалізований у підкласах)
    virtual void deleteVertex(int vertexNumber) = 0;

    // Додавання ребра до графа (метод має бути реалізований у підкласах)
    virtual void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData) = 0;

    // Вилучення ребра з графа (метод має бути реалізований у підкласах)
    virtual void deleteEdge(int firstVertexNumber, int secondVertexNumber) = 0;

     // DFS обхід графа (метод має бути реалізований у підкласах)
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

    // Перевірка на слабку зв'язність (метод має бути реалізований у підкласах)
    // Слабка зв'язність - при заміні всіх орієнтованих ребер на неорієнтовані граф є зв'язним
    virtual bool isWeaklyConnected() = 0;

    // Перевірка на сильну зв'язність
    // Сильна зв'язність - кожна вершина може бути досягнути з іншої
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

    // Знаходження відстані між двома вершинами (метод має бути реалізований у підкласах)
    virtual int findDistance(int firstVertexNumber, int secondVertexNumber) = 0;
    
    virtual std::map<int, VertexT> getVertices()
    { 
        return this->m_vertices; 
    }


protected:
    // Вершини та їх дані
    std::map<int, VertexT> m_vertices;
};   

#endif