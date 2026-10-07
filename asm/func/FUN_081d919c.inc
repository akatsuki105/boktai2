	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r6, r1, #0
	adds r7, r6, #0
	adds r7, #0x74
	ldrb r0, [r7]
	cmp r0, #0
	beq _081D91F8
	ldr r5, _081D9228 @ =0x0203B400
	ldr r2, _081D922C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r4, _081D9230 @ =0x000003FF
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x5a
	adds r3, r6, #0
	adds r3, #0x70
	movs r1, #0
	strh r0, [r3]
	strb r1, [r7]
	ldr r0, [r2]
	adds r0, #1
	ands r0, r4
	str r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrb r0, [r0]
	adds r7, r3, #0
	cmp r0, #0x17
	bgt _081D91F8
	adds r0, r6, #0
	movs r1, #1
	bl Entity8CC7Elem_SetFlags
	ldrh r0, [r7]
	adds r0, #0x3c
	strh r0, [r7]
_081D91F8:
	adds r0, r6, #0
	bl FUN_081d8cb0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D924E
	adds r0, r6, #0
	bl FUN_081d8d20
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D924E
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _081D9234 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _081D9238 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081D923C
	movs r0, #1
	b _081D923E
	.align 2, 0
_081D9228: .4byte 0x0203B400
_081D922C: .4byte 0x030046B8
_081D9230: .4byte 0x000003FF
_081D9234: .4byte 0x030046A0
_081D9238: .4byte 0x00000934
_081D923C:
	movs r0, #0
_081D923E:
	cmp r0, #0
	bne _081D924E
	mov r0, r8
	bl FUN_081d8d90
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081D9256
_081D924E:
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #3
	b _081D939A
_081D9256:
	adds r0, r6, #0
	movs r1, #1
	bl Entity8CC7Elem_TestFlags
	lsls r0, r0, #0x18
	adds r7, r6, #0
	adds r7, #0x70
	adds r5, r6, #0
	adds r5, #0x2c
	cmp r0, #0
	beq _081D92A0
	ldrh r0, [r7]
	cmp r0, #0x28
	bhi _081D92A0
	adds r0, r6, #0
	adds r0, #0x75
	ldrb r0, [r0]
	mov r4, sp
	adds r4, #5
	add r1, sp, #4
	adds r2, r4, #0
	bl FUN_081d8c80
	mov r0, r8
	ldr r1, [r0, #0x18]
	add r0, sp, #4
	ldrb r3, [r0]
	ldrb r0, [r4]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #6
	bl AuxAnim_SetAnim
	adds r0, r6, #0
	movs r1, #1
	bl Entity8CC7Elem_ClearFlags
_081D92A0:
	adds r4, r5, #0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D92CE
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _081D92D6
_081D92CE:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081D92D6:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081D92FA
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _081D9302
_081D92FA:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081D9302:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081D933C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _081D9382
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081D9346
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081D9340
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _081D935C
	.align 2, 0
_081D933C: .4byte 0x0000FFFF
_081D9340:
	subs r0, #1
	strh r0, [r4, #8]
	b _081D935A
_081D9346:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081D935A
	strh r1, [r4, #8]
	movs r2, #1
	b _081D935C
_081D935A:
	movs r2, #0
_081D935C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081D9384
	movs r0, #1
	strb r0, [r4, #7]
	b _081D9384
_081D9382:
	movs r2, #0
_081D9384:
	ldrh r0, [r7]
	cmp r0, #0
	beq _081D9390
	subs r0, #1
	strh r0, [r7]
	b _081D93A2
_081D9390:
	cmp r2, #0
	beq _081D93A2
	adds r1, r6, #0
	adds r1, #0x68
	movs r0, #2
_081D939A:
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #1
	strb r0, [r1]
_081D93A2:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
