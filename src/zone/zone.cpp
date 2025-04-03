#include "zone.h"

Zone::Zone(int minX, int maxX, int minY, int maxY)
{
    setMinX(minX);
    setMaxX(maxX);
    setMinY(minY);
    setMaxY(maxY);
}
int Zone::getMinX() const
{
    return minX;
}
int Zone::getMaxX() const
{
    return maxX;
}
int Zone::getMinY() const
{
    return minY;
}
int Zone::getMaxY() const
{
    return maxY;
}

void Zone::setMinX(int value)
{
    minX = value;
}
void Zone::setMaxX(int value)
{
    maxX = value;
}
void Zone::setMinY(int value)
{
    minY = value;
}
void Zone::setMaxY(int value)
{
    maxY = value;
}
