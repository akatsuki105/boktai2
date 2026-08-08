	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	mov r8, r1
	mov sl, r2
	adds r6, r3, #0
	ldrh r7, [r5]
	ldrh r0, [r1]
	lsls r3, r7, #0x10
	asrs r2, r3, #0x10
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	mov ip, r1
	cmp r0, #0
	beq _082369A8
	mov r4, sl
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, r2
	bge _08236916
	ldrh r0, [r6]
	adds r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	ble _08236926
	b _08236924
_08236916:
	ldrh r0, [r6]
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r2
	bge _08236926
_08236924:
	lsrs r4, r3, #0x10
_08236926:
	mov r1, r8
	movs r0, #2
	ldrsh r2, [r1, r0]
	movs r1, #2
	ldrsh r0, [r5, r1]
	subs r2, r2, r0
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	mov sb, r1
	mov r0, sb
	muls r0, r2, r0
	mov r2, ip
	lsls r1, r2, #0x10
	asrs r7, r1, #0x10
	adds r1, r7, #0
	bl Div
	ldrh r1, [r5, #2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r0, r1, #0x10
	str r0, [sp]
	asrs r1, r1, #0x10
	mov r2, sl
	movs r0, #2
	ldrsh r3, [r2, r0]
	movs r0, #2
	ldrsh r2, [r6, r0]
	subs r0, r3, r2
	cmp r1, r0
	blt _082369A8
	adds r0, r3, r2
	cmp r1, r0
	bgt _082369A8
	mov r1, r8
	movs r2, #4
	ldrsh r0, [r1, r2]
	movs r2, #4
	ldrsh r1, [r5, r2]
	subs r0, r0, r1
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r1, r7, #0
	bl Div
	ldrh r1, [r5, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	asrs r1, r1, #0x10
	mov r2, sl
	movs r0, #4
	ldrsh r3, [r2, r0]
	movs r0, #4
	ldrsh r2, [r6, r0]
	subs r0, r3, r2
	cmp r1, r0
	blt _082369A8
	adds r0, r3, r2
	cmp r1, r0
	ble _082369AC
_082369A8:
	movs r0, #0
	b _082369BA
_082369AC:
	ldr r1, [sp, #0x24]
	strh r4, [r1]
	mov r2, sp
	ldrh r2, [r2]
	strh r2, [r1, #2]
	strh r5, [r1, #4]
	movs r0, #1
_082369BA:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
