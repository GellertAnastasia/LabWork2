#ifndef ZONE_H
#define ZONE_H

class Zone {
private:
    int minX, maxX, minY, maxY;

public:
    Zone() = default; 
    Zone(int minX, int maxX, int minY, int maxY); 
    Zone(const Zone&) = default; 
    int getMinX() const;
    int getMaxX() const;
    int getMinY() const;
    int getMaxY() const;

    void setMinX(int value);
    void setMaxX(int value);
    void setMinY(int value);
    void setMaxY(int value);
};
#endif
