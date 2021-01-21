#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Person {
public:
	int age;
	string name;
	Person(int n, string str) : age(n), name(str) {}
};

bool compare(Person p1, Person p2) {
	return p1.age < p2.age;
};

int main() {
	vector<Person> people;

	int N;
	cin >> N;

	int age;
	string name;

	for (int i = 0; i < N; i++)
	{
		cin >> age >> name;
		people.push_back(Person(age, name));
	}
	stable_sort(people.begin(), people.end(), compare);

	for (int i = 0; i < N; i++)
	{
		cout << people[i].age << " " << people[i].name << "\n";
	}

	return 0;
}



/*
#include <iostream>
#include <string>
using namespace std;

class Node {
	friend class List;
private:
	int age;
	string name;
	Node *next;
	Node(int a, string nm, Node *n) : age(a), name(nm), next(n) {}
};

class List {
private:
	Node * head;
public:
	List() { head = NULL; }
	void addNode(int a, string n) {
		Node *temp = head;
		Node *data = new Node(a, n, NULL);
		if (head != NULL) {	
			if (head->age > a) {
				data->next = head;
				head = data;
			}
			else {
				while (temp->next != NULL && temp->next->age <= a) {
					temp = temp->next;
				};
				data->next = temp->next;
				temp->next = data;
			}
		}	
		else {
			head = data;
		}
	}
	void print() {
		Node * temp = head;
		while (temp != NULL) {
			cout << temp->age << " " << temp->name<<"\n";
			temp = temp->next;
		}
	}
};

int main() {
	List * list = new List();

	int N;
	int age;
	string name;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		list->addNode(age, name);
	}
	
	list->print();

	return 0;
}
*/
//왜 시간초과 뜨는지 이유 찾기