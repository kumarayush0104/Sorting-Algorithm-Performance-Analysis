import pandas as pd
import matplotlib.pyplot as plt

data=pd.read_csv('uniform.csv')

# Calculate total comparisons and swaps for each algorithm
total_comparisons = data.groupby('Algorithm')['Comparisons'].mean()
total_swaps = data.groupby('Algorithm')['Swaps'].mean()

# Create a figure with two subplots
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(15, 7))

# Pie chart for comparisons
ax1.pie(total_comparisons, labels=total_comparisons.index, autopct='%1.1f%%', startangle=140)
ax1.set_title("Proportion of Comparisons by Algorithm")

# Pie chart for swaps
ax2.pie(total_swaps, labels=total_swaps.index, autopct='%1.1f%%', startangle=140)
ax2.set_title("Proportion of Swaps by Algorithm")

plt.show()