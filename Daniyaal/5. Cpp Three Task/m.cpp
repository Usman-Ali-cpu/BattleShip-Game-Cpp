// // C++ program to find size of an array by writing our
// // sizeof
// #include <iostream>
// using namespace std;

// int main()
// {
//     string str = "12345";
//     string s = "***************";
//     string sArr[3];
//     for (int i = 0; i < 3; i++)
//     {
//         sArr[i] = s;
//     }
//     int mul = 3;
//     int y = 0;
//     int z = 0;
//     for (int x = 0; x < 3; x += mul)
//     {
//         int k = 0;
//         int j = 0;
//         for (int i = 0; i < s.length(); i += mul)
//         {
//             int count = 0;

//             while (count < mul)
//             {
//                 if (j >= str.length())
//                 {
//                     j = 0;
//                 }
//                 s.at(k) = str.at(j);
//                 k++;
//                 count++;
//             }
//             j++;
//         }

//         // cout << s << endl;
//         int counter = 0;

//         while (counter < mul)
//         {
//             if (y >= 3)
//             {
//                 y = 0;
//             }
//             sArr[z] = s;
//             z++;
//             counter++;
//         }
//         y++;
//     }
//     for (int i = 0; i < 3; i++)
//     {
//         cout << sArr[i] << endl;
//     }

//     return 0;
// }

// int row = this->numRows * mult;
// int cols = this->numCols * mult;
// char **a = new char *[row];
// for (int i = 0; i < row; i++)
// {
//     a[i] = new char[cols];
// }

// int y = 0;
// int z = 0;
// int b = 0;

// for (int x = 0; x < row - 1; x += mult)
// {
//     int k = 0;
//     int j = 0;
//     char *array = new char[cols];
//     for (int i = 0; i < cols; i += mult)
//     {
//         int count = 0;
//         while (count < mult)
//         {
//             if (j >= numCols)
//             {
//                 j = 0;
//             }
//             b = x / 2;
//             if (b == 0)
//             {
//                 b++;
//             }
//             cout << "x: " << b << endl;
//             // array[k] = grid[x][j];
//             a[x][k] = grid[b - 1][j];
//             k++;
//             // cout << a[x][k] << endl;
//             count++;
//         }
//         j++;
//     }
//     // int counter = 0;
//     // while (counter < mult)
//     // {
//     //     setRow(z, 0, a[x]);
//     //     z++;
//     //     counter++;
//     // }
//     // cout << "endl 2" << endl;
//     delete[] array;
// }
// // for (int i = 0; i < row; i++)
// // {
// //     for (int j = 0; j < cols; j++)
// //     {
// //         cout << a[i][j] << " ";
// //     }
// //     cout << endl;
// // }
// // deleteGrid(this->grid, numRows);
// // this->numRows = row;
// // this->numCols = cols;

// // this->grid = new char *[numRows];

// // for (int i = 0; i < numRows; i++)
// // {
// //     grid[i] = new char[numCols];
// // }
// // cout << "Good" << endl;
// // for (int i = 0; i < numRows; i++)
// // {
// //     for (int j = 0; j < numCols; j++)
// //     {
// //         grid[i][j] = a[i][j];
// //     }
// // }
// // deleteGrid(a, row);