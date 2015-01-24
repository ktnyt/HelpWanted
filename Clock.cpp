/******************************************************************************
 **
 ** Clock.cpp
 ** Insanity
 **
 ** Created by kotone on 2015/01/25.
 ** Copyright (c) 2015 Kotone Itaya. All rights reserved.
 **
 ** This file is part of Insanity.
 **
 ** Insanity is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 **
 ** Insanity is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **
 ** You should have received a copy of the GNU General Public License
 ** along with Insanity.  If not, see <http://www.gnu.org/licenses/>.
 **
 *****************************************************************************/

#include "Clock.hpp"

namespace model {
  Clock::Clock() {
    time = 0;
    frame = 0;
    fps = 58;
    prev = std::chrono::steady_clock::now();
  }

  Frame Clock::nanoToFrame(Time time) {
    return ((time * fps) / 1000000000);
  }
  
  bool Clock::pollFrame() {
    curr = std::chrono::steady_clock::now();
    std::chrono::nanoseconds duration = (curr - prev);
    time = duration.count() / 1000000;
    Frame now = nanoToFrame(duration.count());
    if(now > frame) {
      frame++;
      while(now > frame) {
        std::cerr << "Clock: Dropped frame " << frame << std::endl;
        frame++;
      }
      return true;
    }
    return false;
  }
  
  void Clock::reset() {
    time = 0;
    frame = 0;
    prev = std::chrono::steady_clock::now();
  }
}