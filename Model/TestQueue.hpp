/******************************************************************************
 **
 ** TestQueue.hpp
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

#ifndef __Insanity__TestQueue__
#define __Insanity__TestQueue__

#include "Model/Queue.hpp"
#include "Model/TestObject.hpp"

namespace model {
  class TestQueue : public Queue<int> {
  public:
    TestQueue();
  };
}

#endif /* defined(__Insanity__TestQueue__) */
