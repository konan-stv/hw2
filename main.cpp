#include <iostream>
#include <set>
#include <string>
#include <tuple>
#include <algorithm>
#include <boost/range/adaptor/reversed.hpp>

std::multiset <unsigned long> ip;

auto sep(std::string &l) {
    l.erase(l.find('\t'));
    unsigned char a[4];
    int i = 0;
    while (l.length()) [&a, &i](std::string &s) {a[i++]=stol(s.substr(0, s.find('.'))); s.erase(0, s.find('.')); s.erase(0, 1);}(l);
    return std::make_tuple(a[0], a[1], a[2], a[3]);
}

int main() {
    std::string ln;
    
    while (std::getline(std::cin, ln)) {
        unsigned char a,b,c,d;
        std::tie(a, b, c, d) = sep(ln);
        //printf("%d %d %d %d\r\n", a, b, c, d);
        ip.insert((a<<24)+(b<<16)+(c<<8)+d);
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