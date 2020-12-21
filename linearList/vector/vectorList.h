/******************************************************
* Author : CT
* https://github.com/guessable
*******************************************************/

#ifndef VECTORLIST
#define VECTORLIST
#include <iostream>
#include <vector>
#include <memory>
#include "../myExceptions.h"
using namespace std;

template<typename T>
class Vector_list {
   public:
      typedef typename vector<T>::size_type size_type;
      typedef typename vector<T>::iterator iterator;
      // 构造函数
      Vector_list(int init_length = 10);
      Vector_list(const Vector_list<T>&);
      Vector_list(initializer_list<T> _list);

      ~Vector_list() {}

      iterator begin() {
         return element -> begin();
      }

      iterator end() {
         return element -> end();
      }

      bool empty() const {
         return element -> empty();
      }

      size_type size() const {
         return element -> size();
      }

      size_type capacity() const {
         return element -> capacity();
      }

      void insert(int index, const T& the_element);
      void erase(int index);

      // void output(ostream& out) const;

   private:
      void check_index(int index) const;
      shared_ptr<vector<T>> element;
};

template<typename T>
void Vector_list<T>::check_index(int index) const {
   try {
      if(index < 0 ) {
         throw My_exceptions("index_out_scope");
      }
   } catch(My_exceptions& e) {
      e.show_message();
   }
}

template<typename T>
Vector_list<T>::Vector_list(int init_length) {
   try {
      if (init_length < 1) {
         throw My_exceptions("capacity error");
      }
   } catch(My_exceptions& e) {
      e.show_message();
   }

   element = make_shared<vector<T>>(init_length);
}

template<typename T>
Vector_list<T>::Vector_list(const Vector_list<T>& the_list):
   element(the_list.element) {};

template<typename T>
Vector_list<T>::Vector_list(initializer_list<T> _list):
   element(make_shared<vector<T>>(_list)) {}

template<typename T>
void Vector_list<T>::erase(int index) {
   check_index(index);
   element -> erase(begin() + index);
}

template<typename T>
void Vector_list<T>::insert(int index, const T& the_element) {
   try {
      if (index < 0) {
         throw My_exceptions("illegal_index");
      }
   } catch(My_exceptions& e) {
      e.show_message();
   }

   element -> insert(element->begin() + index, the_element);
}

#endif
