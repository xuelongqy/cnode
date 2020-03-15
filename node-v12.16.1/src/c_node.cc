#include "c_node.h"

#include <thread>

/**
 * Start node program
 * @param argc Argument count
 * @param argv Arguments
 * @return exit code (Temporarily useless)
 */
int nodeStart(int argc, char *argv[]) {
    std::thread([argc, argv] {
        node::Start(argc, argv);
    }).detach();
    return 0;
}

/**
 * Stop node program
 * @param env Node Environment
 * @return exit code (Temporarily useless)
 */
int nodeStop(node::Environment* env) {
    return node::Stop(env);
}
