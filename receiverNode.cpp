#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<time.h>
#include<Windows.h>

using namespace std;


class RecieverNode {
	vector<queue<int>> Stack_Of_Queues_Of_Numbers;
	
public:

	void SetSize() {
		Stack_Of_Queues_Of_Numbers.resize(5);
	}
	int getSizeOfQueue(int id) {
		return Stack_Of_Queues_Of_Numbers[id].size();
	}
	
	void addRequestForResources(int Resource_id, int request_No) {
		//adds a new quest with number reqno to the resource sqn[rid]
		Stack_Of_Queues_Of_Numbers[Resource_id].push(request_No);
		

	}

	void serviceRequestatResource(int rid) {
		//services the request (dequeues) at front of sqn[rid]
		Stack_Of_Queues_Of_Numbers[rid].pop();
	}
	
	

	void printQueues() {
		//prints all queues line by line, numbers separated by spaces
		system("cls");
		int j = 0;
		while (j < Stack_Of_Queues_Of_Numbers.size()) {
			int Size = Stack_Of_Queues_Of_Numbers[j].size();
			for (int i = 0; i < Size; i++) {
				int front = Stack_Of_Queues_Of_Numbers[j].front();
				cout << front << " ";
				Stack_Of_Queues_Of_Numbers[j].pop();
				Stack_Of_Queues_Of_Numbers[j].push(front);
			}
			cout << endl;
			j++;
		}
		
	}
		
};



void Simulator() {
	RecieverNode node;
	cout << "Please enter 5 servicing rates : " << endl;
	int* Servicing_Rates_Keeper = new int[5];
	for (int i = 0; i < 5; i++) {
		cin >> Servicing_Rates_Keeper[i];
	}
	
	int counter_For_Iterations = 0;
	node.SetSize();

	for (int i = rand()%5; ; i = rand() % 5) {
		
		if (counter_For_Iterations >= 100) {
			
			for (int j = 0; j < 5; j++) {
				int counter_For_Time_For_Requests = Servicing_Rates_Keeper[i];
				if (node.getSizeOfQueue(i) != 1) {
					node.serviceRequestatResource(i);					
				}
				node.printQueues();
				Sleep(counter_For_Time_For_Requests);
			}
			Sleep(500);
		}
		else {
			cout << "Processing ... " << endl;
			system("cls");
		}
		// after 500 ms, request is added :
		node.addRequestForResources(i, Servicing_Rates_Keeper[i]);
		counter_For_Iterations++;
		
	}


}

int main() {
	Simulator();

	return 0;
}
