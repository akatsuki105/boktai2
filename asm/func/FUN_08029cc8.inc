	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xfe
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r0, #0xb5
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0x16
	movs r3, #1
	bl MainSprite_SetAnim
	movs r2, #0
	movs r1, #0xc1
	strh r1, [r5, #0x3a]
	ldr r0, _08029D10 @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r5, #0x48]
	ldr r1, _08029D14 @ =0x00000FD5
	adds r0, r4, r1
	strb r2, [r0]
	ldr r0, _08029D18 @ =0x00000FD6
	adds r4, r4, r0
	movs r0, #1
	strb r0, [r4]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08029D10: .4byte 0x03003584
_08029D14: .4byte 0x00000FD5
_08029D18: .4byte 0x00000FD6
