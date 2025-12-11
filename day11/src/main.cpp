#include <cstdio>
#include <fstream>
#include <sstream>
#include <iostream>
#include <sys/types.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

typedef struct s_node {
    std::vector<std::string> connected;
    std::string name;
} Node;

typedef std::vector<Node>::iterator NIter;
typedef std::vector<std::string>::iterator SIter;

int count_out(Node node, std::map<std::string, Node> map) {
    int count = 0;
    for (SIter it = node.connected.begin(); it != node.connected.end(); it++) {
        if (*it == "out") {
            count += 1;
        }
        else {
            count += count_out(map[*it], map);
        }
    }
    return count;
}

int count_out(Node node, std::map<std::string, Node> map, std::set<std::string> chain) {
    int count = 0;


    if (chain.find(node.name) != chain.end()) {
        return 0;
    }

    for (SIter it = node.connected.begin(); it != node.connected.end(); it++) {
        if (*it == "out"
            && chain.find("dac") != chain.end()
            && chain.find("fft") != chain.end()) {
            std::cout << "here" << std::endl;
            count += 1;
        }
        else {
            chain.insert(node.name);
            count += count_out(map[*it], map, chain);
        }
    }
    return count;
}

int main ( int ac, char **av ) {

    if (ac != 2) {

        std::cerr << "Usage: ./day11 <puzzle-input>" << std::endl;
        return 1;
    }
    std::fstream input(av[1]);
    if (!input.good()) {
        std::cerr << "Could not open file: " << av[1] << std::endl;
        return 1;
    }

    std::string buffer;
    std::vector<Node> nodes;
    while(std::getline(input, buffer)) {
        std::stringstream ss(buffer);
        std::string name;
        std::getline(ss, name, ' ');
        name.pop_back();
        Node node;
        node.name = name;
        std::string tmp;
        while(std::getline(ss, tmp, ' ')) {
            node.connected.push_back(tmp);
        }
        nodes.push_back(node);
    }

    std::map<std::string, Node> map;
    for (NIter it = nodes.begin(); it != nodes.end(); it++) {
        map[(*it).name] = *it;
    }

    /*
    Node init1 = map["you"];
    int res1 = count_out(init1, map);
    std::cout << "\e[1m" << res1 << "\e[0m paths lead from \"you\" to \"out\"" << std::endl;
    */

    std::set<std::string> chain;
    int res2 = count_out(map["svr"], map, chain);
    std::cout << "\e[1m" << res2 << "\e[0m paths lead from \"you\" to \"out\"" << std::endl;
}
