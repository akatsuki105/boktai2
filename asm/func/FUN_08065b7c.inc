	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08065BA4
	cmp r1, #0
	blt _08065BA4
	ldr r0, _08065BA8 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08065BA4
	ldr r0, _08065BAC @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08065BB0
_08065BA4:
	movs r4, #0
	b _08065BBE
	.align 2, 0
_08065BA8: .4byte 0x030046A8
_08065BAC: .4byte 0x030046AC
_08065BB0:
	ldr r0, _08065BD0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08065BBE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08065BD4
	adds r0, #4
	b _08065BE0
	.align 2, 0
_08065BD0: .4byte 0x030046A4
_08065BD4:
	ldr r0, _08065C6C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08065BE0:
	ldrh r0, [r0, #2]
	bl FUN_08065ad0
	cmp r0, #0
	beq _08065CB0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _08065CB0
	ldr r2, _08065C70 @ =0x00000395
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08065CB0
	adds r0, r7, #0
	adds r0, #0x2c
	bl FUN_081d2230
	cmp r0, #0
	bne _08065CB0
	movs r5, #0xe0
	lsls r5, r5, #1
	adds r6, r7, r5
	ldrh r0, [r6]
	ldr r5, _08065C6C @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r6]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl Div
	lsls r4, r4, #8
	adds r1, r4, #0
	adds r1, #0x80
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r3, r7, r2
	strh r1, [r3]
	lsls r0, r0, #8
	adds r2, r0, #0
	adds r2, #0x80
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r2, [r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r7, r2
	str r3, [r1]
	adds r2, r4, #1
	adds r4, #0xff
	adds r3, r0, #1
	adds r0, #0xff
	movs r5, #0x2c
	ldrsh r1, [r7, r5]
	cmp r1, r2
	bge _08065C74
	strh r2, [r7, #0x2c]
	b _08065C7A
	.align 2, 0
_08065C6C: .4byte 0x030046A4
_08065C70: .4byte 0x00000395
_08065C74:
	cmp r1, r4
	ble _08065C7A
	strh r4, [r7, #0x2c]
_08065C7A:
	movs r2, #0x30
	ldrsh r1, [r7, r2]
	cmp r1, r3
	bge _08065C86
	strh r3, [r7, #0x30]
	b _08065C8C
_08065C86:
	cmp r1, r0
	ble _08065C8C
	strh r0, [r7, #0x30]
_08065C8C:
	movs r5, #0x82
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, r7, #0
	adds r2, #0xa8
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_08065CB0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
