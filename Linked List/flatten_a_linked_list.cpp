/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

// Approach 1

Node* flattenLinkedList(Node* head) 
{
	Node* curr = head;
	vector<int> v;

	while(curr) {
		Node* temp = curr;
		while(temp) {
			v.push_back(temp -> data);
			temp = temp -> child;
		}

		curr = curr -> next;
	}

	sort(v.begin(), v.end());

	Node* newHead = new Node(v[0]);
	Node* temp = newHead;

	for(int i=1; i<v.size(); i++) {
		Node* newNode = new Node(v[i]);
		temp -> child = newNode; 
		temp = temp -> child;
	}

	return newHead;
}

// Approach 2

Node* merge(Node*& head1, Node* &head2) {
	Node* dummyNode = new Node(-1);
	Node* temp = dummyNode;

	while(head1 != NULL && head2 != NULL) {
		if(head1 -> data < head2 -> data) {
			temp -> child = head1;
			head1 = head1 -> child;
			temp = temp -> child;
		}
		else {
			temp -> child = head2;
			head2 = head2 -> child;
			temp = temp -> child;
		}
	}

	if(head1) temp -> child = head1;
	if(head2) temp -> child = head2;

	return dummyNode -> child;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> next == NULL) return head;

	Node* newHead = flattenLinkedList(head -> next);
	head = merge(head, newHead);
	return head;
}

