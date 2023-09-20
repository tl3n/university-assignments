#ifndef LAB1_VERTEX_H
#define LAB1_VERTEX_H

template <typename VertexT>
class Vertex
{
public:
    Vertexdata(VertexT vertexdData{})
    {
        m_number = numberOfVertices;
        m_data = vertexData;
        ++numberOfVertices;
    }

    VertexT getData() { return m_data; }

    void setData(VertexT vertexData) { m_data = vertexData; }

    int getNumber() { return m_number; }

    void setNumber(int vertexNumber) { m_number = vertexNumber; }

private:
    static int numberOfVertices{};
    int m_number{};
    VertexT m_data{};
};

#endif LAB1_VERTEX_H