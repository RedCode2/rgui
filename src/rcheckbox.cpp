#include "RGUI.h"

bool RGUI::CheckBox::IsChecked() const {
	return this->isChecked;
}

void RGUI::CheckBox::SetCheckedTexturePath(char* checked_texture_path) {
	this->checked_texture_path = checked_texture_path;
}

void RGUI::CheckBox::SetUncheckedTexturePath(char* unchecked_texture_path) {
	this->unchecked_texture_path = unchecked_texture_path;
}