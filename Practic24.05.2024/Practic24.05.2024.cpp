#include <iostream>

using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

void insertFront(node** head, int d) {
	node* newNode = new node;

	newNode->data = d;
	newNode->next = *head;
	newNode->prev = nullptr;
	if (*head)
		(*head)->prev = newNode;
	*head = newNode;
}
void insertEnd(node** head, int d) {
	node* newNode = new node;

	newNode->data = d;
	newNode->next = nullptr;

	if (*head == nullptr) {
		newNode->prev = nullptr;
		*head = newNode;
		return;
	}

	node* temp = *head;
	while (temp->next != nullptr)
		temp = temp->next;

	temp->next = newNode;
	newNode->prev = temp;
}
void insertAfter(node* prev_node, int d) {
	node* newNode = new node;
	newNode->data = d;

	newNode->next = prev_node->next;
	prev_node->next = newNode;
	newNode->prev = prev_node;

	if (newNode->next != nullptr)
		newNode->next->prev = newNode;
}

void deleteNode(node** head, node* delNode) {
	if (*head == nullptr || delNode == nullptr) return;

	if (delNode == *head)
		*head = delNode->next;

	if (delNode->next != nullptr)
		delNode->next->prev = delNode->prev;

	if (delNode->prev != nullptr)
		delNode->prev->next = delNode->next;

	free(delNode);
}

void showNodes(node* n) {
	node* temp;
	while (n != nullptr) {
		cout << n->data << " ";
		temp = n;
		n = n->next;
	}
	cout << endl;
}



class Human {
public:
	string name;
	Human(string n) {
		name = n;
		cout << "constr Human\n";
	}
	~Human() {
		delete nums;
		cout << "Human\n";
	}
protected:
	int* nums = new int[12];
	int age;

	void Walk() {
		cout << "walk" << endl;
	}
};

class Employee : private Human {
public:
	int* nums1 = new int[50];
	string position;
	float salary;
	Employee(string pos, float sal, string n) : Human(n) {
		position = pos;
		salary = sal;
		cout << "constr Employee\n";
	}

	void Work() {
		cout << "work" << age << name; Walk();
	}
	~Employee() {
		delete nums1;
		delete nums;
		cout << "Employee\n";
	}
};


int main()
{
	//node* head = nullptr;

	//insertEnd(&head, 7);	// 7
	//insertFront(&head, 15);	// 15 7
	//insertFront(&head, 2);	// 2 15 7
	//insertAfter(head->next, 4);	// 2 15 4 7

	//insertAfter(head, 30);	// 2 30 15 4 7

	//showNodes(head);

	//deleteNode(&head, head->next->next);

	//showNodes(head);

	Employee empl("Cashier", 45000, "Ivan");
	
}

//
//class BaseClass {
//
//};
//// агрегация
//class TestClass {
//	BaseClass* bClass;
//};
//// композиция
//class TestClass2 {
//	TestClass* testClass;
//};
//
//class A {
//	int a;
//public:
//	//-------------------------
//	class B {
//		int b;
//	public:
//		void funcB();/* { cout << "function B"; funcA(); }*/
//	};
//	//-------------------------
//
//public:
//	void static staticFuncA() { cout << "static function A"; }
//	void funcA();/* { cout << "function A"; }*/
//};
//
//void A::funcA() {
//	cout << "function A";
//}
//void A::B::funcB() {
//	cout << "function B";
//}

template <class T>
class TemplateClass {
protected:
	T test1;
	void testMethod(T t){}
};

class ChildClass : TemplateClass<int> {

};

template<class T>
class ChildClass2 : TemplateClass<T> {

};

template <class T, class T1>
class ChildClass3 : TemplateClass<T> {

};