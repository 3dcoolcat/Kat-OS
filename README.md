# Among-OS
![Version][Screen02] ![USB][NoUSB]<br>
an operating system for ARMv7l architechture, or, more specifically, the raspberry pi. for contributers, it is required that you place a comment on every line of code, so that we know what is happening.

## File Structure
The file structure for this project looks like this: <br>
&nbsp;.<br>
├── build<br>
├── kernel.ld<br>
├── Makefile<br>
└── source<br>
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── main.s  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;├── ____.s  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;└── ...  

## Installing on Micro SD Card
installation is done through 2 steps: Building, and Installing

### Building
In lx_terminal enter the project root dircetory and type the following command:
```
make
```

### Installing
Copy `bootcode.bin`, `start.elf`, and `config.txt`. Then, put the compiled kernel.img on the sd card as well.

## What is Happening When the OS is Run?
1. The BMC2835 SOC (specifically, the VideoCore IV GPU in it) loads the stage 1 boot loader from an on-chip ROM
    The stage 1 loader knows how to talk to the SD card controller and read FAT16/FAT32 file systems. It looks for a file called `bootcode.bin` on the first partition of the SD card, and loads it. `bootcode.bin` is the stage 2 boot loader.
2. The stage 2 loader loads `start.elf` from the SD card's first partition. This is the stage 3 boot loader.
3. The stage 3 loader then reads `config.txt` which acts a bit like a BIOS configuration configures the GPU and ARM processor loads `kernel.img` and releases the ARM processor to begin executing it

## Sources
 * [Programming the BMC2835 SOC](https://www.glennklockwood.com/embedded/bmc2835-gpio.html)
 * [BMC2835 Datasheet](https://datasheets.raspberrypi.org/bcm2835/bcm2835-peripherals.pdf)
   * Page 65 - EMMC Memory Management
   * Page 89 - GPIO
   * Page 109 - Interrupts
   * Pages 172 and 196 - Timer
   * Page 200 - USB
 * [Raspberry Pi 0 Specs](https://cdn.sparkfun.com/assets/learn_tutorials/6/7/6/PiZero_1.pdf)
 * [Baking Pi - Operating Systems Development](https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/os/downloads.html)
 * [ARM reference](https://www.keil.com/support/man/docs/armasm/armasm_dom1361289850039.htm)

## Assembly Commands Learned:
* **ldr**  
    `ldr reg, =val` put the number `val` in the register `reg`

* **mov**  
      `mov reg,#val` moves the number 'val' into the register named 'reg'.
      
* **lsl**  
      `lsl reg,#val` shifts the binary representation of the number in 'reg' by 'val' places to the left.
 
* **str**  
    `str reg,[dest,#val]` stores the number in `reg` at the address given by `dest + val`.

* **____:**  
    `name:` labels the next line `name`

* **b**  
    `b label` causes the program to be execute line `label`.

* **sub**  
    `sub reg,#val` subtracts the number `val` from the value in `reg`.

* **add**
    `add reg,#val` adds the number `val` to the value in `reg`

* **mov**  
     `mov reg,#val` puts the number `val` into the register named `reg`.

* **name:**  
     `name:` labels the next line `name`.

* **cmp**  
    `cmp reg,#val` compares the value in `reg` with the number `val`.

* **Suffix ne**  
    causes the command to be executed only if the last comparison determined that the numbers were not equal.

* **.globl**  
    `.globl lbl` makes the label `lbl` accessible from other files.

* **Suffix ls**  
    causes the command to be executed only if the last comparison determined that the first number was less than or the same as the second. Unsigned.

* **Suffix hi**  
    causes the command to be executed only if the last comparison determined that the first number was higher than the second. Unsigned.

* **push**  
    `push {reg1,reg2,...}` copies the registers in the list `reg1,reg2,...` onto the top of the stack. Only general purpose registers and `lr` can be pushed.

* **bl**  
    `bl lbl` sets `lr` to the address of the next instruction and then branches to the label `lbl`.

* **Argument shift**  
    `reg,lsl #val` shifts the binary representation of the number in `reg` left by `val` before using it in the operation before.'

* **pop**  
    `{reg1,reg2,...}` copies the values from the top of the stack into the register list `reg1,reg2,...` Only general purpose registers and pc can be popped.

* **.req**  
    `alias .req reg` sets `alias` to mean the register `reg`.

* **.unreq alias**  
    `.unreq alias` removes the alias `alias`.

* **lsr**  
    `lsr dst,src,#val` shifts the binary representation of the number in `src` right by `val`, but stores the result in `dst`.

* **and**  
    reg,#val computes the Boolean and function of the number in reg with val.'

* **teq**  
    'reg,#val checks if the number in reg is equal to val.'

* **ldrd**  
    'regLow,regHigh,[src,#val] loads 8 bytes from the address given by the number in src plus val into regLow and regHigh.'

* **.align num**  
    'ensures the address of the next line is a multiple of 2num.'

* **.int val**  
    'outputs the number val.'

* **tst**  
    'reg,#val computes and reg,#val and compares the result with 0.'

* **mla**  
    `dst,reg1,reg2,reg3` multiplies the values from `reg1` and `reg2`, adds the value from `reg3` and places the least significant 32 bits of the result in `dst`.

* **strh**  
    `reg,[dest]` stores the low half word number in reg at the address given by dest.

## Next Steps:
 * Follow Screen Tutorial and test to see if it actually works - Joseph
 * Fix Boot Issues - John - Primary
 * Look into File Managment - John - Secondary

[OK01]: https://img.shields.io/badge/Version-OK01-blue
[OK02]: https://img.shields.io/badge/Version-OK02-blue
[OK03]: https://img.shields.io/badge/Version-OK03-blue
[OK04]: https://img.shields.io/badge/Version-OK04-blue
[OK05]: https://img.shields.io/badge/Version-OK05-blue
[Screen01]: https://img.shields.io/badge/Version-Screen01-blue
[Screen02]: https://img.shields.io/badge/Version-Screen02-blue
[Screen03]: https://img.shields.io/badge/Version-Screen03-blue
[Screen04]: https://img.shields.io/badge/Version-Screen04-blue
[Input01]: https://img.shields.io/badge/Version-Input01-blue
[Input02]: https://img.shields.io/badge/Version-Input02-blue

[NoUSB]: https://img.shields.io/badge/USB-No-brightgreen
[USB]: https://img.shields.io/badge/USB-Yes-brightgreen
