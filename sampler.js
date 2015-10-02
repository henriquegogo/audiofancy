var bpm = 220;
var bpm_ratio = Math.floor(60000 / bpm);
var current_millisecond = 0, current_bar = 1;

setInterval(function() {
  current_millisecond++;
  current_bar = Math.floor(current_millisecond / bpm_ratio);

  if (current_millisecond % bpm_ratio === 0) {
    console.log(current_bar);
  }
}, 0);
