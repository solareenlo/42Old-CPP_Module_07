/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:54:07 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/22 20:51:34 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>

#include "iter.hpp"

template <typename T>
void printX(T const& x) {
    std::cout << x << " ";
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
        size_t size = sizeof(arr) / sizeof(int const*);
        ::iter(arr, size, printX);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "< Test INT array >" << std::endl;
        int arr[] = {1, 2, 3};
        size_t size = sizeof(arr) / sizeof(int);
        ::iter(arr, size, printX);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "< Test FLOAT array >" << std::endl;
        float arr[] = {1.1, 2.1, 3.1};
        size_t size = sizeof(arr) / sizeof(float);
        ::iter(arr, size, printX);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "< Test DOUBLE array >" << std::endl;
        double arr[] = {1.11, 2.11, 3.11};
        size_t size = sizeof(arr) / sizeof(double);
        ::iter(arr, size, printX);
        std::cout << std::endl;
    }
    std::cout << std::endl;
    {
        std::cout << "< Test STRING array >" << std::endl;
        std::string arr[] = {"a", "b", "c"};
        size_t size = sizeof(arr) / sizeof(arr[0]);
        ::iter(arr, size, printX);
        std::cout << std::endl;
    }
    return 0;
}
