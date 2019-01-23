#include <string>
#include <iostream>
#include <set>
#include <tuple>
#include <algorithm>

using ipset = std::multiset <uint32_t>;

int lnum = 1;

auto sep(std::string &l) {
    l.erase(l.find('\t'));
    uint8_t a[4];
    int i = 0;
    auto lf = [&a, &i](std::string &s) {
      a[i++]=stol(s.substr(0, s.find('.'))); 
      s.erase(0, s.find('.')); 
      s.erase(0, 1);
    };
    while (l.length()) lf(l);
    return std::make_tuple(a[0], a[1], a[2], a[3]);
}

int ccount(std::string l, char c) {
  if (l.find(c) == std::string::npos) return 0;
  else return ccount(l.substr(l.find(c)+1), c) + 1;
}

int chk(std::string &l) {   // returns 1 in case of syntax error
    if (ccount(l, '\t') != 2)
        return 1;
    if (ccount(l.substr(0, l.find('\t')), '.') != 3)
        return 2;
    return 0;
}

void printIP(uint32_t v) {
    std::cout << ((v>>24)&0xFF) << '.' << ((v>>16)&0xFF) << '.' << ((v>>8)&0xFF) << '.' << (v&0xFF) << std::endl;
}

uint8_t getOct(uint32_t v, uint8_t o1) {   // o is 1-based, MSO (left) is 1st
    return (v>>((4-o1)*8))&0xFF;
}

uint32_t packIP(uint8_t a, uint8_t b, uint8_t c, uint8_t d) {
    return (a<<24)+(b<<16)+(c<<8)+d;
}

int parseIP(std::string& l, ipset& i) {
    auto [a, b, c, d] = sep(l);
    if (!d)
        return 1;
    i.insert(packIP(a, b, c, d));
    lnum++;
    return 0;
}