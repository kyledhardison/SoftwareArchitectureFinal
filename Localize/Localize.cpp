#include "Localize.h"

Localize::Localize() {}

Localize::~Localize() {}

bool Localize::InitializeLocalize()
{
	Localize* instance = Localize::GetInstance();

	if (instance->initialized) {
		return false;
	}
	// TODO  initialize any boost stuff needed
	// Use instance->SetLocale() - set the default locale here, probably english

	instance->initialized = true;

	return true;
}

bool Localize::UninitializeLocalize()
{
	Localize* instance = Localize::GetInstance();

	if (!instance->initialized) {
		return false;
	}
	// TODO Uninitialize any boost stuff that's needed

	instance->initialized = false;

	return true;
}

Localize* Localize::GetInstance()
{
	static Localize instance;

	return &instance;
}

bool Localize::SetLocale(std::string locale)
{
	// TODO set the locale
	return false;
}

std::string Localize::GetLocale()
{
	return m_locale;
}

bool Localize::Translate(std::string* str)
{
	// TODO do the translation according to the currently set locale, return true/false
	// Translated string should be put in str param

	return false;
}

bool Localize::TranslateLocale(std::string* str, std::string locale)
{
	// TODO do the translation according to the locale passed in the 2nd arg, return true/false
	// Translated string should be put in str param
	return false;
}