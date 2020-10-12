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
    int* ms;
    int x;

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
        this->x = 1;
        this->ms = new int[x];
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
       // this->x = kol;
       //ms = new int[x];
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


    //double* operator[](int index)
    //{
    //    cout << "Перезрузка []" << endl;
    //    
    //    return array[index];
    //    cout << endl << "-----------" << endl;
    //}

    void setmas(int kol, int* mas) {
        this->x = kol;
        for (int i = 0; i < kol; i++) {
            this->ms[i] = mas[i];
        }
    }


    int& operator[](int index)
    {
        cout << "Перегрузка []" << endl;
        return ms[index];
    }



    //double* operator [](const int index) {
    //    cout << "Перегрузка индексации" << endl;

    //    for (int f = 0; f < 2; f++) {
    //        if (index == f)
    //            cout << "[]" << array[index] << "[]";
    //            return array[index];
    //    }
    //    
    //}



    ~matrix() {
    delete[] array;
    }


    
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
    cout << endl << "N = ";
    bool a1 = true;
    do
    {
        cin >> n;
        if (cin.fail())
            cout << "Повторите попытку" << endl;
        else
            a1 = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (a1);
    cout << "M = "; 
    bool a2 = true;
    do
    {
        cin >> m;
        if (cin.fail())
            cout << "Повторите попытку" << endl;
        else
            a2 = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (a2);
    elements = new double* [n];
    for (int i = 0; i < n; i++)
        elements[i] = new double[m];
    int k = 0;
    for (k = 0; k < 3; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << "Введите элемент [" << i << "][" << j << "] = ";
                bool a = true;
                do
                {
                    cin >> elements[i][j];
                    if (cin.fail())
                        cout << "Повторите попытку" << endl;
                    else
                        a = false;
                    cin.clear();
                    cin.ignore(cin.rdbuf()->in_avail());
                } while (a);
            }
        }
        matr[k] = { elements, n, m };
    }


    for (int k = 0; k < 3; k++)
    cout << matr[k] << endl;
    system("pause");

    matrix sum;
    int m1 = 0, m2 = 0;
    cout << "Выберите матрицы для сложения: ";
    bool a3 = true;
    do
    {
        cin >> m1;
        if (cin.fail())
            cout << "Повторите попытку" << endl;
        else
            a3 = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (a3);
    bool a4 = true;
    do
    {
        cin >> m2;
        if (cin.fail())
            cout << "Повторите попытку" << endl;
        else
            a4 = false;
        cin.clear();
        cin.ignore(cin.rdbuf()->in_avail());
    } while (a4);
    if (m1 >= 0 && m1 < k && m2 >= 0 && m2 < k) {
        sum = matr[m1] + matr[m2];
        cout << sum << endl;
    }
    system("pause");
    

    matrix s;
    int* mas;
    int kol;
    cout << "Введите кол-во элементов" << endl;
    cin >> kol;

    mas = new int[kol];

    for (int z = 0; z < kol; z++)
    {
        cout << "Элемент [" << z << "]" << endl;
        cin >> mas[z];
    }
    s.setmas(kol,mas);
    int d = 0;
    cout << "Введите индекс для перегрузки";
    cin >> d;
    cout << s[d];
    
    
    
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
