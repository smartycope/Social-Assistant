#pragma once

#include "components/fs/FS.h"
#include "displayapp/screens/Screen.h"
#include <cstdint>
#include <lvgl/lvgl.h>
#include <string>

#define DEEP_LEVELS 4
#define QUESTION_COUNT_0 9
#define QUESTION_COUNT_1 41
#define QUESTION_COUNT_2 25
#define QUESTION_COUNT_3 4
#define MAX_QUESTIONS 128
#define MAX_QUESTION_SIZE 128
#define CHARS_PER_LINE 18
#define LINE_COUNT QUESTION_SIZE / CHARS_PER_LINE

// To build this:
// cmake ..
// -DARM_NONE_EABI_TOOLCHAIN_PATH=/home/leonard/Software/gcc-arm-none-eabi-10.3-2021.10
// -DNRF5_SDK_PATH=/home/leonard/Software/nRF5_SDK_15.3.0_59ac345 -DBUILD_DFU=1
// -DCMAKE_BUILD_TYPE=Release make -j5 pinetime-mcuboot-app

// To (attempt) to build infiniSim:
// clear && rm -rf build/* && cmake -S . -B build
// -DInfiniTime_DIR=../InfiniTimeMessy -DCMAKE_CXX_STANDARD=14
// -DCMAKE_CXX_COMPILER=gcc -DCMAKE_C_COMPILER=gcc
// -DCMAKE_CXX_FLAGS="-static-libstdc++ -static-libgcc" && cmake --build build
// -j5

namespace Pinetime {
namespace Applications {
namespace Screens {
class DateAid : public Screen {
public:
  DateAid(DisplayApp *app, Pinetime::Controllers::FS &fs);

  ~DateAid() override;
  bool OnTouchEvent(TouchEvents event) override;
  void updateFile();

private:
  // static char questions0[QUESTION_COUNT_0][45];
  // static char questions1[QUESTION_COUNT_1][MAX_QUESTION_SIZE];
  // static char questions2[QUESTION_COUNT_2][MAX_QUESTION_SIZE];
  // static char questions3[QUESTION_COUNT_3][MAX_QUESTION_SIZE];
  static const char levelLabels[DEEP_LEVELS][21];
  int8_t deepLevel = 0;
  int16_t questionIndex = 0;
  // lv_obj_t* questionLabels[QUESTION_COUNT];
  lv_obj_t *lineLabel;
  lv_obj_t *deepLabel;
  void updateQuestion();
  // static char** questions[DEEP_LEVELS];
  static int16_t questionCount(uint8_t level);
  std::string insertLines(std::string str, uint16_t spaces);
  std::string getQuestion(int8_t deepLevel, uint16_t index);
  std::string error = "Error";
  lfs_file_t *file;
};
} // namespace Screens
} // namespace Applications
} // namespace Pinetime