/*
  ==============================================================================

   This file is part of the JUCE library.
   Copyright (c) 2013 - Raw Material Software Ltd.

   Permission is granted to use this software under the terms of either:
   a) the GPL v2 (or any later version)
   b) the Affero GPL v3

   Details of these licenses can be found at: www.gnu.org/licenses

   JUCE is distributed in the hope that it will be useful, but WITHOUT ANY
   WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
   A PARTICULAR PURPOSE.  See the GNU General Public License for more details.

   ------------------------------------------------------------------------------

   To release a closed-source product which uses JUCE, commercial licenses are
   available: visit www.juce.com for more information.

  ==============================================================================
*/

#ifndef __JUCE_SHAPEBUTTON_JUCEHEADER__
#define __JUCE_SHAPEBUTTON_JUCEHEADER__

#include "juce_Button.h"


//==============================================================================
/**
    A button that contains a filled shape.

    @see Button, ImageButton, TextButton, ArrowButton
*/
class JUCE_API  ShapeButton  : public Button
{
public:
    //==============================================================================
    /** Creates a ShapeButton.

        @param name             a name to give the component - see Component::setName()
        @param normalColour     the colour to fill the shape with when the mouse isn't over
        @param overColour       the colour to use when the mouse is over the shape
        @param downColour       the colour to use when the button is in the pressed-down state
    */
    ShapeButton (const String& name,
                 const Colour& normalColour,
                 const Colour& overColour,
                 const Colour& downColour);

    /** Destructor. */
    ~ShapeButton();

    //==============================================================================
    /** Sets the shape to use.

        @param newShape                 the shape to use
        @param resizeNowToFitThisShape  if true, the button will be resized to fit the shape's bounds
        @param maintainShapeProportions if true, the shape's proportions will be kept fixed when
                                        the button is resized
        @param hasDropShadow            if true, the button will be given a drop-shadow effect
    */
    void setShape (const Path& newShape,
                   bool resizeNowToFitThisShape,
                   bool maintainShapeProportions,
                   bool hasDropShadow);

    /** Set the colours to use for drawing the shape.

        @param normalColour     the colour to fill the shape with when the mouse isn't over
        @param overColour       the colour to use when the mouse is over the shape
        @param downColour       the colour to use when the button is in the pressed-down state
    */
    void setColours (const Colour& normalColour,
                     const Colour& overColour,
                     const Colour& downColour);

    /** Sets up an outline to draw around the shape.

        @param outlineColour        the colour to use
        @param outlineStrokeWidth   the thickness of line to draw
    */
    void setOutline (const Colour& outlineColour,
                     float outlineStrokeWidth);


    /** @internal */
    void paintButton (Graphics&, bool isMouseOverButton, bool isButtonDown);

private:
    //==============================================================================
    Colour normalColour, overColour, downColour, outlineColour;
    DropShadowEffect shadow;
    Path shape;
    bool maintainShapeProportions;
    float outlineWidth;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ShapeButton)
};


#endif   // __JUCE_SHAPEBUTTON_JUCEHEADER__
