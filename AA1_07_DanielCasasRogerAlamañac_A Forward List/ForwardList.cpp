#include "ForwardList.h"

// Constructor
ForwardList::ForwardList() {
	m_size = 0;
	m_first = nullptr;
	m_last = nullptr;
}
// Destructor
ForwardList::~ForwardList() {
	if (m_first != nullptr) delete m_first;
	if (m_last != nullptr) delete m_last;
}
// Inserts one element at the back of the list
void ForwardList::PushBack(int value) {
	Node* newNode;
	newNode->m_value = value;
	if (IsEmpty()) {
		m_first = newNode;
	}
	else {
		m_last->m_next = newNode;
	}
	m_last = newNode;
	m_size++;
}
// Removes last element at the back of the list
void ForwardList::PopBack() {
	if (IsEmpty()) {
		return;
	}
	if (m_first == m_last) {
		m_last = nullptr;
		m_first = nullptr;
	}
	else {
		Node* auxNode = m_first;
		while (auxNode->m_next != m_last) {
			auxNode = auxNode->m_next;
		}
		delete m_last;
		m_last = auxNode;
		m_last->m_next = nullptr;
	}
}
// Inserts one element at the front of the list
void ForwardList::PushFront(int value) {

}
// Removes first element at the front of the list
void ForwardList::PopFront() {
	Node* nodeToRemove = m_first;
	int valueToRemove = nodeToRemove->m_value;

	delete nodeToRemove;
	--m_size;
}
// Checks if the list is empty or not
bool ForwardList::IsEmpty() const {
	return m_size == 0;
}
// Returns the element at the front of the list
int ForwardList::Front() const {
	return m_first->m_value;
}
// Returns the element at the front of the list
int ForwardList::Back() const {
	return m_last->m_value;
}
// Returns the size of the list
int ForwardList::Size() const {
	return m_size;
}
// Removes all the elements from the list that are equal to value
void ForwardList::Erase(int value) {
	
}
// Inserts the element with value at a specific position within the list
void ForwardList::Insert(int value, int position) {

}
// Compares de content of lists l1 and l2. Returns true if both are equal, false otherwise.
bool operator==(const ForwardList& l1, const ForwardList& l2) {

}
// Outputs the elements of the list into an output stream object
std::ostream& operator<<(std::ostream& o, const ForwardList& l) {

}