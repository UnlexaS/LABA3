// Laba_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <locale.h>
using namespace std;

class matrix {
private:

    int N;
    int M;
    double** array;

public:

    matrix() {
        this->N = 0;
        this->M = 0;
        array = new double* [N];
        for (int i = 0; i < N; i++)
            array[i] = new double[M];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
            {
                array[i][j] = 0;
            }
    }

    matrix(double** elements, int n, int m) {
        cout << "Инициализация" << endl;
        N = n; M = m;
        this->array = new double* [this->N];
        for (int i = 0; i < N; i++)
            this->array[i] = new double[this->M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                this->array[i][j] = elements[i][j];
        }
    }

    matrix(const matrix& other) {
        this->N = other.N;
        this->M = other.M;

        this->array = new double* [other.N];
        for (int i = 0; i < N; i++)
            this->array[i] = new double[other.M];

        for (int i = 0; i < other.N; i++) {
            for (int j = 0; j < other.M; j++) {
                this->array[i][j] = other.array[i][j];
            }
        }
        cout << "Вызвался конструктор копирования" << endl;
    }

    matrix operator +(const matrix& sum) {
        cout << "Перегрузка оператором +" << endl;
        matrix temp;

        temp.array = new double* [N];
        for (int i = 0; i < N; i++)
            temp.array[i] = new double[M];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                temp.array[i][j] = this->array[i][j] + sum.array[i][j];
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++)
                cout << temp.array[i][j] << " ";
            cout << endl;
        }

        return temp;
    }



    ~matrix() {
    delete[] array;
    }

    //double& operator [][](const int index1,const int index2) {
    //    cout << "Перегрузка индексации" << endl;
    //    return array[index1][index2];
    //};

    friend ostream& operator<<(ostream& out, const matrix& Matrix);
    friend void Print(matrix& prin);

};

void Print(matrix& prin) {
    cout << endl << "Функция Print:" << endl;
    for (int i = 0; i < prin.N; i++) {
        for (int j = 0; j < prin.M; j++) 
            cout << prin.array[i][j] << " ";
        cout << endl;
    }
}

ostream& operator<<(ostream& out, const matrix& Matrix)
{
    for (int i = 0; i < Matrix.N; i++)
    {
        for (int j = 0; j < Matrix.M; j++)
        {
            out << Matrix.array[i][j] << " ";
        }
        out << endl;
    }
    return out;
}


int main()
{
    setlocale(LC_ALL,"Russian");

    matrix matr[3];

    double** elements;
    int n; int m;
    cout << "Введите размеры матрицы: ";
    cout << endl << "N = "; cin >> n; cout << "M = "; cin >> m;
    elements = new double* [n];
    for (int i = 0; i < n; i++)
        elements[i] = new double[m];
    int k = 0;
    for (k = 0; k < 3; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "Введите элемент [" << i << "][" << j << "] = ";
                cin >> elements[i][j];
            }
        }
        //matrix E(elements, n, m);
        matr[k] = { elements, n, m };
    }

    for (int k = 0; k < 3; k++)
    cout << matr[k] << endl;
    system("pause");

    matrix sum;
    int m1 = 0, m2 = 0;
    cout << "Выберите матрицы для сложения: "; cin >> m1 >> m2;
    if (m1 >= 0 && m1 < k && m2 >= 0 && m2 < k) {
        sum = matr[m1] + matr[m2];
        cout << sum << endl;
    }
    system("pause");
    
    



    //int index1 = 0, index2 = 0;
    //cout << "Введите индекс: "; cin >> index1;  cin >> index2; 
    //cout << matr.array[index1][index2];




    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
