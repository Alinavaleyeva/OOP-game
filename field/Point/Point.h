#ifndef point_h
#define point_h

class Point {
private:
    int x, y;

public:
    Point();
    Point(int x_val, int y_val);

    int get_x() const;
    int get_y() const;

    void set_x(int x);
    void set_y(int y);
};
#endif
