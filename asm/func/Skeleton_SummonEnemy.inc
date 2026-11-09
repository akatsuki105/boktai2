	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	ldr r1, _081063D0 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08106440
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #8
	bne _08106440
	subs r1, #0x13
	adds r0, r4, r1
	ldr r7, [r0]
	adds r0, r4, #0
	bl Skeleton_CanSummonEnemy
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08106440
	ldrb r0, [r4, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	add r3, sp, #0xc
	lsls r5, r0, #6
	ldr r2, _081063D4 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #8
	adds r6, r3, #0
	cmp r0, #0
	blt _081063D8
	asrs r1, r0, #0xc
	b _081063DE
	.align 2, 0
_081063D0: .4byte 0x000001DF
_081063D4: .4byte gSineTable
_081063D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081063DE:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x80
	lsls r0, r0, #1
	muls r0, r1, r0
	cmp r0, #0
	blt _081063FA
	asrs r0, r0, #0xc
	b _08106400
_081063FA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08106400:
	strh r0, [r3, #4]
	movs r1, #8
	ldrsh r0, [r4, r1]
	movs r2, #0
	ldrsh r1, [r6, r2]
	adds r0, r0, r1
	str r0, [sp]
	movs r1, #0xa
	ldrsh r0, [r4, r1]
	str r0, [sp, #4]
	movs r2, #0xc
	ldrsh r0, [r4, r2]
	add r1, sp, #0xc
	movs r2, #4
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	str r0, [sp, #8]
	ldr r1, _08106448 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	movs r1, #3
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	mov r0, sp
	str r0, [r1, #4]
	movs r2, #0xe4
	lsls r2, r2, #3
	adds r0, r7, r2
	ldrh r0, [r0]
	bl VM_ExecByID
_08106440:
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08106448: .4byte 0xFFFF0000
