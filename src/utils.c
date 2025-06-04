#include "../includes/philo_bonus.h"

long get_time(void) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int ft_atoi(const char *str) {
    int res = 0;
    int sign = 1;
    
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-') sign = -1;
    if (*str == '-' || *str == '+') str++;
    while (*str >= '0' && *str <= '9') {
        res = res * 10 + (*str - '0');
        str++;
    }
    return (res * sign);
}