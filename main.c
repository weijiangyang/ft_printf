/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weiyang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:20:56 by weiyang           #+#    #+#             */
/*   Updated: 2025/06/23 10:42:22 by weiyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h" // Assure-toi d'inclure ton header

int main(void)
{
    int ret1, ret2;
    unsigned int value;
    void *ptr;
    int	 x;

    x = 42;
    value  = 305441741;
    // Test 1 : Chaîne simple
    ret1 = printf("Hello, world!\n");
    ret2 = ft_printf("Hello, world!\n");
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 2 : Chaîne avec format %s
    ret1 = printf("String: %s\n", "Test");
    ret2 = ft_printf("String: %s\n", "Test");
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 3 : Format %d et %i
    ret1 = printf("Int: %d %i\n", 42, -42);
    ret2 = ft_printf("Int: %d %i\n", 42, -42);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 4 : Format %u
    ret1 = printf("Unsigned: %u\n", 3000000000U);
    ret2 = ft_printf("Unsigned: %u\n", 3000000000U);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 5 : Format %x et %X
    ret1 = printf("Hex: %x %X\n", 255, 255);
    ret2 = ft_printf("Hex: %x %X\n", 255, 255);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 6 : Format %p
    ptr = &ret1;
    ret1 = printf("Pointer: %p\n", ptr);
    ret2 = ft_printf("Pointer: %p\n", ptr);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 7 : Format %%
    ret1 = printf("Percent: %%\n");
    ret2 = ft_printf("Percent: %%\n");
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 8 : Chaine avec flag '-'
    ret1 = printf("Left aligned: |%-10s|\n", "Hello");
    ret2 = ft_printf("Left aligned: |%-10s|\n", "Hello");
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 9 : Int avec flag '0'
    ret1 = printf("Zero padded: |%010d|\n", 42);
    ret2 = ft_printf("Zero padded: |%010d|\n", 42);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 10 : Hex avec flag '#'
    ret1 = printf("Hex with #: |%#x|\n", 255);
    ret2 = ft_printf("Hex with #: |%#x|\n", 255);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 11 : int positive  avec flag '+'
    ret1 = printf("Plus sign: |%+d|\n", 42);
    ret2 = ft_printf("Plus sign: |%+d|\n", 42);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 12 : int positive  avec espace (' ')
    ret1 = printf("Space flag: |% d|\n", 42);
    ret2 = ft_printf("Space flag: |% d|\n", 42);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 13 : chaine avec  précision 
    ret1 = printf("Precision string: |%.5s|\n", "abcdef");
    ret2 = ft_printf("Precision string: |%.5s|\n", "abcdef");
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test 14 : int avc précision 
    ret1 = printf("Precision int: |%.5d|\n", 42);
    ret2 = ft_printf("Precision int: |%.5d|\n", 42);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test combinaison flags : 0 et + avec largeur
    ret1 = printf("Combo: |%+08d|\n", 42);
    ret2 = ft_printf("Combo: |%+08d|\n", 42);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

   // Test simple %x
    ret1 = printf("Hex lowercase: %x\n", value);
    ret2 = ft_printf("Hex lowercase: %x\n", value);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test simple %X
    ret1 = printf("Hex uppercase: %X\n", value);
    ret2 = ft_printf("Hex uppercase: %X\n", value);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test avec flag #
    ret1 = printf("Hex with #: %#x\n", value);
    ret2 = ft_printf("Hex with #: %#x\n", value);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test avec flag # et %X
    ret1 = printf("Hex with #: %#X\n", value);
    ret2 = ft_printf("Hex with #: %#X\n", value);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test avec flag 0 et largeur
    ret1 = printf("Zero padded: |%08x|\n", value);
    ret2 = ft_printf("Zero padded: |%08x|\n", value);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test avec flag - et largeur
    ret1 = printf("Left aligned: |%-10x|\n", value);
    ret2 = ft_printf("Left aligned: |%-10x|\n", value);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test précision
    ret1 = printf("Precision: |%.6x|\n", value);
    ret2 = ft_printf("Precision: |%.6x|\n", value);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test précision et largeur
    ret1 = printf("Width & Precision: |%10.6x|\n", value);
    ret2 = ft_printf("Width & Precision: |%10.6x|\n", value);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test zéro avec précision 0
    ret1 = printf("Zero with .0: |%.0x|\n", 0);
    ret2 = ft_printf("Zero with .0: |%.0x|\n", 0);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test zéro avec #
    ret1 = printf("Zero with #: |%#x|\n", 0);
    ret2 = ft_printf("Zero with #: |%#x|\n", 0);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test simple pointeur
    ret1 = printf("Pointer: %p\n", ptr);
    ret2 = ft_printf("Pointer: %p\n", ptr);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test NULL pointeur
    ret1 = printf("NULL pointer: %p\n", NULL);
    ret2 = ft_printf("NULL pointer: %p\n", NULL);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test avec texte autour
    ret1 = printf("Addr of x is: [%p]\n", &x);
    ret2 = ft_printf("Addr of x is: [%p]\n", &x);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

    // Test dans une chaîne complexe
    ret1 = printf("x = %d, address = %p, again = %p\n", x, &x, &x);
    ret2 = ft_printf("x = %d, address = %p, again = %p\n", x, &x, &x);
    printf("printf returned: %d, ft_printf returned: %d\n\n", ret1, ret2);

     // Test simple %%
//    ret1 = printf("Percent: %%\n");
    ret2 = ft_printf("Percent: %%\n");
    printf("ft_printf returned: %d\n\n", ret2);

    // Test avec largeur
//    ret1 = printf("Width: |%5%|\n");
    ret2 = ft_printf("Width: |%5%|\n");
    printf("ft_printf returned: %d\n\n", ret2);

    // Test avec flag '-' (aligné à gauche)
//    ret1 = printf("Left align: |%-5%|\n");
    ret2 = ft_printf("Left align: |%-5%|\n");
    printf("ft_printf returned: %d\n\n", ret2);

    // Test avec flag '0' (remplissage par zéro)
  //  ret1 = printf("Zero padded: |%05%|\n");
    ret2 = ft_printf("Zero padded: |%05%|\n");
    printf("ft_printf returned: %d\n\n", ret2);

    // Test combinaison de flags invalides (pas de sens ici mais doit matcher printf)
//    ret1 = printf("Combo (ignored flags): |%-05%|\n");
    ret2 = ft_printf("Combo (ignored flags): |%-05%|\n");
    printf("ft_printf returned: %d\n\n", ret2);
    return 0;
}

