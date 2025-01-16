#include <string>
#include <vector>
#include "globalformat.h"
using namespace std;

// SuburbanAlmanac
// Made by IceandFire04
// Covers front lawn plants and zombies from PvZ1

// Colors for things like name colors
const Color plantColor = {150, 255, 150};
const Color zombieColor = {200, 55, 255};
const Color suncostColor = {255, 200, 100};
const Color healthColor = {255, 100, 100};
const Color almanacColor = {250, 156, 15};

enum Tiers {
	SSS = 0,
	SS,
	S,
	A,
	B,
	C,
	D,
	F,
	FMINUS
};

vector<Color> TierColors =
{
	{255, 166, 0},
	{247, 175, 40},
	{255, 255, 0},
	{252, 191, 76},
	{252, 76, 76},
	{255, 208, 128},
	{158, 255, 66},
	{145, 153, 255},
	{217, 92, 255},
	{134, 7, 148}
};

vector<string> TierText =
{
	"SSS",
	"SS",
	"S",
	"A",
	"B",
	"C",
	"D",
	"F",
	"F-"
};

/*
############################################################
P L A N T S
############################################################
*/

struct PlantEntry { // the outline for a plant's entry
	string name;
	string description;
	// string flavor;
	short suncost;
	float cooldown;
	int toughness;
	short damage;
	string damageType;
	string range;
	string attackSpeed;
	int tier;
	string fact;
};

enum PlantPages {
	PEASHOOTER,
	SUNFLOWER,
	CHERRYBOMB,
	WALLNUT,
	POTATOMINE,
	SNOWPEA,
	CHOMPER,
	REPEATER,
};

vector<string> PlantFlavorTexts = {
	"Been shootin' since '09 and hasn't stopped.",
	"Despite being just a little flower, she has some very good singing skills.",
	"Explode? Detonate? They can't decide which is better, but 'explodonate' is a keeper.",
	"Most days he's pretty open to jokes, but sometimes he can be a tough nut to crack.",
	"Some say he's lazy because he leaves everything to the last minute, but he's focusing his investment strategy.",
	"People tell Snow Pea how 'cool' he is, or how he needs to 'chill,' but he rolls his eyes. He's heard 'em all.",
	"Was -this- close to getting a gig for stunts, but his agent demanded to much on the front end. It's just the business.",
	"A fierce plant, Repeater doesn't take additude from anybody, but yet, he secretly yearns for love.",
};

vector<PlantEntry> PlantAlmanac = {
	//Name          Description                                     Sun  CD   HP    DMG     DMG Type            Range   AtkSpd        Tier Fact
	{"Peashooter", "Shoots peas at zombies.",                       100, 7.5, 300,  20,     "Damage",           "Lane", "Normal",       C, "Unlocked first in almost every game"},
	{"Sunflower",  "Produces extra sun.",                           50,  7.5, 300,  50,     "Sun Production",   "NA",   "Slow",         S, "First and most important sun producer"},
	{"Cherry Bomb","Explodes in an area dealing massive damage.",   150, 50,  300,  1800,   "Damage",           "3x3",  "NA",           S, "Extremely effective for final waves"},
	{"Wall-nut",   "Defends plants from zombies.",                  50,  30,  3000, 0,      "Damage",           "NA",   "NA",           B, "Professional bowling ball"},
	{"Potato Mine","Takes time to arm, then explodes.",             25,  30,  300,  1800,   "Damage",           "Tile", "NA",           B, "Very good for early game"},
	{"Snow Pea",   "Shoots slowing projectiles.",                   175, 7.5, 300,  20,     "Damage",           "Lane", "Normal",       A, "Torchwood turns his peas into normal ones"},
	{"Chomper",    "Eats zombies whole, but takes time to chew.",   150, 7.5, 300,  1800,   "Damage",           "Tile", "Very Slow",    B, "For bigger zombies he just deals 40 damage"},
	{"Repeater",   "Shoots two peas at once.",                      200, 7.5, 300,  20,     "Damage (per pea)", "Lane", "Normal",       B, "Has a left-facing variant called Leftpeater"},
};

// this function is how we get the plant's entry from the index provided
PlantEntry getPlantEntry(int entryNumber) {
	return PlantAlmanac[entryNumber];
}

/*
############################################################
Z O M B I E S
############################################################
*/

struct ZombieEntry { // the outline for a zombie's entry
	string name;
	string description;
	// string flavor;
	int toughness;
	int toughnessTotal;
	int armorToughness;
	string ability;
	string range;
	int tier;
	string fact;
};

enum ZombiePages {
	ZOMBIE,
	FLAG,
	CONEHEAD,
	POLEVAULTER,
	BUCKETHEAD,
};

vector<string> ZombieFlavorTexts = {
	"Yeah, sure, all he's got is his brown coat and tie, but he doesn't need those fancy cones or buckets.",
	"Most zombies like brains, but this one likes flags more. Either it's that or the flag has a brain on it.",
	"A normal zombie who came across a traffic cone and decided to put it on his head. Now that's a party animal.",
	"He actually prefers hurdles. Nothing personal. He just likes jumping without the help of the pole.",
	"Former painter, he's been wearing the bucket forever. Mainly because he forgot it was there.",
};

vector<ZombieEntry> ZombieAlmanac = {
	//Name                      Description                                         HP      TrueHP Armor   Ability                     Range  Tier Fact
	{"Zombie",                  "Your everyday garden-variety zombie.",             200,    270,   0,      "No Ability",               "NA",   F, "Most common zombie, found in literally every level"},
	{"Flag Zombie",             "The commander of a huge wave of zombies.",         200,    270,   0,      "No Ability",               "NA",   D, "About twice as fast as a regular zombie"},
	{"Conehead Zombie",         "Another simple shuffler, with a twist.",           200,    270,   370,    "No Ability",               "NA",   C, "Second most common zombie"},
	{"Pole Vaulting Zombie",    "A sporty zombie with a very helpful pole.",        340,    500,   0,      "Can vault a plant.",       "Close",C, "Can't vault over tall plants like Tall-nut"},
	{"Buckethead Zombie",       "A bucket-wearing warrior and a lot of health.",    200,    270,   1100,   "No Ability",               "NA",   B, "Can have his bucket stolen by Magnet-Shroom"},
};

// this function is how we get the zombies's entry from the index provided
ZombieEntry getZombieEntry(int entryNumber) {
	return ZombieAlmanac[entryNumber];
}

// gets the text for a tier, complete with colors
string getTierText(int tier)
{
	return formatText(TierText[tier], RGBCOLOR, true, TierColors[tier]);
}