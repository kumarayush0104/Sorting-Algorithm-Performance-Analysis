# Performance Analysis of Sorting Algorithms

This project analyzes the performance of several common sorting algorithms, comparing their efficiency based on key metrics like number of comparisons, swaps/assignments, and execution time.  The analysis uses a data-driven approach, generating diverse datasets and visualizing the results to provide insights into algorithm behavior.

## Project Overview

Sorting algorithms are fundamental to computer science, and understanding their performance characteristics is crucial for efficient software development. This project implements and benchmarks six different sorting algorithms:

* Bubble Sort
* Insertion Sort
* Selection Sort
* Merge Sort
* Quick Sort
* Heap Sort

For each algorithm, the project measures and records the following metrics across varying input sizes:

* **Number of Comparisons:** The total number of element comparisons made during the sorting process.
* **Number of Swaps/Assignments:** The number of times elements are swapped or assigned to new positions.
* **Execution Time:** The time taken to sort the dataset.

The collected data is then analyzed and visualized using various techniques to compare the algorithms and identify their strengths and weaknesses.

## Methodology

1. **Dataset Generation:**  Randomly generated integer datasets within the range [1, 10000] are used. Multiple datasets are created for each input size to ensure a robust analysis.

2. **Algorithm Implementation:**  The sorting algorithms are implemented in C++.

3. **Performance Measurement:**  The number of comparisons, swaps/assignments, and execution time are measured for each algorithm and dataset.

4. **Data Analysis and Visualization:** The collected data is analyzed using statistical measures and visualized using:
    * Table Summaries
    * Pie Charts (Comparisons/Swaps proportion)
    * Bar Charts (Total operations)
    * Line Graphs (Performance metrics vs. input size)
    * Scatter Plots (Distribution of comparisons/swaps)
    * Heatmaps (Multiple metrics comparison)
    * Radar Charts (Multi-dimensional comparison)
    * Box Plots (Execution time distribution)

5. **Insights and Discussion:**  The results are analyzed to provide insights into the performance characteristics of each algorithm, discussing their efficiency and scalability.

## Report (Key Findings)

* **Bubble Sort:** High number of comparisons and swaps due to its simple, iterative nature. Inefficient for larger datasets.
* **Insertion Sort:** Efficient for smaller datasets, but performance degrades with increasing array size. High number of swaps can impact execution time.
* **Selection Sort:** Low number of swaps but high number of comparisons. Performance is relatively consistent across array sizes.
* **Merge Sort:** Efficient for larger datasets due to its divide-and-conquer approach. Consistent performance with moderate comparisons and swaps.
* **Quick Sort:** Generally the most efficient algorithm with low comparisons and swaps. High performance across various array sizes. However, performance can degrade in the worst-case scenario (e.g., already sorted data).
* **Heap Sort:** Good balance between comparisons and swaps. Efficient for larger datasets.

The analysis revealed that Quick Sort and Merge Sort generally exhibit superior performance for larger datasets, while Insertion Sort performs well for smaller, nearly sorted datasets. Bubble Sort and Selection Sort demonstrated significantly lower efficiency, especially as the input size increased.  The visualizations provide a clear picture of these performance differences.

## How to Run the Code

1. Clone the repository: `git clone https://github.com/kumarayush0104/Sorting-Algorithm-Performance-Analysis.git`
2. Navigate to the project directory: `cd Sorting-Algorithm-Performance-Analysis`

## Files Included

* `Sorting Algorithms/`: Contains the Python implementations of the sorting algorithms.
* `Data Analysis and Plotting/`: Contains the Python scripts for data analysis and generating visualizations.
* `Report.pdf`:  The project report documenting the analysis and findings.
* `README.md`: This file.

## Dependencies

* Python 3.x
* NumPy
* Pandas
* Matplotlib
* Seaborn

## Contributing

Contributions are welcome! Please open an issue or submit a pull request.
