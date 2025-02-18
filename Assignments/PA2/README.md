CPTS223 Programming Assignment 1
Author: Kobe Bui
Date: February 2nd, 2025

Project Notes: I wrote the output sequences to the file outputSequences.log. The List and Vector implementations 
                of the Josephus problem are identical aside from the container type used.

Discussion Questions
1. Does maching processing power affect execution time?
    Machine processing power does affect execution time because more powerful machines will be able to execute individual tasks faster, 
    which is why it is important when comparing algorithms to compare the amount of operations in an algorithm rather than time.

2. Which performs better: std::list or std::vector? Under what conditions?
    List performs better than vector, especially as the number of inputs (size of N) grows larger. List is a better container for 
    inserting/deleting nodes in the middle of the list which is the main operation occuring in the implementation of the Josephus problem.

3. How does N impact runtime compared to M?
    M and N both impact runtime linearly. In the scenario where all variables besides M are held constant, M impacts runtime linearly because
    the function eliminateDestination() must traverse the container M times, meaning as M increases, the number of steps taken in eliminateDestionation() 
    increases linearly. In the scenario where all variables besides N are held constnat, N impact runtime linearly because it calls 
    eliminateDestination() N times in pickDest(). Meaning as N increases, the number of times eliminateDestinations() is called increases linearly.