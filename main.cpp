#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <algorithm>
#include <boost/range/adaptor/reversed.hpp>

std::multiset <unsigned long> ip;
int lnum = 1;

auto sep(std::string &l) {
    l.erase(l.find('\t'));
    unsigned char a[4];
    int i = 0;
    while (l.length()) [&a, &i](std::string &s) {a[i++]=stol(s.substr(0, s.find('.'))); s.erase(0, s.find('.')); s.erase(0, 1);}(l);
    return std::make_tuple(a[0], a[1], a[2], a[3]);
}

int ccount(std::string l, char c) {
  if (l.find(c) == std::string::npos) return 0;
  else return ccount(l.substr(l.find(c)+1), c) + 1;
}

int chk(std::string &l) {   // returns 1 in case of error
    if (ccount(l, '\t') != 2) {
        std::cout << "Line format error at line " << lnum << std::endl;
        return 1;
    }
    if (ccount(l.substr(0, l.find('\t')), '.') != 3) {
        std::cout << "IP address format error at line " << lnum << std::endl;
        return 1;
    }
    return 0;
}

int main() {
    std::string ln;
    
    while (std::getline(std::cin, ln)) {
        if (chk(ln)) return 0;
        unsigned char a,b,c,d;
        std::tie(a, b, c, d) = sep(ln);
        if (!d) {
            std::cout << "Broadcast IP address forbidden at line " << lnum << std::endl;
            return 0;
        }
        //printf("%d %d %d %d\r\n", a, b, c, d);
        ip.insert((a<<24)+(b<<16)+(c<<8)+d);
        lnum++;
    }
    
    for (auto const& val : boost::adaptors::reverse(ip)) {
        std::cout << ((val>>24)&0xFF) << '.' << ((val>>16)&0xFF) << '.' << ((val>>8)&0xFF) << '.' << (val&0xFF) << std::endl;
    }
    for (auto const& val : boost::adaptors::reverse(ip)) {
        if (((val>>24)&0xFF) == 1)
            std::cout << ((val>>24)&0xFF) << '.' << ((val>>16)&0xFF) << '.' << ((val>>8)&0xFF) << '.' << (val&0xFF) << std::endl;
    }
    for (auto const& val : boost::adaptors::reverse(ip)) {
        if ((((val>>24)&0xFF) == 46) && (((val>>16)&0xFF) == 70))
            std::cout << ((val>>24)&0xFF) << '.' << ((val>>16)&0xFF) << '.' << ((val>>8)&0xFF) << '.' << (val&0xFF) << std::endl;
    }
    for (auto const& val : boost::adaptors::reverse(ip)) {
        if ((((val>>24)&0xFF) == 46) || (((val>>16)&0xFF) == 46) || (((val>>8)&0xFF) == 46) || ((val&0xFF) == 46))
            std::cout << ((val>>24)&0xFF) << '.' << ((val>>16)&0xFF) << '.' << ((val>>8)&0xFF) << '.' << (val&0xFF) << std::endl;
    }

    return 0;
}