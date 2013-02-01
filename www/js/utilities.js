
/*
----------------------------------------------------------------------------------------------
	Input
----------------------------------------------------------------------------------------------
*/

var inputConstants = {
	/* Customizable ------------------------------------------------------- */
			elementFocusClass: 'focus',
			elementSelectedClass: 'selected',
			textfieldLabelClass: 'pci_label_textfield',
	/* -------------------------------------------------------------------- */
	
	labelIdSufix: '_label'
};

function configureTextfield(textfieldId, labelText) {
	var textfield = $('#' + textfieldId);
	var label = $('<label>' + labelText + '</label>');
	label.attr('id', textfieldId + inputConstants.labelIdSufix);
	label.attr('for', textfieldId);
	label.css('position', 'absolute');
	label.offset(textfield.offset());
	label.addClass(inputConstants.textfieldLabelClass);
	
	textfield.blur(function() {
		if ($(this).val().length == 0) {
			var label = $('#' + $(this).attr('id') + inputConstants.labelIdSufix);
			label.removeClass(inputConstants.elementFocusClass);
			label.css('display', 'inline');
		}
	});
	
	textfield.change(function() {
		if ($(this).val().length > 0)
			$('#' + $(this).attr('id') + inputConstants.labelIdSufix).css('display', 'none');
	});
	
	textfield.focus(function() {
		if ($(this).val().length == 0)
			$('#' + $(this).attr('id') + inputConstants.labelIdSufix).addClass(inputConstants.elementFocusClass);
	});
	
	textfield.keydown(function() {
		$('#' + $(this).attr('id') + inputConstants.labelIdSufix).css('display', 'none');
	});
	
	textfield.parent().prepend(label);
}

function configureDropdownlist(dropdownlistId) {
	$('#' + dropdownlistId).change(function() {
		if ($(this).prop('selectedIndex') > 0)
			$(this).addClass(inputConstants.elementSelectedClass);
		else
			$(this).removeClass(inputConstants.elementSelectedClass);
	});
}


/*
----------------------------------------------------------------------------------------------
	Datepicker
----------------------------------------------------------------------------------------------
*/

function configureDatepicker(elementId) {
	var currentYear = new Date().getFullYear();
	$('#' + elementId).datepicker({
		showOn:'focus',
		yearRange: (currentYear - 100) + ':' + currentYear,
		dateFormat:'dd-mm-yy',
		changeMonth:true,
		changeYear:true
	});
}


/*
----------------------------------------------------------------------------------------------
	Texteditor
----------------------------------------------------------------------------------------------
*/

function configureTexteditor(texteditorName) {
	CKEDITOR.replace(texteditorName, {
		customConfig: '',
		extraPlugins: 'bbcode',
		fontSize_sizes: "10/100%; 12/120%; 14/140%; 16/160%; 18/180%; 20/200%",
		language: 'es',
		removePlugins: 'elementspath, colordialog',
		resize_enabled: false,
		toolbar: [
			[ 'Undo', '-', 'Redo' ],
			[ 'FontSize' ],
			[ 'Bold', 'Italic', 'Underline', '-', 'TextColor' ],
			[ 'RemoveFormat' ],
			[ 'Link', '-', 'Unlink' ],
			[ 'NumberedList', 'BulletedList', '-', 'Blockquote' ]
		],
		uiColor: '#6CA4C8'
	});
}


/*
----------------------------------------------------------------------------------------------
	Validation
----------------------------------------------------------------------------------------------
*/

var validationConstants = {
	/* Customizable ------------------------------------------------------- */
			elementErrorClass: 'error',
			errorBoxClass: 'pci_box_error',
			errorBoxOffset: 8,
	/* -------------------------------------------------------------------- */
	
	errorBoxIdSufix: '_error_box'
};

function configureValidator(elementInfoArray) {
	var length = elementInfoArray.length;
	for (var i = 0; i < length; i++) {
		var elementInfo = elementInfoArray[i];
		$('#' + elementInfo.elementId).change({
			onChangeFunction: elementInfo.onChangeFunction
		}, function(event) {
			event.data.onChangeFunction($(this));
		});
	}
}

function showErrorBox(elementId, errorDescription) {
	var errorBoxId = elementId + validationConstants.errorBoxIdSufix;
	if ($('#' + errorBoxId).length == 0) {
		var element = $('#' + elementId);
		var errorBox = $('<div>' + errorDescription + '</div>');
		errorBox.attr('id', errorBoxId);
		errorBox.css('position', 'absolute');
		var offset = element.offset();
		offset.left += element.outerWidth() + validationConstants.errorBoxOffset;
		errorBox.offset(offset);
		errorBox.addClass(validationConstants.errorBoxClass);
		element.addClass(validationConstants.elementErrorClass);
		element.parent().append(errorBox);
	}
}

function hideErrorBox(elementId) {
	$('#' + elementId).removeClass(validationConstants.elementErrorClass);
	$('#' + elementId + validationConstants.errorBoxIdSufix).remove();
}

function hideErrorBoxes() {
	$('.' + validationConstants.elementErrorClass).removeClass(validationConstants.elementErrorClass);
	$('div.' + validationConstants.errorBoxClass).remove();
}

function validateMaxLength(text, maxLength) {
	return text.length <= maxLength;
}

function validateMinLength(text, minLength) {
	return text.length >= minLength;
}

function validateRegExp(text, regExp) {
	return text.match(regExp) != null;
}
