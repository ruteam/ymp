#pragma once
#include<iostream>
#include <fstream>
#include "Account.h"

using TInfo = Account;

struct NODE
{
	TInfo info;
	NODE* next, * prev;
	NODE(TInfo info, NODE* next = nullptr, NODE* prev = nullptr) :
		info(info), next(next), prev(prev) {};
	~NODE()
	{
		next = nullptr;
		prev = nullptr;
	}
};
using ptrNODE = NODE*;

struct  DLIST
{
private:
	ptrNODE begin, end;
	size_t size;
public:
	DLIST() { begin = nullptr; end = nullptr; }
	DLIST(const char* filename);
	void first_node(const Account& acc);
	bool empty();
	void add_after(ptrNODE ptr, const Account& acc);
	void add_before(ptrNODE ptr, const Account& acc);
	void print();
	~DLIST();
	Account& del_by_pointer(ptrNODE& ptr);
	void del_after(ptrNODE ptr);
	void del_before(ptrNODE ptr);
	ptrNODE get_begin()
	{
		return begin;
	}
};