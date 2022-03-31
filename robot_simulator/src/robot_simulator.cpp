#include "robot_simulator.hpp"

const int bearing_count = 4;

int mod(int n, int m) {
  return ((n % m) + m) % m;
}

namespace robot_simulator {

Robot::Robot() : position({0, 0}), bearing(NORTH) {}

Robot::Robot(std::pair<int, int> position, Bearing bearing) {
    this->position = position;
    this->bearing = bearing;
}

const std::pair<int, int>& Robot::get_position() const {
    return position;
}

const Bearing& Robot::get_bearing() const {
    return bearing;
}

void Robot::turn_right() {
    bearing = Bearing(mod(bearing + 1, bearing_count));
}

void Robot::turn_left() {
    bearing = Bearing(mod(bearing - 1, bearing_count));
}

void Robot::advance() {
    switch (bearing) {
        case NORTH:
            position.second += 1;
            
            break;

        case SOUTH:
            position.second -= 1;
            
            break;

        case EAST:
            position.first += 1;
            
            break;

        case WEST:
            position.first -= 1;
            
            break;
    }
}

void Robot::execute_sequence(std::string_view sequence) {
    for (const char& ch: sequence) {
        switch (ch) {
            case 'R':
                turn_right();
                
                break;

            case 'L':
                turn_left();
                
                break;

            case 'A':
                advance();
            
                break;
        }
    }
}

}  // namespace robot_simulator
