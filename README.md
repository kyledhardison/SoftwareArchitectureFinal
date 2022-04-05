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

