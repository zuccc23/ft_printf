#include <stdio.h>
#include <unistd.h>

int	print_address(void * ptr)
{
	unsigned long	p;

	if (!ptr)
		return (0);
	p = (long)ptr;
	write(1, "0x", 2);
	return (ft_putnbr_base(p, "0123456789abcdef") + 2);
}

int	main(void)
{
	int n = 1;
	printf("%p\n", &n);
	printf("%ld\n", (long)&n);
}