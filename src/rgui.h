// RGUI.hpp - Pure C++ GUI Library
#pragma once

// 1. Version Information (as compile-time constants)
namespace RGUI {
    constexpr   int             VERSION_MAJOR = 1;
    constexpr   int             VERSION_MINOR = 0;
    constexpr   int             VERSION_PATCH = 0;
    constexpr   const char*     VERSION = "1.0.0";

    const char* GetVersion() { return VERSION; };
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
        Dimension dimension;               // Component Dimensions
        Dimension onHoverDimension;        // Component onHover Dimensions
        Dimension onClickDimension;        // Component onClick Dimensions

        // Component Position
        Vector2 position;                   // Component Position
        Vector2 onHoverPosition;            // Component onHover Position
        Vector2 onClickPosition;            // Component onClick Position

        // Component bgcolor
        Color bgcolor;                      // Component bgcolor
        Color onHoverBgcolor;               // Component onHover bgcolor
        Color onClickBgColor;               // Component onClick BgColor

    public:
        BasicComponent(
            Dimension   dimension,
            Vector2     position,
            Color       bgcolor
        ) :
            dimension(dimension),
            position(position),
            bgcolor(bgcolor)
        {
        };

        void SetOnHoverDimensions(Dimension onHoverDimension);      // Set Component Dimensions when cursor hovers over Component
        void SetOnHoverPosition(Vector2 onHoverPosition);           // Set Component Position when cursor hovers over Component
        void SetOnHoverBgcolor(Color onHoverBgcolor);               // Set Component Bgcolor when cursor hovers over Component

        void SetOnClickDimensions(Dimension onClickDimension);      // Set Component Dimensions when Component is clicked
        void SetOnClickPosition(Vector2 onClickPosition);           // Set Component Position when Component is clicked
        void SetOnClickBgcolor(Color onClickBgcolor);               // Set Component Bgcolor when Component is clicked
    };

    class RGUI_API Component : public BasicComponent {
    protected:
        // Component Border
        Border border;                      // Component Border
        Border onHoverBorder;               // Component onHover Border
        Border onClickBorder;               // Component onClick Border

    };

    class RGUI_API ComponentPro : public BasicComponent {
    protected:
        // Component BorderPro
        BorderPro borderPro;                // Component ProBorder
        BorderPro onHoverBorderPro;         // Component onHover BorderPro
        BorderPro onClickBorderPro;         // Component onClick BorderPro
    };

    class RGUI_API Button : public Component {

    };

} // namespace RGUI