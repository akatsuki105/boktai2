	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	movs r0, #0xc4
	adds r0, r0, r4
	mov r8, r0
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _0805E142
	movs r0, #0
	strb r0, [r4, #3]
	adds r2, r4, #0
	adds r2, #0x64
	subs r0, #5
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805e67c_SetElemAnim
_0805E142:
	ldr r0, [r4, #4]
	movs r1, #0xf
	ands r0, r1
	ands r5, r1
	adds r6, r4, #0
	adds r6, #0xe0
	cmp r0, r5
	bne _0805E17C
	ldr r1, _0805E1DC @ =0x00001508
	adds r2, r7, r1
	movs r3, #0
	ldrsh r0, [r2, r3]
	mov r5, r8
	movs r3, #0x1c
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	movs r5, #4
	ldrsh r1, [r2, r5]
	movs r3, #4
	ldrsh r2, [r6, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r4]
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl Entity0805e67c_SetElemAnim
_0805E17C:
	adds r0, r4, #0
	adds r0, #0x64
	adds r1, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r0, [r4, #4]
	ldrb r5, [r4, #0xa]
	cmp r0, r5
	blo _0805E1EC
	ldr r0, _0805E1DC @ =0x00001508
	adds r2, r7, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r3, r8
	movs r5, #0x1c
	ldrsh r1, [r3, r5]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r2, r3]
	movs r5, #4
	ldrsh r2, [r6, r5]
	subs r1, r1, r2
	bl ArcTan2_8
	ldr r3, _0805E1E0 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _0805E1E4 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _0805E1E8 @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #0xf
	ands r1, r2
	adds r0, r0, r1
	subs r0, #8
	movs r1, #0
	strb r0, [r4]
	movs r0, #3
	strb r0, [r4, #2]
	movs r0, #1
	strb r0, [r4, #3]
	str r1, [r4, #4]
	b _0805E1F0
	.align 2, 0
_0805E1DC: .4byte 0x00001508
_0805E1E0: .4byte 0x030046B8
_0805E1E4: .4byte 0x000003FF
_0805E1E8: .4byte 0x0203B400
_0805E1EC:
	adds r0, #1
	str r0, [r4, #4]
_0805E1F0:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
