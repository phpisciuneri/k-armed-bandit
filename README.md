# k-armed-bandit

A testbed for practicing reinforcement learning.

## Getting Started

### Prerequisites

- cmake
- c++ compiler
- python with matplotlib (for plotting)

### Building

From root of repository:

```sh
mkdir build
cd build
cmake ..
make
```

### Running

From build directory:

```sh
./k_armed_bandit
```

### Plotting

From build directory:

```sh
python ../bin/plot.py 
```

This will reproduce Figure 2.2 in Reinforcement Learning by Sutton and Barto.

![Average Reward](/doc/figure-2-2.png)
