#include <string>
#include <boost/range/adaptor/reversed.hpp>
#include "ip_filter.h"

ipset ip;

int main() {
    std::string ln;
    
    while (std::getline(std::cin, ln)) {
        int a = chk(ln);
        if (a == 1) {
          std::cout << "Line format error at line " << lnum << std::endl;
          return 1;
        } else if (a == 2) {
          std::cout << "IP address format error at line " << lnum << std::endl;
          return 1;
        }
        if (parseIP(ln, ip)) {
          std::cout << "Broadcast IP address forbidden at line " << lnum << std::endl;
          return 1;
        }
    }
    
    for (auto const& val : boost::adaptors::reverse(ip)) {
        printIP(val);
    }
    for (auto const& val : boost::adaptors::reverse(ip)) {
        if (getOct(val,1) == 1)
            printIP(val);
    }
    for (auto const& val : boost::adaptors::reverse(ip)) {
        if ((getOct(val, 1) == 46) && (getOct(val, 2) == 70))
            printIP(val);
    }
    for (auto const& val : boost::adaptors::reverse(ip)) {
        if ((getOct(val, 1) == 46) || (getOct(val, 2) == 46) || (getOct(val, 3) == 46) || (getOct(val, 4) == 46))
            printIP(val);
    }

    return 0;
}