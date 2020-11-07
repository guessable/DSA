
#ifndef VECTOR
#define VECTOR
#include <iostream>

typedef int Rank;
const int DEFAULT_CAPACITY = 3; // 默认容量

template <class T>
class Vector
{
private:
    Rank _size;    // 规模
    int _capacity; //容量
    T *_elem;      //数据区

    Rank max(Rank lo, Rank hi);
    void copyFrom(const T *A, Rank lo, Rank hi);
    void expand();
    void shrink();

    bool bubble(Rank lo, Rank hi); //扫描交换
    bool bullleSort(Rank lo, Rank hi);
    void selectionSort(Rank lo, Rank hi);  //选择排序算法
    void merge(Rank lo, Rank mi, Rank hi); //归并算法
    void mergeSort(Rank lo, Rank hi);      //归并排序算法
    Rank partition(Rank lo, Rank hi);      //轴点构造算法
    void quickSort(Rank lo, Rank hi);      //快速排序算法
    void heapSort(Rank lo, Rank hi);       //堆排序

public:
    // 构造函数
    Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0); //容量为c、规模为s、所有元素初始化为v
    Vector(const T *A, Rank lo, Rank hi)
    {
        copyFrom(A, lo, hi);
    } //数组区间复制
    Vector(const T *A, Rank n)
    {
        copyFrom(A, 0, n);
    } // 数组整体复制
    Vector(const Vector<T> &V, Rank lo, Rank hi)
    {
        copyFrom(V._elem, lo, hi);
    } //向量区间复制
    Vector(const Vector<T> &V)
    {
        copyFrom(V._elem, 0, V._size);
    } //向量整体复制

    // 析构函数
    ~Vector()
    {
        delete[] _elem;
    }

    // 访问接口（只读）
    Rank size() const
    {
        return _size;
    } // 规模

    bool isEmpty() const
    {
        return !_size;
    } // 判读是否为空

    int disordered() const; // 判读向量是否排序

    Rank find(const T &e, Rank lo, Rank hi) const; // 无序向量区间查找
    Rank find(const T &e) const
    {
        return find(e, 0, _size);
    } // 无序向量整体查找

    Rank search(const T &e, Rank lo, Rank hi) const; // 有序向量区间查找
    Rank serch(const T &e)
    {
        return search(e, 0, _size);
    } // 有序向量整体查找

    // 重载运算符
    T &operator[](Rank r);                   // 重载下标运算符，返回引用则可做左值
    Vector<T> operator=(const Vector<T> &e); //重载赋值运算符

    // 可写接口
    T remove(Rank r);                //删除元素
    int remove(Rank lo, Rank hi);    // 删除区间
    Rank insert(Rank r, const T &e); //插入
    Rank insert(const T &e)
    {
        return insert(_size, e);
    } // 默认末尾插入

    void sort(Rank lo, Rank hi); //区间排序
    void sort()
    {
        sort(0, _size);
    } // 整体排序

    int deduplicate(); //无序去重
    int uniquify();    //有序去重
};

#endif
