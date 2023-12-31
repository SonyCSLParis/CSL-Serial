/*
  RomiSerial

  Copyright (C) 2019 Sony Computer Science Laboratories
  Author(s) Peter Hanappe

  RomiSerial is part of the Romi Rover project.

  RomiSerial is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see
  <http://www.gnu.org/licenses/>.

 */
#include <ArduinoSerial.h>
#include <RomiSerial.h>

void my_handler(RomiSerial *romiSerial,
                int16_t *args,
                const char *string_arg)
{
        // Do stuff here.
        // Then:
        romiSerial->send_ok();
}

const static MessageHandler handlers[] = {
        { 'a', 0, false, my_handler }
};

ArduinoSerial serial(Serial);
RomiSerial romiSerial(serial, serial, handlers, 1);

void setup()
{
        Serial.begin(115200);
        while (!Serial)
                ;
}

void loop()
{
        romiSerial.handle_input();
}
