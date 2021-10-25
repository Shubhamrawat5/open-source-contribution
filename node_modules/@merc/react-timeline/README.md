# React Timeline

[![npm badge](https://img.shields.io/npm/v/@merc/react-timeline)](https://www.npmjs.com/package/@merc/react-timeline)
[![travis badge](https://img.shields.io/travis/steven-mercatante/react-timeline)](https://travis-ci.org/steven-mercatante/react-timeline)

The easiest way to add responsive and customizable timelines to React apps.

**View the [documentation](https://react-timeline.com/) for detailed instructions and demos.**

## Installation

```bash
npm install @merc/react-timeline
# or
yarn add @merc/react-timeline
```

## Usage

```jsx
import React from 'react';
import {
  Timeline,
  Events,
  UrlButton,
  ImageEvent,
  TextEvent,
  YouTubeEvent,
} from '@merc/react-timeline';

export default function App() {
  return (
    <Timeline>
      <Events>
        <TextEvent date="1/1/19" text="**Markdown** is *supported*" />

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
  );
}
```
