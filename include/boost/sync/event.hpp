// event.hpp
//
// Copyright (C) 2013 Tim Blechmann
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_SYNC_EVENT_HPP
#define BOOST_SYNC_EVENT_HPP

#ifdef BOOST_SYNC_DETAIL_DOXYGEN

class event
{

public:
    /**
     * \b Effects: Constructs an event object. If `auto_reset` is true, waiting for an even will automatically reset it.
     *
     * \b Throws: if an error occurs.
     */
    event(bool auto_reset = false);

    /**
     * \b Effects: Destroys the event object.
     *
     * \b Precondition: No thread waits on this event.
     *
     * \b Throws: if an error occurs.
     */
    ~event();

    /**
     * \b Effects: Signals the event object: the event is set and waiting threads will be woken up.
     *
     * \b Precondition: No thread waits on this event.
     *
     * \b Throws: if an error occurs.
     */
    void post();

    /**
     * \b Effects: Waits for the event to be signaled. If the event is created as `auto_reset`, it will unset the `signaled` state
     *
     * \b Precondition: No thread waits on this event.
     *
     * \b Throws: if an error occurs.
     */
    void wait();

    /**
     * \b Effects: Resets the event to the  unsignaled  state.
     *
     * \b Throws: if an error occurs.
     */
    void reset();

    /**
     * \b Effects: Waits for the event to be signaled. If the event is created as `auto_reset`, it will unset the `signaled` state
     *
     * \b Returns: True if the event had been signaled, False, if the call would be blocking or the event has not been signaled.
     *
     * \b Throws: if an error occurs.
     */
    bool try_wait();

    /**
     * \b Effects: Waits for the event to be signaled. If the event is created as `auto_reset`, it will unset the `signaled` state
     *
     * \b Returns: True if the event had been signaled, False, if the call would be blocking or the event has not been signaled.
     *
     * \b Throws: if an error occurs.
     */
    template <typename Duration>
    bool try_wait_for(const Duration & duration);

    /**
     * \b Effects: Waits for the event to be signaled. If the event is created as `auto_reset`, it will unset the `signaled` state
     *
     * \b Returns: True if the event had been signaled, False, if the call would be blocking or the event has not been signaled.
     *
     * \b Throws: if an error occurs.
     */
    template <typename TimePoint>
    bool try_wait_until(const TimePoint & timeout);
};

#else // BOOST_SYNC_DETAIL_DOXYGEN

#include <boost/sync/detail/config.hpp>

#ifdef BOOST_HAS_PRAGMA_ONCE
#pragma once
#endif

#include <boost/sync/detail/header.hpp>


#if defined(BOOST_SYNC_DETAIL_PLATFORM_WINAPI)
#include <boost/sync/detail/windows/event.hpp>

//#elif defined(BOOST_SYNC_POSIX_SEMAPHORES)
//#include <boost/sync/semaphore/semaphore_posix.hpp>

//#elif defined(BOOST_SYNC_DISPATCH_SEMAPHORES)
//#include <boost/sync/semaphore/semaphore_dispatch.hpp>

#else

#include <boost/sync/detail/generic/event_cv_emulation.hpp>

#endif

#include <boost/sync/detail/footer.hpp>

#endif // BOOST_SYNC_DETAIL_DOXYGEN

#endif // BOOST_SYNC_EVENT_HPP