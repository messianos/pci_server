
/*
----------------------------------------------------------------------------------------------
	Global variables/constants
----------------------------------------------------------------------------------------------
*/

var graphic_memory = new Object();

graphic_memory.toast = new Object();
graphic_memory.toast.separation = 8;
graphic_memory.toast.initial_offset = 64;
graphic_memory.toast.z_index = 1500;
graphic_memory.toast.current_offset = graphic_memory.toast.initial_offset;


/*
----------------------------------------------------------------------------------------------
	Toast functions
----------------------------------------------------------------------------------------------
*/

function showTooltip(element, placement, text) {
	element.addClass('graphic_tooltip');
	element.tooltip({
		placement: placement,
		title: text,
		trigger: 'manual',
		container: 'body'
	});

	element.tooltip('show');
}

function hideAllTooltips() {
	$('.graphic_tooltip').tooltip('destroy');
}

function showErrorToast(content) {
	var toast = $('<div class="graphic_toast">' + content + '</div>');
	toast.css({
		'background-color': '#CD1B1B',
		'border-top-color': '#F22020',
		'border-top-style': 'solid',
		'border-top-width': '1px',
		'box-shadow': '0px 15px 16px -16px #CACACA inset',
		'opacity': '0.86',
		'color': '#EEEEEE',
		'word-break': 'break-word',
		'max-width': '288px',
		'padding': '14px 20px 14px 16px',
		'position': 'fixed',
		'left': graphic_memory.toast.initial_offset,
		'z-index': graphic_memory.toast.z_index,
		'display': 'none'
	});
	
	configureToast(toast);
}

function showNotificationToast(content) {
	var toast = $('<div class="graphic_toast">' + content + '</div>');
	toast.css({
		'background-color': '#1A1A1A',
		'border-top-color': '#666666',
		'border-top-style': 'solid',
		'border-top-width': '1px',
		'box-shadow': '0px 15px 16px -16px #CACACA inset',
		'opacity': '0.86',
		'color': '#EEEEEE',
		'word-break': 'break-word',
		'max-width': '288px',
		'padding': '14px 20px 14px 16px',
		'position': 'fixed',
		'left': graphic_memory.toast.initial_offset,
		'z-index': graphic_memory.toast.z_index,
		'display': 'none'
	});
	
	configureToast(toast);
}


/*
----------------------------------------------------------------------------------------------
	Notification functions
----------------------------------------------------------------------------------------------
*/

function appendNotification(notification_container, url, message) {
	var notification = $('<a href="' + logic_memory.url.root + url + '">' + message + '</a><br />');
	notification_container.append(notification);
}


/*
----------------------------------------------------------------------------------------------
	Auxiliar functions
----------------------------------------------------------------------------------------------
*/

function getToastOffset(toast_height) {
	var offset = graphic_memory.toast.current_offset;
	graphic_memory.toast.current_offset += toast_height + graphic_memory.toast.separation;
	return offset;
}

function removeToast(toast) {
	var toast_offset = parseInt(toast.css('bottom'));
	var toast_height = toast.outerHeight();
	toast.remove();
	if (toast_offset + toast_height + graphic_memory.toast.separation == graphic_memory.toast.current_offset) {
		var max_offset = graphic_memory.toast.initial_offset;
		var highest_toast = null;
		$.each($('.graphic_toast'), function() {
			var offset = parseInt($(this).css('bottom'));
			if (offset > max_offset) {
				max_offset = offset;
				highest_toast = $(this);
			}
		});
		
		if (highest_toast != null)
			graphic_memory.toast.current_offset = max_offset + highest_toast.outerHeight() + graphic_memory.toast.separation;
		else
			graphic_memory.toast.current_offset = max_offset;
	}
}

function configureToast(toast) {
	var close_button = $('<a>X</a>');
	close_button.css({
		'background-color': '#1A1A1A',
		'border-color': '#DCDCDC',
		'border-radius': '16px',
		'border-style': 'solid',
		'border-width': '2px',
		'color': '#DCDCDC',
		'font-family': 'Arial',
		'font-size': '0.625em',
		'font-weight': 'bold',
		'text-decoration': 'none',
		'text-align': 'center',
		'line-height': '16px',
		'width': '16px',
		'height': '16px',
		'position': 'absolute',
		'right': '-4px',
		'top': '-4px',
		'cursor': 'pointer'
	});
	close_button.click(function() {
		toast.fadeOut({
			duration: 600,
			queue: false,
			complete: function() { removeToast(toast); }
		});
	});
	
	toast.append(close_button);
	$('body').append(toast);
	toast.css('bottom', getToastOffset(toast.outerHeight()));
	
	toast.fadeIn(2000);
	/*setTimeout(function() {
		toast.fadeOut({
			duration: 4000,
			complete: function() { removeToast(toast); }
		});
	}, 4000);*/ // TODO: Uncomment this
}