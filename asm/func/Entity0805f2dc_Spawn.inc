	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r4, r1, #0
	mov r8, r2
	mov sl, r3
	adds r7, r0, #0
	cmp r7, #0
	beq _0805F34E
	adds r0, r7, #0
	bl Entity0805f2dc_FindFreeElem
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x68
	movs r0, #0x18
	adds r0, r0, r5
	mov sb, r0
	cmp r5, #0
	bne _0805F354
_0805F34E:
	movs r0, #1
	rsbs r0, r0, #0
	b _0805F428
_0805F354:
	adds r3, r5, #0
	adds r3, #0x10
	ldr r2, _0805F378 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805F37C
	asrs r1, r0, #0xc
	b _0805F382
	.align 2, 0
_0805F378: .4byte gSineTable
_0805F37C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805F382:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	movs r0, #0xff
	ands r0, r4
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _0805F3A2
	asrs r0, r0, #0xc
	b _0805F3A8
_0805F3A2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805F3A8:
	movs r4, #0
	strh r0, [r3, #4]
	movs r0, #2
	strh r0, [r6, #0x10]
	ldr r0, [sp, #0x38]
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r0, r6, #0
	movs r1, #0
	bl Video_AddAuxSpriteIntoDrawList
	str r4, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	mov r0, sb
	mov r1, sl
	ldr r2, [sp, #0x28]
	movs r3, #0
	bl Hitbox_SetAttack
	add r0, sp, #0x30
	ldrb r0, [r0]
	strb r0, [r5, #1]
	mov r1, sp
	ldrh r1, [r1, #0x34]
	strh r1, [r5, #8]
	mov r0, sp
	ldrh r0, [r0, #0x34]
	strh r0, [r5, #0xa]
	mov r1, sp
	ldrh r1, [r1, #0x34]
	strh r1, [r5, #0xc]
	mov r0, sp
	ldrh r0, [r0, #0x34]
	strh r0, [r5, #0xe]
	ldr r1, [sp, #0x30]
	lsls r0, r1, #0x18
	cmp r0, #0
	beq _0805F410
	adds r1, r7, #0
	adds r1, #0x18
	adds r0, r6, #0
	bl AuxSprite_SetGfx
	b _0805F41A
_0805F410:
	adds r1, r7, #0
	adds r1, #0x34
	adds r0, r6, #0
	bl AuxSprite_SetGfx
_0805F41A:
	movs r0, #0
	str r0, [r5, #4]
	movs r0, #1
	strb r0, [r5]
	ldr r0, _0805F438 @ =0x00000361
	bl PlaySound_082406e0
_0805F428:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805F438: .4byte 0x00000361
