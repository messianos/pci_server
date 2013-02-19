
function showErrorFloatingBox(input_element, error_description) {
	// TODO
	alert(input_element.val() + ' - Descripcion del error: ' + error_description);
}

function showErrorLateralBox(error_description) {
	$('div.dialog_error_report').animate({
		left: -$(this).outerWidth() - 16
	}, 800, function() {
		$(this).remove();
	});
	
	var dialog = $('<div class="dialog_error_report"></div>');
	dialog.css('background-color', '#FF0000');
	dialog.css('border-bottom-right-radius', '12px');
	dialog.css('border-top-right-radius', '12px');
	dialog.css('box-shadow', '1px 1px 3px 0px #555555');
	dialog.css('max-width', '448px');
	dialog.css('opacity', '0.95');
	dialog.css('padding', '8px 8px 8px 0px');
	dialog.css('position', 'fixed');
	dialog.hover(function() {
		$(this).animate({
			opacity: 1
		}, {
			duration: 300,
			queue: false
		});
	}, function() {
		$(this).animate({
			opacity: 0.95
		}, {
			duration: 500,
			queue: false
		});
	});
	
	var close_button = $('<a>X</a>');
	close_button.css('background-color', '#111111');
	close_button.css('border-color', '#E0E0E0');
	close_button.css('border-radius', '28px');
	close_button.css('border-style', 'solid');
	close_button.css('border-width', '2px');
	close_button.css('color', '#D2D2D2');
	close_button.css('cursor', 'pointer');
	close_button.css('font-family', 'Arial');
	close_button.css('font-weight', 'bold');
	close_button.css('height', '28px');
	close_button.css('line-height', '28px');
	close_button.css('position', 'absolute');
	close_button.css('right', '-7px');
	close_button.css('text-align', 'center');
	close_button.css('text-decoration', 'none');
	close_button.css('top', '-7px');
	close_button.css('width', '28px');
	close_button.click({
		dialog: dialog
	}, function(event) {
		dialog.animate({
			left: -dialog.outerWidth() - 16
		}, 800, function() {
			dialog.remove();
		});
	});
	
	var container = $('<div><h3>Se ha producido un error</h3><p>' + error_description + '</p></div>');
	container.css('background-color', '#F84444');
	container.css('border-color', '#E0E0E0');
	container.css('border-top-right-radius', '8px');
	container.css('border-bottom-right-radius', '8px');
	container.css('border-style', 'solid');
	container.css('border-width', '1px 1px 1px 0px');
	container.css('color', '#FFFFFF');
	container.css('font-family', 'Lucida Console');
	container.css('letter-spacing', '0.0625em');
	container.css('padding', '8px 24px 8px 64px');
	container.css('text-shadow', '0px 0px 0.125em #000000');
	container.css('word-break', 'break-word');
	
	dialog.append(close_button);
	dialog.append(container);
	$('body').append(dialog);
	
	dialog.css('bottom', '64px');
	dialog.css('left', -dialog.outerWidth()) - 16;
	dialog.animate({
		left: 0
	}, {
		duration: 1000, queue: false
	});
}

function showToast(message) {
	// TODO
	//alert(message);
	
	var close_button = $('<a>X</a>');
	close_button.css('background-color', '#111111');
	close_button.css('border-color', '#E0E0E0');
	close_button.css('border-radius', '28px');
	close_button.css('border-style', 'solid');
	close_button.css('border-width', '2px');
	close_button.css('color', '#D2D2D2');
	close_button.css('cursor', 'pointer');
	close_button.css('font-family', 'Arial');
	close_button.css('font-weight', 'bold');
	close_button.css('height', '28px');
	close_button.css('line-height', '28px');
	close_button.css('position', 'absolute');
	close_button.css('right', '-7px');
	close_button.css('text-align', 'center');
	close_button.css('text-decoration', 'none');
	close_button.css('top', '-7px');
	close_button.css('width', '28px');
	close_button.click({
		toast: toast
	}, function(event) {
		toast.animate({
			left: -toast.outerWidth() - 16
		}, 800, function() {
			toast.remove();
		});
	});
	
	var container = $('<div>' + message + '</div>');
	container.css('background-color', '#F84444');
	container.css('border-color', '#E0E0E0');
	container.css('border-top-right-radius', '8px');
	container.css('border-bottom-right-radius', '8px');
	container.css('border-style', 'solid');
	container.css('border-width', '1px 1px 1px 0px');
	container.css('color', '#FFFFFF');
	container.css('font-family', 'Lucida Console');
	container.css('letter-spacing', '0.0625em');
	container.css('padding', '8px 24px 8px 64px');
	container.css('text-shadow', '0px 0px 0.125em #000000');
	container.css('word-break', 'break-word');
	
	var toast = $('<div></div>');
	toast.css('background-color', '#FF0000');
	toast.css('border-radius', '12px');
	toast.css('box-shadow', '1px 1px 3px 0px #555555');
	toast.css('left', 0);
	toast.css('max-width', '448px');
	toast.css('opacity', '0.95');
	toast.css('padding', '8px 8px 8px 0px');
	toast.css('position', 'fixed');
	toast.css('top', 0);
	toast.css('z-index', 1500);
	toast.append(close_button);
	toast.append(container);
	$('body').append(toast);
}
