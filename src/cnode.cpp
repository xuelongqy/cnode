#include "cnode.h"
#include "node.h"

// 启动node
int nodeStart(int argc, char *argv[]) {
    return node::Start(argc, argv);
}
