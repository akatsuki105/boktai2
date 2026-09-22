	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x30
	str r0, [sp, #0x1c]
	adds r4, r1, #0
	adds r6, r2, #0
	str r3, [sp, #0x20]
	ldr r7, [sp, #0x50]
	ldr r0, _0800C870 @ =0x03002B34
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _0800C842
	b _0800CA0A
_0800C842:
	mov r0, sl
	bl HazardManager_FindFreeSlot
	str r0, [sp, #0x24]
	cmp r0, #0
	bge _0800C850
	b _0800CA0A
_0800C850:
	movs r0, #0xd4
	ldr r2, [sp, #0x24]
	adds r1, r2, #0
	muls r1, r0, r1
	mov r3, sl
	ldr r0, [r3, #0x20]
	adds r5, r0, r1
	strh r4, [r5]
	strh r6, [r5, #2]
	cmp r7, #0
	beq _0800C874
	ldr r0, [sp, #0x1c]
	bl FUN_08241574
	str r0, [r5, #4]
	b _0800C876
	.align 2, 0
_0800C870: .4byte 0x03002B34
_0800C874:
	str r7, [r5, #4]
_0800C876:
	ldr r0, [r5, #4]
	cmp r0, #0
	bge _0800C87E
	b _0800CA0A
_0800C87E:
	ldr r0, [sp, #0x54]
	strh r0, [r5, #8]
	adds r7, r5, #0
	adds r7, #0x14
	adds r6, r5, #0
	adds r6, #0x2c
	add r4, sp, #0x14
	movs r0, #0x1c
	adds r0, r0, r5
	mov r8, r0
	movs r1, #0x24
	adds r1, r1, r5
	mov sb, r1
	adds r2, r5, #0
	adds r2, #0x7c
	str r2, [sp, #0x28]
	adds r3, r5, #0
	adds r3, #0xb8
	str r3, [sp, #0x2c]
	ldr r3, [sp, #0x58]
	adds r1, r5, #0
	adds r1, #0xc
	movs r2, #3
_0800C8AC:
	ldm r3!, {r0}
	strh r0, [r1]
	adds r1, #2
	subs r2, #1
	cmp r2, #0
	bge _0800C8AC
	ldr r2, [sp, #0x1c]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #0x14]
	str r1, [r5, #0x18]
	ldr r2, _0800C990 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800C994 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldrh r1, [r5]
	ldr r2, _0800C998 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r6, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Hitbox_SetPowerAndAttributes
	ldr r1, _0800C99C @ =Hazard_OnHit
	adds r0, r6, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	adds r0, r6, #0
	bl Hitbox_Register
	ldr r1, _0800C9A0 @ =0x0000FF5C
	ldr r0, _0800C9A4 @ =0x0000FF80
	strh r0, [r5, #0x1e]
	strh r1, [r5, #0x20]
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	ldrh r0, [r7, #2]
	mov r1, r8
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	mov r2, r8
	strh r0, [r2, #2]
	ldrh r0, [r7, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	movs r1, #0xa4
	movs r0, #0x80
	strh r0, [r5, #0x26]
	strh r1, [r5, #0x28]
	ldrh r0, [r5, #0x14]
	adds r0, #0xa4
	strh r0, [r5, #0x24]
	ldrh r0, [r7, #2]
	mov r1, sb
	ldrh r1, [r1, #2]
	adds r0, r0, r1
	mov r2, sb
	strh r0, [r2, #2]
	ldrh r0, [r7, #4]
	ldrh r3, [r2, #4]
	adds r0, r0, r3
	strh r0, [r2, #4]
	ldrh r0, [r5, #0x14]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800C98C
	cmp r1, #0
	blt _0800C98C
	ldr r0, _0800C9A8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800C98C
	ldr r0, _0800C9AC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800C9B0
_0800C98C:
	movs r4, #0
	b _0800C9BE
	.align 2, 0
_0800C990: .4byte 0xFFFF0000
_0800C994: .4byte 0x0000FFFF
_0800C998: .4byte 0x00004001
_0800C99C: .4byte Hazard_OnHit
_0800C9A0: .4byte 0x0000FF5C
_0800C9A4: .4byte 0x0000FF80
_0800C9A8: .4byte 0x030046A8
_0800C9AC: .4byte 0x030046AC
_0800C9B0:
	ldr r0, _0800C9D0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0800C9BE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800C9D4
	adds r0, #4
	b _0800C9E0
	.align 2, 0
_0800C9D0: .4byte 0x030046A4
_0800C9D4:
	ldr r0, _0800CA10 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800C9E0:
	ldrb r0, [r0]
	movs r3, #0xf
	ands r3, r0
	cmp r3, #0xe
	bgt _0800C9EC
	adds r3, #1
_0800C9EC:
	movs r0, #0xff
	str r0, [sp]
	movs r0, #2
	str r0, [sp, #4]
	ldr r0, [sp, #0x28]
	adds r1, r4, #0
	movs r2, #0
	bl FUN_08234270
	ldr r1, _0800CA14 @ =0x000004B3
	ldr r0, [sp, #0x2c]
	bl Video_GetAuxSprite
	cmp r0, #0
	bne _0800CA18
_0800CA0A:
	movs r0, #1
	rsbs r0, r0, #0
	b _0800CA46
	.align 2, 0
_0800CA10: .4byte 0x030046A4
_0800CA14: .4byte 0x000004B3
_0800CA18:
	adds r4, r5, #0
	adds r4, #0x8c
	adds r0, r4, #0
	ldr r1, [sp, #0x2c]
	movs r2, #0
	bl AuxSprite_Add
	mov r1, sp
	ldrh r1, [r1, #0x20]
	strh r1, [r4, #0x10]
	adds r3, r5, #0
	adds r3, #0xa8
	ldr r1, [r5, #0x14]
	ldr r2, [r5, #0x18]
	str r1, [r3]
	str r2, [r3, #4]
	movs r2, #1
	ldr r3, [sp, #0x24]
	lsls r2, r3
	mov r3, sl
	ldr r1, [r3, #0x1c]
	orrs r1, r2
	str r1, [r3, #0x1c]
_0800CA46:
	add sp, #0x30
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
