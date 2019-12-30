/* MIT License
 *
 * Copyright (c) 2019 Andreas Merkle <web@blue-andi.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

/*******************************************************************************
    DESCRIPTION
*******************************************************************************/
/**
 * @brief  Progress bar
 * @author Andreas Merkle <web@blue-andi.de>
 * 
 * @addtogroup gfx
 *
 * @{
 */

#ifndef __PROGRESSBAR_H__
#define __PROGRESSBAR_H__

/******************************************************************************
 * Compile Switches
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include <stdint.h>
#include <Widget.hpp>
#include <Color.h>

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Types and Classes
 *****************************************************************************/

/**
 * A progress bar widget, showing the progress from 0 to 100%.
 */
class ProgressBar : public Widget
{
public:

    /**
     * Constructs a progress bar widget.
     */
    ProgressBar() :
        Widget(WIDGET_TYPE),
        m_progress(0u),
        m_color(ColorDef::RED)
    {
    }

    /**
     * Constructs the progress bar, by assigning another.
     * 
     * @param[in] widget Progress bar, which to assign.
     */
    ProgressBar(const ProgressBar& widget) :
        Widget(WIDGET_TYPE),
        m_progress(widget.m_progress),
        m_color(widget.m_color)
    {
    }

    /**
     * Destroys the progress bar.
     */
    ~ProgressBar()
    {
    }

    /**
     * Assign the content of a progress bar widget.
     * 
     * @param[in] widget Widget, which to assign
     */
    ProgressBar& operator=(const ProgressBar& widget)
    {
        m_progress  = widget.m_progress;
        m_color     = widget.m_color;

        return *this;
    }

    /**
     * Update/Draw the progress bar widget.
     * 
     * @param[in] gfx Graphics interface
     */
    void update(Adafruit_GFX& gfx) override;

    /**
     * Set progress in % [0; 100].
     * 
     * @param[in] progress  Progress as number from 0 to 100.
     */
    void setProgress(uint8_t progress)
    {
        if (100 < progress)
        {
            m_progress = 100;
        }
        else
        {
            m_progress = progress;
        }

        return;
    }

    /**
     * Set progress bar color.
     * 
     * @param[in] color Progress bar color
     */
    void setColor(const Color& color)
    {
        m_color = color;
        return;
    }

    /** Widget type string */
    static const char*  WIDGET_TYPE;

private:

    uint8_t m_progress; /**< Progress in % [0; 100]. */
    Color   m_color;    /**< Color of the progress bar */

};

/******************************************************************************
 * Functions
 *****************************************************************************/

#endif  /* __PROGRESSBAR_H__ */

/** @} */