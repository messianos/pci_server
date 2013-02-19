{	
	"file_server" : {
		"document_root" : "www",
		"enable": true
	},
	
	"http" : {
		"script_names" : [ "/", "/pci" ]
	},
	
	"logging" : {
		"level" : "error" // Default
	},
	
	"service" : {
		"api" : "http" ,
		"port" : 8080,
		"ip" : "127.0.0.1"
	},
	
	"session" : {
		"expire" : "browser",
		"timeout" : 500,
		"location" : "client",
		"client" : {
			"hmac" : "sha1",
			"hmac_key" : "3891bbf7f845fd4277008a63d72640fc13bb9a31"
		}    
	},
	
	"views" : {
		"paths" : [ "lib" ],
		"skins" : [ "pci_skin" ],
		"default_skin" : [ "pci_skin" ],
		"auto_reload" : true
		// The application auto reloads the libraries so it isn't necesary
		// to restart the server to test templates.
		// TODO: Slows down the application performance.
	}
}