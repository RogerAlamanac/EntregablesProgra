#include <iostream>
#include "ForwardList.h"
int main()
{
	ForwardList list;
	if (list.IsEmpty()) {
		std::cout << "LIST IS EMPTY RIGHT NOW." << std::endl;
	}

	std::cout << "PushFront -> 29 " << std::endl;
	list.PushFront(29);
	std::cout << "list: " << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
	std::cout << "list: " << list;

	std::cout << "PushBack -> 33 " << std::endl;
	list.PushBack(33);
	std::cout << "list: " << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;

	std::cout << "Insert -> Value 47, position 10 -->AFTER INSERT--> Value 15, position 2 -->AFTER INSERT--> Value 30, position 1 -->AFTER INSERT--> Value 30, position 3" << std::endl;
	list.Insert(47, 10);
	list.Insert(15, 2);
	list.Insert(30, 1);
	list.Insert(30, 3);
	std::cout << "list: " << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;

	std::cout << "PopFront: " << std::endl;
	list.PopFront();
	std::cout << "list: " << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;

	std::cout << "Pop Back: " << std::endl;
	list.PopBack();
	std::cout << "list: " << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;

	std::cout << "Num to erase -> 30" << std::endl;
	list.Erase(30);
	std::cout << "list: " << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;

	std::cout << "Compare two lists that are the same and two lists that are different." << std::endl;
	ForwardList l2;
	l2.PushBack(33);
	ForwardList l3;
	l3.PushBack(150);
	std::cout << "list: " << list;
	std::cout << "l2: " << l2;
	std::cout << "l3: " << l3 << std::endl;
	if (list == l2) {
		std::cout << "list == l2" << std::endl;
	}
	else {
		std::cout << "list != l2" << std::endl;
	}

	if (list == l3) {
		std::cout << "list == l3" << std::endl;
	}
	else {
		std::cout << "list != l3" << std::endl;
	}
}