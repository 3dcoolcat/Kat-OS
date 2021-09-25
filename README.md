# Oexis-OS
an operating system for ARMv7l architechture, or, more specifically, the raspberry pi. for contributers, it is required that you place a comment on every line of code, so that we know what is happening.

## Sources
 * [Programming the BMC2835 SOC](https://www.glennklockwood.com/embedded/bmc2835-gpio.html)

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
