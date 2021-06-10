#include <jni.h>
#include <string>

#include "Engine/Game.hpp"

extern "C" JNIEXPORT jstring JNICALL
Java_com_zippyzen_kotlin_1test_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    Game game = Game();
//    game.run();
    std::string hello = "Hello Barsoom World 4!!";
    return env->NewStringUTF(hello.c_str());
}