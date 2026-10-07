	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DF6F0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DF6FA
	movs r0, #1
	rsbs r0, r0, #0
	b _081DF718
	.align 2, 0
_081DF6F0: .4byte 0x03002C68
_081DF6F4:
	strb r5, [r1]
	movs r0, #1
	b _081DF718
_081DF6FA:
	movs r2, #0
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r3, r0, r1
	movs r4, #1
	rsbs r4, r4, #0
_081DF706:
	adds r1, r3, r2
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, r4
	beq _081DF6F4
	adds r2, #1
	cmp r2, #4
	ble _081DF706
	movs r0, #0
_081DF718:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
