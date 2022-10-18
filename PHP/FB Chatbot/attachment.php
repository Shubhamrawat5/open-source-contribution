<?php


$hubVerifyToken = 'Tech-Space'; // change this
$accessToken = 'EAAnzgRkKZCyYBABLq4N9qDbB1ChDZAJwYhreJ4gPnRRPkV9cP83G8eMZCNzZCk6TYTkGJrzZBnIrdJWzj97V4uv6JFgIab1a3fvq8VuFmJiL7PDBDcrNZA818R6j9aO7g5jWpZCFTZARhIZCJ16PY6qZAjZCGgTHGpN6cIuQIBO1VZA2v4hI1eQAbNk0'; //change this


$imageurl='https://nurshatfatehali.000webhostapp.com//m1.jpg'; //change this





    $image = '{
  "message":{
    "attachment":{
      "type":"image", 
      "payload":{
        "is_reusable": true,
        "url":"' . $imageurl . '"
      }
    }
  }
}';

    $ch = curl_init('https://graph.facebook.com/v8.0/me/message_attachments?access_token=' . $accessToken);
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $image);
    curl_setopt($ch, CURLOPT_HTTPHEADER, ['Content-Type: application/json']);


    $result = curl_exec($ch);


    $return = json_decode($result, true);
    echo $attachment_id = $return["attachment_id"];