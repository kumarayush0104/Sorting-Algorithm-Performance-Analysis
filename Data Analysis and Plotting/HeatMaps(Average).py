import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt
import numpy as np


data = pd.read_csv('uniform.csv')

# Calculate average values for each algorithm and metric
avg_data = data.groupby('Algorithm').mean()

# Transpose the data for heatmap visualization


# Create the heatmap
plt.figure(figsize=(8, 6))
sns.heatmap(avg_data, annot=True, fmt=".2f", cmap="coolwarm", cbar_kws={'label': 'Average Metric Value'})
plt.title("Sorting Algorithm Metrics Comparison")
plt.xlabel("Metric")
plt.ylabel("Algorithm")
plt.show()