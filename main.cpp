#include <windows.h>
#include <chrono>
#include <iostream>
#include <string>
#include <math.h>
#include "sha256.h"
#include "Tools.h"

#define SHA2_MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

using Shafunc::AddMod;
using Shafunc::Choice;
using Shafunc::Major;
using Shafunc::SIGMA0;
using Shafunc::sigma0;
using Shafunc::SIGMA1;
using Shafunc::sigma1;
using std::cout;
using std::endl;
using std::string;

string ShaAlgo(string Hash);

int main(int argc, char *argv[])
{
    // string temp = "0100000000000000000000000000000000000000000000000000000000000000000000003ba3edfd7a7b12b27ac72c3e67768f617fc81bc3888a51323a9fb8aa4b1e5e4a29ab5f49ffff001d1dac2b7c";
    // cout << Major("1111010000100100000", "0110000110101000000", "01010011000000100000"); //SHA2_MAJ(500000, 200000, 340000);
    int i = 26;

    // auto start = std::chrono::high_resolution_clock::now();

    // while (i < 5000)
    // {
    //     int j = i;
    //     string temp = "";
    //     if (i == 0)
    //     {
    //         temp = "a";
    //     }
    //     while (j != 0)
    //     {
    //         temp = temp + char((j % 26) + 97);
    //         cout << char((j % 26) + 97);
    //         j = j / 26;
    //     }
    //     int Hex = temp[0];
    //     for (size_t i = 1; i < temp.length(); i++)
    //     {
    //         Hex = (Hex << 4) + temp[i];
    //     }
    //     string temp2 = Baseconv::DecToHex(Hex);
    //     if (temp2.length() % 2 != 0)
    //     {
    //         temp2 = "0" + temp2;
    //     }
    //     string basehex = Baseconv::HexToStr(temp2);
    //     // temp = Baseconv::DecToHex(temp);
    //     string my_alg = ShaAlgo(temp2);
    //     string their_alg = sha256(basehex);
    //     cout << "My Algorithm"
    //          << "\n"
    //          << my_alg << "\n";
    //     cout << "Their Algorithm"
    //          << "\n"
    //          << their_alg << "\n";
    //     cout << "hex "
    //          << "\n"
    //          << int(temp2[1]) << "\n";
    //     cout << "str "
    //          << "\n"
    //          << Baseconv::HexToStr(temp2) << "\n";
    //     cout << "i "
    //          << "\n"
    //          << i << "\n";
    //     if (my_alg == their_alg)
    //     {
    //         cout << "working\n\n";
    //     }
    //     else
    //     {
    //         // cout << "error " << i << " " << temp2 << " " << Baseconv::HexToStr(temp2) << " ";
    //         cout << temp2;
    //         break;
    //     }
    //     i++;
    // }
    string temp = "672";
    while (true)
    {
        std::cin >> temp;
        cout << ShaAlgo(temp) << "\n"
             << "\n";
        // cout << " " << sha256(Baseconv::HexToStr(temp)) << "\n";
        // cout << temp;
        // cout << Baseconv::HexToStr(temp);
    }

    // auto stop = std::chrono::high_resolution_clock::now();

    // auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    // cout << "\n"
    //      << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl;
    return 0;
}

