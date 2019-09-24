/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 14:23:51 by tjuzen            #+#    #+#             */
/*   Updated: 2019/05/07 14:23:52 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Assignment name  : ft_split
// Expected files   : ft_split.c
// Allowed functions: malloc
// --------------------------------------------------------------------------------
//
// Write a function that takes a string, splits it into words, and returns them as
// a NULL-terminated array of strings.
//
// A "word" is defined as a part of a string delimited either by spaces/tabs/new
// lines, or by the start/end of the string.
//
// Your function must be declared as follows:
//
// char    **ft_split(char *str);

#include <stdlib.h>

char        **ft_split(char *str)
{
    int        i;
    int        j;
    int        k;
    char    **split;

    i = 0;
    k = 0;
    if (!(split = (char **)malloc(sizeof(char *) * 256)))
        return (NULL);
    while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        i += 1;
    while (str[i])
    {
        j = 0;
        if (!(split[k] = (char *)malloc(sizeof(char) * 4096)))
            return (NULL);
        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i])
            split[k][j++] = str[i++];
        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i += 1;
        split[k][j] = '\0';
        k += 1;
    }
    split[k] = NULL;
    return (split);
}
