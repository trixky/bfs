# bfs

An implementation of the [bfs](https://en.wikipedia.org/wiki/Breadth-first_search) algorithm, illustrated by an anthill.
The goal being that all the ants arrive as quickly as possible at their destination, maximizing the flow, while avoiding traffic jams.

## Rules

- All ants start in the same start room.
- All ants end in the same end room.
- A room can only contain one ant except for the start and end room.
- An ant can only move one room at a time.
- The program ends when all the ants have reached the end room.

![Image description](https://i.ibb.co/JcryMr1/Capture-d-cran-de-2020-06-10-23-17-32-1.png)

First, the program displays the configuration of the anthill, then each line represents a turn with all its ant movements according to the following format: __L\[an\]-\[rn\]__ where __an__ is the ant number and __rn__ the room name.

## Usage

```bash
make

# a simple configuration with schema
./bfs < configs/exemple-strawberry.conf

make extra

# use the generator (Nb_ants | Nb_rooms | Nb_max_tubes/room | Nb_entry_tubes | Nb_exit_tubes)
./generator/generator 300 300 10 8 8 | ./bfs
```