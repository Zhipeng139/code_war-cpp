#include <string>
#define member 13
class RomanHelper{
  public:
    std::string rome_num [member] = {"M","CM","D","CD","C","XC","L", "XL", "X", "IX", "V", "IV", "I"};
    unsigned int number [member] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  
    std::string to_roman(unsigned int n){
      std::string ans;
      for(int i = 0; i < member;i++){
        while(n >= number[i]){
          ans+=rome_num[i];
          n-=number[i];
        }
      }
      return ans;
    }
  
    int from_roman(std::string rn){
      std::string remain = rn;
      int ans = 0;
      for(int i = 0; i < member; i++){
        while(remain.find(rome_num[i])==0){
          ans+=number[i];
          int len = rome_num[i].length();
          remain = remain.substr(len,remain.length());
        }
      }
      return ans;
    }
} RomanNumerals;
