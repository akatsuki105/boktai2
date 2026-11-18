	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	adds r2, r4, #0
	adds r2, #0x45
	ldrb r1, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08197C56
	movs r0, #2
	rsbs r0, r0, #0
	ands r0, r1
	movs r1, #0
	strb r0, [r2]
	adds r0, r4, #0
	adds r0, #0x5a
	strb r1, [r0]
	movs r0, #1
	b _08197C58
_08197C56:
	movs r0, #0
_08197C58:
	cmp r0, #0
	beq _08197CF6
	ldr r1, _08197CA0 @ =0x00000C98
	adds r0, r4, r1
	movs r3, #0
	strh r3, [r0]
	ldr r2, _08197CA4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08197CA8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08197CAC @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	ldr r2, _08197CB0 @ =0x00000C9D
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _08197CB4 @ =0x00000C54
	adds r1, r4, r0
	ldr r0, _08197CB8 @ =FUN_08197244
	str r0, [r1]
	ldr r1, _08197CBC @ =0x00000C9A
	adds r0, r4, r1
	strh r3, [r0]
	adds r2, #0x28
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _08197CD8
	cmp r0, #1
	bgt _08197CC0
	cmp r0, #0
	beq _08197CC6
	b _08197CF0
	.align 2, 0
_08197CA0: .4byte 0x00000C98
_08197CA4: .4byte 0x030046B8
_08197CA8: .4byte 0x000003FF
_08197CAC: .4byte 0x0203B400
_08197CB0: .4byte 0x00000C9D
_08197CB4: .4byte 0x00000C54
_08197CB8: .4byte FUN_08197244
_08197CBC: .4byte 0x00000C9A
_08197CC0:
	cmp r0, #2
	beq _08197CE8
	b _08197CF0
_08197CC6:
	ldr r3, _08197CD0 @ =0x00000C58
	adds r1, r4, r3
	ldr r0, _08197CD4 @ =FUN_08199d48
	b _08197CEE
	.align 2, 0
_08197CD0: .4byte 0x00000C58
_08197CD4: .4byte FUN_08199d48
_08197CD8:
	ldr r0, _08197CE0 @ =0x00000C58
	adds r1, r4, r0
	ldr r0, _08197CE4 @ =FUN_08199cf0
	b _08197CEE
	.align 2, 0
_08197CE0: .4byte 0x00000C58
_08197CE4: .4byte FUN_08199cf0
_08197CE8:
	ldr r2, _08197D3C @ =0x00000C58
	adds r1, r4, r2
	ldr r0, _08197D40 @ =FUN_08199c98
_08197CEE:
	str r0, [r1]
_08197CF0:
	ldr r0, _08197D44 @ =0x0000016F
	bl PlaySound_082406e0
_08197CF6:
	adds r0, r4, #0
	bl FUN_08196378
	ldr r3, _08197D48 @ =0x00000C54
	adds r0, r4, r3
	ldr r1, [r0]
	cmp r1, #0
	beq _08197D0C
	adds r0, r4, #0
	bl _call_via_r1
_08197D0C:
	ldr r0, _08197D4C @ =0x00000C9A
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	ldr r3, _08197D50 @ =0x0000FFFF
	adds r1, r3, #0
	ands r1, r0
	ldr r3, _08197D54 @ =0x000003FF
	adds r0, r3, #0
	ands r1, r0
	cmp r1, #0
	bne _08197DD8
	strh r1, [r2]
	ldr r1, _08197D58 @ =0x00000CC5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _08197D6C
	cmp r0, #1
	bgt _08197D5C
	cmp r0, #0
	beq _08197D62
	b _08197DD8
	.align 2, 0
_08197D3C: .4byte 0x00000C58
_08197D40: .4byte FUN_08199c98
_08197D44: .4byte 0x0000016F
_08197D48: .4byte 0x00000C54
_08197D4C: .4byte 0x00000C9A
_08197D50: .4byte 0x0000FFFF
_08197D54: .4byte 0x000003FF
_08197D58: .4byte 0x00000CC5
_08197D5C:
	cmp r0, #2
	beq _08197D98
	b _08197DD8
_08197D62:
	ldr r2, _08197D68 @ =0x00000C58
	adds r1, r4, r2
	b _08197DD4
	.align 2, 0
_08197D68: .4byte 0x00000C58
_08197D6C:
	ldr r3, _08197D7C @ =0x00000C58
	adds r1, r4, r3
	ldr r2, [r1]
	ldr r3, _08197D80 @ =FUN_08199c98
	cmp r2, r3
	bne _08197D88
	ldr r0, _08197D84 @ =FUN_08199cf0
	b _08197DD6
	.align 2, 0
_08197D7C: .4byte 0x00000C58
_08197D80: .4byte FUN_08199c98
_08197D84: .4byte FUN_08199cf0
_08197D88:
	ldr r0, _08197D94 @ =FUN_08199cf0
	cmp r2, r0
	bne _08197DD8
	str r3, [r1]
	b _08197DD8
	.align 2, 0
_08197D94: .4byte FUN_08199cf0
_08197D98:
	ldr r2, _08197DBC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08197DC0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08197DC4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _08197DD0
	ldr r2, _08197DC8 @ =0x00000C58
	adds r1, r4, r2
	ldr r0, _08197DCC @ =FUN_08199c98
	b _08197DD6
	.align 2, 0
_08197DBC: .4byte 0x030046B8
_08197DC0: .4byte 0x000003FF
_08197DC4: .4byte 0x0203B400
_08197DC8: .4byte 0x00000C58
_08197DCC: .4byte FUN_08199c98
_08197DD0:
	ldr r3, _08197DE0 @ =0x00000C58
	adds r1, r4, r3
_08197DD4:
	ldr r0, _08197DE4 @ =FUN_08199d48
_08197DD6:
	str r0, [r1]
_08197DD8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08197DE0: .4byte 0x00000C58
_08197DE4: .4byte FUN_08199d48
