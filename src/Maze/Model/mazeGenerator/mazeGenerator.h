#ifndef MODEL_MAZE_GENERATOR_
#define MODEL_MAZE_GENERATOR_

#include <fstream>

class MazeGenerator{
public:
    RowsAndColumns Generate(std::ofstream& file, int cols){

        RowsAndColumns maze;
        // file << "i am a test and i have " << cols;

        file << "4 4" << std::endl;

        file << "1 0 1 0" << std::endl;
        file << "1 0 1 0" << std::endl;
        file << "1 0 1 0" << std::endl;
        file << "1 0 1 0" << std::endl;

        file << "1 0 1 0" << std::endl;
        file << "1 0 1 0" << std::endl;
        file << "1 0 1 0" << std::endl;
        file << "1 0 1 0" << std::endl;
        // file << cols ;

        return maze;
    }
private:


};

#endif // MODEL_MAZE_GENERATOR_