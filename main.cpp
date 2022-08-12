#include "double_linked_list.hpp"

int main() {
    double_linked_list<int> arr;
    arr.insert(1, 0);
    arr.insert(2, 1);
    arr.insert(3, 2);
    arr.insert(4, 3);
    arr.print_list();
    std :: cout << '\n';
    std :: cout.flush();

    arr.clear();

    arr.insert(1, 0);
    arr.insert(2, 1);
    arr.insert(3, 2);
    arr.insert(4, 3);

    arr.erase(0);
    arr.erase(0);
    arr.print_list();
    return 0;
}
