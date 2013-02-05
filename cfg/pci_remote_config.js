{		
	"http" : {
		"script_names" : [ "/", "/pci" ]
	},
	
	"service" : {
		"api" : "fastcgi" ,
		"socket" : "stdin"
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
		"default_skin" : [ "pci_skin" ]
	}
}
