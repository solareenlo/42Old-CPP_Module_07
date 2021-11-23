/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:12:27 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/23 18:12:03 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

#include "Array.hpp"

#define MAX_VAL 750

template <typename T>
void print_array(Array<T> const& arr) {
    for (int i = 0; i < static_cast<int>(arr.size()); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void _test(Array<T>& a) {
    try {
        std::cout << "Array size: " << a.size() << std::endl;
        if (a.size() < 1) {
            return;
        }
        for (int i = 0; i < static_cast<int>(a.size()); i++) {
            a[i] = i;
        }
        print_array(a);

        Array<T> b;
        b = a;
        print_array(b);

        Array<T> c(a);
        print_array(c);
        std::cout << std::endl;

        a[0] = static_cast<T>(-1.1);
        b[0] = static_cast<T>(-2.2);
        c[0] = static_cast<T>(-3.3);
        print_array(a);
        print_array(b);
        print_array(c);
    } catch (std::exception& e) {
        std::cout << "error: " << e.what() << std::endl;
    }
}

int main(int, char**) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    std::srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = std::rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    // SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "Random number Success!" << std::endl;
    try {
        numbers[-2] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    try {
        numbers[MAX_VAL] = 0;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = rand();
    }
    //delete[] mirror;  //
    std::cout << std::endl;

    {
        std::cout << "< TEST: Exception >" << std::endl;
        try {
            Array<int> a(3);
            for (int i = 0; i < static_cast<int>(a.size()) + 1; i++) {
                a[i] = i;
            }
        } catch (std::exception& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "< TEST: Type is Int >" << std::endl;
        Array<int> a(3);
        _test(a);
    }
    std::cout << std::endl;
    {
        std::cout << "< TEST: Type is Double >" << std::endl;
        Array<double> a(4);
        _test(a);
    }
    std::cout << std::endl;
    {
        std::cout << "< TEST: Size is 0 >" << std::endl;
        Array<double> a(0);
        _test(a);
    }
    return 0;
}
