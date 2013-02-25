/* From documentation */

function getLoginStatus() {
	var response = FB.getAuthResponse();
	return response;
}

function login() {
	FB.login(function(response) {
		if (response.authResponse) {
			// connected
		} else {
			// cancelled
		}
	});
}

function testAPI() {
	console.log('Welcome!  Fetching your information.... ');
	FB.api('/me', function(response) {
		console.log('Good to see you, ' + response.name + '.');
	});
}

function getFriends() {
	if (getLoginStatus())
		FB.api('/me/friends', function(response) {
			if (response.data) {
				$.each(response.data, function(index, friend) {
					console.log('name: ' + friend.name + ', id:' + friend.id);
				});
			} else {
				alert("Error!");
			}
		});
	else
		console.log('no user signed in');
}

function setProfilePicture(){
	FB.api('/me', function(response) {
		var id = response.id;
		$('#profile-picture').attr('src', 'https://graph.facebook.com/' + id + '/picture');
		$('#profile-picture').toggle();
	});
}

window.fbAsyncInit = function() {
	FB.init({
		appId : '256609674356889', // App ID
		channelUrl : '//WWW.YOUR_DOMAIN.COM/channel.html', // Channel File
		status : true, // check login status
		cookie : true, // enable cookies to allow the server to access the
		// session
		xfbml : true
	// parse XFBML
	});
	
};

$(document).ready(function(){
	if(getLoginStatus())
		setProfilePicture();
});