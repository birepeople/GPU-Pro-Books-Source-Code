////////////////////////////////////////////////////////////////////////////////
// The Loki Library
// Copyright (c) 2001 by Andrei Alexandrescu
// This code accompanies the book:
// Alexandrescu, Andrei. "Modern C++ Design: Generic Programming and Design 
//     Patterns Applied". Copyright (c) 2001. Addison-Wesley.
// Permission to use, copy, modify, distribute and sell this software for any 
//     purpose is hereby granted without fee, provided that the above copyright 
//     notice appear in all copies and that both that copyright notice and this 
//     permission notice appear in supporting documentation.
// The author or Addison-Wesley Longman make no representations about the 
//     suitability of this software for any purpose. It is provided "as is" 
//     without express or implied warranty.
////////////////////////////////////////////////////////////////////////////////

// Last update: June 20, 2001

#ifndef __STATIC_CHECK_INC__
#define __STATIC_CHECK_INC__


////////////////////////////////////////////////////////////////////////////////
// Helper structure for the STATIC_CHECK macro
////////////////////////////////////////////////////////////////////////////////

template<int> struct CompileTimeError;
template<> struct CompileTimeError<true> {};


////////////////////////////////////////////////////////////////////////////////
// macro STATIC_CHECK
// Invocation: STATIC_CHECK(expr, id)
// where:
// expr is a compile-time integral or pointer expression
// id is a C++ identifier that does not need to be defined
// If expr is zero, id will appear in a compile-time error message.
////////////////////////////////////////////////////////////////////////////////

//#define STATIC_CHECK(expr, msg) \
//    { CompileTimeError<((expr) != 0)> ERROR_##msg; (void)ERROR_##msg; } 

#define STATIC_CHECK(expr) \
    { CompileTimeError<((expr) != 0)> inst; (void)inst; } 


////////////////////////////////////////////////////////////////////////////////
// Change log:
// March 20, 2001: add extra parens to STATIC_CHECK - it looked like a fun 
//     definition
// June 20, 2001: ported by Nick Thurn to gcc 2.95.3. Kudos, Nick!!!
////////////////////////////////////////////////////////////////////////////////

#endif // STATIC_CHECK_INC_
