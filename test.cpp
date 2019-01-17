#include <string>
#include <boost/range/adaptor/reversed.hpp>
#include "ip_filter.h"
#include <gtest/gtest.h>

TEST(hwTest, TESTccount) {
  std::string s = "sthdytjdfyjdyjd";
  EXPECT_EQ(ccount(s, 'd'), 4) << "ccount returns wrong count: " << ccount(s, 'd') << std::endl;
  EXPECT_EQ(ccount(s, '5'), 0) << "ccount wrong zero condition: " << ccount(s, '5') << std::endl;
}

TEST(hwTest, TESTsep) {
  std::string s = "192.168.32768.0\t1\t1\n";
  uint8_t a,b,c,d;
  std::tie(a, b, c, d) = sep(s);

  EXPECT_EQ(a, 192) << "sep error 1: a=" << a << std::endl;
  EXPECT_EQ(b, 168) << "sep error 2: b=" << b << std::endl;
  EXPECT_EQ(c, 0) << "sep error 3: c=" << c << std::endl;
  EXPECT_EQ(d, 0) << "sep error 4: d=" << d << std::endl;
}

TEST(hwTest, TESTchk) {
  std::string s = "192.168.32768.0\t1\t1\n";
  EXPECT_EQ(chk(s), 0) << "chk false alarm";
  s = "192.168.32768.0\t11\n";
  EXPECT_EQ(chk(s), 1) << "chk TAB";
  s = "192168.32768.0\t1\t1\n";
  EXPECT_EQ(chk(s), 2) << "chk DOT";
}

TEST(hwTest, TESTgetOct) {
  EXPECT_EQ(getOct(0x12345678, 2), 0x34);
}

TEST(hwTest, TESTpackIP) {
  EXPECT_EQ(packIP(0x12, 0x34, 0x56, 0x78), 0x12345678);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
