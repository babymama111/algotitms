#include <iostream>
#include <fstream>
#include <vector>

void topologicalSorting(int **ptr_cols,int n, int* buffer, std::vector<int> &order,int vertex);
void outputVector(std::vector<int> &order,int n);
int main(int argc, char *argv[]) {
    int n;
    std::ifstream file("2.txt");
    if (!file.is_open()) {
        std::cout << "Проблема с чтением файлом";
        return 0;
    }

    file >> n;
    
    int **ptr_cols = new int *[n];
    for (int i = 0; i < n; i++) {
        ptr_cols[i] = new int[n];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            file >> ptr_cols[i][j];
        }
    }
    int* buffer = new int[n](); 
    std::vector<int> order;
    std::cout << "Топологический порядок вершин: \n";
    
    for (int vertex = 0; vertex < n; vertex++) {
        if (buffer[vertex] == 0) {
            topologicalSorting(ptr_cols,n, buffer,order,vertex);
        }
    }
    outputVector(order,n);

    for (int i = 0; i < n; i++) {
        delete[] ptr_cols[i];
    }
    delete[] ptr_cols;
    return 0;
}

void topologicalSorting(int **ptr_cols, int n, int* buffer, std::vector<int> &order, int vertex) {
    buffer[vertex] = 1;
    for (int i = 0; i < n; i++) {
        if (ptr_cols[vertex][i] == 1 && buffer[i] == 0) {
            topologicalSorting(ptr_cols, n, buffer, order, i);
        }
    }
    
    order.push_back(vertex + 1);
}
void outputVector(std::vector<int> &order,int n){
    std::cout  <<"\n ";

    for (int i = n-1; i >= 0 ; i-- ) {
        std::cout << order[i]  << " ";
    }
}



//Задача 2. Топологическая сортировка орграфа
//
//В этом задании нам нужно реализовать топологическую сортировку ациклического ориентированного графа
//
//Граф представлен матрицей смежности размерностью N x N - то есть это двумерный массив, содержащий N строчек и N столбцов
//
//N - это количество вершин графа. Все вершины графа пронумерованы - то есть имеют уникальный индекс от 1 до N включительно
//
//Значение находящееся в ячейке матрицы смежности, говорит о наличии или отсутствии связи между вершинами, индексы которых соответствуют номеру строчки и номеру столбца этой ячейки. Если значение в ячейке равно 1, то из вершины, имеющей номер строки ячейки, можно попасть в вершину, имеющую номер столбца ячейки. Если значение равно 0, то из вершины, имеющей номер строки ячейки, нельзя попасть в вершину, имеющую номер столбца ячейки. В ячейках с одинаковыми номерами столбца и строки всегда находится 0
//
//В отличие от неориентированного графа, в матрице смежности ориентированного графа значения в ячейках, находящихся симметрично относительно диагонали матрицы (такие ячейки образуют пары, в этих парах номер строки первой ячейки будет равен номеру столбца второй ячейки, а номер столбца первой ячейки будет равен номеру строки второй ячейки) могут не совпадать - это будет означать, что из одной вершины можно попасть в другую, но не наоборот
//
//Наша задача: имея предоставленную матрицу смежности, произвести топологическую сортировку ориентированного графа и вывести на консоль получившийся порядок вершин
//
//Матрица смежности будет задаваться в текстовом файле в следующем формате: первым числом в файле идёт количество вершин графа (N). Далее располагаются N строчек, каждая из которых содержит N чисел - 1 или 0
//
//На выходе мы должны получить последовательность вершин, находящихся в топологическом порядке. Заметьте, что для одного и того же орграфа может существовать несколько топологических сортировок - в зависимости от того, с какой вершины вы начали обход графа