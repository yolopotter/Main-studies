/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:34:19 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/14 18:07:00 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_identifier(va_list args, char a)
{
	int	i;

	i = 0;
	if (a == 'c')
		i += ft_char(args);
	else if (a == 's')
		i += ft_string(args);
	else if (a == 'p')
		i += ft_pointer(args);
	else if (a == 'd' || a == 'i')
		i += ft_int(args);
	else if (a == 'u')
		i += ft_unsigned_int(args);
	else if (a == 'x')
		i += ft_hex(args, "lower");
	else if (a == 'X')
		i += ft_hex(args, "upper");
	else if (a == '%')
		i += write(1, "%", 1);
return (i);
}

int	ft_printf(const char *s, ...)
{
	va_list args;
	va_start(args, s);
	int	i;
	int	c;

	i = 0;
	c = 0;
	while(s[i])
	{
		if (s[i] == '%' && ft_strchr("cspdiuxX", s[i + 1]))
		{
			c += is_identifier(args, s[i + 1]);
			i++;
		}
		else
			c += write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return(c);
}

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

// Test 1: Testing pointer output with unsigned int
void test_tester1() {
    printf("Test tester NULL: \n");
    int j = ft_printf(" NULL %s NULL \n", NULL);
    int l = printf(" NULL %s NULL \n", NULL);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 2 Testing pointer output with unsigned int
void test_tester2() {
    printf("Test tester NULL: \n");
    int j = ft_printf(" %p %p \n", 0, 0);
    int l = printf(" %p %p \n", 0, 0);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

void test_tester3() {
    printf("Test tester more specifiers than arguments: \n");
    int j = ft_printf(" %p %p %p\n", "asd", "189");
    int l = printf(" %p %p %p\n", "asd", "189");
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}


// Test 1: Testing pointer output with unsigned int
void test1() {
    unsigned int b = 2326657;
    printf("Test 1: Testing pointer output with unsigned int\n");
    int j = ft_printf("%p\n", b);
    int l = printf("%p\n", b);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 2: Testing pointer output with signed int
void test2() {
    int b = 123456;
    printf("Test 2: Testing pointer output with signed int\n");
    int j = ft_printf("%p\n", b);
    int l = printf("%p\n", b);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 3: Testing integer output with signed int
void test3() {
    int b = 123456;
    printf("Test 3: Testing integer output with signed int\n");
    int j = ft_printf("%i\n", b);
    int l = printf("%i\n", b);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 4: Testing integer output with a string
void test4() {
    char arr[] = "1234";
    printf("Test 4: Testing integer output with a string\n");
    int j = ft_printf("%i\n", arr);
    int l = printf("%i\n", arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 5: Testing pointer output with a string
void test5() {
    char arr[] = "1234";
    printf("Test 5: Testing pointer output with a string\n");
    int j = ft_printf("%p\n", arr);
    int l = printf("%p\n", arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 6: Testing string output
void test6() {
    char arr[] = "1234";
    printf("Test 6: Testing string output\n");
    int j = ft_printf("%s\n", arr);
    int l = printf("%s\n", arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 7: Testing character output
void test7() {
    char a = 'e';
    printf("Test 7: Testing character output\n");
    int j = ft_printf("%c\n", a);
    int l = printf("%c\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Additional tests for edge cases and other format specifiers

// Test 8: Testing negative integer output
void test8() {
    int b = -987654;
    printf("Test 8: Testing negative integer output\n");
    int j = ft_printf("%i\n", b);
    int l = printf("%i\n", b);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 9: Testing unsigned integer output
void test9() {
    unsigned int b = 987654321;
    printf("Test 9: Testing unsigned integer output\n");
    int j = ft_printf("%u\n", b);
    int l = printf("%u\n", b);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 10: Testing zero integer output
void test10() {
    int b = 0;
    printf("Test 10: Testing zero integer output\n");
    int j = ft_printf("%i\n", b);
    int l = printf("%i\n", b);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}


int main() {
    // test_tester1();
	// test_tester2();
	test_tester3();
    // test1();
    // test2();
    // test3();
    // test4();
    // test5();
    // test6();
    // test7();
    // test8();
    // test9();
    // test10();
    return 0;
}
