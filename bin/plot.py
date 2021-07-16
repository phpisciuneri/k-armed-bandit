import csv

import matplotlib.pyplot as plt

iteration = []
avg_reward = []
with open('greedy.csv') as csvfile:
    for row in csv.reader(csvfile):
        iteration.append(int(row[0]))
        avg_reward.append(float(row[1]))

plt.plot(iteration, avg_reward, color='green')
plt.xlabel('Steps')
plt.ylabel('Average Reward')
plt.show()
