# Fritzing Files

The clock I built dad (still working, BTW, after 3 years) was a bit of a "breadboard special." Now, I've bitten the bullet to create a printed circuit board, using Fritzing, and exporting the artwork as Gerber files.

![YAPMC_PCBimg_D1mini_Version"](https://user-images.githubusercontent.com/46626696/203237052-1747fa44-66f8-4580-ad78-948db6ee14b4.png)

### How to use these files

To order a small batch of boards, or to machine your own (double sided, I hope your CNC is accurate), 
  * download the YAPMC_D1mini.zip file
  * browse to PCBway or similar service
  * upload the zip file to their quoting service and follow their instructions
  * select 4 or 5 if this is your first order, you may get the order for free 
    * (the postage is never free, though, so it's not really free)
  * when the file is approved, select your preferred postage service
  * pay
  * wait for your boards to arrive!

Order parts from your preferred local supplier while waiting. I've used some custom digital panel meters in fritzing, but they provide pads that provide meter output pins and power for meter backlights. The LEDs and buttons, as well as spare D1 pins, are broken out to pads, too, making this flexible for developing extra features for the clock, like an alarm and an ambient light sensor for backlit meters. Enjoy!

The board description file in the firmware code, for an Arduino Uno, is really only to help beginners, or parents with kids for holiday projects, to get YAPMC up and running as a learning exercise. If there's interest in an UNO panel meter clock shield, create an issue the usual github way and I'll see what I can do. However, I'm not a professional, I'm also not a service, I have other projects for my nearest and dearest and I don't get back here ar lot. I do get notifications for issues such as bug reports and feature request, so I will respond if I can, and have time to

.
