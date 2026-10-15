	push {r4, r5, lr}
	sub sp, #4
	adds r1, r0, #0
	ldr r0, _081E3EFC @ =0x0000161A
	adds r4, r1, r0
	movs r5, #0
	strb r5, [r4]
	ldr r2, _081E3F00 @ =0x0000161B
	adds r0, r1, r2
	strb r5, [r0]
	ldr r2, _081E3F04 @ =0x00000808
	adds r0, r1, r2
	ldrb r2, [r4]
	movs r3, #3
	ands r3, r2
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	adds r2, #0x90
	strh r2, [r0, #0x20]
	ldrb r3, [r4]
	lsrs r3, r3, #2
	lsls r2, r3, #1
	adds r2, r2, r3
	lsls r2, r2, #3
	adds r2, #0x20
	strh r2, [r0, #0x22]
	ldr r2, [r0, #8]
	movs r3, #1
	orrs r2, r3
	str r2, [r0, #8]
	ldr r2, _081E3F08 @ =0x00000AC8
	adds r1, r1, r2
	str r5, [sp]
	movs r2, #0
	bl MainSprite_SetAnim
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E3EFC: .4byte 0x0000161A
_081E3F00: .4byte 0x0000161B
_081E3F04: .4byte 0x00000808
_081E3F08: .4byte 0x00000AC8
