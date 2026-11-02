	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	mov ip, r0
	movs r5, #0
	movs r0, #8
	mov r8, r0
	mov r3, sp
	mov r6, ip
	adds r6, #8
	movs r1, #0xec
	lsls r1, r1, #1
	add r1, ip
	mov sb, r1
	ldr r4, _0814854C @ =0x03002BE0
_081484DA:
	lsls r2, r5, #2
	ldr r1, [r4]
	cmp r1, #0
	beq _08148554
	ldr r0, _08148550 @ =0x03002BC0
	adds r0, r2, r0
	ldr r0, [r0]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	bne _08148554
	adds r2, r1, #0
	adds r2, #0x2c
	ldrh r0, [r1, #0x2c]
	mov r7, ip
	ldrh r1, [r7, #8]
	subs r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	movs r1, #0
	ldrsh r0, [r3, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	movs r0, #0x90
	lsls r0, r0, #6
	cmp r1, r0
	bgt _08148554
	ldr r2, [r4]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08148554
	adds r0, r2, #0
	adds r0, #0x24
	mov r2, sb
	str r0, [r2]
	movs r0, #1
	b _0814855E
	.align 2, 0
_0814854C: .4byte 0x03002BE0
_08148550: .4byte 0x03002BC0
_08148554:
	adds r4, #4
	adds r5, #1
	cmp r5, #3
	ble _081484DA
	movs r0, #0
_0814855E:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
