#ifndef GRID_H
#define GRID_H

#include "stdafx.h"

template <typename T>
class Grid
{
public:

	Grid(int width_ = 0, int height_ = 0) : width(width_), height(height_) 
	{
		grid = new T * [height_]();
		for (int i = 0; i < height_; i++)
			grid[i] = new T[width_]();
	}

	~Grid()
	{
		shutdown();
	}

	void shutdown()
	{
		for (int i = 0; i < getHeight(); i++)
			delete[] grid[i];
			
		SAFE_DELETE_ARRAY(grid);
	}

	void resize(int newWidth_ = width, int newHeight_ = height)
	{
		if (getHeight() == 0 || getWidth() == 0)
			return;

		T** tempGrid = grid;

		grid = new T * [newHeight_]();
		for (int i = 0; i < newHeight_; i++)
			grid[i] = new T[newWidth_]();

		int h = newHeight_;
		int w = newWidth_;

		if (newHeight_ > getHeight())
			h = getHeight();
		if (newWidth_ > getWidth())
			w = getWidth();

		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				at(x, y) = tempGrid[y][x];

		for (int i = 0; i < getHeight(); i++)
			delete[] tempGrid[i];
		SAFE_DELETE_ARRAY(tempGrid);

		width = newWidth_;
		height = newHeight_;
	}

	void clear()
	{
		for (int y = 0; y < getHeight(); y++)
			for (int x = 0; x < getWidth(); x++)
				at(x, y) = nullptr;
	}

	void insert(int x, int y, T c)
	{
		grid[y][x] = c;
	}

	T at(int x, int y)
	{
		return grid[y][x];
	}

	void assign(int x, int y, T a)
	{
		grid[y][x] = a;
	}

	void addRow(T* row)
	{
		resize(getWidth(), getHeight() + 1);

		for (int i = 0; i < getWidth(); i++)
		{
			at(i, getHeight() - 1) = row[i];
		}
	}

	T* getRow(int y)
	{
		if (y >= getWidth())
			return nullptr;

		T* row = new T[getWidth()]();

		for (int i = 0; i < getWidth(); i++)
			row[i] = at(i, getHeight() - 1);

		return row;
	}

	T* removeRow()
	{
		if (getHeight() == 0)
			return nullptr;

		T* row = new T[getWidth()]();

		for (int i = 0; i < getWidth(); i++)
			row[i] = at(i, getHeight() - 1);

		resize(getWidth(), getHeight() - 1);

		return row;
	}

	void addColumn(T* column)
	{
		resize(getWidth() + 1, getHeight());
		for (int i = 0; i < getHeight(); i++)
		{
			grid[i][getWidth() - 1] = column[i];
		}
	}

	T* getColumn(int x)
	{
		if (x >= getWidth())
			return nullptr;

		T* column = new T[getHeight()]();

		for (int i = 0; i < getHeight(); i++)
			column[i] = grid[i][x];

		return column;
	}

	T* removeColumn()
	{
		if (getWidth() == 0)
			return nullptr;

		T* column = new T[getHeight()]();
		for (int i = 0; i < getHeight(); i++)
		{
			column[i] = grid[i][getWidth() - 1];
		}

		resize(getWidth() - 1, getHeight());

		return column;
	}

	T* getLine(int x1, int x2, int y1, int y2)
	{
		T* line = new T[1]();

		// Swap first and second if second < first
		if (x2 < x1)
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}

		if (y2 < y1)
		{
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}

		// Check if line is horizontal or vertical
		if (x1 == x2) {
			// Vertical line
			// Get starting and ending if not within bounds
			if (x1 > getWidth() - 1 || x1 < 0)
				return nullptr;
			if (y1 < 0) y1 = 0;
			if (y2 > getHeight()) y2 = getHeight();

			line = new T[y2 - y1]();

			for (int i = 0; i < (y2 - y1); i++)
			{
				line[i] = grid[i + y1][x1];
			}
		}
		else if (y1 == y2) {
			// Horizontal line
			// Get starting and ending if not within bounds
			if (y1 > getHeight() - 1 || y1 < 0)
				return nullptr;
			if (x1 < 0) x1 = 0;
			if (x2 > getWidth()) x2 = getWidth();

			line = new T[x2 - x1]();

			for (int i = 0; i < (x2 - x1); i++)
			{
				line[i] = grid[y1][i + x1];
			}
		}

		return line;
	}
	
	T** getQuad(int x1, int x2, int y1, int y2)
	{
		// Swap first and second if second < first
		if (x2 < x1)
		{
			int temp = x1;
			x1 = x2;
			x2 = temp;
		}

		if (y2 < y1)
		{
			int temp = y1;
			y1 = y2;
			y2 = temp;
		}

		T** quad = new T * [(y2 - y1)]();

		for (int i = 0; i < (y2 - y1); i++)
		{
			quad[i] = getLine(x1, x2, i + y1, i + y1);
		}

		return quad;
	}

	T* getRadius(int x, int y, int r)
	{
		int size = 0;
		for (int i = 1; i <= r; i++)
			size += 4 * i;

		T* radius = new T[size + 1]();
		int rc = 0;
		
		// Keep top middle and bottom middle line of radius split in case want to change back to not including the center of the radius
		T* line = getLine(x, x, y - r, y);
		for (int i = 0; i < r; i++)
		{
			radius[rc] = line[i];
			rc++;
		}

		line = getLine(x, x, y, y + r + 1);
		for (int i = 0; i < r + 1; i++)
		{
			radius[rc] = line[i];
			rc++;
		}

		for (int i = r - 1; i >= 0; i--)
		{
			int h = (y + i + 1) - (y - i);
			line = getLine(x - (r - i), x - (r - i), y - i, y + i + 1);
			for (int i = 0; i < h; i++)
			{
				radius[rc] = line[i];
				rc++;
			}
			line = getLine(x + r - i, x + r - i, y - i, y + i + 1);
			for (int i = 0; i < h; i++)
			{
				radius[rc] = line[i];
				rc++;
			}
		}

		return radius;
	}

	T* getNeighbours(int x, int y)
	{
		T* neighbours = new T[4]();

		if (y > 0)
			neighbours[0] = at(x, y - 1);
		if (y < getHeight() - 1)
			neighbours[1] = at(x, y + 1);
		if (x > 0)
			neighbours[2] = at(x - 1, y);
		if (x < getHeight() - 1)
			neighbours[3] = at(x + 1, y);

		return neighbours;
	}

	size_t getSize() { return width * height; }
	int getWidth() { return width; }
	int getHeight() { return height; }
	void getDimensions(int& w_, int& h_)
	{
		w_ = getWidth();
		h_ = getHeight();
	}

private:

	T** grid;

	int width, height;

	
};

#endif
