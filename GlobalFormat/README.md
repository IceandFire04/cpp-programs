# GlobalFormat
> [!IMPORTANT]
> This is being rewritten soon because I just found out haw ANSI codes _actually_ work. This only really works on Online GDB and Replit right now. My bad!

GlobalFormat is a custom header file I made to apply those cool colors to the output in my programs, but I thought it was pretty versatile so I put it here so other people could use it because they might find it useful. It allows you to format output with bolding, italics, colors (including your own) and more on most standard outputs.

If you have any problems in a certain terminal or just in general, please open an issue! I'm also open to suggestion that make this readme sound less like coorperate slop.

## How to use it
> [!WARNING]
> GlobalFormat uses standard C++ strings for the majority of it's functions, but if you really need to you can modify the header file yourself to fit character arrays or custom string implementations.

### formatText

Since it's last iteration, GlobalFormat has added new ways to format the console. First, we'll start with `formatText`.

- `formatText(string text, int type, bool useColor = false, Color color = {255, 255, 255})`
  - `text` is the text that will have the formatting applied to it
  - `type` is the type of formatting that should be applied (in the `FormattingTypes` enum)
  - `useColor` is whether or not to add special conditions for custom colors (for use with `RGBCOLOR` and `BG_RGBCOLOR`)
  - `color` is the custom color if needed

#### Example
Heres an example program outputting bold text, blue text, and custom colored text using `formatText`.
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
  cout << formatText("Custom Colored Text", RGBCOLOR, true, {100,50,255}) << endl; // add the extra parameters for a custom color
  return 0;
}
```

### multiFormat

This is the new way of formatting things, but with a _twist_! `multiFormat` is basically a deterent for stacking `multiFormat` inside one another.

- `formatText(string text, int type, bool useColor = false, Color color = {255, 255, 255})`
  - `text` is the text that will have the formatting applied to it
  - `formattings` is a vector of different types of formatting and use a custom struct called `MFE`
    - `MFE`s include the formatting type and color if needed like this: `{RGBCOLOR, {255, 0, 0}}` (the example below better explains this)

#### Example
This example is similar to the previous one, but we color the text _and_ boldface it at the same time.
```cpp
//example program for GlobalFormat
#include <iostream>
#include <string>
#include "globalformat.h"
using namespace std;

int main()
{
  cout << multiFormat("Blue AND bold text", {{BOLD},{BLUE}}) << endl;
  cout << multiFormat("Custom Colored AND italic text", {{ITALIC},{RGBCOLOR,{100,50,255}}}) << endl;
  return 0;
}
```

GlobalFormat also has a void function `testFormatting()` so you can see what formatting styles work and don't work in your output.

## How it works
All GlobalFormat does is use various ways to add [ANSI escape codes](https://en.wikipedia.org/wiki/ANSI_escape_code) in front of your text. I've tried to comment all over the file so it's easier to understand because, let's be real, this documentation kinda sucks.

Anyways, thanks for using this header or at least checking it out!
