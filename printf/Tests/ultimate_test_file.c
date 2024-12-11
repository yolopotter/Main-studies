# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include "./libft/libft.h"
# include "./include/ft_printf.h"

//ccc -Wno-format -Iinclude ultimate_test_file.c libftprintf.a

// Test 1: Testing pointer output with unsigned int
// void test_tester1() {
//     printf("Test tester NULL: \n");
//     int j = ft_printf(" NULL %s NULL \n", NULL);
//     int l = printf(" NULL %s NULL \n", NULL);
//     printf("ft_printf result: %i\n", j);
//     printf("printf result: %i\n\n", l);
// }

// // Test 2 Testing pointer output with unsigned int
// void test_tester2() {
//     printf("Test tester NULL: \n");
//     int j = ft_printf(" %p %p \n", 0, 0);
//     int l = printf(" %p %p \n", 0, 0);
//     printf("ft_printf result: %i\n", j);
//     printf("printf result: %i\n\n", l);
// }

// Test 1: Testing pointer output with unsigned int
// void test1() {
//     unsigned int b = 2326657;
//     printf("Test 1: Testing pointer output with unsigned int\n");
//     int j = ft_printf("%p\n", b);
//     int l = printf("%p\n", b);
//     printf("ft_printf result: %i\n", j);
//     printf("printf result: %i\n\n", l);
// }

// // Test 2: Testing pointer output with signed int
// void test2() {
//     int b = 123456;
//     printf("Test 2: Testing pointer output with signed int\n");
//     int j = ft_printf("%p\n", b);
//     int l = printf("%p\n", b);
//     printf("ft_printf result: %i\n", j);
//     printf("printf result: %i\n\n", l);
// }

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
// void test4() {
//     char arr[] = "1234";
//     printf("Test 4: Testing integer output with a string\n");
//     int j = ft_printf("%i\n", arr);
//     int l = printf("%i\n", arr);
//     printf("ft_printf result: %i\n", j);
//     printf("printf result: %i\n\n", l);
// }

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
// void test11() {
//     printf("Test 11: wrong/no specifier\n\n");
// 	printf("\n");
//     int j = ft_printf("%");
// 	printf("\n");
//     int l = printf("%");
// 	printf("\n");
//     printf("ft_printf result: %i\n", j);
//     printf("printf result: %i\n\n", l);
// }

// // Test 12: Testing zero integer output
// void test12() {
//     printf("Test 12: wrong/no specifier\n");
//     int j = ft_printf("%k");
//     int l = printf("%k");
//     printf("ft_printf result: %i\n", j);
//     printf("printf result: %i\n\n", l);
// }

// // Test 13: Testing zero integer output
// void test13() {
//     printf("Test 13: wrong/no specifier\n");
//     int j = ft_printf("abc%");
//     int l = printf("abc%");
//     printf("ft_printf result: %i\n", j);
//     printf("printf result: %i\n\n", l);
// }

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
    test3();
    // test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
	// test11();
	// test12();
	// test13();
	cross_test1();
    cross_test2();
    cross_test3();
    cross_test4();
    cross_test5();
    cross_test6();
    cross_test7();
    cross_test8();
    multi_test1();
    multi_test2();
    multi_test3();
    multi_test4();
    multi_test5();
    multi_test6();
    multi_test7();
    multi_test8();
    multi_test9();
    multi_test10();
	test_extra_arguments1();
	test_extra_arguments2();
    return 0;
}
