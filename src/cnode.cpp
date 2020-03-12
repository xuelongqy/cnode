#include "cnode.hpp"
#include <node/node.h>

// 启动node
int nodeStart(int argc, char *argv[]) {
    return node::Start(argc, argv);
}