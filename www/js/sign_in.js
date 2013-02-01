
var headerBarConstants = {
	/* Customizable ------------------------------------------------------- */
			elementClickedClass: 'clicked'
	/* -------------------------------------------------------------------- */
};

function configureSignInFormContainer(containerId, buttonId) {
	$('#' + buttonId).click({
		containerId: containerId
	}, function(event) {
		showSignInFormContainer(event.data.containerId, $(this).attr('id'));
	});
}

function showSignInFormContainer(containerId, buttonId) {
	$('#' + containerId).toggle();
	$('#' + buttonId).toggleClass(headerBarConstants.elementClickedClass);
}
