#include <iostream>

using namespace std;

// Hàm in dãy bit nhị phân của một số nguyên 4 byte
void printBits(int num)
{
    for (int i = 31; i >= 0; i--) // Duyệt qua từng bit (4 byte = 32 bit)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

// Hàm tạo số nguyên từ mảng 32 phần tử 0 hoặc 1
int createIntFromBitArray(int bitArray[32])
{
    int result = 0;
    for (int i = 0; i < 32; i++)
    {
        result = (result << 1) | bitArray[i];
    }
    return result;
}

int main()
{
    // Phần 1: Nhập số nguyên X và in ra dãy bit nhị phân
    int X;
    cout << "Nhap so nguyen X: ";
    cin >> X;
    cout << "Day bit cua so nguyen X: ";
    printBits(X);

    // Phần 2: Tạo số nguyên từ mảng bit
    int bitNum;
    int bitArray[32];
    cout << "Nhap 32 phan tu 0 hoac 1 de tao mang bit:" << endl;
    cin >> bitNum;
    for (int i = 31; i >= 0; i--)
    {
        bitArray[i] = bitNum % 10;
        bitNum /= 10;
    }

    int newX = createIntFromBitArray(bitArray);
    cout << "So nguyen duoc tao tu mang bit: " << newX << endl;
    cout << "Day bit cua so nguyen vua tao: ";
    printBits(newX);

    return 0;
}
