#pragma once

#include <iostream>
#include "LocalizeExports.h"
#include <boost/locale.hpp>
// Boost Requries `Linker`->`Additional Library Directories` to contain a path to the boost libraries on the system. i.e. <Path_To_Boost>\boost_1_78_0\stage\lib
// Boost Requires `C/C++`->`Additional Include Directories` to contain a path to boost on the system. i.e. <Path_To_Boost>\boost_1_78_0


class LOCALIZE_API Localize 
{
public:
	Localize(Localize const&) = delete;
	void operator=(Localize const&) = delete;

	~Localize();

	/// <summary>
	/// Get the singleton for the class
	/// </summary>
	/// <returns>Pointer to Singleton if it exists, null if not</returns>
	static Localize* GetInstance();

	/// <summary>
	/// Initialize the Localize Singleton and translation dependencies
	/// Initialize the default locale
	/// </summary>
	/// <returns>True if initialized, False if not</returns>
	static bool InitializeLocalize();

	/// <summary>
	/// Uninitialize the Localize Singleton and translation dependencies
	/// </summary>
	/// <returns>True if uninitialized, Flase if not</returns>
	static bool UninitializeLocalize();

	/// <summary>
	/// Set the current locale dynamically
	/// </summary>
	/// <param name="locale">The locale to be set</param>
	/// <returns>True if locale is set, False if not</returns>
	/// NOTE: Currently supports English and German
	bool SetLocale(const std::string& locale);
	
	/// <summary>
	/// Returns the currently set locale
	/// </summary>
	/// <returns>The current locale, or an empty string on failure</returns>
	std::string GetLocale();

	/// <summary>
	/// Translate the given string according to the currently set locale
	/// </summary>
	/// <param name="str">[in/out]The string to be translated, and the translated string if successful</param>
	/// <returns>True if the translation was successful, false if not</returns>
	bool Translate(std::string& str);

	/// <summary>
	/// Translate the given string according to the provided locale
	/// </summary>
	/// <param name="str">[in/out] The string to be translated, and the translated string if successful</param>
	/// <param name="locale">The locale to translate</param>
	/// <returns>True if the translation is successful, False if not</returns>
	/// @note locale is NOT set persistently, it is only used for this one translation
	bool TranslateLocale(std::string& str, const std::string& locale);

private:
	Localize();
	bool initialized;
	std::string locale;
	boost::locale::generator gen;

	// Private constructor so class cannot be directly instantiated
};
