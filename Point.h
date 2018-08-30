struct Point;

Point *Point__create(int x, int y);

void Point__destroy(Point *self);

int *Point__x(Point *self);

int *Point__y(Point *self);