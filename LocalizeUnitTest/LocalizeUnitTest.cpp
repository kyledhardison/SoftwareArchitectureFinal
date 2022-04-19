#include "pch.h"
#include "CppUnitTest.h"
#include "../Localize/Localize.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LocalizeUnitTest
{
	TEST_CLASS(LocalizeUnitTest)
	{
	public:
		
		/// <summary>
		/// Ensure that Localize can only be initialized once
		/// </summary>
		TEST_METHOD(InitializeTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			Assert::IsTrue(Localize::InitializeLocalize());

			Assert::IsFalse(Localize::InitializeLocalize());
		}

		/// <summary>
		/// Ensure that Localize can only be initialized once
		/// </summary>
		TEST_METHOD(UninitializeTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			Localize::InitializeLocalize();

			Assert::IsTrue(Localize::UninitializeLocalize());

			Assert::IsFalse(Localize::UninitializeLocalize());

			Assert::IsFalse(Localize::UninitializeLocalize());
		}

		/// <summary>
		/// Ensure that SetLocale fails if Localize is uninitialized
		/// </summary>
		TEST_METHOD(SetLocaleUninitializedTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			Localize* localize = Localize::GetInstance();

			// A valid locale
			Assert::IsFalse(localize->SetLocale("en.UTF-8"));
		}

		/// <summary>
		/// Ensure that SetLocale returns successfully if Localize is initialized
		/// </summary>
		TEST_METHOD(SetLocaleTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			Localize* localize = Localize::GetInstance();

			Localize::InitializeLocalize();

			// A valid Locale
			Assert::IsTrue(localize->SetLocale("en.UTF-8"));
		}

		/// <summary>
		/// Ensure that GetLocale returns an empty string if Localize is uninitialized
		/// </summary>
		TEST_METHOD(GetLocaleUninitializedTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			Localize* localize = Localize::GetInstance();

			Assert::IsTrue(localize->GetLocale().empty());
		}

		/// <summary>
		/// Ensure that GetLocale returns true if locale was set successfully
		/// Ensure that GetLocale returns the set locale if locale has been set
		/// </summary>
		TEST_METHOD(GetLocaleTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			Localize* localize = Localize::GetInstance();

			Localize::InitializeLocalize();

			// A valid non-default locale
			Assert::IsTrue(localize->SetLocale("de_DE.UTF-8"));
			
			// The same valid locale here
			std::string str = localize->GetLocale();
			Assert::IsTrue(str == "de_DE.UTF-8");
		}

		/// <summary>
		/// Ensure that Translate returns false if Localize is uninitialized
		/// </summary>
		TEST_METHOD(TranslateUninitializedTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			std::string str("Test String");
			Localize* localize = Localize::GetInstance();

			Assert::IsFalse(localize->Translate(str));
		}

		/// <summary>
		/// Ensure that Translate returns false for a string that is not in the translation database
		/// </summary>
		TEST_METHOD(TranslateInvalidStringTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			// DO NOT add this string to the translation database
			std::string str("Test String that is not in the database");
			Localize* localize = Localize::GetInstance();

			Localize::InitializeLocalize();

			Assert::IsFalse(localize->Translate(str));
		}

		/// <summary>
		/// Ensure that Translate returns true for a string that is in the database
		/// Ensure that the string is properly translated
		/// </summary>
		TEST_METHOD(TranslateTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			// TODO add these strings to the translation database
			std::string str("Test String");
			std::string translatedStr("English Translated String");
			Localize* localize = Localize::GetInstance();

			Localize::InitializeLocalize();

			// A valid locale for translation
			localize->SetLocale("en.UTF-8");

			Assert::IsTrue(localize->Translate(str));

			Assert::IsTrue(str == translatedStr);
		}

		/// <summary>
		/// Ensure that TranslateLocale returns false if Localize is uninitialized
		/// </summary>
		TEST_METHOD(TranslateLocaleUninitializedTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			std::string str("Test String");
			// A valid non-default locale
			std::string locale("de_DE.UTF-8");
			Localize* localize = Localize::GetInstance();

			Assert::IsFalse(localize->TranslateLocale(str, locale));
		}

		/// <summary>
		/// Ensure that TranslateLocale returns true for a string that is in the database
		/// Ensure that the string is properly translated according to the locale passed
		/// </summary>
		TEST_METHOD(TranslateLocaleTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			std::string str("Test String");
			std::string translatedStr("German Translated String");

			// A valid non-default locale
			std::string locale("de_DE.UTF-8");

			Localize* localize = Localize::GetInstance();

			Localize::InitializeLocalize();

			Assert::IsTrue(localize->TranslateLocale(str, locale));

			Assert::IsTrue(str == translatedStr);
		}

	};
}
