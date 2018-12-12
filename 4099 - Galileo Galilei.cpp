#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
double epsilon = 0.000000001;
int answer = 0;

double distance(pii nuno, pii ndos){
  return sqrt(pow((nuno.first - ndos.first),2) + pow((nuno.second - ndos.second),2));
}

bool check(pii a, pii b, pii c){
  double duno = distance(a, b);
  double ddos = distance(b, c);
  double dtre = distance(c, a);
  if(fabs(pow(duno,2)-(pow(ddos,2)+pow(dtre,2))) <= epsilon)
    return true;
  if(fabs(pow(ddos,2)-(pow(duno,2)+pow(dtre,2))) <= epsilon)
    return true;
  if(fabs(pow(dtre,2)-(pow(duno,2)+pow(ddos,2))) <= epsilon)
    return true;
  return false;
}

void solve(pii cords[], int n, int r, int index, pii data[], int i){
  if(index == r){
    if(check(data[0],data[1],data[2]))
      answer += 1;
    return;
  }
  if(i >= n){
    return;
  }
  data[index] = cords[i];
  solve(cords, n, r, index + 1, data, i + 1);
  solve(cords, n, r, index, data, i + 1);
}

int main(){
  pii cords[301], data[3];
  int n;

  scanf("%d",&n);
  for(int i = 0; i < n; i++)
    scanf("%d %d",&cords[i].first, &cords[i].second);
  solve(cords, n, 3, 0, data, 0);
  printf("%d\n",answer);

  return 0;
}
