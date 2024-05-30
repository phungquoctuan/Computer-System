#include <iostream>
#include <algorithm>

using namespace std;

// hex
// hex2dec
int hex2dec(string hex)
{
    int dec = 0;
    int base = 1;
    for (int i = hex.size() - 1; i >= 0; i--)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            dec += (hex[i] - 48) * base;
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            dec += (hex[i] - 55) * base;
        }
        base *= 16;
    }
    return dec;
}

// hex2bin
string hex2bin(string hex)
{
    string bin = "";
    for (int i = 0; i < hex.size(); i++)
    {
        if (hex[i] >= '0' && hex[i] <= '9')
        {
            switch (hex[i])
            {
            case '0':
                bin += "0000";
                break;
            case '1':
                bin += "0001";
                break;
            case '2':
                bin += "0010";
                break;
            case '3':
                bin += "0011";
                break;
            case '4':
                bin += "0100";
                break;
            case '5':
                bin += "0101";
                break;
            case '6':
                bin += "0110";
                break;
            case '7':
                bin += "0111";
                break;
            case '8':
                bin += "1000";
                break;
            case '9':
                bin += "1001";
                break;
            }
        }
        else if (hex[i] >= 'A' && hex[i] <= 'F')
        {
            switch (hex[i])
            {
            case 'A':
                bin += "1010";
                break;
            case 'B':
                bin += "1011";
                break;
            case 'C':
                bin += "1100";
                break;
            case 'D':
                bin += "1101";
                break;
            case 'E':
                bin += "1110";
                break;
            case 'F':
                bin += "1111";
                break;
            }
        }
    }
    return bin;
}

// dec
// dec2hex
string dec2hex(int dec)
{
    string hex = "";
    while (dec > 0)
    {
        int rem = dec % 16;
        if (rem < 10)
        {
            hex += rem + 48;
        }
        else
        {
            hex += rem + 55;
        }
        dec /= 16;
    }
    reverse(hex.begin(), hex.end());
    return hex;
}

// dec2bin
string dec2bin(int dec)
{
    string bin = "";
    while (dec > 0)
    {
        bin += dec % 2 + 48;
        dec /= 2;
    }
    reverse(bin.begin(), bin.end());
    return bin;
}

// bin
// bin2dec
int bin2dec(string bin)
{
    int dec = 0;
    int base = 1;
    for (int i = bin.size() - 1; i >= 0; i--)
    {
        dec += (bin[i] - '0') * base;
        base *= 2;
    }
    return dec;
}

// bin2hex
string bin2hex(string bin)
{
    string hex = "";
    int len = bin.size();
    int rem = len % 4;
    if (rem > 0)
    {
        bin.insert(0, 4 - rem, '0');
        len = bin.size();
    }
    for (int i = 0; i < len; i += 4)
    {
        string group = bin.substr(i, 4);
        int dec = bin2dec(group);
        if (dec < 10)
        {
            hex += dec + 48;
        }
        else
        {
            hex += dec + 55;
        }
    }
    return hex;
}

int main()
{
    string hex = "3E";
    cout << "Hexadecimal: " << hex << endl;
    cout << "Decimal: " << hex2dec(hex) << endl;
    cout << "Binary: " << hex2bin(hex) << endl;
    cout << endl;
    cout << endl;

    int dec = 62;
    cout << "Decimal: " << dec << endl;
    cout << "Hexadecimal: " << dec2hex(dec) << endl;
    cout << "Binary: " << dec2bin(dec) << endl;
    cout << endl;
    cout << endl;

    string bin = "111110";
    cout << "Binary: " << bin << endl;
    cout << "Hexadecimal: " << bin2hex(bin) << endl;
    cout << "Decimal: " << bin2dec(bin) << endl;
    cout << endl;
    cout << endl;
    
    return 0;
}
