#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>> matrix)
{
    vector<vector<int>> transposed;
    for (int i = 0; i < matrix[0].size(); i++)
    {
        transposed.push_back(vector<int>(matrix.size()));
    }

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

int main()
{
    string pathIn = "../HomeWork_Lesson8/Task2/Matrix.txt";
    string pathOut = "../HomeWork_Lesson8/Task2/MatrixOut.txt";
    string input;
    vector<vector<int>> matrix;
    fstream objectIn, objectOut;

    objectIn.open(pathIn, fstream::in);

    if (!objectIn.is_open())
    {
        cout << "Error in" << endl;
    }
    else
    {
        while (getline(objectIn, input, '\n'))
        {
            stringstream stream{ input };

            string number;
            vector<int> result;

            while (getline(stream, number, ' '))
                result.push_back(stoi(number));

            matrix.push_back(result);
        }
    }

    objectIn.close();

    auto transposed = transpose(matrix);

    for (auto& row : transposed)
    {
        sort(row.begin(), row.end());
    }
    
    matrix = transpose(transposed);

    objectOut.open(pathOut, fstream::out);

    if (!objectOut.is_open())
    {
        cout << "Error out" << endl;
    }
    else
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                objectOut << matrix[i][j] << " ";
            }
            objectOut << endl;
        }
    }

    objectOut.close();
}