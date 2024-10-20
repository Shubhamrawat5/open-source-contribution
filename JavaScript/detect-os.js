# Run it in browser
var Name = "Not known"; 
if (navigator.platform.indexOf('Win32', 'Win64', 'Windows', 'WinCE') != -1) Name =  
  "Windows"; 
if (navigator.platform.indexOf('Macintosh', 'MacIntel', 'MacPPC', 'Mac68K') != -1) Name =  
  "macOS"; 
if (navigator.appVersion.indexOf("X11") != -1) Name =  
  "UNIX"; 
if (navigator.appVersion.indexOf("Linux") != -1) Name =  
  "Linux";
if (navigator.platform.indexOf('iPhone','iPod') != -1) Name =  
  "iOS";
 if (navigator.platform.indexOf('iPad') != -1) Name =  
  "iPadOS";
console.log(Name);
