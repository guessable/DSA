/******************************************************
* Author : CT
* https://github.com/guessable
*******************************************************/

#include<numeric>
#include <string>
#include "arrayList.h"
#include "arrayList_iter.h"

class Message {
   private:
      string message;
   public:
      Message(string message = "test"): message(message) {}
      void show_message() {
         cout << message << endl;
      }
      friend ostream& operator<<(ostream& out, const Message& e);
      bool operator==(const Message& e); //index_firet有判断是否相等操作
};

ostream& operator<<(ostream& out, const Message& e) {
   out << e.message;
   return out;
}

bool Message::operator==(const Message& e) {
   return message == e.message;
}


int main() {
   //初始化
   Array_list<double> arr1;
   cout << "arr1 empty: " << arr1.empty() << endl;

   Array_list<double> arr2{3.14, 2.71};
   cout << "arr2 empty: " << arr2.empty() << endl;

   Array_list<double> arr3(arr2);
   cout << "复制构造:" << arr3 << endl;

   Array_list<double> arr4(20);
   cout << "arr4 empty: " << arr4.empty() << endl;
   cout << "arr4: " << endl
        << "capacity: " << arr4.capacity() << endl
        << "list size: " << arr4.size() << endl;

   cout << "列表初始化: " << arr2 << endl
        << "capacity: " << arr2.capacity() << endl
        << "list size: " << arr2.size() << endl;
   //insert
   arr2.insert(2, 3.14);
   cout << "insert: " << arr2 << endl
        << "capacity: " << arr2.capacity() << endl
        << "list size: " << arr2.size() << endl;

   arr2.insert(3, 1.32);
   arr2.insert(3, 2.10);
   arr2.insert(4, 2.13);
   arr2.insert(4, 2.13);
   arr2.insert(4, 2.13);
   arr2.insert(4, 2.13);

   cout << "insert: " << arr2 << endl
        << "capacity: " << arr2.capacity() << endl
        << "list size: " << arr2.size() << endl;

   //get
   cout << "arr2[2]=" << arr2[2] << endl;
   cout << "arr2.get(2): " << arr2.get(2) << endl;

   //index_firet
   cout << "index_first(2.13): "
        << arr2.index_first(2.13) << endl;

   //earse
   arr2.erase(8);
   cout << "erase: " << arr2 << endl
        << "capacity: " << arr2.capacity() << endl
        << "list size: " << arr2.size() << endl;

   arr2.erase(0);
   arr2.erase(1);
   arr2.erase(1);
   arr2.erase(1);
   arr2.erase(1);
   cout << "erase: " << arr2 << endl
        << "capacity: " << arr2.capacity() << endl
        << "list size: " << arr2.size() << endl;

   // 迭代器
   cout << "************迭代器**********" << endl;
   copy(arr2.begin(), arr2.end(), ostream_iterator<double>(cout, ","));
   auto result = accumulate(arr2.begin(), arr2.end(), 1.0,
   [](double x, double y) {
      return x * y;
   });
   cout << "accumulate=" << result << endl;

   //自定义类型
   cout << "***********自定义类型*********" << endl;
   Array_list<Message> arr5;
   cout << "Array_list<Message>: " << "capacity " << arr5.capacity()
        << " size " << arr5.size() << endl;

   Array_list<Message> arr6{Message("test1"), Message("test2")};
   arr6.insert(2, Message("test3"));
   arr6.insert(2, Message("test3"));
   cout << "insert: " << arr6 << endl
        << "capacity: " << arr6.capacity() << endl
        << "list size: " << arr6.size() << endl;

   arr6.erase(1);
   arr6.erase(1);
   cout << "erase: " << arr6 << endl
        << "capacity: " << arr6.capacity() << endl
        << "list size: " << arr6.size() << endl;

   cout << "******迭代器******" << endl;
   for(auto it = arr6.begin(); it != arr6.end(); ++it) {
      it -> show_message();
   }
}
