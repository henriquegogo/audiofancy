#!/usr/bin/env node

var bpm = 220;
var bpm_ratio = Math.floor(60000 / bpm);
var current_time = 0;

setInterval(function() {
  if (current_time % bpm_ratio === 0) {
    console.log(current_time);
  }
  current_time++;
}, 0);
