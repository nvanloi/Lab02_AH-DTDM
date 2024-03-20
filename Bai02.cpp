#include <iostream>
#include <cmath>

using namespace std;

// Hàm kiểm tra xem một số có phải là số chính phương hay không
bool isPerfectSquare(int num) {
    int sqrtNum = sqrt(num);
    return sqrtNum * sqrtNum == num;
}

// Hàm đếm và in ra các số chính phương nhỏ hơn n
void countAndPrintPerfectSquares(int n) {
    cout << "Cac so chinh phuong nho hon " << n << " la: ";
    int count = 0;
    for (int i = 1; i * i < n; ++i) {
        if (isPerfectSquare(i)) {
            cout << i * i << " ";
            count++;
        }
    }
    cout << endl;
    cout << "Tong so chinh phuong: " << count << endl;
}

int main() {
    int n;
    cout << "Nhap vao mot so nguyen duong n: ";
    cin >> n;
    countAndPrintPerfectSquares(n);
    return 0;
}
