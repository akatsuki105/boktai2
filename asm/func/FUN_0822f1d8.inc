	push {r4, lr}
	ldr r1, _0822F1FC @ =0x03003568
	ldr r0, _0822F200 @ =0x03003530
	ldr r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _0822F1F6
_0822F1EA:
	ldr r4, [r0, #0x5c]
	bl FUN_0822f1c0
	adds r0, r4, #0
	cmp r0, #0
	bne _0822F1EA
_0822F1F6:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0822F1FC: .4byte 0x03003568
_0822F200: .4byte 0x03003530
