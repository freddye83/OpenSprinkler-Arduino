
// TEST CODE ONLY - PLEASE IGNORE
// This code is a hacked together to troubleshoot weather  

#include <Arduino.h>
#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE }; //assign arduino mac address
byte ip[] = { 192, 168, 0, 202 }; // ip in lan assigned to arduino
//byte gateway[] = { 192, 168, 0, 1 }; // internet access via router
//byte subnet[] = { 255, 255, 255, 0 }; //subnet mask
byte port = 80;

EthernetServer server ( port ); //server port arduino server will use
EthernetClient client;

//char serverName[] = "checkip.dyndns.com"; // (DNS) dyndns web page server
char serverName[] = "weather.opensprinkler.com"; //
//byte serverName[] = { 208, 104, 2, 86 }; // (IP) zoomkat web page server IP address

String readString; //used by server to capture GET request
uint32_t timeout = 0;

//////////////////////

void setup()
{
	Serial.begin(115200);

    pinMode ( 5, OUTPUT ); //pin selected to control
    pinMode ( 6, OUTPUT ); //pin selected to control
    pinMode ( 7, OUTPUT ); //pin selected to control
    //pinMode ( 8, OUTPUT ); //pin selected to control
	pinMode (13, OUTPUT ); //pin selected to control

	// start the Ethernet connection:
	//Ethernet.begin ( mac, ip, gateway, gateway, subnet );
	if (Ethernet.begin(mac) == 0) 
	{
		Serial.println("Failed to configure Ethernet using DHCP");

		// try to congifure using IP address instead of DHCP:
		Ethernet.begin(mac, ip);
	}

	// give the Ethernet shield a second to initialize:
	delay(500);

	server.begin();

    Serial.println ( F ( "server/client 1.0 test 9/02/14" ) ); // keep track of what is loaded
    Serial.println ( F ( "Send a g in serial monitor to test client" ) ); // what to do to test client
	Serial.print("Server IP address: ");
	Serial.println(Ethernet.localIP());
}

