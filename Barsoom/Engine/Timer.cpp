#include "Timer.hpp"

Timer::Timer() {
    mStartTicks = 0;
    mPausedTicks = 0;
    mPaused = false;
    mStarted = false;
}

void Timer::start() {
    mStarted = true;
    mPaused = false;
    mStartTicks = SDL_GetTicks();
    mPausedTicks = 0;
}

void Timer::stop() {
    mStarted = false;
    mPaused = false;
    mStartTicks = 0;
    mPausedTicks = 0;
}

void Timer::pause() {
    if (mStarted && !mPaused) {
        mPaused = true;

        mPausedTicks = SDL_GetTicks() - mStartTicks;
        mStartTicks = 0;
    }
}

void Timer::unpause() {
    if (mStarted && mPaused) {
        mPaused = false;
        mStartTicks = SDL_GetTicks() - mPausedTicks;
        mPausedTicks = 0;
    }
}

Uint32 Timer::getTicks() {
    //The actual timer time
    Uint32 time = 0;

    //If the timer is running
    if (mStarted) {
        //If the timer is paused
        if (mPaused) {
            //Return the number of ticks when the timer was paused
            time = mPausedTicks;
        } else {
            //Return the current time minus the start time
            time = SDL_GetTicks() - mStartTicks;
        }
    }

    return time;
}

bool Timer::isStarted() {
    return mStarted;
}

bool Timer::isPaused() {
    //Timer is running and paused
    return mPaused && mStarted;
}
