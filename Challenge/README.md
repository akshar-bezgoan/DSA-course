Task:
There will be a list of 3 billion people entered. Each person has up to 1000 friends and there are up to 3 billion people. 
Write a function which takes two people as parameters and returns true if they are friends or have a mutual connection and false if they are 2 connections (or more) away or aren't connected.
The process must run and complete in 10ms

Update:
It is not possible for my computer to run and execute C# or Python files using 3,000,000,000 people with up to 1,000 friends as that is terabytes of data in the file itself. Instead I am using 1,000 max people with 25 friends each (25,000 numbers + 12,500 spaces in the data). The C# runs in 24.3ms on average. I assume if the data was the requested size of 3bn, it would take a much longer time to run - therefore my program failed in time complexity but the BFS works well.
