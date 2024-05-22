#include <iostream>
#include "ForwardList.h"
int main()
{
	ForwardList list;
	if (list.IsEmpty()) {
		std::cout << "LIST IS EMPTY RIGHT NOW." << std::endl;
	}
	list.PushFront(29);
	std::cout << "PushFront -> 29 " << std::endl;
	std::cout << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
	std::cout << list;
	list.PushBack(33);
	std::cout << "PushBack -> 33 " << std::endl;
	std::cout << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
	list.Insert(15, 2);
	list.Insert(30, 1);
	std::cout << "Insert -> Value 15, position 2 && Value 30, position 1" << std::endl;
	std::cout << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
	list.PopFront();
	std::cout << "PopFront: " << std::endl;
	std::cout << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
	list.PopBack();
	std::cout << "Pop Back: " << std::endl;
	std::cout << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
	list.Erase(30);
	std::cout << "Num to erase -> 30" << std::endl;
	std::cout << list;
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
}