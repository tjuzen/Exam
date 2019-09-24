/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 13:44:49 by tjuzen            #+#    #+#             */
/*   Updated: 2019/05/07 13:44:51 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Assignment name  : ft_itoa_base
// Expected files   : ft_itoa_base.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
//
// Write a function that converts an integer value to a null-terminated string
// using the specified base and stores the result in a char array that you must
// allocate.
//
// The base is expressed as an integer, from 2 to 16. The characters comprising
// the base are the digits from 0 to 9, followed by uppercase letter from A to F.
//
// For example, base 4 would be "0123" and base 16 "0123456789ABCDEF".
//
// If base is 10 and value is negative, the resulting string is preceded with a
// minus sign (-). With any other base, value is always considered unsigned.
//
// Your function must be declared as follows:
//
// char	*ft_itoa_base(int value, int base);

#include <stdlib.h>

char    *ft_itoa_base(int value, int base)
{
    char    *s;
    long    n;
    int        sign;
    int        i;

    n = (value < 0) ? -(long)value : value;
    sign = (value < 0 && base == 10) ? -1 : 0;
    i = (sign == -1) ? 2 : 1;
    while ((n /= base) >= 1)
        i++;

    s = (char*)malloc(sizeof(char) * (i + 1));
    s[i] = '\0';
    n = (value < 0) ? -(long)value : value;

    while (i-- + sign)
    {
        s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
        n /= base;
    }

    (i == 0) ? s[i] = '-' : 0;
    return (s);
}
