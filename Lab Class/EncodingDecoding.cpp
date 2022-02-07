#include <stdio.h>
#include <iostream>

int main()
{
    char msg[100], ch;
    int i, key;
    std::cout << "Enter a string to encrypt: ";
    gets(msg);
    std::cout << "Enter key: ";
    scanf("%d", &key);

    for (i = 0; msg[i] != '\0'; ++i)
    {
        ch = msg[i];
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            msg[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        }
    }
    std::cout << msg;

    return 0;
}
