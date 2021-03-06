// This file is part of openCaesar3.
//
// openCaesar3 is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// openCaesar3 is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with openCaesar3.  If not, see <http://www.gnu.org/licenses/>.
//
// Copyright 2012-2013 Gregoire Athanase, gathanase@gmail.com


#ifndef GUI_INFO_BOX_HPP
#define GUI_INFO_BOX_HPP

#include <string>
#include <list>

#include "gui_menu.hpp"
#include "picture.hpp"
#include "house.hpp"
#include "factory_building.hpp"
#include "service_building.hpp"

// base class for info boxes
class GuiInfoBox : public WidgetGroup
{
public:
   GuiInfoBox();
   virtual ~GuiInfoBox();
   void init(const int width, const int height);
   void initStatic();
   virtual void draw(const int dx, const int dy);  // draw on screen
   virtual void paint() = 0;  // custom paint the bg picture

   Picture& getBgPicture();

   void handleEvent(SDL_Event &event);
   // returns true if widget needs to be deleted
   bool isDeleted() const;

   Picture& getPictureGood(const GoodType& goodType);

protected:
   std::string _title;
   Picture *_bgPicture;
   bool _isDeleted;  // true if needs to be deleted
   ImageButton _helpButton;
   ImageButton* _hoverButton;

   static std::vector<Picture*> _mapPictureGood;  // index=GoodType, value=Picture

   int _paintY;  // Y pixel coordinate of the next paint operation
};


// info box about a service building
class GuiInfoService : public GuiInfoBox
{
public:
   GuiInfoService(ServiceBuilding &building);
   virtual void paint();

   void drawWorkers();

private:

   ServiceBuilding *_building;
};


// info box about a factory building
class GuiInfoFactory : public GuiInfoBox
{
public:
   GuiInfoFactory(Factory &building);
   virtual void paint();

   void drawWorkers();
   std::string getInfoText();

private:
   Factory *_building;
};


// info box about a granary
class GuiInfoGranary : public GuiInfoBox
{
public:
   GuiInfoGranary(Granary &building);
   virtual void paint();

   void drawWorkers();
   void drawGood(const GoodType &goodType);

private:
   Granary *_building;
};


// info box about a market
class GuiInfoMarket : public GuiInfoBox
{
public:
   GuiInfoMarket(Market &building);
   virtual void paint();

   void drawWorkers();
   void drawGood(const GoodType &goodType);

private:
   Market *_building;
};


// info box about a house
class GuiInfoHouse : public GuiInfoBox
{
public:
   GuiInfoHouse(House &house);
   virtual void paint();

   void drawHabitants();
   void drawTaxes();
   void drawCrime();
   void drawGood(const GoodType &goodType, const int col, const int row);

private:

   House *_house;
};

class GuiBuilding : public GuiInfoBox
{
public:
   GuiBuilding(Building &building);
   virtual void paint();

private:

   Building *_building;
};

#endif
