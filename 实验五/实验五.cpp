// 实验五.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#include "pch.h"
#include "date.h"
#include<string>
#include<string.h>
#include<map>
#include <iostream>
using namespace std;
void creatdate();
void adddate();
void subdate();
void difference();
void deletedate();
map<int, date> datemap;
map<int, date>::iterator i;

int main()
{
	bool loop = true;//选择操作
	int select;
	i = datemap.begin();
	do {
		cout << "------------------------------------------" << endl;
		cout << "\t请输入您要执行的操作：\n\t1、创建日期\n\t2、求加上某天数得到的日期\n\t3、求减去某天数得到的日期\n\t4、求两日期相差的天数\n\t5、删除日期" << endl;
		cout << "------------------------------------------" << endl;
		cout << "请输入您要执行的操作：" << endl;
		cin >> select;
		cin.get();
		switch (select) {
		case 1:
			creatdate();
			break;
		case 2:
			adddate();
			break;
		case 3:
			subdate();
			break;
		case 4:
			difference();
			break;
		case 5:
			deletedate();
		default:
			break;
		}
		i = datemap.begin();
	} while (loop);
}

void creatdate() {
	date* date1 = NULL;
	int year, month, day;
	cout << "请输入年份：" << endl;
	cin >> year;
	cin.get();
	cout << "请输入月份：" << endl;
	cin >> month;
	cin.get();
	cout << "请输入日期：" << endl;
	cin >> day;
	cin.get();
	date1 = new date(year, month, day);
	if (date1->getDay() <= date1->getDpm() && date1->getDay() >= 1 && date1->getMonth() <= 12 && date1->getMonth() >= 1) {
		if (datemap.empty()) {
			datemap[1] = *date1;
		}
		else {
			i = --datemap.end();
			datemap[i->first + 1] = *date1;
		}
	}
	cout << "所有日期如下：" << endl;
	for (i = datemap.begin(); i != datemap.end(); ++i) {
		cout << i->first << ":" << i->second.toString() << endl;
	}
}

void adddate() {
	int days;
	int key;
	if (datemap.empty()) {
		cout << "请先创建一个日期:" << endl;
		creatdate();
	}
	else {
		cout << "所有日期如下：" << endl;
		for (i = datemap.begin(); i != datemap.end(); ++i) {
			cout << i->first << ":" << i->second.toString() << endl;
		}
	}
	cout << "请选择您要执行操作的日期序号：" << endl;
	cin >> key;
	cin.get();
	if ((datemap.find(key) == datemap.end()) ||key<1) {
		cout << "数据错误！请重新输入。" << endl;
		return;
	}
	cout << "请输入您要加上的天数" << endl;
	cin >> days;
	cin.get();
	cout << datemap[key].toString() << "的" << days << "天后是";
	datemap[key] = datemap[key] + days;
	cout << datemap[key].toString() << endl;
}

void subdate() {
	int days;
	int key;
	if (datemap.empty()) {
		cout << "请先创建一个日期:" << endl;
		creatdate();
	}
	else {
		cout << "所有日期如下：" << endl;
		for (i = datemap.begin(); i != datemap.end(); ++i) {
			cout << i->first << ":" << i->second.toString() << endl;
		}
	}
	cout << "请选择您要执行操作的日期序号：" << endl;
	cin >> key;
	cin.get();
	if ((datemap.find(key) == datemap.end()) || key < 1) {
		cout << "数据错误！请重新输入。" << endl;
		return;
	}
	cout << "请输入您要减去的天数" << endl;
	cin >> days;
	cin.get();
	cout << datemap[key].toString() << "的" << days << "天后是";
	datemap[key] = datemap[key] - days;
	cout << datemap[key].toString() << endl;
}

void difference() {
	int key1;
	int key2;
	if (datemap.size() < 2) {
		cout << "请先创建两个及以上的日期:" << endl;
		creatdate();
	}
	else {
		cout << "所有日期如下：" << endl;
		for (i = datemap.begin(); i != datemap.end(); ++i) {
			cout << i->first << ":" << i->second.toString() << endl;
		}
	}
	cout << "请选择您要执行操作的第一个日期序号：" << endl;
	cin >> key1;
	cin.get();
	if ((datemap.find(key1) == datemap.end()) || key1 < 1) {
		cout << "数据错误！请重新输入。" << endl;
		return;
	}
	cout << "请选择您要执行操作的第二个日期序号：" << endl;
	cin >> key2;
	if ((datemap.find(key2) == datemap.end()) || key2 < 1) {
		cout << "数据错误！请重新输入。" << endl;
		return;
	}
	cin.get();
	cout << datemap[key1].toString() << "与" << datemap[key2].toString() << "之间的差值为：";
	cout << datemap[key1] - datemap[key2] << endl;
}

void deletedate() {
	int key;
	cout << "所有日期如下：" << endl;
	for (i = datemap.begin(); i != datemap.end(); ++i) {
		cout << i->first << ":" << i->second.toString() << endl;
	}
	cout << "请选择您要执行操作的日期序号：" << endl;
	cin >> key;
	cin.get();
	if ((datemap.find(key) == datemap.end()) || key < 1) {
		cout << "数据错误！请重新输入。" << endl;
		return;
	}
	datemap.erase(key);
	cout << "删除后的日期如下：" << endl;
	for (i = datemap.begin(); i != datemap.end(); ++i) {
		cout << i->first << ":" << i->second.toString() << endl;
	}
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
