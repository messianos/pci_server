
/*

	Usage:

	octagon_information = {
		inner_length: 256,
		frame_width: 128,
		z_index: -10,
		color: '#FFFFFF'
	};

	border_information = {
		width: 2,
		color: '#D0D0D0'
	}
	
	appendBorderedOctagon($('#container'), octagon_information, border_information);

*/

function appendBorderedOctagon(container, octagon_information, border_information) {
	var octagon_inner_length = octagon_information.inner_length;
	var octagon_frame_width = octagon_information.frame_width;
	var octagon_z_index = octagon_information.z_index;
	var octagon_color = octagon_information.color;
	var border_width = border_information.width;
	var border_color = border_information.color;

	var content = container.html();
	container.empty();
	var inner_octagon = $('<div>' + content + '</div>');
	inner_octagon.css('position', 'relative');
	inner_octagon.css('left', -octagon_frame_width + border_width);
	inner_octagon.css('top', Math.floor(border_width / 2));
	container.append(inner_octagon);
	appendOctagon(inner_octagon, octagon_inner_length - border_width, octagon_frame_width - Math.floor(border_width / 2), octagon_z_index, octagon_color);
	appendOctagon(container, octagon_inner_length, octagon_frame_width, octagon_z_index - 1, border_color);
}

function appendOctagon(container, inner_length, frame_width, z_index, color) {
	
	var left_top_block = $('<div></diV>');
	left_top_block.css('border-bottom', frame_width + 'px solid ' + color);
	left_top_block.css('border-left', frame_width + 'px solid transparent');
	left_top_block.css('position', 'absolute');
	left_top_block.css('left', -frame_width);
	left_top_block.css('top', -frame_width);
	left_top_block.css('z-index', z_index);
	
	var top_block = $('<div></diV>');
	top_block.css('background-color', color);
	top_block.css('height', frame_width);
	top_block.css('position', 'absolute');
	top_block.css('width', inner_length);
	top_block.css('left', 0);
	top_block.css('top', -frame_width);
	top_block.css('z-index', z_index);
	
	var right_top_block = $('<div></diV>');
	right_top_block.css('border-bottom', frame_width + 'px solid ' + color);
	right_top_block.css('border-right', frame_width + 'px solid transparent');
	right_top_block.css('position', 'absolute');
	right_top_block.css('right', -frame_width);
	right_top_block.css('top', -frame_width);
	right_top_block.css('z-index', z_index);
	
	var left_block = $('<div></diV>');
	left_block.css('background-color', color);
	left_block.css('height', inner_length);
	left_block.css('position', 'absolute');
	left_block.css('width', frame_width);
	left_block.css('left', -frame_width);
	left_block.css('top', 0);
	left_block.css('z-index', z_index);
	
	var right_block = $('<div></diV>');
	right_block.css('background-color', color);
	right_block.css('height', inner_length);
	right_block.css('position', 'absolute');
	right_block.css('width', frame_width);
	right_block.css('right', -frame_width);
	right_block.css('top', 0);
	right_block.css('z-index', z_index);
	
	var left_bottom_block = $('<div></diV>');
	left_bottom_block.css('border-left', frame_width + 'px solid transparent');
	left_bottom_block.css('border-top', frame_width + 'px solid ' + color);
	left_bottom_block.css('position', 'absolute');
	left_bottom_block.css('bottom', -frame_width);
	left_bottom_block.css('left', -frame_width);
	left_bottom_block.css('z-index', z_index);
	
	var bottom_block = $('<div></diV>');
	bottom_block.css('background-color', color);
	bottom_block.css('height', frame_width);
	bottom_block.css('position', 'absolute');
	bottom_block.css('width', inner_length);
	bottom_block.css('bottom', -frame_width);
	bottom_block.css('left', 0);
	bottom_block.css('z-index', z_index);

	var right_bottom_block = $('<div></diV>');
	right_bottom_block.css('border-right', frame_width + 'px solid transparent');
	right_bottom_block.css('border-top', frame_width + 'px solid ' + color);
	right_bottom_block.css('position', 'absolute');
	right_bottom_block.css('bottom', -frame_width);
	right_bottom_block.css('right', -frame_width);
	right_bottom_block.css('z-index', z_index);
	
	container.css('background-color', color);
	container.css('height', inner_length);
	container.css('margin', frame_width);
	container.css('position', 'relative');
	container.css('width', inner_length);
	container.css('z-index', z_index);
	container.append(left_top_block);
	container.append(top_block);
	container.append(right_top_block);
	container.append(left_block);
	container.append(right_block);
	container.append(left_bottom_block);
	container.append(bottom_block);
	container.append(right_bottom_block);
}
