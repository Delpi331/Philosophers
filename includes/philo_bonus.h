#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>
# include <pthread.h>

typedef struct s_data {
    int         num_philos;
    int         time_to_die;
    int         time_to_eat;
    int         time_to_sleep;
    int         must_eat_times;
    long        start_time;
    sem_t       *forks;
    sem_t       *print;
    sem_t       *death;
    pid_t       *pids;
}               t_data;

typedef struct s_philo {
    int         id;
    int         eat_count;
    long        last_meal;
    t_data      *data;
}               t_philo;

/* Functions */
int     init_data(t_data *data, int argc, char **argv);
int     init_philosophers(t_data *data);
void    philosopher_life(t_philo *philo);
void    *monitor_routine(void *arg);
void    cleanup(t_data *data);

/* Utils */
long    get_time(void);
void    print_status(t_philo *philo, char *status);
void    ft_usleep(long time);
int     ft_atoi(const char *str);

#endif
