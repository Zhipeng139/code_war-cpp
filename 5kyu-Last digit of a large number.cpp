#include <string>
#include <cmath>
int modulo(const std::string str){
  int a = 0;
  // its 4 beacause 10 = 2*5 -> p(2*5)=p(2)*p(5)=(2-1)*(5-1)=4
  for(int i = 0; i < str.length();i++) a = (a*10+str.at(i)-'0')%4;
  return a;
}
int last_digit(const std::string &str1, const std::string &str2) {
  if(str2=="0") return 1;
  if(str1=="0") return 0;
  int a = modulo(str2)==0?4:modulo(str2);
  int b = pow(str1.back()-'0',a);
  return b%10;
}
