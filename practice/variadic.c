#include <stdarg.h>
#include <stdio.h>

float	average(int n, ...)
{
	va_list	ap;
	int	total;
	int	i;

	va_start(ap, n);
	total = 0;
	i = 0;
	while (i < n)
	{
		total += va_arg(ap, int); // va_arg calls the next one every time is invoked
		i++;
	}
	return ((float)total / n);
}

int	main(void)
{
	float	average_age;
						  // The 5 is a flag
	average_age = average(3, 10, 15, 20);
	printf("The Average age is  %f\n", average_age);
	return (0);
}