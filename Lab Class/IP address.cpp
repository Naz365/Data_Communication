#include<iostream>
using namespace std;
// Function to find out the Class
char findClass(const char s[])
{
    char a[4];
    int i=0;
    while(s[i]!='.')
    {
        a[i]=s[i];
        i++;
    }
    i--;
    int ip=0, j=1;
    while(i>=0)
    {
        ip=ip+(s[i]-'0')*j;
        j=j*10;
        i--;
    }
    if(ip>=1 && ip<=126)
        return 'A';
    else if(ip>=128 && ip<=191)
        return 'B';
    else if(ip>=192 && ip<=223)
        return 'C';
    else if(ip>=224 && ip<=239)
        return 'D';
    else
        return 'E';
}
// Function to separate Network ID and Host ID and print them
void separate(const char s[], char ip_C)
{
    char network[12], host[12];
    for (int k=0; k<12; k++)
        network[k]=host[k]='\0';
    if(ip_C=='A')
    {
        int i=0, j=0;
        while(s[j]!='.')
            network[i++]=s[j++];
        i=0;
        j++;
        while(s[j]!='\0')
            host[i++]=s[j++];
        cout<<"Network ID is "<<network<<endl;
        cout<<"Host ID is "<<host<<endl;
    }
    else if(ip_C=='B')
    {
        int i=0, j=0, dot=0;
        while(dot<2)
        {
            network[i++]=s[j++];
            if(s[j]=='.')
                dot++;
        }
        i=0;
        j++;
        while(s[j]!='\0')
            host[i++]=s[j++];
        cout<<"Network ID is "<<network<<endl;
        cout<<"Host ID is "<<host<<endl;
    }
    else if(ip_C=='C')
    {
        int i=0, j=0, dotCount=0;
        while(dotCount<3)
        {
            network[i++]=s[j++];
            if(s[j]=='.')
                dotCount++;
        }
        i=0;
        j++;
        while(s[j]!='\0')
            host[i++]=s[j++];
        cout<<"Network ID is "<<network<<endl;
        cout<<"Host ID is "<<host<<endl;
    }
    else
        cout<<"In this Class, IP address is not divided into Network and Host ID\n";
}
int main()
{
    int n;
    cout<<"Enter the number of characters in the IP address including dots: ";
    cin>>n;
    cout<<"Enter the IP address: ";
    char s[n];
    for(int i=0; i<n; i++)
        cin>>s[i];
    char ip_C=findClass(s);
    cout<<"Given IP address belongs to Class "<<ip_C<<endl;
    separate(s, ip_C);
    return 0;
}
