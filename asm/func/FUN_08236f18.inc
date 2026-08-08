	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r0, #0
	mov ip, r0
	movs r1, #0x1c
	ldrsh r0, [r4, r1]
	movs r2, #0x1c
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	movs r6, #0
	movs r7, #0x24
	ldrsh r3, [r4, r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	subs r0, r3, r2
	movs r7, #0x24
	ldrsh r1, [r5, r7]
	cmp r0, r1
	bgt _08236F48
	subs r0, r1, r2
	cmp r0, r3
	bgt _08236F48
	movs r6, #1
_08236F48:
	cmp r6, #0
	beq _08236FA4
	movs r1, #0x1e
	ldrsh r0, [r4, r1]
	movs r2, #0x1e
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	movs r6, #0
	movs r7, #0x26
	ldrsh r3, [r4, r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	subs r0, r3, r2
	movs r7, #0x26
	ldrsh r1, [r5, r7]
	cmp r0, r1
	bgt _08236F72
	subs r0, r1, r2
	cmp r0, r3
	bgt _08236F72
	movs r6, #1
_08236F72:
	cmp r6, #0
	beq _08236FA4
	movs r1, #0x20
	ldrsh r0, [r4, r1]
	movs r2, #0x20
	ldrsh r1, [r5, r2]
	adds r0, r0, r1
	movs r6, #0
	movs r7, #0x28
	ldrsh r3, [r4, r7]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x10
	subs r0, r3, r2
	movs r4, #0x28
	ldrsh r1, [r5, r4]
	cmp r0, r1
	bgt _08236F9C
	subs r0, r1, r2
	cmp r0, r3
	bgt _08236F9C
	movs r6, #1
_08236F9C:
	cmp r6, #0
	beq _08236FA4
	movs r7, #1
	mov ip, r7
_08236FA4:
	mov r0, ip
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
