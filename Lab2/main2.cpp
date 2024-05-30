#include <iostream>

using namespace std;

// chương trình Nhập vào 2 dãy bit 8 bit (ở dạng bù 2). Hãy thực hiện các phép tính cộng, trừ,nhân, chia trên 2 dãy bit đã nhập
// Hàm in dãy bit nhị phân của một số nguyên 1 byte
void printBits(int num)
{
    for (int i = 7; i >= 0; i--) // Duyệt qua từng bit (1 byte = 8 bit)
    {
        cout << ((num >> i) & 1);
    }
    cout << endl;
}

// Hàm tạo số nguyên từ mảng 8 phần tử 0 hoặc 1
int createIntFromBitArray(int bitArray[8])
{
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        result = (result << 1) | bitArray[i];
    }
    return result;
}

// Hàm cộng 2 số nguyên 8 bit
int add(int num1, int num2)
{
    return num1 + num2;
}

// Hàm trừ 2 số nguyên 8 bit
int subtract(int num1, int num2)
{
    return num1 - num2;
}

// Hàm nhân 2 số nguyên 8 bit
int multiply(int num1, int num2)
{
    return num1 * num2;
}

// Hàm chia 2 số nguyên 8 bit
int divide(int num1, int num2)
{
    return num1 / num2;
}

int main(int argc, char const *argv[])
{
    // Phần 1: Nhập 2 dãy bit 8 bit và in ra dãy bit nhị phân
    int bitNum1, bitNum2;
    int bitArray1[8], bitArray2[8];
    cout << "Nhap 2 so nguyen 8 bit:" << endl;
    cin >> bitNum1 >> bitNum2;
    for (int i = 7; i >= 0; i--)
    {
        bitArray1[i] = bitNum1 % 10;
        bitNum1 /= 10;
        bitArray2[i] = bitNum2 % 10;
        bitNum2 /= 10;
    }

    cout << "Day bit cua so nguyen 1: ";
    printBits(createIntFromBitArray(bitArray1));
    cout << "Day bit cua so nguyen 2: ";
    printBits(createIntFromBitArray(bitArray2));

    // Phần 2: Thực hiện các phép toán cộng, trừ, nhân, chia
    int result;
    result = add(createIntFromBitArray(bitArray1), createIntFromBitArray(bitArray2));
    cout << "Tong 2 so nguyen: ";
    printBits(result);

    result = subtract(createIntFromBitArray(bitArray1), createIntFromBitArray(bitArray2));
    cout << "Hieu 2 so nguyen: ";
    printBits(result);

    result = multiply(createIntFromBitArray(bitArray1), createIntFromBitArray(bitArray2));
    cout << "Tich 2 so nguyen: ";
    printBits(result);

    result = divide(createIntFromBitArray(bitArray1), createIntFromBitArray(bitArray2));
    cout << "Thuong 2 so nguyen: ";
    printBits(result);

    return 0;
}
