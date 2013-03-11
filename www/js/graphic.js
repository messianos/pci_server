
/*

	Toast
		Temp
		Aux
			getToastOffset
			removeToast
			configureToast
		showErrorToast
		showNotificationToast

*/

var Toast = new Object();
Toast.Aux = new Object();
Toast.Temp = new Object();

Toast.Temp.separation = 8;
Toast.Temp.initial_offset = 64;
Toast.Temp.z_index = 1500;
Toast.Temp.current_offset = Toast.Temp.initial_offset;

Toast.Aux.getToastOffset = function(toast_height) {
	var offset = Toast.Temp.current_offset;
	Toast.Temp.current_offset += toast_height + Toast.Temp.separation;
	return offset;
}

Toast.Aux.removeToast = function(toast) {
	var toast_offset = parseInt(toast.css('bottom'));
	var toast_height = toast.outerHeight();
	toast.remove();
	if (toast_offset + toast_height + Toast.Temp.separation == Toast.Temp.current_offset) {
		var max_offset = Toast.Temp.initial_offset;
		var highest_toast = null;
		$.each($('.graphic_toast'), function() {
			var offset = parseInt($(this).css('bottom'));
			if (offset > max_offset) {
				max_offset = offset;
				highest_toast = $(this);
			}
		});
		
		if (highest_toast != null)
			Toast.Temp.current_offset = max_offset + highest_toast.outerHeight() + Toast.Temp.separation;
		else
			Toast.Temp.current_offset = max_offset;
	}
}

Toast.Aux.configureToast = function(toast) {
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
			complete: function() { Toast.Aux.removeToast(toast); }
		});
	});
	
	toast.append(close_button);
	$('body').append(toast);
	toast.css('bottom', Toast.Aux.getToastOffset(toast.outerHeight()));
	
	toast.fadeIn(2000);
	setTimeout(function() {
		toast.fadeOut({
			duration: 4000,
			complete: function() { Toast.Aux.removeToast(toast); }
		});
	}, 4000);
}

Toast.showErrorToast = function(content) {
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
		'left': Toast.Temp.initial_offset,
		'z-index': Toast.Temp.z_index,
		'display': 'none'
	});
	
	Toast.Aux.configureToast(toast);
}

Toast.showNotificationToast = function(content) {
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
		'left': Toast.Temp.initial_offset,
		'z-index': Toast.Temp.z_index,
		'display': 'none'
	});
	
	Toast.Aux.configureToast(toast);
}


/*

	Tooltip
		showTooltip
		hideAllTooltips

*/

var Tooltip = new Object();

Tooltip.showTooltip = function(element, placement, text) {
	element.addClass('graphic_tooltip');
	element.tooltip({
		placement: placement,
		title: text,
		trigger: 'manual',
		container: 'body'
	});

	element.tooltip('show');
}

Tooltip.hideAllTooltips = function() {
	$('.graphic_tooltip').tooltip('destroy');
}


/*

	Ornament
		Aux
			appendOrnamentBlocks
			appendOrnament
		appendErrorOrnament

*/

var Ornament = new Object();
Ornament.Aux = new Object();

Ornament.Aux.appendOrnamentBlocks = function(container, width, height, block_dimensions, block_decorations, block_colors) {
	for (var i = 0; i < height; i++) {
		var row = $('<div></div>');
		row.css('clear', 'both');

		for (var j = 0; j < width; j++) {
			var block = $('<div></div>');
			var color = block_colors[i * width + j];
			
			if (block_decorations != null && color != 'transparent')
				block.css(block_decorations);
				
			block.css('background-color', color);
			block.css('float', 'left');
			block.css('width', block_dimensions.width);
			block.css('height', block_dimensions.height);
			block.css('margin', block_dimensions.margin);
			
			row.append(block);
		}

		container.append(row);
	}
}

Ornament.Aux.appendOrnament = function(container, width, height, block_dimensions, block_decorations, color_set) {
	var block_number = width * height;
	var block_colors = new Array(block_number);
	for (var i = 0; i < block_number; i++)
		block_colors[i] = color_set[Math.floor(Math.random() * color_set.length)];

	container.css('overflow', 'hidden');
	container.css('width', (block_dimensions.width + block_dimensions.margin * 2) * width);
	container.css('height', (block_dimensions.height + block_dimensions.margin * 2) * height);
	Ornament.Aux.appendOrnamentBlocks(container, width, height, block_dimensions, block_decorations, block_colors);
}

