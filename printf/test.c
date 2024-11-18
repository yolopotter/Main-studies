/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlopatin <vlopatin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:36:55 by vlopatin          #+#    #+#             */
/*   Updated: 2024/11/14 10:14:52 by vlopatin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int main()
{
	int i = 6;
	char arr[] = "abc";
	printf("%%", arr);
	return 0;
}
*/
#include <stdarg.h>
#include <stdio.h>

void print_integers(int count, ...) {
    va_list args;
    va_start(args, count);

    int value = va_arg(args, int);
    printf("%d ", value);

	value = va_arg(args, int);
    printf("%d ", value);

    va_end(args); // Clean up
    printf("\n");
}

int main() {
    printf("%x %%\n", 4294967294U, 3456);
    return 0;
}
