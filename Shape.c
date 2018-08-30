struct Shape
{
	ShapeType *type;
	char buffer_start;
};

struct ShapeType
{
	int buffer_size;
	const char* (*name) (Shape *self);
	int (*sides) (Shape *self);
	void (*destroy) (Shape *shape);
};

ShapeType *ShapeType__create(
	int buffer_size,
	const char* (*name) (Shape *self),
	int (*sides) (Shape *self),
	void (*destroy) (Shape *shape))
{
	ShapeType *result = malloc(sizeof(ShapeType));
	result->buffer_size = buffer_size;
	result->name = name;
	result->sides = sides;
	result->destroy = destroy;

	return result;
}

Shape *Shape__create(ShapeType *type)
{
	int size = sizeof(Shape) + type->buffer_size;
	Shape *result = malloc(size);
	result->type = (*Shape) type;

	return result;
}

ShapeType *Shape__type(Shape *self)
{
	return self->type;
}

void *Shape__buffer(Shape* self) {
   return (void*) &(self->buffer_start);
}

int Shape__sides(Shape *self)
{
	return self->type->sides(self);
}

void Shape__destroy(Shape *shape)
{
	if (shape)
	{
		shape->type->destroy(shape);
	}
}
