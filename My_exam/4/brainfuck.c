/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuzen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:21:37 by tjuzen            #+#    #+#             */
/*   Updated: 2019/05/07 16:21:38 by tjuzen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// Assignment name  : brainfuck
// Expected files   : *.c, *.h
// Allowed functions: write, malloc, free
// --------------------------------------------------------------------------------
//
// Write a Brainfuck interpreter program.
// The source code will be given as first parameter.
// The code will always be valid, with no more than 4096 operations.
// Brainfuck is a minimalist language. It consists of an array of bytes
// (in our case, let's say 2048 bytes) initialized to zero,
// and a pointer to its first byte.
//
// Every operator consists of a single character :
// - '>' increment the pointer ;
// - '<' decrement the pointer ;
// - '+' increment the pointed byte ;
// - '-' decrement the pointed byte ;
// - '.' print the pointed byte on standard output ;
// - '[' go to the matching ']' if the pointed byte is 0 (while start) ;
// - ']' go to the matching '[' if the pointed byte is not 0 (while end).
//
// Any other character is a comment.
//
// Examples:
//
// $>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
// >++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
// Hello World!$
// $>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
// Hi$
// $>./brainfuck | cat -e
// $

#include <unistd.h>
#include <stdlib.h>

char    *par(char *src, int way)
{
    int s;

    s = 0;
    while (1)
    {
        if (*src == '[')
            s++;
        else if (*src == ']')
            s--;
        if (s == 0)
            return (src);
        src += way;
    }
    return (NULL);
}

void    brainfuck(char *src, char *buf)
{
    while (*src != '\0')
    {
        if (*src == '>')
            buf++;
        else if (*src == '<')
            buf--;
        else if (*src == '+')
            (*buf)++;
        else if (*src == '-')
            (*buf)--;
        else if (*src == '.')
            write(1, buf, 1);
        else if (*src == '[' && !(*buf))
            src = par(src, 1);
        else if (*src == ']' && (*buf))
            src = par(src, -1);
        src++;
    }
}

int        main(int ac, char **av)
{
    char buf[2048];
    int a;

    if (ac > 1)
    {
        a = 0;
        while (a < 2048)
            buf[a++] = 0;
        brainfuck(av[1], buf);
    }
    else
        write(1, "\n", 1);
    return(0);
}
