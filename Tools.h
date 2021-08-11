#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using std::string;

typedef struct TwoString
{
    string val1, val2;
} twostr;

typedef struct Picktyp
{
    int intg;
    string strg;

} picktyp;

namespace FileFunc
{
    using std::string;
    int FwriteOw(string Filename, string Data)
    {
        std::fstream my_file;
        my_file.open(Filename, std::ios::out);
        if (!my_file)
        {
            printf("File Doesnt exist :-");
            std::cout << Filename << "\n";
            exit(EXIT_FAILURE);
        }
        else
        {
            my_file << Data;
            my_file.close();
        }
        return 0;
    }
    string Fread(string Filename)
    {
        std::fstream my_file;
        string Data;
        string Line;
        my_file.open(Filename, std::ios::in);
        if (!my_file)
        {
            printf("File Doesnt exist :-");
            std::cout << Filename << "\n";
            exit(EXIT_FAILURE);
        }
        else
        {
            while (std::getline(my_file, Line))
            {
                Data = Data + Line + "\n";
            }
        }
        my_file.close();
        return Data;
    }
}

namespace StrFunc
{
    string SubTxt(string text, int init, int fin)
    {
        string Txt = "";
        bool InSubTxt = false;
        for (int i = 0; i < text.length(); i++)
        {
            if (i == init)
            {
                InSubTxt = true;
            }
            if (InSubTxt)
            {
                Txt = Txt + text[i];
                if (i == fin)
                {
                    InSubTxt = false;
                    return Txt;
                }
            }
        }
        printf("Err init or fin out of bounds (in Tools/SubTxt)\n");
        std::cout << "initial cord :- " << init << "\n";
        std::cout << "initial cord :- " << fin << "\n";
        exit(EXIT_FAILURE);
        return "Err init or fin out of bounds (in Tools/SubTxt)\n";
    }

    twostr SplitTxt(string text, int spliceLoc)
    {
        string Txt1 = "";
        string Txt2 = "";
        bool InSubTxt = false;
        for (int i = 0; i < text.length(); i++)
        {
            if (i == spliceLoc)
            {
                InSubTxt = true;
            }
            if (InSubTxt)
            {
                Txt1 = Txt1 + text[i];
            }
            else
            {
                Txt2 = Txt2 + text[i];
            }
        }
        twostr Txt;
        Txt.val1 = Txt1;
        Txt.val2 = Txt2;
        return Txt;
    }

    string InjectTxt(string text, string injtxt, int loc = -1)
    {
        // -1 = at the end of Txt(default)
        // injtxt = txt to be inserted

        if (loc == -1)
        {
            return text + injtxt;
        }
        else if (loc >= 0 && loc <= text.length())
        {
            string FirstTxt = "";
            string SecondTxt = "";
            for (int i = 0; i < text.length(); i++)
            {
                if (i < loc)
                {
                    FirstTxt = FirstTxt + text[i];
                }
                else
                {
                    SecondTxt = SecondTxt + text[i];
                }
            }
            return FirstTxt + injtxt + SecondTxt;
        }
        else
        {
            printf("Err loc out of bounds (in Tools/InjectTxt)\n");
            exit(EXIT_FAILURE);
            return "Err loc out of bounds (in Tools/InjectTxt)\n";
        }
    }

    string AddLetters(string text, int len, string letter = "0", int loc = -1)
    {
        //letter = letter to be repeated
        string letters = "";
        if (loc < -1 || loc > len)
        {
            printf("Err loc out of bounds (in Tools/AddLetters)\n");
            exit(EXIT_FAILURE);
            return "Err loc out of bounds (in Tools/AddLetters)\n";
        }
        for (int i = 0; i < len; i++)
        {
            letters = letters + letter;
        }
        return InjectTxt(text, letters, loc);
    }

}

