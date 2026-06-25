Imagine a Whiteboard with 5 Squares
text
[ 1 ] [ 2 ] [ 3 ] [ 4 ] [ 5 ]
You Have Two Magnets
A green magnet that says "PUT NEXT HERE"

A red magnet that says "TAKE NEXT FROM HERE"

The Rules
When you want to store something, put it where the green magnet is. Then move the green magnet right one square.

When you want to read something, take it from where the red magnet is. Then move the red magnet right one square.

If either magnet falls off the right edge, it jumps back to square 1.

That's the Whole Thing
Magnet	What It Means in Code
Green magnet	head
Red magnet	tail
The 5 squares	buffer
Number of squares	size

Buffer = Block of boxes.
Size = How many boxes.
Write = Fill next box, move green magnet.
Read = Empty oldest box, move red magnet.



Field	   Type	         Purpose	   Question It Answers
buffer	pointer	  Location of boxes	 "Where are the boxes?"
size	 number	     Total number of boxes	"How many boxes total?"
head	 number	     Next write position	 "Where do I put new stuff?"
tail	 number	     Next read position	 "Where do I take old stuff?"
full	 true/false	 Distinguish empty vs full	"Are we actually full or just empty?"

