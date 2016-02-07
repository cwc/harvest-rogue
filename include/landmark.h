/*
    harvest-rogue is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    harvest-rogue is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with harvest-rogue.  If not, see <http://www.gnu.org/licenses/>.     */

#ifndef HARVEST_ROGUE_LANDMARK_H
#define HARVEST_ROGUE_LANDMARK_H

#include <string>
#include <memory>
#include <vector>
#include "tiles.h"

class Landmark {
public:
   static std::shared_ptr<Landmark> Construct(std::string name, int width, int height) {
      return std::shared_ptr<Landmark>(new Landmark(name, width, height));
   }

   std::string GetName();

   unsigned int GetWidth();

   unsigned int GetHeight();

   void SetTile(int x, int y, eTileType tile);

   Tile GetTile(int x, int y);
private:
   Landmark(std::string name, int width, int height);

   std::vector<Tile> Tiles;
   std::string Name;
   unsigned int Width, Height;
};


#endif //HARVEST_ROGUE_LANDMARK_H