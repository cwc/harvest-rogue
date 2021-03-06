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
#include "item.h"
#include "nameable.h"

typedef struct landmark_item_s {
   int x;
   int y;
   ItemPtr ItemTarget;
} LandmarkItem;

class Landmark 
   : public INameable{
public:
   static std::shared_ptr<Landmark> Construct(std::string name, int width, int height) {
      return std::shared_ptr<Landmark>(new Landmark(name, width, height));
   }

   unsigned int GetWidth();
   unsigned int GetHeight();
   void SetTile(int x, int y, TileType::TileType tile);
   Tile::Tile GetTile(int x, int y);
   void AddItem(int x, int y, ItemPtr item);
   ItemPtr GetItem(int x, int y);
   void RemoveItem(int x, int y);
   bool LocateItem(ItemPtr item, int& x, int& y);
   std::map<int, std::shared_ptr<LandmarkItem>> GetAllLandmarkItems();

   // INameable
   std::string GetName();

private:
   Landmark(std::string name, int width, int height);

   std::vector<Tile::Tile> Tiles;
   std::string Name;
   unsigned int Width, Height;
   std::map<int, std::shared_ptr<LandmarkItem>> Items;
};


#endif //HARVEST_ROGUE_LANDMARK_H
