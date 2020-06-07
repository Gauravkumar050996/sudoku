#include <bits/stdc++.h>
using namespace std;
bool checkforcolumn(int arr[9][9], int i, int num)
{
    for (int col = 0; col < 9; col++)
    {
        if (arr[i][col] == num)
            return false;
    } //check for column
    return true;
}
bool checkforrow(int arr[9][9], int j, int num)
{
    for (int row = 0; row < 9; row++)
    {
        if (arr[row][j] == num)
            return false;
    } //check for row
    return true;
}
bool checkforsub_matrix(int arr[9][9], int i, int j, int num)
{
    int si = i / 3;
    si = si * 3;
    int sc = j / 3;
    sc = sc * 3;
    for (int a = si; a < si + 3; a++)
    {
        for (int b = sc; b < sc + 3; b++)
        {
            if (num == arr[a][b])
                return false;
        }
    }
    return true;
}

bool issafe(int arr[9][9], int i, int j, int num)
{

    if (checkforrow(arr, j, num) && checkforcolumn(arr, i, num) && checkforsub_matrix(arr, i, j, num))
        return true;
    else
        return false;
}

void fill(int arr[9][9], int idx)
{
    if (idx == (9 * 9))
    {
        for (int m = 0; m < 9; m++)
        {
            for (int n = 0; n < 9; n++)
            {
                cout << arr[m][n] << ", ";
            }
            cout << endl;
        }
        return;
    }

    int a = idx / 9;
    int b = idx % 9;
    if (arr[a][b] == 0)
    {

        for (int num = 1; num <= 9; num++)
        {
            if (issafe(arr, a, b, num))
            {
                arr[a][b] = num;
                fill(arr, idx + 1);
                arr[a][b] = 0;
            }
        }
    }
    else
    {
        fill(arr, idx + 1);
    }
    return;
}

// bool issafe(int arr[9][9], int i, int j, int num)
// {

//     if (checkforrow(arr, j, num) && checkforcolumn(arr, i, num) && checkforsub_matrix(arr, i, j, num))
//         return true;
//     else
//         return false;
// }

// void fill(int arr[9][9], int i, int j)
// {
//     if (i == 9 && j == 0)
//     {
//         for (int m = 0; m < 9; m++)
//         {
//             for (int n = 0; n < 9; n++)
//             {
//                 cout << arr[m][n] << ", ";
//             }
//             cout << endl;
//         }
//         return;
//     }

//     for (int a = i; a < 9; a++)
//     {
//         for (int b = j; b < 9; b++)
//         {
//             if (arr[a][b] == 0)
//             {

//                 for (int num = 1; num <= 9; num++)
//                 {
//                     if (issafe(arr, a, b, num))
//                     {
//                         arr[a][b] = num;
//                         (b == 8) ? (fill(arr, a + 1, 0)) : fill(arr, a, b + 1);
//                         arr[a][b] = 0;
//                     }
//                 }
//             }
//             else
//             {

//                 (j + 1 == 8) ? (fill(arr, i + 1, 0)) : fill(arr, i, j + 1);
//             }
//         }
//     }
// }

int main()
{
    int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    fill(grid, 0);

    return 0;
}