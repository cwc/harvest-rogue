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

#ifndef HARVEST_ROGUE_CHOPPINGTOOL_H
#define HARVEST_ROGUE_CHOPPINGTOOL_H

#include "iteminterface.h"
#include "item.h"
#include "direction.h"
#include "useable.h"
#include "equippable.h"
#include <memory>

class ChoppingTool : public IItemInterface, public IUseable, public IDirectionallyUsable, public IEquippable, public std::enable_shared_from_this<ChoppingTool> {
public:
   IItemInterface* Clone() const { return new ChoppingTool(*this); }
private:
   ChoppingTool();

   ChoppingTool(ChoppingTool const &src) {
      this->Strength = src.Strength;
      this->Fatigue = src.Fatigue;
   };

   ChoppingTool &operator=(ChoppingTool const &) { };
public:
   ~ChoppingTool();
   static std::shared_ptr<ChoppingTool> Deserialize(picojson::value serializedValue);

   int GetStrength();
   void SetStrength(int strength);
   int GetFatigue();
   void SetFatigue(int fatigue);

   void Chop(ItemPtr sourceItem);
   void Chop(ItemPtr sourceItem, Direction::Direction direction);

   // IItemInterface
   virtual ItemInterfaceType::ItemInterfaceType GetInterfaceType();

   // IUseable
   virtual void Use(ItemPtr sourceItem);

   // IDirectionallyUseable
   virtual void Use(ItemPtr sourceItem, Direction::Direction direction);

   // IEquippable
   virtual void OnItemEquipped(ItemPtr sourceItem);
   virtual void OnItemUnequipped(ItemPtr sourceItem);
private:
   int Strength;
   int Fatigue;
};

#endif //HARVEST_ROGUE_CHOPPINGTOOL_H
