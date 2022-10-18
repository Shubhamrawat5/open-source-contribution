<?php

$hubVerifyToken = 'Tech-Space';
$accessToken = 'EAAnzgRkKZCyYBABLq4N9qDbB1ChDZAJwYhreJ4gPnRRPkV9cP83G8eMZCNzZCk6TYTkGJrzZBnIrdJWzj97V4uv6JFgIab1a3fvq8VuFmJiL7PDBDcrNZA818R6j9aO7g5jWpZCFTZARhIZCJ16PY6qZAjZCGgTHGpN6cIuQIBO1VZA2v4hI1eQAbNk0';
$attachment_id = 341005707480408;


if ($_REQUEST['hub_verify_token'] === $hubVerifyToken) {
    echo $_REQUEST['hub_challenge'];
    exit;
}
$raw = file_get_contents('php://input');


$input = json_decode($raw, true);

$senderId = $input['entry'][0]['messaging'][0]['sender']['id'];
$messageText = $input['entry'][0]['messaging'][0]['message']['text'];
$buttonClick = $input['entry'][0]['messaging'][0]['postback']['payload'];
$quickReplyClick = $input['entry'][0]['messaging'][0]['message']['quick_reply']['payload'];
$response = null;



if (!empty($messageText) && $messageText != 'Bye!' && $messageText != 'Ok. Bye!') {
    $answer = [
        "attachment" =>
        [
            "type" => "template",
            "payload" =>
            [
                "template_type" => "button",
                "text" => "Hi, Stranger! Wanna talk about tech?",

                "buttons" => [

                    [
                        "type" => "postback",
                        "title" => "Yup! I love tech!",
                        "payload" => "button0"
                    ],
                    [
                        "type" => "postback",
                        "title" => "Sorry! I'm busy",
                        "payload" => "button00"
                    ],
                ],
            ],
        ],
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'message' => $answer
    ];
} else if ($buttonClick == 'button0') {



    $answer = [
        "attachment" =>
        [
            "type" => "template",
            "payload" =>
            [
                "template_type" => "button",
                "text" => "Okay! Let's talk about computers!\nWhich processor do you use?",

                "buttons" => [

                    [
                        "type" => "postback",
                        "title" => "Intel",
                        "payload" => "button1"
                    ],
                    [
                        "type" => "postback",
                        "title" => "Apple M1",
                        "payload" => "button2"
                    ],
                    [
                        "type" => "postback",
                        "title" => "Ryzen",
                        "payload" => "button3"
                    ],


                ],
            ],
        ],
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'message' => $answer
    ];
} else if ($buttonClick == 'button1' || $buttonClick == 'button3') {
    $answer = [
        "attachment" =>
        [
            "type" => "template",
            "payload" =>
            [
                "template_type" => "button",
                "text" => "Cool!\nYou use x86 architechure based CPU.\nWhich GPU do you use?",

                "buttons" => [

                    [
                        "type" => "postback",
                        "title" => "NVIDIA",
                        "payload" => "button4"
                    ],
                    [
                        "type" => "postback",
                        "title" => "AMD",
                        "payload" => "button5"
                    ],
                    [
                        "type" => "postback",
                        "title" => "Integrated gpu :)",
                        "payload" => "button6"
                    ],
                ],
            ],
        ],
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'message' => $answer
    ];
} else if ($buttonClick == 'button4') {
    $answer = [
        "attachment" =>
        [
            "type" => "template",
            "payload" =>
            [
                "template_type" => "button",
                "text" => "Nice! NVIDIA is the market leader in the GPU manufacturing!\nWhich series do you use?",

                "buttons" => [

                    [
                        "type" => "postback",
                        "title" => "RTX",
                        "payload" => "buttonr"
                    ],
                    [
                        "type" => "postback",
                        "title" => "GTX",
                        "payload" => "buttong"
                    ],
                ],
            ],
        ],
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'message' => $answer
    ];
} else if ($buttonClick == 'button2') {
    $answer = [
        "attachment" =>
        [
            "type" => "template",
            "payload" =>
            [
                "template_type" => "button",
                "text" => "You use ARM architecture based SOC. You do not have the option to use dedicated gpu yet :)",

                "buttons" => [

                    [
                        "type" => "postback",
                        "title" => "Details pls :)",
                        "payload" => "button9"
                    ],
                    [
                        "type" => "postback",
                        "title" => "Okay...ig",
                        "payload" => "button8"
                    ]
                ],
            ],
        ],
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'messaging_type' => 'RESPONSE',
        'message' => $answer,

    ];
} else if ($buttonClick == 'buttong') {
    $answer =   [
        "text" => "That's a good gpu. But unfortunately you don't have access to Ray Tracing and DLSS :)",
        "quick_replies" => [
            [
                "content_type" => "text",
                "title" => "Ok. Bye!",
                "payload" => "qr1",

            ],
            [
                "content_type" => "text",
                "title" => "Restart",
                "payload" => "qr2",

            ],

        ]
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'messaging_type' => 'RESPONSE',
        'message' => $answer,

    ];
} else if ($buttonClick == 'buttonr') {
    $answer =   [
        "text" => "Your gpu supports Ray Tracing and DLSS. WOW!",
        "quick_replies" => [
            [
                "content_type" => "text",
                "title" => "Ok. Bye!",
                "payload" => "qr1",

            ],
            [
                "content_type" => "text",
                "title" => "Restart",
                "payload" => "qr2",

            ],

        ]
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'messaging_type' => 'RESPONSE',
        'message' => $answer,

    ];
} else if ($buttonClick == 'button6') {
    $answer =   [
        "text" => "Oh! Then you are using an APU. Nice!",
        "quick_replies" => [
            [
                "content_type" => "text",
                "title" => "Ok. Bye!",
                "payload" => "qr1",

            ],
            [
                "content_type" => "text",
                "title" => "Restart",
                "payload" => "qr2",

            ],

        ]
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'messaging_type' => 'RESPONSE',
        'message' => $answer,

    ];
} else if ($buttonClick == 'button5') {
    $answer =   [
        "text" => "WOW! You have a Radeon series graphics card! You have access to FidelityFX Super Resolution!",
        "quick_replies" => [
            [
                "content_type" => "text",
                "title" => "Ok. Bye!",
                "payload" => "qr1",

            ],
            [
                "content_type" => "text",
                "title" => "Restart",
                "payload" => "qr2",

            ],

        ]
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'messaging_type' => 'RESPONSE',
        'message' => $answer,

    ];
} else if ($quickReplyClick == 'qr1') {

    $answer = 'tata!';

    $response = [
        'recipient' => ['id' => $senderId],
        'message' => ['text' => $answer]
    ];
} else if ($buttonClick == 'button9') {
    $accessToken = $GLOBALS["accessToken"];
    $input = $GLOBALS["input"];
    $senderId = $GLOBALS["senderId"];
    $attachment_id = 341005707480408;


    $resp = '{
  "recipient":{
    "id":"' . $senderId . '"
  },
  "message":{
    "attachment":{
      "type":"image", 
      "payload":{
        "attachment_id": "' . $attachment_id . '"
      }
    }
  }
}';
    $ch = curl_init('https://graph.facebook.com/v8.0/me/messages?access_token=' . $accessToken);
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_POSTFIELDS, $resp);
    curl_setopt($ch, CURLOPT_HTTPHEADER, ['Content-Type: application/json']);
    if (!empty($input)) {

        $result = curl_exec($ch);
    }
    curl_close($ch);
}


if ($buttonClick == 'button9' ||  $buttonClick == 'button8' || $buttonClick == 'button00') {
    $answer =   [
        "text" => "Okay!\nHave a nice day!",
        "quick_replies" => [
            [
                "content_type" => "text",
                "title" => "Bye!",
                "payload" => "qr1",

            ],
            [
                "content_type" => "text",
                "title" => "Restart",
                "payload" => "qr2",

            ],

        ]
    ];
    $response = [
        'recipient' => ['id' => $senderId],
        'messaging_type' => 'RESPONSE',
        'message' => $answer,

    ];
}


$ch = curl_init('https://graph.facebook.com/v9.0/me/messages?access_token=' . $accessToken);
curl_setopt($ch, CURLOPT_POST, 1);
curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($response));
curl_setopt($ch, CURLOPT_HTTPHEADER, ['Content-Type: application/json']);

if (!empty($input)) {
    $result = curl_exec($ch);
}
curl_close($ch);
