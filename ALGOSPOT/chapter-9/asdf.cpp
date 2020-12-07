#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>

typedef enum msg
{
	KernelMsgQ_Task0,
	KernelMsgQ_Task1,
	KernelMsgQ_Task2,
	KernelMsgQ_Task3,

	KernelMsgQ_Num
} KernelMsgQ_t;

void pdequeue(int num, int* out_data) {
	*out_data = num;
}

void dequeue(int num, int& out_data) {
	out_data = num;
}

int main() {
	int* pdata;
	int data;
	data = 11;
	pdata = &data;
	int asdf = (17 >> 3);
	printf("%d\n", asdf);

	pdequeue(22, pdata);
	printf("%d %d\n", data, *pdata);

	dequeue(33, data);
	printf("%d %d\n", data, *pdata);

	printf("%d\n", KernelMsgQ_Task3);
	printf("%d\n", KernelMsgQ_Num);
}