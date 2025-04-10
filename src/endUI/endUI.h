#ifndef ENDUI_H
#define ENDUI_H
#include "../func/func.h"
#include <string>
#include <vector>
#include <atomic>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>

extern std::atomic<bool> keepRunning;
extern const std::vector<std::string> stars;
extern const std::vector<int> starColors;

void animateStars(int startRow);
void waitForEnter();
void showGameOverScreen(const std::string& winner);

#endif
