
/*

	Usage:

	var frame_dimensions = {
		width: 16,
		height: 16,
		top_side_height: 3,
		left_side_width: 3,
		right_side_width: 3,
		bottom_side_height: 3,
		padding: 16
	}

	var block_dimensions = {
		width: 32,
		height: 32,
		margin: 1
	};
	
	var color_set = new Array(
		'#983636',
		'#6DA5C8',
		'#BEC89B',
		'#8D7DC8',
		'#C8A899',
		'#27403D',
		'#0D3566',
		'#D6CDF4',
		'#F4B674',
		'transparent',
		'transparent',
		'transparent'
	);

	appendOrnamentFrame($('#container'), frame_dimensions, block_dimensions, color_set);

*/

function appendOrnamentFrame(container, frame_dimensions, block_dimensions, color_set) {
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
	appendOrnament(top_ornament, frame_width, frame_top_side_height, block_dimensions, color_set);
	
	var left_ornament = $('<div></div>');
	left_ornament.css('position', 'absolute');
	left_ornament.css('left', 0);
	left_ornament.css('top', top_side_pixels);
	appendOrnament(left_ornament, frame_left_side_width, frame_height - frame_top_side_height - frame_bottom_side_height, block_dimensions, color_set);
	
	var right_ornament = $('<div></div>');
	right_ornament.css('position', 'absolute');
	right_ornament.css('right', 0);
	right_ornament.css('top', top_side_pixels);
	appendOrnament(right_ornament, frame_right_side_width, frame_height - frame_top_side_height - frame_bottom_side_height, block_dimensions, color_set);
	
	var bottom_ornament = $('<div></div>');
	bottom_ornament.css('position', 'absolute');
	bottom_ornament.css('bottom', 0);
	bottom_ornament.css('left', 0);
	appendOrnament(bottom_ornament, frame_width, frame_bottom_side_height, block_dimensions, color_set);
	
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
}

function appendOrnament(container, width, height, block_dimensions, color_set) {
	var block_number = width * height;
	var block_colors = new Array(block_number);
	for (var i = 0; i < block_number; i++)
		block_colors[i] = color_set[Math.floor(Math.random() * color_set.length)];
	
	container.css('overflow', 'hidden');
	container.css('width', (block_dimensions.width + block_dimensions.margin * 2) * width);
	container.css('height', (block_dimensions.height + block_dimensions.margin * 2) * height);
	appendBlocks(container, width, height, block_dimensions, block_colors);
}

function appendBlocks(container, width, height, block_dimensions, block_colors) {
	for (var i = 0; i < height; i++) {
		var row = $('<div></div>');
		row.css('clear', 'both');
		
		for (var j = 0; j < width; j++) {
			var block = $('<div class="ornament_block"></div>');
			block.css('background-color', block_colors[i * width + j]);
			block.css('float', 'left');
			block.css('width', block_dimensions.width);
			block.css('height', block_dimensions.height);
			block.css('margin', block_dimensions.margin);
			row.append(block);
		}
		
		container.append(row);
	}
}
