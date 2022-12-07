#include "My_List.h"
#include <functional>
ptrNODE find_place(ptrNODE begin, const Account& acc)
{
	ptrNODE p = begin;
	while (p && p->info.compare(acc) < 0)
		p = p->next;
	return p;
}

DLIST::DLIST(const char* filename)
{
	std::ifstream file(filename);
	Account acc(file);
	first_node(acc);
	ptrNODE place;
	while (!file.eof())
	{
		Account acc(file);
		place = find_place(begin, acc);
		if (place)
			add_before(place, acc);
		else
			add_after(end, acc);
	}
	file.close();
}

void DLIST::first_node(const Account& acc)
{
	begin = new NODE(acc);
	end = begin;
}

bool DLIST::empty()
{
	return begin == nullptr;
}

void DLIST::add_after(ptrNODE ptr, const Account& acc)
{
	ptrNODE p = new NODE(acc, ptr->next, ptr);
	if (ptr == end)
		end = p;
	ptr->next = p;
}

void DLIST::add_before(ptrNODE ptr, const Account& acc)
{
	ptrNODE p = new NODE(acc, ptr, ptr->prev);
	if (ptr == begin)
		begin = p;
	else
		ptr->prev->next = p;
	ptr->prev = p;
}

void DLIST::print()
{
	ptrNODE ptr = begin;
	while (ptr)
	{
		ptr->info.print();
		ptr = ptr->next;
	}
}

DLIST::~DLIST()
{
	while (!empty())
		del_by_pointer(begin);
}

Account& DLIST::del_by_pointer(ptrNODE& ptr)
{
	ptrNODE p = ptr;
	if (ptr == begin)
	{
		begin = p->next;
		ptr = begin;
		if (p->next)
			p->next->prev = nullptr;
	}
	else
		if (ptr == end)
		{
			end = p->prev;
			ptr = end;
			if (p->prev)
				p->prev->next = nullptr;
		}
		else
		{
			ptr = ptr->next;
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
	static Account acc;
	acc = p->info;
	delete p;
	--size;
	return acc;
}

void DLIST::del_after(ptrNODE ptr)
{
	if (ptr && ptr->next)
	{
		ptrNODE p = ptr->next;
		if (ptr->next == end)
		{
			end = p->prev;
			ptr->next = end;
			if (p->prev)
				p->prev->next = nullptr;
		}
		else
		{
			ptr->next = ptr->next->next;
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
		--size;
	}
}

void DLIST::del_before(ptrNODE ptr)
{
	if (ptr != begin)
	{
		ptrNODE tmp = begin;
		while (tmp->next != ptr)
			tmp->next;

		ptrNODE p = tmp;
		if (tmp == begin)
		{
			begin = p->next;
			tmp = begin;
			if (p->next)
				p->next->prev = nullptr;
		}
		else
		{
			tmp = tmp->next;
			p->next->prev = p->prev;
			p->prev->next = p->next;
		}
		--size;
	}
}
