# Software Architecture Final Project
Kyle Hardison & John Brown

## Introduction
For the final project, we were given task 4, which involves creating a library that deals with localization for the entire project.

## Requirements
The first 6 requirements were given to us. Requirements 7-9 were additions we came up with after some consideration. 

1 (Required) - All localization capabilities will be handled by one library.

2 (Desired) - The library will have the ability to switch locales during execution.

3 (Desired) - All `po` files will be merged together.

4 (Desired) - xtext will be run as part of the build process.

5 (Required) - The library will be in the core layer but separate from the core.

6 (Desired) - There will be utilities that check for `mo` files.

7 (Optional) - Multiple language options will be implemented for localization.

8 (Optional) - Localization will be a licensed feature, requiring specific licenses for its support.

9 (Optional) - Investigate alternative translation libraries for the future, with easier implementation than boost.

## Implemented Reqiurements
We plan on definitely implementing reqiurements 1, 2, 3, and 5.

If time permits, requirements 4, 6, and 7 will be implemented.

Requirements 7 and 9 are purely intended for future work outside the scope of this project.

## Estimation

We estimate that part 2 of the project will take 8 hours total:
* Initial technology investigation - 1 hour
* API design - 1 hour
* Design Document - 1 hours
* API stub implementation - 2 hours
* Unit Tests implementation - 3 hours

We estimate that part 3 of the project will take hours 7.5 total:
* Initial investigation/technology refresher - 2 hour
* Boost installation - 0.5 hours
* Initial Translation implementation - 3 hours
* Runtime locale switching implementation - 1 hour
* Unit test verification & debugging - 1 hour

Optional additional work could potentially take 3.5 hours, if time allows:
* xtext build process integration - 1 hour
* `mo` file searcher - 2 hours
* Multiple language support - 0.5 hours

## Conclusion
* We implemented requirements 1, 2, 3, 5, and 7. Our solution is a standalone library (which requires boost installed locally), which covers requirement 1. Our Localization library contains the ability to dynamically switch between locales and supports both English and German translation. These two points cover requirements 2 and 7 respectfully. The library also supports combined `po` files, covering requirement 3. Our localization library also runs at the `core` layer of an application, completing requirement 5. 
* The implementation took way longer than expected, with implementation taking around 10 hours to develop. Our final solution consists of nine functions. Two functions initialize and uninitialized the library. One function returns the instance of the Localize object. We created two functions to get and set the locale used for translation. The remaining four functions implement translation. The translation functions take a translation string and a context string, and complete translation based on the currently configured locale. Note that the translation will not occur unless the `.po` file is created correctly, refer to the boost documentation for instructions. The remaining two of the translation functions are implemented, but unsupported. They take a translation string, a optional context string, and a locale, and complete the translation based on the given locale instead of the currently configured locale. This feature was pushed for future development.
* The following image shows the results of the unit tests for our Localization Library:
![Successful Unit Tests](https://github.com/kyledhardison/SoftwareArchitectureFinal/blob/main/UnitTestsPassing.png?raw=true)
