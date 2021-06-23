open Platform
   
type range = { lo: int; hi: int }

let set_leds ~range ~sustain ~intensity =
  let set v = 
    for i=range.lo to range.hi do
      Led.set i v
    done in
  for _=0 to sustain do
    set true;
    delay intensity;
    set false;
    delay (10-intensity)
  done
  
let () =
  let off_leds = { lo=0; hi=2 } in
  let pulsating_leds = { lo=3; hi=Led.size-1 } in
  for i=off_leds.lo to off_leds.hi do 
    Led.set i false (* Switch these off for reference *)
  done;
  while true do
    for i=0 to 9 do
      set_leds ~range:pulsating_leds ~sustain:5 ~intensity:i
    done;
    for i=9 downto 0 do
      set_leds ~range:pulsating_leds ~sustain:5 ~intensity:i
    done
  done
