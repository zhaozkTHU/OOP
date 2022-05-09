#include<iostream>
#include<vector>

int main() {
    std::vector<int> a = {1, 2, 3};
    auto p = a.begin();
    p = std::find(a.begin(), a.end(), 4);
    if(p == a.end()) std::cout << 1;
}