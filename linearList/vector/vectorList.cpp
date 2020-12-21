/******************************************************
* Author : CT
* https://github.com/guessable
*******************************************************/

#include <boost/format.hpp>
#include "vectorList.h"

int main() {
	Vector_list<int> vec1;
	cout << "****insert*****" << endl;
	vec1.insert(0,1);
	vec1.insert(0,2);
	vec1.insert(0,3);
	vec1.insert(0,4);
	int i = 0;
	for(auto a:vec1){
		cout << boost::format("vec1[%1%]=%2%")%i++%a <<endl;
	}

	cout << "***earse****" << endl;
	int j = 0;
	vec1.erase(1);
	vec1.erase(1);
	vec1.erase(1);
	vec1.erase(1);
	for(auto a:vec1){
		cout << boost::format("vec1[%1%]=%2%")%j++%a <<endl;
	}

	cout << "***列表初始化****" << endl;
	Vector_list<string> vec2{"hello","world","C","T"};

	int h = 0;
	for(auto a:vec2){
		cout << boost::format("vec2[%1%]=%2%")%h++%a <<endl;
	}

	vec2.insert(1,"C");
	vec2.insert(1,"C");
	vec2.insert(1,"C");
	vec2.insert(1,"C");

	int k = 0;
	for(auto a:vec2){
		cout << boost::format("vec2[%1%]=%2%")%k++%a <<endl;
	}
}
