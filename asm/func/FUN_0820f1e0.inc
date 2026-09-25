	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r0, #0
	str r0, [r7, #0x18]
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	adds r6, r7, #0
	adds r6, #0x28
	movs r2, #0
	mov sl, r2
	add r3, sp, #0xc
	mov sb, r3
	ldr r5, _0820F2B4 @ =0x085AF0B0
	str r5, [sp, #0x18]
_0820F20C:
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r5, sl
	lsls r5, r5, #1
	str r5, [sp, #0x14]
	ldr r0, [sp, #0x18]
	movs r4, #0
	ldrsb r4, [r0, r4]
	adds r1, #2
	adds r0, r7, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	ldr r5, [sp, #0x18]
	movs r3, #1
	ldrsb r3, [r5, r3]
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r7, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	adds r2, r2, r4
	adds r1, r1, r3
	mov r3, sb
	strh r2, [r3]
	strh r1, [r3, #2]
	strh r0, [r3, #4]
	mov r5, r8
	ldrh r1, [r5]
	ldrh r2, [r5, #2]
	str r3, [sp]
	adds r0, r6, #0
	movs r3, #0x10
	bl FUN_08055dac
	cmp r0, #0
	blt _0820F2FA
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08055f1c
	ldrb r1, [r5, #0xb]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0820F274
	ldrh r1, [r5, #8]
	adds r0, r6, #0
	bl FUN_08055fbc
_0820F274:
	adds r0, r6, #0
	movs r1, #2
	bl FUN_08055f5c
	mov r1, r8
	ldrb r0, [r1, #0xa]
	ldr r2, _0820F2B8 @ =0x00000366
	adds r4, r7, r2
	ldr r3, _0820F2BC @ =0x00000367
	adds r5, r7, r3
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_0820efc4
	mov r0, sl
	cmp r0, #0
	bne _0820F2C4
	ldr r0, _0820F2C0 @ =0x085AF0BA
	ldrh r1, [r0]
	ldrb r2, [r4]
	ldrb r3, [r5]
	movs r0, #2
	str r0, [sp]
	mov r5, sl
	str r5, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r6, #0
	bl FUN_08055b5c
	b _0820F2E2
	.align 2, 0
_0820F2B4: .4byte 0x085AF0B0
_0820F2B8: .4byte 0x00000366
_0820F2BC: .4byte 0x00000367
_0820F2C0: .4byte 0x085AF0BA
_0820F2C4:
	ldr r0, _0820F30C @ =0x085AF0BA
	ldr r1, [sp, #0x14]
	adds r0, r1, r0
	ldrh r1, [r0]
	movs r0, #2
	str r0, [sp]
	movs r2, #0
	str r2, [sp, #4]
	movs r0, #5
	str r0, [sp, #8]
	adds r0, r6, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08055b5c
_0820F2E2:
	adds r0, r6, #0
	bl FUN_08055c04
	adds r6, #0x94
	ldr r3, [sp, #0x18]
	adds r3, #2
	str r3, [sp, #0x18]
	movs r5, #1
	add sl, r5
	mov r0, sl
	cmp r0, #4
	ble _0820F20C
_0820F2FA:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820F30C: .4byte 0x085AF0BA
