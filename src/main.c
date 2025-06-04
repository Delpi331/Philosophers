#include "../includes/philo_bonus.h"

int main(int argc, char **argv) {
    t_data  data;
    
    if (argc < 5 || argc > 6) {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat "
               "time_to_sleep [must_eat_times]\n", argv[0]);
        return (1);
    }
    
    memset(&data, 0, sizeof(t_data));
    if (init_data(&data, argc, argv))
        return (1);
    
    if (init_philosophers(&data)) {
        cleanup(&data);
        return (1);
    }
    
    return (0);
}