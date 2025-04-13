/**********************************************************************************************
*   RGUI v1.0.0 - A simple, easy-to-use library to make good looking, interactive GUI with raylib
*   
*   FEATURES:
*       - No external dependencies, all required libraries are included with RGUI
*       - Easily create GUI as raylib doesn't have much good support to make interactive GUIs.
*       - Easy Component Initialization.
*   
*   NOTES:
*       - Made only for developing games/apps with the Raylib game development library
*       - 
*   
*   DEPENDENCIES (included):
*       [rcore] rglfw (Camilla Löwy - github.com/glfw/glfw) for window/context management and input (PLATFORM_DESKTOP)
*       [raudio] miniaudio (David Reid - github.com/mackron/miniaudio) for audio device/context management
* 
**********************************************************************************************/
#pragma once

// 1. Version Information (as compile-time constants)
namespace RGUI {
    constexpr   int             VERSION_MAJOR   = 1;
    constexpr   int             VERSION_MINOR   = 0;
    constexpr   int             VERSION_PATCH   = 0;
    constexpr   const char*     VERSION         = "1.0.0";
}

// 2. Platform Detection (constexpr if for C++17+)
#if defined(_WIN32) || defined(_WIN64)
    #define RGUI_PLATFORM_WINDOWS
#elif defined(__APPLE__)
    #include <TargetConditionals.h>
    #if TARGET_OS_MAC
        #define RGUI_PLATFORM_MACOS
    #endif
#endif

// 3. DLL Export/Import (Windows-specific)
#if defined(RGUI_PLATFORM_WINDOWS)
    #ifdef RGUI_BUILD_SHARED
        #define RGUI_API __declspec(dllexport)
    #elif defined(RGUI_USE_SHARED)
        #define RGUI_API __declspec(dllimport)
    #else
        #define RGUI_API
    #endif
#else
    #define RGUI_API
#endif

#include <raylib.h>
#include <chrono>
#include <thread>

#include "rtexture.h"

// 4. Core GUI Classes
namespace RGUI {

    using Dimension = struct {
        float   width;      // Width of Element
        float   height;     // Height of Element
    };
    using Border = struct {
        float   thickness;  // Thickness of border
        Color   color;      // Color of border
    };
    using BorderPro = struct {
        float   t_thickness;    // Thickness of top border
        float   r_thickness;    // Thickness of right border
        float   b_thickness;    // Thickness of bottom border
        float   l_thickness;    // Thickness of left border

        Color   t_color;        // Color of top border
        Color   r_color;        // Color of right border
        Color   b_color;        // Color of bottom border
        Color   l_color;        // Color of left border
    };

    class RGUI_API BasicComponent {
    protected:
        // Component Dimensions
        Dimension dimension;                            // Component Dimensions
        Dimension onHoverDimension = dimension;         // Component onHover Dimensions
        Dimension onClickDimension = dimension;         // Component onClick Dimensions

        // Component Position
        Vector2 position;                               // Component Position
        Vector2 onHoverPosition = position;             // Component onHover Position
        Vector2 onClickPosition = position;             // Component onClick Position

        // Component bgcolor
        Color bgcolor;                                  // Component bgcolor
        Color onHoverBgcolor = bgcolor;                 // Component onHover bgcolor
        Color onClickBgColor = bgcolor;                 // Component onClick BgColor

        // Component labelText
        char*   labelText           = "";               // Component default label text
        char*   onHoverLabelText    = labelText;        // Component onHover label text
        char*   onClickLabelText    = labelText;        // Component onClick label text
            
        int     textSize            = 0;                // Component default label text size
        int     onHoverTextSize     = textSize;         // Component onHover label text size
        int     onClickTextSize     = textSize;         // Component onClick label text size

        Vector2 textPosition        = {0, 0};           // Component default label text position
        Vector2 onHoverTextPosition = textPosition;     // Component onHover label text position
        Vector2 onClickTextPosition = textPosition;     // Component onClick label text position

