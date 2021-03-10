// List_Class.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

template<typename T>
class Queue
{
public:
    Queue();
	~Queue();
	void push_back(T data);
	int GetSize() { return size; }
	T& operator[](const int index);

private:

	template<typename T>
	class Node
	{
		public:

			Node* pNext;
			T data;
			Node(T data = T(), Node* pNext = nullptr)
			{
				this->data = data;
				this->pNext = pNext;
			}
	};
	
	Node<T>* head;
	Node<T>* tail;
	int size;
};


int main()
{

	Queue<int> Q;


	std::cout << Q.GetSize() << "\n";
	Q.push_back(5);
	std::cout << Q.GetSize() << "\n";
	Q.push_back(10);
	std::cout << Q.GetSize() << "\n";
	Q.push_back(56);
	std::cout << Q.GetSize()<<"\n\n";

	

	for (size_t i = 0; i < Q.GetSize(); i++)
	{
		std::cout << Q[i] << "\n";
	}


    
   // std::cout << "test git 1 \n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.


template<typename T>
Queue<T>::Queue()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}
template<typename T>
Queue<T>::~Queue()
{
}

template<typename T>
void Queue<T>::push_back(T data)
{

	Node<T>* NewNode = new Node<T>(data);

	if (tail != nullptr)
	{
		tail->pNext = NewNode;
	}
	
	tail = NewNode;

	if (head == nullptr)
	{
		head = NewNode;
	}

	size++;
}

template<typename T>
T& Queue<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