/*Ornament.Aux.appendOrnamentFrame = function(container, frame_dimensions, block_dimensions, block_decorations, color_set) {
	var frame_width = frame_dimensions.width;
	var frame_height = frame_dimensions.height;
	var frame_top_side_height = frame_dimensions.top_side_height;
	var frame_left_side_width = frame_dimensions.left_side_width;
	var frame_right_side_width = frame_dimensions.right_side_width;
	var frame_bottom_side_height = frame_dimensions.bottom_side_height;
	var frame_padding = frame_dimensions.padding;
	var block_width = block_dimensions.width;
	var block_height = block_dimensions.height;
	var block_margin = block_dimensions.margin;

	var width_pixels = (block_width + block_margin * 2) * frame_width;
	var height_pixels = (block_height + block_margin * 2) * frame_height;
	var top_side_pixels = (block_height + block_margin * 2) * frame_top_side_height;
	var left_side_pixels = (block_width + block_margin * 2) * frame_left_side_width;
	var right_side_pixels = (block_width + block_margin * 2) * frame_right_side_width;
	var bottom_side_pixels = (block_height + block_margin * 2) * frame_bottom_side_height;

	var top_ornament = $('<div></div>');
	top_ornament.css('position', 'absolute');
	top_ornament.css('top', 0);
	top_ornament.css('left', 0);
	Ornament.appendOrnament(top_ornament, frame_width, frame_top_side_height, block_dimensions, block_decorations, color_set);

	var left_ornament = $('<div></div>');
	left_ornament.css('position', 'absolute');
	left_ornament.css('left', 0);
	left_ornament.css('top', top_side_pixels);
	Ornament.appendOrnament(left_ornament, frame_left_side_width, frame_height - frame_top_side_height - frame_bottom_side_height, block_dimensions, block_decorations, color_set);

	var right_ornament = $('<div></div>');
	right_ornament.css('position', 'absolute');
	right_ornament.css('right', 0);
	right_ornament.css('top', top_side_pixels);
	Ornament.appendOrnament(right_ornament, frame_right_side_width, frame_height - frame_top_side_height - frame_bottom_side_height, block_dimensions, block_decorations, color_set);

	var bottom_ornament = $('<div></div>');
	bottom_ornament.css('position', 'absolute');
	bottom_ornament.css('bottom', 0);
	bottom_ornament.css('left', 0);
	Ornament.appendOrnament(bottom_ornament, frame_width, frame_bottom_side_height, block_dimensions, block_decorations, color_set);

	container.css('position', 'relative');
	container.css('padding-top', top_side_pixels + frame_padding);
	container.css('padding-left', left_side_pixels + frame_padding);
	container.css('padding-right', right_side_pixels + frame_padding);
	container.css('padding-bottom', bottom_side_pixels + frame_padding);
	container.css('width', width_pixels - 2 * frame_padding - left_side_pixels - right_side_pixels);
	container.css('height', height_pixels - 2 * frame_padding - top_side_pixels - bottom_side_pixels);
	container.append(top_ornament);
	container.append(left_ornament);
	container.append(right_ornament);
	container.append(bottom_ornament);
}*/

Ornament.appendErrorOrnament = function(container) {
	var block_dimensions = {
		width: 32,
		height: 32,
		margin: 1
	};

	var color_set = new Array(
		'#983636',
		'#DD0000',
		'#EEAAAA',
		'#EE1313',
		'#EE5E5E',
		'transparent',
		'transparent',
		'transparent',
		'transparent'
	);

	Ornament.Aux.appendOrnament(container, 3, 12, block_dimensions, color_set);
}


/*

	Notification
		appendNotification

*/

var Notification = new Object();

Notification.appendNotification = function(container, url, message) {
	var notification = $('<a href="' + logic_memory.url.root + url + '">' + message + '</a><br />');
	container.append(notification);
}


/*

	Effect
	TODO

*/

var Effect = new Object();

Effect.configureActiveNavigationButton = function(button) {
	button.addClass('active');
}

Effect.configureSignInFormContainer = function(container, button) {
	button.click(function() {
		container.toggle();
		button.toggleClass('active'); // TODO: ?????
	});
}

Effect.configureTexteditor = function(textarea_name_or_id) {
	CKEDITOR.replace(textarea_name_or_id, {
		customConfig: '',
		extraPlugins: 'bbcode',
		fontSize_sizes: "10/100%; 12/120%; 14/140%; 16/160%; 18/180%; 20/200%",
		language: 'es',
		removePlugins: 'elementspath, colordialog',
		resize_enabled: false,
		skin: 'moono-dark',
		toolbar: [
			[ 'Undo', '-', 'Redo' ],
			[ 'FontSize' ],
			[ 'Bold', 'Italic', 'Underline', '-', 'TextColor' ],
			[ 'RemoveFormat' ],
			[ 'Link', '-', 'Unlink' ],
			[ 'NumberedList', 'BulletedList', '-', 'Blockquote' ]
		]
	});
}

Effect.configureDatepicker = function(textfield) {
	var current_year = new Date().getFullYear();
	textfield.datepicker({
		showOn:'focus',
		yearRange: (current_year - 100) + ':' + current_year,
		dateFormat:'dd/mm/yy',
		changeMonth:true,
		changeYear:true
	});
}









// TO ADD

function fly(){
	
	var flying_problem = $('#problem');

	/* hacks */
	var main_container = $(".main-container");
	main_container.position('relative');
	main_container.css('overflowX', 'hidden');

	/* save width and pos with static position */
	var pos = flying_problem.offset();
	var width = flying_problem.width();
	
	flying_problem.css('position', 'absolute');
	flying_problem.offset(pos);
    flying_problem.width(width);

	flying_problem.animate({
		left: "-1000px" 
		},
		1500, 
		function(){
			//$(this).css('left', '0px');

			/* Restore position and width */
			flying_problem.css('position', 'static');
			flying_problem.width('auto');
		}
	);
}
