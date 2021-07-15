#include <iostream>
#include <vector>
#include <random>

#include "multi_armed_bandit.hpp"
#include "reinforcement_learning.hpp"

int main() {

  // Simulation parameters
  int k = 10;
  int n_tests = 200;  // 2000
  int n_steps = 1000;

  std::default_random_engine generator;
  std::vector<double> total_reward(n_steps);

  for (int i=0; i<n_tests; i++) {

    Multi_armed_bandit bandit(k, generator);
    Reinforcement_learning rl(k);

    for (int j=0; j<n_steps; j++) {

      size_t a = rl.greedy_selection();

      double reward = bandit.pull_arm(a, generator);
      total_reward[j] += reward;

      rl.update_action_value_estimate(a, reward);

    }

  }

  std::cout << "Average reward per time step:" << std::endl;
  for (int j=0; j<n_steps; j++) {
    std::cout << j << ": " << total_reward[j] / n_tests << std::endl;
  }

  return 0;
}
