#include <string>
bool is_operator(char ch){
  return ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^';   
}
int priority(char ch){
  if(ch == '^') return 2;
  if(ch == '*' || ch == '/') return 3;
  if(ch == '+' || ch == '-') return 4;
  return 5;
}
bool greater(char var, char cmp){
  return priority(cmp) <= priority(var); 
}
std::string to_postfix(std::string infix) {
  std::stack<char> s;
  std::string ans;
  for(char ch: infix){
    if(ch>= '0' && ch <= '9') ans+=ch;
    else if(is_operator(ch)){
      while(!s.empty()&& greater(ch,s.top())){
        ans+=s.top();
        s.pop();
      }
      s.push(ch);
    }
    else if(ch == '(') s.push(ch);
    else if(ch == ')'){
      while(!s.empty() && s.top()!='('){
        ans+=s.top();
        s.pop();
      }
      s.pop();
    }
  }
  while(!s.empty()){
    ans+=s.top();
    s.pop();
  }
  return ans;
}