# Project 1a : Boggle Solver (in C)

## How to compile

To compile `spellcheck`

```
make spellcheck
```

To compile `onePlayerBoggle`

```
make onePlayerBoggle
```

## Testing using ./test.sh

Note the test file may take some time to run because of `valgrind`. If you are completing this project on replit, this may be quite, quite slow. I recommend you use smaller dictionaries and test different aspects of your program and avoid simply testing with `./teset.sh`

## Help Received

Please document any help you received in completing this lab. Note that the what you submit should be your own work. Refer to the syllabus for more details. 

I got help from office hours from Hunter and Austin.


## Describe your work

Please provide a short description of your programming progress

My linked list process:
In my linked list method I created methods that initalize, delete, and push items in a linked list. A lot of the logic came from lab 4 and the in class code from the lecture. In the first method I allocated space for a new list set pointers to NULL and 0 to basically reset the list. For the delete function if you use the free function it will delete the nodes in the list but you have to free the list in the end as well. The push function uses the strdup function to duplicate a list and point to it and you have to increase the size because you are pushing an item to the front of the list. 

My Hashmap process:
In the hasmhmap process we start off with resize and with resize it was the most efficent in my opinion to create a new double pointer to an array of pointers. Basically create everything new and take each bucket and resize. In order to do that i was able to use other functions such as the hashmap add and the ll_init function. I resized every bucket by iteration and then deleted the old buckets. Next was the hashmap initalize which contains the same logic as the linked list initialize in where you allocate memory but using calloc so we know the memory is zeroed out. Then since you need the new list inside you have to initialize a new list. The delete function was similar to the logic in the linked list delete. The check function checks to see if a string is in the hashmap and goes through every bucket and uses the hash function.

My boggle function:
The first part I worked on was to create a new hashmap for the dictionary and then to load the dictionary I opened the file to load the dictionary. After that we need to return the words we found by going through the hashmap, and in that function we also check to see if the word found is in the dictionary. After that the main part of the recursive function I do some base checks. Using the variables I check to see if we go off the board... or if we already visited that dice. After that we check out the cases for Qu and we check to see that if we get a q then we add a u to the next index with it. Lastly we check to see if this is a word we already saw.


