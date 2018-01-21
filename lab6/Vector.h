// #pragma once

#include <cstddef>


template <typename T>
struct Vector {
	Vector();
	Vector(size_t);
	Vector(size_t, T const &);

	~Vector();

	void resize(size_t);
	void resize(size_t, T const &);

	T & operator[](std::size_t);
	T const & operator[](std::size_t) const;

	T & at(std::size_t);
	T const & at(std::size_t) const;

	Vector(Vector const &);
    Vector<T> & operator=(Vector const &);

    void swap(Vector &);

    Vector (Vector &&);
    Vector & operator=(Vector &&);

    void push_back(T const &);
    void push_back(T &&);

    void pop_back();

    size_t size() const;
    bool empty() const;

 private:
 	size_t size_, capacity_;
 	T* data_;

 	void ensure_capacity();

 	void inc_capacity(size_t);
    size_t pow2(size_t);
};

#include "Vector.cpp"