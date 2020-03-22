#include "c_node.h"

#include <thread>

#include "env-inl.h"

int nodeStart(int argc, char *argv[], InitNode initNode) {
    return node::Start(argc, argv, initNode);
}

int nodeStartThread(int argc, char *argv[], InitNode initNode) {
    std::thread([argc, argv, initNode] {
        node::Start(argc, argv, initNode);
    }).detach();
    return 0;
}

int nodeStop(node::Environment* env) {
    return node::Stop(env);;
}