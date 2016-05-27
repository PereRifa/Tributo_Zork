#ifndef _DOUBLE_LINKED_LIST_
#define _DOUBLE_LINKED_LIST_

typedef unsigned int uint;

template <class TYPE>

class DLList
{
public:
	class Node
	{
	public:
		TYPE data;
		Node* next = nullptr;
		Node* prev = nullptr;

	public:
		Node(const TYPE& data) : data(data){};
		~Node(){};
	};
private:
	Node* first = nullptr;

public:

	~DLList()
	{
		clear();
	};

	bool empty() const
	{
		return first == nullptr;
	}

	uint size() const
	{
		uint ret = 0;

		Node* temp = first;
		while (temp != nullptr)
		{
			temp = temp->next;
			ret++;
		}
		
		return ret;
	}

	Node* end() const
	{
		Node* ret = first;
		if (first != nullptr)
		{
			while (ret->next != nullptr)
			{
				ret = ret->next;
			}
		}
		return ret;
	}

	void erase(Node* other)
	{
		Node* temp = first;
		if (first != nullptr)
		{
			if (first == other){
				first = other->next;
				other->next->prev = nullptr;
			}
			else{
				while (temp->next != other && temp->next != nullptr)
				{
					temp = temp->next;
				}

				temp->next = other->next;
				if (other->next != nullptr && first != other->next)
				{
					temp->next->prev = other->prev;
				}
			}
			delete other;
		}
	}

	void insert(Node* position, const TYPE& data)
	{
		Node* temp = first;
		Node* inode = new Node(data);
		if (first != nullptr)
		{
			if (position == nullptr)
			{
				temp = end();
				temp->next = inode;
				inode->prev = temp;
			}
			else
			while (temp != nullptr)
			{
				if (temp == position)
				{
					inode->next = position->next;
					inode->prev = position;
					position->next = inode;
					if (inode->next != nullptr)
						inode->next->prev = inode;
					break;
				}
				else temp = temp->next;
			}
		}
		else first = inode;
		
	}

	TYPE* at(uint index)
	{
		uint count = 0;
		Node* temp = start;

		while (temp != nullptr)
		{
			if (count == index)
				return temp->data;
			temp = temp->next;
			count++;
		}
		return nullptr;
	}
	const TYPE* at(uint index) const
	{
		uint count = 0;
		Node* temp = start;

		while (temp != nullptr)
		{
			if (count == index)
				return temp->data;
			temp = temp->next;
			count++;
		}
		return nullptr;
	}

	Node* atnode(uint index)
	{
		uint count = 0;
		Node* temp = start;

		while (temp != nullptr)
		{
			if (count == index)
				return temp;
			temp = temp->next;
			count++;
		}
		return nullptr;
	}

	void pop_back()
	{
		Node* temp = end();
		if (temp != nullptr)
			erase(temp);
	}
	void pop_front()
	{
		if (first != nullptr)
			erase(first);
	}

	void push_back(const TYPE& data)
	{
		Node* pbnode = new Node(data);
		Node* last = end();
		if (last != nullptr)
		{
			last->next = pbnode;
			pbnode->prev = last;
		}
		else first = pbnode;
	}

	void push_front(const TYPE& data)
	{
		Node* pfnode = new Node(data);
		if (first != nullptr){
			first->prev = pfnode;
			pfnode->next = first;
		}
		first = pfnode;
	}

	void clear()
	{
		Node* temp = first;
		Node* last;

		while (temp != nullptr)
		{
			last = temp->next;
			delete temp;
			temp = last;
		}
		first = nullptr;
	}

};


#endif;