	push {lr}
	adds r2, r0, #0
	ldr r0, _081DF8B8 @ =0x03002C68
	ldr r1, [r0]
	cmp r1, #0
	beq _081DF8CE
	ldrb r0, [r1, #0x1c]
	cmp r0, #0
	bne _081DF8BC
	movs r0, #1
	b _081DF8BE
	.align 2, 0
_081DF8B8: .4byte 0x03002C68
_081DF8BC:
	movs r0, #0
_081DF8BE:
	cmp r0, #0
	bne _081DF8CE
	adds r0, r1, #0
	adds r0, #0x24
	strb r2, [r0]
	movs r0, #1
	bl Sound_FadeOutBGM
_081DF8CE:
	pop {r0}
	bx r0
	.align 2, 0
