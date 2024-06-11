#include <iostream>
#include <bitset>
using namespace std;

/**
 * dumpFloat: Hàm này in ra biểu diễn nhị phân của một số chấm động kiểu float.
 * @param p con trỏ trỏ đến số chấm động kiểu float.
 */
void dumpFloat(float *p)
{
    // Sử dụng union để ánh xạ giữa float và unsigned int
    union
    {
        float input; // Kiểu float để nhập vào
        int output;  // Kiểu int để thao tác trên các bit
    } data;

    data.input = *p;

    // Lấy giá trị nhị phân của số float
    unsigned int binary = data.output;

    // Tách và in dấu
    unsigned int sign = (binary >> 31) & 1;
    cout << sign << " ";

    // Tách và in phần mũ
    unsigned int exponent = (binary >> 23) & 0xFF;
    bitset<8> expBits(exponent);
    cout << expBits << " ";

    // Tách và in phần trị
    unsigned int significand = binary & 0x7FFFFF;
    bitset<23> significandBits(significand);
    cout << significandBits << endl;
}

int main()
{
    float number;

    cout << "Nhập vào số chấm động (32-bit): ";
    cin >> number;

    cout << "Biểu diễn nhị phân tương ứng: ";
    dumpFloat(&number);

    return 0;
}
