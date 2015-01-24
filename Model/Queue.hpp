/******************************************************************************
 **
 ** Queue.hpp
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

#ifndef __Insanity__Queue__
#define __Insanity__Queue__

#include <list>

#include "Types.hpp"
#include "Model/Object.hpp"

namespace model {
  template<typename T>
  class Queue {
  protected:
    std::list<Object<T>> list;
  public:
    Queue() {};
    Queue(const Queue<T>& rhs) {
      this->list = rhs.list;
    }
    void operator= (const Queue<T>& rhs) {
      this->list = rhs.list;
    }
    bool find(Object<T>& object) {
      typename std::list<Object<T>>::iterator iter;
      for(iter = list.begin(); iter != list.end(); ++iter) {
        if(*iter == object) {
          return true;
        }
      }
      return false;
    }
    void enqueue(Object<T>& object) {
      if(!this->find(object)) {
        list.push_back(object);
        list.sort([](const Object<T>& a, const Object<T>& b){
          return (a < b);
        });
      }
    }
    void enqueue(Queue<T>& queue) {
      typename std::list<Object<T>>::iterator iter;
      for(iter = list.begin(); iter != list.end(); ++iter) {
        this->enqueue(*iter);
      }
    }
    Object<T>& dequeue() {
      Object<T>& ret = * new Object<T>(list.front());
      list.pop_front();
      return ret;
    }
    Queue<T>& dequeue(Time time) {
      Queue<T>& ret = * new Queue<T>();
      while(time >= list.front()) {
        ret.enqueue(this->dequeue());
      }
      return ret;
    }
    void clear() {
      list.clear();
    }
    bool empty() {
      return list.empty();
    }
  };

  template<>
  class Queue<int> {
  protected:
    std::list<Object<int>> list;
  public:
    Queue() {};
    Queue(const Queue<int>& rhs) {
      this->list = rhs.list;
    }
    void operator= (const Queue<int>& rhs) {
      this->list = rhs.list;
    }
    bool find(Object<int>& object) {
      typename std::list<Object<int>>::iterator iter;
      for(iter = list.begin(); iter != list.end(); ++iter) {
        if(*iter == object) {
          return true;
        }
      }
      return false;
    }
    void enqueue(Object<int>& object) {
      if(!this->find(object)) {
        list.push_back(object);
        list.sort([](const Object<int>& a, const Object<int>& b){
          return (a < b);
        });
      }
    }
    void enqueue(Queue<int>& queue) {
      typename std::list<Object<int>>::iterator iter;
      for(iter = list.begin(); iter != list.end(); ++iter) {
        this->enqueue(*iter);
      }
    }
    Object<int>& dequeue() {
      Object<int>& ret = * new Object<int>(list.front());
      list.pop_front();
      return ret;
    }
    Queue<int>& dequeue(Time time) {
      Queue<int>& ret = * new Queue<int>();
      while(time >= list.front()) {
        ret.enqueue(this->dequeue());
      }
      return ret;
    }
    void clear() {
      list.clear();
    }
    bool empty() {
      return list.empty();
    }
  };
}

#endif /* defined(__Insanity__Queue__) */
