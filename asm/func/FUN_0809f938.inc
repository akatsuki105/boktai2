	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrh r0, [r5]
	cmp r0, #0
	bne _0809F954
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809F954:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F9D8
	movs r0, #6
	strh r0, [r4, #0x10]
	ldrh r1, [r5]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0809F972
	b _0809FA6E
_0809F972:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r6, _0809F9C8 @ =0x0203B400
	ldr r5, _0809F9CC @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _0809F9D0 @ =0x000003FF
	ands r2, r4
	lsls r3, r2, #1
	adds r3, r3, r6
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x7f
	ldrb r3, [r3]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0809F9D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	adds r2, r2, r6
	add r0, sp, #4
	ldrh r0, [r0, #4]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	add r0, sp, #4
	str r0, [sp]
	b _0809FA40
	.align 2, 0
_0809F9C8: .4byte 0x0203B400
_0809F9CC: .4byte 0x030046B8
_0809F9D0: .4byte 0x000003FF
_0809F9D4: .4byte 0xFFFF0000
_0809F9D8:
	cmp r0, #0xf
	bhi _0809FA60
	movs r0, #7
	strh r0, [r4, #0x10]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0809FA6E
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, _0809FA50 @ =0x0203B400
	mov r8, r0
	ldr r6, _0809FA54 @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r4, _0809FA58 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	add r0, r8
	add r3, sp, #0xc
	ldrh r1, [r3]
	subs r1, #0x7f
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _0809FA5C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	ldrh r0, [r3, #4]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [r3, #4]
	str r3, [sp]
_0809FA40:
	movs r0, #1
	movs r1, #0
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015c90
	b _0809FA6E
	.align 2, 0
_0809FA50: .4byte 0x0203B400
_0809FA54: .4byte 0x030046B8
_0809FA58: .4byte 0x000003FF
_0809FA5C: .4byte 0xFFFF0000
_0809FA60:
	movs r0, #8
	strh r0, [r4, #0x10]
	ldr r2, _0809FA7C @ =FUN_0809f8e4
	adds r0, r4, #0
	movs r1, #2
	bl Entity1DBEElem_SetState
_0809FA6E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809FA7C: .4byte FUN_0809f8e4
