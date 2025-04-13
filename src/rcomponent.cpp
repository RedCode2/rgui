#include "RGUI.h"
#include "RGUI.h"
#include "RGUI.h"

void RGUI::BasicComponent::SetOnHoverProperties(Vector2 onHoverPosition, Dimension onHoverDimension, Color onHoverBgcolor) {
	// Set Component's onHover values to specified values
	this->onHoverDimension	=	onHoverDimension;
	this->onHoverPosition	=	onHoverPosition;
	this->onHoverBgcolor	=	onHoverBgcolor;
}

void RGUI::BasicComponent::SetOnClickProperties(Vector2 onClickPosition, Dimension onClickDimension, Color onClickBgcolor) {
	// Set Component's onClick values to specified values
	this->onClickDimension	=	onClickDimension;
	this->onClickPosition	=	onClickPosition;
	this->onClickBgColor	=	onClickBgcolor;
}

void RGUI::Component::SetOnHoverBorderProperties(Border onHoverBorder) {
	// Set Component's onHoverBorder value to specified value
	this->onHoverBorder = onHoverBorder;
}

void RGUI::Component::SetOnClickBorderProperties(Border onClickBorder) {
	// Set Component's onClickBorder value to specified value
	this->onClickBorder = onClickBorder;
}

void RGUI::BasicComponent::SetOnHoverDimensions(Dimension onHoverDimension) {
	// Set Component's onHoverDimension value to specified value
	this->onHoverDimension = onHoverDimension;
}

void RGUI::BasicComponent::SetOnHoverPosition(Vector2 onHoverPosition) {
	// Set Component's onHoverPosition value to specified value
	this->onHoverPosition = onHoverPosition;
}

void RGUI::BasicComponent::SetOnHoverBgcolor(Color onHoverBgcolor) {
	// Set Component's onHoverBgcolor value to specified value
	this->onHoverBgcolor = onHoverBgcolor;
}

void RGUI::BasicComponent::SetOnClickDimensions(Dimension onClickDimension) {
	// Set Component's onClickDimension to specified value
	this->onClickDimension = onClickDimension;
}

void RGUI::BasicComponent::SetOnClickPosition(Vector2 onClickPosition) {
	// Set Component's onClickPosition to specified value
	this->onClickPosition = onClickPosition;
}

void RGUI::BasicComponent::SetOnClickBgcolor(Color onClickBgcolor) {
	// Set Component's onClickBgcolor to specified value
	this->onClickBgColor = onClickBgcolor;
}

void RGUI::Component::SetBorderProperties(Border border) {
	// Set Component's Border Properties
	this->border = border;
}

void RGUI::ComponentPro::SetBorderProperties(BorderPro borderPro) {
	// Set Pro Component's Border Properties
	this->borderPro = borderPro;
}

void RGUI::ComponentPro::SetBorderTProperties(Border border_t) {
	// Set Pro Component's Border_t Properties
	this->borderPro.t_color		= border_t.color;
	this->borderPro.t_thickness = border_t.thickness;
}

void RGUI::ComponentPro::SetBorderRProperties(Border border_r) {
	// Set Pro Component's Border_r Properties
	this->borderPro.r_color		= border_r.color;
	this->borderPro.r_thickness = border_r.thickness;
}

void RGUI::ComponentPro::SetBorderBProperties(Border border_b) {
	// Set Pro Component's Border_r Properties
	this->borderPro.b_color		= border_b.color;
	this->borderPro.b_thickness = border_b.thickness;
}

void RGUI::ComponentPro::SetBorderLProperties(Border border_l) {
	// Set Pro Compoment's Border_l Properties
	this->borderPro.l_color		= border_l.color;
	this->borderPro.l_thickness	= border_l.thickness;
}

void RGUI::ComponentPro::SetOnHoverBorderProperties(BorderPro onHoverBorderPro) {
	// Set Pro Component's onHover Border Properties
	this->onHoverBorderPro = onHoverBorderPro;
}

void RGUI::ComponentPro::SetOnClickBorderProperties(BorderPro onClickBorderPro) {
	// Set Pro Component's onClick Border Properties
	this->onClickBorderPro = onClickBorderPro;
}

