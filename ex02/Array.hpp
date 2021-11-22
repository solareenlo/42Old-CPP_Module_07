/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 23:45:30 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/23 00:57:42 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX02_ARRAY_HPP_
#define EX02_ARRAY_HPP_

#include <exception>

template <typename T>
class Array {
 public:
    Array() : n_(0), arr_(new T[0]) {}
    explicit Array(unsigned int n) : n_(n), arr_(new T[n]) {}
    virtual ~Array() { delete[] this->arr_; }
    Array(Array const& src) : n_(src.n_), arr_(new T[src.n_]) {
        for (unsigned int i = 0; i < this->n_; i++) {
            this->arr_[i] = src.arr_[i];
        }
    }

    Array& operator=(Array const& rhs) {
        if (this == &rhs) {
            return *this;
        }
        if (this->arr_) {
            this->~Array();
        }
        this->n_ = rhs.n_;
        this->arr_ = new T[this->n_];
        for (unsigned int i = 0; i < this->n_; i++) {
            this->arr_[i] = rhs.arr_[i];
        }
        return *this;
    }

    T const& operator[](unsigned int index) const {
        if (this->n_ < index + 1) {
            throw std::exception();
        }
        return this->arr_[index];
    }

    T& operator[](unsigned int index) {
        if (this->n_ < index + 1) {
            throw std::exception();
        }
        return this->arr_[index];
    }

    unsigned int size() const { return this->n_; }

 private:
    unsigned int n_;
    T* arr_;
};

#endif  // EX02_ARRAY_HPP_
