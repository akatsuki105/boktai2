	adds r2, r0, #0
	ldr r0, _081E3790 @ =0x000015EC
	adds r3, r2, r0
	ldr r1, _081E3794 @ =0x000015ED
	adds r0, r2, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	ldrb r3, [r3]
	adds r0, r0, r3
	ldr r3, _081E3798 @ =0x000015EE
	adds r1, r2, r3
	ldrb r3, [r1]
	movs r1, #0x64
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _081E379C @ =0x000015EF
	adds r2, r2, r1
	ldrb r2, [r2]
	lsls r1, r2, #5
	subs r1, r1, r2
	lsls r1, r1, #2
	adds r1, r1, r2
	lsls r1, r1, #3
	adds r0, r0, r1
	bx lr
	.align 2, 0
_081E3790: .4byte 0x000015EC
_081E3794: .4byte 0x000015ED
_081E3798: .4byte 0x000015EE
_081E379C: .4byte 0x000015EF
