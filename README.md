
# ASCII-maze-shortest-path

This program uses the Breadth First Search algorithm to find the shortest path from a point S to a point E on a ASCII maze.

The input maze must be a rectangle of maximum 100*100, with a 'S' (starting) point and a 'E' (ending) point.






## Run Locally

Clone the project

```bash
  git clone https://github.com/Lixhr/ASCII-maze-shortest-path.git
```

Go to the project directory

```bash
  cd ASCII-maze-shortest-path
```

Build the binaries

```bash
  make all
```

Run the program

```bash
  ./shortest_path
```

## Example
```bash
┌──(Lixhr㉿Lixhr)-[~/Desktop/ASCII-maze-shortest-path]
└─$ make test                                                                   
./test.exp
spawn ./shortest_path
Please paste your ASCII maze (end it with a blank line):
#S###################
#    #    #     # # #
### ### # ##### # # #
#     # #   #       #
# # ####### # ##### #
# #       #   #     #
### # ##### ### ### #
# # # # # #   #   # #
# ### # # # ### #####
#           #       #
###################E#

Your walls seems to be '#'.
Type Y to agree, else type your char : Y

#S###################
#... #    #     # # #
###.### # ##### # # #
#  .  # #   #.......#
# #.####### #.#####.#
# #...    #...#.....#
### #.#####.###.### #
# # #.# # #.  #.  # #
# ###.# # #.###.#####
#    .......#  .....#
###################E#

shortest path: 48
```

## Contributing

Contributions are always welcome!          



## License

MIT License

Copyright (c) 2024 Charlie Beaufils

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://choosealicense.com/licenses/mit/)
