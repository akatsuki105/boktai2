	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x58
	adds r6, r0, #0
	adds r4, r1, #0
	adds r0, #0x24
	adds r1, r6, #0
	adds r1, #0x14
	mov r2, sp
	bl FUN_082367e4
	mov r5, sp
	movs r0, #0
	mov ip, r0
	movs r1, #0x1c
	ldrsh r0, [r5, r1]
	movs r2, #0x1c
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	movs r7, #0
	mov r8, r7
	movs r1, #0x24
	ldrsh r3, [r5, r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	subs r0, r3, r2
	movs r7, #0x24
	ldrsh r1, [r4, r7]
	cmp r0, r1
	bgt _08236C60
	subs r0, r1, r2
	cmp r0, r3
	bgt _08236C60
	movs r0, #1
	mov r8, r0
_08236C60:
	mov r1, r8
	cmp r1, #0
	beq _08236CC4
	movs r2, #0x1e
	ldrsh r0, [r5, r2]
	movs r7, #0x1e
	ldrsh r1, [r4, r7]
	adds r0, r0, r1
	movs r1, #0
	mov r8, r1
	movs r2, #0x26
	ldrsh r3, [r5, r2]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	subs r0, r3, r2
	movs r7, #0x26
	ldrsh r1, [r4, r7]
	cmp r0, r1
	bgt _08236C90
	subs r0, r1, r2
	cmp r0, r3
	bgt _08236C90
	movs r0, #1
	mov r8, r0
_08236C90:
	mov r1, r8
	cmp r1, #0
	beq _08236CC4
	movs r2, #0x20
	ldrsh r0, [r5, r2]
	movs r7, #0x20
	ldrsh r1, [r4, r7]
	adds r0, r0, r1
	movs r7, #0
	movs r1, #0x28
	ldrsh r3, [r5, r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	subs r0, r3, r2
	movs r5, #0x28
	ldrsh r1, [r4, r5]
	cmp r0, r1
	bgt _08236CBC
	subs r0, r1, r2
	cmp r0, r3
	bgt _08236CBC
	movs r7, #1
_08236CBC:
	cmp r7, #0
	beq _08236CC4
	movs r7, #1
	mov ip, r7
_08236CC4:
	mov r0, ip
	cmp r0, #0
	beq _08236CDE
	adds r0, r6, #0
	adds r0, #0x24
	adds r1, r6, #0
	adds r1, #0x14
	add r3, sp, #0x50
	adds r2, r4, #0
	bl Unused_FUN_08236bbc
	cmp r0, #0
	bne _08236CE2
_08236CDE:
	movs r0, #0
	b _08236D04
_08236CE2:
	ldrh r1, [r4, #6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08236CFA
	ldr r0, [sp, #0x50]
	ldr r1, [sp, #0x54]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	b _08236D02
_08236CFA:
	ldr r0, [sp, #0x50]
	ldr r1, [sp, #0x54]
	str r0, [r4, #0x2c]
	str r1, [r4, #0x30]
_08236D02:
	movs r0, #1
_08236D04:
	add sp, #0x58
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
