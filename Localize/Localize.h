#pragma once

#include <iostream>
#include "LocalizeExports.h"


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
	bool SetLocale(std::string locale);
	
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
	bool Translate(std::string* str);

	/// <summary>
	/// Translate the given string according to the provided locale
	/// </summary>
	/// <param name="str">[in/out] The string to be translated, and the translated string if successful</param>
	/// <param name="locale">The locale to translate</param>
	/// <returns>True if the translation is successful, False if not</returns>
	/// @note locale is NOT set persistently, it is only used for this one translation
	bool TranslateLocale(std::string* str, std::string locale);

private:
	Localize();
	std::string m_locale;
	bool initialized;

	// Private constructor so class cannot be directly instantiated
};
