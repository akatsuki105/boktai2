	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r1, #0
	adds r7, r2, #0
	movs r0, #0x5c
	adds r0, r0, r5
	mov r8, r0
	adds r6, r5, #0
	adds r6, #0x20
	ldrb r0, [r5, #9]
	cmp r0, #0
	beq _0820B80C
	movs r4, #0
	strb r4, [r5, #9]
	strb r4, [r5, #7]
	movs r0, #4
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #2
	movs r3, #1
	bl FUN_08041480
	strh r4, [r5, #0x20]
	strh r4, [r6, #2]
	mov r2, r8
	ldr r0, [r2, #8]
	ldr r1, [r2, #0xc]
	str r0, [r6, #0xc]
	str r1, [r6, #0x10]
	movs r0, #0xca
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0820B80C:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r5, #0xe]
	orrs r0, r1
	strh r0, [r5, #0xe]
	movs r1, #0xb9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	beq _0820B892
	ldr r0, [r6, #0xc]
	ldr r1, [r6, #0x10]
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	movs r0, #3
	ands r0, r7
	adds r3, r5, #0
	adds r3, #0x6c
	lsls r4, r0, #6
	lsls r6, r7, #3
	ldr r2, _0820B860 @ =gSineTable
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
	blt _0820B864
	asrs r1, r0, #0xc
	b _0820B86A
	.align 2, 0
_0820B860: .4byte gSineTable
_0820B864:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0820B86A:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0820B882
	asrs r0, r0, #0xc
	b _0820B888
_0820B882:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0820B888:
	strh r0, [r3, #4]
	cmp r7, #0x1f
	ble _0820B892
	movs r0, #1
	strb r0, [r5, #7]
_0820B892:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
