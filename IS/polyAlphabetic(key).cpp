#include<bits/stdc++.h>

using namespace std;

int hashTable[128][20];

void hash_generator(int key){
    for (int i = 0; i < 128; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            hashTable[i][j] = (i + j + key) % 128;
        }
    }
}

int find(int ch, int position){
    for (int i = 0; i < 128; i++)
    {
        if(hashTable[i][position]==ch){
            return i;
        }
    }
    return 0;
}

void encrypt_decrypt(string str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        int ch = (int)str[i];
        int position = i % 20;
        str[i] = hashTable[ch][position];
    }

    cout << "CipherText :" << str << endl;

     for (int i = 0; str[i] != '\0'; i++)
    {
        int ch = (int)str[i];
        int position = i % 20;
        int key = find(ch,position);
        str[i]= (char)key;
    }
    cout << "PlainText :" << str << endl;
}




int main()
{
    

    int choice;
    // cout << "1.Encryption" << endl;
    // cout << "2.Decryption" << endl;
    // cout << "Enter choice :";
    // cin >> choice;
    // getchar();

    cout << "Enter PLainText: ";
    string inputStr;
    getline(cin, inputStr);

    cout << "Enter Key: ";
    int key;
    cin >> key;

    hash_generator(key);
    // if (choice == 1)
    // {
    //     encryption(inputStr);
    // }
    // else
    // {
    //     decryption(inputStr);
    // }
    encrypt_decrypt(inputStr);
}