#include <stdio.h>
#include <iostream>

using namespace std;

string plainText, cipherText, output;
void encryption()
{
    int key;
    cout << "Enter your key to encrypt : ";
    cin >> key;
    // cout << "!!!!!!!!!!!!!!!!" << endl;
    // if (key < 0)
    // {
    //     key = key + 25;
    // }
    for (int i = 0; plainText[i] != '\0'; i++)
    {

        if (plainText[i] != ' ')
        {
            plainText[i] = plainText[i] + key;
        }

    }
}

void decryption()
{
    int key;
    cout << "Enter your key to decrypt : ";
    cin >> key;
    // if (key < 0)
    // {
    //     key = key + 25;
    // }
    for (int i = 0; cipherText[i] != '\0'; i++)
    {
        if (cipherText[i] != ' ')
        {
            cipherText[i] = cipherText[i] - key;
        }
    }
}

int main()
{

    int choice;
    cout << "1. PlainText->CipherText" << endl;
    cout << "2. CipherText->PlainText" << endl;
    cin >> choice;
    getchar();
    if (choice == 1)
    {
        getline(cin,plainText);
        encryption();
        cout << "CipherText: " << plainText << endl;
    }
    else
    {
        getline(cin, cipherText);
        decryption();
        cout << "PlainText: " << cipherText << endl;
    }
}