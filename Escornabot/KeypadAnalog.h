// KeypadAnalog.h
/*

Copyright (C) 2014-2017 Escornabot - http://escornabot.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#ifndef _BUTTON_SET_ANALOG_H
#define _BUTTON_SET_ANALOG_H

#include "Keypad.h"

/**
 * \brief Implementation of a keypad connected to 1 analog input.
 * \author @caligari
 */
class KeypadAnalog : Keypad
{
public:

    typedef struct {
        uint8_t pin_keypad;
        bool pullup;
        int16_t val_btn_up;
        int16_t val_btn_right;
        int16_t val_btn_down;
        int16_t val_btn_left;
        int16_t val_btn_go;
        int16_t val_btn_reset;
    } Config;

    KeypadAnalog(const Config* config);

    /**
     * Does the hardware initialization.
     */
    virtual void init();

    /**
     * Reads the buttons.
     */
    virtual void scanButtons();

    /**
     * Returns if the keypad has configured the optional reset button.
     */
    virtual bool hasResetButton() { return (_val_btn_reset != 0); }

    // ToDo
    void rescan(BUTTON button) {}

    // ToDo
    bool isRescanning() { return false; }

private:

    const Config* _config;

    int16_t _val_btn_up;
    int16_t _val_btn_right;
    int16_t _val_btn_down;
    int16_t _val_btn_left;
    int16_t _val_btn_go;
    int16_t _val_btn_reset;

    BUTTON _last_button;

};


#endif // _BUTTON_SET_ANALOG_H

// EOF