void RGUI::ComponentPro::SetOnHoverBorderTProperties(Border onHoverBorder_t) {
	// Set Pro Component's onHover Border_t Properties
	this->onHoverBorderPro.t_color		= onHoverBorder_t.color;
	this->onHoverBorderPro.t_thickness	= onHoverBorder_t.thickness;
}

void RGUI::ComponentPro::SetOnHoverBorderRProperties(Border onHoverBorder_r) {
	// Set Pro Component's onHover Border_r Properties
	this->onHoverBorderPro.r_color		= onHoverBorder_r.color;
	this->onHoverBorderPro.r_thickness	= onHoverBorder_r.thickness;
}

void RGUI::ComponentPro::SetOnHoverBorderBProperties(Border onHoverBorder_b) {
	// Set Pro Component's onHover Border_b Properties
	this->onHoverBorderPro.b_color		= onHoverBorder_b.color;
	this->onHoverBorderPro.b_thickness	= onHoverBorder_b.thickness;
}

void RGUI::ComponentPro::SetOnHoverBorderLProperties(Border onHoverBorder_l) {
	// Set Pro Component's onHover Border_l Properties
	this->onHoverBorderPro.l_color		= onHoverBorder_l.color;
	this->onHoverBorderPro.l_thickness	= onHoverBorder_l.thickness;
}

void RGUI::ComponentPro::SetOnClickBorderTProperties(Border onClickBorder_t) {
	// Set Pro Component's onClick Border_t Properties when clicked
	this->onClickBorderPro.t_color		= onClickBorder_t.color;
	this->onClickBorderPro.t_thickness	= onClickBorder_t.thickness;
}

void RGUI::ComponentPro::SetOnClickBorderRProperties(Border onClickBorder_r) {
	// Set Pro Component's onClick Border_r Properties when clicked
	this->onClickBorderPro.r_color		= onClickBorder_r.color;
	this->onClickBorderPro.r_thickness	= onClickBorder_r.thickness;
}

void RGUI::ComponentPro::SetOnClickBorderBProperties(Border onClickBorder_b) {
	// Set Pro Component's onClick Border_b Properties when clicked
	this->onClickBorderPro.b_color		= onClickBorder_b.color;
	this->onClickBorderPro.b_thickness	= onClickBorder_b.thickness;
}

void RGUI::ComponentPro::SetOnClickBorderLProperties(Border onClickBorder_l) {
	// Set Pro Component's onClick Border_l Properties when clicked
	this->onClickBorderPro.l_color		= onClickBorder_l.color;
	this->onClickBorderPro.l_thickness	= onClickBorder_l.thickness;
}

bool RGUI::BasicComponent::IsCursorHoveringOverComponent() const {
	if (CheckCollisionPointRec(GetMousePosition(), this->componentRec)) {
		// Return true if Mouse is Hovering over Component
		return true;
	}
	// Return false if Mouse is not Hovering over Component
	return false;
}

bool RGUI::BasicComponent::IsComponentPressed(int mouse_button) const {
	if (CheckCollisionPointRec(GetMousePosition(), this->componentRec)) {
		if (IsMouseButtonDown(mouse_button)) {
			// Return true if Component is clicked by <mouse_button>
			return true;
		}
		return false;	// Return false instead
	}
	return false;	// Return false instead
}

void RGUI::BasicComponent::SetBgOnHoverPropertiesDefault() {
	// Set all onHover properties to default
	this->SetOnHoverProperties(
		this->position,
		this->dimension,
		this->bgcolor
	);
}

void RGUI::BasicComponent::SetBgOnClickPropertiesDefault() {
	// Set all onClick properties to default
	this->SetOnClickProperties(
		this->position,
		this->dimension,
		this->bgcolor
	);
}

void RGUI::BasicComponent::SetOnHoverPropertiesDefault() { this->SetBgOnHoverPropertiesDefault(); }
void RGUI::BasicComponent::SetOnClickPropertiesDefault() { this->SetBgOnClickPropertiesDefault(); }

