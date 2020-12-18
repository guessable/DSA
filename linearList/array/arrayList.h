/******************************************************
* Author : CT
* https://github.com/guessable
*******************************************************/

#ifndef ATTAYLIST
#define ATTAYLIST
#include <algorithm>
#include <iterator>
#include "../linearList.h"
#include "arrayList_iter.h"

template<typename T>
class Array_list: public Linear_list<T> {
   public:
      typedef Iterator<T> iterator;
   private:
      int list_size;  //线性表元素个数
      int length;     //数组容量
      T* element;
      void check_index(int index) const;
   public:
      Array_list(int init_length = 10);
      Array_list(const Array_list<T>&);
      Array_list(initializer_list<T> _list);
      ~Array_list() {
         delete[] element;
      }

      iterator begin() const {
         return element;
      }

      iterator end() const {
         return element + list_size;
      }

      bool empty() const {
         return list_size == 0;
      }

      int size() const {
         return list_size;
      }

      int capacity() {
         return length;
      }

      T& get(int index) const;
      T& operator[](int index) const;

      int index_first(const T& the_element) const;
      void erase(int index);
      void insert(int index, const T& the_element);

      void output(ostream& out) const;
};

template<typename T>
void Array_list<T>::check_index(int index) const {
   try {
      if(index < 0 || index >= list_size) {
         throw My_exceptions("index_out_scope");
      }
   } catch(My_exceptions& e) {
      e.show_message();
   }
}

//构造函数
template<typename T>
Array_list<T>::Array_list(const Array_list<T>& the_list){
	length = the_list.length;
	list_size = the_list.list_size;
   element = new T[length];
   copy(the_list.element, the_list.element + list_size, element);
}

template<typename T>
Array_list<T>::Array_list(int init_length) {
   try {
      if(init_length < 0) {
         throw My_exceptions("illegal_parameter");
      }
   } catch(My_exceptions& e) {
      e.show_message();
   }

   length = init_length;
   element = new T[length];
   list_size = 0;
}

template<typename T>
Array_list<T>::Array_list(initializer_list<T> _list) {
   length = _list.size();
   list_size = _list.size();
   element = new T[length];
   int i = 0;
   for(auto the_element : _list) {
      element[i++] = the_element;
   }
}

/**************************************
 * ************************************/

template<typename T>
T& Array_list<T>::get(int index) const {
   check_index(index);
   return element[index];
}

template<typename T>
T& Array_list<T>::operator[](int index) const {
   check_index(index);
   return element[index];
}

template<typename T>
int Array_list<T>::index_first(const T& the_element) const {
   int result = find(element, element + list_size, the_element) - element;

   try {
      if(result == list_size) {
         throw My_exceptions("the_element_not_find");
      }
   } catch(My_exceptions& e) {
      e.show_message();
   }

   return result;
}

template<typename T>
void Array_list<T>::erase(int index) {
   check_index(index);

   if(list_size <= static_cast<int>(length / 4)) {
      int new_length = static_cast<int>(length / 2);
      change_array(element, length, new_length);
      length = new_length;
   }

   copy(element + index + 1, element + list_size, element + index);

   element[--list_size].~T(); //最后一个元素所在位置析构掉
}

template<typename T>
void Array_list<T>::insert(int index, const T& the_element) {
   try {
      if(index < 0 || index > list_size) {
         throw My_exceptions("index_out_scope");
      }
   } catch(My_exceptions& e) {
      e.show_message();
   }

   // 达到容量则容量倍增
   if(list_size == length) {
      change_array(element, length, 2 * length);
      length *= 2;
   }

   copy_backward(element + index, element + list_size,
                 element + list_size + 1);
   element[index] = the_element;
   list_size++;
}

template<typename T>
void Array_list<T>::output(ostream& out) const {
	copy(element, element + list_size, ostream_iterator<T>(out, ","));
}

template<typename T>
ostream& operator<<(ostream& out, const Array_list<T>& x) {
   x.output(out);
   return out;
}

#endif
