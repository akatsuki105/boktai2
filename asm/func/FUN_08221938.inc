	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x50
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r7, [r0]
	movs r3, #0
	ldrsh r2, [r7, r3]
	movs r1, #0
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r1, [r7, r3]
	movs r3, #4
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r1, _08221990 @ =0x00000898
	subs r0, r1, r0
	lsls r0, r0, #0x10
	bl Div
	adds r6, r0, #0
	ldr r0, _08221994 @ =0x00001998
	cmp r6, r0
	bgt _0822199C
	ldr r6, _08221998 @ =0x00001999
	b _082219A6
	.align 2, 0
_08221990: .4byte 0x00000898
_08221994: .4byte 0x00001998
_08221998: .4byte 0x00001999
_0822199C:
	movs r0, #0x80
	lsls r0, r0, #8
	cmp r6, r0
	ble _082219A6
	adds r6, r0, #0
_082219A6:
	adds r0, r4, #0
	bl FUN_0822190c
	cmp r0, #0
	beq _082219C0
	ldr r6, _082219BC @ =0x00001999
	movs r3, #0xc0
	lsls r3, r3, #4
	adds r1, r4, r3
	movs r0, #0x3c
	b _082219D0
	.align 2, 0
_082219BC: .4byte 0x00001999
_082219C0:
	movs r0, #0xc0
	lsls r0, r0, #4
	adds r1, r4, r0
	ldr r0, [r1]
	cmp r0, #0
	ble _082219D2
	ldr r6, _08221A68 @ =0x00001999
	subs r0, #1
_082219D0:
	str r0, [r1]
_082219D2:
	mov r4, sp
	ldrh r0, [r5]
	ldrh r1, [r7]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r5, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	movs r3, #2
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	bl Sqrt
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _08221A58
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r5, #0
	bl Div
	mov r1, sp
	strh r0, [r1]
	movs r2, #2
	ldrsh r0, [r4, r2]
	mov r3, r8
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #2]
	movs r1, #4
	ldrsh r0, [r4, r1]
	mov r2, r8
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r5, #0
	bl Div
	strh r0, [r4, #4]
_08221A58:
	mov r0, sp
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08221A6C
	asrs r1, r0, #0x10
	b _08221A72
	.align 2, 0
_08221A68: .4byte 0x00001999
_08221A6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r1, r0, #0
_08221A72:
	mov r0, sp
	strh r1, [r0]
	movs r1, #4
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08221A84
	asrs r0, r0, #0x10
	b _08221A8A
_08221A84:
	rsbs r0, r0, #0
	asrs r0, r0, #0x10
	rsbs r0, r0, #0
_08221A8A:
	mov r4, sp
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	ldrh r2, [r7]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _08221AD8 @ =0xFFFF0000
	ldr r2, [sp, #8]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #8]
	ldrh r1, [r7, #2]
	adds r1, #0x78
	lsls r1, r1, #0x10
	ldr r0, _08221ADC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r2, [r4, #4]
	ldrh r7, [r7, #4]
	adds r2, r2, r7
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	add r1, sp, #8
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r0, #8
	bl FUN_0823b980
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08221AD8: .4byte 0xFFFF0000
_08221ADC: .4byte 0x0000FFFF
