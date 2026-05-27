*This project has been created as part of the 42 curriculum by exia.*

# Description

Through this project 42 requires the student to show off their control of the race-conditions of multi-threading (and ofc, learning how to work with threads while doing it). A race condition happens when multiple threads attempts to use one single data from a certain point, such as files, variables...

The problem presented is the popular is similar to the [Dinning Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem), just that now the philosophers are coders, the forks are dongles and they will have to compile with both dongles in hands, right after drop them so the next can take them and start debugging and refactoring, then going back again the specified times. Also an arbitration policy used by the dongles must be set, it being fifo (first in first out) or edf (earliest deadline first).

The student will create a simulation with the arguments provided by the user.
>Note that none unexpected or uncontrolled errors must happen.

___

# Instructions

In order to compile this project, just use the rule ```make``` from the root of the dir. Then you can execute the main file with ```./codexion <number_of_coders> <time_to_compile> <time_to_debug> <time_to_refactor> <number_of_compiles_required> <dongle_cooldown> <scheduler>```.

> Note that all values must be positive integers, there are 2 schedulers (fifo and edf) and that times are interpreted as miliseconds.

___

# Resources

Here I'll just list all the resources used for the project.

- [Unix Threads in C playlist](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2) **(highly recommended if you are starting with threads in C)**
- [Dinning Philosophers Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)
- [Priority queue's video](https://www.youtube.com/watch?v=HqPJF2L5h9U) Tho this is a requisite of the project, there is no need into using it actually.
- [Claude](https://claude.ai/chat/) (This was used for learning use-cases, cleaner explainations... learning purposes)

___

# Additional sections

## - Blocking cases handled

To prevent deadlocks (Coffman’s conditions), the asymetric solution was introduced into this project, note that because of it, coders might need 3 rounds for the first compilation.

The starvation prevention is solved by a queue made for each dongle, where each coder hop in when they request the dongle. The order of the queue will be set depeding on the schedule mode, if it's fifo then it will just be the last, otherwise the last compilation times will be checked and the earliest deadline will be pushed first and the other behind.

For the cooldown handling, each dongle will have the last dropped time which will be updated each time someone finish compiling with it. Then if it is in cooldown, the coder will wait to pick it up.

Another thread will be checking the last_compile time from each coder, therefore if some coder burnout time has passed, the program will finish and the burnout message will be displayed.

All logs are controlled by one mutex, this way the printf overlapping is avoided. (Note that this is only necessary if you are using printf or multiple writes, write function uses the core to run).

## - Thread synchronization mechanisms

- pthread_mutex_t is a variable which can be locked and unlocked, normally locking it when you are using a shared variable and unlocking it after so that next coder can lock it and make it's own changes.
- pthread_cond_t is a signaling variable, which can be used both for receiving and sending signals to other threads through the same variable. Normally, it is used so that a thread waits until a condition. Then it keeps running with the mutex locked for it's own.

When the mutex is locked, you are free to make the ops you need with the variable that the mutex covers without any problem.

The problems that could happen if this is not done well, are the race conditions achieved by non thread-safe comms. For example:

There are 2 threads accesing to a variable and changing it's value, the first thread will be adding 5 and the second one will add 10. Normally, what we expect it happens, is that both threads add when they want no matter what, but just add it. These are the steps for them to do this operation:

1. Read the value
2. Do the operation with the value
3. Set the new value

If this is not controlled, when the first thread is doing the operation already with the old value, lets say 10 + 5, the second thread could be reading the value, it being 10. Then the first thread set the new value to 15 and so what we expect is that the second thread set it to 25. But this will not happen because it has already read the old value and the result of the operation will be 10 + 10, resulting in the set as 20 and not 25.

With a secure controll of this variable, we don't allow the second thread to starts it's exection until the first one finished, this way, second thread reads the new value set by first thread before starting.
