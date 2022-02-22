# CS50
These are some projects that I have done in CS50 (Havard Univeristy's Computer Science course)
  1. Filter 
  
  I implemented a C program that uses filters to BMP images. Specifically, i worked on the filter.c program which applies many filters, such as grayscale, reflect, blur, and edges to the pictures and each filter is a function in a program. My goal was to program these functions to edit the 2D array of pixels so that desired filter is applied. 
  
  (The original photo)
  
   ![image](https://user-images.githubusercontent.com/85450944/155099964-ee6baa99-0f78-48d4-88dd-36127b64beba.png)

   (edges filter's result)
   
   ![image](https://user-images.githubusercontent.com/85450944/150460115-e6fa7d58-9656-47fa-8d66-9dd8d658a960.png)

  2. DNA
  
  This Python program can indetify a person based on their DNA. In this problem, I learned how to use command-line arguments, work with CSV file and open and read another file that has a random DNA sequence. I tried to find the longest run of consecutive repeats of a specific gene in the DNA sequence. Then I matched these long runs with any of the individuals in the CSV file and therefore I could find a person based on their DNA sequence.
  
  3. Speller
  
  I Implemented a C program that can spell-check words in a file using a hash table. Specically, I worked on dictionary.c to implement 5 function prototypes. First funcion is to load words into a hash table, then I maded a check function where it takes each word and checks if this word is in a dictionary or not. I also implemeted a function to delete all the memory i created to store all the date inside the data structure.
  
  4. SQL lab7 and pset7
  
  I wrote SQL queries to answer a variety of questions by selecting data from many tables from Spotify and IMDb.
   
  5. Tideman
  
  I coded a C program that runs a Tideman voting method. This method works by drawing a graph of candidates where an arrow from candidate A to candidate B implies that A wins against B. The winner of this election is the one who has no arrow pointing at them. In this C program, i used typedef struct to pair 2 candidates, so that means each pair should have one winner and one loser. Then I compare the votes to know who's the winner, afterthat I have a function prototype to update the ranks of the candidates which is an array.  
