This codebase contains data structures and algorithm to solve the great well problem. The Great Wall problem is:

Long ago, a great wall was built along the northern border of an ancient kingdom. After the wall was finished, an artist walked along the wall from west to east, decorating the southern side of each top brick with a unique symbol.

The artist's apprentice was instructed to follow and copy each symbol onto the northern side of each brick. However, instead of copying each symbol onto the back of the same brick, the apprentice accidentally copied the symbol onto the back of the next brick along to the east. That is, he drew the symbol from southern side of the first brick onto the northern side of the second brick, the symbol from the southern side of the second brick onto the northern side of the third brick, and so forth all the way along the wall. When he reached the eastern end, he realised his mistake, as there was no brick on which to draw the final symbol. In panic, he removed the first brick from the wall, and destroyed it.

The years passed, and the local people gave names to the symbols decorating the wall. They carved these names beneath the symbol on (both sides of) each brick. Many years later, an earthquake shook the kingdom, and the wall came crashing down. Dismayed, the King ordered all of the decorated bricks to be brought to his palace. Upon examining the heap of bricks, the Royal Data Scientist observed that it was readily apparent which was the north and south side of each brick, as exposure to sunlight had caused the symbols on one side of the wall to fade more than the other. Thus there was enough information to efficiently determine the original sequence of symbols.

The Royal Software Engineer noted that processing the symbol names would be more efficient than processing images of the symbols, and proposed the following algorithm for computing the original sequence:

 1- Load the information from each brick into main memory, organising it in a manner suitable for efficient searching.
 
 2 - Arbitrarily choose one of the bricks as a starting point.
 
 3 - Taking the two symbol names from the starting brick, start constructing a result sequence elsewhere in main memory, northern name followed by southern name.
 
 4 - Repeatedly, until no matching brick is found:
 
   i - Search for the brick with a northern symbol that matches the back (easternmost) symbol in the result sequence.
   
   ii - Add the southern symbol name from that brick to the back of the result sequence.
   
 5 -  Repeatedly, until no matching brick is found:
 
   i - Search for the brick with a southern symbol that matches the front (westernmost) symbol in the result sequence.
   
   ii - Add the northern symbol name from that brick to the front of the result sequence.
   
