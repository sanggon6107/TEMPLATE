/*
* HOME       : ecourse.co.kr
* EMAIL      : smkang @ codenuri.co.kr
* COURSENAME : C++ Template Programming
* MODULE     : specialization1.cpp
* Copyright (C) 2017 CODENURI Inc. All rights reserved.
*/

#include <iostream>
using namespace std;

// template specialization
// primary template
template<typename T> class Stack
{
public:
	void push(T v) { cout << "T" << endl; }
};

// partial specialization( 부분 특수화 )
template<typename T>
class Stack<T*> // 위의 <typename ...> 보다 여기가 더 중요하다. 이 곳을 먼저 보고 그 뒤에, 필요한 타입 네임에 대해서만 적을 것.
	        // 포인터인 경우에 대해 specialization하고, 그래도 T는 정해지지 않았으므로 위에 적는다.
{
public:
	void push(T* v) { cout << "T*" << endl; }
};

// specialization
template<>
class Stack<char*>   // T가 char*로 안전히 정해졌다.즉, 더이상 T와는 관계없어졌으므로 typename T를 지운다.
{
public:
	void push(char* v) { cout << "char*" << endl; }
};

int main()
{
	Stack<int>   s1; s1.push(0);
	Stack<int*>  s2; s2.push(0);
	Stack<char*> s3; s3.push(0);
}
