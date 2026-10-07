	push {lr}
	ldr r0, _081DF9A0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _081DF99C
	ldrb r0, [r0, #0x1e]
	cmp r0, #0
	bne _081DF9A4
_081DF99C:
	movs r0, #0
	b _081DF9A6
	.align 2, 0
_081DF9A0: .4byte 0x03002C68
_081DF9A4:
	movs r0, #1
_081DF9A6:
	pop {r1}
	bx r1
	.align 2, 0
