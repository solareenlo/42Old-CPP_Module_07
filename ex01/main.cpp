/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:54:07 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/22 21:59:38 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

template <typename T>
void printX(T const& x) {
    std::cout << x << " ";
}

template <typename T>
void incrementX(T& x) {
    x++;
}

template <typename T>
void decrementX(T& x) {
    x--;
}

template <typename T>
void output(T& arr, size_t len) {
    ::iter(arr, len, printX);
    std::cout << std::endl;
    ::iter(arr, len, incrementX);
    ::iter(arr, len, printX);
    ::iter(arr, len, decrementX);
    std::cout << std::endl;
    ::iter(arr, len, printX);
    std::cout << std::endl;
}

int main() {
    {
        std::cout << "< First parameter is NULL >" << std::endl;
        int* arr = NULL;
        ::iter(arr, 10, printX);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "< Third parameter is NULL >" << std::endl;
        void (*pfunc)(int const& x) = NULL;
        int arr[1] = {1};
        ::iter(arr, 10, pfunc);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "< Test Int Pointer array >" << std::endl;
        int a = 1;
        int const* arr[2] = {NULL, &a};
        size_t len = sizeof(arr) / sizeof(int const*);
        ::iter(arr, len, printX);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "< Test INT array >" << std::endl;
        int arr[3];
        for (int i = 0; i < 3; i++) {
            arr[i] = i;
        }
        size_t len = sizeof(arr) / sizeof(int);
        output(arr, len);
    }
    std::cout << std::endl;
    {
        std::cout << "< Test FLOAT array >" << std::endl;
        float arr[] = {1.1, 2.1, 3.1};
        size_t len = sizeof(arr) / sizeof(float);
        output(arr, len);
    }
    std::cout << std::endl;
    {
        std::cout << "< Test DOUBLE array >" << std::endl;
        double arr[] = {1.11, 2.11, 3.11};
        size_t len = sizeof(arr) / sizeof(double);
        output(arr, len);
    }
    std::cout << std::endl;
    {
        std::cout << "< Test STRING array >" << std::endl;
        std::string arr[] = {"a", "b", "c"};
        size_t len = sizeof(arr) / sizeof(arr[0]);
        ::iter(arr, len, printX);
        std::cout << std::endl;
    }
    return 0;
}
