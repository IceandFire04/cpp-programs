# GlobalFormat
GlobalFormat is a header file I made to use for some of my programs, but it's pretty versatile so I put it here so other people could use it. It allows you to format output with bolding, italics, colors (and custom colors)
and more in most places.

## How to use it
> [!IMPORTANT]
> GlobalFormat uses standard C++ strings for its main function `formatText`, but if you really need to you can modify the header file yourself to fit character arrays or custom string implementations.

All you really need to do is put a string in `formatText` and tell it what type of formatting you'd like. In the header file, there is an enum with all the available formatting types.
You can also do custom colors by setting the formatting type to `RGBCOLOR` or `BG_RGBCOLOR` and adding a couple extra parameters to the function.

### Example
Heres an example program outputting bold text, blue text, and custom colored text.
```cpp
//example program for GlobalFormat
#include <iostream>
#include <string>
#include "globalformat.h"
using namespace std;

int main()
{
  cout << formatText("Bold Text", BOLD) << endl;
  cout << formatText("Blue Text", BLUE) << endl;
  cout << formatText("Custom Colored Text", RGBCOLOR, true, {100,50,255}) << endl; //  add the extra parameters for a custom color
  return 0;
}
```

GlobalFormat also has a void function `testFormatting()` so you can see what formatting styles work and don't work in your output.

## How it works
All GlobalFormat does is add an [ANSI escape code](https://en.wikipedia.org/wiki/ANSI_escape_code) in front of your string to format it, then another escape code to reset it normal. This should work in most cases, but 
I'd reccomend only using it in when outputting something, so be careful not to set a variable to a formatted string.

Anyways, thanks for using this header or at least checking it out!
