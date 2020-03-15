#include "c_node.h"
#include "node.h"
#include <thread>

// 启动node
void nodeStart(int argc, char *argv[]) {
    std::thread([argc, argv] {
        node::Start(argc, argv);
    }).detach();
}
