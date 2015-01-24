/******************************************************************************
 **
 ** Object.hpp
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

#ifndef __Insanity__Object__
#define __Insanity__Object__

#include "Types.hpp"
#include "View.hpp"

namespace model {
  template<typename T>
  class Object {
  private:
    Time time;
    T value;
  public:
    Object() {
      this->time = 0;
    }
    Object(Time time, T value) {
      this->time = time;
      this->value = value;
    }
    friend bool operator== (const Object& a, const Object& b) {return (a.time == b.time) && (a.value == b.value);}
    friend bool operator>  (const Object& a, const Object& b) {return (a.time >  b.time);}
    friend bool operator<  (const Object& a, const Object& b) {return (a.time <  b.time);}
    friend bool operator>= (const Object& a, const Object& b) {return (a.time >= b.time);}
    friend bool operator<= (const Object& a, const Object& b) {return (a.time <= b.time);}
    friend bool operator== (const Time& a, const Object& b) {return (a == b.time);}
    friend bool operator>  (const Time& a, const Object& b) {return (a >  b.time);}
    friend bool operator<  (const Time& a, const Object& b) {return (a <  b.time);}
    friend bool operator>= (const Time& a, const Object& b) {return (a >= b.time);}
    friend bool operator<= (const Time& a, const Object& b) {return (a <= b.time);}
    friend bool operator== (const Object& a, const Time& b) {return (a.time == b);}
    friend bool operator>  (const Object& a, const Time& b) {return (a.time >  b);}
    friend bool operator<  (const Object& a, const Time& b) {return (a.time <  b);}
    friend bool operator>= (const Object& a, const Time& b) {return (a.time >= b);}
    friend bool operator<= (const Object& a, const Time& b) {return (a.time <= b);}
  };
  
  template<>
  class Object<int> {
  private:
    Time time;
    int value;
  public:
    Object() {
      this->time = 0;
    }
    Object(Time time, int value) {
      this->time = time;
      this->value = value;
    }
    friend bool operator== (const Object& a, const Object& b) {return (a.time == b.time) && (a.value == b.value);}
    friend bool operator>  (const Object& a, const Object& b) {return (a.time >  b.time);}
    friend bool operator<  (const Object& a, const Object& b) {return (a.time <  b.time);}
    friend bool operator>= (const Object& a, const Object& b) {return (a.time >= b.time);}
    friend bool operator<= (const Object& a, const Object& b) {return (a.time <= b.time);}
    friend bool operator== (const Time& a, const Object& b) {return (a == b.time);}
    friend bool operator>  (const Time& a, const Object& b) {return (a >  b.time);}
    friend bool operator<  (const Time& a, const Object& b) {return (a <  b.time);}
    friend bool operator>= (const Time& a, const Object& b) {return (a >= b.time);}
    friend bool operator<= (const Time& a, const Object& b) {return (a <= b.time);}
    friend bool operator== (const Object& a, const Time& b) {return (a.time == b);}
    friend bool operator>  (const Object& a, const Time& b) {return (a.time >  b);}
    friend bool operator<  (const Object& a, const Time& b) {return (a.time <  b);}
    friend bool operator>= (const Object& a, const Time& b) {return (a.time >= b);}
    friend bool operator<= (const Object& a, const Time& b) {return (a.time <= b);}
  };
}

#endif /* defined(__Insanity__Object__) */
