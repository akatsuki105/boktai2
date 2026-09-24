	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081DCA94 @ =0x0000CB05
	ldr r1, _081DCA98 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r6, r3
	bl OpenMainSpriteFile
	ldr r1, _081DCA9C @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081DCAA0 @ =0x000006BC
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r0, r6, r3
	bl OpenMainSpriteFile
	movs r7, #0
	movs r4, #0
	adds r5, r6, #0
	adds r5, #0x18
_081DCA22:
	lsls r0, r7, #1
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r1, r1, r0
	strh r4, [r1]
	ldrh r2, [r1]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r3, #0x10
	bl MainSprite_Add
	adds r2, r0, #0
	cmp r2, #0
	bne _081DCA8C
	adds r5, #0x60
	adds r7, #1
	cmp r7, #0xf
	ble _081DCA22
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #4
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r1, r6, r3
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0x10
	bl MainSprite_Add
	cmp r0, #0
	bne _081DCA8C
	movs r1, #0xc4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081DCA8C:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCA94: .4byte 0x0000CB05
_081DCA98: .4byte 0x0000DCC1
_081DCA9C: .4byte 0x0000B343
_081DCAA0: .4byte 0x000006BC
