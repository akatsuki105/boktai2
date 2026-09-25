	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0xf8
	movs r0, #0x90
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r0, #0
	mov r8, r0
	movs r7, #0xf
_0807F8E8:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0807F926
	ldrb r0, [r4, #6]
	subs r0, #1
	strb r0, [r4, #6]
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	cmp r3, #0
	bne _0807F90E
	adds r0, r5, #0
	adds r0, #0xf8
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	strb r3, [r4]
	b _0807F926
_0807F90E:
	ldrb r0, [r4, #7]
	cmp r0, #0
	bne _0807F91E
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0807f650
	b _0807F926
_0807F91E:
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0807f750
_0807F926:
	adds r6, #0x3c
	adds r4, #0x3c
	movs r0, #0x3c
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _0807F8E8
	movs r0, #0x97
	lsls r0, r0, #3
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
