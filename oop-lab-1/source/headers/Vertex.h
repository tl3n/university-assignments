#ifndef LAB1_VERTEX_H
#define LAB1_VERTEX_H

class VertexBase
{
public:
    static inline int numberOfVertices{ 1 };
};

template <typename VertexT>
class Vertex : VertexBase
{
public:
    explicit Vertex(VertexT vertexData)
    {
        m_number = numberOfVertices++;
        m_data = vertexData;
    }

    VertexT getData() { return m_data; }

    void setData(VertexT vertexData) { m_data = vertexData; }

    int getNumber() { return m_number; }

    void setNumber(int vertexNumber) { m_number = vertexNumber; }

private:
    int m_number{};
    VertexT m_data{};
};

#endif