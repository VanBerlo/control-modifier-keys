# Control Modifier Keys
A NodeJS module to control modifier keys (scroll, num and capslock) on a windows device. This means you can read AND set the state of either Num Lock, Caps Lock or Scroll Lock. 

## Motivation
While there are plenty of solutions to set these modifier keys with other packages, it is hard to read the state of these keys on-demand in NodeJS. Therefore, this simple package was created. We needed it for a custom hardware peripheral.

## Installation

Simply add it to your project with `npm install control-modifier-keys`.

## Usage

- Get the state of a modifier key (e.g. capslock) with `getModifierState("capslock")`.
- Set the state of a modifier key (e.g. numlock) with `setModifierState("numlock", true)`. Use the second boolean argument to enable or disable the key.


```javascript
const cmk = require("control-modifier-keys");

// Turn on Scroll lock
cmk.setModifierState("scrolllock", true);

// Get the state of Caps lock
const capsLockState = cmk.getModifierState("capslock");

```

## Example

To try it out, run `npm run example` this repo. It will toggle all three modifier keys based on the state they're currently in.
