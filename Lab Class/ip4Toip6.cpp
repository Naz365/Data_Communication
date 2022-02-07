#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
class Sol
{
public:
    void str_spliting(string &s, vector<string> &g, char d)
    {
        istringstream sti(s);
        string temporary;
        while (getline(sti, temporary, d))
        {
            g.push_back(temporary);
        }
    }
    bool isIPv6Valid(string &s)
    {
        if (s.size() > 4 || s.size() == 0)
            return false;
        for (auto f : s)
        {
            if (f >= 'a' && f <= 'f')
                continue;
            else if (f >= 'A' && f <= 'F')
                continue;
            else if (f >= '0' && f <= '9')
                continue;
            else
                return false;
        }
        return true;
    }
    bool isIPv4Valid(string &s)
    {
        if (s.size() == 0)
            return false;
        if (s.size() > 1 && s[0] == '0')
            return false;
        if (s.size() > 3)
            return false;
        int i = 0;
        for (auto f : s)
        {
            if (f < '0' || f > '9')
                return false;
        }
        i = stoi(s);

        return i >= 0 && i <= 255;
    }

    bool IPv6(string &IP)
    {
        if (IP[0] == ':' || IP[IP.size() - 1] == ':')
            return false;
        vector<string> g;
        str_spliting(IP, g, ':');
        if (g.size() != 8)
            return false;
        for (auto s : g)
            if (!isIPv6Valid(s))
                return false;
        return true;
    }

    bool IPv4(string &IP)
    {
        if (IP[0] == '.' || IP[IP.size() - 1] == '.')
            return false;
        vector<string> g;
        str_spliting(IP, g, '.');
        if (g.size() != 4)
            return false;
        for (auto s : g)
        {
            if (!isIPv4Valid(s))
                return false;
        }
        return true;
    }

    string IpAddress(string IP)
    {
        if (IP.size() < 7)
        {
            return "Neither";
        }
        if (IPv4(IP))
        {
            return "IPv4";
        }
        if (IP.size() < 15)
        {
            return "neither IPv4 or IPv6";
        }
        if (IPv6(IP))
        {
            return "IPv6";
        }
        return "neither IPv4 or IPv6";
    }
};
int main()
{
    Sol p;
    string s;
    cout << "Enter an IP address: ";
    cin >> s;
    cout << s << " is " << p.IpAddress(s);
}
