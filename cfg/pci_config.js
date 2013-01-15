{	
	"file_server" : {
		"document_root" : "www",
		"enable": true
	},
	
	"http" : {
		"script_names" : [ "/", "/pci" ]
	},
	
	"service" : {
		"api" : "http",
		"port" : 8080
	},
	
	"views" : {
		"default_skin" : [ "test_skin" ]
	}
}