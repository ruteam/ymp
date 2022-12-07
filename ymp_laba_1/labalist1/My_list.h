#pragma once
#include "NODE.h"
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#define _CRTDBG_MAP_ALLOC//�������� ������������ ������
#include <crtdbg.h>
#define DBG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#define newDBG_NEW

using ptrNODE = NODE*;//��������� ����

struct LIST
{
private:
	ptrNODE head, tail;
	size_t size;
	void adding_by_pointer(ptrNODE& ptr, TInfo elem)
	{
		ptrNODE p = new NODE(elem, ptr);
		ptr = p;
	}
	void deleting_by_pointer(ptrNODE& ptr)
	{
		ptrNODE p = ptr;
		ptr = p->next;
		delete p;
	}
public:
	LIST()//�����������
	{
		head = new NODE(0);
		tail = head;
		size = 0;
	}
	//������
	~LIST();
	ptrNODE get_head()//������ ������ (� �����, ����� ��������� ������ ������)
	{
		return head;
	}
	TInfo get_first()
	{
		return *head->next->info;
	}
	size_t get_size()
	{
		return size;
	}
	ptrNODE get_tail()
	{
		return tail;
	}
	void set_tail(ptrNODE ptr)
	{
		tail = ptr;
	}
	bool empty();
	void add_to_head(TInfo elem);
	void add_to_tail(TInfo elem);
	void add_after(ptrNODE ptr, TInfo elem);
	void del_from_head();
	void del_after(ptrNODE ptr);
	void create_by_stack(std::ifstream& file);
	void create_by_queue(std::ifstream& file);
	void create_by_order(std::ifstream& file);
	void print();
	void print(std::ostream& ostream, std::string message = "");
	void sorting();
};

