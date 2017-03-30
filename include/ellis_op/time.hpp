/*
 * Copyright (c) 2016 Surround.IO Corporation. All Rights Reserved.
 * Copyright (c) 2017 Xevo Inc. All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


/**
 * @file ellis_op/time.hpp
 *
 * @brief Ellis Op Time Definitions
 *
 * This file defines some structures etc for working with time. 
 */

#pragma once
#ifndef ELLIS_OP_TIME_HPP_
#define ELLIS_OP_TIME_HPP_

#include <stdint.h>


namespace ellis_op {


/**
 * Time representation.
 *
 * Hopefully reduces misunderstandings and conversion accidents?
 * TODO: separate absolute and delta representations?
 */
struct timeval {
  int64_t m_nanos_since_epoch;
  explicit operator int64_t() const {
    return m_nanos_since_epoch;
  }
  timeval & operator=(const timeval &o) {
    m_nanos_since_epoch = o.m_nanos_since_epoch;
    return *this;
  }
  bool operator==(const timeval &o) {
    return m_nanos_since_epoch == o.m_nanos_since_epoch;
  }
  bool operator!=(const timeval &o) {
    return m_nanos_since_epoch != o.m_nanos_since_epoch;
  }
  bool operator>=(const timeval &o) {
    return m_nanos_since_epoch >= o.m_nanos_since_epoch;
  }
  bool operator<=(const timeval &o) {
    return m_nanos_since_epoch <= o.m_nanos_since_epoch;
  }
  bool operator<(const timeval &o) {
    return m_nanos_since_epoch < o.m_nanos_since_epoch;
  }
  bool operator>(const timeval &o) {
    return m_nanos_since_epoch > o.m_nanos_since_epoch;
  }
};


/**
 * Add two times together.
 *
 * Since timeval says specifically "since epoch" then this probably should
 * be removed rather than used for deltas.  TODO: investigate and fix.
 */
static inline timeval operator+(const timeval &a, const timeval &b)
{
  return { a.m_nanos_since_epoch + b.m_nanos_since_epoch };
}


/**
 * Subtract one time from another.
 *
 * Since this represents a delta, it should probably be a different return
 * type than timeval.
 */
static inline timeval operator-(const timeval &a, const timeval &b)
{
  return { a.m_nanos_since_epoch - b.m_nanos_since_epoch };
}


/**
 * Return a high-resolution representation of the current time.
 */
timeval now();


}  /* namespace ellis_op */


#endif  /* ELLIS_OP_TIME_HPP_ */
