#include <iostream>
#include "ForwardList.h"
int main()
{
	ForwardList list;
	std::cout << "PushFront: " << std::endl;
	list.PushFront(29);
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
	std::cout << "PushBack: " << std::endl;
	list.PushBack(33);
	std::cout << "Primer elemento: " << list.Front() << std::endl;
	std::cout << "Ultimo elemento: " << list.Back() << std::endl;
	std::cout << "PopFront: " << std::endl;
	list.PopFront();
	list.PopBack();
}