namespace Baseconv
{
    string HexToBin(string hexdec)
    {
        long int i = 0;
        string bin = "";

        while (hexdec[i])
        {

            switch (hexdec[i])
            {
            case '0':
                bin = bin + "0000";
                break;
            case '1':
                bin = bin + "0001";
                break;
            case '2':
                bin = bin + "0010";
                break;
            case '3':
                bin = bin + "0011";
                break;
            case '4':
                bin = bin + "0100";
                break;
            case '5':
                bin = bin + "0101";
                break;
            case '6':
                bin = bin + "0110";
                break;
            case '7':
                bin = bin + "0111";
                break;
            case '8':
                bin = bin + "1000";
                break;
            case '9':
                bin = bin + "1001";
                break;
            case 'A':
            case 'a':
                bin = bin + "1010";
                break;
            case 'B':
            case 'b':
                bin = bin + "1011";
                break;
            case 'C':
            case 'c':
                bin = bin + "1100";
                break;
            case 'D':
            case 'd':
                bin = bin + "1101";
                break;
            case 'E':
            case 'e':
                bin = bin + "1110";
                break;
            case 'F':
            case 'f':
                bin = bin + "1111";
                break;
            default:
                printf("Err not HexDec (in Tools/HexToBin)\n");
                std::cout << hexdec << "\n";
                std::cout << hexdec[i] << "\n";
                exit(EXIT_FAILURE);
                break;
            }
            i++;
        }
        return bin;
    }

    string BinToHex(string hexdec)
    {
        long int i = 0;
        string dec = "";
        string bin = "";
        string temp = "";
        for (int i = 0; i < hexdec.length(); i = i + 4)
        {
            int a = hexdec[i] == 49 ? 8 : 0;
            int b = hexdec[i + 1] == 49 ? 4 : 0;
            int c = hexdec[i + 2] == 49 ? 2 : 0;
            int d = hexdec[i + 3] == 49 ? 1 : 0;
            int e = a + b + c + d;

            if (e > 9)
            {
                dec = dec + std::to_string(e - 10);
                temp = temp + "1";
            }
            else
            {
                dec = dec + std::to_string(e);
                temp = temp + "0";
            }
        }
        while (temp[i])
        {
            if (temp[i] == '0')
            {
                switch (dec[i])
                {
                case '0':
                    bin = bin + "0";
                    break;
                case '1':
                    bin = bin + "1";
                    break;
                case '2':
                    bin = bin + "2";
                    break;
                case '3':
                    bin = bin + "3";
                    break;
                case '4':
                    bin = bin + "4";
                    break;
                case '5':
                    bin = bin + "5";
                    break;
                case '6':
                    bin = bin + "6";
                    break;
                case '7':
                    bin = bin + "7";
                    break;
                case '8':
                    bin = bin + "8";
                    break;
                case '9':
                    bin = bin + "9";
                    break;
                default:
                    printf("Err not HexDec in num (in Tools/BinToHex)\n");
                    std::cout << dec << "\n";
                    std::cout << dec[i] << "\n";
                    exit(EXIT_FAILURE);
                    break;
                }
            }
            else
            {
                switch (dec[i])
                {
                case '0':
                    bin = bin + "a";
                    break;
                case '1':
                    bin = bin + "b";
                    break;
                case '2':
                    bin = bin + "c";
                    break;
                case '3':
                    bin = bin + "d";
                    break;
                case '4':
                    bin = bin + "e";
                    break;
                case '5':
                    bin = bin + "f";
                    break;
                default:
                    printf("Err not HexDec in Letters (in Tools/BinToHex)\n");
                    std::cout << dec << "\n";
                    std::cout << dec[i] << "\n";
                    exit(EXIT_FAILURE);
                    break;
                }
            }
            i++;
        }
        return bin;
    }

    string DecToBin(int dec)
    {
        string bin = "";
        while (dec > 0)
        {
            bin = std::to_string((dec % 2)) + bin;
            dec = dec / 2;
        }

        return bin;
    }

    string DecToHex(unsigned int n)
    {
        // char array to store hexadecimal number
        string dec = "";

        // counter for hexadecimal number array
        int i = 0;
        while (n != 0)
        {

            // std::cout << n;
            // std::cout << "\n";
            // temporary variable to store remainder
            int temp = 0;

            // storing remainder in temp variable.
            temp = n % 16;

            // check if temp < 10
            if (temp < 10)
            {
                dec = char(temp + 48) + dec;
                i++;
            }
            else
            {
                dec = char(temp + 55) + dec;
                i++;
            }

            n = n / 16;
        }
        return dec;
    }

