#include<iostream>
#include<cmath>
using namespace std;
struct Node {
	int data;
	Node* next;
};
struct List {
	Node* pHead;
	Node* pTail;
};
void creatList(List &l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
Node* createNode(int data) {
	Node* p = new Node();
	if (p == NULL) {
		return NULL;
	}
	else {
		p->data = data;
		p->next = NULL;
	}
	return p;
}
void addNodeFirst(List &l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->next = l.pHead;
		l.pHead = p;
	}
}
void addNodeLastInList(List &l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->next = p;
		l.pTail = p;
	}
}
void addNode_P_After_node_Q(List &l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	int data;
	cout << "Nhap du lieu cho node q" << endl;
	cin >> data;
	Node* q = createNode(data);
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		Node* h = createNode(p->data);
		if (q->data == k->data) {
			h->next = k->next;
			k->next = h;
		}
	}
}
void addNode_p_Before_node_Q(List &l, Node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	int data;
	cout << "Nhap du lieu cho node q" << endl;
	cin >> data;
	Node* q = createNode(data);
	Node* g = new Node();
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		Node* h = createNode(p->data);
		if (q->data == k->data) {
			h->next = g->next;
			g->next = h;
		}
		g = k;
	}
}
void addNode_p_inloaction_of_list(List& l, Node* p, int location) {
	int n = 0;
	Node* g = new Node();
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		++n;
	}
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	if (location == 1) {
		addNodeFirst(l, p);
	}
	if (location == n + 1) {
		addNodeLastInList(l, p);
	}
	if (location >= 2 && location <= n) {
		int count = 0;
		for (Node* k = l.pHead; k != NULL; k = k->next) {
			++count;
			if (count == location) {
				p->next = k;
				g->next = p;
			}
			g = k;
		}
		
	}
}
void showInfor(List l) {
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		cout << k->data << " ";
	}
}
void deletMemories(List &l) {
	if (l.pHead == NULL)
	{
		return;
	}
	while (l.pHead != NULL)
	{
		Node* p = l.pHead;
		l.pHead = l.pHead->next;
		delete p;
	}
}
void deleteFirstNode(List &l) {
	if (l.pHead == NULL) {
		return;
	}
	Node* p = l.pHead;
	l.pHead = l.pHead->next;
	delete p;
}
void deleteLastNode(List &l) {
	if (l.pHead == NULL) {
		return;
	}
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		if (k->next == l.pTail) {
			delete l.pTail;
			k->next = NULL;
		}
	}
}
void deleteNodeWithValue(List &l, int x) {
	if (l.pHead == NULL) {
		return;
	}
	if (l.pHead->data == x) {
		deleteFirstNode(l);
	}
	if (l.pTail->data == x) {
		deleteLastNode(l);
	}
	Node* g = new Node();
	for (Node* k = l.pHead; k != NULL; k = k->next) {
		Node* h = createNode(x);
		Node* q = createNode(k->data);//tao ra mot dia chi moi cho k
		if (q->data == h->data) {
			g->next = k->next;
			delete q;
		}
		g = k;
		
	}
}
void menu() {
	List l;
	creatList(l);
	int n;
	int choose;
	int data;
	do
	{
		cout << "\n**************************MENU***************************" << endl;
		cout << "1.add node in list" << endl;
		cout << "2.add node last in List" << endl;
		cout << "3.add node p after Node q" << endl;
		cout << "4.add Node p before Node q" << endl;
		cout << "5.add Node p in location of the list" << endl;
		cout << "6.delete the firstNode" << endl;
		cout << "7.delete the lastNode" << endl;
		cout << "8.delete Node with value" << endl;
		cout << "9.show information in List" << endl;
		cout << "0.exist!" << endl;
		cout << "you choose ";
		cin >> choose;
		switch (choose) {
		case 0: {
			cout << "program is end" << endl;
			break;
		}
		case 1: {
			cout << "Nhap so luong node can nhap" << endl;
			cin >> n;
			cout << "Nhap du lieu cho cac  node" << endl;
			for (int i = 0; i < n; ++i) {
				cin >> data;
				Node* p = createNode(data);
				addNodeFirst(l, p);
			}
			break;
		}
		case 2: {
			cout << "Nhap so luong node can nhap" << endl;
			cin >> n;
			cout << "Nhap du lieu cho cac  node" << endl;
			for (int i = 0; i < n; ++i) {
				cin >> data;
				Node* p = createNode(data);
				addNodeLastInList(l, p);
			}
			break;
		}
		case 3: {
			cout << "khoi tao danh sach" << endl;
			cout << "Nhap so luong node can nhap" << endl;
			cin >> n;
			cout << "Nhap du lieu cho cac  node" << endl;
			for (int i = 0; i < n; ++i) {
				cin >> data;
				Node* p = createNode(data);
				addNodeLastInList(l, p);
			}
			int x;
			cout << "Nhap du lieu cho node can chen" << endl;
			cin >> x;
			Node* p = createNode(x);
			addNode_P_After_node_Q(l, p);
			break;
		}
		case 4: {
			cout << "khoi tao danh sach" << endl;
			cout << "Nhap so luong node can nhap" << endl;
			cin >> n;
			cout << "Nhap du lieu cho cac  node" << endl;
			for (int i = 0; i < n; ++i) {
				cin >> data;
				Node* p = createNode(data);
				addNodeLastInList(l, p);
			}
			int x;
			cout << "Nhap du lieu cho node can chen" << endl;
			cin >> x;
			Node* p = createNode(x);
			addNode_p_Before_node_Q(l, p);
			break;
		}
		case 5: {
			cout << "khoi tao danh sach" << endl;
			cout << "Nhap so luong node can nhap" << endl;
			cin >> n;
			cout << "Nhap du lieu cho cac  node" << endl;
			for (int i = 0; i < n; ++i) {
				cin >> data;
				Node* p = createNode(data);
				addNodeLastInList(l, p);
			}
			int location;
			cout << "Nhap vi tri can chen" << endl;
			cin >> location;
			int x;
			cout << "Nhap du lieu cho node can chen" << endl;
			cin >> x;
			Node* p = createNode(x);
			addNode_p_inloaction_of_list(l, p, location);
			break;
		}
		case 6: {
			deleteFirstNode(l);
			break;
		}
		case 7: {
			deleteLastNode(l);
			break;
		}
		case 8: {
			int x;
			cout << "Nhap gia tri cua node can xoa" << endl;
			cin >> x;
			deleteNodeWithValue(l, x);
			break;
		}
		case 9: {
			showInfor(l);
			deletMemories(l);
			break;
		}
		default: {
			cout << "please choose the option in list" << endl;
			break;
		}
		}
	} while (choose != 0);
}
int main() {
	menu();
	return 0;
}