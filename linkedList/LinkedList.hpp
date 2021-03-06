/**
*	@author
*	@date
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList()
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	Node<T>* temp = m_front;

	int i=1;
	if(isEmpty()==true)
	{
		return (0);
	}
	else
	{
	while(temp->getNext() != nullptr)
	{
		i=i+1;
		temp = temp->getNext();
	}
	return (i);

}

}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* temp = m_front;
	if(isEmpty()==true)
	{
		return (false);
	}
	else{
		while(temp->getNext() != nullptr)
		{

			if(temp->getValue()==value)
			{
				return (true);
			}
			temp = temp->getNext();
		}
		if(temp->getValue()==value)
		{
			return (true);
		}
	}
return(false);
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);

}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	Node<T>* lastNode = nullptr;
	Node<T>* secondintoLast = nullptr;
	if(isEmpty()==true)
	{
		return false;
	}
	else if (size()==1)
	{
		delete m_front;
		return true;
	}
	else
	{
		lastNode = m_front;
		secondintoLast= m_front;
		while(lastNode->getNext() != nullptr)
		{
			lastNode = lastNode->getNext();
		}
		while(secondintoLast->getNext()->getNext() != nullptr)
		{
			secondintoLast = secondintoLast->getNext();
		}

		secondintoLast->setNext(nullptr);
		delete lastNode;
		m_size--;

		return (true);
	}
	return (false);
}

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}
