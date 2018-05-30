#include <jni.h>
#include <dlfcn.h>
#include <stdlib.h>
#include "Substrate.h"
#include <string>

struct MinecraftGame {
    bool useMinecraftVersionOfXBLUI() const;
};

bool (*_MinecraftGame$useMinecraftVersionOfXBLUI)();
bool MinecraftGame$useMinecraftVersionOfXBLUI() {
    return true;
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	MSHookFunction((void*) &MinecraftGame::useMinecraftVersionOfXBLUI, (void*) &MinecraftGame$useMinecraftVersionOfXBLUI, (void**) &_MinecraftGame$useMinecraftVersionOfXBLUI);
	return JNI_VERSION_1_2;
}