void loop()
{
    // check for serial input
    if ( Serial.available() > 0 )
    {
        byte inChar;
        inChar = Serial.read();
        if ( inChar == 'g' )
        {
            sendGET(); // call client sendGET function
        }
    }

    EthernetClient client = server.available();

    if ( client )
    {
        while ( client.connected() )
        {
            if ( client.available() )
            {
                char c = client.read();

                //read char by char HTTP request
                if ( readString.length() < 100 )
                {

                    //store characters to string
                    readString += c;
                    //Serial.print(c);
                }

                //if HTTP request has ended
                if ( c == '\n' )
                {

                    ///////////////
                    Serial.print ( readString ); //print to serial monitor for debuging

                    //now output HTML data header
                    if ( readString.indexOf ( '?' ) >= 0 ) //don't send new page
                    {
                        client.println ( F ( "HTTP/1.1 204 Zoomkat" ) );
                        client.println();
                        client.println();
                    }
                    else
                    {
                        client.println ( F ( "HTTP/1.1 200 OK" ) ); //send new page on browser request
                        client.println ( F ( "Content-Type: text/html" ) );
                        client.println();

                        client.println ( F ( "<HTML>" ) );
                        client.println ( F ( "<HEAD>" ) );
                        client.println ( F ( "<TITLE>Arduino GET test page</TITLE>" ) );
                        client.println ( F ( "</HEAD>" ) );
                        client.println ( F ( "<BODY>" ) );

                        client.println ( F ( "<H1>Zoomkat's simple Arduino 1.0 button</H1>" ) );

                        // DIY buttons
                        client.println ( F ( "Pin5" ) );
                        client.println ( F ( "<a href=/?on2 target=inlineframe>ON</a>" ) );
                        client.println ( F ( "<a href=/?off3 target=inlineframe>OFF</a><br><br>" ) );

                        client.println ( F ( "Pin6" ) );
                        client.println ( F ( "<a href=/?on4 target=inlineframe>ON</a>" ) );
                        client.println ( F ( "<a href=/?off5 target=inlineframe>OFF</a><br><br>" ) );

                        client.println ( F ( "Pin7" ) );
                        client.println ( F ( "<a href=/?on6 target=inlineframe>ON</a>" ) );
                        client.println ( F ( "<a href=/?off7 target=inlineframe>OFF</a><br><br>" ) );

                        client.println ( F ( "Pin13" ) );
                        client.println ( F ( "<a href=/?on8 target=inlineframe>ON</a>" ) );
                        client.println ( F ( "<a href=/?off9 target=inlineframe>OFF</a><br><br>" ) );

                        client.println ( F ( "Pins" ) );
                        client.println ( F ( "&nbsp;<a href=/?off2468 target=inlineframe>ALL ON</a>" ) );
                        client.println ( F ( "&nbsp;<a href=/?off3579 target=inlineframe>ALL OFF</a>" ) );

                        client.println ( F ( "<IFRAME name=inlineframe style='display:none'>" ) );
                        client.println ( F ( "</IFRAME>" ) );

                        client.println ( F ( "</BODY>" ) );
                        client.println ( F ( "</HTML>" ) );
                    }

                    delay ( 1 );
                    //stopping client
                    client.stop();

                    ///////////////////// control arduino pin
                    if ( readString.indexOf ( '2' ) >0 ) //checks for 2
                    {
                        digitalWrite ( 5, HIGH ); // set pin 5 high
                        Serial.println ( F ( "Led 5 On" ) );
                        Serial.println();
                    }
                    if ( readString.indexOf ( '3' ) >0 ) //checks for 3
                    {
                        digitalWrite ( 5, LOW ); // set pin 5 low
                        Serial.println ( F ( "Led 5 Off" ) );
                        Serial.println();
                    }
                    if ( readString.indexOf ( '4' ) >0 ) //checks for 4
                    {
                        digitalWrite ( 6, HIGH ); // set pin 6 high
                        Serial.println ( F ( "Led 6 On" ) );
                        Serial.println();
                    }
                    if ( readString.indexOf ( '5' ) >0 ) //checks for 5
                    {
                        digitalWrite ( 6, LOW ); // set pin 6 low
                        Serial.println ( F ( "Led 6 Off" ) );
                        Serial.println();
                    }
                    if ( readString.indexOf ( '6' ) >0 ) //checks for 6
                    {
                        digitalWrite ( 7, HIGH ); // set pin 7 high
                        Serial.println ( F ( "Led 7 On" ) );
                        Serial.println();
                    }
                    if ( readString.indexOf ( '7' ) >0 ) //checks for 7
                    {
                        digitalWrite ( 7, LOW ); // set pin 7 low
                        Serial.println ( F ( "Led 7 Off" ) );
                        Serial.println();
                    }
                    if ( readString.indexOf ( '8' ) >0 ) //checks for 8
                    {
                        digitalWrite ( 13, HIGH ); // set pin 8 high
                        Serial.println ( F ( "Led 13 On" ) );
                        Serial.println();
                    }
                    if ( readString.indexOf ( '9' ) >0 ) //checks for 9
                    {
                        digitalWrite ( 13, LOW ); // set pin 8 low
                        Serial.println ( F ( "Led 13 Off" ) );
                        Serial.println();
                    }

                    //clearing string for next read
                    readString = "";

                }
            }
        }
    }
}

//////////////////////////
/// 
/// Browse URL: GET /weather0.py?loc=-27.44939,153.17598&key=e409b2aeaa5e3ffe&fwv=216&wto= HTTP/1.0  Host: *  Accept: text/html    
/// Browse URL : sent(OK)
void sendGET() //client function to send and receive GET data from external server.
{
    if ( client.connect ( serverName, 80 ) )
    {
        Serial.println ( F ( "connected" ) );

		client.println(F("GET /weather0.py?loc=-27.44939,153.17598&key=e409b2aeaa5e3ffe&fwv=216&wto= HTTP/1.0"));
		client.println(F("Host: *"));
		client.println(F("Accept: text/html"));
		client.println();

		timeout = millis() + 5000;
    }
    else
    {
        Serial.println ( F ( "Connection failed" ) );
        Serial.println();
    }

    while ( client.connected() && !client.available() ) delay ( 1 ); //waits for data

    while ( client.connected() || client.available() ) //connected or data available
    {
        char c = client.read(); //gets byte from ethernet buffer
        readString += c; //places captured byte in readString
    }

    //Serial.println();
    client.stop(); //stop client
    Serial.println ( F ( "Client disconnected." ) );
    Serial.println ( F ( "Data from server captured in readString:" ) );
    Serial.println();
    Serial.print ( readString ); //prints readString to serial monitor
    Serial.println();
    Serial.println ( F ( "End of readString" ) );
    Serial.println ( F ( "==================" ) );
    Serial.println();
    readString = ""; //clear readString variable
}

