Action()
{

	web_set_sockets_option("SSL_VERSION", "2&3");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("DNT", 
		"1");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("WebTours", 
		"URL=http://localhost:1080/WebTours", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	/*Possible OAUTH authorization was detected. It is recommended to correlate the authorization parameters.*/

	web_add_cookie("mbac=5b8d4aa9-502d-4e36-bcf9-4f8d0bfcdde3; DOMAIN=gatpsstat.com");

	web_add_header("Origin", 
		"chrome-extension://mbacbcfdfaapbcnlnbmciiaakomhkbkb");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_custom_request("stat", 
		"URL=https://gatpsstat.com/ext/stat", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=1", 
		"RecContentType=image/gif", 
		"Referer=", 
		"Snapshot=t2.inf", 
		"EncType=text/plain;charset=UTF-8", 
		"Body=eyJpZCI6Im1iYWNiY2ZkZmFhcGJjbmxuYm1jaWlhYWtvbWhrYmtiIiwiYmFja2dyb3VuZCI6eyJwYWdlIjoiYmFja2dyb3VuZC5odG1sIiwicGVyc2lzdGVudCI6dHJ1ZX0sImJyb3dzZXJfYWN0aW9uIjp7ImRlZmF1bHRfaWNvbiI6ImltLzM4Zy5wbmciLCJkZWZhdWx0X3RpdGxlIjoiZnJpR2F0ZSAtINCy0LrQuy/"
		"QstGL0LrQuyJ9LCJjb250ZW50X3NjcmlwdHMiOlt7ImNzcyI6WyJjc3MvaW5qMi5jc3MiXSwianMiOlsibGliL01vb1Rvb2xzLUNvcmUtMS42LjAtY29tcHJlc3NlZC5qcyIsImpzL3MyLmpzIl0sIm1hdGNoZXMiOlsiaHR0cDovLyovKiIsImh0dHBzOi8vKi8qIl0sInJ1bl9hdCI6ImRvY3VtZW50X3N0YXJ0In0seyJqcyI6WyJzaS5qcyJdLCJtYXRjaGVzIjpbIjxhbGxfdXJscz4iXSwicnVuX2F0IjoiZG9jdW1lbnRfZW5kIn0seyJhbGxfZnJhbWVzIjp0cnVlLCJqcyI6WyJqcy9wcm9maWxlci5qcyJdLCJtYXRjaF9hYm91dF9ibGFuayI6dHJ1ZSwibWF0Y2hlcyI6WyI8YWxsX3VybHM+"
		"Il0sInJ1bl9hdCI6ImRvY3VtZW50X3N0YXJ0In0seyJqcyI6WyJqcy90Yi5qcyJdLCJtYXRjaGVzIjpbIio6Ly8qLm96b24udHJhdmVsLyoiLCIqOi8vKi5vbmV0d290cmlwLmNvbS8qIiwiKjovLyouYWVyb2Zsb3QucnUvKiIsIio6Ly8qLmFueXdheWFueWRheS5jb20vKiIsIio6Ly8qLnN2eWF6bm95LnRyYXZlbC8qIiwiKjovL2F2aWEudGlja2V0cy5ydS8qIiwiKjovLyouczcucnUvKiIsIio6Ly8qLmt1cGliaWxldC5ydS8qIiwiKjovLyoudHJpcC5ydS8qIiwiKjovLyouc2luZGJhZC5ydS8qIiwiKjovLyouYXZpYWthc3NhLnJ1LyoiLCIqOi8vKi5iaWxldGl4LnJ1LyoiLCIqOi8vKi51dGFpci5ydS8qIiwiKjovLyoub3JiaXR6LmNvbS8qIiwiKjovLyoudH"
		"JhdmVsb2NpdHkuY29tLyoiLCIqOi8vKi5leHBlZGlhLmNvbS8qIiwiKjovLyoucHJpY2VsaW5lLmNvbS8qIiwiKjovL2Jvb2tpbmcuYWlyYXNpYS5jb20vKiIsIio6Ly8qLnJ5YW5haXIuY29tLyoiLCIqOi8vKi5ob3RlbHMuY29tLyoiLCIqOi8vKi5vc3Ryb3Zvay5ydS8qIiwiKjovLyoudHJhdmVsLnJ1LyoiLCIqOi8vKi5va3RvZ28ucnUvKiIsIio6Ly8qLnJvb21ndXJ1LnJ1LyoiLCIqOi8vKi50cmlwYWR2aXNvci5ydS8qIiwiKjovLyouaGlsdG9uLnJ1LyoiLCIqOi8vKi5oaWx0b24uY29tLyoiLCIqOi8vKi5tYXJyaW90dC5jb20vKiIsIio6Ly8qLmhvc3RlbHdvcmxkLmNvbS8qIiwiKjovLyoudGlrZXQuY29tLyoiLCIqOi8vKi5ob3RlbHNjbGljay5jb20v"
		"KiIsIio6Ly8qLmhvdGVsc2NvbWJpbmVkLmNvbS8qIiwiKjovLyoud2l6emFpci5jb20vKiIsIio6Ly8qLmVtaXJhdGVzLmNvbS8qIiwiKjovLyouZGVsdGEuY29tLyoiLCIqOi8vKi5idWRnZXQuY29tLyoiLCIqOi8vKi5oZXJ0ei5jb20vKiIsIio6Ly8qLmV1cm9wY2FyLmNvbS8qIl0sInJ1bl9hdCI6ImRvY3VtZW50X2VuZCJ9LHsianMiOlsianMvY29udGVudC5qcyJdLCJtYXRjaGVzIjpbIio6Ly8qLmFsaWV4cHJlc3MuY29tLyoiXSwicnVuX2F0IjoiZG9jdW1lbnRfZW5kIn0seyJpbmNsdWRlX2dsb2JzIjpbIio6Ly8qLnNreXNjYW5uZXIuKi8qIiwiKjovLyoubW9tb25kby4qLyoiLCIqOi8vKi5rYXlhay4qLyoiLCIqOi8vKi5ib29raW5nLiovKiIsIio6Ly"
		"8qLmFnb2RhLiovKiIsIio6Ly8qLmF2aXMuKi8qIl0sImpzIjpbImpzL3RiLmpzIl0sIm1hdGNoZXMiOlsiPGFsbF91cmxzPiJdLCJydW5fYXQiOiJkb2N1bWVudF9lbmQifV0sImNvbnRlbnRfc2VjdXJpdHlfcG9saWN5Ijoic2NyaXB0LXNyYyAnc2VsZicgJ3Vuc2FmZS1ldmFsJzsgb2JqZWN0LXNyYyAnc2VsZiciLCJjdXJyZW50X2xvY2FsZSI6InJ1IiwiZGVmYXVsdF9sb2NhbGUiOiJlbiIsImRlc2NyaXB0aW9uIjoi0J/QvtC30LLQvtC70Y/QtdGCINC/0L7Qu9GD0YfQuNGC0Ywg0YPQu9GD0YfRiNC10L3QvdGL0Lkg0LTQvtGB0YLRg9C/"
		"INC6INGB0LDQudGC0LDQvC4iLCJpY29ucyI6eyI2NCI6ImltLzY0LnBuZyIsIjEyOCI6ImltLzEyOC5wbmcifSwia2V5IjoiTUlHZk1BMEdDU3FHU0liM0RRRUJBUVVBQTRHTkFEQ0JpUUtCZ1FERVVqOUlha3VHdmFldG5xOFhVNVBDSU1XNTJqN0Zhd3VSQjNqY1Fib3hhRjdSa3lreEpoSllLckV5eDFZcEFjUmlxYk5VTTdPQlprQ1FCWFNxbnVOZC8wU0VUMTZaZmVKSmNiS1grMHdTbERnOVZkc0tmM0NpZkRtZ0laV2VlbGZxN0V4MnpCNmRzaXl2blRyd0l6SDV3dXNXWHFubUlqUzRJODlsc3RZcTZRSURBUUFCIiwibWFuaWZlc3RfdmVyc2lvbiI6MiwibWluaW11bV9jaHJvbWVfdmVyc2lvbiI6IjM2IiwibmFtZSI6ImZyaUdhdGUgQ0ROIC0g0LHQtdGB0L/"
		"QtdGA0LXQsdC+0LnQvdGL0Lkg0LTQvtGB0YLRg9C/"
		"INC6INGB0LDQudGC0LDQvCIsIm9wdGlvbnNfcGFnZSI6Im9wdGlvbnMuaHRtbCIsInBlcm1pc3Npb25zIjpbImlkbGUiLCJjb29raWVzIiwid2ViTmF2aWdhdGlvbiIsIndlYlJlcXVlc3QiLCJ3ZWJSZXF1ZXN0QmxvY2tpbmciLCJ1bmxpbWl0ZWRTdG9yYWdlIiwidGFicyIsInByb3h5IiwiYnJvd3NpbmdEYXRhIiwic3RvcmFnZSIsIjxhbGxfdXJscz4iXSwic2hvcnRfbmFtZSI6ImZyaUdhdGUgQ0ROIiwidXBkYXRlX3VybCI6Imh0dHBzOi8vY2xpZW50czIuZ29vZ2xlLmNvbS9zZXJ2aWNlL3VwZGF0ZTIvY3J4IiwidmVyc2lvbiI6IjIuMS4yMDMiLCJ3ZWJfYWNjZXNzaWJsZV9yZXNvdXJjZXMiOlsiaW0vKi5wbmciLCJpbS8qLmdpZiIsImxpYi8qLmpzIl19", 
		LAST);

	web_add_header("Origin", 
		"null");

	lr_think_time(5);

	web_custom_request("def", 
		"URL=https://gatpsstat.com/ext/def?hk=XfgceCdD", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=application/octet-stream", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		"EncType=", 
		"BodyBinary=\\x1C\\xDA\t\\xD3\\xE6\\xDA\\x9B\\x14K\\xB1\\xB7\\x84\\x80I\\xC9\\x8A\\xE99\\xCC\\xBB\\xF63K\\x01\"z2K(\\xFDfN}\\x8E\\xB5\\xB0\\x0F(\\xAFS\\xD0 \\xC2~\\x11\\x07Q\\xD3\\x1B\\xDD\\xF7S\\x94\\xD1-\\xA1\\xE7\\xCDK\\xC4pAt\"+\\x117W\\x19\\xCD\\x96W~\\x95D\\xCFR<\"\\x93\\x9F\\xB6\\x93s \\x10m\\xD7\\xB5+\\xF3\\xA2\\x10\\xC7\\x11\\x95,\\xF8)\\xEC\\xFDx\\x8DY\\xA3\\x7Fnh\r\\x84\\x85\\xD9\\x93\\xB2d\\xFF23\\xAD\\xEB\\xE3\\x19*1\\x10$[\\x97\\xB6G\\x98\\x9C\\xB5\\xB6O\\xD9  "
		"\\x13\\xFF\\xB9d\\xB5LTZ\\xCF\\xB0[3\\xC3\\xA6*\\xFB.\\xDF\\xD7<F]o\\xF0\\x7F\\xECD\\xF1\\x00/d\tic}\\xB0\\x95c\\xB9u\\\\xF8\\xED\\x12\\x1E\\xFE\\x91\\xD4\\xE3<\\xCA\\xC5\\x86ED\\x14ix\\xE0e_\\xB3\\x16\\\\xC6\\xE02\\xE6\\x7FT\\xFBf\\x06\\x04\\xAD\\x96\\x88\\x82Q\\xEB\\x85\\x13\\xEB\\x17<\\x1C`# \\x04\\x87\\xFBa\\xF9\\xA9'\\xD5\\x12\\xEC\\x9C\\xDA\\x98\\xE6\\\\xD6\\xA9\\x15p\\xD0\\xFA.\\xB8\\xBC\\xA8\\x97hk\\x14\\xB9\\x90\\x050b]\\xFDf\\xDDB\\xF2\\xB5/"
		"\\x87\\x06\\xB5\\x0FA\\xD4\\xC7\\xF9\\xB52X\\xF2\\xD8\\xA8\\x07W\\xA3O(\\xAC\\xD3{/\\x11\\xA2&4!,\\xBF\\xA7Y\\xF3Rc\\xA1\\x94n\\xA6SL\\xC6\\xA6\\xBCu9\\xA3ud\\xC0NZ\\xF0\\xF0At`\r\\xB1\\xCB\\xE8\\xF5\\xF2?#EE/O{(\\xF2\\x19\\xCD\\xA5\\x92\\x05N\\x08uI\\xAF\\xFBj+}\\xF8\\xBC\\xF1\\x190\\xE5\\xA6s:\\x15h=\\xFC\\xA8\\x9E\\xB8\\xF6z\\x88\\x03\\x84;\\xA4\\x05\\xDE\\x1B\\xEA\\x13H\\xEF\\x9C\n\\xB6\\xFF}\\xDA?|\\xBE\\x0B&FA\\xFB\\xAA\\xDD\\xA6\\xFF{\\xC5HR\\x99\\xAC\\x85[\\x07"
		"{1\\xE6\\x1D\\x81\\xD5GU74\\x16\\x87\\x1E\\xBFu,\\xED\\xA8\\xCC\t\\xF1\\x8E\\x14\\xE4\\xF5]U\\x9F\\x82n3F6`\\xD645-\\xB6\\xEAH9~\\xBAX\\xFF=\\xE5xz\\x83.\\xDDkM\\xB9d\\xBAH\\x9C\\xB2\\xD4H\\x81\\x163\\xF5\"U\\xF3\\x076*\\xD1\\xDF\\xBF\\xBE[\\x80\\x9Ev\\xD5\\xD7I$U\\xD5\\x0Bd\"\\x17\\xA5\\xB4\\xDD\\xA9*\\x86j\\xE6\\xA68\\xD4\\x19\\xE6\\xC1\\xA5^\\xD7\\x96\\xAE\r\\xD0\\xE00\\x0B\\x8D\\x86|{8\\xA1\\x886\\x86\\x05n\\x96\\x1F", 
		LAST);

	web_add_auto_header("Origin", 
		"chrome-extension://mbacbcfdfaapbcnlnbmciiaakomhkbkb");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(23);

	web_submit_data("api3.friproxy0.eu:80", 
		"Action=https://api3.friproxy0.eu:80/?1600108222037&kf2uzwmm", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=new", "Value=1", ENDITEM, 
		"Name=k", "Value=G3pjnxV7XOQScnzQ", ENDITEM, 
		"Name=t", "Value=0", ENDITEM, 
		"Name=s", "Value=0", ENDITEM, 
		"Name=ip", "Value=", ENDITEM, 
		"Name=po", "Value=0", ENDITEM, 
		"Name=pu", "Value=1", ENDITEM, 
		LAST);

	web_submit_data("r", 
		"Action=https://api3.friproxy0.eu:80/r?1600108224316&kf2uzwmn", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=k", "Value=G3pjnxV7XOQScnzQ", ENDITEM, 
		"Name=s", "Value=09fbb5240aeefb6a9a02418ffc9b440e", ENDITEM, 
		LAST);

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Origin", 
		"null");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	lr_think_time(135);

	web_custom_request("beacon", 
		"URL=https://gatpsstat.com/ext/beacon?hk=CNKAMhRU", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		"EncType=", 
		"BodyBinary=\\xA1<\\x83\\x8C\\xE2z\\xBA\\xD3|N3\\xA5\\x9B\\xB0\\xC2\t\\x99a\\xE29jf\\xA1\\xAA\\xD8\\x0C\\xBB\\x15\\x98\\xFC\\xBBc\\x14\\xF7\\x1F\\xAE\\x07\\xE6PNU\\xEA\\xE7\\xECwHh\\xA3W\\x01 '\\xC5#\\xA4X%\\x17Y\\xD7<\\xB6J\\xDD\\x11\\xC7\\x81\\xD8t\\xAD2\\xF2P\\xDCdG\\xBD\\x07v\\xCD\\xED\\x81G8\\xD2\\x12-\\x82\\x8D\\x9D\\x13\\xBB}l;>\\x15\\xA8\\xB6+\\xC2B\rQ,*\\xDEh\\xCE*\tM\\xF0\\x95PWIR):\\x0C3\\x90\\x82\\xF5\\xD17\\xDC!\\x1E\\xB5\\x88\\xBA\\x05\\x84\\xE3\\xE7\\x19*<,\\xDE\\xD1\\xF0.p\""
		"uEn\\xF7.\\xDE\\xC6n\\xB4\\xD5\\xDB8:\\x07L\\xA8fl\\xDF)\\xD1:\\x85\\xCD\\xB8\\xC1\\x0C\\x99\\xEDD\\xB2\\x9B\\x89^p\rhd\\xD2\\x9C\\x8D\\xE4\\xB9\\x11\\xCB\\xC0t4\\xCB\\x1C\\xA8\\xE8>\\x1D\\xB8I\\xB4\\xF2.\\x14\\xDB<\\xF0#\\xB6\\xF7Z\\xF9L\\xA5!1\\x18\\xB4B\\xA0=\\x9D\\xA6C\\xE2\\xDD\\xE9\\x03G+\\xF5\\x99\\x8E\\x1B\\xA3(ygx\\xA5;1\\xF73:~\\xFC\\x05\\xAC\\x94X\\xB7/An\\x1D\\xDE\\xE9\\x9F\\x05\\x8C&i\\x9B2F\\xB5\\xCD\\x82(\\xC3\\x08\\xBA\\xF1k\\xFE5\\xDB\\x17Iz\\x8ErZl^\\xBE\\x8F\\x9A\\xAA?"
		"\\xEC\\xCD.\\x92\\xEC\\x8D\\xB5\\xF5\\x1F\\xB8\\x96)\\xBA\\xA8\\xA6\\x0Bx\\x1E\\xB6\\x9D\\xDD\\x878\\xF6\\xCF\\x9C\\x1C\\xD4E\\x7FAv\\xCF\\x93\\x8A\\xCC\\xC5Y\\xD4\"\\xA1\\x91T\rp\\xBF\\xD4\\xF3/\\x04\\xE5o\\x8B|H\\x7F%\\x8B\\x05\\x12|\\xC3/D\\x1E{\\xB5D\\xEE\\xEEhz\\xB6\\xF1\\x16\\xD6\\xC2.G\\xB1\\x11\\xCC\\xBD\\x87\\xDBO)%\\xF0\\xC5\\x8B.Z\\xCBU\\xF4m\\x81^m\\x070B9\\xFF\\x11\\xE1XI\\x9B<D\\x9ER 0\\x04\\xC9\\xE6\\x00>\\x8B\\xFF\\x9EfS\\xE8\\x12\\xAE\\x0F-`\\xC9\\xF6 A\\x9B\\xA6\\x08\\xD9"
		"<\\x17\\xEEZ\\xE92\\xBF^v.\\xF5\\xFD\\x90\\x05\\xAEe7\\xF0t\\xA1U\\x13\\xCB\\xB3j\\x86\\x92\\x00\\x94\\xAA\te\\x149\\x14S\\xBB\\x02Sm*\\x9A\\xD5\\xC78\\x8E\\xD3\\xC3&3B\\xB1\\x10\\xA9=*\\xDB'\\x052Ra\\xAE\\xD9n\r?Hm~\\x8A\\xDF\\xB0\\x92u(\\xDC#J`\\x9F\\xEDm{\\xD4\\xB5\\x00\\xEE\\x9B\\xF1\\xB4F\\xBA\\x8D\\xD9\\xAA$\\xF1X\\xBA\\xB1\\x10_D2\\xE1\\xE6\\x90e\\x81U\\x94\\xCBh\\x180\\x91>2H9{\\xF5\\xFC\\x80\\xF5\\xA8>\\xFEA{\\x98\\xC6\\x91\\x0F.S\\xC0\\x9B\\xCC\\x02\\x820\\xF5\\x8A\\xFB", 
		LAST);

	lr_think_time(5);

	web_custom_request("beacon_2", 
		"URL=https://gatpsstat.com/ext/beacon?hk=bcMIytnt", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		"EncType=", 
		"BodyBinary=\\xD4\\xF2\\xB5\\xB8\\xF6\\xBF\\x8E\\xC7s\\xF9\\xFD\\xA8-;+\\xF6\\x86\\xB14\\!\\s*\\xC5Gcel\\xDA\\xD9\\xD1a\\xC7\\x0B\\x1E\\xB2~\\x90\\x85\\x95CzM\\xE4\\x83@z\\xA1\\x917^n\\x87\\xE0\\xBC\\x0BS\n^\\xAE\t\\xC0\\x9E\\xD8\\x04\\xF6N!`\\xBA\\xD6\\xAF\\xA9F\\xB8\\x02{2Be\\x9By\"\\xE4\\x89\\xBC&\\xC7\\xBE+"
		"nF\\x07\\xC0\\xE7\\xBE@\\xEBX\\x15fD\\xF2\\x9D\\x9As\\xB5iv\\xA7H\\x89\\x06\\xB9\\xEC\\xDC\\xAB\\xCD\\x90N\\xB2\\xDFK\\xC1\\xA6C\\xE7G\\x16\\x86\\x9F\\xF2\\x86\\xD8\\xBC\\x17\\xCF\\xA6Z\\x18\\x02\\xD0l\\xB7qs\\x8D\\xE5~g\\x15\\xFE\\xCF\\xC2\\x0B\\xA6@U\\x9B\\xCC\\xAD.\\xCC\\xC1\\xE5\\xE6X\\x03\\xAC\\xFF\\x02v\\xDC\\x04\\xDA\\xDE\\x91~a\\x11iD\\x92\\xFA\"\\x95\\x7Fq\\xE5B\\x89&\\xAB\\x1D\\xA0\\xCA\\xA5!\\x00\\xD3mTm-]u(\\xF1\\x9F\\x86\\x9D\\xDF\\x93lG)rI\\x93\\xD6E.F\\xA1\\xD4~"
		"y\\x1CY2\\x8C\\xFF\\xB2\\xFFu\\xE1=K\\x1A\\xB1\\xE4\\x19\\x01\\xFC\\xEE\\xDB\\x88\\xBA\\xEA\\xE39(\\xADj\\xD9\\xC7K\\xD3\\xB7\\xA1\\x8FU\\xBE\\\\xEB\\xB2\\xB9*_\\xEA\\xC5\\xCB=\\xE3\\x8D+\\x84$>0\\xCC\\x9B:\\x1C)\\xFD\\x95\\xFB\\xFD\\x1EN2Oe\\xE3a7#\\xBA\\x0C#\\xC1)\\xFF\\xB4\\x8A\\x8B\\x17\\xCB\\xED\\xAB&\\xFE'\\x99dQ\\xC4\\xCB#*[\\x1D0v\\x1D\\x8E,\"c\\x9F\\xCA}\\x99\\x9B\\xBEgHf\\x01w\\xFC\\xD0{\t\\x94\\xC2^;\\x11\\xF5\\xF3\\xB4\\x81\\xCB\\x92}\rV\\x01\\x85F\\x82\\x84\\xA2\\xCBUUkj\\x92BH\\x8E}"
		"\\x1C)\\xDEP\\x8B\\xB4\\x02Y\\xF9\\xB6!\\x97x\\xBEk)\\x9E\\x1A\\xD7#Z\\xB5p\\x8C\\x1C\\xE3\\xD0\\xC1", 
		LAST);

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_submit_data("login.pl", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=129615.892021061zzzHVVHpttfiDDDDtAAAcpHAtzHf", ENDITEM, 
		"Name=username", "Value=sasha", ENDITEM, 
		"Name=password", "Value=qwer", ENDITEM, 
		"Name=login.x", "Value=42", ENDITEM, 
		"Name=login.y", "Value=1", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_revert_auto_header("Origin");

	web_add_header("Origin", 
		"chrome-extension://mbacbcfdfaapbcnlnbmciiaakomhkbkb");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("api3.friproxy0.eu:80_2", 
		"Action=https://api3.friproxy0.eu:80/?1600108358216&kf2uzwmo", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=new", "Value=1", ENDITEM, 
		"Name=k", "Value=G3pjnxV7XOQScnzQ", ENDITEM, 
		"Name=t", "Value=1600125504", ENDITEM, 
		"Name=s", "Value=14772df55825d1aae2b1f5b2c9b8bd49", ENDITEM, 
		"Name=ip", "Value=89.178.192.240", ENDITEM, 
		"Name=po", "Value=0", ENDITEM, 
		"Name=pu", "Value=0", ENDITEM, 
		LAST);

	web_add_header("Origin", 
		"null");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	lr_think_time(4);

	web_custom_request("beacon_3", 
		"URL=https://gatpsstat.com/ext/beacon?hk=oryabZgR", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		"EncType=", 
		"BodyBinary=y\\xE3 o\\x06\\xA9\\x9Cqd\\xD6\\x7F\\x19\\xD9\\xC00\\x02\\xDB\\xE3\r\\x9F\\xDC\\xAD\\xD1itp\\xB5\\x01\\xB8\\xA7Y\\xB6\\xD8\\xC0\\xB4\\xF5}I\\x96\\x83y\\xE3\\xD7\\xC1\\xD5\\xC7WE\\xB3\\xF4\\x18r<\\x87\\xC2p\\x0BQ\\xEA\\xD9$\\xDF\\xF0jJ_\\xBA\\x07\\xBE\\x00+\\x19dG\\xAB\\xC9[=\\xD7\\xC3\\x85w3\\xB4J\\xE3\\xCD\\xFB\\xA0\\x01j}\\xA8$>\\x07x\\x054U<4m\\xBA\\x16\\\\x98\\xD0 *\\xAE\\xF0DRqL\\x93\\xE3\\xAE\\x01KZJK\\xAC\\x91\\x03\\x97\\xEE\\xF2\\xB8\\x0Fk\\xFA\\x9B\\x02x\\xFEoBJ,|"
		"H\\xDB\\x90.\\xA2h0\\xDE\\\\xE0\\xC6\\x8C\\xC0\\x15\\xF8\\x18-6\\xAE\\x8C\\x90[\\xEC\\x19n^\\xFB\\xF0\\x88\\xF5E\\xC67F\\xCB\\x94a\\x8Ck&]\\xB58%\\xFB~\\x0E\\x0F\\x90\\xE3\\x86\\x8B\\x0E\\xF8\\xC6\\xEC\\xD46\\xB7p\\xA5)\\xF2\\x99\\x11\\xDD\\xDA\\xD7\\xAE`*a\\x0E\\xC6\\x99\\x11\\x064{\\xC6\\xC5+\\x0Cv\\xE3\\x15b\\xEB\\xB8\\xF9\\x9FO\\xBD\\x8Ad\\xA6\\x8C\\xE9\\xE7\\xD1\\xE0S\\xD17d\\xC4\\x99\\xBB\\xD3\\xFF\\xCB\\xDA?`\\x18eF\\xF69C4O\\x00+\\xEE\\xB6%\\xAB\\x80\\x92\\xCC|\\xD8\\x12\\xBB\""
		"h\\xE3\\x89\\xD5\\x9D\\xA9\\xF76\\x04+\\xEB+\\xFAa\\xDB\\x7F\\xCA`\\x87\\xCA\\x95\\xEB\\x02\\xAC8\\xECGd;\\xA6\\xC7\\x94\\xB8\\x92m%S\\xC6W\\xC1p\\xB6)\\xF0\\x84\\xB8l\\xF0\\x8F\\xFB4dZk\\x8A\\x9D\\x9A\\x13O\\xF3\\xFD\\xBD\\xD5\\x90\\xBF\\x85\\xBA\\xE0\r\\x18/\\xF7N\\xAA\\xEA\\xC1 \\xE0\\x01\\x11i\\x8C,\\x13\\x97\\xA0\\x1A\\x1D\\xC6\\x96\\xBD~\\x0B\\xA6\\xAE\"\\xEFQ\\xA5\\xF0\\xB0b\\xF4\\x17\\xC9", 
		LAST);

	web_add_auto_header("Origin", 
		"chrome-extension://mbacbcfdfaapbcnlnbmciiaakomhkbkb");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	web_submit_data("api3.fri-gate0.biz:80", 
		"Action=https://api3.fri-gate0.biz:80/?1600108403262&kf2uzwmr", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t13.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=new", "Value=1", ENDITEM, 
		"Name=k", "Value=G3pjnxV7XOQScnzQ", ENDITEM, 
		"Name=t", "Value=1600125504", ENDITEM, 
		"Name=s", "Value=14772df55825d1aae2b1f5b2c9b8bd49", ENDITEM, 
		"Name=ip", "Value=89.178.192.240", ENDITEM, 
		"Name=po", "Value=0", ENDITEM, 
		"Name=pu", "Value=0", ENDITEM, 
		LAST);

	web_submit_data("r_2", 
		"Action=https://api3.fri-gate0.biz:80/r?1600108404059&kf2uzwms", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t14.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=k", "Value=G3pjnxV7XOQScnzQ", ENDITEM, 
		"Name=s", "Value=09fbb5240aeefb6a9a02418ffc9b440e", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(13);

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t15.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(7);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t16.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=1", "Value=on", ENDITEM, 
		"Name=flightID", "Value=368096418-793-SC", ENDITEM, 
		"Name=2", "Value=on", ENDITEM, 
		"Name=flightID", "Value=368083006-1552-SC", ENDITEM, 
		"Name=3", "Value=on", ENDITEM, 
		"Name=flightID", "Value=368110442-2381-SC", ENDITEM, 
		"Name=4", "Value=on", ENDITEM, 
		"Name=flightID", "Value=368093426-3117-SC", ENDITEM, 
		"Name=flightID", "Value=368108191-3858-SC", ENDITEM, 
		"Name=flightID", "Value=368075652-4663-SC", ENDITEM, 
		"Name=flightID", "Value=3681070807-53984-SC", ENDITEM, 
		"Name=flightID", "Value=368082737-6224-SC", ENDITEM, 
		"Name=removeFlights.x", "Value=48", ENDITEM, 
		"Name=removeFlights.y", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"null");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	lr_think_time(75);

	web_custom_request("beacon_4", 
		"URL=https://gatpsstat.com/ext/beacon?hk=QoWSuElx", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t17.inf", 
		"Mode=HTML", 
		"EncType=", 
		"BodyBinary=\\x16\\xF4jP\\xC9-\\xA5|\\x982\\x060m\\x9D(\\xB2\\xC62\\xFB\\x18dV\\x055\\xCA\\xF9\\xD2<\\xB7\\xBE#N?61U~\\x7F\\xD8]\\x80\\xEA*\\xC9\\xC5\n\\xA3t\\xE1\\x1D\\xD5\\xD1\\xE0\\xAA\\x0F\\x1D\\x17\nTpwxmR;Rz\\xB8>\\xC0<\\x1ET\n\\x86\\x89*|\\x8E\\xAF\\xD5\t.5S\\x1Bn\\xC6M\\xC4Aa\\xFC\\x92\\xE3 \\xD1#$UO\\xC2\\xCF\\x84`qc\\xEE4\\xD8U\\xB5\\xD3\\xEF\\xF41\\xDF\\xCF\\x16U\\x06\\x0B\\xD6\\x9F@\\x9A\\xE5\\x04w\\x9D\\x13xJ\\xE1\\xA8\\x0FB+\\xC5\\xD6|"
		"\\xF8\\x86$\\xE7\\xB1\\x95\\xCC\\x0F\\x95\\xA5@\\TWi[Q\\xA6\\xF5\\x83\t\\xFB\\x90\\xFB\\xFA\\x0E\\xFF\\xFE\\xDEb\n(\\xCB2p\\x1D$\\x18\\xB6.\\x03\\xA4\\x88\\xA1\\x1AX\\xB6?\\xA0\\xB60|\\x90\\xC4\\xEB\\xE9*\\xF2\\x98i~\\x1A\\xEC\\x1D\"N\\x1C\\xF9#\\x0E\\xD7l\\x03\\xFC9\\xB8\\xFF\\xF8f\\xBD\\xD1\\x14\\xF6\\xE5d8\\xA2\\xEE\\xD1g3\\xD2{o\\x02\\xB4i\\x8B\\xE2\\x1D\\xF3q\\x1Es\\xAD\\xD5h\\x11\\xB7\\x02x\\xC9f\\xF62\\x9D/\\xF7\\x93F\\xF7[\\x00o\\xC6\\xE4\\xD9=:M5\\xF5\\x99\"\\xEA\\x98 "
		"\\x9F\\x9F\\xF3r\\xC6\\xEC\\x80/\\x15\\x85\\x83T\\x19\\xA0\\xD5\\xDC\\xDAh\\x8D\\x96\\xCB\\xEB-)\\xC2fK\\xB7l\\x0Fx\\xFD\"2\\xFF_\\xDE\\xF7.;\\xF4\\xF2=\\xBF\n\\x83asd\\x98\\x141;2\\x82W\\x81\\xFA\\xEB\\x16\\x1DS\\xD8Y\\xCA\\x0F1\\x9A\\x82\\xE71\\\\x11\\xCF\\xA3\\x1Duo\\xBB\\x8C{N\\xC7\\xAF\\x88\\x17\\x97nB}<6\\xBE\\x86\\x01\\xA8\\x84K#\\x19\\xC6\\xC0\\x80\\xCCoD\\xFEV3\\xC1\\x86\\xE8b\\xB9\\xBB[\\xC6\\xFE\\x9Fc{\\x15\\x19\\xBBBE\\xC9\\xA6\\xFBa", 
		LAST);

	web_add_auto_header("Origin", 
		"chrome-extension://mbacbcfdfaapbcnlnbmciiaakomhkbkb");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("X-Requested-With", 
		"XMLHttpRequest");

	lr_think_time(6);

	web_submit_data("api3.fri-gate0.biz:80_2", 
		"Action=https://api3.fri-gate0.biz:80/?1600108596132&kf2uzwmt", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t18.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=new", "Value=1", ENDITEM, 
		"Name=k", "Value=G3pjnxV7XOQScnzQ", ENDITEM, 
		"Name=t", "Value=1600125504", ENDITEM, 
		"Name=s", "Value=08b08bc093c39c2c38f272b0288a1f33", ENDITEM, 
		"Name=ip", "Value=89.178.192.240", ENDITEM, 
		"Name=po", "Value=0", ENDITEM, 
		"Name=pu", "Value=0", ENDITEM, 
		LAST);

	web_submit_data("r_3", 
		"Action=https://api3.fri-gate0.biz:80/r?1600108598331&kf2uzwmu", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t19.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=k", "Value=G3pjnxV7XOQScnzQ", ENDITEM, 
		"Name=s", "Value=09fbb5240aeefb6a9a02418ffc9b440e", ENDITEM, 
		LAST);

	web_revert_auto_header("Origin");

	web_revert_auto_header("X-Requested-With");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(18);

	web_url("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t20.inf", 
		"Mode=HTML", 
		LAST);

	web_add_header("Origin", 
		"null");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_custom_request("beacon_5", 
		"URL=https://gatpsstat.com/ext/beacon?hk=woDPKjTw", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t21.inf", 
		"Mode=HTML", 
		"EncType=", 
		"BodyBinary=*\\xF9\\x19MD\\xA5\\xE0\\xD1\\xEA\\xE8\\x10aj0\\xE1TE\\xFC\\xD01{\\xAD\\x93v\\xF0\\xBA\\x9B\\xFA\\xF0\\xA9\\xA4\\x12\\x9C_W\\xB9\\x96,e\\xEE\\xDD\\xAFG\tC\\xAF\\x16!&\\xE6y\\x82\\xF5i\\xFF\\xE8_qV\\x93\\xEDQ\\x94L!\\xCA\\xB3\\x9BZ\\xCB\\x0BF?\\xDAi>\\xABx\"\\x1DU\"/ 0u\\x99\\x88\\x9E\\xF1\\xEC&\\x7Fw\\xE8\\xB9'\\xDCZ\\xEC\\x1A\\x9F\\x80\\xDE\\xC7\\xC8c\\xC8\\x00WZ\\x94-\\xFA\\x931l\\x08\\xD5+\\x84\\xA1\\xE1\\xBAD\\x8Fx\\xAFd\\xD9\\xF9\\xC7\\x7F;\\xA7n\\x04\\xF8|"
		"\\xD4\\xB5\\x11\\xF9\\xB1\\xD0\\x01P}\\xBC:\\xB6\\xA8\\xA6\\xC5\\x8Ciq\\xBB\\x95\\xFB\\x87\\xAF\\xF9~\\xB7N\\xCC\\x18\\x97a\\x96\\xA8\\x03\\xC2\\xD8 7\"91\\\tu\\xF2\\xB2\\x0B@(\\x8CY1\\xEE\\x92\\x11\\xEC\\x93~j\\x0E14\\xA0\\x99&$\\xE2\\xFD\\xA9A\\x11\\xEC\\xA2\\xE8\\xBD\\xE9\\x1F\\xBDA\\xF3\\xB2m\\x86 \\x87d\\xF6\\xF7$M\\xC4\\xC1\\xCE\\xF0\\xEA\\xA8\\x85\\xCE:\\xDC\\xC0O#\\x92\\xB8\\xF2\rMp\\x0Bt-\\x99\\x13\\xF4\\xEF\\xFE\\xC8\\x9A?F\\xAA\\x00\\x9E`Zf\\xEA\\xBBE\\x8D\\xD9\\xEA\\xBC\\x91\\xFE\\xCDu"
		")\\xAC\\xB2\\xE7$XJ\\xD1\\x93\\x89\\xC86\\xD0\\xC3\\xBB\\xE4\\x8D$+\\x80\\x1BVO\\x8C\\xA1T|T\\xFB2NjGXW\\xDE#\\xED<\\xE8[\\xA0 \\xE0\\xB8\\xFA\\xE7\\xF9\\xD3\\xC7)/7\\xE6\\xDD\\xAF.`\\xC4\\x7F\\x90!:\\xBE\\xB7|k++\\xB3U#0\\xBFv\\x9D\\xD2V+\\x14\\xAC\\xDFw\\xE9\\x861\\xE8\\xA7\\xD90\\x14a\\xAD'\\xE6Un\\xF2\\xD6\\x00\\xE4\\xED\r-\\x9B_\\x95.\\x0E\\x1F\\xD2n\\xF8o\\xADEF\\xFF\\x06z\\xD3()\\xC7\\xBA[\\xED\\xE94\\x9A\\xDF\\x9C\\xF3\\x15x;\\\\xD0\\xB0\\x0F\\xCE\\x14<Bp\\x1B{f\\xB3\\xA90"
		"!\\x88\\x14\\xCD\\x82y\\xA4\\x08\\xD0\\xD39\\xCA\\x05\\xCD\\xD448\\x04\\x84\\x84T?\\x08i\\x9C\\xD2\\x1A\\xAEh\\xBD1\\x9F[\\x96QP\\xEB\\\\xEE\\xEA\\xAA\\xCB$Q", 
		LAST);

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(31);

	web_submit_data("reservations.pl", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
		"Snapshot=t22.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=depart", "Value=Denver", ENDITEM, 
		"Name=departDate", "Value=09/15/2020", ENDITEM, 
		"Name=arrive", "Value=San Francisco", ENDITEM, 
		"Name=returnDate", "Value=09/16/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=findFlights.x", "Value=55", ENDITEM, 
		"Name=findFlights.y", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=roundtrip", ENDITEM, 
		"Name=.cgifields", "Value=seatType", ENDITEM, 
		"Name=.cgifields", "Value=seatPref", ENDITEM, 
		LAST);

	lr_think_time(18);

	web_submit_data("reservations.pl_2", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t23.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=outboundFlight", "Value=061;338;09/15/2020", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=reserveFlights.x", "Value=72", ENDITEM, 
		"Name=reserveFlights.y", "Value=7", ENDITEM, 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_auto_header("Origin", 
		"null");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_custom_request("beacon_6", 
		"URL=https://gatpsstat.com/ext/beacon?hk=PrRTwrBt", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t24.inf", 
		"Mode=HTML", 
		"EncType=", 
		"BodyBinary=\\x00.\\xDACO2\\xD5z\\xE0E\\xAD\\xD8g\\xF6a?\\x07\\xD3d\\xBFpg\\xA4Y\\x13\\xCC\\x93n=\\xF0g\\xEF\\xF3E\\xE3\\x89@\\x15|\\xA8\\xB3\\xE4\\xBB\\x05C\\xCC4M\\xDF\"U\\xE8i\\xD87\\x83*6r&q\\xCEMJ\\xD3&^KPh\\x84\\xD6\\x00>\\x9E\\xCB\\xC4\\x18\\xFB\\xC70\\xB7C\\xAA\\x99\\x1ALd?p\\x95R\\xED\\x1B`Zrv2l\\x0F\\xC5\\xA9\\xE5\\x92\\x0F\\xE8\t\\xDB\\x89\\xBA\\xC52 oKD\\xF1O\\xC6\\xDA\\xC9\\xCC\\xF0\\xE8\\x11d\\xFF\\x923\\x0Em\\x91y\\xC5\\xE1\\xA4\\xE6hOy\\xAC\\x19\\xA0\\xA8\\xE5#\\xCF\\xDE\\x1AU\\x99 "
		"\\xBFcE\\x83\\xF5\\x06\\xDBPV\\xC7\\xB1\\xCF z\\xDC\\xFDGK\\xF3qy$C\\xEC\\xDD)w\\xF5#\\xBC\\xE1$\\xA3t\\xA0`b\\xE4\\xB7\\xDCZO\\x95\\xE4d?\\xFD\\{\\x10\\xBBf\\xBE\\x95#@\\x8F\\x90EA\\x9C\\x1DsR\\xE7.!p\r\\xBA2\\xD7\\xE0\\x0BM8^\\x8A\\x8A\\x0B\\x82\\xE72\\x0B\\xF2V\\xC7\\x98\"\\xE2\\xB56\\x8C%\\xC6\\xC1^XK\\x08\\xDB\\xFC\\xDC\\x95#85\\xE1Ol\\xE3\\xA6\\xFB\\xBA\\x83\\x08\\xBFn\\xA9*K\\xD9\\x9B\\xFB\\xC4p\\xC3\\xF1\\x050\\x00\\x1A\\xD5V-\\x9F\\x10\\xEA\\x82|\\x99_\\xFC\\xCF\\x85\\x97w\\xA6\\xBC\\xD3Y"
		"<\\x97\\xB0u\\xEF\\xCC\\xA7\\x7FH\\x01\\xA3\\xDA_\\xE0R\\x04B\\xC4\\x05Z\\xB6\\xAA\\xC1\\xB3U\\xF6\\xB6\\x99\\xA33Yh\\xFF+d\\x81\\xF73}q\\xFAe\\x90\\xD7\\xE3D\\xF2\\xD6\\xF7=\\xD0&\\xED\\x10\\xE9\\x17\\xDA\\xCA\\x93\\x19\\x18\\xD9-\\xA9\tE\\xA2\\xF5\\xAEBu-\\xFF)\\xC6\\xCC\\xEA\\x17\\xCAY", 
		LAST);

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_revert_auto_header("Origin");

	web_add_header("Origin", 
		"http://localhost:1080");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(5);

	web_submit_data("reservations.pl_3", 
		"Action=http://localhost:1080/cgi-bin/reservations.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
		"Snapshot=t25.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=firstName", "Value=Sasha", ENDITEM, 
		"Name=lastName", "Value=Carrington", ENDITEM, 
		"Name=address1", "Value=Druzba street", ENDITEM, 
		"Name=address2", "Value=Moscow", ENDITEM, 
		"Name=pass1", "Value=Sasha Carrington", ENDITEM, 
		"Name=creditCard", "Value=1234567890123456", ENDITEM, 
		"Name=expDate", "Value=02/24", ENDITEM, 
		"Name=oldCCOption", "Value=", ENDITEM, 
		"Name=numPassengers", "Value=1", ENDITEM, 
		"Name=seatType", "Value=First", ENDITEM, 
		"Name=seatPref", "Value=Window", ENDITEM, 
		"Name=outboundFlight", "Value=061;338;09/15/2020", ENDITEM, 
		"Name=advanceDiscount", "Value=0", ENDITEM, 
		"Name=returnFlight", "Value=", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		"Name=buyFlights.x", "Value=37", ENDITEM, 
		"Name=buyFlights.y", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=saveCC", ENDITEM, 
		LAST);

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(7);

	web_url("welcome.pl_3", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t26.inf", 
		"Mode=HTML", 
		LAST);

	web_revert_auto_header("Upgrade-Insecure-Requests");

	web_add_header("Origin", 
		"null");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"none");

	lr_think_time(5);

	web_custom_request("beacon_7", 
		"URL=https://gatpsstat.com/ext/beacon?hk=EaxHFndy", 
		"Method=POST", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/plain", 
		"Referer=", 
		"Snapshot=t27.inf", 
		"Mode=HTML", 
		"EncType=", 
		"BodyBinary=\\x94\\xAD%\\xDAL\\x89+v\\x08\\xEE\\xB9b7\\xEAR\\xD7\\xA7t*\\xF1a\\xDEP\\x83L~\\x02\\x10\\x93\\x92)\\x0Cq\\xC4;\"\\x8A\\xC4\\x06\\xAF\\xBFncgV\\xD1\\x94\\x9C\\xE2\\x84\\xD4\\x0ET6\\xC1\\xD5\n\\xEFjs\\x9C\\xE7~\\x03\\x94\\xF6\\xC5\\xC9\\x1AQ7TqA\\x1F\\xCAW;\\xAE@>Z\\x8F\\xF8\\xA8\\xD7S\\xFC\\x7F+\\x8D\\xBAB\\xB1Y\\xF3\\xF5t\\x993\\x89\\x8F\\xF4R\\xA9B=\\x80\\y\\\\x8A>\\xEAr\\x82|Z\\xC7|ha)l\\xE4\\x16\\xA5U\\xC8\\xBE\\xD7\\x83@\\xC1(\\xC1\\xF4\\x99\\x93\\x80r\\xC5\\x01\\xCE\\xF9\\xE0+"
		"\\xB6\"\\xC8\\x0C)\"\\x91\\xB5\\x80P\\x9C\\x8C\tE'\\x15X3\\x8F\\xA0\\x10\\x86\\xEFk\\xE2\\x05\\xF1if\\xA9f\\xF8{L>\\x00\\xD4H\\xD1s\\x10+\\xE0fQ\\xD9\\x03 \\xB2:bj&\\x87\\xF04K\\xF3t\\x03\\xAF\\xB7O\\x9EC\\x0B\\xC6\\x9A\\x99f\\x99\\x103T\\xA8\\xB21m\\xA8\\x95\\x89\\xF3\\xFA\\xD6\\xB5\\xC5\\x82\\xF6\\xAD\\x16\\x03+V]^H#b\\xDE}\\x0CF\n\\xE0\\x83\\x17F#n}\t\\x98\\xBB[Z\\x844m\\x05/\\xD8U\\xA7n)N\\xCE \\\\xB0\\x1B\\x18\\xE3\\xB9\\x82\\xDC\\xC4\\xD4\\xFAN\\xD1\\xE2\\xCA\\xAE\\xD9\\x18\\xD7\\xBD\\xB5~"
		"\\x89\\x1B\\xFA\\x03\\x05f\\xABR\\x0C&k\\x85\\xAF\r>D|\\x14\\xF1\\xE5\\xFB\\xB3.\\xAA\\xDC\\xA6\\xC4\\xBBg\\xD3j\\x93\\x86\\xF6_\\xBC\\xFB\\x88\\xE0\\xF0\\x181\\d?\\xE4\\x10\\x00\\xFB\\x1D\\x1BZq-\\x99*\\xBB\\xBEc\\xB4\\x81\\xC2\\x88mTe\\x12>V\\xAD\\xE1\\x92\\xB1\\xAC\\xC2 \\xF8l\\xFF_0\\x15\\xC13|\\x07\rQ\\x08\\xAD\\x0E%u\\xFF\\xA6\\xFF\\xA9\\xF7j$lI8'\\xB5\\xDA\\xFF\\xC2\\xBB~b\\xCF\\xD6\\xA2\\xF64\\x111\\xF4\\x01\\x9Fw\\x0F\\xBDDL\\xB6\\xF0\\xBF\\x0F"
		"<\\x89\\xF8uB\\x06o\\xBA#\\x17\\x80\\xB7t\\x87ez\\x96d\\x96\\xC7\\x0Ed\\x16\\x11xaz%\\xFB\\xEBU\\xCC\\xFE\\x87\\x0C\\x0B\\xCC`\\x9D\\xC1\\xBD\\xEE\\x12\\x91\\xE6 @2\\x0C\\xA2Y:\\xF6\\x00<\\xBF\\xC1ISo\\xBA]\\xAB\\xF4\\xC07\\x1B\\x88t9\\x9F<\\xB2\r\\xA4\\xB3s\"z9\\xF3c\\xD9\\xA9\\xE9\\xDDn\\x96IIKaX\\xAF\\xDD\\xA3r\\xA9\\xFC\\x9F\\xC1\\xDD\\x07\\xFES\\xDC\\xED\\xDD\\xF4\\x7FE\\xD3\\xB0\\x9FZ\\xC0|X\\xBFQ?\\xC8\\xD8\r\\xE0E\\xE4\\xDC\\xD6\\xD5Lc\\xC6\\xF5\\xA8h\"\\x97~\\xC8h \\xB3\\x06\\xDB\\\\xAF\t"
		">\\x08\\xC8\\xA9\\xBD\\xF9]\\xBBz\\x87\\x14Mu\\xC0B\\xFFO\\xE8H7\\xE8", 
		LAST);

	return 0;
}