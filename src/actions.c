#include "../includes/philo_bonus.h"

void print_status(t_philo *philo, char *status) {
    sem_wait(philo->data->print);
    printf("%ld %d %s\n", get_time() - philo->data->start_time, 
           philo->id, status);
    sem_post(philo->data->print);
}

void ft_usleep(long time) {
    long start = get_time();
    while (get_time() - start < time)
        usleep(100);
}