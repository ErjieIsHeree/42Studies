_This project has been created as part of the 42 curriculum by exia_

# Fly-In

---

## Description

The task is to design a system that efficiently routes a fleet of drones from a central base (start) to a target location (end), while navigating this dynamic network under a set of strict constraints and optimization goals.

A graph will be given representing the network of zones, and a set of constraints that must be respect.

The graph is represented as a network of connected zones, where connections define possible movement paths between zones.

---

## Instructions

This project includes a Makefile which is used to help on executing the program, simply run `make run` in the terminal and voilà.

---

## Resources

- [Claude](https://claude.ai/chat/)
    > Claude was used for learning or small things in the code, everything was written by me. You will notice when you check the poor structure of it.

---

## Additional sections

### A detailed description of the algorithm choice and implementation strategy

No algorithm was choosen here, which in my opinion I wasted a great opportunity on learning new algorithms. But anyways, I, by my self, found the way through the mazes and made a solution on my own. Wasn't much complicated, later I found that it is similar to one already existing named dijkstra.

The drones decide which hub to travel and they do it by choosing the lightest weight on each hub (prioritizing the priorities hubs).

### Documentation of the visual representation features and how they enhance the user experience

Well, by each movement the drone do, it will return a string with the direction it went to. At the end just had to put them together and voilà.g

### Example input and expected output demonstrating the program’s functionality.

No inputs are expected. The program requires you to directly write the maze file root from the execution root.

The output will be follow the next constraint:

D<drone_id>-<Hub> or D<drone_id>-<Connection> for the movement of each drone. For example

D1-waypoint1
D1-waypoint2 D2-waypoint1
D1-goal D2-waypoint2
D2-goal
