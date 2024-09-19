#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#define eleType int//����Ԫ�ؾ�Ϊint

struct SequentialList
{

	eleType * elements;//Ԫ��
	int size;//��С
	int capacity;//����
};


void initializeList(SequentialList* list, int capacity)
{

	list->elements = new eleType[capacity];//��ȡԪ�أ����ٿռ�
	list->size = 0;//��ʼ����С
	list->capacity = capacity;//��ʼ������
}

void destroyList(SequentialList* list)
{
	delete[]list->elements;//ɾ��Ԫ��,�ͷſռ䣬��ֹ�ڴ�й¶
}

int size(SequentialList* list)
{
	return list->size;//����һ����Ա����sizeҲ���Ǵ�С
}
bool isEmpty(SequentialList* list)
{
	return list->size == 0;//�ж�˳����Ƿ�Ϊ0��
}

void insert(SequentialList* list, int index, eleType element)
{

	if (index<0 || index>list->size)
	{
		throw std::invalid_argument ("Invalid index");//�ж��±��Ƿ�Ϸ������Ϸ����׳��쳣��ʾ
	}
	if (list->size == list->capacity)
	{
		int newCapactiy = list->capacity * 2;//����
		eleType* newElements = new eleType[newCapactiy];//����ռ䣨�ѣ���ָ��newElements;
		for (int i = 0; i < list->size; ++i)
		{
			newElements[i] = list->elements[i];//��ԭ����Ԫ�ظ�ֵ���µ�Ԫ����
		}delete[]list->elements;//ɾ��Ԫ��,�ͷſռ䣬��ֹ�ڴ�й¶
		list->elements = newElements;//���������ʹ�С���������
		list->capacity = newCapactiy;//
	}
	//��ʼ����Ԫ�أ��ӱ�����һ��λ�ò���
	for (int i = list->size; i > index; --i)
	{
		list->elements[i] = list->elements[i - 1];//�����λ�ú����Ԫ������Ųһλ
	}
	list->elements[index] = element;//����Ԫ�أ�indexλ����
	list->size++;
}

void deleteElement(SequentialList* list, int index)//ɾ��
{
	if (index<0 || index>=list->size)
	{
		throw std::invalid_argument("Invalid index");//�ж��±��Ƿ�Ϸ������Ϸ����׳��쳣��ʾ
	}
	for (int i = index; i < list->size - 1; ++i)
	{
		list->elements[i] = list->elements[i + 1];
	}
	list->size--;//����
}

int findElemnt(SequentialList* list, eleType element)
{
	for (int i = 0; i < list->size; ++i)
	{
		if (list->elements[i] == element)
		{
			return i;//�ҵ��ͷ��ظ��±�
		}
	}
	return -1;//û���ҵ��ͷ���-1
}
eleType getElement(SequentialList* list, int index)
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");//�ж��±��Ƿ�Ϸ������Ϸ����׳��쳣��ʾ
	}
	return list->elements[index];//��������
}

void updataElement(SequentialList* list, int index, eleType value)
{
	if (index < 0 || index >= list->size)
	{
		throw std::invalid_argument("Invalid index");//�ж��±��Ƿ�Ϸ������Ϸ����׳��쳣��ʾ
	}
	list->elements[index] = value;
}

void BubbleSort(SequentialList* list)
{//��˳���L��ð������
	int i, j, n, change;
	int x;
	n = list->size;
	change = 1; //changeΪ��¼Ԫ�ؽ���
	for (i = 0; i < n && change; ++i) { //��n-1������
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

