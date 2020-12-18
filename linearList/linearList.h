/******************************************************
* Author : CT
* https://github.com/guessable
*******************************************************/

#ifndef LINEARLSIT
#define LINEARLSIT
#include <iostream>
#include <memory>
#include "myExceptions.h"
using namespace std;

template<typename T>
class Linear_list {
   public:
      Linear_list() = default;
      virtual ~Linear_list() {};

      virtual bool empty() const = 0;

      virtual int size() const = 0;

      virtual T& get(int index) const = 0;

      // 返回元素第一次出现时索引
      virtual int index_first(const T& the_element) const = 0;

      virtual void erase(int index) = 0;
      virtual void insert(int index, const T& the_element) = 0;

      virtual void output(ostream& out) const = 0;
};


// 改变一维数组长度
template<typename T>
void change_array(T*& a, int old_length, int new_length) {

   try {
      if (new_length < 0) {
         throw My_exceptions("illegal parameter");
      }
   } catch(My_exceptions& e) {
      e.show_message();
   }

   T* temp = new T[new_length];
   int number = min(old_length, new_length);
   copy(a, a + number, temp);
   delete [] a;
   a = temp;
}

#endif
