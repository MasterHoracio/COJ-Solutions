#include <cstdio>
#include <cstring>
#include <map>

using namespace std;

const int maxn = 1e5 + 10;

int main(){
	int n, circle[maxn], sum, sz, curr, ans, tmp, visited[maxn], izq, der;
	map <int, int>::iterator it;
	map <int, int> custom_map;
	bool hascircle;
	
	while(scanf("%d",&n) != EOF){
		
		memset(visited, 0, sizeof(visited));
		izq = der = ans = sum = 0;
		
		for(int i = 0; i < n; i++){
			scanf("%d",&circle[i]);
			sum += circle[i];
		}
		
		sz = sum / 3;
		
		curr = circle[0];
		hascircle = false;
		
		while(!hascircle){
			if(curr == sz){
				custom_map[izq] = der;
				++der;
				if(der == n)
					der = 0;
				curr += circle[der];
			}
			
			if(curr > sz){
				curr -= circle[izq++];
				if(izq == n)
					hascircle = true;
			}else{
				++der;
				if(der == n)
					der = 0;
				curr += circle[der];
			}
			
			
		}
		
		for(it = custom_map.begin(); it != custom_map.end(); it++){
			if(visited[it->first] == 0 && custom_map[it->second + 1] && visited[it->second + 1] == 0){
				tmp = custom_map[it->second + 1];
				if(custom_map[tmp + 1] && visited[tmp + 1] == 0){
					++ans;
					visited[tmp + 1] = 1;
					visited[it->first] = 1;
					visited[it->second + 1] = 1;
				}
			}
		}
		
		printf("%d\n",ans);
		custom_map.clear();
	}
	
	return 0;
}
