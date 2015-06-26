#include <iostream>
using namespace std;

struct Node {
	char value;
	Node *next;
};

bool isPali(Node *head) {
	Node *fst = head;
	Node *snd = head;

	while (fst->next && fst->next->next) {
		fst = fst->next;
		fst = fst->next;
		snd = snd->next;
	}

	fst = snd->next;

	Node *new_head = NULL;
	Node *temp;

	while(fst) {
		temp = new Node;
		temp->value = fst->value;
		temp->next = new_head;
		new_head = temp;
		fst = fst->next;
	}

	while (new_head) {
		if (head->value != new_head->value) {
			return false;
		}
		head = head->next;
		new_head = new_head->next;
	}

	return true;
}


int main() {

	char c;

	Node *head = NULL;
	Node *temp = head;

	while (cin >> c) {
		temp = new Node;
		temp->value = c;
		temp->next = head;
		head = temp;
	}

	temp = head;

	if(isPali(head)) {
		cout << "IS A PALINDROME! YEAAAAH!\n";
	} else {
		cout << "NOT A PALINDROME! BOOOOOO!\n";
	}

	return 0;
}