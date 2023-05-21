# philosophers

## Table of Contents
* [General Info](#general-information)
* [Problem Description](#problem-description)
* [Implementation](#implementation)
* [Setup](#setup)
* [Usage](#usage)

## General Information
This project involves solving the classic dining philosophers problem using threads and mutexes in C. The dining philosophers problem is a classic example of a concurrency problem where multiple processes compete for shared resources without any coordination or communication.

## Problem Description
In the dining philosophers problem, there are n philosophers seated around a circular table. Each philosopher has a plate of spaghetti and a fork to their left and right. However, there are only n forks, one between each pair of adjacent philosophers. In order to eat, a philosopher must pick up both the fork to their left and the fork to their right. Once a philosopher has both forks, they can eat for a fixed amount of time before putting down the forks and letting another philosopher eat.

The problem arises when all philosophers try to pick up both their forks at the same time. If they all reach for the fork to their left first, they will end up in a deadlock where no one can eat. To avoid this, the philosophers need to coordinate their actions and ensure that only one philosopher at a time picks up a fork.

## Implementation
The philosophers problem is solved in this project by creating a thread for each philosopher and using mutexes to coordinate their actions. Each philosopher thread has a state machine that determines what action they should take next, based on their current state and the state of the forks.

The program also includes a monitor thread that keeps track of the state of the forks and signals the philosophers when a fork is available. When a philosopher wants to pick up a fork, they first try to acquire the mutex that protects the fork. If the mutex is locked by another philosopher, they wait until it is released before trying again.

To prevent deadlock, the philosophers are given a fixed amount of time to eat before they must put down their forks and wait for another turn. If a philosopher cannot acquire both forks within this time limit, they put down the forks and start again from the beginning.

## Setup
To use philosophers, you must first clone this repository.

`git clone https://github.com/tessavdvorst/philosophers.git`

Once you have the source code, you can compile it using the provided Makefile.

`make`

This will create an executable file called philosophers in the same directory.

## Usage
Once you have compiled the program, you can run it by typing the following command:

`./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]`

![](https://github.com/tessavdvorst/philosophers/blob/master/philo.gif)

* **number_of_philosophers:** The number of philosophers and also the number
of forks.
* **time_to_die (in milliseconds):** If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
* **time_to_eat (in milliseconds):** The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
* **time_to_sleep (in milliseconds):** The time a philosopher will spend sleeping.
* **number_of_times_each_philosopher_must_eat (optional argument):** If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.