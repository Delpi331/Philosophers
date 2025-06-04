#include "../includes/philo_bonus.h"

void cleanup(t_data *data) {
    int i;
    
    if (!data) return;
    
    if (data->pids) {
        for (i = 0; i < data->num_philos; i++)
            if (data->pids[i] > 0)
                kill(data->pids[i], SIGKILL);
        free(data->pids);
    }
    
    if (data->forks) {
        sem_close(data->forks);
        sem_unlink("/forks");
    }
    if (data->print) {
        sem_close(data->print);
        sem_unlink("/print");
    }
    if (data->death) {
        sem_close(data->death);
        sem_unlink("/death");
    }
}

int init_data(t_data *data, int argc, char **argv) {
    data->num_philos = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    data->must_eat_times = (argc == 6) ? ft_atoi(argv[5]) : -1;
    
    data->pids = malloc(sizeof(pid_t) * data->num_philos);
    if (!data->pids) return (1);
    
    sem_unlink("/forks");
    sem_unlink("/print");
    sem_unlink("/death");
    
    data->forks = sem_open("/forks", O_CREAT, 0644, data->num_philos);
    data->print = sem_open("/print", O_CREAT, 0644, 1);
    data->death = sem_open("/death", O_CREAT, 0644, 0);
    
    if (data->forks == SEM_FAILED || data->print == SEM_FAILED || 
        data->death == SEM_FAILED) {
        cleanup(data);
        return (1);
    }
    
    data->start_time = get_time();
    return (0);
}

int init_philosophers(t_data *data) {
    int         i;
    t_philo     *philo;
    pthread_t   monitor_thread;

    philo = malloc(sizeof(t_philo) * data->num_philos);
    if (!philo) return (1);
    
    for (i = 0; i < data->num_philos; i++) {
        philo[i].id = i + 1;
        philo[i].eat_count = 0;
        philo[i].last_meal = data->start_time;
        philo[i].data = data;
        
        data->pids[i] = fork();
        if (data->pids[i] == 0) {
            philosopher_life(&philo[i]);
            exit(0);
        }
    }
    
    pthread_create(&monitor_thread, NULL, monitor_routine, philo);
    pthread_detach(monitor_thread);
    
    sem_wait(data->death);
    cleanup(data);
    free(philo);
    return (0);
}