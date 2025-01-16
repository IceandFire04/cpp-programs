/*
GlobalFormat Header File version 2
BIG UPDATE with comments (I tried my best) and many more functions
Made by IceandFire04
Examples in the github readme
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// color struct used for custom colored text
struct Color {
	int r;
	int g;
	int b;
};

// used for applying multiple formatting styles at once, elaborated later
struct MFE { // stands for multiFormat element
	int formattingType;
	Color color = {255, 255, 255};
};

// all of the formatting types that work in places like onlineGDB and replit (extensive testing, I know)
enum FormattingTypes {
	NORMAL = 0,
	BOLD,
	DIM,
	ITALIC,
	UNDERLINE,
	INVERT = 7,
	HIDE,
	DOUBLEUNDERLINE = 21,
	BLACK = 30,
	RED,
	GREEN,
	YELLOW,
	BLUE,
	MAGENTA,
	CYAN,
	WHITE,
	RGBCOLOR, // add arguments 2;r;g;b to the text
	BG_BLACK = 40,
	BG_RED,
	BG_GREEN, // orange in replit
	BG_YELLOW,
	BG_BLUE,
	BG_MAGENTA,
	BG_CYAN,
	BG_WHITE,
	BG_RGBCOLOR, // same as before, add some extra args
	BRIGHTBLACK = 90,
	BRIGHTRED,
	BRIGHTGREEN,
	BRIGHTYELLOW,
	BRIGHTBLUE,
	BRIGHTMAGENTA,
	BRIGHTCYAN,
	BRIGHTWHITE,
	BG_BRIGHTBLACK = 100,
	BG_BRIGHTRED,
	BG_BRIGHTGREEN,
	BG_BRIGHTYELLOW,
	BG_BRIGHTBLUE,
	BG_BRIGHTMAGENTA,
	BG_BRIGHTCYAN,
	BG_BRIGHTWHITE,
	NUM_FORMATTINGTYPES
};

// for readability and convienence
const string REMOVE_FORMATTING = "\e[0m";

// just adds the set of characters for formatting styles
string formatting(int type)
{
	// you'll see ""\e[ + type + m" a lot; thats just tells the console to apply a formattingType
	return "\e[" + to_string(type) + "m";
}

// same as above but adds the extra args for custom colors
string formattingRGB(int type, Color color)
{
	return "\e[" + to_string(type) + ";2;" + to_string(color.r) + ";" +
	       to_string(color.g) + ";" + to_string(color.b) + "m";
}

// compares 2 colors with each other with &&, not ||
bool compareColor(Color color1, Color color2) {
	return color1.r == color2.r && color1.g == color2.g && color1.b == color2.b;
};

// parses and MFE object into formatting
string parseMFE(vector<MFE> formattings)
{
	string output; // the output string that will have all the formattings
	for (int i = 0; i < formattings.size(); i++) // for every type of formatting given in the function call
	{
		MFE focusedElement = formattings[i]; // get the element
		if (compareColor(focusedElement.color, {255, 255, 255})) // check if its white
		{
			// if it is, add something like bold or italics that doesn't require a color
			output += formatting(focusedElement.formattingType);
			//cout << "Adding formatting " << focusedElement.formattingType << endl;
		}
		else
		{
			// if it isn't, a color has been passed and therefore we add rgb formatting
			output += formattingRGB(focusedElement.formattingType, focusedElement.color);
			//cout << "Adding color" << endl;
		}
	}
	return output; // once all the formatting has been generated, return it to be used in multiFormat() (coming up soon)
}

// formats a string with ONE type of formatting
string formatText(string text, int type, bool useColor = false, Color color = {255, 255, 255})
{
	if (!useColor) // if no color needed
	    // return just a regular type of formatting like bold and makes sure to reset it
		return formatting(type) + text + REMOVE_FORMATTING;
	else
	    // return custom color text
		return formattingRGB(type, color) + text + REMOVE_FORMATTING;
}

// formats a string with MANY types of formatting (this could technically replace the function above, but whatever)
string multiFormat(string text, vector<MFE> formattings)
{
	string output = parseMFE(formattings); // get the formattings
	output += text + REMOVE_FORMATTING; // add the string and the reseter
	return output; // return the formatted string
};

void clear() // emulates system("clear") because some envirements don't have it
{
	cout << "\x1B[2J\x1B[H";
}

void testFormatting() // tests for any potentially missed formatting types since different outputs can have different results
{
	for (int i = 0; i < NUM_FORMATTINGTYPES; ++i)
	{
		cout << formatText("text!", i) << " (format style "
		     << formatText(to_string(i), BOLD) << ")" << endl;
	}
}