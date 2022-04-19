#include "Localize.h"
#include <boost/locale.hpp>

Localize::Localize() {}

Localize::~Localize() {}

bool Localize::InitializeLocalize()
{
	Localize* instance = Localize::GetInstance();

	if (instance->initialized) {
		return false;
	}
	// Initialize needed boost stuff
	
	// Specify location of dictionaries
	instance->gen.add_messages_path("C:\\Users\\jpbro\\Documents\\develop\\SoftwareArch\\FinalProject\\SoftwareArchitectureFinal\\Localize"); // Path to .mo file
	instance->gen.add_messages_domain("Localize"); // Name of .mo file

	// Use instance->SetLocale() - set the default locale here (english)
	instance->SetLocale("en.UTF-8");

	instance->initialized = true;

	return true;
}

bool Localize::UninitializeLocalize()
{
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return false;
	}
	// Uninitialize any boost stuff that's needed
	instance->locale = "";

	instance->initialized = false;

	return true;
}

Localize* Localize::GetInstance()
{
	static Localize instance;

	return &instance;
}

bool Localize::SetLocale(const std::string& locale)
{
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return false;
	}
	
	if (locale != "en.UTF-8" && locale != "de_DE.UTF-8") {
		// Unsupported Locale
		return false;
	}

	instance->locale = locale;

	// Generate locales and imbue them to iostream
	std::locale::global(instance->gen(locale));
	std::cout.imbue(std::locale());
	
	return true;
}

std::string Localize::GetLocale()
{
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return "";
	}

	return instance->locale;
}

bool Localize::Translate(std::string& str)
{
	// Do the translation according to the currently set locale, return true/false
	Localize* instance = Localize::GetInstance();
	
	if (!instance->initialized) {
		return false;
	}

	// Translated string should be put in str param
	std::string temp = boost::locale::translate("translate_string1");
	
	if (temp == str) {
		str = temp;
		return true;
	}
	else {
		return false;
	}

}

bool Localize::TranslateLocale(std::string& str, const std::string& locale)
{
	// Do the translation according to the locale passed in the 2nd arg, return true/false
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return false;
	}

	// Translated string should be put in str param
	std::string temp = boost::locale::translate("translate_string2").str(locale);

	if (temp == str) {
		str = temp;
		return true;
	}
	else {
		return false;
	}	
}