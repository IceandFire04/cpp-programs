#include "SuburbanAlmanac.h"
#include <iomanip>
#include <iostream>

int page = 0; // the page to display
char quitChar = 'c'; // used for asking if you want to quit
bool zombiePage = false; // if the page is a zombie's
bool quit = false; // whether or not to end program

// this function is just to not have cout literally everywhere
void print(string theString, bool endline = true) {
	if (endline)
		cout << theString << endl;
	else
		cout << theString;
}

// prevents floats and doubles from having a million zeros
string stringPrecision(double theDouble, int precision) {
	stringstream ss; // stringstreams in short are like cout statements but for strings
	ss << fixed << setprecision(precision) << theDouble; // so thats how I can utilize fixed and setprecision() for strings
	return ss.str(); // then it returns the stringstream as an actual string
};

// This functions gets a Plant's entry and then outputs to the console with a tad bit of formatting (using my header globalformat)
void printPlantEntry(int entryIndex) {

	// Get the plant entry by their index in the almanac
	PlantEntry entry = getPlantEntry(entryIndex);

	// Print the name of the plant with a nice green color
	print(multiFormat(entry.name, {{BOLD}, {RGBCOLOR, plantColor}}));

	// print their description with italics
	print(formatText(entry.description, ITALIC));

	// turn the suncost to a string, join it to " Sun", then color it a nice solar yellow
	print(formatText(to_string(entry.suncost) + " Sun", RGBCOLOR, true, suncostColor));

	// get the cooldown and make sure it doesn't look like 1.5000000000
	print(stringPrecision(entry.cooldown, 1) + "s Cooldown");

	// print toughness/health with red color
	print(formatText(to_string(entry.toughness) + " Toughness", RGBCOLOR, true, healthColor));

	// print the damage value and the type; this is how sun producers show sun and marigold shows coins
	print(to_string(entry.damage) + ' ' + entry.damageType);

	// more joining and only outputs if applicable
	if (entry.range != "NA") print("Range: " + entry.range);
	if (entry.attackSpeed != "NA") print(entry.attackSpeed + " Speed");

	// gets the tier string
	print("Tier: " + getTierText(entry.tier));

	// print fact and flavor text based of index of the entry
	print(entry.fact);
	print(PlantFlavorTexts[entryIndex]);
}

// This functions gets a Zombie's entry and then outputs to the console with a tad bit of formatting (using my header globalformat)
void printZombieEntry(int entryIndex) {

	// Get the zombie entry by their index in the almanac
	ZombieEntry entry = getZombieEntry(entryIndex);

	// Print the name of the zombie with a nice purple color
	print(multiFormat(entry.name, {{BOLD}, {RGBCOLOR, zombieColor}}));

	// print their description with italics
	print(formatText(entry.description, ITALIC));

	// print toughness, true toughness with gray and armor toughness with orange
	print(to_string(entry.toughness) + " " + formatText("(" + to_string(entry.toughnessTotal) + ")", RGBCOLOR, true, {175, 175, 175}) // toughness and true toughness
	      + " + " + formatText(to_string(entry.armorToughness), RGBCOLOR, true, {255, 112, 47}) + " Toughness");

	// print the zombie's ability and range if applicable
	print(entry.ability);
	if (entry.range != "NA") print(entry.range + " Range");

	// gets the threat tier string
	print("Threat Tier: " + getTierText(entry.tier));

	// print fact and flavor text based of index of the entry
	print(entry.fact);
	print(ZombieFlavorTexts[entryIndex]);
}

int main() {
	// Initial boot
	// Title and other info
	print(multiFormat("THE SUBURBAN ALMANAC", {{BOLD},{RGBCOLOR, almanacColor}}));
	print("Created by IceandFire04");
	print(formatText("Made for my C++ final project!", ITALIC));
	cout << endl;

	// Supposed to be like "Press any key to continue..."
	print(formatText("Enter anything to continue... ", ITALIC), false);
	string temp = "eee"; // temporary string so the program doesn't geek out
	cin >> temp; // Using cin here let's us wait for the user's action

	// Clear the console for a nice clean slate
	clear();

	// Menu
	// Exiting this while loop makes the program end
	do {
		// Index
		print(multiFormat("THE SUBURBAN ALMANAC - Index", {{BOLD},{RGBCOLOR, almanacColor}})); // Title

		// Section options
		print("Choose your section: ");
		print("1. " + formatText("PLANTS", RGBCOLOR, true, plantColor));
		print("2. " + formatText("ZOMBIES", RGBCOLOR, true, zombieColor));
		cin >> page;
		clear();

		// zombiePage determines whether or not to display the options for zombies
		if (page == 1)
			zombiePage = false;
		else if (page == 2)
			zombiePage = true;
		else
			print(formatText("Your input wasn't a valid option; defaulting to last choice", RGBCOLOR, true, healthColor));

		// Sections
		// all the +1 and -1 stuff is to account for vectors starting at 0
		if (zombiePage)
		{
			print(multiFormat("THE SUBURBAN ALMANAC - Zombies", {{BOLD},{RGBCOLOR, zombieColor}}));
			for ( int i = 0; i < ZombieAlmanac.size(); i++ ) // for every zombie
			{
				print(to_string(i+1) + ". " + ZombieAlmanac[i].name); // list the index of the zombie and it's name
			}
		}
		else
		{
			print(multiFormat("THE SUBURBAN ALMANAC - Plants", {{BOLD},{RGBCOLOR, plantColor}}));
			for ( int i = 0; i < PlantAlmanac.size(); i++ ) // for every plant
			{
				print(to_string(i+1) + ". " + PlantAlmanac[i].name); // list the index of the zombie and it's name
			}
		}
		print("\nGo to page: ", false); // ask which page to go to
		cin >> page; // store that page
		clear(); // clean slate

		// Entry Page
		page -= 1; // -1 because vectors start at 0
		if (((!zombiePage && page >= PlantAlmanac.size()) || (zombiePage && page >= ZombieAlmanac.size())) || page < 0) page = PEASHOOTER; // check if page is inbounds; if not, default to page 1

		// print the entry depending on if it's a zombie or plant
		if (zombiePage)
			printZombieEntry(page);
		else
			printPlantEntry(page);

		cout << endl;

		// ask whether or not to quit
		print("Exit program? Saying no will redirect you to the index (y/n): ", false);
		cin >> quitChar;
		if (tolower(quitChar) == 'y') quit = true; // realistically I could've put break here, but...
		clear();
	}
	while (!quit);

	print(formatText("Thank you for reading the Suburban Almanac!", BOLD));
	return 0;
}




