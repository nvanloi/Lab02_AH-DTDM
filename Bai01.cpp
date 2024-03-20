#include <iostream>

using namespace std;

int main() {
    cout << "Cac so nguyen co 2 chu so va la boi cua 7 la: " << endl;
    for (int i = 10; i < 100; ++i) {
        if (i % 7 == 0) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}
