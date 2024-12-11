#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <locale>

using namespace std;

void newMatrix(int**& a, int m, int n)
{
    a = new int* [m];
    for (int i = 0; i < m; i++)
        a[i] = new int[n];
}

void fillMatrix(int** a, const int M, const int N)
{
    int x;
    cout << "Заполните матрицу: " << endl;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> x;
            a[i][j] = x;
        }
}

void randomMatrix(int** a, const int M, const int N)
{
    srand(time(NULL));
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            a[i][j] = rand() % 9;
}

void printMatrix(int** a, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

bool isSymmetricMainDiagonal(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (matrix[i][j] != matrix[j][i])
                return false;
    return true;
}

bool isSymmetricSecondaryDiagonal(int** matrix, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (matrix[i][j] != matrix[n - 1 - j][n - 1 - i])
                return false;
    return true;
}

void func1()
{
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    int** matrix;
    newMatrix(matrix, n, n);
    fillMatrix(matrix, n, n);

    cout << "Матрица:" << endl;
    printMatrix(matrix, n, n);

    if (isSymmetricMainDiagonal(matrix, n))
        cout << "Матрица симметрична относительно главной диагонали" << endl;
    else
        cout << "Матрица не симметрична относительно главной диагонали" << endl;

    if (isSymmetricSecondaryDiagonal(matrix, n))
        cout << "Матрица симметрична относительно побочной диагонали" << endl;
    else
        cout << "Матрица не симметрична относительно побочной диагонали" << endl;
}

void func2()
{
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    int** matrix;
    newMatrix(matrix, n, n);
    randomMatrix(matrix, n, n);

    cout << "Матрица:" << endl;
    printMatrix(matrix, n, n);

    int maxElem = matrix[0][1];
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (matrix[i][j] > maxElem)
                maxElem = matrix[i][j];

    int minElem = matrix[1][0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (matrix[i][j] < minElem)
                minElem = matrix[i][j];

    cout << "Максимальный элемент выше главной диагонали: " << maxElem << endl;
    cout << "Минимальный элемент ниже главной диагонали: " << minElem << endl;
}

void func3()
{
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    int** matrix;
    newMatrix(matrix, n, n);
    randomMatrix(matrix, n, n);

    cout << "Матрица:" << endl;
    printMatrix(matrix, n, n);

    int sum = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i + j < n - 1)
                sum += matrix[i][j];

    int maxElem = matrix[1][n - 1];
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i + j > n - 1)
                if (matrix[i][j] > maxElem)
                    maxElem = matrix[i][j];

    cout << "Сумма элементов выше побочной диагонали: " << sum << endl;
    cout << "Максимальный элемент ниже побочной диагонали: " << maxElem << endl;
}

void func4()
{
    int n, m;
    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> n >> m;

    int** matrix;
    newMatrix(matrix, n, m);
    fillMatrix(matrix, n, m);

    cout << "Матрица:" << endl;
    printMatrix(matrix, n, m);

    int maxSum = 0;

    for (int i = 0; i < n; i++) {
        int currentSum = 0;
        for (int j = 0; j < m; j++) {
            currentSum += matrix[i][j];
        }
        if (i == 0 || currentSum > maxSum) {
            maxSum = currentSum;
        }
    }
    cout << "Максимальная сумма элементов строки матрицы: " << maxSum << endl;
}

void func11()
{
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    int** A;
    newMatrix(A, n, n);
    randomMatrix(A, n, n);

    int** B;
    newMatrix(B, n, n);
    fillMatrix(B, n, n);

    int** C;
    newMatrix(C, n, n);

    cout << "Матрица A:" << endl;
    printMatrix(A, n, n);
    cout << endl;

    cout << "Матрица B:" << endl;
    printMatrix(B, n, n);
    cout << endl;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            C[i][j] = 0; 
            for (int k = 0; k < n; k++)
                C[i][j] += A[i][k] * B[k][j];
        }

    cout << "Результат умножения матриц A и B (матрица C):" << endl;
    printMatrix(C, n, n);
}

void func15()
{
    int n;
    cout << "Введите размер матрицы: ";
    cin >> n;

    int** matrix;
    int** rotatedMatrix;
    newMatrix(matrix, n, n);
    randomMatrix(matrix, n, n);

    cout << "Матрица:" << endl;
    printMatrix(matrix, n, n);

    newMatrix(rotatedMatrix, n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            rotatedMatrix[j][n - 1 - i] = matrix[i][j];

    cout << "Повернутая матрица на 90 градусов по часовой стрелке:" << endl;
    printMatrix(rotatedMatrix, n, n);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    //func1();
    //func2();
    //func3();
    //func4();
    //func11();
    func15();
    return 0;
} 