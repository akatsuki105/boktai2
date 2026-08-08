	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov r8, r1
	ldrh r3, [r1, #4]
	lsls r3, r3, #2
	adds r1, r0, #4
	adds r1, r1, r3
	ldr r1, [r1]
	adds r0, r0, r1
	mov sb, r0
	ldr r0, [r0, #8]
	add r0, sb
	str r0, [sp]
	mov r1, sb
	ldr r0, [r1, #0xc]
	add r0, sb
	str r0, [sp, #4]
	ldr r0, [r1, #0x10]
	add r0, sb
	str r0, [sp, #8]
	mov r3, r8
	ldrh r4, [r3, #0xa]
	lsls r0, r4, #1
	adds r0, r0, r4
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r5, r1, r0
	movs r0, #0
	ldrsh r3, [r2, r0]
	ldrh r0, [r5]
	subs r3, r3, r0
	movs r1, #4
	ldrsh r0, [r2, r1]
	ldrh r1, [r5, #2]
	subs r0, r0, r1
	adds r1, r3, #0
	muls r1, r3, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	movs r0, #0xe1
	lsls r0, r0, #4
	cmp r1, r0
	bgt _08236258
	mov r3, r8
	ldrh r3, [r3, #8]
	cmp r4, r3
	bne _082361AA
	mov r2, r8
	ldr r0, [r2, #0xc]
	ldr r1, [r2, #0x10]
	mov r3, r8
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	movs r0, #6
	b _08236256
_082361AA:
	ldr r0, _08236228 @ =0x0000FFFF
	str r0, [sp, #0xc]
	movs r1, #0xff
	mov sl, r1
	movs r2, #0
	adds r1, r5, #6
	ldrb r0, [r5, #6]
	str r1, [sp, #0x10]
	cmp r0, #0xff
	beq _0823621A
_082361BE:
	adds r0, r1, r2
	ldrb r0, [r0]
	lsls r0, r0, #4
	ldr r3, [sp]
	adds r6, r3, r0
	movs r5, #0
	adds r1, r6, #4
	ldrb r0, [r6, #4]
	adds r7, r2, #1
	cmp r0, #0xff
	beq _0823620A
_082361D4:
	adds r4, r1, r5
	ldrb r3, [r4]
	cmp r3, sl
	beq _082361FA
	mov r0, sb
	ldrh r1, [r0, #2]
	mov r0, r8
	ldrh r2, [r0, #8]
	ldr r0, [sp, #8]
	bl FUN_0823595c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	cmp r0, r1
	bge _082361FA
	str r0, [sp, #0xc]
	ldrb r4, [r4]
	mov sl, r4
_082361FA:
	adds r5, #1
	cmp r5, #0xb
	bgt _0823620A
	adds r1, r6, #4
	adds r0, r1, r5
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _082361D4
_0823620A:
	adds r2, r7, #0
	cmp r7, #5
	bgt _0823621A
	ldr r1, [sp, #0x10]
	adds r0, r1, r7
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _082361BE
_0823621A:
	ldr r0, _0823622C @ =0x0000FFFE
	ldr r2, [sp, #0xc]
	cmp r2, r0
	ble _08236230
	movs r0, #0
	mov r3, r8
	b _08236256
	.align 2, 0
_08236228: .4byte 0x0000FFFF
_0823622C: .4byte 0x0000FFFE
_08236230:
	movs r2, #0
	mov r1, sl
	mov r0, r8
	strh r1, [r0, #0xa]
	mov r3, sl
	lsls r0, r3, #1
	add r0, sl
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, r8
	strh r1, [r3, #0x1c]
	strh r2, [r3, #0x1e]
	ldrh r0, [r0, #2]
	strh r0, [r3, #0x20]
	ldrh r1, [r3]
	movs r0, #2
	orrs r0, r1
_08236256:
	strh r0, [r3]
_08236258:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
