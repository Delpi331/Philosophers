#include "../includes/philo_bonus.h"

void philosopher_life(t_philo *philo) {
    pthread_t monitor_thread;
    
    pthread_create(&monitor_thread, NULL, monitor_routine, philo);
    pthread_detach(monitor_thread);
    
    while (1) {
        print_status(philo, "is thinking");
        
        sem_wait(philo->data->forks);
        print_status(philo, "has taken a fork");
        sem_wait(philo->data->forks);
        print_status(philo, "has taken a fork");
        
        print_status(philo, "is eating");
        philo->last_meal = get_time();
        ft_usleep(philo->data->time_to_eat);
        philo->eat_count++;
        
        sem_post(philo->data->forks);
        sem_post(philo->data->forks);
        
        print_status(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep);
    }
}