#include <iostream>

template <typename T>
Vector<T>::Vector() : size_(0), capacity_(0), data_(nullptr) {}

template <typename T>
Vector<T>::Vector(size_t n) : size_(n), capacity_(n), data_(new T[n]) {}

template <typename T>
Vector<T>::Vector(size_t n, T const &val) : size_(n), capacity_(n), data_(new T[n]) {
	for (size_t i = 0; i < n; i++) {
		data_[i] = val;
	}
}

template <typename T>
Vector<T>::~Vector() {
	delete [] data_;
}

template <typename T>
void Vector<T>::resize(size_t n) {
	if (n > capacity_) {
		inc_capacity(pow2(n));
	}
	size_ = n;
}

template <typename T>
void Vector<T>::resize(size_t n, T const &val) {
	if (n > capacity_) {
		inc_capacity(pow2(n));
	}
	for (size_t i = size_; i < n; i++) {
		data_[i] = val;
	}
	size_ = n;
}

template <typename T>
size_t Vector<T>::pow2(size_t n) {
	size_t k = 1;
	while (n > k) {
		k = k << 1;
	}
	return k;
}

template <typename T>
void Vector<T>::inc_capacity(size_t n) {
	T * data = new T[n];
	for (size_t i = 0; i < size_; i++) {
		data[i] = data_[i];
	}
	capacity_ = n;
	delete [] data_;
	data_ = data;
}

template <typename T>
T & Vector<T>::operator[](size_t n) {
	return data_[n];
}

template <typename T>
T const & Vector<T>::operator[](size_t n) const {
	return data_[n];
}

template <typename T>
T & Vector<T>::at(size_t n) {
	if (n > size_) {
		std::cerr << "Index out of range\n";
	}
	return data_[n];
}

template <typename T>
T const & Vector<T>::at(size_t n) const {
	if (n > size_) {
		std::cerr << "Index out of range\n";
	}
	return data_[n];
}

template <typename T>
Vector<T>::Vector(Vector<T> const & v): size_(v.size_), capacity_(v.capacity_), data_(new T[capacity_]) {
	for (size_t i = 0; i < size_; i++) {
		data_[i] = v.data_[i];
	}
}

template <typename T>
Vector<T> & Vector<T>::operator=(Vector<T> const &v) {
	if (this != &v) {
		delete[] data_;
		size_ = v.size_;
		capacity_ = v.capacity_;
		data_ = new T[capacity_];
		for (size_t i = 0; i < size_; i++) {
			data_[i] = v.data_[i];
		}
	}
	return *this;
}

template <typename T>
void Vector<T>::swap(Vector<T> &v) {
	std::swap(size_, v.size_);
	std::swap(capacity_, v.capacity_);
	std::swap(data_, v.data_);
}

template <typename T>
Vector<T>::Vector(Vector<T> &&v) {
	size_ = 0;
	capacity_ = 0;
	data_ = nullptr;
	swap(v);
}

template <typename T>
Vector<T> & Vector<T>::operator=(Vector<T> &&v) {
	swap(v);
	return *this;
}

template <typename T>
void Vector<T>::push_back(T const &val) {
	ensure_capacity();
	data_[size_] = val;
	size_++;
}

template <typename T>
void Vector<T>::push_back(T &&val) {
	ensure_capacity();
	data_[size_] = std::move(val);
	size_++;
}

template <typename T>
void Vector<T>::ensure_capacity() {
	if (size_ == capacity_) {
		inc_capacity(capacity_ * 2);
	}
}

template <typename T>
void Vector<T>::pop_back() {
	if (size_ == 0) {
		std::cerr << "Vector is empty\n";
	} else {
		size_--;
	}
}

template <typename T>
size_t Vector<T>::size() const {
	return size_;
}

template <typename T>
bool Vector<T>::empty() const {
	return size_ == 0;
}
