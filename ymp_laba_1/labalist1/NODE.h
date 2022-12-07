#pragma once
using TInfo = int;
using ptrInfo = int*;

struct NODE
{
	ptrInfo info;
	NODE* next;
	NODE(TInfo info, NODE* ptr = nullptr) :info(new int(info)), next(ptr) {}
	~NODE()
	{
		delete info;
		next = nullptr;
	}
};