#include "displayapp/screens/DateAid.h"
#include "displayapp/DisplayApp.h"
#include "displayapp/screens/Questions.h"
#include "lvgl/src/lv_core/lv_disp.h"
#include "lvgl/src/lv_core/lv_obj.h"
#include "lvgl/src/lv_misc/lv_area.h"
#include "lvgl/src/lv_widgets/lv_label.h"
#include <cstdint>

using namespace Pinetime::Applications::Screens;
using namespace Pinetime::Controllers;

constexpr const char DateAid::levelLabels[DEEP_LEVELS][21]{
    "Stranger Questions", "First Date Questions", "Deep Questions", "Weird Questions"
};

DateAid::DateAid(DisplayApp* app): Screen(app), fs{ fs } {
    // Add newlines to all the questions
    for(int16_t l = DEEP_LEVELS; l; l--) {
        for(int16_t q = questionCount(l); q; q--) {
            insertLines(getQuestion(l, q), CHARS_PER_LINE);
        }
    }
    deepLabel = lv_label_create(lv_scr_act(), nullptr);
    lineLabel = lv_label_create(lv_scr_act(), nullptr);
    updateQuestion();

    if(fs.FileOpen(file, "/questions.txt", LFS_O_RDWR | LFS_O_CREAT) != LFS_ERR_OK)
        return;

    updateFile();
}

void DateAid::updateFile() {
    fs.FileWrite(file, reinterpret_cast<uint8_t*>(&settings), sizeof(settings));
}

DateAid::~DateAid() {
    fs.FileClose(file);
    lv_obj_clean(lv_scr_act());
}

bool DateAid::OnTouchEvent(Pinetime::Applications::TouchEvents event) {
    switch(event) {
        case TouchEvents::SwipeLeft:
            questionIndex += 1;
            updateQuestion();
            return true;
        case TouchEvents::SwipeRight:
            questionIndex -= 1;
            updateQuestion();
            return true;
        // We don't want to go back if we swipe up
        case TouchEvents::SwipeUp:
            deepLevel += 1;
            updateQuestion();
            return true;
        case TouchEvents::SwipeDown:
            deepLevel -= 1;
            updateQuestion();
            return true;
        default: return false;
    }
    return false;
}

std::string DateAid::insertLines(std::string str, uint16_t spaces) {
    // Offset is how many total chars we have up until the last \n
    uint16_t offset = 0;
    // Iterate through the string
    for(uint16_t i = 0; str[i]; i++) {
        // If there's no more room on the current line
        if(i >= spaces + offset) {
            // Loop until the previous space
            while(str[i] and str[i] != ' ' and i > 0)
                i--;
            str[i] = '\n';
            offset += i;
        }
    }
    return str;
}

int16_t DateAid::questionCount(uint8_t level) {
    switch(level) {
        case 0: return QUESTION_COUNT_0; break;
        case 1: return QUESTION_COUNT_1; break;
        case 2: return QUESTION_COUNT_2; break;
        case 3: return QUESTION_COUNT_3; break;
        default: return level;
    }
}

void DateAid::updateQuestion() {
    // Loop if the index is out of bounds
    if(questionIndex < 0)
        questionIndex = questionCount(deepLevel);
    if(questionIndex >= questionCount(deepLevel))
        questionIndex = 0;

    // Don't loop if out of bounds
    if(deepLevel < 0)
        deepLevel = 0;
    if(deepLevel >= DEEP_LEVELS)
        deepLevel = DEEP_LEVELS - 1;

    // Update deep level label
    lv_label_set_text(deepLabel, levelLabels[deepLevel]);
    lv_label_set_align(deepLabel, LV_LABEL_ALIGN_LEFT);
    lv_obj_align(deepLabel, lv_scr_act(), LV_ALIGN_IN_TOP_MID, 0, 0);

    // Update question
    lv_label_set_text(lineLabel, insertLines(getQuestion(deepLevel, questionIndex), CHARS_PER_LINE).c_str());
    lv_label_set_align(lineLabel, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(lineLabel, lv_scr_act(), LV_ALIGN_CENTER, 0, 0);
}

#include <cstdlib>
#include <cstring>

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
