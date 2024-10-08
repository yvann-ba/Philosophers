/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybarbot <ybarbot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 10:10:57 by ybarbot           #+#    #+#             */
/*   Updated: 2024/08/30 11:59:06 by ybarbot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = '0' + (n % 10);
	write(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(STDOUT_FILENO, str++, 1);
}

void	safe_write(t_philo *philo, char *msg)
{
	long long	current_time;
	int			should_write;

	pthread_mutex_lock(&philo->params->is_dead_mutex);
	pthread_mutex_lock(&philo->params->all_eaten_mutex);
	should_write = (philo->params->is_dead != 1 \
	&& philo->params->all_eaten < philo->params->num_philos);
	pthread_mutex_unlock(&philo->params->all_eaten_mutex);
	if (should_write)
	{
		pthread_mutex_lock(&philo->params->write_mutex);
		current_time = get_elapsed_time(philo->params->start_time);
		ft_putnbr(current_time);
		ft_putstr(" ");
		ft_putnbr(philo->id);
		ft_putstr(msg);
		pthread_mutex_unlock(&philo->params->write_mutex);
	}
	pthread_mutex_unlock(&philo->params->is_dead_mutex);
}
