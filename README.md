<h1 align="center">
	📖 Philosophers
</h1>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/linasbk/get_next_line?color=lightblue" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/linasbk/get_next_line?color=critical" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/linasbk/get_next_line?color=yellow" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/linasbk/get_next_line?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/linasbk/get_next_line?color=green" />
</p>
---
## General idea

The mandatory part of this project asks us to solve the dining philosophers problem and implement a mutithreading solution. In order to better understand the solution that we are going to implement in this project I suggest you to read something about what a thread is and how multithreading works, I'll leave a couple of wikipedia references to start learning about these topics:

    Thread
    Multi Threading

Another raccomandation is to read the subject before starting, I'll leave a link also to that: subject.
Now that we know what we have to do we can start explaining the general idea that I've applied in this project. First of all we have to immagine a round table, N num of philosophers sits around it and each of them brings a fork and let's say that they place it on the table on their right (doesn't really change if they place it on the right or left). At this point we know that a philosopher can do three things: eat, think or sleep; but in order to eat he has to pick two forks (the one on his right and the one on his left). Let's use a picture to have a more concrete idea of what we are talking about:



Since I'm not a big fan of philosophy i don't know a single name one these guys up here so I'll give them some more familiar names and starting from the bottom left one they will be: Roberto Legno, Thiago, Marcello, Lapo Raspanti and Rekkless.

Let's say that Roberto Legno wants to eat, so he picks his right and left fork, at this point we notice that Rekkless can't eat since Roberto Legno picked his right fork which was shared with Rekkless; this might seem a little obvious but keep in mind this situation because the main problem of this project is how to organize the eating action of the philosophers.
Probably the first solution that came to your mind is to simply make the odd and even philos eat separately, well we are not going to do that, it's too hard coded and we would loose the meaning of the project, philos have to organize by themselves.
But, how are we going to do that? Using mutex!

## Race Conditions & Mutex
Race conditions
Before explaining what mutex are and why we have to use them, let's talk about what race conditions are. A Race condition it is a condition in which one or more threads are trying to access and modify a same variable at the same time, this can lead to an error in the final value of that variable. To better understan the race condition here's an example: Let's say that we want to count to 2.000.000, to do that with the multithreading we simply make two threads that execute the same routine, and the routine increase the variable cont to 1.000.000, in this way we should execute the while inside routine 2 times and when cont is printed we should get 2.000.000. Well, that's not exactly how it works. 

Mutex
Now that we know what a race condition is we'll talk about mutex, that are what we need to avoid a data racing. Immagine these as locks, if a mutex is already locked and a thread tries to lock it he we'll be stopped untill the mutex will be unlocked. Taking up the previous example, we could avoid the race condition simply adding a lock before we increase the value, in this way thread B can't overwrite the value of cont with what he read before being stopped. 

## Issues related to thedining philosophers problem.

 Five philosophers dine together at the same table. Each philosopher has their own plate at the table. There is a fork between each plate. The dish served is a kind of spaghetti which has to be eaten with two forks. Each philosopher can only alternately think and eat. Moreover, a philosopher can only eat their spaghetti when they have both a left and right fork. Thus two forks will only be available when their two nearest neighbors are thinking, not eating. After an individual philosopher finishes eating, they will put down both forks. The problem is how to design a regimen (a concurrent algorithm) such that no philosopher will starve; i.e., each can forever continue to alternate between eating and thinking, assuming that no philosopher can know when others may want to eat or think (an issue of incomplete information).
  Wikipedia-Dining philosophers problem.

## The conditions are as follows.

    Each philosopher must have a thread.
    The forks that philosophers have with each other must be locked by mutex to prevent overlap.

To prevent deadlock, the idea used is that each philosopher must always get from the right-hand fork, and the odd-numbered philosopher will try to get the fork a little later.
Usage

## Example of Usage

### Simple example of functionality
  ./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_time_each_philosophers_must_eat(option)]
