#include "My_list.h"

LIST::~LIST()
{
	while (!empty())
		del_from_head();
	delete head;
	_CrtDumpMemoryLeaks();
}

bool LIST::empty()
{
	return !head->next;
}

void LIST::add_to_head(TInfo elem)
{
	adding_by_pointer(head->next, elem);
	if (head == tail)//cписок пуст
		tail = tail->next;
	++size;
}

void LIST::add_to_tail(TInfo elem)
{
	adding_by_pointer(tail->next, elem);
	tail = tail->next;
}

void LIST::add_after(ptrNODE ptr, TInfo elem)
{
	if (ptr)
	{
		adding_by_pointer(ptr->next, elem);
		if (ptr == tail)
			tail = tail->next;
	}
}

void LIST::del_from_head()
{
	if (head->next)
	{
		deleting_by_pointer(head->next);
		if (!head->next)
			tail = head;
		--size;
	}
}

void LIST::del_after(ptrNODE ptr)
{
	if (ptr && ptr->next)
	{
		if (ptr->next == tail)
			tail = ptr;
		deleting_by_pointer(ptr->next);
		if (empty())
			tail = head;
		--size;
	}
}

void LIST::create_by_stack(std::ifstream& file)
{
	TInfo elem;
	while (file >> elem)
		add_to_head(elem);
}

void LIST::create_by_queue(std::ifstream& file)
{
	TInfo elem;
	while (file >> elem)
		add_to_tail(elem);
}

void LIST::create_by_order(std::ifstream& file)
{
	TInfo elem;
	ptrNODE p = nullptr;
	auto find_place = [this](TInfo elem)->ptrNODE//ищем, куда вставить элемент (поиск места для вставки)
	{
		ptrNODE result = head;
		while (result->next && *result->next->info < elem)
			result = result->next;
		return result;
	};
	while (file >> elem)
	{
		p = find_place(elem);
		add_after(p, elem);
	}
}

void LIST::print()
{
	if (empty())
		std::cout << "Список пуст!\n";
	else
	{
		ptrNODE p = head->next;
		while (p)
		{
			std::cout << *p->info << ' ';
			p = p->next;
		}
		std::cout << '\n';
	}
}

void LIST::print(std::ostream &ostream, std::string msg)
{
	if (empty())
		std::cout << "Список пуст!\n";
	else
	{
		ptrNODE p = head->next;
		while (p)
		{
			ostream << *p->info << ' ';
			p = p->next;
		}
		ostream << "\n";
	}
	if (msg.size())
		ostream << msg << '\n';
}

void LIST::sorting()
{
	auto switch_pointers = [](ptrNODE q, ptrNODE p)
	{
		ptrNODE tmp = p->next;
		p->next = tmp->next;
		tmp->next = q->next;
		q->next = tmp;
	};
	//h -      элемент, для котрого ищется место для вставки в упорядоченнной области
	//h_prev - куда вставлять
	ptrNODE h = head->next->next,
		    h_prev = head->next;
	while (h)
	{
		if (h_prev->info > h->info)//означает, что нашли место для вставки
		{
			ptrNODE p = head;
			while (p->next != h && p->next->info < h->info)//имеет место вставки (для переключения указателей)
				p = p->next;
			switch_pointers(p, h_prev);
			h = h_prev->next;
		}
		else //если элементы упорядочены (место искать не надо)
		{
			h_prev = h;
			h = h->next;
		}
	}
	tail = h_prev;
}
