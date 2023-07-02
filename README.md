<!DOCTYPE html>
<html>
  <head>
  </head>
  <body>
    <h1>Sorting Algorithms</h1>
    <p>In this project, we implemented several sorting algorithms using templates to sort data of different types. The algorithms we implemented are:</p>
    <ul>
      <li>Insertion sort</li>
      <li>Selection sort</li>
      <li>Bubble sort</li>
      <li>Shell sort</li>
      <li>Count sort</li>
      <li>Merge sort</li>
      <li>Quick sort</li>
    </ul>
    <h2>Implementation</h2>
    <p>Each algorithm is implemented as a separate function using templates. We tested each algorithm on randomly generated arrays of sizes 200, 500, 1000, 5000, 10000, 20000, and 50000. We calculated the running time on each dataset and drew a plot for each algorithm to see how the running time changes according to the different sizes of datasets.</p>
    <h2>Results</h2>
    <h3>Insertion sort</h3>
    <p>Insertion sort is a simple sorting algorithm that works the way we sort playing cards in our hands. It has an average time complexity of O(n^2).</p>
    <img src="insertion_sort.png" alt="Insertion sort plot">
    <p>As we can see from the plot, the running time of insertion sort increases drastically as the size of the dataset increases. Therefore, it is not recommended to use insertion sort for large datasets.</p>
    <h3>Selection sort</h3>
    <p>Selection sort is an in-place comparison sorting algorithm that has an average time complexity of O(n^2).</p>
    <img src="selection_sort.png" alt="Selection sort plot">
    <p>As we can see from the plot, the running time of selection sort increases significantly as the size of the dataset increases. Therefore, it is not recommended to use selection sort for large datasets.</p>
    <h3>Bubble sort</h3>
    <p>Bubble sort is a simple sorting algorithm that repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order. It has an average time complexity of O(n^2).</p>
    <img src="bubble_sort.png" alt="Bubble sort plot">
    <p>As we can see from the plot, the running time of bubble sort increases significantly as the size of the dataset increases. Therefore, it is not recommended to use bubble sort for large datasets.</p>
    <h3>Shell sort</h3>
    <p>Shell sort is an in-place comparison sorting algorithm that is a generalization of insertion sort. It has an average time complexity of O(n^2).</p>
    <img src="shell_sort.png" alt="Shell sort plot">
    <p>As we can see from the plot, the running time of shell sort increases significantly as the size of the dataset increases. Therefore, it is not recommended to use shell sort for large datasets.</p>
    <h3>Count sort</h3>
    <p>Count sort is an efficient algorithm for sorting arrays with small integer values. It has a time complexity of O(n+k), where k is the maximum value in the array.</p>
    <img src="count_sort.png" alt="Count sort plot">
    <p>As we can see from the plot, the running time of count sort is very low and almost constant, regardless of the size of the dataset. Therefore, count sort is a good choice for sorting arrays with small integer values.</p>
    <h3>Merge sort</h3>
    <p>Merge sort is a divide-and-conquer algorithm that recursively divides the input array into two halves, sorts each half, and then merges the sorted halves. It has a time complexity of O(n log n).</p>
    <img src="merge_sort.png" alt="Merge sort plot">
    <p>As we can see from the plot, the running time of merge sort increases slowly as the size of the dataset increases. Therefore, merge sort is a good choice for large datasets.</p>
    <h3>Quick sort</h3>
    <p>Quick sort is a divide-and-conquer algorithm that selects a pivot element and partitions the input array around the pivot, recursively sorting the two subarrays. It has an average time complexity of O(n log n).</p>
    <img src="quick_sort.png" alt="Quick sort plot">
    <p>As we can see from the plot, the running time of quick sort increases slowly as the size of the datasetincreases. Therefore, quick sort is a good choice for large datasets.</p>
    <h2>Conclusion</h2>
    <p>In conclusion, we implemented several sorting algorithms using templates and tested them on randomly generated arrays of different sizes to analyze their running time. We found that count sort is a good choice for sorting arrays with small integer values, while merge sort and quick sort are good choices for large datasets. On the other hand, insertion sort, selection sort, bubble sort, and shell sort are not recommended for large datasets due to their significantly increasing running time.</p>
  </body>
</html>
