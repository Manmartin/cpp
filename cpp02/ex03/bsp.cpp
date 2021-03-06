#include <Point.hpp>

/*
** Explanation
** v1 = AB = (v1.x, v1.y, v1.z = 0) = (B.x - A.x, B.y - A.y, B.z - A.z = 0)
** v2 = AP = (v2.x, v2.y, v2.z = 0) = (P.x - A.x, P.y - A.y, P.z - A.z = 0)
** v1 X v2 = (v1.y*v2.z - v1.z*v2.y = 0, v1.x*v2.z - v1.z*v2.x = 0, v1.x*v2.y - v1.y*v2.x)
*/

static float  get_direction(Point P, Point A, Point B) {
    Point v1 = B - A;
    Point v2 = P - A;
    Fixed value =  v1.getX() * v2.getY() - v1.getY() * v2.getX();
    return value.toFloat();
}

bool    bsp( Point const a, Point const b, Point const c, Point const point) {
    float   direction1, direction2, direction3;

    direction1 = get_direction(point, a, b);
    direction2 = get_direction(point, b, c);
    direction3 = get_direction(point, c, a);
    return  (direction1 > 0 && direction2 > 0 && direction3 > 0) || (direction1 < 0 && direction2 < 0 && direction3 < 0);
}
