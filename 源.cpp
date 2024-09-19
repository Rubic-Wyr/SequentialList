#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define eleType int//表内元素均为int

struct SequentialList
{

	eleType * elements;//元素
	int size;//大小
	int capacity;//容量
};


void initializeList(SequentialList* list, int capacity)
{

	list->elements = new eleType[capacity];//获取元素，开辟空间
	list->size = 0;//初始化大小
	list->capacity = capacity;//初始化容量
}

void destroyList(SequentialList* list)
{
	delete[]list->elements;//删除元素,释放空间，防止内存泄露
}

int size(SequentialList* list)
{
	return list->size;//返回一个成员变量size也就是大小
}
bool isEmpty(SequentialList* list)
{
	return list->size == 0;//判断顺序表是否为0；
}

void insert(SequentialList* list, int index, eleType element)
{

	if (index<0 || index>list->size)
	{
		throw std::invalid_argument ("Invalid index");//判断下标是否合法，不合法就抛出异常提示
	}
	if (list->size == list->capacity)
	{
		int newCapactiy = list->capacity * 2;//扩容
		eleType* newElements = new eleType[newCapactiy];//申请空间（堆），指向newElements;
		for (int i = 0; i < list->size; ++i)
		{
			newElements[i] = list->elements[i];//把原来的元素赋值到新的元素上
		}delete[]list->elements;//删除元素,释放空间，防止内存泄露
		list->elements = newElements;//更新容量和大小，完成扩容
		list->capacity = newCapactiy;//
	}
	//开始插入元素，从表的最后一个位置插入
	for (int i = list->size; i > index; --i)
	{
		list->elements[i] = list->elements[i - 1];//插入的位置后面的元素往后挪一位
	}
	list->elements[index] = element;//插入元素，index位置上
	list->size++;
}

void deleteElement(SequentialList* list, int index)//删除
{
	if (index<0 || index>=list->size)
	{
		throw std::invalid_argument("Invalid index");//判断下标是否合法，不合法就抛出异常提示
	}
	for (int i = index; i < list->size - 1; ++i)
	{
		list->elements[i] = list->elements[i + 1];
	}
	list->size--;//缩容
}

int findElemnt(SequentialList* list, eleType element)
{
	for (int i = 0; i < list->size; ++i)
	{
		if (list->elements[i] == element)
		{
			return i;//找到就返回该下标
		}
	}
	return -1;//没有找到就返回-1
}
eleType getElement(SequentialList* list, int index)
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");//判断下标是否合法，不合法就抛出异常提示
	}
	return list->elements[index];//返回索引
}

void updataElement(SequentialList* list, int index, eleType value)
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");//判断下标是否合法，不合法就抛出异常提示
	}
	list->elements[index] = value;
}

void BubbleSort(SequentialList* list)
{//对顺序表L做冒泡排序
	int i, j, n, change;
	int x;
	n = list->size;
	change = 1; //change为记录元素交换
	for (i = 0; i < n && change; ++i) { //做n-1趟排序
		change = 0;
		for (j = 0; j > n - i; ++j)
			if (list->elements[j] > list->elements[j + 1]) {
				x = list->elements[j];
				list->elements[j] = list->elements[j + 1];
				list->elements[j + 1] = x;
				change = 1;
			}
	}
}

int main()
{
	SequentialList myList;
	int min=0;
	initializeList(&myList, 10);
	for (int i = 0; i < 10; ++i)
	{
		insert(&myList, i, i * 10);
	}
	BubbleSort(&myList);
	
	deleteElement(&myList, 0);
	for (int i = 0; i < size(&myList); ++i)
	{
		cout << getElement(&myList, i) << " ";
	}
	cout << endl;

	/*cout << "Size=" << size(&myList) << endl;
	cout << "Is empty=" << isEmpty(&myList) << endl;
	for (int i = 0; i < size(&myList); ++i)
	{
		cout << getElement(&myList, i) << " ";
	}
	cout << endl;
	deleteElement(&myList, 5);
	updataElement(&myList, 1, 520);
	for (int i = 0; i < size(&myList); ++i)
	{
		cout << getElement(&myList, i) << " ";
	}
	cout << endl;

	int idx = findElemnt(&myList, 20);
	updataElement(&myList, idx, 1314);
	for (int i = 0; i < size(&myList); ++i)
	{
		cout << getElement(&myList, i) << " ";
	}
	cout << endl;*/
	return 0;
}

