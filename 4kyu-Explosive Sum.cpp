using ull = unsigned long long;
//Obsevasion: p(10,10) = 1+p(10,9) = 1+p(10,8)+p(1,9) = 1+p(10,7)+p(2,8)+p(1,9) = 1+p(10,7)+p(2,2)+p(1,1) = 1+p(10,7)+ [ 1+p(2,1) ] +p(1,1) = 1+p(10,7)+ [ 1+p(2,0)+p(1,1) ] +p(1,1) = ...
/* first version:
  we can notice that some cases is already computed
  ull recursive(unsigned int a, unsigned int b){
  if(a==1||b==1) return 1;
  if(a < b) return recursive(a,a);
  if(a == b) return 1+recursive(a,a-1);
  else return recursive(a-b,b)+recursive(a,b-1);
}*/
ull exp_sum(unsigned int n) {
  if(n <= 1) return 1;
  std::vector<ull> v(n+1,0);
  v[0] = 1;
  for(int i = 1; i < n; i++){
    for(int j = i; j <= n;j++) v[j] += v[j-i];
  }
  return v[n]+1;
}
