#include "Localize.h"
#include <boost/locale.hpp>

Localize::Localize() {}

Localize::~Localize() {}

Localize* Localize::GetInstance()
{
	static Localize instance;

	return &instance;
}

bool Localize::InitializeLocalize()
{
	Localize* instance = Localize::GetInstance();

	if (instance->initialized) {
		return false;
	}

	// Initialize Boost generator
	instance->generator = new boost::locale::generator();
	
	// Specify location of Boost Dictionaries
	instance->generator->add_messages_path("C:\\Users\\jpbro\\Documents\\develop\\SoftwareArch\\FinalProject\\SoftwareArchitectureFinal\\Localize"); // Path to .mo file
	instance->generator->add_messages_domain("Localize"); // Name of .mo file

	// Set the default locale (english)
	instance->locale = "en.UTF-8";
	std::locale::global((*instance->generator)(instance->locale));
	std::cout.imbue(std::locale());
	
	instance->initialized = true;
	
	return true;
}

bool Localize::UninitializeLocalize()
{
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return false;
	}
	
	// Uninitialize everything
	instance->locale = std::string();
	delete instance->generator;
	instance->initialized = false;

	return true;
}

bool Localize::SetLocale(const std::string locale)
{
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return false;
	}
	
	// Validate locale
	if (locale != "en.UTF-8" && locale != "de_DE.UTF-8") {
		// Unsupported Locale
		return false;
	}
	
	// Generate locales and imbue them to iostream
	instance->locale = locale;
	std::locale::global((*instance->generator)(instance->locale));
	std::cout.imbue(std::locale());
	
	return true;
}

std::string Localize::GetLocale()
{
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return std::string();
	}

	return instance->locale;
}

bool Localize::Translate(const std::string& str, std::string &result)
{
	Localize* instance = Localize::GetInstance();
	
	if (!instance->initialized) {
		return false;
	}
	
	// Call the Boost Translation function
	result.clear();
	result = boost::locale::translate(str);
	
	// Check if a translation occured (does NOT check for a successful translation)
	if (result != str) {
		return true;
	}
	else {
		return false;
	}

}
/*
bool Localize::TranslateLocale(const char* str, const char* locale)
{
	// Do the translation according to the locale passed in the 2nd arg, return true/false
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return false;
	}

	// Translated string should be put in str param
	const char* temp = boost::locale::translate(str).str(locale);

	if (temp == str) {
		str = temp;
		return true;
	}
	else {
		return false;
	}	
}
*/