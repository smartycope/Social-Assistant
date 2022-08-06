#pragma once

#include "displayapp/screens/DateAid.h"
#include <string>

using namespace Pinetime::Applications::Screens;

std::string DateAid::getQuestion(int8_t deepLevel, uint16_t index) {
    std::string s = error;
    // clang-format off
  switch (deepLevel) {
    case 0:
      switch (index){
        case 0: s = "Where are you from?"; break;
        case 1: s = "What are you studying?"; break;
        case 2: s = "Where do you work?"; break;
        case 3: s = "What do you like to do for fun?"; break;
        case 4: s = "What is something you do in your free time?"; break;
        case 5: s = "What kind of books to you like?"; break;
        case 6: s = "What kind of music do you like?"; break;
        case 7: s = "What's your favorite TV show?"; break;
        case 8: s = "Do you play an instrument?"; break;
      }
      break;
    // First date questions
    case 1:
      switch(index){
        case 0: s = "What is something you'd like to do more of?"; break;
        case 1: s = "What's something you're interested in?"; break;
        case 2: s = "What is something you'd like to learn more about?"; break;
        case 3: s = "What's the craziest thing that's happened to you?"; break;
        case 4: s = "What is something you're passionate about?"; break;
        case 5: s = "Who is a hero from media you look up to?"; break;
        case 6: s = "What is something that makes you laugh?"; break;
        case 7: s = "What is something in your life that's happened that you can't explain?"; break;
        case 8: s = "What's something you've learned this week?"; break;
        case 9: s = "Is there anything you really geek out over?"; break;
        case 10: s = "Where do you feel the happiest?"; break;
        case 11: s = "If you were to be stuck in a car with someone for 8 hours, who would you choose to be stuck with?"; break;
        case 12: s = "What's something you could talk about for hours?"; break;
        case 13: s = "How many siblings do you have?/Are you the oldest?"; break;
        case 14: s = "What's your favorite instrument to listen to?"; break;
        case 15: s = "What is your favorite food?"; break;
        case 16: s = "What is the one of the funnest things you've done?"; break;
        case 17: s = "What's your favorite place in your hometown?"; break;
        case 18: s = "When you think of home, what do you think of?"; break;
        case 19: s = "What are some of your pet peeves?"; break;
        case 20: s = "What's something you wish were more socially acceptable?"; break;
        case 21: s = "What's the worst/best job you've had?"; break;
        case 22: s = "Would you rather have more money or more time?"; break;
        case 23: s = "What's the worst/best strangest book you've read?"; break;
        case 24: s = "Whats something you could teach me about?"; break;
        case 25: s = "Whats something you consider yourself an expert in?"; break;
        case 26: s = "If you could pick one superpower, what would it be?"; break;
        case 27: s = "If you could only eat 3 foods for the rest of your life, what would you pick?"; break;
        case 28: s = "Would you rather fly or be invisible? No turning it off."; break;
        case 29: s = "If you had $1,000 and a weekend just to yourself, what would you do? (no practical answers)"; break;
        case 30: s = "If you could time travel, what year would you visit for a day? A week?"; break;
        case 31: s = "If you could only watch 3 books/movies for the rest of your life, what would you pick?"; break;
        case 32: s = "What are 3 things you would bring to a deserted island you're moving to?"; break;
        case 33: s = "What was the naughtiest thing you did as a kid?"; break;
        case 34: s = "Would you rather have more knowledge, more intelligence, or more wisdom?"; break;
        case 35: s = "If you could spend a day with one person, alive or dead, who would it be?"; break;
        case 36: s = "What's the strongest animal you think you could beat in a fight?"; break;
        case 37: s = "What is your earliest happy memory?"; break;
        case 38: s = "What's an accomplishment you're proud of?"; break;
        case 39: s = "Whats the most beautiful thing about your mom?"; break;
        case 40: s = "Whats the most beautiful thing about your dad?"; break;
        case 41: s = "Tell me about yourself"; break;
      }
      break;
    case 2:
      switch(index){
        case 0: s = "Have you served a mission?"; break;
        case 1: s = "What's new in your life?"; break;
        case 2: s = "What is something most people don't appreciate about you?"; break;
        case 3: s = "What's something people don't appreciate about you enough?"; break;
        case 4: s = "What is something really interesting about you?"; break;
        case 5: s = "What else is something most people don't know about you?"; break;
        case 6: s = "What are some things you wish people knew about you?"; break;
        case 7: s = "What are some questions you wish people would ask you?"; break;
        case 8: s = "What's something you find really attractive in a guy?"; break;
        case 9: s = "Are you more scared of failure or success?"; break;
        case 10: s = "What's the favorite compliment you've ever got?"; break;
        case 11: s = "What's a compliment you don't receive enough?"; break;
        case 12: s = "What's a compliment you think I need to hear right now?"; break;
        case 13: s = "whats a compliment you think I recive often?"; break;
        case 14: s = "Who is a stranger that's changed your life?"; break;
        case 15: s = "What does it take for you to be vunerable around someone?"; break;
        case 16: s = "Do you belive we met for a reason, and if so, what reason?"; break;
        case 17: s = "What is the biggest question you're trying to answer in your life right now?"; break;
        case 18: s = "What's something you've done that you regret?"; break;
        case 19: s = "What's a goal of yours right now?"; break;
        case 20: s = "What is something you're trying to let go of?"; break;
        case 21: s = "What is something you can't live with forever?"; break;
        case 22: s = "Most controversial opinion"; break;
        case 23: s = "What are your most fringe political views?"; break;
        case 24: s = "What's something you're ashamed to do?"; break;
      }
      break;
    case 3:
      switch(index) {
        case 0: s = "What do for think an alien encounter would look like"; break;
        case 1: s = "If your soul were a color, what color would it be?"; break;
        case 2: s = "Whats a song you could play at both a wedding and a funeral?"; break;
        case 3: s = "How many chickens do you think it would take to take an elephant? A wolf?"; break;
      }
      break;
            // clang-format on
    }
    return s;
}

