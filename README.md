# OS2
OS Assignment 2

Banker’s Algorithm
An deadlock avoidance algorithm that ensures that the system never enters an unsafe state by simulating allocations before committing them. It prevents deadlock by only granting requests if the system remains safe after the allocation.

Objective:
To determine whether the system is in a safe state by checking if there exists a sequence of process execution so that all processes can complete without causing deadlock.

Algorithm Overview:

Need Matrix is calculated as Max – Allocation.

Work Vector starts as the Available resources.

Iteratively check if a process’s needs can be satisfied with current Work.

If yes, allocate resources, mark the process as finished, and release its allocation back to Work.

Continue until all processes finish or no progress is possible.

If all processes finish → system is safe, and the safe sequence is displayed. If not → system is unsafe, and a message is shown.

Compilation
On Linux/Unix: g++ bankers.cpp -o bankers
On Windows (PowerShell or CMD): g++ bankers.cpp -o bankers.exe

Running the Program
When you run the program, it will prompt for a filename:

./bankers
Enter input filename: input_safe.txt

Input File Format
The file must follow this structure:

n m
<Allocation Matrix rows>
<Maximum Matrix rows>
<Available Resources vector>

First line: number of processes (n) and number of resources (m)

Next n lines: Allocation matrix

Next n lines: Maximum matrix

Final line: Available resources vector

<img width="175" height="337" alt="image" src="https://github.com/user-attachments/assets/92ae299d-6594-4986-8375-137255f924a9" />

<img width="202" height="253" alt="image" src="https://github.com/user-attachments/assets/f3592b81-1555-48dd-8f39-66fed8183e9e" />

<img width="717" height="265" alt="image" src="https://github.com/user-attachments/assets/7c7e9ae6-d9cd-45be-b99a-1fc8da079379" />
