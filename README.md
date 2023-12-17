"# Corner-Store-Inventory-Frequency-Tracker" 

About:
  This project solves the problem of tracking inventory on-hands for small businesses. It does this by automatically reading from a text file containing the names of various inventory items listed and counting the frequency of those inventory items. 
  The program allows the user to search for items and their current quantity, list all current inventory items and their quantities, and display a histogram created using the frequency of each item found in the database (text file). Additionally, with each option selection, the program will automatically query the backend to ensure that the data provided is up-to-date.
  
What does the project do well?
  I am particularly proud of the automatic query feature and histogram. This program is reuasble in other contexts and will be useful in other data analysis projects.
  
Where can this code be improved?
  This project could use a more interesting user interface, more data visualization options, and the ability to query other types of text files or data bases. For instance, the program could be extended to count word frequency in a text file.
  
What were the challenges?
  When writing this program, I found that working with pointers and storing the data line by line into a set was more cumbersome than simply reading data into a dynamic array in, say, Python or JavaScript. The end result, however, is a quick data retrieval and backup!

Transferable skills:
  The most significant transferable skills I learned while creating this program were reading data from a file, manipulating that data, and then writing the data out to a new file for backup. Additionally, using pointers and sets provided me with a better understanding of data structures and how they work under the hood.

Code readability and adaptability:
  This program was made readable by choosing an object-oriented approach with a clear class structure, well-defined methods and fields, and helpful comments. The program is maintainable because each code block exists in either a class method or function. Each component is properly encapsulated and can be changed without changing any other feature. The program is adaptable because it can be extended beyond its current functionality. Additional menu options can be added to perform more complex data analysis, new methods can be added as needed, the UI can be altered if desired, and the files that are read from and written to can be any file with some arbitrary data if needed.
