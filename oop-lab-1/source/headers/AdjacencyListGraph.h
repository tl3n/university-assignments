#ifndef LAB1_ADJACENCYLISTGRAPH_H
#define LAB1_ADJACENCYLISTGRAPH_H

#include "Graph.h"

// Шаблон класу для використання різних типів даних
template <typename VertexT, typename EdgeT>
class AdjacencyListGraph : public Graph<VertexT, EdgeT>
{
public:
    // Стандарнний конструктор
    explicit AdjacencyListGraph() : Graph<VertexT, EdgeT>() {}

    // Конструктор із списком ініціалізації для додавання вершин
    explicit AdjacencyListGraph(std::initializer_list<std::pair<int, VertexT>> vertices) : Graph<VertexT, EdgeT>(vertices) {}

    // Стандартний деструктор
    ~AdjacencyListGraph() = default;

    // Додавання вершини до графу
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

    // Вилучення вершини з графу
    void deleteVertex(int vertexNumber) override
    {
        if (this->m_vertices.find(vertexNumber) != this->m_vertices.end())
        {
            this->m_vertices.erase(vertexNumber);
            
            // Вилучення інцидентних до вершини ребер з списку суміжності
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

    // Додавання ребра до списку суміжності
    void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData) override
    {
       if (this->m_vertices.find(firstVertexNumber) != this->m_vertices.end() && this->m_vertices.find(secondVertexNumber) != this->m_vertices.end())
       {
            m_adjacencyList[firstVertexNumber].emplace_back(secondVertexNumber, edgeData);
       }
       else
       {
            std::cout << "CAN NOT ADD SUCH AN EDGE\n";
       }
    }

    // Видалення ребра зі списку суміжності
    void deleteEdge(int firstVertexNumber, int secondVertexNumber) override
    {
        if (this->m_vertices.find(firstVertexNumber) != this->m_vertices.end() && this->m_vertices.find(secondVertexNumber) != this->m_vertices.end())
        {
            auto& edges = m_adjacencyList[firstVertexNumber];
            auto it = edges.begin();
            std::advance(it, secondVertexNumber - 1);
            edges.erase(it);
        }
        else
        {
            std::cout << "CAN NOT FIND SUCH AN EDGE\n";
        }
    }   

    // Пошук у глибину для графа, відмічає відвідані вершини
    void DepthFirstSearch(int vertexNumber, std::vector<int>& visited) override
    {
        visited.emplace_back(vertexNumber);

        for (auto& edges: m_adjacencyList[vertexNumber])
        {
            int adjacent = edges.first;
            if (std::find(visited.begin(), visited.end(), adjacent) == visited.end())
            {
                DepthFirstSearch(adjacent, visited);
            }
        }
    }

    // Отримання транспонованого графа
    // Транспонований граф - орієнтований граф, де змінена орієнтація ребер
    AdjacencyListGraph<VertexT, EdgeT>* getTransposed()
    {
        AdjacencyListGraph* transposed = new AdjacencyListGraph{};
        
        // Копіюємо вершини
        for (auto& vertex : this->m_vertices)
        {   
            int vertexNumber = vertex.first;
            VertexT vertexData = vertex.second;

            transposed->addVertex(vertexNumber, vertexData);
        }

        // Копіюємо ребра зі зміненою орієнтацією до списку суміжності
        for (auto& edges: m_adjacencyList)
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

    // Перевірка на слабку зв'язність
    // Слабка зв'язність - при заміні всіх орієнтованих ребер на неорієнтовані граф є зв'язним
    bool isWeaklyConnected() override
    {
        AdjacencyListGraph<VertexT, EdgeT>* transposed = getTransposed();
        
        return this->isConnected() || transposed->isConnected();
    }

    // Знаходження відстані від однієї вершини до іншої
    int findDistance(int firstVertexNumber, int secondVertexNumber) override
    {
        // Використовуємо пошук у ширину графа
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

            for (auto& edge: m_adjacencyList[currentVertex])
            {
                int adjacent = edge.first;
                if (std::find(visited.begin(), visited.end(), adjacent) == visited.end())
                {
                    visited.push_back(adjacent);
                    queue.push(adjacent);
                    
                    // Заносимо відстань до кожної вершини
                    distance[adjacent] = distance[currentVertex] + 1;
                }
            }
        }

        // Якшо до заданої вершини є шлях, то повертаємо відстань до неї
        if (distance.find(secondVertexNumber) != distance.end())
        {
            return distance[secondVertexNumber];
        }

        return 0;
    }

    // Геттер списку суміжності
    std::map<int, std::list<std::pair<int, EdgeT>>> getAdjacencyList()
    {
        return m_adjacencyList;
    }

private:
    // Список суміжності
    std::map<int, std::list<std::pair<int, EdgeT>>> m_adjacencyList;
};

#endif