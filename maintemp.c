#include <limits.h>
#include "libft/libft.h"


int	main(void)
{
	char nb[] = "2147483647";
	char nb2[] = "2147483648";

	printf("%i\n", ft_atoi(nb));
	printf("%ld\n", ft_atoi(nb2));
	return (0);
}