void RGUI::BasicComponent::drawBackground() {
	if (this->IsComponentPressed(MOUSE_BUTTON_LEFT)) {
		this->isHoveredView = false;
		this->isNormalView = false;
		this->isClickedView = true;

		this->clickStartTime = GetTime();
	}
	else if (this->IsCursorHoveringOverComponent()) {
		this->isHoveredView = true;
		this->isNormalView = false;
		this->isClickedView = false;
	}
	else {
		this->isHoveredView = false;
		this->isNormalView = true;
		this->isClickedView = false;
	}

	if (this->isClickedView) {
		DrawRectangle(
			this->onClickPosition.x,
			this->onClickPosition.y,
			this->onClickDimension.width,
			this->onClickDimension.height,
			this->onClickBgColor
		);

		DrawText(
			this->onClickLabelText,
			this->onClickTextPosition.x,
			this->onClickTextPosition.y,
			this->onClickTextSize,
			this->onClickTextColor
		);
	}
	else if (this->isHoveredView) {
		DrawRectangle(
			this->onHoverPosition.x,
			this->onHoverPosition.y,
			this->onHoverDimension.width,
			this->onHoverDimension.height,
			this->onHoverBgcolor
		);

		DrawText(
			this->onHoverLabelText,
			this->onHoverTextPosition.x,
			this->onHoverTextPosition.y,
			this->onHoverTextSize,
			this->onHoverTextColor
		);
	}
	else if (this->isNormalView) {
		DrawRectangle(
			this->position.x,
			this->position.y,
			this->dimension.width,
			this->dimension.height,
			this->bgcolor
		);

		DrawText(
			this->labelText,
			this->textPosition.x,
			this->textPosition.y,
			this->textSize,
			this->textColor
		);
	}
}

void RGUI::BasicComponent::Draw() {
	if (this->IsVisible()) {
		// Only draw background as this component is borderless
		this->drawBackground();
	}
}

void RGUI::BasicComponent::SetDefaultLabelTextProperties(char* labelText, int textSize, Vector2 textPosition, Color textColor) {
	this->labelText		= labelText;
	this->textSize		= textSize;
	this->textPosition	= textPosition;
	this->textColor		= textColor;
}

void RGUI::BasicComponent::SetOnHoverLabelTextProperties(char* onHoverLabelText, int onHoverTextSize, Vector2 onHoverTextPosition, Color onHoverTextColor) {
	this->onHoverLabelText		= onHoverLabelText;
	this->onHoverTextSize		= onHoverTextSize;
	this->onHoverTextPosition	= onHoverTextPosition;
	this->onHoverTextColor		= onHoverTextColor;
}

void RGUI::BasicComponent::SetOnClickLabelTextProperties(char* onClickLabelText, int onClickTextSize, Vector2 onClickTextPosition, Color onClickTextColor) {
	this->onClickLabelText		= onClickLabelText;
	this->onClickTextSize		= onClickTextSize;
	this->onClickTextPosition	= onClickTextPosition;
	this->onClickTextColor		= onClickTextColor;
}

void RGUI::Component::Draw() {
	if (this->IsVisible()) {
		// Ensure componentBorderRec is up-to-date
		this->componentBorderRec = {
			this->position.x - this->border.thickness,
			this->position.y - this->border.thickness,
			this->dimension.width + (2 * this->border.thickness),
			this->dimension.height + (2 * this->border.thickness)
		};

		this->drawBackground();

		// Only draw the border if thickness is valid
		if (this->border.thickness > 0) {
			if (this->IsComponentPressed(MOUSE_BUTTON_LEFT)) {
				DrawRectangleLinesEx(
					this->componentBorderRec,
					this->onClickBorder.thickness,
					this->onClickBorder.color
				);
			}
			else if (this->IsCursorHoveringOverComponent()) {
				DrawRectangleLinesEx(
					this->componentBorderRec,
					this->onHoverBorder.thickness,
					this->onHoverBorder.color
				);
			}
			else {
				DrawRectangleLinesEx(
					this->componentBorderRec,
					this->border.thickness,
					this->border.color
				);
			}
		}
	}
}

