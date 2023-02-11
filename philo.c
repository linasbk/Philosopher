#include"philo.h"

int main(int ac, char **av)
{
	t_data	*data;

	if(ac != 5 && ac != 6)
		return (print_error("Wrong arguments!"));
	if(init(data, av) == SUCCESS)
		join();
	return(SUCCESS);
}