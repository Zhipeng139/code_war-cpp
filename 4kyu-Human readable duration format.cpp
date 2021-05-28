#include <string>
using namespace std;

string format_duration(int seconds) {
  if(seconds==0) return "now";
  if(seconds==1) return "1 second";
  string ans = "";
  int time[] = {365*24*60*60,24*60*60,60*60,60,1};
  string car[] = {"year","day","hour","minute","second"};
  for(int i = 0; i < 5; i++){
    if(seconds >= time[i]){
      int t = seconds/time[i];
      seconds%=time[i];
      ans+=(ans==""?"":(seconds==0?" and ":", "))+to_string(t)+" "+car[i]+(t > 1?"s":"");
    }
  }
  return ans;
}