void RGUI::ComponentPro::drawBorder(BorderPro _borderPro) {
	// Top Border
	// Top Left Top Triangle
	DrawTriangle(
		{ position.x, position.y },
		{ position.x, position.y - _borderPro.t_thickness },
		{ position.x - borderPro.l_thickness, position.y - _borderPro.t_thickness },
		_borderPro.t_color
	);

	// Top Rectangle
	DrawRectangle(
		position.x,
		position.y - _borderPro.t_thickness,
		dimension.width,
		_borderPro.t_thickness,
		_borderPro.t_color
	);

	// Top Right Top Triangle
	DrawTriangle(
		{ position.x + dimension.width + _borderPro.r_thickness, position.y - _borderPro.t_thickness },
		{ position.x + dimension.width, position.y - _borderPro.t_thickness },
		{ position.x + dimension.width, position.y },                        
		_borderPro.t_color
	);

	// Left Border
	// Top Left Bottom Triangle
	DrawTriangle(
		{ position.x - _borderPro.l_thickness, position.y - _borderPro.t_thickness },
		{ position.x - _borderPro.l_thickness, position.y },
		{ position.x, position.y },
		_borderPro.l_color
	);

	// Left Rectangle
	DrawRectangle(
		position.x - _borderPro.l_thickness,
		position.y,
		_borderPro.l_thickness,
		dimension.height,
		_borderPro.l_color
	);

	// Bottom Left Top Triangle
	DrawTriangle(
		{ position.x, position.y + dimension.height },
		{ position.x - _borderPro.l_thickness, position.y + dimension.height },
		{ position.x - _borderPro.l_thickness, position.y + dimension.height + _borderPro.l_thickness },
		_borderPro.l_color
	);

	// Bottom Border
	// Bottom Left Bottom Triangle
	DrawTriangle(
		{ position.x, position.y + dimension.height },
		{ position.x - _borderPro.l_thickness, position.y + dimension.height + _borderPro.b_thickness },
		{ position.x, position.y + dimension.height + _borderPro.b_thickness },
		_borderPro.b_color
	);

	// Bottom Rectangle
	DrawRectangle(
		position.x,
		position.y + dimension.height,
		dimension.width,
		_borderPro.b_thickness,
		_borderPro.b_color
	);

	// Bottom Right Bottom Triangle
	DrawTriangle(
		{ position.x + dimension.width, position.y + dimension.height },
		{ position.x + dimension.width, position.y + dimension.height + _borderPro.b_thickness },
		{ position.x + dimension.width + _borderPro.r_thickness, position.y + dimension.height + _borderPro.t_thickness },
		_borderPro.b_color
	);

	// Bottom Right Top Triangle
	DrawTriangle(
		{ position.x + dimension.width, position.y + dimension.height },
		{ position.x + dimension.width + _borderPro.r_thickness, position.y + dimension.height + _borderPro.b_thickness },
		{ position.x + dimension.width + _borderPro.r_thickness, position.y + dimension.height },
		_borderPro.r_color
	);

	// Right Rectangle
	DrawRectangle(
		position.x + dimension.width,
		position.y,
		_borderPro.r_thickness,
		dimension.height,
		_borderPro.r_color
	);

	// Top Right Bottom Triangle
	DrawTriangle(
		{ position.x + dimension.width + _borderPro.r_thickness, position.y - _borderPro.t_thickness },
		{ position.x + dimension.width, position.y },
		{ position.x + dimension.width + _borderPro.r_thickness, position.y },
		_borderPro.r_color
	);
}

void RGUI::ComponentPro::Draw() {
	if (this->IsVisible()) {
		if (this->IsComponentPressed(MOUSE_BUTTON_LEFT)) {
			this->drawBorder(this->onClickBorderPro);
		}
		else if (this->IsCursorHoveringOverComponent()) {
			this->drawBorder(this->onHoverBorderPro);
		}
		else {
			this->drawBorder(this->borderPro);
		}

		this->drawBackground();
	}
}

void RGUI::BasicComponent::SetVisibility(bool isVisible) {
	this->isVisible = isVisible;
}

bool RGUI::BasicComponent::IsVisible() const {
	return this->isVisible;
}
