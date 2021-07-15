#ifndef MULTI_ARMED_BANDIT_HPP_
#define MULTI_ARMED_BANDIT_HPP_

#include <random>
#include <vector>

class Multi_armed_bandit {

public:

  Multi_armed_bandit(int n_arms, std::default_random_engine& generator) : k(n_arms) {

    // initialize known action values from ~ N(0, 1)
    q_star.resize(k);
    std::normal_distribution<double> distribution;
    for (int i=0; i<k; i++) q_star[i] = distribution(generator);

    // initialize reward distributions from ~ N(q_star(k), 1)
    reward_distributions.resize(k);
    for (int i=0; i<k; i++) {
      std::normal_distribution<double> dist(q_star[i], 1);
      reward_distributions[i] = dist;
    }

  }

  double pull_arm(size_t arm, std::default_random_engine& generator) {
    assert(arm >=0 && arm < k);
    return reward_distributions[arm](generator);
  }

private:

  int k;  // number of arms
  std::vector<double> q_star;  // known action values
  std::vector< std::normal_distribution<double> > reward_distributions;

};

#endif // MULTI_ARMED_BANDIT_HPP_