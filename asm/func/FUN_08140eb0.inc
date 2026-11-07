	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	ldr r0, _08140EC8 @ =0x0000046C
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08140ECC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08140ECE
	.align 2, 0
_08140EC8: .4byte 0x0000046C
_08140ECC:
	movs r0, #0
_08140ECE:
	cmp r0, #0
	beq _08140F1C
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r4, [r0]
	movs r2, #0xb4
	lsls r2, r2, #3
	adds r0, r6, r2
	ldr r1, [r0]
	movs r5, #1
	ldr r3, _08140F6C @ =0x0000046D
	adds r0, r6, r3
	movs r2, #0
	strb r5, [r0]
	subs r3, #2
	adds r0, r6, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r6, r3
	strb r5, [r0]
	adds r3, #0x25
	adds r0, r6, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0xd6
	lsls r3, r3, #3
	adds r1, r4, r3
	str r2, [sp]
	mov r0, sp
	ldr r2, _08140F70 @ =0x05000002
	bl CpuSet
	ldr r0, _08140F74 @ =0x00000667
	adds r4, r4, r0
	strb r5, [r4]
_08140F1C:
	adds r0, r6, #0
	bl EnemyBat_UpdateCurveBend
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r4, r0, #0
	ldr r2, _08140F78 @ =0x000004A4
	adds r0, r6, r2
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r6, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r6, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _08140F54
	rsbs r2, r2, #0
_08140F54:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _08140F7C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08140F62
	rsbs r2, r2, #0
_08140F62:
	cmp r2, #0x20
	bgt _08140F7C
	movs r0, #1
	b _08140FE6
	.align 2, 0
_08140F6C: .4byte 0x0000046D
_08140F70: .4byte 0x05000002
_08140F74: .4byte 0x00000667
_08140F78: .4byte 0x000004A4
_08140F7C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _08140F88
	cmp r1, #0
	beq _08140FE4
_08140F88:
	asrs r1, r1, #0x10
	bl ArcTan2_8
	strb r0, [r6, #5]
	ldr r2, _08140FAC @ =gSineTable
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r4, r0
	cmp r0, #0
	blt _08140FB0
	asrs r1, r0, #0xc
	b _08140FB6
	.align 2, 0
_08140FAC: .4byte gSineTable
_08140FB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08140FB6:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r1, _08140FD4 @ =gSineTable
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _08140FD8
	asrs r1, r0, #0xc
	b _08140FDE
	.align 2, 0
_08140FD4: .4byte gSineTable
_08140FD8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08140FDE:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
_08140FE4:
	movs r0, #0
_08140FE6:
	cmp r0, #0
	beq _081410B4
	adds r0, r6, #0
	bl FUN_081406b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081410BE
	ldr r2, _0814102C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08141030 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08141034 @ =0x0203B400
	adds r0, r0, r2
	ldrb r4, [r0]
	ldr r0, _08141038 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r1, _0814103C @ =gSineTable
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	cmp r0, #0
	blt _08141040
	asrs r0, r0, #4
	b _08141046
	.align 2, 0
_0814102C: .4byte 0x030046B8
_08141030: .4byte 0x000003FF
_08141034: .4byte 0x0203B400
_08141038: .4byte 0x03002BE0
_0814103C: .4byte gSineTable
_08141040:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_08141046:
	add r3, sp, #4
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08141074 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08141078
	asrs r0, r0, #4
	b _0814107E
	.align 2, 0
_08141074: .4byte 0xFFFF0000
_08141078:
	rsbs r0, r0, #0
	asrs r0, r0, #4
	rsbs r0, r0, #0
_0814107E:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081410B0 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r1, r3, #0
	bl EnemyBat_BeginCurveMove
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r1, r3
	movs r2, #9
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	b _081410BC
	.align 2, 0
_081410B0: .4byte 0xFFFF0000
_081410B4:
	ldr r0, _081410C8 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
_081410BC:
	str r0, [r1]
_081410BE:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081410C8: .4byte 0x00000484
