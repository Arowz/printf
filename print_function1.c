#include "main.h"


/**
 * print_unsigned - To print an unsigned number
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags:  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}


/**
 * print_octal - to Prints an unsigned number in octal notation
 * @types:  arguments list
 * @buffer: Buffer array to handle print
 * @flags:  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[k--] = '0';

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - To Prints an unsigned number in hexadecimal notation
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags:  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: arguments list
 * @buffer: Buffer array to handle print
 * @flags:  active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}


/**
 * print_hexa - To print a hexadecimal number in lower or upper
 * @types: arguments list
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[k--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[k--] = flag_ch;
		buffer[k--] = '0';
	}

	k++;

	return (write_unsgnd(0, k, buffer, flags, width, precision, size));
}
