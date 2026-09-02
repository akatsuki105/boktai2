	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r4, r2, #0
	mov sb, r3
	bl FUN_08236d10
	ldr r4, [r4]
	mov r8, r4
	cmp r4, #0
	beq _08236E3A
	ldr r0, _08236E30 @ =Hitbox_CheckOverlap
	mov sl, r0
_08236D8E:
	mov r5, r8
	ldr r1, [r5]
	mov r8, r1
	mov r0, sb
	ldr r6, [r0]
_08236D98:
	cmp r6, #0
	beq _08236E34
	adds r4, r6, #0
	ldr r6, [r6]
	ldrh r1, [r5, #0xa]
	ldrh r0, [r4, #0xa]
	ands r0, r1
	cmp r0, #0
	bne _08236D98
	ldrh r3, [r4, #6]
	movs r0, #4
	ands r0, r3
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	cmp r7, #0
	bne _08236D98
	ldrh r0, [r4, #4]
	cmp r0, #0
	beq _08236DC4
	ldrh r1, [r5, #4]
	cmp r0, r1
	beq _08236D98
_08236DC4:
	ldrh r1, [r5, #6]
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	bne _08236DD8
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	bne _08236D98
_08236DD8:
	movs r2, #0x80
	lsls r2, r2, #5
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _08236DEC
	adds r0, r2, #0
	ands r0, r3
	cmp r0, #0
	beq _08236D98
_08236DEC:
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_sl
	cmp r0, #0
	beq _08236D98
	strh r7, [r4, #0x3e]
	ldrh r1, [r4, #6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08236E14
	ldr r3, [r5, #0x48]
	cmp r3, #0
	beq _08236E14
	ldr r2, [r5, #0x4c]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r3
_08236E14:
	ldrh r1, [r5, #6]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _08236D98
	ldr r3, [r4, #0x48]
	cmp r3, #0
	beq _08236D98
	ldr r2, [r4, #0x4c]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r3
	b _08236D98
	.align 2, 0
_08236E30: .4byte Hitbox_CheckOverlap
_08236E34:
	mov r0, r8
	cmp r0, #0
	bne _08236D8E
_08236E3A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
