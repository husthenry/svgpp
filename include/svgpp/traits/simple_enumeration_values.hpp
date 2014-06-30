#pragma once

#include <svgpp/definitions.hpp>
#include <boost/mpl/vector.hpp>
#include <boost/mpl/pair.hpp>
#include <boost/preprocessor.hpp>

namespace svgpp { namespace traits
{

  template<class AttributeTag>
  struct simple_enumeration_values;

#define SVGPP_ON_ATTR(name, values) \
  template<> struct simple_enumeration_values<tag::attribute::name> { \
    typedef boost::mpl::vector<SVGPP_ON_VALUES(values)> type; \
  };
#define SVGPP_ON_ATTR_NS(ns, name, values) SVGPP_ON_ATTR(ns::name, values)
#define SVGPP_ON_ELEM_ATTR(elem, attr, values) \
  template<> struct simple_enumeration_values<boost::mpl::pair<tag::element::elem, tag::attribute::attr> > { \
    typedef boost::mpl::vector<SVGPP_ON_VALUES(values)> type; \
  };
#define SVGPP_ON_VALUES(values) BOOST_PP_SEQ_FOR_EACH_I(SVGPP_ON_VALUE, _, values)
#define SVGPP_ON_VALUE(r, _, i, value_tag) BOOST_PP_COMMA_IF(i) tag::value::value_tag  
#include <svgpp/detail/dict/enumerate_simple_enumeration_attributes.inc>
#undef SVGPP_ON_ATTR
#undef SVGPP_ON_ATTR_NS
#undef SVGPP_ON_ELEM_ATTR
#undef SVGPP_ON_VALUES
#undef SVGPP_ON_VALUE
}

}