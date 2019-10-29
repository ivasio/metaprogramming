#ifndef TYPELISTS_INDEXOF_H
#define TYPELISTS_INDEXOF_H


class NullType {};

template <class T, class U>
struct TypeList {
    typedef T head;
    typedef U tail;
};

template <class TList, class Type>
struct IndexOf;

template <class T, class U>
struct IndexOf <TypeList <T, U>, T> {
    enum {
        value = 1
    };
};

template <class T>
struct IndexOf <TypeList <T, NullType>, T> {
    enum {
        value = 1
    };
};

template <class T, class O>
struct IndexOf <TypeList <T, NullType>, O> {
    enum {
        value = 0
    };
};

template <class T, class U, class O>
struct IndexOf <TypeList <T, U>, O> {
    enum {
        nextValue = IndexOf<U, O>::value,
        value = (nextValue > 0) ? nextValue + 1 : nextValue
    };
};

template<class TList, class Type>
int getIndexOf() {
    return IndexOf<TList, Type>::value - 1;
}


#endif //TYPELISTS_INDEXOF_H
