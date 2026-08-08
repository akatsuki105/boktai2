	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x60
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	str r2, [sp, #0x20]
	movs r2, #0xc
	ldrsh r1, [r0, r2]
	ldr r3, [sp, #0x20]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08235AD4
	ldr r0, [sp, #0x18]
	movs r2, #0x10
	ldrsh r1, [r0, r2]
	movs r7, #4
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08235AD4
	ldr r0, [sp, #0x18]
	movs r2, #0x14
	ldrsh r1, [r0, r2]
	ldr r3, [sp, #0x1c]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08235AD4
	ldr r0, [sp, #0x18]
	movs r2, #0x18
	ldrsh r1, [r0, r2]
	movs r7, #4
	ldrsh r0, [r3, r7]
	cmp r1, r0
	bne _08235AD4
	movs r0, #2
	b _08235F2E
_08235AD4:
	ldr r0, _08235AF8 @ =0x030046A4
	ldr r0, [r0]
	ldr r5, [r0, #0x14]
	ldr r1, [sp, #0x20]
	ldrh r0, [r1]
	ldr r2, [sp, #0x18]
	strh r0, [r2, #0xc]
	ldrh r0, [r1, #4]
	strh r0, [r2, #0x10]
	movs r3, #0xff
	movs r7, #0xff
	movs r0, #0
	str r0, [sp, #0x24]
	movs r1, #0
	str r1, [sp, #0x28]
	movs r6, #0
	b _08235B40
	.align 2, 0
_08235AF8: .4byte 0x030046A4
_08235AFC:
	lsls r1, r6, #2
	adds r0, r5, #4
	adds r0, r0, r1
	ldr r0, [r0]
	adds r0, r5, r0
	str r0, [sp, #0x24]
	ldr r0, [r0, #8]
	ldr r1, [sp, #0x24]
	adds r0, r1, r0
	str r0, [sp, #0x28]
	movs r4, #0
	ldrh r2, [r1]
	cmp r4, r2
	bge _08235B3E
_08235B18:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x20]
	adds r2, r4, #0
	str r3, [sp, #0x58]
	bl FUN_08235924
	ldr r3, [sp, #0x58]
	cmp r0, #0
	beq _08235B34
	adds r3, r6, #0
	adds r7, r4, #0
	ldrh r6, [r5]
	ldr r0, [sp, #0x24]
	ldrh r4, [r0]
_08235B34:
	adds r4, #1
	ldr r1, [sp, #0x24]
	ldrh r1, [r1]
	cmp r4, r1
	blt _08235B18
_08235B3E:
	adds r6, #1
_08235B40:
	ldrh r2, [r5]
	cmp r6, r2
	blt _08235AFC
	cmp r7, #0xff
	bne _08235B52
	movs r0, #0
	ldr r3, [sp, #0x18]
	strh r0, [r3]
	b _08235F2E
_08235B52:
	ldr r1, [sp, #0x18]
	ldrh r0, [r1, #4]
	cmp r0, r3
	beq _08235B60
	movs r0, #0
	strh r0, [r1]
	b _08235F2E
_08235B60:
	ldr r2, [sp, #0x18]
	ldrh r1, [r2, #6]
	cmp r1, r7
	bne _08235B8A
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	adds r7, r2, #0
	str r0, [r7, #0xc]
	str r1, [r7, #0x10]
	ldr r2, [sp, #0x18]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r3, [sp, #0x1c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	movs r0, #6
	b _08235F2A
_08235B8A:
	ldr r0, [sp, #0x24]
	cmp r0, #0
	beq _08235B96
	ldr r1, [sp, #0x28]
	cmp r1, #0
	bne _08235B9A
_08235B96:
	movs r0, #0
	b _08235F2E
_08235B9A:
	ldr r2, [sp, #0x24]
	ldr r0, [r2, #0xc]
	adds r0, r2, r0
	str r0, [sp, #0x2c]
	ldr r0, [r2, #0x10]
	adds r0, r2, r0
	str r0, [sp, #0x30]
	lsls r0, r7, #4
	mov r3, sp
	adds r3, #0xc
	str r3, [sp, #0x4c]
	movs r2, #0xff
	mov r1, sp
	adds r1, #0xa
_08235BB6:
	strh r2, [r1]
	subs r1, #2
	cmp r1, sp
	bge _08235BB6
	ldr r1, [sp, #0x28]
	adds r1, r1, r0
	mov sl, r1
	mov r0, sp
	strh r7, [r0]
	movs r2, #1
	str r2, [sp, #0x44]
	movs r6, #0
	adds r1, #4
	mov r3, sl
	ldrb r0, [r3, #4]
	cmp r0, #0xff
	beq _08235C78
_08235BD8:
	adds r0, r1, r6
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r7, [sp, #0x2c]
	adds r5, r7, r0
	movs r4, #0
	adds r1, r5, #6
	ldrb r0, [r5, #6]
	b _08235C56
_08235BEE:
	adds r0, r1, r4
	ldrb r2, [r0]
	mov r0, sp
	adds r1, r4, #1
	mov sb, r1
	ldrh r0, [r0]
	cmp r2, r0
	beq _08235C4A
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x20]
	bl FUN_08235924
	cmp r0, #0
	beq _08235C4A
	movs r7, #1
	ldr r2, [sp, #0x44]
	cmp r2, #0
	beq _08235C2C
	adds r0, r5, #6
	adds r0, r0, r4
	ldrb r3, [r0]
	mov r2, sp
	ldr r1, [sp, #0x44]
_08235C1C:
	ldrh r0, [r2]
	cmp r0, r3
	bne _08235C24
	movs r7, #0
_08235C24:
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _08235C1C
_08235C2C:
	cmp r7, #0
	beq _08235C4A
	ldr r3, [sp, #0x44]
	lsls r0, r3, #1
	mov r7, sp
	adds r1, r7, r0
	adds r0, r5, #6
	adds r0, r0, r4
	ldrb r0, [r0]
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x44]
_08235C4A:
	mov r4, sb
	cmp r4, #5
	bgt _08235C60
	adds r1, r5, #6
	adds r0, r1, r4
	ldrb r0, [r0]
_08235C56:
	cmp r0, #0xff
	beq _08235C60
	ldr r0, [sp, #0x44]
	cmp r0, #5
	bls _08235BEE
_08235C60:
	adds r6, #1
	cmp r6, #0xb
	bgt _08235C78
	mov r1, sl
	adds r1, #4
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08235C78
	ldr r2, [sp, #0x44]
	cmp r2, #5
	bls _08235BD8
_08235C78:
	ldr r3, [sp, #0x18]
	ldrh r1, [r3, #6]
	ldr r2, [sp, #0x4c]
	movs r3, #0xff
	adds r0, r2, #0
	adds r0, #0xa
_08235C84:
	strh r3, [r0]
	subs r0, #2
	cmp r0, r2
	bge _08235C84
	lsls r0, r1, #4
	ldr r7, [sp, #0x28]
	adds r0, r7, r0
	str r0, [sp, #0x34]
	ldr r0, [sp, #0x4c]
	strh r1, [r0]
	movs r1, #1
	str r1, [sp, #0x48]
	movs r6, #0
	ldr r1, [sp, #0x34]
	adds r1, #4
	ldr r2, [sp, #0x34]
	ldrb r0, [r2, #4]
	cmp r0, #0xff
	beq _08235D56
_08235CAA:
	adds r0, r1, r6
	ldrb r1, [r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, [sp, #0x2c]
	adds r5, r3, r0
	movs r4, #0
	adds r1, r5, #6
	ldrb r0, [r5, #6]
	adds r6, #1
	str r6, [sp, #0x50]
	cmp r0, #0xff
	beq _08235D3E
	ldr r7, [sp, #0x48]
	cmp r7, #5
	bhi _08235D3E
_08235CCC:
	adds r0, r1, r4
	ldrb r2, [r0]
	adds r0, r4, #1
	mov sb, r0
	ldr r1, [sp, #0x4c]
	ldrh r1, [r1]
	cmp r2, r1
	beq _08235D28
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x1c]
	bl FUN_08235924
	cmp r0, #0
	beq _08235D28
	movs r6, #1
	ldr r2, [sp, #0x48]
	cmp r2, #0
	beq _08235D0A
	adds r0, r5, #6
	adds r0, r0, r4
	ldrb r3, [r0]
	ldr r2, [sp, #0x4c]
	ldr r1, [sp, #0x48]
_08235CFA:
	ldrh r0, [r2]
	cmp r0, r3
	bne _08235D02
	movs r6, #0
_08235D02:
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bne _08235CFA
_08235D0A:
	cmp r6, #0
	beq _08235D28
	ldr r3, [sp, #0x48]
	lsls r1, r3, #1
	ldr r7, [sp, #0x4c]
	adds r1, r7, r1
	adds r0, r5, #6
	adds r0, r0, r4
	ldrb r0, [r0]
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x48]
_08235D28:
	mov r4, sb
	cmp r4, #5
	bgt _08235D3E
	adds r1, r5, #6
	adds r0, r1, r4
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08235D3E
	ldr r0, [sp, #0x48]
	cmp r0, #5
	bls _08235CCC
_08235D3E:
	ldr r6, [sp, #0x50]
	cmp r6, #0xb
	bgt _08235D56
	ldr r1, [sp, #0x34]
	adds r1, #4
	adds r0, r1, r6
	ldrb r0, [r0]
	cmp r0, #0xff
	beq _08235D56
	ldr r2, [sp, #0x48]
	cmp r2, #5
	bls _08235CAA
_08235D56:
	movs r6, #0
	ldr r3, [sp, #0x48]
	cmp r6, r3
	bge _08235D88
	ldr r2, [sp, #0x4c]
_08235D60:
	movs r4, #0
	ldr r7, [sp, #0x44]
	cmp r4, r7
	bge _08235D7E
	ldrh r1, [r2]
	mov r0, sp
_08235D6C:
	ldrh r3, [r0]
	cmp r1, r3
	bne _08235D74
	b _08235EC8
_08235D74:
	adds r0, #2
	adds r4, #1
	ldr r7, [sp, #0x44]
	cmp r4, r7
	blt _08235D6C
_08235D7E:
	adds r2, #2
	adds r6, #1
	ldr r0, [sp, #0x48]
	cmp r6, r0
	blt _08235D60
_08235D88:
	ldr r1, _08235D98 @ =0x0000FFFF
	str r1, [sp, #0x38]
	movs r2, #0xff
	str r2, [sp, #0x3c]
	movs r3, #0xff
	str r3, [sp, #0x40]
	movs r6, #0
	b _08235EA8
	.align 2, 0
_08235D98: .4byte 0x0000FFFF
_08235D9C:
	lsls r0, r6, #1
	ldr r1, [sp, #0x4c]
	adds r0, r1, r0
	ldrh r0, [r0]
	lsls r0, r0, #4
	ldr r2, [sp, #0x28]
	adds r0, r2, r0
	str r0, [sp, #0x34]
	movs r4, #0
	adds r6, #1
	str r6, [sp, #0x50]
	b _08235EA0
_08235DB4:
	lsls r0, r4, #1
	add r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #4
	ldr r7, [sp, #0x28]
	adds r7, r7, r0
	mov sl, r7
	movs r1, #0
	ldrb r0, [r7, #4]
	adds r4, #1
	mov sb, r4
	cmp r0, #0xff
	beq _08235E9E
	ldr r0, [sp, #0x34]
	adds r0, #4
	str r0, [sp, #0x54]
_08235DD4:
	movs r2, #0
	mov r8, r2
	ldr r3, [sp, #0x34]
	adds r3, #4
	ldr r7, [sp, #0x34]
	ldrb r0, [r7, #4]
	adds r2, r1, #1
	str r2, [sp, #0x5c]
	cmp r0, #0xff
	beq _08235E8C
	mov r0, sl
	adds r0, #4
	adds r6, r0, r1
_08235DEE:
	ldr r7, [sp, #0x24]
	ldrh r1, [r7, #2]
	ldrb r2, [r6]
	mov r0, r8
	adds r5, r3, r0
	ldrb r3, [r5]
	ldr r0, [sp, #0x30]
	bl FUN_0823595c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x38]
	cmp r0, r1
	bhs _08235E16
	str r0, [sp, #0x38]
	ldrb r5, [r5]
	str r5, [sp, #0x3c]
	ldrb r2, [r6]
	str r2, [sp, #0x40]
	b _08235E78
_08235E16:
	ldr r3, [sp, #0x38]
	cmp r0, r3
	bne _08235E78
	ldr r0, _08235EC0 @ =0x0000FFFF
	cmp r3, r0
	beq _08235E78
	ldr r7, [sp, #0x1c]
	movs r0, #0
	ldrsh r4, [r7, r0]
	ldrb r5, [r5]
	lsls r0, r5, #1
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, [sp, #0x2c]
	adds r0, r0, r1
	ldrh r1, [r0]
	subs r1, r4, r1
	movs r2, #4
	ldrsh r3, [r7, r2]
	ldrh r0, [r0, #2]
	subs r0, r3, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r2, r2, r0
	ldr r1, [sp, #0x3c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r7, [sp, #0x2c]
	adds r0, r0, r7
	ldrh r1, [r0]
	subs r1, r4, r1
	ldrh r0, [r0, #2]
	subs r0, r3, r0
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	adds r7, r0, #0
	muls r7, r0, r7
	adds r0, r7, #0
	adds r1, r1, r0
	cmp r2, r1
	bge _08235E78
	str r5, [sp, #0x3c]
	ldrb r0, [r6]
	str r0, [sp, #0x40]
_08235E78:
	movs r1, #1
	add r8, r1
	mov r2, r8
	cmp r2, #0xb
	bgt _08235E8C
	ldr r3, [sp, #0x54]
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08235DEE
_08235E8C:
	ldr r1, [sp, #0x5c]
	cmp r1, #0xb
	bgt _08235E9E
	mov r0, sl
	adds r0, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0xff
	bne _08235DD4
_08235E9E:
	mov r4, sb
_08235EA0:
	ldr r3, [sp, #0x44]
	cmp r4, r3
	blt _08235DB4
	ldr r6, [sp, #0x50]
_08235EA8:
	ldr r7, [sp, #0x48]
	cmp r6, r7
	bge _08235EB0
	b _08235D9C
_08235EB0:
	ldr r0, _08235EC4 @ =0x0000FFFE
	ldr r1, [sp, #0x38]
	cmp r1, r0
	bls _08235EEA
	movs r0, #0
	ldr r2, [sp, #0x18]
	strh r0, [r2]
	b _08235F2E
	.align 2, 0
_08235EC0: .4byte 0x0000FFFF
_08235EC4: .4byte 0x0000FFFE
_08235EC8:
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0xc]
	str r1, [r7, #0x10]
	ldr r2, [sp, #0x18]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r3, [sp, #0x1c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	movs r0, #6
	b _08235F2A
_08235EEA:
	movs r2, #0
	add r0, sp, #0x40
	ldrh r1, [r0]
	ldr r0, [sp, #0x18]
	strh r1, [r0, #8]
	ldr r3, [sp, #0x20]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0xc]
	str r1, [r7, #0x10]
	ldr r3, [sp, #0x1c]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	ldr r7, [sp, #0x18]
	str r0, [r7, #0x14]
	str r1, [r7, #0x18]
	mov r0, sp
	ldrh r0, [r0, #0x3c]
	strh r0, [r7, #0xa]
	ldr r1, [sp, #0x3c]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldr r3, [sp, #0x2c]
	adds r0, r0, r3
	ldrh r1, [r0]
	strh r1, [r7, #0x1c]
	strh r2, [r7, #0x1e]
	ldrh r0, [r0, #2]
	strh r0, [r7, #0x20]
	movs r0, #3
_08235F2A:
	strh r0, [r7]
	movs r0, #1
_08235F2E:
	add sp, #0x60
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
