//
// Created by Latandu on 14/04/2023.
//

#ifndef FIRSTPROJECT_POINT_H
#define FIRSTPROJECT_POINT_H


class Point {
protected:
    int x = 0, y = 0;
public:
    Point() = default;

    int getX() const;

    int getY() const;

    void setX(int x);

    void setY(int y);
};



#endif //FIRSTPROJECT_POINT_H
