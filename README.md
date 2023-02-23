# Minotaur_problems

## How To run
- Run the command ``` g++ -o problem1  problem1.cpp ``` to compile the source code
- Run the executable with the command ``` .\problem1.exe ```
- Run the command ``` g++ -o problem2  problem2.cpp ``` to compile the source code
- Run the executable with the command ``` .\problem2.exe ```

## Problem 1: Minotaur’s Birthday Party 
### Approach: 
- Each time a guest enters for the first time they will always eat the cake
- Every time after they do not eat the cake but will call the waiter if there is no cake
- Given that there are N number of guests, the Minatour can count the number of times the server is called and when the server is called N number of times he will know that every guest has entered atleast once

## Problem 2: Minotaur’s Crystal Vase
### Chosen approach to code: 3 queue
### Strategy Discussion:
#### Strategy 1
With this method, there is no orginizated way for guests to know who should enter next in the event that many guests would want to see the vase which leads to a situation where not every guest is guaranteed to see it. One advantage of this would be that there is no necesary pre-party planning needed.
#### Strategy 2
With this methed, it would prevent the crowding problem that the first strategy suffered from. However, this strategy still suffers from the problem that "A particular guest wanting to see the vase would also have no guarantee that she or he will be able to do so and when".
#### *Strategy 3*
This is the strategy that the the Minotaur should choose! Because of the queue, there is no disorginazation caused by crowding and every guest that enters the queue is guaranteed to see the vase and they will have an estimated time of when they will see it by just looking at their spot in the queue. Additionaly, guests and re-enter the queue and would not netively impact the guests who have not seen it yet and have already entered the queue. 
