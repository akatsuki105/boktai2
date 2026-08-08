	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08223CAC @ =0x030044E0
	ldr r0, [r0]
	cmp r0, #0
	beq _08223C0C
	ldr r0, _08223CB0 @ =0x00000F39
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08223CB4 @ =0x00000E38
	adds r0, r5, r1
	strh r2, [r0]
_08223C0C:
	ldr r2, _08223CB0 @ =0x00000F39
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08223CA6
	ldr r1, _08223CB8 @ =0x00000F14
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08223CA6
	subs r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	subs r0, #1
	ldr r2, _08223CBC @ =0x00000DBA
	adds r1, r5, r2
	movs r2, #0
	strh r0, [r1]
	ldr r1, _08223CC0 @ =0x00000F58
	adds r0, r5, r1
	str r2, [r0]
	ldr r2, _08223CC4 @ =0x00000F4C
	adds r1, r5, r2
	ldr r0, _08223CC8 @ =FUN_08223ad0
	str r0, [r1]
	ldr r1, _08223CCC @ =0x00000F3A
	adds r0, r5, r1
	ldrh r3, [r0]
	subs r2, #0x36
	adds r6, r5, r2
	ldrb r0, [r6]
	lsls r0, r0, #0x1c
	lsrs r0, r0, #0x1c
	subs r1, #0x22
	adds r4, r5, r1
	strh r0, [r4]
	movs r2, #3
	ldrb r1, [r6]
	movs r0, #0x10
	rsbs r0, r0, #0
	ands r0, r1
	orrs r0, r2
	strb r0, [r6]
	lsls r3, r3, #4
	ldrh r1, [r6]
	movs r2, #0xf
	adds r0, r2, #0
	ands r0, r1
	orrs r0, r3
	strh r0, [r6]
	ldrh r0, [r4]
	cmp r0, #3
	bne _08223C98
	ldrb r1, [r6]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #3
	bne _08223C98
	ldr r2, _08223CD0 @ =0x00000DEC
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r2, _08223CD4 @ =0x00000F42
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08223CD8 @ =0x00000DF2
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
_08223C98:
	movs r0, #1
	movs r1, #0xf2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldrb r1, [r2]
	orrs r0, r1
	strb r0, [r2]
_08223CA6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08223CAC: .4byte 0x030044E0
_08223CB0: .4byte 0x00000F39
_08223CB4: .4byte 0x00000E38
_08223CB8: .4byte 0x00000F14
_08223CBC: .4byte 0x00000DBA
_08223CC0: .4byte 0x00000F58
_08223CC4: .4byte 0x00000F4C
_08223CC8: .4byte FUN_08223ad0
_08223CCC: .4byte 0x00000F3A
_08223CD0: .4byte 0x00000DEC
_08223CD4: .4byte 0x00000F42
_08223CD8: .4byte 0x00000DF2