    unsigned char hexval(unsigned char c)
    {
        if ('0' <= c && c <= '9')
            return c - '0';
        else if ('a' <= c && c <= 'f')
            return c - 'a' + 10;
        else if ('A' <= c && c <= 'F')
            return c - 'A' + 10;
        else
            abort();
    }
    string HexToStr(const string &in)
    {
        string out;
        for (string::const_iterator p = in.begin(); p != in.end(); p++)
        {
            unsigned char c = hexval(*p);
            p++;
            if (p == in.end())
                break;                 // incomplete last digit - should report error
            c = (c << 4) + hexval(*p); // + takes precedence over <<
            out.push_back(c);
        }
        return out;
    }

}

namespace Shafunc
{
    using std::string;
    using StrFunc::AddLetters;
    using StrFunc::InjectTxt;
    using StrFunc::SplitTxt;
    using StrFunc::SubTxt;

    string And(string bin1, string bin2)
    {
        string finbin;
        for (int i = 0; i < bin1.length(); i++)
        {
            finbin = finbin + std::to_string((bin1[i] & bin2[i]) == 49);
        }
        return finbin;
    }
    string Or(string bin1, string bin2)
    {
        string finbin;
        for (int i = 0; i < bin1.length(); i++)
        {
            finbin = finbin + std::to_string((bin1[i] | bin2[i]) == 49);
        }
        return finbin;
    }
    string Xor(string bin1, string bin2)
    {
        string finbin;
        for (int i = 0; i < bin1.length(); i++)
        {
            finbin = finbin + std::to_string(bin1[i] ^ bin2[i]);
            // std::cout << (bin1[i] ^ bin2[i]) << "\n";
        }
        return finbin;
    }
    string Comp(string bin)
    {
        //Compliment
        string finbin;
        for (int i = 0; i < bin.length(); i++)
        {
            finbin = finbin + std::to_string(bin[i] == 48);
            // std::cout << (bin1[i] ^ bin2[i]) << "\n";
        }
        return finbin;
    }
    string AddMod(string bin1, string bin2)
    {
        //Addition modulo 2^w
        string finbin;
        bool carrybit = false;
        for (int i = bin1.length() - 1; i >= 0; i--)
        {
            finbin = std::to_string((bin1[i] == 49 ^ bin2[i] == 49) ^ carrybit) + finbin;
            carrybit = bin1[i] == 49 & bin2[i] == 49 ^ carrybit & bin2[i] == 49 ^ carrybit & bin1[i] == 49;
        }
        return finbin;
    }
    string RotRight(string bin, int modnum)
    {
        //Rotate Right by int modnum
        twostr splitted = SplitTxt(bin, bin.length() - modnum);
        return InjectTxt(splitted.val2, splitted.val1, 0);
    }
    string RotLeft(string bin, int modnum)
    {
        //Rotate Left by int modnum
        twostr splitted = SplitTxt(bin, modnum);
        return InjectTxt(splitted.val2, splitted.val1, 0);
    }
    string ShiftRight(string bin, int modnum)
    {
        //Shifts Right by int modnum
        return AddLetters(SubTxt(bin, 0, bin.length() - modnum - 1), modnum, "0", 0);
    }
    string ShiftLeft(string bin, int modnum)
    {
        //Shifts Left by int modnum
        return AddLetters(SubTxt(bin, modnum, bin.length() - 1), modnum);
    }
    string Choice(string x, string y, string z)
    {
        return Xor(And(x, y), And(Comp(x), z));
    }
    string Major(string x, string y, string z)
    {
        return Xor(Xor(And(x, y), And(x, z)), And(y, z));
    }
    string SIGMA0(string x)
    {
        return Xor(Xor(RotRight(x, 2), RotRight(x, 13)), RotRight(x, 22));
    }
    string SIGMA1(string x)
    {
        return Xor(Xor(RotRight(x, 6), RotRight(x, 11)), RotRight(x, 25));
    }
    string sigma0(string x)
    {
        return Xor(Xor(RotRight(x, 7), RotRight(x, 18)), ShiftRight(x, 3));
    }
    string sigma1(string x)
    {
        return Xor(Xor(RotRight(x, 17), RotRight(x, 19)), ShiftRight(x, 10));
    }
}
