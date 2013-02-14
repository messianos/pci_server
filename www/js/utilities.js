
/*
----------------------------------------------------------------------------------------------
	Constants
----------------------------------------------------------------------------------------------
*/

var templateConstants = {
	/* Customizable ------------------------------------------------------- */
		activeClass: 'active',
		clickedClass: 'clicked',
		errorBoxClass: 'box_error',
		errorBoxOffset: 8,
		errorClass: 'error',
		selectedClass: 'selected',
		setClass: 'set',
	/* -------------------------------------------------------------------- */
	
	errorBoxIdSufix: '_error_box'
};


/*
----------------------------------------------------------------------------------------------
	Input elements
----------------------------------------------------------------------------------------------
*/

function configureClarificationTextarea(textareaId, answerButtonId, clarificationId) {
	var textarea = $('#' + textareaId);
	var answerButton = $('#' + answerButtonId);
	textarea.attr('valueSet', '0');
	textarea.attr('defaultHeight', textarea.height());
	answerButton.css('display', 'none');

	textarea.blur(function() {
		var textarea = $(this);
		if (textarea.val().length == 0) {
			textarea.val(textarea.prop('defaultValue'));
			textarea.removeClass(templateConstants.setClass);
			textarea.height(textarea.attr('defaultHeight'));
			answerButton.css('display', 'none');
		}
	});
	
	textarea.change(function() {
		var textarea = $(this);
		if (textarea.val().length == 0)
			textarea.attr('valueSet', '0');
		else
			textarea.attr('valueSet', '1');
	});
	
	textarea.focus(function() {
		var textarea = $(this);
		if (textarea.attr('valueSet') == '0') {
			textarea.val('');
			textarea.addClass(templateConstants.setClass);
			textarea.animate({
				height:textarea.attr('defaultHeight') * 2
			}, 50);
			answerButton.css('display', 'inline');
		}
	});
	
	answerButton.click({
		textarea: textarea,
		clarificationId: clarificationId
	}, function(event) {
		var request = $.ajax({
			data: {
				answer: event.data.textarea.val(),
				id: event.data.clarificationId
			},
			type:'POST',
			url:'/pci/new_clarification_answer'
		})
		
		request.done({
			textarea:event.data.textarea
		}, function() {
			var parent = textarea.parent();
			parent.empty();
			parent.addClass('box_content');
			parent.append($('<span class="text_clarification">' + textarea.val() + '</span>'));
		});
	});
}

function configureDatepicker(textfieldId) {
	$('#' + textfieldId).change(function() {
		$(this).addClass(templateConstants.setClass);
	});
	
	var currentYear = new Date().getFullYear();
	$('#' + textfieldId).datepicker({
		showOn:'focus',
		yearRange: (currentYear - 100) + ':' + currentYear,
		dateFormat:'dd-mm-yy',
		changeMonth:true,
		changeYear:true
	});
}

function configureDropdownlist(dropdownlistId) {
	var dropdownlist = $('#' + dropdownlistId);
	
	dropdownlist.blur(function() {
		var dropdownlist = $(this);
		if (dropdownlist.prop('selectedIndex') == 0)
			dropdownlist.removeClass(templateConstants.setClass);
	});
	
	dropdownlist.focus(function() {
		var dropdownlist = $(this);
		if (dropdownlist.prop('selectedIndex') == 0)
			dropdownlist.addClass(templateConstants.setClass);
	});
}

function configurePasswordfield(passwordfieldId) {
	var passwordfield = $('#' + passwordfieldId);
	var textfield = $('<input class="' + passwordfield.attr('class') + '" type="text" value="' + passwordfield.val() + '" />');
	passwordfield.prop('defaultValue', '');
	passwordfield.val('');
	textfield.insertAfter(passwordfield);
	passwordfield.detach();
	
	textfield.focus({
		passwordfield: passwordfield
	}, function(event) {
		var passwordfield = event.data.passwordfield; 
		var textfield = $(this);
		passwordfield.insertAfter(textfield);
		textfield.detach();
		passwordfield.addClass(templateConstants.setClass);
		passwordfield.trigger('focus');
	});
	
	passwordfield.blur({
		textfield: textfield
	}, function(event) {
		var passwordfield = $(this);
		var textfield = event.data.textfield;
		if (passwordfield.val().length == 0) {
			passwordfield.removeClass(templateConstants.setClass);
			textfield.insertAfter(passwordfield);
			textfield.attr('class', passwordfield.attr('class'));
			passwordfield.detach();
		}
	});
}

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

function configureTextfield(textfieldId) {
	var textfield = $('#' + textfieldId);
	textfield.attr('valueSet', '0');
	
	textfield.blur(function() {
		var textfield = $(this);
		if (textfield.val().length == 0) {
			textfield.val(textfield.prop('defaultValue'));
			textfield.removeClass(templateConstants.setClass);
		}
	});
	
	textfield.change(function() {
		var textfield = $(this);
		if (textfield.val().length == 0)
			textfield.attr('valueSet', '0');
		else
			textfield.attr('valueSet', '1');
	});
	
	textfield.focus(function() {
		var textfield = $(this);
		if (textfield.attr('valueSet') == '0') {
			textfield.val('');
			textfield.addClass(templateConstants.setClass);
		}
	});
}


/*
----------------------------------------------------------------------------------------------
	Navigation menu
----------------------------------------------------------------------------------------------
*/

function setActiveNavigationButton(buttonId) {
	$('#' + buttonId).addClass(templateConstants.activeClass);
}


/*
----------------------------------------------------------------------------------------------
	Sign in
----------------------------------------------------------------------------------------------
*/

function configureSignInFormContainer(containerId, buttonId) {
	$('#' + buttonId).click({
		containerId: containerId
	}, function(event) {
		$('#' + event.data.containerId).toggle();
		$(this).toggleClass(templateConstants.clickedClass);
	});
}


/*
----------------------------------------------------------------------------------------------
	Validation
----------------------------------------------------------------------------------------------
*/

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
	var errorBoxId = elementId + templateConstants.errorBoxIdSufix;
	if ($('#' + errorBoxId).length == 0) {
		var element = $('#' + elementId);
		var errorBox = $('<div>' + errorDescription + '</div>');
		errorBox.attr('id', errorBoxId);
		errorBox.css('position', 'absolute');
		var offset = element.offset();
		offset.left += element.outerWidth() + templateConstants.errorBoxOffset;
		errorBox.offset(offset);
		errorBox.addClass(templateConstants.errorBoxClass);
		element.addClass(templateConstants.errorClass);
		element.parent().append(errorBox);
	}
}

function hideErrorBox(elementId) {
	$('#' + elementId).removeClass(templateConstants.errorClass);
	$('#' + elementId + templateConstants.errorBoxIdSufix).remove();
}

function hideErrorBoxes() {
	$('.' + templateConstants.errorClass).removeClass(templateConstants.errorClass);
	$('div.' + templateConstants.errorBoxClass).remove();
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