//   "We aren't really strangers" game has a bunch of questions



// Standard questions, like how old are you, how many siblings, are you the oldest, etc



//  if you had to hide a dead body where would you


// Weird: do you believe in love at first sight?
// Do you think aliens would have a sense of humor?
// Invention you wish exist3d and could exist in your lifetime
// Ice cream flavor you like that doesn't exist
// Something you like that is bad
// Lady tv show you finished
// Do you think anyone has ever had an appendix implanted?
// If you could have 1 physical object dedicated to you, would you pick?
// If you must cause 1 animal to go extinct, what would you pick?
// If you could bring back 1 extinct species, what would you pick?
// How many tide pods could you eat in 1 go?
// How many bees could you defeat in a fight, unarmed and naked?
// What kind of parent do you think you would be?
// If you were a God, what precepts/commandments would you have?

// if you could gain the best and worst (you have to get both) attributes of an animal, which animal would you pick?

'/'



#include <cstdlib>
#include <cstring>

    using namespace Pinetime::Controllers;

Settings::Settings(Pinetime::Controllers::FS& fs): fs{ fs } { }

void Settings::Init() {
    // Load default settings from Flash
    LoadSettingsFromFile();
}

void Settings::SaveSettings() {
    // verify if is necessary to save
    if(settingsChanged) {
        SaveSettingsToFile();
    }
    settingsChanged = false;
}

void Settings::LoadSettingsFromFile() {
    SettingsData bufferSettings;
    lfs_file_t settingsFile;

    if(fs.FileOpen(&settingsFile, "/settings.dat", LFS_O_RDONLY) != LFS_ERR_OK) {
        return;
    }
    fs.FileRead(&settingsFile, reinterpret_cast<uint8_t*>(&bufferSettings), sizeof(settings));
    fs.FileClose(&settingsFile);
    if(bufferSettings.version == settingsVersion) {
        settings = bufferSettings;
    }
}

void Settings::SaveSettingsToFile() {
    lfs_file_t settingsFile;

    if(fs.FileOpen(&settingsFile, "/settings.dat", LFS_O_WRONLY | LFS_O_CREAT) != LFS_ERR_OK) {
        return;
    }
    fs.FileWrite(&settingsFile, reinterpret_cast<uint8_t*>(&settings), sizeof(settings));
    fs.FileClose(&settingsFile);
}



#pragma once

#include "displayapp/screens/DateAid.h"
#include <string>

using namespace Pinetime::Applications::Screens;

