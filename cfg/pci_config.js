{	
	"file_server" : {
		"document_root" : "www",
		"enable": true
	},
	
	"http" : {
		"script_names" : [ "/", "/pci" ]
	},
	
	"service" : {
		"list" : [
		          { "api" : "http" , "port" : 8080, "ip" : "127.0.0.1" },
		          { "api" : "http" , "port" : 8000, "ip" : "192.168.1.6" }
		          ]
	},
	
	"session" : {
		"expire" : "browser",
		"timeout" : 100,
		"location" : "client",
		"client" : {
			"hmac" : "sha1",
			"hmac_key" : "3891bbf7f845fd4277008a63d72640fc13bb9a31"
		}    
	},
	
	"views" : {
		"default_skin" : [ "pci_skin" ]
	}
}