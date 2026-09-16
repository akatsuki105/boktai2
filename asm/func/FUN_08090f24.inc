	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r1
	mov r8, r2
	movs r7, #0
	mov r0, sb
	adds r0, #0x20
	str r0, [sp, #4]
	movs r1, #0x20
	add r1, r8
	mov sl, r1
_08090F42:
	ldr r1, _08091074 @ =0x085ACEA0
	lsls r0, r7, #2
	adds r4, r0, r1
	ldrb r0, [r4, #3]
	bl FUN_08090f0c
	cmp r0, #0
	beq _08091004
	ldrb r5, [r4]
	ldrb r6, [r4, #1]
	ldrb r0, [r4, #2]
	movs r2, #8
	str r2, [sp]
	cmp r0, #0
	beq _08090F64
	movs r0, #0xc
	str r0, [sp]
_08090F64:
	cmp r5, sb
	blt _08090F8A
	ldr r1, [sp, #4]
	cmp r5, r1
	bge _08090F8A
	cmp r6, r8
	blt _08090F8A
	cmp r6, sl
	bge _08090F8A
	movs r0, #1
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, [sp]
	ldr r2, _08091078 @ =0xFFFFE000
	orrs r0, r2
	strh r0, [r1]
_08090F8A:
	adds r4, r5, #1
	cmp r4, sb
	blt _08090FB4
	ldr r0, [sp, #4]
	cmp r4, r0
	bge _08090FB4
	cmp r6, r8
	blt _08090FB4
	cmp r6, sl
	bge _08090FB4
	movs r0, #1
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, [sp]
	adds r0, #1
	ldr r2, _08091078 @ =0xFFFFE000
	orrs r0, r2
	strh r0, [r1]
_08090FB4:
	cmp r5, sb
	blt _08090FDC
	ldr r0, [sp, #4]
	cmp r5, r0
	bge _08090FDC
	adds r2, r6, #1
	cmp r2, r8
	blt _08090FDC
	cmp r2, sl
	bge _08090FDC
	movs r0, #1
	adds r1, r5, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, [sp]
	adds r0, #0x10
	ldr r2, _08091078 @ =0xFFFFE000
	orrs r0, r2
	strh r0, [r1]
_08090FDC:
	cmp r4, sb
	blt _08091004
	ldr r0, [sp, #4]
	cmp r4, r0
	bge _08091004
	adds r2, r6, #1
	cmp r2, r8
	blt _08091004
	cmp r2, sl
	bge _08091004
	movs r0, #1
	adds r1, r4, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r0, [sp]
	adds r0, #0x11
	ldr r2, _08091078 @ =0xFFFFE000
	orrs r0, r2
	strh r0, [r1]
_08091004:
	adds r7, #1
	cmp r7, #9
	ble _08090F42
	movs r0, #0xe
	bl FUN_08090f0c
	cmp r0, #0
	bne _08091062
	movs r6, #0
	movs r7, #0
_08091018:
	movs r5, #0
	adds r0, r7, #1
	mov r8, r0
_0809101E:
	adds r0, r7, r5
	cmp r0, #1
	ble _08091056
	cmp r0, #8
	bgt _08091056
	subs r0, r7, r5
	cmp r0, #3
	bgt _08091056
	adds r4, r6, #0
	adds r4, #0x11
	cmp r6, #1
	bgt _08091038
	adds r4, r6, #3
_08091038:
	adds r1, r5, #0
	adds r1, #0x2b
	movs r0, #1
	adds r2, r7, #0
	adds r2, #0xf
	bl FUN_0808a420
	ldr r2, _08091078 @ =0xFFFFE000
	adds r1, r2, #0
	orrs r4, r1
	strh r4, [r0]
	adds r6, #1
	cmp r6, #3
	ble _08091056
	movs r6, #0
_08091056:
	adds r5, #1
	cmp r5, #5
	ble _0809101E
	mov r7, r8
	cmp r7, #5
	ble _08091018
_08091062:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08091074: .4byte 0x085ACEA0
_08091078: .4byte 0xFFFFE000
