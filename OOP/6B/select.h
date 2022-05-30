#include"Student.h"
#include<vector>
using std::vector;

vector<int> select(vector<int> &credit, int l, int r, Student *student) {
    vector<int> result;
    for (int no = l; no <= r; no++) {
        if (student->select(no, credit[no - 1])) result.push_back(no);
    }
    return result;
}