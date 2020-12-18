/******************************************************
* Author : CT
* https://github.com/guessable
*******************************************************/

#ifndef EXCEPTIONS
#define EXCEPTIONS
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class My_exceptions {
   public:
      My_exceptions() = default;
      explicit My_exceptions(string message):
         message(message) {}
      void show_message() const {
         cout << message << endl;
      }
   private:
      string message;
};


#endif
