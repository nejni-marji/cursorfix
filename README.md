this is a hacky c++ script to fix an xserver bug, specifically this one: https://gitlab.freedesktop.org/xorg/xserver/-/issues/633

this is a bug that has plagued my life for at least 4 years now (since december 2017 or so, when i first switched to a trackball)

i realized that i could bypass this issue by wiggling the mouse a tiny bit after it is moved, and i already had c++ code to move the cursor lying around from my other project, SketchController, so i just copied all that code over here and started writing this, and had the entire project done in about half an hour or so. it's not very complicated, but using the c++ hooks for cursor stuff is probably better than calling xdotool 60 times a second as far as performance and cpu cycles go. hopefully this fix doesnt have any weird issues, but if it does, GO ~~YELL AT~~ FIRMLY TALK TO THE XSERVER PEOPLE INSTEAD AND TELL THEM TO FIX THIS. you *can* also submit an issue (or a PR) if you have any problems with this, and honestly, if you're a trackball or weird input device user and you're actually using this, i respect that enough to listen, so lemme know. but also bug the xserver people because really it's not my fault. i have no ill will towards them i get its a big project its just... this particular bug annoys me so friggin much.

anyway have fun i guess enjoy minecraft
