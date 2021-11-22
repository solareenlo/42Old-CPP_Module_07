/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 17:44:16 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/22 18:35:57 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX00_WHATEVER_HPP_
#define EX00_WHATEVER_HPP_

#include <cstdlib>

template <typename T>
void swap(T& a, T& b) {
    T tmp;
    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T const& min(T const& a, T const& b) {
    if (a < b) {
        return a;
    }
    return b;
}

template <typename T>
T const& max(T const& a, T const& b) {
    if (a > b) {
        return a;
    }
    return b;
}

#endif  // EX00_WHATEVER_HPP_
