/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:54:07 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/22 18:38:01 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "whatever.hpp"

int main(void) {
    int a = 2;
    int b = 3;

    std::cout << "a = " << a << ", b = " << b << std::endl;
    ::swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
    std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
    std::cout << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "c = " << c << ", d = " << d << std::endl;
    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
    std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
    std::cout << std::endl;

    double e = 0.0;
    double f = 42.01;

    std::cout << "e = " << e << ", f = " << f << std::endl;
    ::swap(e, f);
    std::cout << "e = " << e << ", f = " << f << std::endl;
    std::cout << "min( e, f ) = " << ::min(e, f) << std::endl;
    std::cout << "max( e, f ) = " << ::max(e, f) << std::endl;
    return 0;
}
