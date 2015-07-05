// Cracking the Coding Interview (9.1)
// A child is running up a staircase with n steps, and can hop either 1 step, 
// 2 steps, or 3 steps at a time. Implement a method to count how many possible
// ways the child can run up the stairs.

#include <iostream>
using namespace std;

int count_poss(int n, int* poss) {
	if (n < 0) {
		return 0;
	}

	if (n == 0) {
		return 1;
	}

	poss[n] = count_poss(n-1, poss) + count_poss(n-2, poss) + count_poss(n-3, poss);
	return poss[n];

}

int main () {
	int num_steps;

	cout << "Enter number of steps: \n";
	cin >> num_steps;

	int *poss = new int[num_steps+1];

	int num_poss = count_poss(num_steps, poss);

	cout << "Number of possible ways: " << num_poss << endl;

}


