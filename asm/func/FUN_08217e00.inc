	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #8
	adds r5, r0, #0
	ldr r0, _08217E28 @ =0x0000166C
	adds r7, r5, r0
	ldr r1, _08217E2C @ =0x00001FE2
	adds r2, r5, r1
	movs r3, #0
	ldrsh r4, [r2, r3]
	cmp r4, #1
	bne _08217E1E
	b _08217F14
_08217E1E:
	cmp r4, #1
	bgt _08217E30
	cmp r4, #0
	beq _08217E38
	b _08218114
	.align 2, 0
_08217E28: .4byte 0x0000166C
_08217E2C: .4byte 0x00001FE2
_08217E30:
	cmp r4, #2
	bne _08217E36
	b _082180E2
_08217E36:
	b _08218114
_08217E38:
	movs r0, #0x80
	lsls r0, r0, #2
	ldr r1, [r5, #0x44]
	ands r0, r1
	cmp r0, #0
	bne _08217E60
	movs r0, #0x20
	ands r1, r0
	cmp r1, #0
	bne _08217E54
	bl FUN_0823cd38
	bl FUN_08218b20
_08217E54:
	ldr r1, _08217E5C @ =0x00001FE6
	adds r0, r5, r1
	strh r4, [r0]
	b _08217E6E
	.align 2, 0
_08217E5C: .4byte 0x00001FE6
_08217E60:
	ldr r0, _08217EF8 @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r5, #0x44]
	ldr r3, _08217EFC @ =0x00001FE6
	adds r1, r5, r3
	movs r0, #0x56
	strh r0, [r1]
_08217E6E:
	movs r0, #0
	str r0, [sp, #4]
	ldr r6, _08217F00 @ =0x00000938
	adds r4, r7, r6
	ldr r2, _08217F04 @ =0x05000008
	add r0, sp, #4
	adds r1, r4, #0
	bl CpuSet
	bl FUN_0823cd38
	adds r1, r4, #0
	movs r2, #5
	bl CpuSet
	movs r1, #0
	ldrb r0, [r4]
	cmp r0, #0
	beq _08217EA6
	adds r2, r6, #0
_08217E96:
	adds r2, #2
	adds r1, #1
	cmp r1, #4
	bgt _08217EA6
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08217E96
_08217EA6:
	movs r2, #4
	cmp r1, #5
	beq _08217EAE
	adds r2, r1, #0
_08217EAE:
	ldr r1, _08217F08 @ =0x00000972
	adds r0, r7, r1
	movs r4, #0
	strh r2, [r0]
	ldr r1, [r5, #0x38]
	movs r0, #2
	movs r2, #0
	bl FUN_0822c398
	str r4, [sp]
	movs r0, #2
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	str r4, [r5, #0x64]
	ldr r3, _08217F0C @ =0x00000974
	adds r0, r7, r3
	strh r4, [r0]
	adds r0, r5, #0
	bl FUN_08217bfc
	adds r0, r5, #0
	bl FUN_08217a10
	adds r0, r5, #0
	bl FUN_08217b48
	str r4, [r5, #0x68]
	str r4, [r5, #0x6c]
	ldr r0, _08217F10 @ =0x00000976
	adds r1, r7, r0
	movs r0, #1
	strh r0, [r1]
	b _08218114
	.align 2, 0
_08217EF8: .4byte 0xFFFFFDFF
_08217EFC: .4byte 0x00001FE6
_08217F00: .4byte 0x00000938
_08217F04: .4byte 0x05000008
_08217F08: .4byte 0x00000972
_08217F0C: .4byte 0x00000974
_08217F10: .4byte 0x00000976
_08217F14:
	ldr r1, _08217F3C @ =0x030044E0
	mov sb, r1
	ldrh r1, [r1, #2]
	movs r3, #2
	adds r0, r3, #0
	ands r0, r1
	cmp r0, #0
	beq _08217F40
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08217d5c
	cmp r0, #0
	bne _08217F36
	b _08218114
_08217F36:
	movs r0, #2
	b _0821812C
	.align 2, 0
_08217F3C: .4byte 0x030044E0
_08217F40:
	ands r4, r1
	lsls r0, r4, #0x10
	cmp r0, #0
	beq _08217F78
	ldr r0, _08217F5C @ =0x00001FE6
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x55
	beq _08217FAC
	cmp r0, #0x56
	bne _08217F60
_08217F58:
	strh r3, [r2]
	b _08218114
	.align 2, 0
_08217F5C: .4byte 0x00001FE6
_08217F60:
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r3, #0
	ldrsh r1, [r4, r3]
	adds r0, r5, #0
	bl FUN_08217cd0
	cmp r0, #0
	bne _08217F76
	b _08218114
_08217F76:
	b _08217F92
_08217F78:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _08217FA4
	ldr r0, _08217FA0 @ =0x00001FE6
	adds r4, r5, r0
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0x56
	beq _08217F58
	movs r0, #0xdc
	bl PlaySound_082406e0
_08217F92:
	movs r0, #0x56
	strh r0, [r4]
	adds r0, r5, #0
	bl FUN_08217a10
	b _08218114
	.align 2, 0
_08217FA0: .4byte 0x00001FE6
_08217FA4:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08217FB4
_08217FAC:
	adds r0, r5, #0
	bl FUN_08217c6c
	b _08218114
_08217FB4:
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _08217FD4
	ldr r3, _08217FD0 @ =0x00001FDE
	adds r1, r5, r3
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #0
	ble _08217FF0
	subs r0, r2, #1
	b _08217FEE
	.align 2, 0
_08217FD0: .4byte 0x00001FDE
_08217FD4:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08218004
	ldr r0, _08218000 @ =0x00001FDE
	adds r1, r5, r0
	ldrh r2, [r1]
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, #3
	bgt _08217FF0
	adds r0, r2, #1
_08217FEE:
	strh r0, [r1]
_08217FF0:
	adds r0, r5, #0
	bl FUN_08217b48
	movs r0, #0xdc
	bl PlaySound_082406e0
	b _08218114
	.align 2, 0
_08218000: .4byte 0x00001FDE
_08218004:
	movs r0, #0
	mov r8, r0
	movs r6, #0
	movs r4, #0x20
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _0821801A
	movs r1, #1
	mov r8, r1
	b _08218060
_0821801A:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _08218028
	movs r3, #2
	mov r8, r3
	b _08218060
_08218028:
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #0x30
	ands r0, r1
	cmp r0, #0
	beq _0821805E
	ldr r0, [r5, #0x68]
	adds r0, #1
	str r0, [r5, #0x68]
	cmp r0, #0xe
	ble _08218060
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _08218060
	mov r3, sb
	ldrh r1, [r3]
	adds r0, r4, #0
	ands r0, r1
	movs r1, #2
	mov r8, r1
	cmp r0, #0
	beq _08218060
	movs r3, #1
	mov r8, r3
	b _08218060
_0821805E:
	str r6, [r5, #0x68]
_08218060:
	ldr r4, _0821807C @ =0x030044E0
	ldrh r1, [r4, #2]
	movs r0, #0x40
	mov sb, r0
	ands r0, r1
	cmp r0, #0
	bne _082180AA
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08218080
	movs r6, #2
	b _082180B0
	.align 2, 0
_0821807C: .4byte 0x030044E0
_08218080:
	ldrh r0, [r4]
	movs r1, #0xc0
	ands r1, r0
	cmp r1, #0
	beq _082180AE
	ldr r0, [r5, #0x6c]
	adds r0, #1
	str r0, [r5, #0x6c]
	cmp r0, #0xe
	ble _082180B0
	movs r1, #5
	bl Mod
	cmp r0, #0
	bne _082180B0
	ldrh r1, [r4]
	mov r0, sb
	ands r0, r1
	movs r6, #2
	cmp r0, #0
	beq _082180B0
_082180AA:
	movs r6, #1
	b _082180B0
_082180AE:
	str r1, [r5, #0x6c]
_082180B0:
	mov r1, r8
	cmp r1, #1
	bne _082180BE
	adds r0, r5, #0
	bl FUN_0821813c
	b _082180CA
_082180BE:
	mov r3, r8
	cmp r3, #2
	bne _082180CA
	adds r0, r5, #0
	bl FUN_082183e0
_082180CA:
	cmp r6, #1
	bne _082180D6
	adds r0, r5, #0
	bl FUN_0821869c
	b _08218114
_082180D6:
	cmp r6, #2
	bne _08218114
	adds r0, r5, #0
	bl FUN_08218910
	b _08218114
_082180E2:
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, [r5, #0x44]
	orrs r0, r1
	str r0, [r5, #0x44]
	ldr r0, _08218110 @ =0x00001FA4
	adds r4, r5, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08218b34
	bl FUN_0823cd38
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #5
	bl CpuSet
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #1
	b _0821812C
	.align 2, 0
_08218110: .4byte 0x00001FA4
_08218114:
	adds r0, r7, #0
	adds r0, #0xc0
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, r4, #0
	bl FUN_082372cc
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_082372cc
	movs r0, #0
_0821812C:
	add sp, #8
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
