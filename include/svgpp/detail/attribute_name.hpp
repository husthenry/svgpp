// Copyright Oleg Maximenko 2014.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//
// See http://github.com/svgpp/svgpp for library home page.

#pragma once

#include <svgpp/definitions.hpp>

namespace svgpp
{

template<class Char>
struct attribute_name;

template<>
struct attribute_name<char>
{
  template<class AttributeTag>
  inline static BOOST_CONSTEXPR const char * get();
};

#define SVGPP_ON_STYLE(name, string) SVGPP_ON(name, string)
#define SVGPP_ON(name, string) \
  template<> inline BOOST_CONSTEXPR const char * attribute_name<char>::get<tag::attribute::name>() \
  { return #string; }
#define SVGPP_ON_NS(ns, name, string) \
  template<> inline BOOST_CONSTEXPR const char * attribute_name<char>::get<tag::attribute::ns::name>() \
  { return #string; }

#include <svgpp/detail/dict/enumerate_all_attributes.inc>

#undef SVGPP_ON
#undef SVGPP_ON_NS
#undef SVGPP_ON_STYLE

}