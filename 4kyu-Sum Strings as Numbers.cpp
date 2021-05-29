#include <string>

std::string sum_strings(const std::string& a, const std::string& b) {
  std::string ans;
  
  int size_a = a.length();
  int size_b = b.length();
  int max_size = size_a > size_b? size_a:size_b;
  int min_size = size_a < size_b? size_a:size_b;
  
  int carry = 0;
  for(int i = 0; i < min_size; i++){
    int value = a[size_a-i-1]+b[size_b-i-1]-(2*'0')+carry;
    ans = std::to_string(value%10)+ans;
    carry = value/10;
  }

  std::string remain = min_size==size_a?b:a;
  for(int i = min_size; i < max_size; i++){
    int value = remain[max_size-i-1]-'0'+carry;
    ans = std::to_string(value%10)+ans;
    carry = value/10;
  }
  if(carry) ans = std::to_string(carry)+ans;
  
  return ans;
}
