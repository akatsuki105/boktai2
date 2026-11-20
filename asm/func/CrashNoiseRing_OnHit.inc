	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r2, #0
	ldr r0, _0805EFE0 @ =0x03002BE0
	ldr r3, [r0]
	adds r4, r3, #0
	cmp r3, #0
	beq _0805F000
	ldrh r0, [r3, #0x24]
	ldrh r6, [r1, #4]
	cmp r0, r6
	bne _0805F000
	movs r6, #0xb6
	lsls r6, r6, #1
	adds r0, r3, r6
	cmp r0, r1
	bne _0805F000
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _0805EFE4
	adds r1, r0, #0
	adds r0, r3, #0
	bl FUN_0807ad60
	b _0805F000
	.align 2, 0
_0805EFE0: .4byte 0x03002BE0
_0805EFE4:
	ldr r0, _0805F008 @ =0x0000097C
	adds r3, r4, r0
	movs r1, #0x98
	lsls r1, r1, #4
	adds r0, r4, r1
	str r0, [sp]
	adds r0, r5, #0
	adds r0, #8
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x1e
	bl MosaicFader_Start
_0805F000:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0805F008: .4byte 0x0000097C
