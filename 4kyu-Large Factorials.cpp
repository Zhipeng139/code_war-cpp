#include <string>
std::string factorial(int factorial){
  if(factorial < 0) return "";
  std::string ans = "";
  std::vector<int> resu;
  resu.push_back(1);
  int carry = 0;
  for(int i = 2; i <= factorial; i++){
    for(int j = 0; j < resu.size(); j++){
      int product = resu[j]*i+carry;
      resu[j] = product%10;
      carry = product/10;
    }
    while(carry){
      resu.push_back(carry%10);
      carry/=10;
    }
  }
  for(int i = resu.size()-1; i >= 0; i--){
    ans.push_back(resu[i]+'0');
  }
  return ans;
}