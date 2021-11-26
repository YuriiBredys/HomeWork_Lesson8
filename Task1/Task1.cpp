#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    string pathIn = "C:\\Users\\User\\source\\repos\\HomeWork_Lesson8\\Task1\\Matrix.txt";
    string pathOut = "C:\\Users\\User\\source\\repos\\HomeWork_Lesson8\\Task1\\MatrixOut.txt";
    string input;
    vector<vector<int>> matrix;
    fstream objectIn, objectOut;

    objectIn.open(pathIn, fstream::in);

    if (!objectIn.is_open())
    {
        cout << "Error" << endl;
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

    for(int i = 0; i < matrix.size(); i++)
    {
        sort(matrix[i].begin(), matrix[i].end());
    }

    objectOut.open(pathOut, fstream::out);

    if(!objectOut.is_open())
    {
        cout << "Error" << endl;
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
