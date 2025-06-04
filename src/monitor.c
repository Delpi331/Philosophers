#include "../includes/philo_bonus.h"

void *monitor_routine(void *arg) {
    t_philo *philo = (t_philo *)arg;
    t_data  *data = philo->data;
    
    while (1) {
        if (get_time() - philo->last_meal > data->time_to_die) {
            sem_wait(data->print);
            printf("%ld %d died\n", get_time() - data->start_time, philo->id);
            sem_post(data->death);
            break;
        }
        
        if (data->must_eat_times != -1 && 
            philo->eat_count >= data->must_eat_times) {
            sem_post(data->death);
            break;
        }
        usleep(1000);
    }
    return (NULL);
}