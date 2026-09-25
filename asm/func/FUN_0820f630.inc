	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r0, #0
	str r0, [r6, #0x18]
	movs r1, #0xdc
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r7, [r0]
	adds r5, r6, #0
	adds r5, #0x28
	movs r2, #0
	mov sl, r2
	add r3, sp, #4
	mov r8, r3
	ldr r4, _0820F6F4 @ =0x085AF0D8
	mov sb, r4
_0820F65A:
	movs r1, #0xd5
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	mov r4, sb
	ldrb r4, [r4]
	lsls r4, r4, #0x18
	asrs r4, r4, #0x18
	mov ip, r4
	adds r1, #2
	adds r0, r6, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	mov r4, sb
	movs r3, #1
	ldrsb r3, [r4, r3]
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r6, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	add r2, ip
	adds r1, r1, r3
	mov r3, r8
	strh r2, [r3]
	strh r1, [r3, #2]
	strh r0, [r3, #4]
	ldrh r1, [r7]
	ldrh r2, [r7, #2]
	str r3, [sp]
	adds r0, r5, #0
	movs r3, #0x10
	bl FUN_08055dac
	cmp r0, #0
	blt _0820F6E4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08055f1c
	ldrb r1, [r7, #0xb]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _0820F6BE
	ldrh r1, [r7, #8]
	adds r0, r5, #0
	bl FUN_08055fbc
_0820F6BE:
	adds r0, r5, #0
	movs r1, #2
	bl FUN_08055f5c
	ldrb r0, [r7, #0xa]
	ldr r4, _0820F6F8 @ =0x00000366
	adds r1, r6, r4
	ldr r3, _0820F6FC @ =0x00000367
	adds r2, r6, r3
	bl FUN_0820efc4
	adds r5, #0x94
	movs r4, #2
	add sb, r4
	movs r0, #1
	add sl, r0
	mov r1, sl
	cmp r1, #4
	ble _0820F65A
_0820F6E4:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0820F6F4: .4byte 0x085AF0D8
_0820F6F8: .4byte 0x00000366
_0820F6FC: .4byte 0x00000367
