#include <iostream>
#include <vector>
using namespace std;

bool searchInRow(const vector<int>& row, int target) {
    int left = 0, right = row.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (row[mid] == target)
            return true;
        else if (row[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

bool searchMatrix(const vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty())
        return false;
    int m = matrix.size();
    int n = matrix[0].size();
    int sr = 0, er = m - 1;
    while (sr <= er) {
        int mr = sr + (er - sr) / 2;
        if (target >= matrix[mr][0] && target <= matrix[mr][n - 1]) {
            return searchInRow(matrix[mr], target);
        }
        else if (target < matrix[mr][0]) {
            er = mr - 1;
        }
        else {
            sr = mr + 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    if (searchMatrix(matrix, target))
        cout << "Found " << target << " in the matrix." << endl;
    else
        cout << target << " not found in the matrix." << endl;
    return 0;
}
