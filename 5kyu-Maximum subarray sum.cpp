#include <vector>

int maxSequence(const std::vector<int>& arr){
  if(arr.size()==0) return 0;
  int help = arr[0], ans = arr[0];
  for(int i = 1; i < arr.size(); i++){
    help = std::max(arr[i],help+arr[i]);
    ans = std::max(help,ans);
  }
  return ans>=0?ans:0;
}
