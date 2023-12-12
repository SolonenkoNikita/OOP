#include "Search/Search.hpp"

#include <vector>
#include <queue>
#include <limits>

std::vector<Coordinate> Search::search(const Matrix<Cell>& grid, const Coordinate& start, const Coordinate& end)
{
    std::queue<Coordinate> q;
    std::vector<Coordinate> path;
    std::vector<std::vector<bool>> visited(grid.size_matrix(), std::vector<bool>(grid.size_line(), false));
    std::vector<std::vector<Coordinate>> prev(grid.size_matrix(), std::vector<Coordinate>(grid.size_line()));

    q.push(start);
    visited[start.x][start.y] = true;
    prev[start.x][start.y] = start;

    const std::vector<Direction> directions = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    while (!q.empty()) 
    {
        Coordinate current = q.front();
        q.pop();
        if (current == end)
        {
            while (current != start)
            {
                path.push_back(current);
                current = prev[current.x][current.y];
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }
       
        for (const Direction& dir : directions)
        {
            int newX = current.x + dir.x();
            int newY = current.y + dir.y();
            int flag = 0;
            if (newX >= 0 && newX < grid.size_matrix() && newY >= 0 && newY < grid.size_line())
            {
                const Coordinate next = { newX, newY };

                if (!visited[next.x][next.y]) 
                {
                    //for (auto& v : grid[newX][newY].get_content())
                    //{
                    //    if (auto content = std::dynamic_pointer_cast<Obstacle>(v))
                    //    {
                    //        if (content->is_hard())
                    //        {
                    //            //flag = 1;
                    //            //std::cout << next.x << ' ' << next.y << '\n';
                    //            break;
                    //        }
                    //    }
                    //}
                   visited[next.x][next.y] = true;
                   prev[next.x][next.y] = current;
                   q.push(next);
                }
            }
        }
    }
    return std::vector<Coordinate>();
}

