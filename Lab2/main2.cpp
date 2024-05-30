#include <iostream>


using namespace std;

// Hàm chuyển đổi 8 bit sang số nguyên bù 2
int bitToInt(bitset<8> bits)
{
    int result = 0;
    if (bits[7] == 0) // Nếu bit đầu tiên là 0
    {
        for (int i = 0; i < 8; i++)
        {
            result = (result << 1) | bits[i];
        }
    }
    else // Nếu bit đầu tiên là 1
    {
        for (int i = 0; i < 8; i++)
        {
            result = (result << 1) | (1 - bits[i]);
        }
        result = -result - 1;
    }
    return result;
}

// Hàm chuyển đổi số nguyên sang bitset 8 bit bù 2
bitset<8> int8ToBitset(int value)
{
    return bitset<8>(value);
}

int main()
{
    // Nhập vào 2 dãy bit 8 bit (ở dạng bù 2)
    bitset<8> bits1, bits2;
    cout << "Nhap vao day bit thu nhat (8 bit): ";
    cin >> bits1;
    cout << "Nhap vao day bit thu hai (8 bit): ";
    cin >> bits2;

    // Chuyển đổi bitset sang số nguyên bù 2
    int num1 = bitsetToInt8(bits1);
    int num2 = bitsetToInt8(bits2);

    // Thực hiện các phép tính
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    int quotient = (num2 != 0) ? (num1 / num2) : 0; // Tránh chia cho 0

    // Chuyển đổi kết quả sang bitset
    bitset<8> sumBits = int8ToBitset(sum);
    bitset<8> differenceBits = int8ToBitset(difference);
    bitset<8> productBits = int8ToBitset(product);
    bitset<8> quotientBits = int8ToBitset(quotient);

    // In kết quả
    cout << "Ket qua phep cong: " << sumBits << " (" << int(sum) << ")" << endl;
    cout << "Ket qua phep tru: " << differenceBits << " (" << int(difference) << ")" << endl;
    cout << "Ket qua phep nhan: " << productBits << " (" << int(product) << ")" << endl;
    if (num2 != 0)
    {
        cout << "Ket qua phep chia: " << quotientBits << " (" << int(quotient) << ")" << endl;
    }
    else
    {
        cout << "Khong the chia cho 0" << endl;
    }

    return 0;
}
