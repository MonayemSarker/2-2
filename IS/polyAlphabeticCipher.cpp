#include <bits/stdc++.h>
using namespace std;

int hashTable[127][5];

void encryption(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int ch = (int)str[i];
        int position = i % 5;
        str[i] = hashTable[ch][position];
    }

    cout << "CipherText :" << str << endl;
}

int find(int ch, int position){
    for (int i = 0; i < 127; i++)
    {
        if(hashTable[i][position]==ch){
            return i;
        }
    }
    return 0;
}

void decryption(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int ch = (int)str[i];
        int position = i % 5;
        int key = find(ch,position);
        str[i]= (char)key;
    }
    cout << "PlainText :" << str << endl;
}

int main()
{
    for (int i = 0; i < 127; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            hashTable[i][j] = (i + j) % 127;
        }
    }

    int choice;
    cout << "1.Encryption" << endl;
    cout << "2.Decryption" << endl;
    cout << "Enter choice :";
    cin >> choice;
    getchar();

    string inputStr;
    getline(cin, inputStr);

    if (choice == 1)
    {
        encryption(inputStr);
    }
    else
    {
        decryption(inputStr);
    }
}