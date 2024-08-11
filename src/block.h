#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block
{
private:
    int cellSize;
    int rotationState;
    std::vector<Color> colors;
    int rowOffset;
    int columnOffset;

public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Rotate();
    void UndoRotation();
    void Move(int rows, int columns);
    std::vector<Position> GetCellPositions();
    std::map<int, std::vector<Position>> cells;
    int id;
};