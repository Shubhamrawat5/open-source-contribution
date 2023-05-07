'''
To find the sum of all prime numbers between 1 to 100,000
'''

import multiprocessing

# Define a function to check if a number is prime
def is_prime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

# Define a function to find the sum of prime numbers in a given range
def sum_primes(start, end, result):
    total = 0
    for i in range(start, end):
        if is_prime(i):
            total += i
    result.value += total

# Define the number of processes to use
num_processes = 4

# Define the range of numbers to check for primes
start = 1
end = 100000

# Divide the range into equal parts for each process
step = (end - start) // num_processes
ranges = [(start + i * step, start + (i + 1) * step) for i in range(num_processes)]
ranges[-1] = (ranges[-1][0], end)  # Adjust the last range to include any remaining numbers

# Create a list to hold the results from each process
results = [multiprocessing.Value('i', 0) for _ in range(num_processes)]

# Create a list to hold the processes
processes = []

# Create a process for each range of numbers
for i, (start, end) in enumerate(ranges):
    result = results[i]
    p = multiprocessing.Process(target=sum_primes, args=(start, end, result))
    processes.append(p)

# Start each process
for p in processes:
    p.start()

# Wait for each process to finish
for p in processes:
    p.join()

# Calculate the total sum of primes from the results
total_sum = sum([result.value for result in results])

# Print the result
print(f"The sum of prime numbers between 1 and 100000 is: {total_sum}")