string ShaAlgo(string Hash)
{
    string K[64] = {"01000010100010100010111110011000", "01110001001101110100010010010001", "10110101110000001111101111001111", "11101001101101011101101110100101", "00111001010101101100001001011011", "01011001111100010001000111110001", "10010010001111111000001010100100", "10101011000111000101111011010101", "11011000000001111010101010011000", "00010010100000110101101100000001", "00100100001100011000010110111110", "01010101000011000111110111000011", "01110010101111100101110101110100", "10000000110111101011000111111110", "10011011110111000000011010100111", "11000001100110111111000101110100", "11100100100110110110100111000001", "11101111101111100100011110000110", "00001111110000011001110111000110", "00100100000011001010000111001100", "00101101111010010010110001101111", "01001010011101001000010010101010", "01011100101100001010100111011100", "01110110111110011000100011011010", "10011000001111100101000101010010", "10101000001100011100011001101101", "10110000000000110010011111001000", "10111111010110010111111111000111", "11000110111000000000101111110011", "11010101101001111001000101000111", "00000110110010100110001101010001", "00010100001010010010100101100111", "00100111101101110000101010000101", "00101110000110110010000100111000", "01001101001011000110110111111100", "01010011001110000000110100010011", "01100101000010100111001101010100", "01110110011010100000101010111011", "10000001110000101100100100101110", "10010010011100100010110010000101", "10100010101111111110100010100001", "10101000000110100110011001001011", "11000010010010111000101101110000", "11000111011011000101000110100011", "11010001100100101110100000011001", "11010110100110010000011000100100", "11110100000011100011010110000101", "00010000011010101010000001110000", "00011001101001001100000100010110", "00011110001101110110110000001000", "00100111010010000111011101001100", "00110100101100001011110010110101", "00111001000111000000110010110011", "01001110110110001010101001001010", "01011011100111001100101001001111", "01101000001011100110111111110011", "01110100100011111000001011101110", "01111000101001010110001101101111", "10000100110010000111100000010100", "10001100110001110000001000001000", "10010000101111101111111111111010", "10100100010100000110110011101011", "10111110111110011010001111110111", "11000110011100010111100011110010"};

    // string Hash = "0100000000000000000000000000000000000000000000000000000000000000000000003ba3edfd7a7b12b27ac72c3e67768f617fc81bc3888a51323a9fb8aa4b1e5e4a29ab5f49ffff001d1dac2b7c";

    // string Hash = "6162636462636465636465666465666765666768666768696768696a68696a6b696a6b6c6a6b6c6d6b6c6d6e6c6d6e6f6d6e6f706e6f7071";

    string H1 = "01101010000010011110011001100111";
    string H2 = "10111011011001111010111010000101";
    string H3 = "00111100011011101111001101110010";
    string H4 = "10100101010011111111010100111010";
    string H5 = "01010001000011100101001001111111";
    string H6 = "10011011000001010110100010001100";
    string H7 = "00011111100000111101100110101011";
    string H8 = "01011011111000001100110100011001";

    Hash = Baseconv::HexToBin(Hash);
    // padding eg xxx100000
    Hash = Hash + "1";
    int len = Hash.length();
    int mod = len % 512;
    int zeros = (mod > 448) ? 896 + 64 - mod : 448 - mod;
    Hash = StrFunc::AddLetters(Hash, zeros);
    // last 64 bits length of string
    string leninbin = Baseconv::DecToBin(len - 1);
    Hash = Hash + StrFunc::AddLetters(leninbin, 64 - leninbin.length(), "0", 0);
    // updates padded length
    len = Hash.length() / 512;
    string blocks[len];

    for (int i = 0; i < len; i++)
    {
        blocks[i] = StrFunc::SubTxt(Hash, i * 512, ((i + 1) * 512 - 1));
    }

    string W[64];

    string a = H1;
    string b = H2;
    string c = H3;
    string d = H4;
    string e = H5;
    string f = H6;
    string g = H7;
    string h = H8;
    string T1;
    string T2;
    string Data;

    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            if (j < 16)
            {
                W[j] = StrFunc::SubTxt(blocks[i], j * 32, ((j + 1) * 32 - 1));
            }
            else
            {
                W[j] = AddMod(AddMod(sigma1(W[j - 2]), W[j - 7]), AddMod(sigma0(W[j - 15]), W[j - 16]));
            }
        }
        a = H1;
        b = H2;
        c = H3;
        d = H4;
        e = H5;
        f = H6;
        g = H7;
        h = H8;
        auto start = std::chrono::high_resolution_clock::now();
        for (int j = 0; j < 64; j++)
        {

            T1 = AddMod(AddMod(h, SIGMA1(e)), AddMod(AddMod(Choice(e, f, g), K[j]), W[j]));
            T2 = AddMod(SIGMA0(a), Major(a, b, c));

            h = g;
            g = f;
            f = e;
            e = AddMod(d, T1);
            d = c;
            c = b;
            b = a;
            a = AddMod(T1, T2);

            // Data = Data + Baseconv::BinToHex(a) + " " + Baseconv::BinToHex(b) + " " + Baseconv::BinToHex(c) + " " + Baseconv::BinToHex(d) + " " + Baseconv::BinToHex(e) + " " + Baseconv::BinToHex(f) + " " + Baseconv::BinToHex(g) + " " + Baseconv::BinToHex(h) + "\n";
        }
        H1 = Shafunc::AddMod(H1, a);
        H2 = Shafunc::AddMod(H2, b);
        H3 = Shafunc::AddMod(H3, c);
        H4 = Shafunc::AddMod(H4, d);
        H5 = Shafunc::AddMod(H5, e);
        H6 = Shafunc::AddMod(H6, f);
        H7 = Shafunc::AddMod(H7, g);
        H8 = Shafunc::AddMod(H8, h);
    }

    return (Baseconv::BinToHex(H1) + Baseconv::BinToHex(H2) + Baseconv::BinToHex(H3) + Baseconv::BinToHex(H4) + Baseconv::BinToHex(H5) + Baseconv::BinToHex(H6) + Baseconv::BinToHex(H7) + Baseconv::BinToHex(H8));
    // cout << blocks[0] << endl;
    // cout << endl;
    // cout << blocks[1] << endl;
    // cout << endl;
}