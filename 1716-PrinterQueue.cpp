#include <iostream>
#include <queue>

using namespace std;

void computeQueue(priority_queue <int> &prioridad, queue <int> &cola, int position){
	int documento;
	while(1){
		documento = cola.front();
		cola.pop();
		if(position == 0){
			if(documento != prioridad.top()){
				position = prioridad.size() - 1;
				cola.push(documento);
			}else{
				break;
			}
		}else{
			position--;
			if(documento != prioridad.top())
				cola.push(documento);
			else
				prioridad.pop();
		}
	}
}

int main(){
	priority_queue <int> prioridad;
	queue <int> cola;
	int TC, position, size, documento;

	cin >> TC;

	while(TC--){

		while(!cola.empty())
			cola.pop();

		while(!prioridad.empty())
			prioridad.pop();

		cin >> size >> position;

		for(int i = 0; i < size; i++){
			cin >> documento;
			cola.push(documento);
			prioridad.push(documento);
		}

		computeQueue(prioridad, cola, position);

		cout << (size - prioridad.size()) + 1 << "\n";
	}

	return 0;
}