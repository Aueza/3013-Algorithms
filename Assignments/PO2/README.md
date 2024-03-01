## P02 - Linear Search Using Json and Getch
### Ethan Saenz
### Description:

This program will create a JSON object using the provided dictionary.json file, and make autosuggestions based on the user's character input using the getch function. The user is first prompted for input, and upon receiving proper input, the program traverses the JSON object using a linear search algorithm comparing any words that begin with the user-entered character/substring. Finally, storing those matches in a vector, and printing out the first 10 matches found, while keeping a total of matches found above the printed 10.



### Files

|   #   | File             | Description                                        |
| :---: | ---------------- | -------------------------------------------------- |
|   1   | Main. cpp         | Main driver of my project that launches the program.      |
|   2   | console. hpp      | Determines the system type (windows/linux).               |
|   3   | json. hpp         | Loads functions to perform on JSON objects.               |
|   4   | rang. hpp         | Allows for colored text to be shown.                      |
|   5   | dictionary.json   | Contains the dictionary to be used for autosuggestions.   |

### Instructions

- Make sure you install the above main. cpp and all .hpp files
- My program expects no parameters to be placed on the command line when you run the program.
- The input should consist of characters, the delete or backspace can be used to go back as well.
- When a single word is found, hit the enter/return key to terminate the program.
- To terminate without finding a word, enter 'Z'.


### Output Examples

<img width="1101" alt="Screen Shot 2024-03-01 at 10 11 43 AM" src="https://github.com/Aueza/3013-Algorithms/assets/134173034/0f60cfc4-588d-4400-b763-fd5f28dcc2ae">

<img width="1101" alt="Screen Shot 2024-03-01 at 10 11 15 AM" src="https://github.com/Aueza/3013-Algorithms/assets/134173034/b82737fc-a0f2-4fe2-9361-a4293802dd1b">

<img width="1097" alt="Screen Shot 2024-03-01 at 10 10 47 AM" src="https://github.com/Aueza/3013-Algorithms/assets/134173034/2088982c-b17a-457b-aae2-ff8bbf1b1752">

<img width="1101" alt="Screen Shot 2024-03-01 at 10 08 54 AM" src="https://github.com/Aueza/3013-Algorithms/assets/134173034/1b19f9d6-6ff6-4d54-bb84-336c3436fefd">


