#include <iostream>
#include <cstdio>
using namespace std;

/**
 * testConversions: Hàm này kiểm tra các chuyển đổi giữa số nguyên và số chấm động.
 * Trong C++, chúng ta có thể chuyển đổi giữa các kiểu dữ liệu số nguyên và số chấm động
 * thông qua các phép ép kiểu (casting). Tuy nhiên, việc chuyển đổi giữa các kiểu dữ liệu
 * này không phải lúc nào cũng an toàn.
 */
void testConversions()
{
    // Trường hợp 1: Chuyển đổi float -> int -> float
    float f1 = 12345.6789f;
    int i1 = static_cast<int>(f1);
    float f1_back = static_cast<float>(i1);
    cout << "Trường hợp 1: float -> int -> float" << endl;
    cout << "Ban đầu: " << f1 << ", Sau khi chuyển đổi: " << f1_back << endl;

    // Trường hợp 2: Chuyển đổi int -> float -> int
    int i2 = 12345;
    float f2 = static_cast<float>(i2);
    int i2_back = static_cast<int>(f2);
    cout << "Trường hợp 2: int -> float -> int" << endl;
    cout << "Ban đầu: " << i2 << ", Sau khi chuyển đổi: " << i2_back << endl;

    // Trường hợp 3: Phép cộng số chấm động có tính kết hợp
    float x = 1.0f;
    float y = 1.0e10f;
    float z = -1.0e10f;
    cout << "Trường hợp 3: (x + y) + z == x + (y + z)" << endl;
    cout << "(x + y) + z = " << (x + y) + z << endl;
    cout << "x + (y + z) = " << x + (y + z) << endl;

    // Trường hợp 4: i = (int) (3.14159 * f)
    float f3 = 2.5f;
    int i3 = static_cast<int>(3.14159 * f3);
    cout << "Trường hợp 4: i = (int) (3.14159 * f)" << endl;
    cout << "f = " << f3 << ", i = " << i3 << endl;

    // Trường hợp 5: f = f + (float) i
    float f4 = 2.5f;
    int i4 = 3;
    f4 = f4 + static_cast<float>(i4);
    cout << "Trường hợp 5: f = f + (float) i" << endl;
    cout << "f = " << f4 << ", i = " << i4 << endl;

    // Trường hợp 6: if (i == (int)((float) i)) { printf("true"); }
    int i5 = 12345;
    cout << "Trường hợp 6: if (i == (int)((float) i)) { printf(\"true\"); }" << endl;
    if (i5 == static_cast<int>(static_cast<float>(i5)))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // Trường hợp 7: if (i == (int)((double) i)) { printf("true"); }
    int i6 = 12345;
    cout << "Trường hợp 7: if (i == (int)((double) i)) { printf(\"true\"); }" << endl;
    if (i6 == static_cast<int>(static_cast<double>(i6)))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // Trường hợp 8: if (f == (float)((int) f)) { printf("true"); }
    float f7 = 2.5f;
    cout << "Trường hợp 8: if (f == (float)((int) f)) { printf(\"true\"); }" << endl;
    if (f7 == static_cast<float>(static_cast<int>(f7)))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    // Trường hợp 9: if (f == (double)((int) f)) { printf("true"); }
    float f8 = 2.5f;
    cout << "Trường hợp 9: if (f == (double)((int) f)) { printf(\"true\"); }" << endl;
    if (f8 == static_cast<double>(static_cast<int>(f8)))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}

int main()
{
    testConversions();
    return 0;
}
