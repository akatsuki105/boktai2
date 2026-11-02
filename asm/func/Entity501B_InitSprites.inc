	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _081E00E8 @ =0x0000CB05
	ldr r1, _081E00EC @ =0x0000DCC1
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	str r1, [r0]
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r0, r5, r3
	bl OpenMainSpriteFile
	movs r7, #0
	movs r4, #0
	adds r6, r5, #0
	adds r6, #0x18
_081E00AE:
	lsls r1, r7, #1
	movs r2, #0xd8
	lsls r2, r2, #2
	adds r0, r5, r2
	adds r0, r0, r1
	strh r4, [r0]
	ldrh r2, [r0]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r6, #0
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r1, r5, r3
	movs r3, #0x10
	bl MainSprite_Add
	cmp r0, #0
	bne _081E00DE
	adds r6, #0x60
	adds r7, #1
	cmp r7, #7
	ble _081E00AE
_081E00DE:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E00E8: .4byte 0x0000CB05
_081E00EC: .4byte 0x0000DCC1