std::string DateAid::getQuestion(int8_t deepLevel, uint16_t index) {
    std::string s = error;
    // clang-format off
  switch (deepLevel) {
    case 0:
      switch (index){
        case 0: s = "Where are you from?"; break;
        case 1: s = "What are you studying?"; break;
        case 2: s = "Where do you work?"; break;
        case 3: s = "What do you like to do for fun?"; break;
        case 4: s = "What is something you do in your free time?"; break;
        case 5: s = "What kind of books to you like?"; break;
        case 6: s = "What kind of music do you like?"; break;
        case 7: s = "What's your favorite TV show?"; break;
        case 8: s = "Do you play an instrument?"; break;
      }
      break;
    // First date questions
    case 1:
      switch(index){
        case 0: s = "What is something you'd like to do more of?"; break;
        case 1: s = "What's something you're interested in?"; break;
        case 2: s = "What is something you'd like to learn more about?"; break;
        case 3: s = "What's the craziest thing that's happened to you?"; break;
        case 4: s = "What is something you're passionate about?"; break;
        case 5: s = "Who is a hero from media you look up to?"; break;
        case 6: s = "What is something that makes you laugh?"; break;
        case 7: s = "What is something in your life that's happened that you can't explain?"; break;
        case 8: s = "What's something you've learned this week?"; break;
        case 9: s = "Is there anything you really geek out over?"; break;
        case 10: s = "Where do you feel the happiest?"; break;
        case 11: s = "If you were to be stuck in a car with someone for 8 hours, who would you choose to be stuck with?"; break;
        case 12: s = "What's something you could talk about for hours?"; break;
        case 13: s = "How many siblings do you have?/Are you the oldest?"; break;
        case 14: s = "What's your favorite instrument to listen to?"; break;
        case 15: s = "What is your favorite food?"; break;
        case 16: s = "What is the one of the funnest things you've done?"; break;
        case 17: s = "What's your favorite place in your hometown?"; break;
        case 18: s = "When you think of home, what do you think of?"; break;
        case 19: s = "What are some of your pet peeves?"; break;
        case 20: s = "What's something you wish were more socially acceptable?"; break;
        case 21: s = "What's the worst/best job you've had?"; break;
        case 22: s = "Would you rather have more money or more time?"; break;
        case 23: s = "What's the worst/best strangest book you've read?"; break;
        case 24: s = "Whats something you could teach me about?"; break;
        case 25: s = "Whats something you consider yourself an expert in?"; break;
        case 26: s = "If you could pick one superpower, what would it be?"; break;
        case 27: s = "If you could only eat 3 foods for the rest of your life, what would you pick?"; break;
        case 28: s = "Would you rather fly or be invisible? No turning it off."; break;
        case 29: s = "If you had $1,000 and a weekend just to yourself, what would you do? (no practical answers)"; break;
        case 30: s = "If you could time travel, what year would you visit for a day? A week?"; break;
        case 31: s = "If you could only watch 3 books/movies for the rest of your life, what would you pick?"; break;
        case 32: s = "What are 3 things you would bring to a deserted island you're moving to?"; break;
        case 33: s = "What was the naughtiest thing you did as a kid?"; break;
        case 34: s = "Would you rather have more knowledge, more intelligence, or more wisdom?"; break;
        case 35: s = "If you could spend a day with one person, alive or dead, who would it be?"; break;
        case 36: s = "What's the strongest animal you think you could beat in a fight?"; break;
        case 37: s = "What is your earliest happy memory?"; break;
        case 38: s = "What's an accomplishment you're proud of?"; break;
        case 39: s = "Whats the most beautiful thing about your mom?"; break;
        case 40: s = "Whats the most beautiful thing about your dad?"; break;
        case 41: s = "Tell me about yourself"; break;
      }
      break;
    case 2:
      switch(index){
        case 0: s = "Have you served a mission?"; break;
        case 1: s = "What's new in your life?"; break;
        case 2: s = "What is something most people don't appreciate about you?"; break;
        case 3: s = "What's something people don't appreciate about you enough?"; break;
        case 4: s = "What is something really interesting about you?"; break;
        case 5: s = "What else is something most people don't know about you?"; break;
        case 6: s = "What are some things you wish people knew about you?"; break;
        case 7: s = "What are some questions you wish people would ask you?"; break;
        case 8: s = "What's something you find really attractive in a guy?"; break;
        case 9: s = "Are you more scared of failure or success?"; break;
        case 10: s = "What's the favorite compliment you've ever got?"; break;
        case 11: s = "What's a compliment you don't receive enough?"; break;
        case 12: s = "What's a compliment you think I need to hear right now?"; break;
        case 13: s = "whats a compliment you think I recive often?"; break;
        case 14: s = "Who is a stranger that's changed your life?"; break;
        case 15: s = "What does it take for you to be vunerable around someone?"; break;
        case 16: s = "Do you belive we met for a reason, and if so, what reason?"; break;
        case 17: s = "What is the biggest question you're trying to answer in your life right now?"; break;
        case 18: s = "What's something you've done that you regret?"; break;
        case 19: s = "What's a goal of yours right now?"; break;
        case 20: s = "What is something you're trying to let go of?"; break;
        case 21: s = "What is something you can't live with forever?"; break;
        case 22: s = "Most controversial opinion"; break;
        case 23: s = "What are your most fringe political views?"; break;
        case 24: s = "What's something you're ashamed to do?"; break;
      }
      break;
    case 3:
      switch(index) {
        case 0: s = "What do for think an alien encounter would look like"; break;
        case 1: s = "If your soul were a color, what color would it be?"; break;
        case 2: s = "Whats a song you could play at both a wedding and a funeral?"; break;
        case 3: s = "How many chickens do you think it would take to take an elephant? A wolf?"; break;
      }
      break;
            // clang-format on
    }
    return s;
}

//   "We aren't really strangers" game has a bunch of questions



// Standard questions, like how old are you, how many siblings, are you the oldest, etc



//  if you had to hide a dead body where would you


// Weird: do you believe in love at first sight?
// Do you think aliens would have a sense of humor?
// Invention you wish exist3d and could exist in your lifetime
// Ice cream flavor you like that doesn't exist
// Something you like that is bad
// Lady tv show you finished
// Do you think anyone has ever had an appendix implanted?
// If you could have 1 physical object dedicated to you, would you pick?
// If you must cause 1 animal to go extinct, what would you pick?
// If you could bring back 1 extinct species, what would you pick?
// How many tide pods could you eat in 1 go?
// How many bees could you defeat in a fight, unarmed and naked?
// What kind of parent do you think you would be?
// If you were a God, what precepts/commandments would you have?

// if you could gain the best and worst (you have to get both) attributes of an animal, which animal would you pick?
