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


/*
 * @file ellis_op/call_trace.hpp
 *
 * @brief Ellis Op Call Tracing Definitions
 *
 * This file defines various entities needed for representing call traces.
 */

#pragma once
#ifndef ELLIS_OP_CALL_TRACE_HPP_
#define ELLIS_OP_CALL_TRACE_HPP_

#include <ellis/core/system.hpp>
#include <ellis_op/time.hpp>


namespace ellis_op {


/**
 * An element in a call execution trace.
 */
struct trace_entry {
  timeval m_time;
  std::string m_stage;
};


/**
 * Timing/tracing info for a single call.
 */
struct call_telemetry {
  timeval m_start_time;
  int64_t m_total_nanos = 0;
  bool m_is_tracing = false;
  std::vector<trace_entry> m_traces;
};


/**
 * Macro for execution tracing.
 *
 * We use a macro here, so that if tracing is not enabled, the cost is
 * minimized.
 *
 * Similar to regular logging, but takes a "stage" parameter, which must be a
 * simple character string constant (not a C++ string), and can be used for
 * building timing charts.
 */
#define ELLIS_OP_TRACE(REQ, TELEM, STAGE) \
  do { \
    if ((TELEM)->m_is_tracing) { \
      (TELEM)->m_traces.push_back({ now(), STAGE }); \
    } \
    ELLIS_LOG(DBUG, "%s: stage -> %s", \
        get_debugid(*(REQ)).c_str(), STAGE); \
  } while (0)


}  /* namespace ellis_op */


#endif  /* ELLIS_OP_CALL_TRACE_HPP_ */
