#include "c_node.h"

#include <thread>

/**
 * Start node program
 * @param argc Argument count
 * @param argv Arguments
 * @param id Node program identification
 * @param onStartNode Before the node program starts
 * @return exit code (Temporarily useless)
 */
int nodeStart(int argc, char *argv[], int id, OnStartNode onStartNode) {
    std::thread([argc, argv, id, onStartNode] {
        node::C_Node_Start(argc, argv, id, onStartNode);
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
