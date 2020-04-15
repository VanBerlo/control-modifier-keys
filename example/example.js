const cmk = require("../src");

console.log("numlock is now", cmk.getModifierState("numlock"));
console.log("capslock is now", cmk.getModifierState("capslock"));
console.log("scrolllock is now", cmk.getModifierState("scrolllock"));

console.log("------- FLIP ALL MODIFIER KEYS -------");
cmk.setModifierState("numlock", !cmk.getModifierState("numlock"));
cmk.setModifierState("capslock", !cmk.getModifierState("capslock"));
cmk.setModifierState("scrolllock", !cmk.getModifierState("scrolllock"));

console.log("numlock is now", cmk.getModifierState("numlock"));
console.log("capslock is now", cmk.getModifierState("capslock"));
console.log("scrolllock is now", cmk.getModifierState("scrolllock"));
