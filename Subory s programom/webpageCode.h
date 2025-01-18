String webpageCode = R"***(
<!DOCTYPE html>
<html>
  <head>    
        <title>ESP32 Webovy Server</title>
  </head>
  <style>
        body {font-family: "Calibri"; text-align:center; background-color: rgba(254,255,238, 0.589)}
        h1   {color: rgba(0, 0, 255, 0.788); font-size: 50px;}
        h2   {color: rgb(155, 11, 11); font-size: 30px}
        #lock
          {
            display: inline-block;
            background: #9b0b0b;
            color: rgba(255,255,255, 0.80);
            font-weight: bold;
            font: 35px arial, sans-serif;
            width: 300px;
            height: 300px;
            line-height: 300px;
            border-radius: 50%;
            margin: 30%;
            margin-top: 50px;
            overflow: hidden;
            vertical-align: middle;
            box-shadow: 0px 0px 0px 8px #0813018e;
            border: solid 2px rgba(247, 243, 7, 0.836);
            transition: 0.4s;
            cursor: pointer;
            
          }
  </style>
  <body>
        <h1>
              ESP32 Web Server: Trezor so servom<br>
        </h1>
        <h2>
              Klikni a odomkni elektronicky trezor
              <a href="/servo" id="lock" onclick="onoff()" align="center">Odomkni</a>
        </h2>
        <script>
            function onoff()
            {
                  var x = document.getElementById("lock");
                  x.innerHTML = "Spracovavam...";
            }       
        </script>
  </body>
</html>
)***";
