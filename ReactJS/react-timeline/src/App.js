import React from "react";
import { Timeline, Events, UrlButton, ImageEvent, TextEvent, YouTubeEvent } from '@merc/react-timeline';

const App = () => {
    return (
        <>
            <h1 style={{textAlign: "center"}}>React Timeline Demo</h1>
            <Timeline>
                <Events>
                    <TextEvent date="1/1/19" text="**Markdown** is *supported*" />
                    <TextEvent 
                        date="1/2/19" 
                        text="Events alternate by default (given enough space in the browser)" 
                    />
                    <ImageEvent
                        date="4/13/19"
                        text="You can embed images..."
                        src="https://res.cloudinary.com/dovoq8jou/image/upload/v1564772194/jellyfish.jpg"
                        alt="jellyfish swimming"
                        credit="Photo by [@tavi004](https://unsplash.com/@tavi004)"
                    >
                        <div>
                            <UrlButton href="https://unsplash.com/search/photos/undersea">
                                View more undersea photos
                            </UrlButton>
                        </div>
                    </ImageEvent>
                    <YouTubeEvent
                        date="6/18/19"
                        id="6UnRHtwHGSE"
                        name="General Tso's Chicken recipe"
                        text="... and YouTube videos!"
                    />
                </Events>
            </Timeline>
        </>
    );
}

export default App;