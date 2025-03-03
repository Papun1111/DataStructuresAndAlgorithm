#include<iostream>
#include<vector>
using namespace std;

void printInSpiral(vector<vector<int>> matrix) {
    int srow = 0, scol = 0, erow = matrix.size() - 1, ecol = matrix[0].size() - 1;
    while (srow <= erow && scol <= ecol) {
        for (int i = scol; i <= ecol; i++) {
            cout << matrix[srow][i] << " ";
        }
        srow++;
        for (int i = srow; i <= erow; i++) {
            cout << matrix[i][ecol] << " ";
        }
        ecol--;
        if (srow <= erow) {
            for (int i = ecol; i >= scol; i--) {
                cout << matrix[erow][i] << " ";
            }
            erow--;
        }
        if (scol <= ecol) {
            for (int i = erow; i >= srow; i--) {
                cout << matrix[i][scol] << " ";
            }
            scol++;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    printInSpiral(matrix);
    return 0;
}
