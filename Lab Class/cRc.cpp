#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    int i, j, k, l;
    //Get Frame
    int fs;
    cout << "\n Enter length of the data: ";
    cin >> fs;
    if (fs > 8)
    {
        cout << "Invalid Input";
        return 0;
    }
    int f[20];
    cout << "\n Enter the data:";
    for (i = 0; i < fs; i++)
    {
        cin >> f[i];
    }
    //Get Generator
    int gs;
    cout << "\n Enter the length of Generator(Divisor): ";
    cin >> gs;
    int g[20];

    cout << "\n Enter the Generator(Divisor):";
    for (i = 0; i < gs; i++)
    {
        cin >> g[i];
    }
    cout << "\n Sender Side:";
    //Append 0's
    int rs = gs - 1;
    cout << "\n Number of 0's to be appended: " << rs;
    for (i = fs; i < fs + rs; i++)
    {
        f[i] = 0;
    }
    int temp[20];
    for (i = 0; i < 20; i++)
    {
        temp[i] = f[i];
    }
    cout << "\n Message after appending 0's :";
    for (i = 0; i < fs + rs; i++)
    {
        cout << temp[i];
    }
    //Division
    for (i = 0; i < fs; i++)
    {
        j = 0;
        k = i;
        //check whether it is divisible or not
        if (temp[k] >= g[j])
        {
            for (j = 0, k = i; j < gs; j++, k++)
            {
                if ((temp[k] == 1 && g[j] == 1) || (temp[k] == 0 && g[j] == 0))
                {
                    temp[k] = 0;
                }
                else
                {
                    temp[k] = 1;
                }
            }
        }
    }
    //CRC
    int crc[15];
    for (i = 0, j = fs; i < rs; i++, j++)
    {
        crc[i] = temp[j];
    }
    cout << "\n CRC bits: ";
    for (i = 0; i < rs; i++)
    {
        cout << crc[i];
    }
    cout << "\n Transmitted Data: ";
    int tf[15];
    for (i = 0; i < fs; i++)
    {
        tf[i] = f[i];
    }
    for (i = fs, j = 0; i < fs + rs; i++, j++)
    {
        tf[i] = crc[j];
    }
    for (i = 0; i < fs + rs; i++)
    {
        cout << tf[i];
    }
    cout << "\n Receiver side : ";
    cout << "\n Received Data: ";
    for (i = 0; i < fs + rs; i++)
    {
        cout << tf[i];
    }
    for (i = 0; i < fs + rs; i++)
    {
        temp[i] = tf[i];
    }
    //Division
    for (i = 0; i < fs; i++)
    {
        j = 0;
        k = i;
        if (temp[k] >= g[j])
        {
            for (j = 0, k = i; j < gs; j++, k++)
            {
                if ((temp[k] == 1 && g[j] == 1) || (temp[k] == 0 && g[j] == 0))
                {
                    temp[k] = 0;
                }
                else
                {
                    temp[k] = 1;
                }
            }
        }
    }
    cout << "\n Remainder: ";
    int rrem[15];
    for (i = fs, j = 0; i < fs + rs; i++, j++)
    {
        rrem[j] = temp[i];
    }
    for (i = 0; i < rs; i++)
    {
        cout << rrem[i];
    }
    int flag = 0;
    for (i = 0; i < rs; i++)
    {
        if (rrem[i] != 0)
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "\n Since Remainder is 0, hence the"
                " Message Transmitted from Sender to Receiver is Correct";
    }
    else
    {
        cout << "\n Since Remainder is not 0,"
                " hence the Message Transmitted from Sender to Receiver contains Error";
    }
    getch();
}