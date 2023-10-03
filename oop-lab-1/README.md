# Лабораторна робота № 1

## Завдання:
### Список 1: структури даних та алгоритми.
#### 7. (****) Графи на основі списку суміжності, матриці суміжності (збереження даних у вершинах та ребрах графів). Додавання та видалення вершин/ребер. Перевірка на зв'язність графу. Визначення відстані між двома вершинами графу.
- Графи на основі списку суміжності, матриці суміжності.
Реалізовано базовий `class Graph` та підкласи `class AdjacencyListGraph` та `class AdjacencyMatrixGraph`
- Збереження даних у вершинах та ребрах.
Збереження даних у вершинах реалізовано за допомогою std::map<int, VertexT> у базовому `class Graph`. Збереження даних у ребрах реалізовано за допомогою використання відповідних пар <int, EdgeT> у структурах суміжності.
- Додавання вершин `void addVertex(int vertexNumber, VertexT vertexData)`, видалення вершин `void deleteVertex(int vertexNumber)`.
- Додавання ребер `void addEdge(int firstVertexNumber, int secondVertexNumber, EdgeT edgeData)`, видалення ребер `void deleteEdge(int firstVertexNumber, int secondVertexNumber)`.
- Перевірка на зв'язність графу.
Одностороння зв'зність `bool isConnected()`, слабка зв'язність `bool isWeaklyConnected()`, сильна зв'язність `bool isStronglyConnected()`.
- Визначення відстані між двома вершинами графу `int findDistance(int firstVertexNumber, int secondsVertexNumber)`

##### +* за інші алгоритми на графах
- Додано транспонування графу `Graph<VertexT, EdgeT>* getTransposed().`
- Додано пошук у глибину графа `void DepthFirstSearch(int vertexNumber, std::vector<int>& visited)`.

### Список 2: класи для опису даних.
#### 9. (**) Інформація про дату (рік, місяць, день) та час (години, хвилини, секунди). Перевірка правильності дати та часу відповідно до григоріанського календаря. Арифметика моментів часу: різниця між двома моментами часу у заданих одиницях, додавання чи віднімання такої різниці до заданого моменту часу. Обчислення дня тижня для заданої дати.
- Інформація про дату (рік, місяць, день) та час (години, хвилини, секунди) реалізовано за допомогою `class DateTime`
- Перевірка правильності дати та часу відповідно до григоріаньского календаря `bool isValid(std::tm timeData)`
- Різниця між двома моментами часу у заданих одиницях. `long long int secondsDifference(DateTime& other)`, `long long int minutesDifference(DateTime& other)`, `long long int hoursDifference(DateTime& other)`, `long int daysDifference(DateTime& other)`, `int monthsDifference(DateTime& other)`, `int yearsDifference(DateTime& other)`.
- Додавання чи віднімання такої різниці до заданого моменту часу. `void increaseBy(int years, int months, int days, int hours, int minutes, int seconds)`, `void decreaseBy(int years, int months, int days, int hours, int minutes, int seconds)`.
- Обчислення дня тижня. `int getDayOfWeek()`

#### ЗАГАЛЬНА КІЛЬКІСТЬ КЛАСІВ - 4
#### ЗАГАЛЬНА КІЛЬКІСТЬ НЕТРИВІАЛЬНИХ МЕТОДІВ - 37
#### ЗАГАЛЬНА КІЛЬКІСТЬ ЗІРОЧОК - 7
#### ДОДАТКОВО РЕАЛІЗОВАНО UNIT TESTS (<doctest.h>)

#### Made by Texas Red