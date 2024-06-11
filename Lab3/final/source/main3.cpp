#include <iostream>
#include <cmath>
#include <limits>
#include <bitset>
#include <string>
#include <cstdint>
using namespace std;

/**
 * forceFloat: Hàm này ép kiểu chuỗi nhị phân thành số chấm động kiểu float.
 * @param p con trỏ trỏ đến số chấm động kiểu float.
 * @param s chuỗi nhị phân cần ép kiểu.
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

/**
 * floatToBinary: Hàm này chuyển đổi số chấm động kiểu float thành chuỗi nhị phân.
 * @param number số chấm động cần chuyển đổi.
 * @return chuỗi nhị phân tương ứng.
 */
string floatToBinary(float number)
{
    uint32_t *binaryPtr = reinterpret_cast<uint32_t *>(&number);
    bitset<32> binary(*binaryPtr);
    return binary.to_string();
}

/**
 * surveySpecialCases: Hàm này khảo sát các trường hợp đặc biệt của số chấm động.
 */
void surveySpecialCases()
{
    float posInf = numeric_limits<float>::infinity();
    float negInf = -numeric_limits<float>::infinity();
    float nanValue = numeric_limits<float>::quiet_NaN();

    cout << "+∞: " << posInf << ", Biểu diễn nhị phân: " << floatToBinary(posInf) << endl;
    cout << "-∞: " << negInf << ", Biểu diễn nhị phân: " << floatToBinary(negInf) << endl;
    cout << "NaN: " << nanValue << ", Biểu diễn nhị phân: " << floatToBinary(nanValue) << endl;

    // Thử nghiệm các phép toán đặc biệt
    float x = 5.0;
    cout << "x - (+∞): " << x - posInf << endl;
    cout << "(+∞) - (+∞): " << posInf - posInf << endl;
    cout << "x / 0: " << x / 0 << endl;
    cout << "0 / 0: " << 0.0 / 0 << endl;
    cout << "∞ / ∞: " << posInf / posInf << endl;
    cout << "sqrt(-x): " << sqrt(-x) << endl;
}

int main()
{
    // 1. Chuyển đổi số 1.3E+20 sang biểu diễn nhị phân
    float number1 = 1.3E+20;
    string binary1 = floatToBinary(number1);
    cout << "1.3E+20: " << number1 << ", Biểu diễn nhị phân: " << binary1 << endl;

    // 2. Số float nhỏ nhất lớn hơn 0 và biểu diễn nhị phân của nó
    float minPositiveFloat = numeric_limits<float>::min();
    string binaryMinPositiveFloat = floatToBinary(minPositiveFloat);
    cout << "Số float nhỏ nhất lớn hơn 0: " << minPositiveFloat << ", Biểu diễn nhị phân: " << binaryMinPositiveFloat << endl;

    // 3. Khảo sát các trường hợp đặc biệt
    surveySpecialCases();

    return 0;
}