        Color   textColor           = BLACK;            // Component default label text Color
        Color   onHoverTextColor    = textColor;        // Component onHover label text Color
        Color   onClickTextColor    = textColor;        // Component onClick label text Color

        // Component Properties
        Rectangle componentRec = {
            this->position.x,       this->position.y,
            this->dimension.width,  this->dimension.height
        };

        // Component appearance
        bool isNormalView   = true;
        bool isHoveredView  = false;
        bool isClickedView  = false;
        bool isVisible      = true;

        double clickStartTime = 0.0;

    protected:
        void drawBackground();

        void SetBgOnHoverPropertiesDefault();       
        void SetBgOnClickPropertiesDefault();       

    public:
        BasicComponent(
            Vector2     position,
            Dimension   dimension,
            Color       bgcolor
        ) :
            dimension(dimension),
            position(position),
            bgcolor(bgcolor)
        {};

        virtual void SetOnHoverPropertiesDefault();       // Set all hover properties of Component to default
        virtual void SetOnClickPropertiesDefault();       // Set all click properties of Component to default

        // Set Component onHover Properties
        void SetOnHoverProperties(
            Vector2     onHoverPosition,    // Component's onHoverPosition
            Dimension   onHoverDimension,   // Component's onHoverDimension
            Color       onHoverBgcolor      // Component's onHoverBgcolor
        );

        // Set Component onClick Properties
        void SetOnClickProperties(
            Vector2     onHoverPosition,    // Component's onHoverPosition
            Dimension   onClickDimension,   // Component's onClickDimension
            Color       onClickBgcolor      // Component's onClickBgcolor
        );

        // Set Component default label Text Properties
        void SetDefaultLabelTextProperties(
            char*   labelText,
            int     textSize,
            Vector2 textPosition,
            Color   textColor
        );

        // Set Component onHover label Text Properties
        void SetOnHoverLabelTextProperties(
            char*   onHoverLabelText,
            int     onHoverTextSize,
            Vector2 onHoverTextPosition,
            Color   onHoverTextColor
        );

        void SetOnClickLabelTextProperties(
            char*   onClickLabelText,
            int     onClickTextSize,
            Vector2 onClickTextPosition,
            Color   onClickTextColor
        );

        void SetOnHoverDimensions(Dimension onHoverDimension);      // Set Component Dimensions when cursor hovers over Component
        void SetOnHoverPosition(Vector2 onHoverPosition);           // Set Component Position when cursor hovers over Component
        void SetOnHoverBgcolor(Color onHoverBgcolor);               // Set Component Bgcolor when cursor hovers over Component

        void SetOnClickDimensions(Dimension onClickDimension);      // Set Component Dimensions when Component is clicked
        void SetOnClickPosition(Vector2 onClickPosition);           // Set Component Position when Component is clicked
        void SetOnClickBgcolor(Color onClickBgcolor);               // Set Component Bgcolor when Component is clicked
        
        bool IsCursorHoveringOverComponent() const;         // Check if cursor is hovering over Component
        bool IsComponentPressed(int mouse_button) const;    // Check if Component is clicked

        virtual void Draw();        // Draw Component

        void SetVisibility(bool isVisible);         // Set Component Visibility

        bool IsVisible() const;         // Return if Component is visible or not
    };


    // Component Class
    class RGUI_API Component : public BasicComponent {
    protected:
        // Component Border
        Border border;                      // Component Border
        Border onHoverBorder;               // Component onHover Border
        Border onClickBorder;               // Component onClick Border

        Rectangle componentBorderRec = {
            this->position.x - this->border.thickness,      this->position.y - this->border.thickness,
            this->dimension.width + this->border.thickness, this->dimension.height + this->border.thickness
        };

    public:
        Component(
            Vector2     position, 
            Dimension   dimension, 
            Color       bgcolor
        ) : BasicComponent(position, dimension, bgcolor) {};

