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

#ifndef HARVEST_ROGUE_CONFIG_H
#define HARVEST_ROGUE_CONFIG_H

#include "keybinding.h"
#include "picojson.h"
#include <memory>

class IConfigProvider;

class Config {
   public:
      static picojson::value Serialize(Config config);
      static Config Deserialize(picojson::value serializedValue);

      static IConfigProvider* provider;

      int GetScreenWidth();
      void SetScreenWidth(int width);

      int GetScreenHeight();
      void SetScreenHeight(int height);

      Keybinding GetKeybinding();
      void SetKeybinding(Keybinding binding);

   private:
      int screenWidth = 640;
      int screenHeight = 480;

      Keybinding keybinding = Keybinding();
};

class IConfigProvider {
   public:
      virtual ~IConfigProvider() {};

      virtual Config GetConfig() = 0;
      virtual void SaveConfig() = 0;
};

#endif // HARVEST_ROGUE_CONFIG_H
