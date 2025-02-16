import pandas as pd
import seaborn as sns
import matplotlib.pyplot as plt

# Load the data from the CSV file
data = pd.read_csv('uniform.csv')

# Calculate average values for each algorithm and metric
avg_data = data.groupby('Algorithm').mean()

# Normalize the data
normalized_data = (avg_data - avg_data.min()) / (avg_data.max() - avg_data.min())

# Create the heatmap
plt.figure(figsize=(8, 6))
sns.heatmap(normalized_data, annot=True, fmt=".2f", cmap="coolwarm", cbar_kws={'label': 'Normalized Metric Value'})
plt.title("Normalized Sorting Algorithm Metrics Comparison")
plt.xlabel("Algorithm")
plt.ylabel("Metric")
plt.show()