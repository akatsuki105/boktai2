	push {lr}
	adds r2, r0, #0
	ldr r1, _08223A58 @ =0x00000DB8
	adds r0, r2, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0x19
	bne _08223AC0
	adds r1, #4
	adds r0, r2, r1
	movs r3, #0
	ldrsh r1, [r0, r3]
	cmp r1, #0
	bne _08223AC0
	ldr r3, _08223A5C @ =0x00000DBA
	adds r0, r2, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r0, #0x66
	cmp r0, #0
	bge _08223A28
	rsbs r0, r0, #0
_08223A28:
	cmp r0, #9
	bgt _08223AC0
	ldr r3, _08223A60 @ =0x00000F58
	adds r0, r2, r3
	str r1, [r0]
	ldr r0, _08223A64 @ =0x00000F4C
	adds r1, r2, r0
	ldr r0, _08223A68 @ =FUN_08223ad0
	str r0, [r1]
	ldr r0, _08223A6C @ =0x030047E0
	ldrb r0, [r0, #0xe]
	cmp r0, #5
	beq _08223A4A
	cmp r0, #0
	beq _08223A4A
	cmp r0, #4
	bne _08223A70
_08223A4A:
	movs r3, #0xf4
	lsls r3, r3, #4
	adds r1, r2, r3
	movs r0, #0xe1
	lsls r0, r0, #3
	b _08223A78
	.align 2, 0
_08223A58: .4byte 0x00000DB8
_08223A5C: .4byte 0x00000DBA
_08223A60: .4byte 0x00000F58
_08223A64: .4byte 0x00000F4C
_08223A68: .4byte FUN_08223ad0
_08223A6C: .4byte 0x030047E0
_08223A70:
	movs r0, #0xf4
	lsls r0, r0, #4
	adds r1, r2, r0
	ldr r0, _08223AAC @ =0x00002A30
_08223A78:
	strh r0, [r1]
	ldr r1, _08223AB0 @ =0x00000F2B
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08223AC8
	ldr r3, _08223AB4 @ =0x00000DA4
	adds r0, r2, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x7f
	beq _08223AC8
	ldr r1, _08223AB8 @ =0x00000D9C
	adds r0, r2, r1
	ldr r0, [r0]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08223AC8
	movs r3, #0xf5
	lsls r3, r3, #4
	adds r1, r2, r3
	ldr r0, _08223ABC @ =FUN_082239c0
	b _08223AC6
	.align 2, 0
_08223AAC: .4byte 0x00002A30
_08223AB0: .4byte 0x00000F2B
_08223AB4: .4byte 0x00000DA4
_08223AB8: .4byte 0x00000D9C
_08223ABC: .4byte FUN_082239c0
_08223AC0:
	ldr r0, _08223ACC @ =0x00000F4C
	adds r1, r2, r0
	movs r0, #0
_08223AC6:
	str r0, [r1]
_08223AC8:
	pop {r0}
	bx r0
	.align 2, 0
_08223ACC: .4byte 0x00000F4C
