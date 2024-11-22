# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"

int		ft_printf(const char *s, ...);

void	ft_putstr(char *str);
int		ft_putnbr_base(unsigned long nbr, char	*base);
char	*ft_utoa(unsigned int n);

int		ft_char(va_list args);
int		ft_hex(va_list args, char *case_type);
int		ft_int(va_list args);
int		ft_pointer(va_list args);
int		ft_string(va_list args);
int		ft_unsigned_int(va_list args);

static	char	*special_case(void)
{
	char	*arr;
	int		i;
	char	*nbr;

	nbr = "-2147483648";
	arr = malloc(12 * sizeof(char));
	if (!arr)
		return (NULL);
	i = 0;
	while (nbr[i])
	{
		arr[i] = nbr[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

static	int	lenint_itoa(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		len += 1;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

static	int	sign_conversion(int n, int *sign)
{
	if (n < 0)
	{
		*sign = -1;
		n = -n;
	}
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		sign;

	if (n == -2147483648)
	{
		str = special_case();
		return (str);
	}
	len = lenint_itoa(n);
	str = (char *)malloc(1 + len * sizeof(char));
	if (!str)
		return (NULL);
	sign = 1;
	n = sign_conversion(n, &sign);
	str[len] = 0;
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

static	int	lenint(unsigned int n)
{
	size_t	len;

	len = 0;
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char	*str;
	size_t	len;

	len = lenint(n);
	str = (char *)malloc(1 + len * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_unsigned_int(va_list args)
{
	unsigned int		value;
	int					str_len;
	char				*uitoa_str;

	value = va_arg(args, unsigned int);
	uitoa_str = ft_utoa(value);
	ft_putstr(uitoa_str);
	str_len = strlen(uitoa_str);
	free(uitoa_str);
	return(str_len);
}

int	ft_string(va_list args)
{
	char	*value;

	value = va_arg(args, char*);
	if (!value)
	{
		ft_putstr("(null)");
		return (6);
	}
	else
		ft_putstr(value);
	return(strlen(value));
}

int	ft_putnbr_base(unsigned long nbr, char	*base)
{
	unsigned long	base_len;
	int				count;

	count = 0;
	base_len = strlen(base);
	if(nbr >= base_len)
		count += ft_putnbr_base(nbr / base_len, base);
	count += write(1, &base[nbr % base_len] ,1);
	return (count);
}

int	ft_pointer(va_list args)
{
	void	*value;
	int		count;

	count = 0;
	value = va_arg(args, void*);
	if (value == 0)
		count += write(1, "(nil)", 5);
	else
	{
		count += write(1, "0x", 2);
		count += ft_putnbr_base((unsigned long)value, "0123456789abcdef");
	}
	return(count);
}

int	ft_int(va_list args)
{
	int		value;
	int		str_len;
	char	*itoa_str;

	value = va_arg(args, int);
	itoa_str = ft_itoa(value);
	ft_putstr(itoa_str);
	str_len = strlen(itoa_str);
	free(itoa_str);
	return(str_len);
}

int	ft_hex(va_list args, char *case_type)
{
	unsigned int	value;
	int				count;

	count = 0;
	value = va_arg(args, unsigned int);
	if (strncmp(case_type, "lower", strlen("upper")) == 0)
		count += ft_putnbr_base((unsigned long)value, "0123456789abcdef");
	else if (strncmp(case_type, "upper", strlen("upper")) == 0)
		count += ft_putnbr_base((unsigned long)value, "0123456789ABCDEF");
	return (count);
}

int	ft_char(va_list args)
{
	char	value;

	value = va_arg(args, int);
	write(1, &value, 1);
	return (1);
}

static int	is_identifier(va_list args, char a)
{
	int	c;

	c = 0;
	if (a == 'c')
		c += ft_char(args);
	else if (a == 's')
		c += ft_string(args);
	else if (a == 'p')
		c += ft_pointer(args);
	else if (a == 'd' || a == 'i')
		c += ft_int(args);
	else if (a == 'u')
		c += ft_unsigned_int(args);
	else if (a == 'x')
		c += ft_hex(args, "lower");
	else if (a == 'X')
		c += ft_hex(args, "upper");
	else if (a == '%')
		c += write(1, "%", 1);
	return (c);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			i;
	int			c;

	va_start (args, s);
	i = 0;
	c = 0;
	while (s[i])
	{
		if (s[i] == '%' && (!strchr("cspdiuxX%", s[i + 1]) || s[i + 1] == '\0'))
			return (-1);
		if (s[i] == '%' && strchr("cspdiuxX%", s[i + 1]))
		{
			c += is_identifier(args, s[i + 1]);
			i++;
		}
		else
			c += write(1, &s[i], 1);
		i++;
	}
	va_end (args);
	return (c);
}


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

// Test 11: Testing zero integer output
void test11() {
    printf("Test 11: wrong/no specifier\n\n");
	printf("\n");
    int j = ft_printf("%");
	printf("\n");
    int l = printf("%");
	printf("\n");
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 12: Testing zero integer output
void test12() {
    printf("Test 12: wrong/no specifier\n");
    int j = ft_printf("%k");
    int l = printf("%k");
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 13: Testing zero integer output
void test13() {
    printf("Test 13: wrong/no specifier\n");
    int j = ft_printf("abc%");
    int l = printf("abc%");
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

#include <stdio.h>

// Cross-Test 1: Integer and pointer with the same value
void cross_test1() {
    int a = 123456;
    printf("Cross Test 1: Integer and Pointer with the same value\n");
    int j = ft_printf("Integer: %i\n", a);
    int l = printf("Integer: %i\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("Pointer: %p\n", &a);
    l = printf("Pointer: %p\n", &a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Cross-Test 2: Pointer and string (address of string)
void cross_test2() {
    char arr[] = "Hello, world!";
    printf("Cross Test 2: Pointer and String (address of string)\n");
    int j = ft_printf("String: %s\n", arr);
    int l = printf("String: %s\n", arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("Pointer to String: %p\n", arr);
    l = printf("Pointer to String: %p\n", arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Cross-Test 3: Integer and hexadecimal (decimal to hex)
void cross_test3() {
    int a = 123456;
    printf("Cross Test 3: Integer and Hexadecimal (decimal to hex)\n");
    int j = ft_printf("Integer: %i\n", a);
    int l = printf("Integer: %i\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("Hexadecimal: %x\n", a);
    l = printf("Hexadecimal: %x\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("Hexadecimal (uppercase): %X\n", a);
    l = printf("Hexadecimal (uppercase): %X\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Cross-Test 4: Integer and unsigned integer (positive number)
void cross_test4() {
    unsigned int a = 123456;
    printf("Cross Test 4: Integer and Unsigned Integer (positive number)\n");
    int j = ft_printf("Signed Integer: %i\n", a);
    int l = printf("Signed Integer: %i\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("Unsigned Integer: %u\n", a);
    l = printf("Unsigned Integer: %u\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Cross-Test 5: Negative integer and unsigned integer (negative number)
void cross_test5() {
    int a = -123456;
    printf("Cross Test 5: Negative Integer and Unsigned Integer (negative number)\n");
    int j = ft_printf("Signed Integer: %i\n", a);
    int l = printf("Signed Integer: %i\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("Unsigned Integer: %u\n", a);
    l = printf("Unsigned Integer: %u\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Cross-Test 6: Integer and character (ASCII value as integer)
void cross_test6() {
    char a = 'A';
    printf("Cross Test 6: Integer and Character (ASCII value as integer)\n");
    int j = ft_printf("Character: %c\n", a);
    int l = printf("Character: %c\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("Integer (ASCII value): %i\n", a);
    l = printf("Integer (ASCII value): %i\n", a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Cross-Test 7: String and pointer (address of string)
void cross_test7() {
    char arr[] = "Hello, world!";
    printf("Cross Test 7: String and Pointer (address of string)\n");
    int j = ft_printf("String: %s\n", arr);
    int l = printf("String: %s\n", arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("Pointer to String: %p\n", arr);
    l = printf("Pointer to String: %p\n", arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Cross-Test 8: Character and string (character and string literal comparison)
void cross_test8() {
    char c = 'A';
    char arr[] = "A";
    printf("Cross Test 8: Character and String (comparison)\n");
    int j = ft_printf("Character: %c\n", c);
    int l = printf("Character: %c\n", c);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);

    j = ft_printf("String: %s\n", arr);
    l = printf("String: %s\n", arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 1: Integer and string in a single format string
void multi_test1() {
    int a = 12345;
    char arr[] = "Hello, world!";
    printf("Multi Test 1: Integer and String\n");
    int j = ft_printf("Integer: %i, String: %s\n", a, arr);
    int l = printf("Integer: %i, String: %s\n", a, arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 2: Character and pointer in a single format string
void multi_test2() {
    char c = 'A';
    char arr[] = "Address of array";
    printf("Multi Test 2: Character and Pointer\n");
    int j = ft_printf("Character: %c, Pointer: %p\n", c, arr);
    int l = printf("Character: %c, Pointer: %p\n", c, arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 3: Integer, hexadecimal, and string
void multi_test3() {
    int a = 123456;
    printf("Multi Test 3: Integer, Hexadecimal, and String\n");
    int j = ft_printf("Integer: %i, Hexadecimal: %x, String: %s\n", a, a, "Test");
    int l = printf("Integer: %i, Hexadecimal: %x, String: %s\n", a, a, "Test");
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 4: Signed and unsigned integers
void multi_test4() {
    int a = -12345;
    unsigned int b = 12345;
    printf("Multi Test 4: Signed and Unsigned Integers\n");
    int j = ft_printf("Signed: %i, Unsigned: %u\n", a, b);
    int l = printf("Signed: %i, Unsigned: %u\n", a, b);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 5: Multiple hexadecimal (lowercase and uppercase)
void multi_test5() {
    int a = 123456;
    printf("Multi Test 5: Lowercase and Uppercase Hexadecimal\n");
    int j = ft_printf("Lowercase Hex: %x, Uppercase Hex: %X\n", a, a);
    int l = printf("Lowercase Hex: %x, Uppercase Hex: %X\n", a, a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 6: Integer, character, and percentage
void multi_test6() {
    int a = 12345;
    char c = 'Z';
    printf("Multi Test 6: Integer, Character, and Percentage\n");
    int j = ft_printf("Integer: %i, Character: %c, Percentage: %%\n", a, c);
    int l = printf("Integer: %i, Character: %c, Percentage: %%\n", a, c);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 7: Pointer, string, and hexadecimal
void multi_test7() {
    int a = 12345;
    char *str = "Test string";
    printf("Multi Test 7: Pointer, String, and Hexadecimal\n");
    int j = ft_printf("Pointer: %p, String: %s, Hex: %x\n", &a, str, a);
    int l = printf("Pointer: %p, String: %s, Hex: %x\n", &a, str, a);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 8: String and percentage symbols
void multi_test8() {
    char *str = "Hello World";
    printf("Multi Test 8: String and Percentage Symbols\n");
    int j = ft_printf("String: %s %% %% %s\n", str, str);
    int l = printf("String: %s %% %% %s\n", str, str);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 9: Mixing Integer, Character, and Pointer
void multi_test9() {
    int a = 12345;
    char c = 'X';
    char arr[] = "Pointer example";
    printf("Multi Test 9: Integer, Character, and Pointer\n");
    int j = ft_printf("Integer: %i, Character: %c, Pointer: %p\n", a, c, arr);
    int l = printf("Integer: %i, Character: %c, Pointer: %p\n", a, c, arr);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

// Test 10: Multiple specifiers, mixing unsigned, integer, and string
void multi_test10() {
    int a = 123456;
    unsigned int b = 654321;
    char *str = "Formatted string!";
    printf("Multi Test 10: Multiple specifiers with unsigned, integer, and string\n");
    int j = ft_printf("Signed: %i, Unsigned: %u, String: %s\n", a, b, str);
    int l = printf("Signed: %i, Unsigned: %u, String: %s\n", a, b, str);
    printf("ft_printf result: %i\n", j);
    printf("printf result: %i\n\n", l);
}

void test_extra_arguments1() {
    int a = 42;
    char *str = "Hello, World!";
    char c = 'X';  // This should be ignored as there is no specifier for '%c'

    printf("Test 1: Extra arguments with integer and string specifiers\n");
    int j = ft_printf("Integer: %d, String: %s\n", a, str, c);  // c will be ignored
    int l = printf("Integer: %d, String: %s\n", a, str);  // Standard printf

    printf("ft_printf result: %d\n", j);
    printf("printf result: %d\n\n", l);
}

void test_extra_arguments2() {
    int num = 123456;
    char *str = "This is a test string";
    char *ptr = str;  // A pointer argument

    printf("Test 2: Extra arguments with pointer and unsigned integer specifiers\n");
    int j = ft_printf("Pointer: %p, Unsigned: %u\n", ptr, num, str);  // str will be ignored
    int l = printf("Pointer: %p, Unsigned: %u\n", ptr, num);  // Standard printf

    printf("ft_printf result: %d\n", j);
    printf("printf result: %d\n\n", l);
}


int main() {
	// test_tester1();
	// test_tester2();
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
	// test11();
	// test12();
	// test13();
	// cross_test1();
    // cross_test2();
    // cross_test3();
    // cross_test4();
    // cross_test5();
    // cross_test6();
    // cross_test7();
    // cross_test8();
    // multi_test1();
    // multi_test2();
    // multi_test3();
    // multi_test4();
    // multi_test5();
    // multi_test6();
    // multi_test7();
    // multi_test8();
    // multi_test9();
    // multi_test10();
	// test_extra_arguments1();
	// test_extra_arguments2();
    return 0;
}
