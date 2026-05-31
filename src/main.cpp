// Copyright 2022 NNTU-CS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "train.h"

int main() {
  static unsigned int seed = static_cast<unsigned int>(time(nullptr));
  int count = 60;
  for (int n = 2; n <= count; n++) {
    Train trainOff;
    int n1 = n;
    while (n1--)
      trainOff.addCar(false);
    trainOff.getLength();

    Train trainOn;
    n1 = n;
    while (n1--)
      trainOn.addCar(true);
    trainOn.getLength();

    Train trainRandom;
    n1 = n;
    while (n1--)
      trainRandom.addCar(rand_r(&seed) % 2);
    trainRandom.getLength();

    std::cout << "кол-во вагонов = " << n
              << " выкл = " << trainOff.getOpCount()
              << " вкл = " << trainOn.getOpCount()
              << " рандом = " << trainRandom.getOpCount()
              << std::endl;
  }
  return 0;
}
