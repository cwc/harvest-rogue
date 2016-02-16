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

#ifndef HARVEST_ROGUE_ITEMCONTAINER_H
#define HARVEST_ROGUE_ITEMCONTAINER_H

#include <vector>
#include <memory>
#include "item.h"
#include "nameable.h"

class IItemContainer; // Foward declaration for the typedef
typedef IItemContainer* ItemContainerPtr;

// Declares that this object has the ability to contain items
class IItemContainer : 
   public INameable {
public:
   virtual ItemListPtr GetAllItems() = 0;

   virtual ~IItemContainer() {}

   virtual ItemContainerPtr AsItemContainer() = 0;
};

#endif //HARVEST_ROGUE_ITEMCONTAINER_H
