//          Copyright Oliver Kowalke 2009.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_FIBERS_ALGORITHM_H
#define BOOST_FIBERS_ALGORITHM_H

#include <boost/assert.hpp>
#include <boost/chrono/system_clocks.hpp>
#include <boost/config.hpp>
#include <boost/utility.hpp>

#include <boost/fiber/detail/config.hpp>
#include <boost/fiber/fiber.hpp>

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_PREFIX
#endif

# if defined(BOOST_MSVC)
# pragma warning(push)
# pragma warning(disable:4251 4275)
# endif

namespace boost {
namespace fibers {

struct BOOST_FIBERS_DECL algorithm : private noncopyable
{
    virtual void spawn( detail::fiber_base::ptr_t const&) = 0;

    virtual void join( detail::fiber_base::ptr_t const&) = 0;

    virtual void cancel( detail::fiber_base::ptr_t const&) = 0;

    virtual void notify( detail::fiber_base::ptr_t const&) = 0;

    virtual detail::fiber_base::ptr_t active() = 0;

    virtual void sleep( chrono::system_clock::time_point const& abs_time) = 0;

    virtual bool run() = 0;

    virtual void wait() = 0;

    virtual void yield() = 0;

    virtual void migrate( detail::fiber_base::ptr_t const&) = 0;

    virtual ~algorithm() {}
};

}}

# if defined(BOOST_MSVC)
# pragma warning(pop)
# endif

#ifdef BOOST_HAS_ABI_HEADERS
#  include BOOST_ABI_SUFFIX
#endif

#endif // BOOST_FIBERS_ALGORITHM_H