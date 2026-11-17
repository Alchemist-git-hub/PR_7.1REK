#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int** C, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j);

void Print(int** C, const int rowCount, const int colCount,
    int i, int j);

void Sort(int** C, const int rowCount, const int colCount,
    int pass, int j);

void Change(int** C, const int row1, const int row2,
    const int colCount, int j);

void Sum(int** C, const int rowCount, const int colCount,
    int& S, int& k, int i, int j);

void DeleteMatrix(int** C, const int rowCount, int i);

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const int Low = -21;
    const int High = 18;

    const int rowCount = 8;
    const int colCount = 7;

    int** C = new int* [rowCount];

    for (int i = 0; i < rowCount; i++)
        C[i] = new int[colCount];

    Create(C, rowCount, colCount, Low, High, 0, 0);

    cout << "Original matrix C:";
    Print(C, rowCount, colCount, 0, 0);

    Sort(C, rowCount, colCount, 0, 0);

    cout << "Sorted matrix C:";
    Print(C, rowCount, colCount, 0, 0);

    int S = 0;
    int k = 0;

    Sum(C, rowCount, colCount, S, k, 0, 0);

    cout << "Sum S = " << S << endl;
    cout << "Count k = " << k << endl;

    cout << "Modified matrix C:";
    Print(C, rowCount, colCount, 0, 0);
    DeleteMatrix(C, rowCount, 0);
    delete[] C;

    return 0;
}
void Create(int** C, const int rowCount, const int colCount,
    const int Low, const int High, int i, int j)
{
    C[i][j] = Low + rand() % (High - Low + 1);

    if (j < colCount - 1)
        Create(C, rowCount, colCount, Low, High, i, j + 1);
    else if (i < rowCount - 1)
        Create(C, rowCount, colCount, Low, High, i + 1, 0);
}
void Print(int** C, const int rowCount, const int colCount,
    int i, int j)
{
    cout << setw(5) << C[i][j];

    if (j < colCount - 1)
        Print(C, rowCount, colCount, i, j + 1);
    else
    {
        cout << endl;

        if (i < rowCount - 1)
            Print(C, rowCount, colCount, i + 1, 0);
        else
            cout << endl;
    }
}
void Sort(int** C, const int rowCount, const int colCount,
    int pass, int j)
{
    if (pass >= rowCount - 1)
        return;

    if (j >= rowCount - pass - 1)
    {
        Sort(C, rowCount, colCount, pass + 1, 0);
        return;
    }

    if ((C[j][0] < C[j + 1][0]) ||

        (C[j][0] == C[j + 1][0] &&
            C[j][1] < C[j + 1][1]) ||

        (C[j][0] == C[j + 1][0] &&
            C[j][1] == C[j + 1][1] &&
            C[j][3] > C[j + 1][3]))
    {
        Change(C, j, j + 1, colCount, 0);
    }

    Sort(C, rowCount, colCount, pass, j + 1);
}
void Change(int** C, const int row1, const int row2,
    const int colCount, int j)
{
    int tmp = C[row1][j];

    C[row1][j] = C[row2][j];
    C[row2][j] = tmp;

    if (j < colCount - 1)
        Change(C, row1, row2, colCount, j + 1);
}
void Sum(int** C, const int rowCount, const int colCount,
    int& S, int& k, int i, int j)
{
    if (C[i][j] % 2 == 0 || C[i][j] <= 0)
    {
        S += C[i][j];
        k++;
        C[i][j] = 0;
    }

    if (j < colCount - 1)
        Sum(C, rowCount, colCount, S, k, i, j + 1);
    else if (i < rowCount - 1)
        Sum(C, rowCount, colCount, S, k, i + 1, 0);
}
// Рекурсивне звільнення пам'яті
void DeleteMatrix(int** C, const int rowCount, int i)
{
    delete[] C[i];

    if (i < rowCount - 1)
        DeleteMatrix(C, rowCount, i + 1);
}
