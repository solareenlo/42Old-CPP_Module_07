/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayamamo <tayamamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:46:48 by tayamamo          #+#    #+#             */
/*   Updated: 2021/11/22 20:51:38 by tayamamo         ###   ########.fr       */
/*   Copyright 2021                                                           */
/* ************************************************************************** */

#ifndef EX01_ITER_HPP_
#define EX01_ITER_HPP_

#include <cstdlib>

template <typename T>
void iter(T* arr, size_t len, void (*f)(T const& x)) {
    if (arr == NULL || f == NULL) {
        return;
    }

    for (size_t i = 0; i < len; i++) {
        f(arr[i]);
    }
}

#endif  // EX01_ITER_HPP_
