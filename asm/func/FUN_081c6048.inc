	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	subs r1, #0xcc
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C6068
	b _081C62FE
_081C6068:
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r0, r5, r3
	adds r2, #0x68
	adds r1, r5, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _081C607C
	b _081C62DE
_081C607C:
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	subs r3, #0xc
	adds r0, r5, r3
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #8
	ldrh r0, [r0, #8]
	ldrh r1, [r5, #8]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _081C60C8
	ldr r0, _081C60C4 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081C60D6
	.align 2, 0
_081C60C4: .4byte 0xFFFFFF00
_081C60C8:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081C60D6
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081C60D6:
	adds r0, r1, #0
	cmp r0, #0
	bge _081C60DE
	rsbs r0, r0, #0
_081C60DE:
	adds r3, r0, #0
	cmp r3, #0x17
	ble _081C60E6
	b _081C62BC
_081C60E6:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #1
	bls _081C60F6
	cmp r0, #4
	bne _081C619C
_081C60F6:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r3, _081C616C @ =0x000006AC
	adds r1, r6, r3
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C6188
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _081C6188
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081C6170 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081C6174 @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _081C6178 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C617C @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C6180 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _081C6184 @ =0x082522DC
	adds r0, r5, #0
	movs r2, #0x6f
	bl Enemy_ClearPendingState
	b _081C62FE
	.align 2, 0
_081C616C: .4byte 0x000006AC
_081C6170: .4byte 0x00000469
_081C6174: .4byte 0x0000046A
_081C6178: .4byte 0x00000484
_081C617C: .4byte Enemy_ClearStateBegun
_081C6180: .4byte 0x0000046B
_081C6184: .4byte 0x082522DC
_081C6188:
	movs r1, #8
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C619A
	b _081C62CC
_081C619A:
	b _081C62D0
_081C619C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _081C6210 @ =0x000006AC
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C622C
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r0, r6, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _081C622C
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r4, [r0]
	ldr r3, _081C6214 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r6, _081C6218 @ =0x0000046A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r1, _081C621C @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #4
	adds r0, r5, r2
	movs r1, #1
	strb r1, [r0]
	ldr r3, _081C6220 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C6224 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _081C6228 @ =0x082522DC
	adds r0, r5, #0
	movs r2, #0x7c
	bl Enemy_ClearPendingState
	b _081C62FE
	.align 2, 0
_081C6210: .4byte 0x000006AC
_081C6214: .4byte 0x00000469
_081C6218: .4byte 0x0000046A
_081C621C: .4byte 0x00000484
_081C6220: .4byte Enemy_ClearStateBegun
_081C6224: .4byte 0x0000046B
_081C6228: .4byte 0x082522DC
_081C622C:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r6, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhs _081C6188
	cmp r3, #5
	bgt _081C6188
	ldr r3, _081C62A4 @ =0x000006CA
	adds r0, r6, r3
	ldrh r4, [r0]
	cmp r4, #0
	bne _081C6188
	movs r2, #2
	movs r1, #1
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r0, r5, r6
	strb r4, [r0]
	ldr r3, _081C62A8 @ =0x00000469
	adds r0, r5, r3
	strb r2, [r0]
	adds r6, #2
	adds r0, r5, r6
	strb r1, [r0]
	ldr r2, _081C62AC @ =0x00000484
	adds r0, r5, r2
	str r4, [r0]
	adds r3, #3
	adds r0, r5, r3
	strb r1, [r0]
	ldr r3, _081C62B0 @ =Enemy_ClearStateBegun
	movs r2, #0x10
	adds r6, #3
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _081C62B4 @ =0x0000046B
	adds r0, r5, r1
	strb r4, [r0]
	adds r6, #0xe6
	adds r0, r5, r6
	strb r2, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	strh r4, [r0]
	ldr r1, _081C62B8 @ =0x082522DC
	adds r0, r5, #0
	movs r2, #0x81
	bl Enemy_ClearPendingState
	b _081C62FE
	.align 2, 0
_081C62A4: .4byte 0x000006CA
_081C62A8: .4byte 0x00000469
_081C62AC: .4byte 0x00000484
_081C62B0: .4byte Enemy_ClearStateBegun
_081C62B4: .4byte 0x0000046B
_081C62B8: .4byte 0x082522DC
_081C62BC:
	movs r1, #8
	movs r2, #0xd5
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C62D0
_081C62CC:
	movs r0, #1
	b _081C62D2
_081C62D0:
	movs r0, #0
_081C62D2:
	cmp r0, #0
	bne _081C62FE
	adds r0, r5, #0
	bl FUN_081c7228
	b _081C62FE
_081C62DE:
	movs r1, #8
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r0, r6, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C62F2
	movs r0, #1
	b _081C62F4
_081C62F2:
	movs r0, #0
_081C62F4:
	cmp r0, #0
	bne _081C62FE
	adds r0, r5, #0
	bl FUN_081c7228
_081C62FE:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
