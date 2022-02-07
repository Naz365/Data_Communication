#include <iostream>
#include <string>

using namespace std;

int main()
{
    // KEYS TO BE USED
    const int ROT13 = 13, ROT7 = 7;

    cout << endl
         << " Enter a string of text. Press ENTER when finished. " << endl
         << endl;
    cout << " Text: ";

    string text;
    getline(cin, text);

    string encText = text; // text to encrypt
    int key = ROT13;

    for (size_t i = 0; i < encText.size(); i++)
    {
        encText[i] = encText[i] + key;

        if ((i + 1) % 5 == 0)
        {
            if (key == ROT7)
                key = ROT13;
            else
                key = ROT7;
        }
    }

    cout << endl
         << "Encrypted text is " << endl
         << encText << endl;
    string decText = encText; // Text to decrypt

    for (size_t i = 0; i < decText.size(); i++)
    {
        decText[i] = decText[i] - ROT13;

        if (decText[i] % 5 == 0)
            decText[i] = decText[i] - ROT7;
        //decText;
    }

    cout << endl
         << "Decrypted text is " << endl
         << decText << endl
         << endl;
    return 0;
}
