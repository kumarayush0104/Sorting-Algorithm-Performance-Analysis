import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


data = pd.read_csv('uniform.csv')

# Calculate average values for each algorithm
avg_data = data.groupby('Algorithm').mean()

# Define the metrics and their order
metrics = ['Comparisons', 'Swaps', 'Time(microseconds)']

# Normalize data for each metric (optional, for better visualization)
normalized_data = avg_data.copy()
for metric in metrics:
    normalized_data[metric] = (normalized_data[metric] - normalized_data[metric].min()) / (normalized_data[metric].max() - normalized_data[metric].min())

# Create a figure and subplot
fig = plt.figure(figsize=(8, 6))
ax = fig.add_subplot(111, polar=True)

# Define angles for each metric
angles = [n / float(len(metrics)) * 2 * np.pi for n in range(len(metrics))]
angles += angles[:1]

# Plot data for each algorithm
for idx, algorithm in enumerate(normalized_data.index):
    values = normalized_data.loc[algorithm].values.tolist()
    values += values[:1]
    ax.plot(angles, values, linewidth=1, linestyle='solid', label=algorithm)
    ax.fill(angles, values, alpha=0.25)

# Set labels
ax.set_xticks(angles[:-1])
ax.set_xticklabels(metrics)
ax.set_title("Algorithm Comparison Radar Chart")
ax.legend()

plt.show()