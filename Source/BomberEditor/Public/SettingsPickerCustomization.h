// Copyright 2021 Yevhenii Selivanov.

#pragma once

#include "MyPropertyTypeCustomization.h"

/**
 * Is customized to show only selected in-game option.
 */
class FSettingsPickerCustomization final : public FMyPropertyTypeCustomization
{
public:
	/* ---------------------------------------------------
	*		Public functions
	* --------------------------------------------------- */

	/** The name of class to be customized. */
	static const FName PropertyClassName;

	/** Default constructor. */
	FSettingsPickerCustomization();

	/** Makes a new instance of this detail layout class for a specific detail view requesting it. */
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();

	/**
	* Called when the header of the property (the row in the details panel where the property is shown)
	* If nothing is added to the row, the header is not displayed
	* @param PropertyHandle Handle to the property being customized
	* @param HeaderRow	A row that widgets can be added to
	* @param CustomizationUtils Utilities for customization
	*/
	virtual void CustomizeHeader(TSharedRef<IPropertyHandle> PropertyHandle, FDetailWidgetRow& HeaderRow, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

	/**
	* Called when the children of the property should be customized or extra rows added.
	* @param PropertyHandle Handle to the property being customized
	* @param ChildBuilder A builder for adding children
	* @param CustomizationUtils Utilities for customization
	*/
	virtual void CustomizeChildren(TSharedRef<IPropertyHandle> PropertyHandle, IDetailChildrenBuilder& ChildBuilder, IPropertyTypeCustomizationUtils& CustomizationUtils) override;

protected:
	/* ---------------------------------------------------
	*		Protected properties
	* --------------------------------------------------- */

	/** Last chosen option. */
	FName CachedSettingsTypeInternal = NAME_None;

	/* ---------------------------------------------------
	*		Protected functions
	* --------------------------------------------------- */

	/** Is called for each property on building its row. */
	virtual void OnCustomizeChildren(IDetailChildrenBuilder& ChildBuilder, FPropertyData& PropertyData) override;

	/** Is called on adding the custom property.
	* @see FMyPropertyTypeCustomization::CustomPropertyNameInternal */
	virtual void AddCustomPropertyRow(const FText& PropertyDisplayText, IDetailChildrenBuilder& ChildBuilder) override;

	/** Is called when any child property is changed. */
	virtual void RefreshCustomProperty() override;

	/** Is called when is chosen new member from custom property. */
	void OnNewSettingsTypeChosen();
};
