	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	adds r5, r1, #0
	mov sb, r2
	adds r7, r5, #0
	adds r7, #0xc4
	ldrb r0, [r5, #3]
	cmp r0, #0
	beq _0805E284
	movs r0, #0
	strb r0, [r5, #3]
	adds r2, r5, #0
	adds r2, #0x64
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	mov r0, r8
	adds r1, r5, #0
	movs r2, #0
	bl Entity0805e67c_SetElemAnim
	adds r3, r5, #0
	adds r3, #0xc
	ldrb r4, [r5]
	ldrb r6, [r5, #1]
	ldr r2, _0805E254 @ =gSineTable
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805E258
	asrs r1, r0, #0xc
	b _0805E25E
	.align 2, 0
_0805E254: .4byte gSineTable
_0805E258:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0805E25E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	ldr r1, _0805E278 @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0805E27C
	asrs r0, r0, #0xc
	b _0805E282
	.align 2, 0
_0805E278: .4byte gSineTable
_0805E27C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0805E282:
	strh r0, [r3, #4]
_0805E284:
	adds r6, r7, #0
	adds r6, #0x1c
	adds r1, r5, #0
	adds r1, #0xc
	ldrh r0, [r5, #0xc]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldrh r0, [r1, #2]
	ldrh r2, [r6, #2]
	adds r0, r0, r2
	strh r0, [r6, #2]
	ldrh r0, [r1, #4]
	ldrh r1, [r6, #4]
	adds r0, r0, r1
	strh r0, [r6, #4]
	adds r0, r5, #0
	adds r0, #0x64
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	movs r0, #1
	mov r2, sb
	ands r0, r2
	ldr r1, _0805E2E8 @ =0x000014E7
	add r1, r8
	ldrb r1, [r1]
	cmp r0, r1
	bne _0805E2D4
	adds r4, r5, #0
	adds r4, #0x14
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_0805E2D4:
	ldr r0, [r5, #4]
	cmp r0, #0x77
	bls _0805E2EC
	mov r0, r8
	adds r1, r5, #0
	mov r2, sb
	bl Entity0805e67c_ReleaseElem
	b _0805E2F0
	.align 2, 0
_0805E2E8: .4byte 0x000014E7
_0805E2EC:
	adds r0, #1
	str r0, [r5, #4]
_0805E2F0:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