        void SetBorderProperties(Border border);                    // Set Component Border Properties
        void SetOnHoverBorderProperties(Border onHoverBorder);      // Set Component Border when cursor hovers over Component
        void SetOnClickBorderProperties(Border onClickBorder);      // Set Component Border when Component is clicked

        void Draw() override;
    };


    // Component Pro Class
    class RGUI_API ComponentPro : public BasicComponent {
    protected:
        // Component BorderPro
        BorderPro borderPro;                // Component ProBorder
        BorderPro onHoverBorderPro;         // Component onHover BorderPro
        BorderPro onClickBorderPro;         // Component onClick BorderPro

        void drawBorder(BorderPro _borderPro);

    public:
        ComponentPro(
            Vector2     position,
            Dimension   dimension,
            Color       bgcolor
        ) : BasicComponent(position, dimension, bgcolor) {};

        void Draw() override;

        void SetBorderProperties(BorderPro borderPro);                  // Set Component Border properties
        void SetOnHoverBorderProperties(BorderPro onHoverBorderPro);    // Set Component Border properties when cursor hovers over Component
        void SetOnClickBorderProperties(BorderPro onClickBorderPro);    // Set Component Border properties when Component is clicked

        void SetBorderTProperties(Border border_t);                     // Set Component Border_t properties
        void SetBorderRProperties(Border border_r);                     // Set Component Border_r properties
        void SetBorderBProperties(Border border_b);                     // Set Component Border_b properties
        void SetBorderLProperties(Border border_l);                     // Set Component Border_l properties

        void SetOnHoverBorderTProperties(Border onHoverBorder_t);       // Set Component Border_t properties when cursor hovers over Component
        void SetOnHoverBorderRProperties(Border onHoverBorder_r);       // Set Component Border_r properties when cursor hovers over Component
        void SetOnHoverBorderBProperties(Border onHoverBorder_b);       // Set Component Border_b properties when cursor hovers over Component
        void SetOnHoverBorderLProperties(Border onHoverBorder_l);       // Set Component Border_l properties when cursor hovers over Component

        void SetOnClickBorderTProperties(Border onClickBorder_t);       // Set Component Border_t properties when Component is clicked
        void SetOnClickBorderRProperties(Border onClickBorder_r);       // Set Component Border_r properties when Component is clicked
        void SetOnClickBorderBProperties(Border onClickBorder_b);       // Set Component Border_b properties when Component is clicked
        void SetOnClickBorderLProperties(Border onClickBorder_l);       // Set Component Border_l properties when Component is clicked
    };

    
    // Button Class
    class RGUI_API Button : public Component {
    public:
        Button(
            Vector2     position,
            Dimension   dimension,
            Color       bgcolor
        ) : Component(position, dimension, bgcolor) {};
    };


    // Button Pro Class
    class RGUI_API ButtonPro : public ComponentPro {
    public:
        ButtonPro(
            Vector2     position,
            Dimension   dimension,
            Color       bgcolor
        ) : ComponentPro(position, dimension, bgcolor) {};
    };


    // CheckBox Class
    class RGUI_API CheckBox : public BasicComponent {
    private:
        char* checked_texture_path;
        char* unchecked_texture_path;

        bool isChecked;

    public:
        CheckBox(
            Vector2     position,
            Dimension   dimension,
            bool        isChecked,
            char*       unchecked_texture_path  = RGUI::Textures::Checkbox::Sharp::BOX_CHECKED_LIGHT,
            char*       checked_texture_path    = RGUI::Textures::Checkbox::Sharp::BOX_UNCHECKED_LIGHT
        
        ) : BasicComponent(position, dimension, WHITE), 
            isChecked(isChecked),
            checked_texture_path(checked_texture_path),
            unchecked_texture_path(unchecked_texture_path)
        {};

        bool IsChecked() const;             // Return if checkbox is checked.

        void SetCheckedTexturePath(char* checked_texture_path);         // Function to set path of texture for checked checkbox
        void SetUncheckedTexturePath(char* unchecked_texture_path);     // Function to set path of texture for unchecked checkbox
    };

}