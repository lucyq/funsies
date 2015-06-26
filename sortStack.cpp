/* 
 *	Sorts a stack using just another stack..maybe (no, DEFINITELY...to our knowledge)
 *	time complexity kinda sucks but whatever
 */


#include <iostream>
#include <stack>
using namespace std;

void printStack(stack<int> stk);
void sortStack(stack<int> stk);


int main () {

	stack<int> stk;
	int num;

	while (cin >> num) {
		stk.push(num);
	}

	// for (int i = 0; i < (int)stk.size(); i++) {
	// 	cout << stk.top();
	// 	stk.pop();
	// }
	// cout << endl;
	sortStack(stk);

}


void sortStack(stack<int> stk) {
	stack<int> temp_stk;

	int size = stk.size();
	int temp;
	bool sorted = false;

	while(!sorted) {

		while (!stk.empty() && (temp_stk.empty() || stk.top() <= temp_stk.top())) {
			int elem = stk.top();
			stk.pop();
			temp_stk.push(elem);
		}

		if ((int)temp_stk.size() == size) {
			sorted = true;
			while(!temp_stk.empty()) {
				stk.push(temp_stk.top());
				temp_stk.pop();
			}
			break;
		}

		if (stk.top() > temp_stk.top()) {
			temp = stk.top();
			stk.pop();
		}

		while(!temp_stk.empty() && temp_stk.top() < temp) {

			stk.push(temp_stk.top());
			temp_stk.pop();
		}

		temp_stk.push(temp);


	}

	printStack(stk);
}

void printStack(stack<int> stk) {
	cout << "PRINTING STACK OF SIZE: " << stk.size() << endl;
	while(!stk.empty()){
		cout << stk.top() << " ";
		stk.pop();
	}
	cout << endl;
}
