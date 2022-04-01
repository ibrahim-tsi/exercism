#ifndef ROBOT_SIMULATOR_HPP
#define ROBOT_SIMULATOR_HPP

#include <utility>
#include <string_view>

namespace robot_simulator {

enum Bearing {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Robot {
    std::pair<int, int> position;
    Bearing bearing;

public:
    Robot();
    Robot(std::pair<int, int> position, Bearing bearing);

    const std::pair<int, int>& get_position() const;
    const Bearing& get_bearing() const;
    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(std::string_view sequence);
};

}  // namespace robot_simulator

#endif // ROBOT_SIMULATOR_HPP