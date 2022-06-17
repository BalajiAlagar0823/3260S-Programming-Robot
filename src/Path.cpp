#include "headers/Path.hpp"

void genPath1() {
  profileController->generatePath({{0_in, 0_in, 0_deg}, {10_in, 5_in, 0_deg}}, "A");

  profileController->generatePath({{0_in, 0_in, 0_deg}, {2_in, 3_in, 90_deg}}, "B");

  profileController->setTarget("A");
  profileController->waitUntilSettled();
  profileController->setTarget("B");
  profileController->waitUntilSettled();
}
