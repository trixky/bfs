# bfs

An implementation of the bfs algorithm, illustrated by an anthill.
The goal being that all the ants arrive as quickly as possible at their destination, maximizing the flow, while avoiding traffic jams.

![Image description](https://i.ibb.co/VVY4wCD/Capture-d-cran-de-2020-06-10-22-58-16-1.png)

## Rules

- All the ants start in the same start room.
- All the ants end in the same end room.
- A room can only contain one ant at a time except for the start and end room.
- An ant can only move one room at a time.
- The program ends when all the ants have reached the end room.

First, the program displays the configuration of the anthill, then each line represents a turn with all its ant movements according to the following format: L \[f\] - \[r\] where f is the ant number and r the name of the room.

## Usage

```bash
make

# a simple configuration with schema
./bfs < configs/exemple-strawberry.conf

make extra

# use the generator (Nb_ants | Nb_rooms | Nb_max_tubes/room | Nb_entry_tubes | Nb_exit_tubes)
./generator/generator 300 300 10 8 8 | ./bfs
```