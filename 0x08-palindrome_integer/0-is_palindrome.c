#include "palindrome.h"
/**
 * is_palindrome - checks whether a given unsigned integer is a palindrome
 * @n: integer to check for palindrome
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, remainder, original;

	original = n;

	/* reverse the int */
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	/* check if they are the same */
	if (original == reversed)
		return (1);
	return (0);
}
