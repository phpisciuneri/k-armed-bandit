#ifndef REINFORCEMENT_LEARNING_HPP_
#define REINFORCEMENT_LEARNING_HPP_

#include <vector>
#include <algorithm>

class Reinforcement_learning {

public:

  explicit Reinforcement_learning(int n_actions) : k(n_actions) {
    q_est.resize(k, 0);
    action_count.resize(k, 0);
  }

  size_t greedy_selection() {
    return std::distance(q_est.begin(), std::max_element(q_est.begin(), q_est.end()));
  }

  void update_action_value_estimate(size_t action, double reward) {
    action_count[action] += 1;
    q_est[action] += (reward - q_est[action]) / action_count[action];
  }

private:

  // number of actions
  int k;

  // estimate of action-values
  std::vector<double> q_est;

  // sample average buffers
  std::vector<int> action_count;

};

#endif // REINFORCEMENT_LEARNING_HPP_