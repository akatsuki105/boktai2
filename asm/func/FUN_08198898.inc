	push {r4, r5, r6, r7, lr}
	mov ip, r0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, ip
	ldr r2, [r0]
	ldr r1, _081989A0 @ =0x00000CEC
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _081988BC
	ldr r1, _081989A4 @ =0x00000185
	add r1, ip
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_081988BC:
	ldr r1, _081989A4 @ =0x00000185
	add r1, ip
	ldrb r0, [r1]
	mov r3, ip
	ldrb r3, [r3, #6]
	adds r0, r0, r3
	mov r4, ip
	strb r0, [r4, #6]
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	bge _081988D6
	rsbs r0, r0, #0
_081988D6:
	cmp r0, #9
	ble _081989C2
	mov r1, ip
	ldrh r0, [r1, #0x1c]
	movs r3, #0x9a
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	ldrh r0, [r1, #0x1e]
	movs r6, #0x9b
	lsls r6, r6, #1
	add r6, ip
	strh r0, [r6]
	ldrh r0, [r1, #0x20]
	movs r4, #0x9c
	lsls r4, r4, #1
	add r4, ip
	strh r0, [r4]
	ldr r0, [r2, #0x18]
	ldrh r0, [r0, #0x2c]
	movs r1, #0x96
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	ldr r0, [r2, #0x18]
	ldrh r0, [r0, #0x2e]
	adds r0, #0xdc
	movs r5, #0x97
	lsls r5, r5, #1
	add r5, ip
	strh r0, [r5]
	ldr r0, [r2, #0x18]
	ldrh r0, [r0, #0x30]
	movs r2, #0x98
	lsls r2, r2, #1
	add r2, ip
	strh r0, [r2]
	ldrh r0, [r1]
	ldrh r1, [r3]
	subs r0, r0, r1
	movs r7, #0x9e
	lsls r7, r7, #1
	add r7, ip
	strh r0, [r7]
	ldrh r0, [r5]
	ldrh r1, [r6]
	subs r0, r0, r1
	movs r3, #0x9f
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	ldrh r0, [r2]
	ldrh r1, [r4]
	subs r0, r0, r1
	movs r3, #0xa0
	lsls r3, r3, #1
	add r3, ip
	strh r0, [r3]
	movs r1, #0xbe
	lsls r1, r1, #1
	add r1, ip
	movs r0, #0
	str r0, [r1]
	ldr r2, _081989A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _081989AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _081989B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08198976
	movs r4, #1
	rsbs r4, r4, #0
	adds r1, r4, #0
_08198976:
	movs r0, #0xc1
	lsls r0, r0, #1
	add r0, ip
	strb r1, [r0]
	movs r0, #0
	ldrsh r1, [r7, r0]
	cmp r1, #0
	bge _08198988
	rsbs r1, r1, #0
_08198988:
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	bge _08198992
	rsbs r0, r0, #0
_08198992:
	cmp r1, r0
	bge _081989B8
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _081989B4 @ =FUN_081989cc
	b _081989C0
	.align 2, 0
_081989A0: .4byte 0x00000CEC
_081989A4: .4byte 0x00000185
_081989A8: .4byte 0x030046B8
_081989AC: .4byte 0x000003FF
_081989B0: .4byte 0x0203B400
_081989B4: .4byte FUN_081989cc
_081989B8:
	movs r1, #0xb6
	lsls r1, r1, #1
	add r1, ip
	ldr r0, _081989C8 @ =FUN_08198a88
_081989C0:
	str r0, [r1]
_081989C2:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081989C8: .4byte FUN_08198a88
