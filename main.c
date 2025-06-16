/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:25:41 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/16 10:25:51 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>      // pour printf
#include "ft_printf.h"  // ton ft_printf

int main(void)
{
    int ret1, ret2;

    // Test 1 : Chaîne simple
    ret1 = ft_printf("Hello, world!\n");
    ret2 = printf("Hello, world!\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 2 : Caractère
    ret1 = ft_printf("Char: %c\n", 'A');
    ret2 = printf("Char: %c\n", 'A');
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 3 : String
    ret1 = ft_printf("String: %s\n", "OpenAI");
    ret2 = printf("String: %s\n", "OpenAI");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 4 : Integer
    ret1 = ft_printf("Int: %d\n", 42);
    ret2 = printf("Int: %d\n", 42);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 5 : Unsigned
    ret1 = ft_printf("Unsigned: %u\n", 3000000000U);
    ret2 = printf("Unsigned: %u\n", 3000000000U);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 6 : Hexa (lower and upper)
    ret1 = ft_printf("Hex lower: %x | upper: %X\n", 255, 255);
    ret2 = printf("Hex lower: %x | upper: %X\n", 255, 255);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 7 : Pointer
    void *ptr = &ret1;
    ret1 = ft_printf("Pointer: %p\n", ptr);
    ret2 = printf("Pointer: %p\n", ptr);
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 8 : Pourcentage
    ret1 = ft_printf("Percent: %%\n");
    ret2 = printf("Percent: %%\n");
    printf("Return values: ft_printf = %d, printf = %d\n\n", ret1, ret2);

    // Test 9 : Format NULL
    ret1 = ft_printf(NULL);
    printf("ft_printf(NULL) returned: %d (expected -1 or custom behavior)\n", ret1);

    return 0;
}

