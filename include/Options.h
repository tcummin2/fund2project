#ifndef OPTIONS_H
#define OPTIONS_H

#include <string>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <stdexcept>


// TODO (Thomas Luppi#4#04/06/14): Change to NOT be a singleton!!!!

///Contains all loaded options
/*! Any sort of modifiable values in the game that don't need to be changed in real value (Such as binded buttons, default screen values, debug output) is contained and loaded here */
class Options {
public:
    //! Default constructor
    /*! Loads a options file into memory
        \param name The filename of the options file, default is "options.txt"
        */
	Options(std::string name="options.txt");
	//! Returns the setting linked to the name
	/*! Will attempt to find the loaded option, first from the arguments created when the program is created, options loaded from the options file, then the default options.
        If no option in any of these lists is found, it will throw a logical_error. Thus a default option should ALWAYS exist
        \param name the name of the option to look up
        \return the string linked to the option name
    */
	std::string get(std::string name); //Gets an option
	//! Sets a specific option to a value. This overwrites the list created by loading the options file
	/*! \param name Option name to change
        \param set The value to set the option to
    */
	void set(std::string name, std::string set) {settings[name] = set;} //Sets an option to something, or creates a new one
	//! Fills the options file with default values
	void reset(); //Default settings file
	//! Fills the options file with the currently loaded values
	void save(); //Saves the settings to a file
	//! Outputs all loaded options to the console, for debug purposes
	void debugOut(); //lists all settings
	//! Fills the options map
	/*! \param name The filename of the options file, relative to the binary */
	void load(std::string name);
	//! Returns a pointer to the Options singleton
	/*! \return pointer to the options singleton */
	static Options& instance() {
		static Options INSTANCE;
		return INSTANCE;
	}
private:
	std::string fileName;
	std::unordered_map<std::string,std::string> settings;
	std::unordered_map<std::string,std::string> defaultSettings;
	void fillDefault();
};

#endif

