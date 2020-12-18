/******************************************************
* Author : CT
* https://github.com/guessable
*******************************************************/

#ifndef ARRAY_LIST_ITER
#define ARRAY_LIST_ITER

template<typename T>
class Iterator {
	public:
		typedef bidirectional_iterator_tag iterator_category;
		typedef ptrdiff_t difference_type;
		typedef T value_type;
		typedef T* pointer;
		typedef T& reference;

		Iterator(T* position): position(position) {}

		reference operator*() const {
			return *position;
		}
		pointer operator->() const {
			return position;
		}

		Iterator& operator++() {
			++position;
			return *this;
		}
		Iterator& operator++(int) {
			Iterator old = *this;
			++position;
			return old;
		}
		Iterator& operator--() {
			--position;
			return *this;
		}
		Iterator& operator--(int) {
			Iterator old = *this;
			--position;
			return old;
		}

		bool operator==(const Iterator right) const {
			return position == right.position;
		}
		bool operator!=(const Iterator right) const {
			return position != right.position;
		}
	private:
		T* position;
};

#endif
