# Philosophers (Bonus) — Simulación de filósofos comensales con procesos y semáforos

## Descripción del Proyecto
Philosophers es un proyecto que simula el problema clásico de los **filósofos comensales**, implementado utilizando **procesos (fork) y semáforos POSIX** para la sincronización. Cada filósofo piensa, come y duerme siguiendo reglas estrictas de concurrencia para evitar **condiciones de carrera y bloqueos**.

Este proyecto es la versión *bonus*, donde se utiliza **multiprocesamiento en lugar de hilos**, y cada filósofo se representa como un proceso independiente. La sincronización de forks y la salida por pantalla se maneja mediante semáforos, garantizando un comportamiento consistente y evitando interbloqueos.

---

## Estructura del Proyecto

### Includes
- `philo_bonus.h`: Cabecera principal que define las estructuras `t_data` y `t_philo`, así como todas las funciones del programa.

### Src
Contiene toda la lógica del programa:
- `main.c`: Inicializa los datos y lanza los procesos filósofos.
- `init.c`: Configura las estructuras, semáforos y procesos.
- `philosopher.c`: Implementa la rutina de vida de cada filósofo.
- `monitor.c`: Hilo monitor que detecta la muerte de filósofos o cuando todos han comido la cantidad requerida.
- `utils.c`: Funciones auxiliares como `get_time`, `ft_usleep`, `ft_atoi` y `print_status`.
- `cleanup.c`: Libera memoria y cierra semáforos.

---

## Uso del Programa

El ejecutable se llama `philo_bonus`. Se ejecuta de la siguiente forma:

./philo_bonus number_of_philosophers time_to_die time_to_eat time_to_sleep [must_eat_times]


- `number_of_philosophers`: Número de filósofos a simular.
- `time_to_die`: Tiempo en milisegundos antes de que un filósofo muera si no ha comido.
- `time_to_eat`: Tiempo que tarda un filósofo en comer.
- `time_to_sleep`: Tiempo que tarda un filósofo en dormir.
- `[must_eat_times]` (opcional): Número de veces que cada filósofo debe comer. Si no se proporciona, el programa continúa hasta la muerte de algún filósofo.

---

## Funcionalidad

Cada filósofo sigue este ciclo:

1. **Pensando**: Reflexiona antes de intentar tomar los tenedores.
2. **Tomando tenedores**: Se asegura de tomar ambos tenedores antes de comer, usando semáforos para sincronizar.
3. **Comiendo**: Come durante `time_to_eat` milisegundos.
4. **Durmiendo**: Duerme durante `time_to_sleep` milisegundos.
5. **Repetición**: Repite el ciclo hasta que un filósofo muera o todos hayan alcanzado `must_eat_times`.

Se imprime en pantalla el estado de cada filósofo con marcas de tiempo relativas al inicio de la simulación.

---

## Manejo de Concurrencia

- **Semáforos**:
  - `forks`: Gestiona la disponibilidad de los tenedores.
  - `print`: Evita que múltiples procesos escriban al mismo tiempo.
  - `death`: Señaliza la muerte de un filósofo o la finalización de la simulación.

- **Monitores**:
  - Cada filósofo tiene un hilo monitor que revisa si ha pasado más tiempo que `time_to_die` desde su última comida.
  - Cuando un filósofo muere o todos han comido la cantidad requerida, se libera la simulación.

---

## Ejemplo de Ejecución
./philo_bonus 5 800 200 200

Esto simula 5 filósofos donde:
- Cada filósofo muere si no come en 800ms.
- Come durante 200ms.
- Duerme durante 200ms.
- La simulación termina si un filósofo muere.

Salida típica:
0 1 is thinking
0 2 is thinking
5 1 has taken a fork
5 1 has taken a fork
5 1 is eating
...
800 3 died

---

## Librerías y Dependencias
- Librerías estándar de C: `stdio.h`, `stdlib.h`, `unistd.h`, `string.h`.
- Librerías para concurrencia: `pthread.h`, `semaphore.h`, `fcntl.h`, `sys/stat.h`, `sys/time.h`, `signal.h`, `sys/wait.h`.

---

## Limpieza y Gestión de Recursos
El programa libera automáticamente todos los recursos:
- Semáforos cerrados y eliminados.
- Procesos hijos terminados.
- Memoria dinámica liberada.

---

## Conclusión

Philosophers (Bonus) es una implementación robusta del problema de los filósofos comensales usando **procesos y semáforos**, demostrando manejo seguro de concurrencia, sincronización y control de recursos compartidos.

