/******************************************************************************
 **
 ** TestProcess.hpp
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

#ifndef __Insanity__TestProcess__
#define __Insanity__TestProcess__

#include "Model/Process.hpp"
#include "Model/TestQueue.hpp"

namespace model {
  class TestProcess : public Process<int> {
  private:
    TestQueue queue;
    TestQueue work;
  public:
    TestProcess(TestQueue queue);
    void update(Time time);
    TestQueue collect();
    bool done();
  };
}

#endif /* defined(__Insanity__TestProcess__) */
