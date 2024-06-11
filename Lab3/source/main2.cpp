#include <iostream>
#include <cmath>
#include <string>
#include <cstdint>
using namespace std;

/**
 * forceFloat: Hàm này ép kiểu chuỗi nhị phân thành số chấm động kiểu float.
 * @param p con trỏ trỏ đến số chấm động kiểu float.
 * @param s chuỗi nhị phân cần ép kiểu.
 */
void forceFloat(float *p, const string &s)
{
    // Chuyển đổi chuỗi nhị phân thành giá trị số nguyên 32 bit
    uint32_t value = 0;
    for (size_t i = 0; i < s.size(); ++i)
    {
        value = (value << 1) | (s[i] - '0');
    }

    // Ép kiểu con trỏ uint32_t thành con trỏ float và gán giá trị
    *reinterpret_cast<uint32_t *>(p) = value;
}

/**
 * binaryToFloat: Hàm này chuyển đổi chuỗi nhị phân thành số chấm động kiểu float.
 * @param binary chuỗi nhị phân cần chuyển đổi.
 * @return giá trị số chấm động kiểu float tương ứng.
 */
float binaryToFloat(const string &binary)
{
    if (binary.size() != 32)
    {
        cerr << "Chuỗi nhị phân phải có đúng 32 ký tự!" << endl;
        return NAN;
    }

    // Tách các phần dấu, phần mũ và phần trị
    int sign = binary[0] - '0';
    string exponent_str = binary.substr(1, 8);
    string mantissa_str = binary.substr(9, 23);

    // Chuyển đổi phần mũ từ nhị phân sang thập phân
    int exponent = 0;
    for (char bit : exponent_str)
    {
        exponent = (exponent << 1) | (bit - '0');
    }
    exponent -= 127; // Trừ đi bias (127)

    // Chuyển đổi phần trị từ nhị phân sang thập phân
    float mantissa = 1.0; // Phần nguyên mặc định là 1 (theo chuẩn IEEE 754)
    for (int i = 0; i < mantissa_str.size(); ++i)
    {
        if (mantissa_str[i] == '1')
        {
            mantissa += pow(2, -(i + 1));
        }
    }

    // Tính giá trị số chấm động
    float result = pow(2, exponent) * mantissa;
    if (sign == 1)
    {
        result = -result;
    }

    return result;
}

int main()
{
    string binary;

    cout << "Nhập vào dãy nhị phân: ";
    cin >> binary;

    float number;
    forceFloat(&number, binary);

    cout << "Số chấm động (single) tương ứng: " << number << endl;

    return 0;
}
