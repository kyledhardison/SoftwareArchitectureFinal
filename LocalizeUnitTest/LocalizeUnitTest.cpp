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
		///		Ensure that Localize can only be initialized once.
		/// </summary>
		TEST_METHOD(InitializeTest)
		{
			// Uninitialize Localize
			Localize::UninitializeLocalize();

			// Verify that InitializeLocalize returns true
			Assert::IsTrue(Localize::InitializeLocalize());

			// Verify that the second call to InitializeLocalize returns false
			Assert::IsFalse(Localize::InitializeLocalize());

			// Uninitialize Localize
			Localize::UninitializeLocalize();

		}

		/// <summary>
		///		Ensure that Localize can only be uninitialized once.
		/// </summary>
		TEST_METHOD(UninitializeTest)
		{
			// Initialize Localize
			Localize::InitializeLocalize();

			// Verify Uninitialize returns true
			Assert::IsTrue(Localize::UninitializeLocalize());

			// Verify Uninitialize returns false
			Assert::IsFalse(Localize::UninitializeLocalize());

			// Verify Uninitialize returns false
			Assert::IsFalse(Localize::UninitializeLocalize());

		}

		/// <summary>
		///		Ensure that SetLocale returns false if Localize is uninitialized.
		/// </summary>
		TEST_METHOD(SetLocaleUninitializedTest)
		{
			// Test Variables
			std::string englishLocale("en.UTF-8");

			// Do NOT Initialize Localize

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Verify that SetLocale returns false if Localize is uninitialized
			Assert::IsFalse(localize->SetLocale(englishLocale));

		}

		/// <summary>
		///		Ensure that SetLocale returns false with a unsupported locale.
		/// </summary>
		TEST_METHOD(SetLocaleInvalidTest)
		{
			// Test Variables
			std::string frenchLocale("fr_FR.UTF-8");

			// Initialize Localize
			Localize::InitializeLocalize();

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Verify that SetLocale returns false with an unsupported locale
			Assert::IsFalse(localize->SetLocale(frenchLocale));

			// Uninitialize Localize
			Localize::UninitializeLocalize();
		}
		
		/// <summary>
		///		Ensure that SetLocale returns true with a supported locale.
		/// </summary>
		TEST_METHOD(SetLocaleValidTest)
		{
			// Test Variables
			std::string englishLocale("en.UTF-8");
			std::string germanLocale("de_DE.UTF-8");
			
			// Initialize Localize
			Localize::InitializeLocalize();

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Verify that SetLocale returns true with a supported locale
			Assert::IsTrue(localize->SetLocale(englishLocale));

			// Verify that SetLocale returns true with a supported locale
			Assert::IsTrue(localize->SetLocale(germanLocale));

			// Uninitialize Localize
			Localize::UninitializeLocalize();
		}

		/// <summary>
		///		Ensure that GetLocale returns an empty string if Localize is uninitialized.
		/// </summary>
		TEST_METHOD(GetLocaleUninitializedTest)
		{
			// Do NOT Initialize Localize

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Verify that GetLocale returns null while localize is uninitialized
			Assert::IsTrue(localize->GetLocale().empty());
			
		}

		/// <summary>
		///		Ensure that GetLocale returns the set locale.
		///		Ensure that SetLocale can change the locale.
		///		Ensure that GetLocale returns the set locale.
		/// </summary>
		TEST_METHOD(GetLocaleTest)
		{
			// Test Variables
			std::string str;
			std::string englishLocale("en.UTF-8");
			std::string germanLocale("de_DE.UTF-8");

			// Initialize Localize
			Localize::InitializeLocalize();

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Get the default locale
			str = localize->GetLocale();

			// Verify that the default locale is correct
			Assert::IsTrue(str == englishLocale);

			// Set a valid non-default locale
			Assert::IsTrue(localize->SetLocale(germanLocale));
			
			// Get the non-default locale
			str = localize->GetLocale();

			// Verify that the non-default locale is correct
			Assert::IsTrue(str == germanLocale);

			// Uninitialize Localize
			Localize::UninitializeLocalize();
		}

		/// <summary>
		///		Ensure that Translate returns false if Localize is uninitialized.
		/// </summary>
		TEST_METHOD(TranslateUninitializedTest)
		{
			// Test Variables
			std::string str("Test String");
			std::string result("Result String");
			std::string expectedTranslation("Result String");

			// Do NOT Initialize Localize

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Verify localize->Translate returns false
			Assert::IsFalse(localize->Translate(str, result));

			// Verify that the translation did not occur
			Assert::IsTrue(result == expectedTranslation);
			
			// Uninitialize Localize
			Localize::UninitializeLocalize();
		}

		/// <summary>
		///		Ensure that Translate returns false for a string that is not in the English dictionary.
		/// </summary>
		TEST_METHOD(TranslateEnglishInvalidStringTest)
		{
			// Test Variables
			std::string str("String NOT in the English dictonary"); // DO NOT add this string to the English dictionary
			std::string result("Result String");
			std::string expectedTranslation("String NOT in the English dictonary");
			 
			// Initialize Localize
			Localize::InitializeLocalize();

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Verify localize->Translate returns false
			Assert::IsFalse(localize->Translate(str, result));

			// Verify that the translation did not occur
			Assert::IsTrue(result == expectedTranslation);

			// Uninitialize Localize
			Localize::UninitializeLocalize();
		}

		/// <summary>
		///		Ensure that Translate returns false for a string that is not in the German dictionary.
		/// </summary>
		TEST_METHOD(TranslateGermanInvalidStringTest)
		{
			// Test Variables
			std::string str("String NOT in the German dictonary"); // DO NOT add this string to the German dictionary
			std::string result("Result String");
			std::string expectedTranslation("String NOT in the German dictonary");
			std::string locale("de_DE.UTF-8");

			// Initialize Localize
			Localize::InitializeLocalize();

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Set the German locale for translation
			localize->SetLocale(locale);

			// Verify localize->Translate returns false
			Assert::IsFalse(localize->Translate(str, result));

			// Verify that the translation did not occur
			Assert::IsTrue(result == expectedTranslation);

			// Uninitialize Localize
			Localize::UninitializeLocalize();
		}

		/// <summary>
		///		Ensure that Translate returns true for a string that is in the English dictionary.
		///		Ensure that the string is properly translated.
		/// </summary>
		TEST_METHOD(TranslateEnglishValidStringTest)
		{
			// Test Variables
			std::string str("Test String"); // Must be in the English Dictionary
			std::string result("Result String");
			std::string expectedTranslation("English Translated String");

			// Initialize Localize
			Localize::InitializeLocalize();

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Verify localize->Translate returns true
			Assert::IsTrue(localize->Translate(str, result));

			// Verify that the translation is correct
			Assert::IsTrue(result == expectedTranslation);

			// Uninitialize Localize
			Localize::UninitializeLocalize();
		}
		
		/// <summary>
		///		Ensure that Translate returns true for a string that is in the German dictionary.
		///		Ensure that the string is properly translated.
		/// </summary>
		TEST_METHOD(TranslateGermanValidStringTest)
		{
			// Test Variables
			std::string str("Test String"); // Must be in the German Dictionary
			std::string result("Result String");
			std::string expectedTranslation("German Translated String");
			std::string locale("de_DE.UTF-8");

			// Initialize Localize
			Localize::InitializeLocalize();

			// Get the Localize Instance
			Localize* localize = Localize::GetInstance();

			// Set the German locale for translation
			localize->SetLocale(locale);
			
			// Verify localize->Translate returns true
			Assert::IsTrue(localize->Translate(str, result));

			// Verify that the translation is correct
			Assert::IsTrue(result == expectedTranslation);

			// Uninitialize Localize
			Localize::UninitializeLocalize();
		}

		/* TODO Get working, then re-enable
		/// <summary>
		/// Ensure that TranslateLocale returns false if Localize is uninitialized
		/// </summary>
		TEST_METHOD(TranslateLocaleUninitializedTest)
		{
			// Uninitialize test to start
			Localize::UninitializeLocalize();

			std::string str("Test String");
			std::string result("Result String");
			// A valid non-default locale
			std::string locale("de_DE.UTF-8");
			Localize* localize = Localize::GetInstance();

			Assert::IsFalse(localize->TranslateLocale(str, locale));
		}

		// New test
		//TODO: re-add this test for translationLocal (if we support it)

		// Assert::IsTrue(localize->TranslateLocale(str, locale));
		*/
	};
}
