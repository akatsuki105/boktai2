	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08142884
FUN_08142884: @ 0x08142884
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r5, r2, #0
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	bne _081428BE
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081428BE
	ldrh r1, [r4, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081428BE
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r4, #4]
	str r0, [r1]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _081428C4 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081428BE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081428C4: .4byte 0xFEFFFFFF

	thumb_func_start FUN_081428c8
FUN_081428c8: @ 0x081428C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov r8, r1
	adds r6, r2, #0
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081428E8
	b _08142FB6
_081428E8:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _081428F6
	b _08142FB6
_081428F6:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0x40
	add r0, r8
	mov sb, r0
	cmp r2, #0
	beq _0814290C
	b _08142F8E
_0814290C:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _08142938
	ldr r3, _08142934 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08142924
	b _08142F8E
_08142924:
	movs r1, #0
	mov r4, r8
	strh r2, [r4, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _08142F8E
	.align 2, 0
_08142934: .4byte 0x0000048C
_08142938:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _08142948
	b _08142F8E
_08142948:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _08142956
	b _08142C60
_08142956:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _08142966
	b _08142F8E
_08142966:
	ldr r2, _081429F8 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0814297A
	b _08142F8E
_0814297A:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _08142988
	b _08142F8E
_08142988:
	movs r0, #0x3c
	strh r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	bne _081429A0
	b _08142AE8
_081429A0:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _08142A08
	ands r3, r1
	cmp r3, #0
	beq _08142A08
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _081429C8
	rsbs r1, r1, #0
_081429C8:
	cmp r1, #0x20
	bgt _08142A08
	ldrh r0, [r7, #0x3c]
	ldr r3, _081429FC @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _08142A00 @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _08142A04 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _08142F8E
	.align 2, 0
_081429F8: .4byte 0x0000A007
_081429FC: .4byte 0x000004BE
_08142A00: .4byte 0x0000048C
_08142A04: .4byte 0x0000044E
_08142A08:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _08142A30 @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08142A38
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142A34 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08142AA6
	.align 2, 0
_08142A30: .4byte 0x0000048A
_08142A34: .4byte 0x03002BE0
_08142A38:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08142A54
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142A50 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08142AA6
	.align 2, 0
_08142A50: .4byte 0x03002BE0
_08142A54:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08142A70
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08142A6C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08142AA6
	.align 2, 0
_08142A6C: .4byte 0x03002BE0
_08142A70:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08142A8C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142A88 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08142AA6
	.align 2, 0
_08142A88: .4byte 0x03002BE0
_08142A8C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08142A9E
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _08142AA6
_08142A9E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08142AA8
_08142AA6:
	movs r3, #1
_08142AA8:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, ip
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	bne _08142AC8
	b _08142C1C
_08142AC8:
	movs r1, #2
	ldr r3, _08142ADC @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08142AE0
	movs r0, #1
	b _08142AE2
	.align 2, 0
_08142ADC: .4byte 0x00000474
_08142AE0:
	movs r0, #0
_08142AE2:
	cmp r0, #0
	bne _08142BC2
	b _08142BD8
_08142AE8:
	mov r3, r8
	strh r2, [r3, #0x3e]
	ldr r1, _08142B10 @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _08142B18
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142B14 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08142B86
	.align 2, 0
_08142B10: .4byte 0x0000048A
_08142B14: .4byte 0x03002BE0
_08142B18:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08142B34
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142B30 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08142B86
	.align 2, 0
_08142B30: .4byte 0x03002BE0
_08142B34:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _08142B50
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08142B4C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08142B86
	.align 2, 0
_08142B4C: .4byte 0x03002BE0
_08142B50:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08142B6C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142B68 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08142B86
	.align 2, 0
_08142B68: .4byte 0x03002BE0
_08142B6C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08142B7E
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _08142B86
_08142B7E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08142B88
_08142B86:
	movs r3, #1
_08142B88:
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	ldr r1, [r7, #0x38]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	mov r4, ip
	str r4, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	cmp r3, #0
	beq _08142C1C
	movs r1, #2
	ldr r3, _08142BB8 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08142BBC
	movs r0, #1
	b _08142BBE
	.align 2, 0
_08142BB8: .4byte 0x00000474
_08142BBC:
	movs r0, #0
_08142BBE:
	cmp r0, #0
	beq _08142BD8
_08142BC2:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142BD4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08142BE4
	.align 2, 0
_08142BD4: .4byte 0x03002BE0
_08142BD8:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _08142C1C
_08142BE4:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08142C1C:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08142C48
	ldr r0, _08142C58 @ =0x0000024E
	adds r2, r6, r0
	adds r1, #0xac
	adds r0, r1, #0
	ldrh r3, [r2]
	adds r0, r0, r3
	strh r0, [r2]
	movs r4, #0x93
	lsls r4, r4, #2
	adds r1, r6, r4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08142C48
	strh r1, [r2]
_08142C48:
	ldr r0, _08142C5C @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x40
	add r1, r8
	mov sb, r1
	b _08142F8E
	.align 2, 0
_08142C58: .4byte 0x0000024E
_08142C5C: .4byte 0x0000048C
_08142C60:
	ldr r0, _08142C74 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08142C78
	movs r0, #1
	b _08142C7A
	.align 2, 0
_08142C74: .4byte 0x030047A4
_08142C78:
	movs r0, #0
_08142C7A:
	cmp r0, #0
	beq _08142C88
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236640
	b _08142C90
_08142C88:
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236524
_08142C90:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _08142CC8 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _08142CCC @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _08142CBE
	cmp r2, #0x17
	bne _08142CD0
_08142CBE:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _08142CF0
	.align 2, 0
_08142CC8: .4byte 0x0000048C
_08142CCC: .4byte 0x000001DF
_08142CD0:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _08142CBE
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _08142D20 @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _08142CF0
	movs r1, #0
_08142CF0:
	mov r0, r8
	adds r0, #0x40
	strh r1, [r0]
	mov sb, r0
	movs r2, #6
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _08142D2E
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _08142D24
	asrs r0, r0, #1
	b _08142D2A
	.align 2, 0
_08142D20: .4byte 0x00000187
_08142D24:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08142D2A:
	mov r3, sb
	strh r0, [r3]
_08142D2E:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08142D4C
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _08142D48 @ =0x000001DD
	adds r1, r6, r4
	b _08142DC0
	.align 2, 0
_08142D48: .4byte 0x000001DD
_08142D4C:
	mov r4, sp
	adds r3, r7, #0
	adds r3, #0xc
	mov r2, r8
	adds r2, #0xc
	mov r1, r8
	ldrh r0, [r1, #0xc]
	ldrh r1, [r7, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r2, #4]
	ldrh r0, [r3, #4]
	subs r1, r1, r0
	strh r1, [r4, #4]
	mov r0, sp
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08142DAC
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _08142DAC
	ldr r2, _08142D9C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08142DA0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08142DA4 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _08142DA8 @ =0x000001DD
	adds r1, r6, r4
	b _08142DC0
	.align 2, 0
_08142D9C: .4byte 0x030046B8
_08142DA0: .4byte 0x000003FF
_08142DA4: .4byte 0x0203B400
_08142DA8: .4byte 0x000001DD
_08142DAC:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _08142DE0 @ =0x000001DD
	adds r1, r6, r3
_08142DC0:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _08142DE8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142DE4 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _08142E56
	.align 2, 0
_08142DE0: .4byte 0x000001DD
_08142DE4: .4byte 0x03002BE0
_08142DE8:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _08142E04
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _08142E00 @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _08142E56
	.align 2, 0
_08142E00: .4byte 0x03002BE0
_08142E04:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _08142E20
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142E1C @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _08142E56
	.align 2, 0
_08142E1C: .4byte 0x03002BE0
_08142E20:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _08142E3C
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _08142E38 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _08142E56
	.align 2, 0
_08142E38: .4byte 0x03002BE0
_08142E3C:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _08142E4E
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _08142E56
_08142E4E:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _08142E58
_08142E56:
	movs r3, #1
_08142E58:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _08142E88 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _08142EF0
	movs r1, #2
	ldr r2, _08142E8C @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08142E90
	movs r0, #1
	b _08142E92
	.align 2, 0
_08142E88: .4byte 0x0000049C
_08142E8C: .4byte 0x00000474
_08142E90:
	movs r0, #0
_08142E92:
	cmp r0, #0
	beq _08142EAC
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _08142EA8 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _08142EB8
	.align 2, 0
_08142EA8: .4byte 0x03002BE0
_08142EAC:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _08142EF0
_08142EB8:
	ldr r1, [r0]
	movs r0, #8
	ldrsh r5, [r1, r0]
	movs r2, #8
	ldrsh r0, [r6, r2]
	subs r5, r5, r0
	movs r3, #0xc
	ldrsh r4, [r1, r3]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823785c
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_08142EF0:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _08142F24
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08142F24
	ldr r3, _08142F3C @ =0x0000024E
	adds r2, r6, r3
	movs r4, #0x96
	lsls r4, r4, #1
	adds r0, r4, #0
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	subs r3, #2
	adds r1, r6, r3
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	bls _08142F24
	strh r1, [r2]
_08142F24:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _08142F40 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _08142F44 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08142F48
	movs r0, #1
	b _08142F4A
	.align 2, 0
_08142F3C: .4byte 0x0000024E
_08142F40: .4byte 0x030046A0
_08142F44: .4byte 0x00000934
_08142F48:
	movs r0, #0
_08142F4A:
	ldr r1, _08142FC8 @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _08142F64
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #8]
	strb r0, [r1]
_08142F64:
	adds r0, r6, #0
	bl FUN_080e64e4
	mov r2, r8
	ldrh r0, [r2, #0x3e]
	strh r0, [r4]
	movs r3, #0xc4
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r7, #0x3e]
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r7, #0x3e]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r4, #0xbc
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08142F8E:
	ldr r2, _08142FCC @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08142FD0 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08142FD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sb
	ldrh r2, [r3]
	movs r1, #0xf
	ands r0, r1
	subs r2, r2, r0
	cmp r2, #0x14
	bge _08142FB2
	movs r2, #0x14
_08142FB2:
	mov r4, sb
	strh r2, [r4]
_08142FB6:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08142FC8: .4byte 0x0000048A
_08142FCC: .4byte 0x030046B8
_08142FD0: .4byte 0x000003FF
_08142FD4: .4byte 0x0203B400

	thumb_func_start FUN_08142fd8
FUN_08142fd8: @ 0x08142FD8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08143000 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08142FEA
	movs r0, #0
	strb r0, [r1]
_08142FEA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	adds r0, r4, #0
	bl FUN_08144b70
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08143000: .4byte 0x0000046D

	thumb_func_start FUN_08143004
FUN_08143004: @ 0x08143004
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r3, _08143024 @ =0x0000046D
	adds r1, r4, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143028
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814302A
	.align 2, 0
_08143024: .4byte 0x0000046D
_08143028:
	movs r0, #0
_0814302A:
	cmp r0, #0
	beq _08143038
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
	b _0814308A
_08143038:
	movs r1, #4
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814304C
	movs r0, #1
	b _0814304E
_0814304C:
	movs r0, #0
_0814304E:
	cmp r0, #0
	bne _0814308A
	adds r0, r2, #0
	movs r1, #0x5a
	bl Mod
	cmp r0, #0
	bne _08143078
	adds r0, r4, #0
	movs r1, #0x10
	bl FUN_080ef86c
	ldr r0, _08143074 @ =0x00000671
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #0x28
	strb r0, [r1]
	b _0814308A
	.align 2, 0
_08143074: .4byte 0x00000671
_08143078:
	ldr r1, _08143090 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0814308A
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080ef86c
_0814308A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08143090: .4byte 0x0000046E

	thumb_func_start FUN_08143094
FUN_08143094: @ 0x08143094
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	ldr r0, _081430B4 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081430B8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081430BA
	.align 2, 0
_081430B4: .4byte 0x0000046D
_081430B8:
	movs r0, #0
_081430BA:
	cmp r0, #0
	beq _081430CE
	adds r0, r4, #0
	movs r1, #0x11
	bl FUN_080ef86c
	ldr r0, _081430F8 @ =0x0000065C
	adds r1, r6, r0
	movs r0, #0
	strb r0, [r1]
_081430CE:
	ldr r1, _081430F8 @ =0x0000065C
	adds r5, r6, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _081430DE
	adds r0, r4, #0
	bl FUN_08144b70
_081430DE:
	ldr r1, _081430FC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08143122
	ldrb r0, [r5]
	cmp r0, #0
	blt _08143118
	cmp r0, #3
	ble _08143100
	cmp r0, #5
	beq _0814310A
	b _08143118
	.align 2, 0
_081430F8: .4byte 0x0000065C
_081430FC: .4byte 0x0000046E
_08143100:
	adds r0, r4, #0
	movs r1, #0xf
	bl FUN_080ef86c
	b _08143118
_0814310A:
	ldr r0, _08143114 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	b _08143120
	.align 2, 0
_08143114: .4byte 0x0000046B
_08143118:
	ldr r0, _08143128 @ =0x0000065C
	adds r1, r6, r0
	ldrb r0, [r1]
	adds r0, #1
_08143120:
	strb r0, [r1]
_08143122:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08143128: .4byte 0x0000065C

	thumb_func_start FUN_0814312c
FUN_0814312c: @ 0x0814312C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _08143144 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143148
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814314A
	.align 2, 0
_08143144: .4byte 0x0000046D
_08143148:
	movs r0, #0
_0814314A:
	cmp r0, #0
	beq _081431CE
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r2, [r0]
	ldr r1, _0814317C @ =0x0000025D
	adds r0, r4, r1
	ldrb r3, [r0]
	cmp r3, #0
	bne _08143188
	ldr r1, _08143180 @ =0x000004B7
	adds r0, r4, r1
	strb r2, [r0]
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	str r3, [sp]
	movs r3, #0
	bl FUN_08236fac
	ldr r0, _08143184 @ =0x0000046E
	adds r6, r4, r0
	b _081431CA
	.align 2, 0
_0814317C: .4byte 0x0000025D
_08143180: .4byte 0x000004B7
_08143184: .4byte 0x0000046E
_08143188:
	ldr r0, [r4, #0x44]
	adds r5, r0, #0
	adds r5, #0x20
	ldr r1, _081431D8 @ =0x000004B7
	adds r0, r4, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081431DC @ =0x0000046E
	adds r6, r4, r0
	cmp r1, r2
	bne _081431AE
	ldrb r0, [r6]
	cmp r0, #0
	bne _081431AE
	ldr r0, [r5, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081431CE
_081431AE:
	strb r2, [r3]
	movs r3, #4
	ldr r1, [r4, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	ldr r0, [r5, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #8]
_081431CA:
	movs r0, #0
	strb r0, [r6]
_081431CE:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081431D8: .4byte 0x000004B7
_081431DC: .4byte 0x0000046E

	thumb_func_start FUN_081431e0
FUN_081431e0: @ 0x081431E0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r5, r0, #0
	adds r2, r5, #0
	ldr r0, _08143200 @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143204
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143206
	.align 2, 0
_08143200: .4byte 0x0000046D
_08143204:
	movs r0, #0
_08143206:
	cmp r0, #0
	beq _081432DE
	ldrb r0, [r2, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_0814480c
	movs r1, #0x99
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0814324C @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08143258
	ldr r1, _08143250 @ =0x000004B7
	adds r0, r5, r1
	strb r2, [r0]
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x48
	ldr r1, [r1, #0x58]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	str r4, [sp]
	bl FUN_08236fac
	ldr r0, _08143254 @ =0x0000046E
	adds r7, r5, r0
	b _081432DA
	.align 2, 0
_0814324C: .4byte 0x0000025D
_08143250: .4byte 0x000004B7
_08143254: .4byte 0x0000046E
_08143258:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _081432C8 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _081432CC @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _08143292
	ldrb r0, [r7]
	cmp r0, #0
	bne _08143292
	cmp r4, #1
	bne _08143284
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081432DE
_08143284:
	cmp r4, #0
	bne _08143292
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _081432DE
_08143292:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _081432A4
	movs r3, #6
_081432A4:
	ldr r1, [r5, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	movs r3, #2
	bl FUN_082370cc
	movs r0, #1
	ands r4, r0
	cmp r4, #0
	beq _081432D0
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _081432D8
	.align 2, 0
_081432C8: .4byte 0x000004B7
_081432CC: .4byte 0x0000046E
_081432D0:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081432D8:
	str r0, [r6, #8]
_081432DA:
	movs r0, #0
	strb r0, [r7]
_081432DE:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081432ec
FUN_081432ec: @ 0x081432EC
	push {lr}
	adds r2, r0, #0
	ldr r0, _0814330C @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081432FE
	movs r0, #0
	strb r0, [r1]
_081432FE:
	adds r0, r2, #0
	movs r1, #0xf
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_0814330C: .4byte 0x0000046D

	thumb_func_start FUN_08143310
FUN_08143310: @ 0x08143310
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08143338 @ =0x0000046D
	adds r1, r7, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0814333C
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0814333E
	.align 2, 0
_08143338: .4byte 0x0000046D
_0814333C:
	movs r0, #0
_0814333E:
	cmp r0, #0
	beq _08143358
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r7, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r7, #0
	movs r1, #3
	bl FUN_080ef86c
_08143358:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r6, #0xbe
	lsls r6, r6, #1
	adds r1, r7, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	cmp r5, #0x13
	bgt _0814337A
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r7, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0814337A:
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r7, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0814339A
	asrs r0, r0, #2
	b _081433A0
_0814339A:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081433A0:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r7, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r7, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _081433BE
	asrs r0, r0, #2
	b _081433C4
_081433BE:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081433C4:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081433CE
	movs r3, #0xc8
	b _081433D8
_081433CE:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _081433D8
	adds r3, r0, #0
_081433D8:
	cmp r2, #0xc8
	ble _081433E0
	movs r2, #0xc8
	b _081433EA
_081433E0:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _081433EA
	adds r2, r0, #0
_081433EA:
	ldrh r0, [r7, #0x10]
	adds r0, r0, r3
	strh r0, [r7, #0x10]
	ldrh r0, [r7, #0x14]
	adds r0, r0, r2
	strh r0, [r7, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0814340E
	cmp r2, #0
	bne _0814340E
	movs r0, #1
	b _08143410
_0814340E:
	movs r0, #0
_08143410:
	cmp r0, #0
	beq _081434BE
	cmp r5, #0x1e
	ble _081434BE
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #0xa
	movs r5, #0
	movs r2, #0
	mov sb, r2
	strh r0, [r1]
	ldr r3, _081434CC @ =0x0000046B
	adds r0, r7, r3
	movs r4, #1
	strb r4, [r0]
	movs r6, #0xc0
	lsls r6, r6, #1
	adds r2, r7, r6
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0xce
	lsls r0, r0, #3
	add r0, r8
	strb r5, [r0]
	adds r0, r7, #0
	bl FUN_081447cc
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r3, r7, r1
	ldrb r0, [r3]
	strb r0, [r7, #5]
	ldr r2, _081434D0 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r6, _081434D4 @ =0x0000046D
	adds r0, r7, r6
	strb r4, [r0]
	subs r6, #2
	adds r0, r7, r6
	strb r5, [r0]
	adds r6, #0xe8
	adds r0, r7, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	mov r6, sb
	strh r6, [r0]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _081434D8 @ =0x00000469
	adds r0, r7, r2
	strb r5, [r0]
	ldr r6, _081434DC @ =0x0000046A
	adds r0, r7, r6
	strb r4, [r0]
	adds r1, #0x1c
	adds r0, r7, r1
	mov r2, sb
	str r2, [r0]
	adds r6, #2
	adds r0, r7, r6
	strb r4, [r0]
	ldrb r0, [r3]
	strb r0, [r7, #5]
	subs r1, #2
	adds r0, r7, r1
	strh r4, [r0]
_081434BE:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081434CC: .4byte 0x0000046B
_081434D0: .4byte FUN_080e48d0
_081434D4: .4byte 0x0000046D
_081434D8: .4byte 0x00000469
_081434DC: .4byte 0x0000046A

	thumb_func_start FUN_081434e0
FUN_081434e0: @ 0x081434E0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _081434FC @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143500
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143502
	.align 2, 0
_081434FC: .4byte 0x0000046D
_08143500:
	movs r0, #0
_08143502:
	cmp r0, #0
	beq _08143544
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080ef86c
	adds r0, r6, #0
	bl FUN_080e8360
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _081435EC @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _081435F0 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r7, _081435F4 @ =0x00000202
	adds r0, r6, r7
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_08143544:
	ldr r0, [r6, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08143558
	b _08143696
_08143558:
	ldr r1, _081435F8 @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _081435C2
	movs r7, #8
	ldrsh r0, [r6, r7]
	str r0, [sp]
	movs r1, #0xa
	ldrsh r0, [r6, r1]
	str r0, [sp, #4]
	movs r3, #0xc
	ldrsh r0, [r6, r3]
	str r0, [sp, #8]
	movs r7, #0xce
	lsls r7, r7, #1
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0xc]
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	str r0, [sp, #0x10]
	movs r3, #0xd2
	lsls r3, r3, #1
	adds r0, r6, r3
	ldr r0, [r0]
	str r0, [sp, #0x14]
	movs r7, #0x94
	lsls r7, r7, #3
	adds r0, r6, r7
	ldr r0, [r0]
	str r0, [sp, #0x18]
	ldrh r0, [r6]
	str r0, [sp, #0x1c]
	ldr r1, _081435FC @ =0xFFFF0000
	ldr r0, [sp, #0x20]
	ands r0, r1
	movs r1, #8
	orrs r0, r1
	str r0, [sp, #0x20]
	add r1, sp, #0x20
	mov r0, sp
	str r0, [r1, #4]
	ldrh r0, [r2]
	bl Script_ExecById
_081435C2:
	ldr r1, _08143600 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _08143608
	ldr r0, _08143604 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _0814361A
	.align 2, 0
_081435EC: .4byte 0xFFFEBE3F
_081435F0: .4byte 0x0000021E
_081435F4: .4byte 0x00000202
_081435F8: .4byte 0x0000046B
_081435FC: .4byte 0xFFFF0000
_08143600: .4byte 0x000001DF
_08143604: .4byte 0x030046A0
_08143608:
	ldr r0, _081436A0 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0814361A:
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08143638
	adds r0, r6, #0
	bl FUN_080e6658
_08143638:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _081436A4 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _081436A8 @ =0x0000046D
	adds r0, r6, r7
	movs r1, #1
	strb r1, [r0]
	subs r7, #2
	adds r0, r6, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r6, r7
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r6, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r2, [r0]
	movs r3, #2
	subs r7, #0xeb
	adds r0, r6, r7
	strb r1, [r0]
	ldr r4, _081436AC @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _081436B0 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl FUN_080136b4
_08143696:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081436A0: .4byte 0x030046A0
_081436A4: .4byte FUN_080e48d0
_081436A8: .4byte 0x0000046D
_081436AC: .4byte 0x00000469
_081436B0: .4byte 0x00000484

	thumb_func_start FUN_081436b4
FUN_081436b4: @ 0x081436B4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r0, [r0]
	mov sl, r0
	ldr r2, _081436E8 @ =0x00000256
	adds r0, r7, r2
	ldrh r4, [r0]
	adds r5, r7, #0
	adds r5, #8
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081436EC
	adds r0, #4
	b _081436F8
	.align 2, 0
_081436E8: .4byte 0x00000256
_081436EC:
	ldr r0, _0814370C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081436F8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08143710
	cmp r2, #2
	beq _08143714
	b _08143718
	.align 2, 0
_0814370C: .4byte 0x030046A4
_08143710:
	ldrb r0, [r5, #4]
	b _08143716
_08143714:
	ldrb r0, [r5]
_08143716:
	subs r1, r1, r0
_08143718:
	str r1, [sp, #0x14]
	ldr r3, _08143730 @ =0x0000046C
	adds r0, r7, r3
	ldrb r1, [r0]
	str r0, [sp, #0x18]
	cmp r1, #0
	beq _08143734
	movs r0, #0
	ldr r5, [sp, #0x18]
	strb r0, [r5]
	movs r0, #1
	b _08143736
	.align 2, 0
_08143730: .4byte 0x0000046C
_08143734:
	movs r0, #0
_08143736:
	cmp r0, #0
	bne _0814373C
	b _0814388C
_0814373C:
	ldr r6, _081437AC @ =0x000005A4
	adds r0, r7, r6
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _081437B0 @ =0x0000046D
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081437B4 @ =0x0000046B
	adds r0, r7, r1
	strb r2, [r0]
	ldr r5, _081437B8 @ =0x00000553
	adds r0, r7, r5
	strb r2, [r0]
	subs r6, #0x2c
	adds r0, r7, r6
	str r3, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r2, [r0]
	ldr r0, _081437BC @ =0x0000066C
	add r0, sl
	ldrh r5, [r0]
	add r6, sp, #4
	ldr r2, _081437C0 @ =0x030046A4
	mov r8, r2
	ldr r0, [r2]
	ldr r0, [r0, #4]
	movs r3, #4
	ldrsh r1, [r0, r3]
	adds r0, r5, #0
	bl Mod
	adds r4, r0, #0
	mov r1, r8
	ldr r0, [r1]
	ldr r0, [r0, #4]
	movs r2, #4
	ldrsh r1, [r0, r2]
	adds r0, r5, #0
	bl Div
	mov sb, r0
	lsls r4, r4, #8
	adds r4, #0x80
	strh r4, [r6]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081437C4
	adds r0, #4
	b _081437D0
	.align 2, 0
_081437AC: .4byte 0x000005A4
_081437B0: .4byte 0x0000046D
_081437B4: .4byte 0x0000046B
_081437B8: .4byte 0x00000553
_081437BC: .4byte 0x0000066C
_081437C0: .4byte 0x030046A4
_081437C4:
	mov r3, r8
	ldr r0, [r3]
	lsls r1, r5, #2
	adds r1, #0xc
	ldr r0, [r0, #4]
	adds r0, r0, r1
_081437D0:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	movs r1, #0
	strh r0, [r6, #2]
	mov r5, sb
	lsls r0, r5, #8
	adds r0, #0x80
	strh r0, [r6, #4]
	ldr r6, _08143844 @ =0x0203B400
	mov r8, r6
	ldr r4, _08143848 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r2, _0814384C @ =0x000003FF
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0xff
	mov sb, r3
	ldrb r6, [r0]
	strb r6, [r7, #5]
	movs r5, #0xd6
	lsls r5, r5, #3
	add r5, sl
	str r1, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _08143850 @ =0x05000002
	bl CpuSet
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _0814384C @ =0x000003FF
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r2, r0, #1
	ldr r1, _08143854 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _08143858
	asrs r1, r0, #0xc
	b _0814385E
	.align 2, 0
_08143844: .4byte 0x0203B400
_08143848: .4byte 0x030046B8
_0814384C: .4byte 0x000003FF
_08143850: .4byte 0x05000002
_08143854: .4byte 0x085B0A08
_08143858:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814385E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	ldr r1, _08143878 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _0814387C
	asrs r0, r0, #0xc
	b _08143882
	.align 2, 0
_08143878: .4byte 0x085B0A08
_0814387C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08143882:
	strh r0, [r5, #4]
	ldr r1, _081438EC @ =0x000006B2
	add r1, sl
	movs r0, #0xe
	strh r0, [r1]
_0814388C:
	movs r5, #0xc1
	lsls r5, r5, #3
	adds r0, r7, r5
	ldr r1, [r0]
	adds r0, r7, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081438A2
	b _081439C2
_081438A2:
	add r3, sp, #0xc
	adds r4, r7, #0
	adds r4, #8
	movs r2, #0xd6
	lsls r2, r2, #3
	add r2, sl
	ldrh r1, [r7, #8]
	ldrh r6, [r2]
	adds r1, r1, r6
	strh r1, [r3]
	ldrh r0, [r4, #2]
	ldrh r5, [r2, #2]
	adds r0, r0, r5
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081438E6
	cmp r1, #0
	blt _081438E6
	ldr r0, _081438F0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081438E6
	ldr r0, _081438F4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081438F8
_081438E6:
	movs r1, #0
	b _08143906
	.align 2, 0
_081438EC: .4byte 0x000006B2
_081438F0: .4byte 0x030046A8
_081438F4: .4byte 0x030046AC
_081438F8:
	ldr r0, _08143998 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_08143906:
	ldr r0, _0814399C @ =0x0000066C
	add r0, sl
	ldrh r0, [r0]
	cmp r0, r1
	beq _08143920
	movs r0, #0xd6
	lsls r0, r0, #3
	add r0, sl
	movs r1, #0
	strh r1, [r0]
	ldr r0, _081439A0 @ =0x000006B4
	add r0, sl
	strh r1, [r0]
_08143920:
	movs r3, #0xd6
	lsls r3, r3, #3
	add r3, sl
	ldrh r0, [r3]
	ldrh r6, [r7, #0x10]
	adds r0, r0, r6
	movs r4, #0
	movs r5, #0
	strh r0, [r7, #0x10]
	ldr r0, _081439A0 @ =0x000006B4
	add r0, sl
	ldrh r0, [r0]
	ldrh r1, [r7, #0x14]
	adds r0, r0, r1
	strh r0, [r7, #0x14]
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r7, r6
	ldr r1, _081439A4 @ =0x000006B2
	add r1, sl
	ldrh r0, [r1]
	ldrh r6, [r2]
	adds r0, r0, r6
	strh r0, [r2]
	ldrh r0, [r1]
	subs r0, #2
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	ldr r6, [sp, #0x14]
	cmp r6, r0
	blt _081439B8
	strh r6, [r7, #0xa]
	mov r1, sp
	ldrh r1, [r1, #0x14]
	strh r1, [r2]
	str r5, [sp]
	mov r0, sp
	adds r1, r3, #0
	ldr r2, _081439A8 @ =0x05000002
	bl CpuSet
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r7, r2
	strb r4, [r0]
	ldr r3, _081439AC @ =0x00000469
	adds r0, r7, r3
	strb r4, [r0]
	ldr r6, _081439B0 @ =0x0000046A
	adds r0, r7, r6
	strb r4, [r0]
	ldr r1, _081439B4 @ =0x00000484
	adds r0, r7, r1
	str r5, [r0]
	movs r0, #1
	ldr r2, [sp, #0x18]
	strb r0, [r2]
	b _081439C2
	.align 2, 0
_08143998: .4byte 0x030046A4
_0814399C: .4byte 0x0000066C
_081439A0: .4byte 0x000006B4
_081439A4: .4byte 0x000006B2
_081439A8: .4byte 0x05000002
_081439AC: .4byte 0x00000469
_081439B0: .4byte 0x0000046A
_081439B4: .4byte 0x00000484
_081439B8:
	ldr r3, _081439D4 @ =0x00000484
	adds r1, r7, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081439C2:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081439D4: .4byte 0x00000484

	thumb_func_start FUN_081439d8
FUN_081439d8: @ 0x081439D8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _08143A00 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143A04
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143A06
	.align 2, 0
_08143A00: .4byte 0x0000046C
_08143A04:
	movs r0, #0
_08143A06:
	cmp r0, #0
	beq _08143A42
	ldr r1, [r5, #0x44]
	ldr r0, [r1]
	movs r3, #2
	orrs r0, r3
	str r0, [r1]
	movs r1, #0xb2
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _08143A9C @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08143AA0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
_08143A42:
	ldr r0, _08143AA4 @ =0x0000065E
	add r0, r8
	ldrh r1, [r0]
	ldr r2, _08143AA8 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r1, r0
	blt _08143A54
	b _08143B64
_08143A54:
	ldr r0, _08143AAC @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r6, r0, #0
	ldrb r0, [r5, #5]
	subs r1, r6, r0
	cmp r1, #0x80
	ble _08143AB4
	ldr r0, _08143AB0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08143AC2
	.align 2, 0
_08143A9C: .4byte 0x0000046D
_08143AA0: .4byte 0x0000046B
_08143AA4: .4byte 0x0000065E
_08143AA8: .4byte 0x00000484
_08143AAC: .4byte 0x03002BE0
_08143AB0: .4byte 0xFFFFFF00
_08143AB4:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08143AC2
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08143AC2:
	adds r0, r1, #0
	cmp r0, #0
	bge _08143ACA
	rsbs r0, r0, #0
_08143ACA:
	cmp r0, #0xb
	bgt _08143B0C
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, r8
	movs r3, #0
	strb r3, [r0]
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08143B04 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r3, [r0]
	ldr r3, _08143B08 @ =0x0000046C
	b _08143CA2
	.align 2, 0
_08143B04: .4byte 0x0000046A
_08143B08: .4byte 0x0000046C
_08143B0C:
	cmp r0, #0
	blt _08143B14
	asrs r0, r0, #2
	b _08143B1A
_08143B14:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_08143B1A:
	adds r3, r0, #0
	cmp r0, #0
	bgt _08143B22
	movs r0, #4
_08143B22:
	adds r3, r0, #0
	cmp r3, #8
	ble _08143B2A
	movs r3, #8
_08143B2A:
	movs r2, #0xcd
	lsls r2, r2, #3
	add r2, r8
	ldrb r0, [r2]
	cmp r0, #0x14
	bls _08143B50
	movs r1, #0
	strb r1, [r2]
	ldr r0, _08143B4C @ =0x00000661
	add r0, r8
	strb r1, [r0]
	movs r2, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	b _08143C8C
	.align 2, 0
_08143B4C: .4byte 0x00000661
_08143B50:
	adds r0, #1
	movs r1, #0
	strb r0, [r2]
	ldr r0, _08143B60 @ =0x00000661
	add r0, r8
	strb r1, [r0]
	b _08143CCE
	.align 2, 0
_08143B60: .4byte 0x00000661
_08143B64:
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r0, _08143BCC @ =0x00007CFF
	cmp r1, r0
	bhi _08143B74
	b _08143C82
_08143B74:
	ldr r0, _08143BD0 @ =0x00000664
	add r0, r8
	ldr r0, [r0]
	cmp r0, r1
	bls _08143C18
	ldr r0, _08143BD4 @ =0x03002BE0
	mov r2, sp
	ldr r1, [r0]
	adds r4, r1, #0
	adds r4, #0x2c
	adds r3, r5, #0
	adds r3, #8
	ldrh r0, [r5, #8]
	ldrh r1, [r1, #0x2c]
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
	bl FUN_0823785c
	adds r6, r0, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _08143BDC
	ldr r0, _08143BD8 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08143BEA
	.align 2, 0
_08143BCC: .4byte 0x00007CFF
_08143BD0: .4byte 0x00000664
_08143BD4: .4byte 0x03002BE0
_08143BD8: .4byte 0xFFFFFF00
_08143BDC:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08143BEA
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08143BEA:
	adds r0, r1, #0
	cmp r0, #0
	bge _08143BF2
	rsbs r0, r0, #0
_08143BF2:
	cmp r0, #0x3f
	bgt _08143BFA
	adds r6, #0x40
	b _08143BFC
_08143BFA:
	adds r6, #0xc0
_08143BFC:
	movs r0, #0xff
	ands r6, r0
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	ldrb r0, [r0]
	movs r1, #8
	bl Div
	adds r3, r0, #0
	cmp r3, #0
	bgt _08143CC8
	movs r3, #2
	b _08143CC8
_08143C18:
	ldr r0, _08143C60 @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
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
	movs r3, #0
	ldrsh r0, [r0, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	adds r6, r0, #0
	ldrb r0, [r5, #5]
	subs r1, r6, r0
	cmp r1, #0x80
	ble _08143C68
	ldr r0, _08143C64 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08143C76
	.align 2, 0
_08143C60: .4byte 0x03002BE0
_08143C64: .4byte 0xFFFFFF00
_08143C68:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08143C76
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08143C76:
	adds r0, r1, #0
	cmp r0, #0
	bge _08143C7E
	rsbs r0, r0, #0
_08143C7E:
	cmp r0, #0x1f
	bgt _08143CB0
_08143C82:
	movs r2, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
_08143C8C:
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r5, r3
	strb r2, [r0]
	ldr r2, _08143CAC @ =0x00000484
	adds r0, r5, r2
	str r1, [r0]
	adds r3, #2
_08143CA2:
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
	b _08143DBE
	.align 2, 0
_08143CAC: .4byte 0x00000484
_08143CB0:
	cmp r0, #0
	blt _08143CB8
	asrs r0, r0, #3
	b _08143CBE
_08143CB8:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_08143CBE:
	adds r3, r0, #0
	cmp r0, #0
	bgt _08143CC6
	movs r0, #2
_08143CC6:
	adds r3, r0, #0
_08143CC8:
	cmp r3, #6
	ble _08143CCE
	movs r3, #6
_08143CCE:
	movs r0, #0xcc
	lsls r0, r0, #3
	add r0, r8
	add r7, sp, #8
	ldrb r4, [r5, #5]
	ldrb r0, [r0]
	mov ip, r0
	ldr r2, _08143D00 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r4
	cmp r0, #0
	blt _08143D04
	asrs r1, r0, #0xc
	b _08143D0A
	.align 2, 0
_08143D00: .4byte 0x085B0A08
_08143D04:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08143D0A:
	movs r0, #0
	strh r1, [r7]
	strh r0, [r7, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r1, ip
	muls r1, r0, r1
	adds r0, r1, #0
	cmp r0, #0
	blt _08143D26
	asrs r0, r0, #0xc
	b _08143D2C
_08143D26:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08143D2C:
	strh r0, [r7, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x10]
	str r1, [r5, #0x14]
	ldr r0, _08143D50 @ =0x00000661
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	bne _08143DAA
	mov r2, sb
	subs r1, r6, r2
	cmp r1, #0x80
	ble _08143D58
	ldr r0, _08143D54 @ =0xFFFFFF00
	adds r1, r1, r0
	b _08143D66
	.align 2, 0
_08143D50: .4byte 0x00000661
_08143D54: .4byte 0xFFFFFF00
_08143D58:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _08143D66
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_08143D66:
	cmp r1, #0
	ble _08143D70
	ldrb r0, [r5, #5]
	adds r0, r0, r3
	b _08143D74
_08143D70:
	ldrb r0, [r5, #5]
	subs r0, r0, r3
_08143D74:
	strb r0, [r5, #5]
	ldr r2, [r5, #0x44]
	ldrb r1, [r5, #5]
	movs r0, #0x9f
	subs r0, r0, r1
	strb r0, [r2, #6]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #0
	bne _08143D98
	ldr r1, _08143D94 @ =0x00000661
	add r1, r8
	movs r0, #4
	b _08143D9E
	.align 2, 0
_08143D94: .4byte 0x00000661
_08143D98:
	ldr r1, _08143DCC @ =0x00000661
	add r1, r8
	movs r0, #2
_08143D9E:
	strb r0, [r1]
	ldr r0, _08143DCC @ =0x00000661
	add r0, r8
	ldrb r0, [r0]
	cmp r0, #0
	beq _08143DB4
_08143DAA:
	ldr r1, _08143DCC @ =0x00000661
	add r1, r8
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_08143DB4:
	ldr r0, _08143DD0 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08143DBE:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08143DCC: .4byte 0x00000661
_08143DD0: .4byte 0x00000484

	thumb_func_start FUN_08143dd4
FUN_08143dd4: @ 0x08143DD4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _08143DF4 @ =0x0000046C
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143DF8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143DFA
	.align 2, 0
_08143DF4: .4byte 0x0000046C
_08143DF8:
	movs r0, #0
_08143DFA:
	cmp r0, #0
	beq _08143E48
	ldr r3, _08143E5C @ =0x000005A4
	adds r0, r4, r3
	ldr r3, [r0]
	movs r2, #0
	ldr r0, _08143E60 @ =0x0000046D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08143E64 @ =0x0000046B
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #0x25
	adds r0, r4, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r2, [r0]
	ldr r2, _08143E68 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08143E6C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08143E70 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0x14
	ldr r2, _08143E74 @ =0x00000671
	adds r1, r5, r2
	strb r0, [r1]
_08143E48:
	movs r1, #4
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08143E78
	movs r0, #1
	b _08143E7A
	.align 2, 0
_08143E5C: .4byte 0x000005A4
_08143E60: .4byte 0x0000046D
_08143E64: .4byte 0x0000046B
_08143E68: .4byte 0x030046B8
_08143E6C: .4byte 0x000003FF
_08143E70: .4byte 0x0203B400
_08143E74: .4byte 0x00000671
_08143E78:
	movs r0, #0
_08143E7A:
	cmp r0, #0
	bne _08143EEE
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	cmp r2, #0
	bne _08143EEE
	ldr r3, _08143ED4 @ =0x00000484
	adds r0, r4, r3
	ldr r3, _08143ED8 @ =0x00000671
	adds r1, r5, r3
	ldr r0, [r0]
	ldrb r1, [r1]
	cmp r0, r1
	ble _08143EE4
	ldr r1, _08143EDC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08143EE4
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r2, [r0]
	adds r3, #1
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _08143ED4 @ =0x00000484
	adds r0, r4, r1
	str r2, [r0]
	ldr r2, _08143EE0 @ =0x0000046C
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	b _08143EEE
	.align 2, 0
_08143ED4: .4byte 0x00000484
_08143ED8: .4byte 0x00000671
_08143EDC: .4byte 0x0000046E
_08143EE0: .4byte 0x0000046C
_08143EE4:
	ldr r3, _08143EF4 @ =0x00000484
	adds r1, r4, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08143EEE:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08143EF4: .4byte 0x00000484

	thumb_func_start FUN_08143ef8
FUN_08143ef8: @ 0x08143EF8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08143F10 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143F14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143F16
	.align 2, 0
_08143F10: .4byte 0x0000046C
_08143F14:
	movs r0, #0
_08143F16:
	cmp r0, #0
	beq _08143F42
	ldr r4, _08143F84 @ =FUN_08143094
	movs r3, #0x22
	ldr r2, _08143F88 @ =0x0000046D
	adds r1, r5, r2
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08143F8C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
_08143F42:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r2, _08143F8C @ =0x0000046B
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08143F98
	movs r2, #2
	movs r3, #1
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08143F90 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _08143F94 @ =0x0000046C
	adds r0, r5, r1
	strb r3, [r0]
	b _08143FA2
	.align 2, 0
_08143F84: .4byte FUN_08143094
_08143F88: .4byte 0x0000046D
_08143F8C: .4byte 0x0000046B
_08143F90: .4byte 0x0000046A
_08143F94: .4byte 0x0000046C
_08143F98:
	ldr r2, _08143FA8 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08143FA2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08143FA8: .4byte 0x00000484

	thumb_func_start FUN_08143fac
FUN_08143fac: @ 0x08143FAC
	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08143FCC @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08143FD0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08143FD2
	.align 2, 0
_08143FCC: .4byte 0x0000046C
_08143FD0:
	movs r0, #0
_08143FD2:
	cmp r0, #0
	beq _08144010
	ldr r2, [r5, #0x44]
	ldr r0, [r2]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r4, _08144080 @ =0x0000046D
	adds r0, r5, r4
	movs r2, #0
	strb r1, [r0]
	subs r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
_08144010:
	movs r4, #0x90
	lsls r4, r4, #3
	adds r0, r5, r4
	ldrh r0, [r0]
	movs r1, #0x28
	cmp r0, #1
	bne _08144020
	movs r1, #0x18
_08144020:
	ldr r2, _08144084 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, r1
	ble _081440DC
	ldr r3, _08144088 @ =0x00000664
	adds r0, r6, r3
	movs r4, #0xf2
	lsls r4, r4, #1
	adds r1, r5, r4
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	bhi _081440AE
	ldr r0, _0814408C @ =0x03002BE0
	mov r2, sp
	adds r4, r5, #0
	adds r4, #8
	ldr r0, [r0]
	adds r3, r0, #0
	adds r3, #0x2c
	ldrh r0, [r0, #0x2c]
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
	bl FUN_0823785c
	ldrb r1, [r5, #5]
	subs r1, r0, r1
	cmp r1, #0x80
	ble _08144094
	ldr r4, _08144090 @ =0xFFFFFF00
	adds r1, r1, r4
	b _081440A2
	.align 2, 0
_08144080: .4byte 0x0000046D
_08144084: .4byte 0x00000484
_08144088: .4byte 0x00000664
_0814408C: .4byte 0x03002BE0
_08144090: .4byte 0xFFFFFF00
_08144094:
	movs r0, #0x80
	rsbs r0, r0, #0
	cmp r1, r0
	bge _081440A2
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
_081440A2:
	adds r0, r1, #0
	cmp r0, #0
	bge _081440AA
	rsbs r0, r0, #0
_081440AA:
	cmp r0, #0x40
	ble _081440DC
_081440AE:
	movs r2, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r3, _081440D4 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r4, _081440D8 @ =0x0000046A
	adds r0, r5, r4
	strb r2, [r0]
	adds r3, #0x1b
	adds r0, r5, r3
	str r1, [r0]
	adds r4, #2
	adds r0, r5, r4
	strb r2, [r0]
	b _08144140
	.align 2, 0
_081440D4: .4byte 0x00000469
_081440D8: .4byte 0x0000046A
_081440DC:
	movs r1, #0xcc
	lsls r1, r1, #3
	adds r0, r6, r1
	add r3, sp, #8
	ldrb r4, [r5, #5]
	ldrb r6, [r0]
	ldr r2, _08144104 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _08144108
	asrs r1, r0, #0xc
	b _0814410E
	.align 2, 0
_08144104: .4byte 0x085B0A08
_08144108:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814410E:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _08144126
	asrs r0, r0, #0xc
	b _0814412C
_08144126:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814412C:
	strh r0, [r3, #4]
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	str r0, [r5, #0x10]
	str r1, [r5, #0x14]
	ldr r3, _08144148 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08144140:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08144148: .4byte 0x00000484

	thumb_func_start FUN_0814414c
FUN_0814414c: @ 0x0814414C
	ldr r1, _08144158 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _0814415C @ =0x085AD828
	str r1, [r0]
	bx lr
	.align 2, 0
_08144158: .4byte 0x00000634
_0814415C: .4byte 0x085AD828

	thumb_func_start FUN_08144160
FUN_08144160: @ 0x08144160
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _081441FC
	ldr r0, _08144204 @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _081441FC
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	ldr r3, _08144208 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r4, _0814420C @ =0x0000046D
	adds r0, r5, r4
	movs r4, #1
	strb r4, [r0]
	ldr r7, _08144210 @ =0x0000046B
	adds r0, r5, r7
	strb r6, [r0]
	adds r7, #0xe8
	adds r0, r5, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r7, #0xe4
	lsls r7, r7, #1
	adds r0, r5, r7
	movs r1, #0
	strh r6, [r0]
	movs r3, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r5, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r5, r7
	strb r1, [r0]
	ldr r1, _08144214 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r7, #0x1b
	adds r0, r5, r7
	str r6, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r4, [r0]
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r2, r2, r4
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r7, #0xbc
	lsls r7, r7, #1
	adds r1, r5, r7
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_081441FC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08144204: .4byte 0x03002BE0
_08144208: .4byte FUN_080e48d0
_0814420C: .4byte 0x0000046D
_08144210: .4byte 0x0000046B
_08144214: .4byte 0x0000046A

	thumb_func_start FUN_08144218
FUN_08144218: @ 0x08144218
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0814427C @ =0x0000065C
	adds r0, r6, r2
	movs r1, #0
	strb r1, [r0]
	ldr r3, _08144280 @ =0x00000672
	adds r0, r6, r3
	strb r1, [r0]
	adds r2, #0x17
	adds r0, r6, r2
	strb r1, [r0]
	subs r3, #0x11
	adds r0, r6, r3
	strb r1, [r0]
	subs r2, #0xb
	adds r0, r6, r2
	strb r1, [r0]
	subs r3, #9
	adds r0, r6, r3
	str r1, [r0]
	movs r0, #0xd7
	lsls r0, r0, #3
	adds r2, r6, r0
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r5, #8]
	str r1, [r5, #0xc]
	ldr r1, _08144284 @ =0x0000066C
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r3, _08144288 @ =0x00000256
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r4, [r0]
	adds r7, r2, #0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0814428C
	adds r0, #4
	b _08144298
	.align 2, 0
_0814427C: .4byte 0x0000065C
_08144280: .4byte 0x00000672
_08144284: .4byte 0x0000066C
_08144288: .4byte 0x00000256
_0814428C:
	ldr r0, _081442AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08144298:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _081442B0
	cmp r3, #2
	beq _081442B4
	b _081442B8
	.align 2, 0
_081442AC: .4byte 0x030046A4
_081442B0:
	ldrb r0, [r7, #4]
	b _081442B6
_081442B4:
	ldrb r0, [r7]
_081442B6:
	subs r2, r2, r0
_081442B8:
	ldr r0, _081442E4 @ =0x00000472
	adds r1, r5, r0
	strh r2, [r1]
	ldrh r0, [r5, #0xa]
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r5, r3
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r5, #0xa]
	ldr r1, _081442E8 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081442EC
	ldr r2, [r5, #0x44]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _081442F6
	.align 2, 0
_081442E4: .4byte 0x00000472
_081442E8: .4byte 0x0000025D
_081442EC:
	ldr r2, [r5, #0x44]
	ldr r0, [r5, #8]
	ldr r1, [r5, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_081442F6:
	movs r2, #0xd4
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _08144364 @ =0x05000002
	bl CpuSet
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r1, r6, r3
	str r4, [sp]
	mov r0, sp
	ldr r2, _08144364 @ =0x05000002
	bl CpuSet
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r1, r6, r0
	str r4, [sp]
	mov r0, sp
	ldr r2, _08144364 @ =0x05000002
	bl CpuSet
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [r5, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08144368
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _08144370
	.align 2, 0
_08144364: .4byte 0x05000002
_08144368:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_08144370:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _08144394
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _0814439C
_08144394:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_0814439C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _081443D4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _0814440C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _081443D8
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _081443CC
	ldrb r0, [r4, #5]
_081443CC:
	subs r0, #1
	strh r0, [r4, #8]
	b _081443E8
	.align 2, 0
_081443D4: .4byte 0x0000FFFF
_081443D8:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _081443E8
	strh r1, [r4, #8]
_081443E8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814440C
	movs r0, #1
	strb r0, [r4, #7]
_0814440C:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08144414
FUN_08144414: @ 0x08144414
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r6, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0814442E
	b _08144600
_0814442E:
	ldr r2, _08144448 @ =0x00000553
	adds r0, r4, r2
	ldrb r2, [r0]
	cmp r2, #0
	beq _08144440
	cmp r2, #0x24
	beq _08144440
	cmp r2, #0x25
	bne _0814444C
_08144440:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r4, r3
	b _0814452C
	.align 2, 0
_08144448: .4byte 0x00000553
_0814444C:
	movs r1, #0x80
	lsls r1, r1, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r0, r4, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08144526
	cmp r2, #0x22
	bne _08144532
	ldrh r0, [r4, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r4, #0xc]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08144486
	cmp r1, #0
	blt _08144486
	ldr r0, _0814448C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08144486
	ldr r0, _08144490 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08144494
_08144486:
	movs r5, #0
	b _081444A2
	.align 2, 0
_0814448C: .4byte 0x030046A8
_08144490: .4byte 0x030046AC
_08144494:
	ldr r0, _081444B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_081444A2:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081444B8
	adds r0, #4
	b _081444C4
	.align 2, 0
_081444B4: .4byte 0x030046A4
_081444B8:
	ldr r0, _081444FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081444C4:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r2, #0x7e
	adds r1, r1, r2
	cmp r0, r1
	bge _08144526
	ldr r1, _08144500 @ =0x085B0A08
	movs r3, #0xce
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #3
	cmp r0, #0
	blt _08144504
	asrs r2, r0, #0xc
	b _0814450A
	.align 2, 0
_081444FC: .4byte 0x030046A4
_08144500: .4byte 0x085B0A08
_08144504:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_0814450A:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r0, #0xce
	lsls r0, r0, #3
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _08144526
	adds r0, #1
	strb r0, [r1]
_08144526:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, r1
_0814452C:
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	b _08144600
_08144532:
	ldr r2, _08144560 @ =0x00000472
	adds r0, r4, r2
	ldrh r1, [r0]
	movs r3, #0xa
	ldrsh r0, [r4, r3]
	ldr r2, _08144564 @ =0xFFFFFEC0
	adds r0, r0, r2
	subs r1, r1, r0
	adds r0, r1, #0
	cmp r1, #0
	bge _0814454A
	rsbs r0, r1, #0
_0814454A:
	cmp r0, #0x10
	ble _08144574
	cmp r1, #0
	bge _08144568
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, #2
	b _08144572
	.align 2, 0
_08144560: .4byte 0x00000472
_08144564: .4byte 0xFFFFFEC0
_08144568:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #2
_08144572:
	strh r0, [r1]
_08144574:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	ldr r2, _081445A4 @ =0x00000553
	adds r0, r4, r2
	ldrb r0, [r0]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _08144600
	ldr r3, [r4, #0x44]
	adds r2, r3, #0
	adds r2, #0x48
	ldrh r0, [r2, #8]
	cmp r0, #4
	bhi _08144600
	lsls r0, r0, #2
	ldr r1, _081445A8 @ =_081445AC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_081445A4: .4byte 0x00000553
_081445A8: .4byte _081445AC
_081445AC: @ jump table
	.4byte _081445C0 @ case 0
	.4byte _081445C6 @ case 1
	.4byte _081445D4 @ case 2
	.4byte _081445E4 @ case 3
	.4byte _081445F2 @ case 4
_081445C0:
	ldrh r0, [r3, #0x1e]
	adds r0, #0x18
	b _081445FE
_081445C6:
	ldrh r1, [r3, #0x1e]
	adds r1, #0x18
	ldrh r0, [r2, #0xe]
	lsls r0, r0, #2
	adds r1, r1, r0
	strh r1, [r3, #0x1e]
	b _08144600
_081445D4:
	ldrh r0, [r3, #0x1e]
	adds r0, #0x3e
	ldrh r2, [r2, #0xe]
	lsls r1, r2, #1
	adds r1, r1, r2
	lsls r1, r1, #2
	subs r0, r0, r1
	b _081445FE
_081445E4:
	ldrh r1, [r3, #0x1e]
	adds r1, #2
	ldrh r0, [r2, #0xe]
	lsls r0, r0, #3
	subs r1, r1, r0
	strh r1, [r3, #0x1e]
	b _08144600
_081445F2:
	ldrh r0, [r3, #0x1e]
	subs r0, #0x16
	ldrh r2, [r2, #0xe]
	lsls r1, r2, #3
	subs r1, r1, r2
	adds r0, r0, r1
_081445FE:
	strh r0, [r3, #0x1e]
_08144600:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08144608
FUN_08144608: @ 0x08144608
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _0814465C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08144660 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _08144664 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _08144642
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_08144642:
	movs r0, #0
	strb r1, [r4, #2]
	strb r0, [r4, #3]
	ldr r0, [r4, #4]
	bl FUN_08234f6c
	ldrb r1, [r4, #2]
	lsls r1, r1, #3
	adds r0, r0, r1
	str r0, [r4, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0814465C: .4byte 0x030046B8
_08144660: .4byte 0x000003FF
_08144664: .4byte 0x0203B400

	thumb_func_start FUN_08144668
FUN_08144668: @ 0x08144668
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x28
	adds r6, r0, #0
	ldr r4, _081446EC @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r2, #0x2a
	orrs r0, r2
	ldr r1, _081446F0 @ =0x0000FFFF
	mov r8, r1
	ands r0, r1
	movs r1, #0xc0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r2
	str r0, [sp, #0xc]
	movs r5, #0
	str r5, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081446F4 @ =FUN_081428c8
	str r6, [sp]
	adds r0, r6, #0
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r4
	movs r2, #0x10
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa8
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r1, #4]
	str r5, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _081446F8 @ =FUN_08142884
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r6, #0
	bl FUN_080e3984
	add sp, #0x28
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081446EC: .4byte 0xFFFF0000
_081446F0: .4byte 0x0000FFFF
_081446F4: .4byte FUN_081428c8
_081446F8: .4byte FUN_08142884

	thumb_func_start FUN_081446fc
FUN_081446fc: @ 0x081446FC
	push {lr}
	ldr r1, _08144724 @ =0x00000484
	adds r0, r0, r1
	ldr r0, [r0]
	movs r1, #0
	cmp r0, #0x1d
	ble _08144718
	movs r1, #1
	cmp r0, #0x31
	ble _08144718
	movs r1, #3
	cmp r0, #0x45
	bgt _08144718
	movs r1, #2
_08144718:
	ldr r0, _08144728 @ =0x085AD83C
	lsls r1, r1, #2
	adds r1, r1, r0
	ldr r0, [r1]
	pop {r1}
	bx r1
	.align 2, 0
_08144724: .4byte 0x00000484
_08144728: .4byte 0x085AD83C

	thumb_func_start FUN_0814472c
FUN_0814472c: @ 0x0814472C
	push {r4, r5, lr}
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r2, r0, r3
	ldr r4, [r2]
	movs r2, #0xd4
	lsls r2, r2, #3
	adds r5, r4, r2
	ldr r2, [r0, #8]
	ldr r3, [r0, #0xc]
	str r2, [r5]
	str r3, [r5, #4]
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r4, r4, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r4]
	str r1, [r4, #4]
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08144758
FUN_08144758: @ 0x08144758
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #2
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #6
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #7
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_081447cc
FUN_081447cc: @ 0x081447CC
	mov ip, r0
	movs r0, #0xe6
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0]
	movs r3, #0x80
	lsls r3, r3, #0xd
	movs r2, #0xbe
	lsls r2, r2, #1
	add r2, ip
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r1, r0
	movs r2, #2
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r2, #0x97
	lsls r2, r2, #1
	add r2, ip
	ldrh r1, [r2]
	ldr r0, _08144808 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	bx lr
	.align 2, 0
_08144808: .4byte 0x0000FFFB

	thumb_func_start FUN_0814480c
FUN_0814480c: @ 0x0814480C
	push {lr}
	adds r3, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r1, r0, #3
	movs r0, #7
	ands r1, r0
	cmp r1, #4
	ble _08144830
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _08144834
_08144830:
	str r1, [r3]
	movs r0, #0
_08144834:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0814483c
FUN_0814483c: @ 0x0814483C
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0814472c
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	ldr r3, _081448D0 @ =0x00000469
	adds r0, r4, r3
	strb r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x1b
	adds r0, r4, r3
	str r6, [r0]
	adds r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	add r2, sp, #4
	adds r3, r4, #0
	adds r3, #8
	ldrh r0, [r5]
	ldrh r1, [r4, #8]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r5, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r5, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r3, #0
	ldrsh r0, [r2, r3]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl FUN_0823785c
	movs r1, #0xee
	lsls r1, r1, #1
	adds r4, r4, r1
	strb r0, [r4]
	movs r2, #0xd6
	lsls r2, r2, #3
	add r8, r2
	str r6, [sp]
	mov r0, sp
	mov r1, r8
	ldr r2, _081448D4 @ =0x05000002
	bl CpuSet
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081448D0: .4byte 0x00000469
_081448D4: .4byte 0x05000002

	thumb_func_start FUN_081448d8
FUN_081448d8: @ 0x081448D8
	push {r4, lr}
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, _08144904 @ =0xFFFFFEFF
	ldrh r2, [r3]
	ands r1, r2
	movs r4, #0
	strh r1, [r3]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r2, _08144908 @ =0xFBFFFFFF
	ldr r1, [r3]
	ands r1, r2
	str r1, [r3]
	ldr r1, _0814490C @ =0x0000024E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08144904: .4byte 0xFFFFFEFF
_08144908: .4byte 0xFBFFFFFF
_0814490C: .4byte 0x0000024E

	thumb_func_start FUN_08144910
FUN_08144910: @ 0x08144910
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0
	bne _08144934
	adds r2, #0xce
	adds r0, r5, r2
	strh r1, [r0]
	b _081449F0
_08144934:
	ldr r0, _08144944 @ =0x0000024E
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08144948
	subs r0, #1
	strh r0, [r1]
	b _081449F0
	.align 2, 0
_08144944: .4byte 0x0000024E
_08144948:
	adds r0, r5, #0
	bl FUN_08144608
	mov r6, sp
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r2, [r0, #8]
	ldrh r1, [r2]
	mov r0, sp
	strh r1, [r0]
	ldrh r1, [r2, #2]
	strh r1, [r6, #4]
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08144982
	cmp r1, #0
	blt _08144982
	ldr r0, _08144988 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08144982
	ldr r0, _0814498C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08144990
_08144982:
	movs r4, #0
	b _0814499E
	.align 2, 0
_08144988: .4byte 0x030046A8
_0814498C: .4byte 0x030046AC
_08144990:
	ldr r0, _081449B0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0814499E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081449B4
	adds r0, #4
	b _081449C0
	.align 2, 0
_081449B0: .4byte 0x030046A4
_081449B4:
	ldr r0, _081449D4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081449C0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _081449D8
	cmp r2, #2
	beq _081449DC
	b _081449E0
	.align 2, 0
_081449D4: .4byte 0x030046A4
_081449D8:
	ldrb r0, [r6, #4]
	b _081449DE
_081449DC:
	ldrb r0, [r6]
_081449DE:
	subs r1, r1, r0
_081449E0:
	strh r1, [r6, #2]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_0814483c
	adds r0, r5, #0
	bl FUN_081448d8
_081449F0:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_081449f8
FUN_081449f8: @ 0x081449F8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r7, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r1, _08144A90 @ =0x00000553
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x24
	beq _08144A22
	b _08144B5E
_08144A22:
	mov r3, sp
	adds r4, r5, #0
	adds r4, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r2, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
	adds r2, r5, #0
	adds r2, #0x10
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r5, #0x10]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r3, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r3, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08144A8C
	cmp r1, #0
	blt _08144A8C
	ldr r0, _08144A94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08144A8C
	ldr r0, _08144A98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08144A9C
_08144A8C:
	movs r4, #0
	b _08144AAA
	.align 2, 0
_08144A90: .4byte 0x00000553
_08144A94: .4byte 0x030046A8
_08144A98: .4byte 0x030046AC
_08144A9C:
	ldr r0, _08144ABC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08144AAA:
	mov r6, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08144AC0
	adds r0, #4
	b _08144ACC
	.align 2, 0
_08144ABC: .4byte 0x030046A4
_08144AC0:
	ldr r0, _08144AE0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08144ACC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r3, r0, #8
	cmp r2, #1
	beq _08144AE4
	cmp r2, #2
	beq _08144AE8
	b _08144AEC
	.align 2, 0
_08144AE0: .4byte 0x030046A4
_08144AE4:
	ldrb r0, [r6, #4]
	b _08144AEA
_08144AE8:
	ldrb r0, [r6]
_08144AEA:
	subs r3, r3, r0
_08144AEC:
	ldr r2, _08144B68 @ =0x00000472
	adds r1, r5, r2
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, r3
	bge _08144B42
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r5, r2
	strh r0, [r1]
	adds r2, #2
	adds r1, r5, r2
	strh r0, [r1]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	strh r0, [r5, #0x10]
	strh r0, [r5, #0x14]
	strh r0, [r5, #0x12]
	movs r2, #2
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08144B42:
	mov r0, sp
	movs r1, #2
	ldrsh r0, [r0, r1]
	cmp r0, r3
	bge _08144B5E
	movs r2, #0xe1
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	strh r0, [r5, #0x12]
	ldr r2, _08144B6C @ =0x000006B2
	adds r1, r7, r2
	strh r0, [r1]
_08144B5E:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08144B68: .4byte 0x00000472
_08144B6C: .4byte 0x000006B2

	thumb_func_start FUN_08144b70
FUN_08144b70: @ 0x08144B70
	push {lr}
	ldr r0, [r0, #0x44]
	adds r1, r0, #0
	adds r1, #0x48
	ldrh r0, [r1, #8]
	cmp r0, #5
	bne _08144B8A
	ldrh r0, [r1, #0xe]
	cmp r0, #0
	bne _08144B8A
	movs r0, #0xf6
	bl PlaySound_082406e0
_08144B8A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08144b90
FUN_08144b90: @ 0x08144B90
	push {r4, lr}
	adds r3, r0, #0
	movs r1, #8
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r3, r0
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08144BD4
	movs r2, #0xa
	ldrsh r1, [r3, r2]
	ldr r0, _08144BD8 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08144BB8
	rsbs r1, r1, #0
_08144BB8:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _08144BD4
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _08144BDC
_08144BD4:
	movs r0, #0
	b _08144BF6
	.align 2, 0
_08144BD8: .4byte 0x03002BE0
_08144BDC:
	movs r0, #0x80
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r3, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #0x14
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #1
_08144BF6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08144bfc
FUN_08144bfc: @ 0x08144BFC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08144C28
	movs r3, #0x93
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r1, [r0]
	ldr r7, _08144C24 @ =0x0000024E
	adds r0, r4, r7
	strh r1, [r0]
	b _08144C9E
	.align 2, 0
_08144C24: .4byte 0x0000024E
_08144C28:
	movs r0, #0x80
	lsls r0, r0, #0x13
	mov ip, r0
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r6, r4, r1
	ldr r5, [r6]
	ands r5, r0
	cmp r5, #0
	bne _08144C9E
	ldr r2, _08144CA4 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _08144CA8 @ =0x0000046D
	adds r0, r4, r3
	movs r3, #1
	strb r3, [r0]
	ldr r7, _08144CAC @ =0x0000046B
	adds r0, r4, r7
	strb r5, [r0]
	adds r7, #0xe8
	adds r0, r4, r7
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r4, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r1, #0
	strh r5, [r0]
	movs r2, #3
	subs r7, #0xeb
	adds r0, r4, r7
	strb r1, [r0]
	adds r7, #1
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _08144CB0 @ =0x0000046A
	adds r0, r4, r1
	strb r2, [r0]
	ldr r2, _08144CB4 @ =0x00000484
	adds r0, r4, r2
	str r5, [r0]
	adds r7, #3
	adds r0, r4, r7
	strb r3, [r0]
	ldr r0, [r6]
	mov r1, ip
	orrs r0, r1
	str r0, [r6]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r4, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08144C9E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08144CA4: .4byte FUN_080e48d0
_08144CA8: .4byte 0x0000046D
_08144CAC: .4byte 0x0000046B
_08144CB0: .4byte 0x0000046A
_08144CB4: .4byte 0x00000484

	thumb_func_start FUN_08144cb8
FUN_08144cb8: @ 0x08144CB8
	push {lr}
	bl FUN_08144414
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08144cc4
FUN_08144cc4: @ 0x08144CC4
	push {lr}
	bl FUN_081449f8
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08144cd0
FUN_08144cd0: @ 0x08144CD0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _08144CF0 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08144CF4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08144CF6
	.align 2, 0
_08144CF0: .4byte 0x0000046C
_08144CF4:
	movs r0, #0
_08144CF6:
	cmp r0, #0
	beq _08144D2C
	ldr r4, _08144D44 @ =FUN_081432ec
	movs r3, #0x25
	ldr r0, _08144D48 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08144D4C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	movs r3, #0xaf
	lsls r3, r3, #3
	adds r0, r5, r3
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r5, r4
	strh r2, [r0]
	ldr r0, _08144D50 @ =0x000006B2
	adds r1, r6, r0
	movs r0, #0x1e
	strh r0, [r1]
_08144D2C:
	ldr r1, _08144D54 @ =0x00000256
	adds r0, r5, r1
	ldrh r4, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08144D58
	adds r0, #4
	b _08144D64
	.align 2, 0
_08144D44: .4byte FUN_081432ec
_08144D48: .4byte 0x0000046D
_08144D4C: .4byte 0x0000046B
_08144D50: .4byte 0x000006B2
_08144D54: .4byte 0x00000256
_08144D58:
	ldr r0, _08144DA4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08144D64:
	ldrh r0, [r0, #2]
	movs r1, #0x42
	ands r0, r1
	cmp r0, #0
	beq _08144DB4
	ldr r2, _08144DA8 @ =0x00000484
	adds r0, r5, r2
	ldr r0, [r0]
	cmp r0, #0x14
	bgt _08144D7A
	b _08144EB4
_08144D7A:
	movs r2, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08144DAC @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r0, _08144DB0 @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _08144EBE
	.align 2, 0
_08144DA4: .4byte 0x030046A4
_08144DA8: .4byte 0x00000484
_08144DAC: .4byte 0x00000469
_08144DB0: .4byte 0x0000046C
_08144DB4:
	ldr r1, _08144DD0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08144DD8
	ldr r3, _08144DD4 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _08144DE8
	.align 2, 0
_08144DD0: .4byte 0x0000A02F
_08144DD4: .4byte 0x00000482
_08144DD8:
	ldr r4, _08144E0C @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _08144DE8
	movs r0, #1
	strh r0, [r2]
_08144DE8:
	ldr r1, _08144E10 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08144E14
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _08144E2C
	.align 2, 0
_08144E0C: .4byte 0x00000482
_08144E10: .4byte 0x0000025D
_08144E14:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_08144E2C:
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r3, _08144E5C @ =0x000006B2
	adds r4, r6, r3
	ldrh r0, [r4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r3, _08144E60 @ =0x00000484
	adds r0, r5, r3
	ldr r0, [r0]
	movs r1, #4
	bl Mod
	cmp r0, #0
	bne _08144E70
	movs r1, #0
	ldrsh r0, [r4, r1]
	cmp r0, #0
	blt _08144E64
	asrs r1, r0, #1
	b _08144E6A
	.align 2, 0
_08144E5C: .4byte 0x000006B2
_08144E60: .4byte 0x00000484
_08144E64:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08144E6A:
	ldr r2, _08144EA4 @ =0x000006B2
	adds r0, r6, r2
	strh r1, [r0]
_08144E70:
	ldr r3, _08144EA4 @ =0x000006B2
	adds r0, r6, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	bgt _08144EB4
	movs r2, #2
	movs r3, #1
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08144EA8 @ =0x00000469
	adds r0, r5, r4
	strb r2, [r0]
	ldr r2, _08144EAC @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _08144EB0 @ =0x0000046C
	adds r0, r5, r1
	strb r3, [r0]
	b _08144EBE
	.align 2, 0
_08144EA4: .4byte 0x000006B2
_08144EA8: .4byte 0x00000469
_08144EAC: .4byte 0x0000046A
_08144EB0: .4byte 0x0000046C
_08144EB4:
	ldr r2, _08144EC4 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_08144EBE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08144EC4: .4byte 0x00000484

	thumb_func_start FUN_08144ec8
FUN_08144ec8: @ 0x08144EC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _08144EEC @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _08144EF0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08144EF2
	.align 2, 0
_08144EEC: .4byte 0x0000046C
_08144EF0:
	movs r0, #0
_08144EF2:
	cmp r0, #0
	bne _08144EF8
	b _08145084
_08144EF8:
	ldr r4, _08144F9C @ =FUN_081431e0
	movs r2, #0x24
	ldr r0, _08144FA0 @ =0x0000046D
	adds r1, r6, r0
	movs r3, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _08144FA4 @ =0x0000046B
	adds r0, r6, r1
	strb r3, [r0]
	adds r1, #0xe8
	adds r0, r6, r1
	strb r2, [r0]
	movs r2, #0xaf
	lsls r2, r2, #3
	adds r0, r6, r2
	str r4, [r0]
	movs r4, #0xe4
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r3, [r0]
	ldr r0, _08144FA8 @ =0x000004A4
	adds r5, r6, r0
	ldr r2, [r5]
	ldr r0, _08144FAC @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2, #0xc]
	str r1, [r2, #0x10]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r1, r7, r2
	str r3, [sp]
	mov r0, sp
	ldr r2, _08144FB0 @ =0x05000002
	bl CpuSet
	add r4, sp, #4
	adds r3, r6, #0
	adds r3, #8
	ldr r0, [r5]
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r6, #8]
	subs r0, r0, r1
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl FUN_0823785c
	strb r0, [r6, #5]
	ldr r2, _08144FB4 @ =0x085B0A08
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _08144FB8 @ =0x0000065D
	adds r0, r7, r2
	ldrb r0, [r0]
	muls r0, r1, r0
	mov r8, r4
	cmp r0, #0
	blt _08144FBC
	asrs r1, r0, #0xc
	b _08144FC2
	.align 2, 0
_08144F9C: .4byte FUN_081431e0
_08144FA0: .4byte 0x0000046D
_08144FA4: .4byte 0x0000046B
_08144FA8: .4byte 0x000004A4
_08144FAC: .4byte 0x03002BE0
_08144FB0: .4byte 0x05000002
_08144FB4: .4byte 0x085B0A08
_08144FB8: .4byte 0x0000065D
_08144FBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08144FC2:
	movs r4, #0xd6
	lsls r4, r4, #3
	adds r0, r7, r4
	strh r1, [r0]
	ldr r1, _08144FE8 @ =0x085B0A08
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	subs r4, #0x53
	adds r0, r7, r4
	ldrb r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _08144FEC
	asrs r1, r0, #0xc
	b _08144FF2
	.align 2, 0
_08144FE8: .4byte 0x085B0A08
_08144FEC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08144FF2:
	ldr r0, _08145054 @ =0x000006B4
	adds r6, r7, r0
	movs r0, #0
	strh r1, [r6]
	ldr r1, _08145058 @ =0x000006B2
	adds r4, r7, r1
	strh r0, [r4]
	movs r2, #0xd6
	lsls r2, r2, #3
	adds r5, r7, r2
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	beq _0814501E
	mov r2, r8
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r2, #0
	ldrsh r1, [r5, r2]
	bl Div
	strh r0, [r5]
_0814501E:
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _08145036
	mov r2, r8
	movs r1, #4
	ldrsh r0, [r2, r1]
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl Div
	strh r0, [r6]
_08145036:
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r1, r0
	ble _0814505C
	cmp r1, #0
	beq _08145072
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	subs r0, #0x20
	movs r2, #0
	ldrsh r1, [r5, r2]
	b _0814506C
	.align 2, 0
_08145054: .4byte 0x000006B4
_08145058: .4byte 0x000006B2
_0814505C:
	cmp r0, #0
	beq _08145072
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	subs r0, #0x20
	movs r2, #0
	ldrsh r1, [r6, r2]
_0814506C:
	bl Div
	strh r0, [r4]
_08145072:
	movs r0, #0xf7
	bl PlaySound_082406e0
	movs r4, #0xce
	lsls r4, r4, #3
	adds r1, r7, r4
	movs r0, #0
	strb r0, [r1]
	b _081452BA
_08145084:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	ldr r1, _081450B0 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081450B8
	ldr r4, _081450B4 @ =0x00000482
	adds r1, r6, r4
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _081450C8
	.align 2, 0
_081450B0: .4byte 0x0000A02F
_081450B4: .4byte 0x00000482
_081450B8:
	ldr r1, _081450EC @ =0x00000482
	adds r0, r6, r1
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _081450C8
	movs r0, #1
	strh r0, [r2]
_081450C8:
	ldr r4, _081450F0 @ =0x0000025D
	adds r0, r6, r4
	ldrb r0, [r0]
	cmp r0, #0
	bne _081450F4
	ldr r4, [r6, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _0814510C
	.align 2, 0
_081450EC: .4byte 0x00000482
_081450F0: .4byte 0x0000025D
_081450F4:
	ldr r4, [r6, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_0814510C:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r2, _0814513C @ =0x000006B2
	adds r4, r7, r2
	ldrh r0, [r4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r1, _08145140 @ =0x00000484
	adds r0, r6, r1
	ldr r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _08145150
	movs r2, #0
	ldrsh r0, [r4, r2]
	cmp r0, #0
	blt _08145144
	asrs r1, r0, #1
	b _0814514A
	.align 2, 0
_0814513C: .4byte 0x000006B2
_08145140: .4byte 0x00000484
_08145144:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_0814514A:
	ldr r4, _08145190 @ =0x000006B2
	adds r0, r7, r4
	strh r1, [r0]
_08145150:
	ldr r1, _08145194 @ =0x0000065D
	adds r0, r7, r1
	ldrb r4, [r0]
	ldr r2, _08145198 @ =0x000004A4
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
	bge _08145178
	rsbs r2, r2, #0
_08145178:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0814519C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _08145186
	rsbs r2, r2, #0
_08145186:
	cmp r2, #0x20
	bgt _0814519C
	movs r0, #1
	b _08145206
	.align 2, 0
_08145190: .4byte 0x000006B2
_08145194: .4byte 0x0000065D
_08145198: .4byte 0x000004A4
_0814519C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081451A8
	cmp r1, #0
	beq _08145204
_081451A8:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r6, #5]
	ldr r2, _081451CC @ =0x085B0A08
	ldrb r0, [r6, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081451D0
	asrs r1, r0, #0xc
	b _081451D6
	.align 2, 0
_081451CC: .4byte 0x085B0A08
_081451D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081451D6:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r1, _081451F4 @ =0x085B0A08
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _081451F8
	asrs r1, r0, #0xc
	b _081451FE
	.align 2, 0
_081451F4: .4byte 0x085B0A08
_081451F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081451FE:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
_08145204:
	movs r0, #0
_08145206:
	cmp r0, #0
	bne _08145224
	movs r1, #2
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r7, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814521E
	movs r0, #1
	b _08145220
_0814521E:
	movs r0, #0
_08145220:
	cmp r0, #0
	beq _081452B0
_08145224:
	ldr r1, _08145250 @ =0x0000065D
	adds r0, r7, r1
	ldrb r0, [r0]
	movs r2, #0xe0
	lsls r2, r2, #1
	adds r4, r6, r2
	ldrb r3, [r6, #5]
	lsls r5, r0, #1
	ldr r2, _08145254 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08145258
	asrs r1, r0, #0xc
	b _0814525E
	.align 2, 0
_08145250: .4byte 0x0000065D
_08145254: .4byte 0x085B0A08
_08145258:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0814525E:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r5, r0
	cmp r0, #0
	blt _08145276
	asrs r0, r0, #0xc
	b _0814527C
_08145276:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0814527C:
	movs r2, #0
	movs r3, #0
	strh r0, [r4, #4]
	movs r1, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r6, r4
	strb r2, [r0]
	ldr r2, _081452A8 @ =0x00000469
	adds r0, r6, r2
	strb r1, [r0]
	adds r4, #2
	adds r0, r6, r4
	strb r1, [r0]
	ldr r1, _081452AC @ =0x00000484
	adds r0, r6, r1
	str r3, [r0]
	adds r2, #3
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _081452BA
	.align 2, 0
_081452A8: .4byte 0x00000469
_081452AC: .4byte 0x00000484
_081452B0:
	ldr r4, _081452C8 @ =0x00000484
	adds r1, r6, r4
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_081452BA:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081452C8: .4byte 0x00000484

	thumb_func_start FUN_081452cc
FUN_081452cc: @ 0x081452CC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081452E4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _081452E8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081452EA
	.align 2, 0
_081452E4: .4byte 0x0000046C
_081452E8:
	movs r0, #0
_081452EA:
	cmp r0, #0
	beq _08145322
	movs r1, #0xb4
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r3, [r0]
	movs r1, #1
	ldr r2, _0814534C @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _08145350 @ =0x0000046B
	adds r0, r5, r4
	strb r2, [r0]
	adds r4, #0xe8
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	ldrb r0, [r5, #5]
	adds r0, #0x80
	strb r0, [r5, #5]
_08145322:
	movs r4, #0xc1
	lsls r4, r4, #3
	adds r0, r5, r4
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	ldr r1, _08145354 @ =0x0000A02F
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0814535C
	ldr r3, _08145358 @ =0x00000482
	adds r1, r5, r3
	movs r0, #1
	strh r0, [r1]
	adds r2, r1, #0
	b _0814536C
	.align 2, 0
_0814534C: .4byte 0x0000046D
_08145350: .4byte 0x0000046B
_08145354: .4byte 0x0000A02F
_08145358: .4byte 0x00000482
_0814535C:
	ldr r4, _08145390 @ =0x00000482
	adds r0, r5, r4
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	bne _0814536C
	movs r0, #1
	strh r0, [r2]
_0814536C:
	ldr r1, _08145394 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08145398
	ldr r4, [r5, #0x44]
	adds r4, #0x48
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_08237098
	b _081453B0
	.align 2, 0
_08145390: .4byte 0x00000482
_08145394: .4byte 0x0000025D
_08145398:
	ldr r4, [r5, #0x44]
	adds r4, #0x20
	ldrh r1, [r2]
	movs r0, #0x40
	bl Div
	adds r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl FUN_0823723c
_081453B0:
	ldr r2, _081453FC @ =0x00000472
	adds r0, r5, r2
	ldrh r1, [r0]
	movs r3, #0xa
	ldrsh r0, [r5, r3]
	ldr r4, _08145400 @ =0xFFFFFEC0
	adds r0, r0, r4
	subs r1, r1, r0
	cmp r1, #0
	bge _081453C6
	rsbs r1, r1, #0
_081453C6:
	cmp r1, #0x10
	bgt _08145410
	ldr r1, _08145404 @ =0x00000484
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0x50
	ble _08145410
	movs r2, #1
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r5, r3
	movs r1, #0
	strb r1, [r0]
	ldr r4, _08145408 @ =0x00000469
	adds r0, r5, r4
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r2, [r0]
	adds r4, #0x1b
	adds r0, r5, r4
	str r1, [r0]
	ldr r1, _0814540C @ =0x0000046C
	adds r0, r5, r1
	strb r2, [r0]
	b _0814541A
	.align 2, 0
_081453FC: .4byte 0x00000472
_08145400: .4byte 0xFFFFFEC0
_08145404: .4byte 0x00000484
_08145408: .4byte 0x00000469
_0814540C: .4byte 0x0000046C
_08145410:
	ldr r2, _08145420 @ =0x00000484
	adds r1, r5, r2
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0814541A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08145420: .4byte 0x00000484

	thumb_func_start FUN_08145424
FUN_08145424: @ 0x08145424
	ldr r1, _08145430 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08145434 @ =0x085AD84C
	str r1, [r0]
	bx lr
	.align 2, 0
_08145430: .4byte 0x0000063C
_08145434: .4byte 0x085AD84C

	thumb_func_start FUN_08145438
FUN_08145438: @ 0x08145438
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08144cb8
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _08145470 @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	adds r0, r4, #0
	bl FUN_08144cc4
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_08145470: .4byte 0x0000062C

	thumb_func_start FUN_08145474
FUN_08145474: @ 0x08145474
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _08145490 @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_08145490: .4byte 0x03002BE0

	thumb_func_start EnemyCrow_Destroy
EnemyCrow_Destroy: @ 0x08145494
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081454AC @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081454B0
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081454B8
	.align 2, 0
_081454AC: .4byte 0x0000025D
_081454B0:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081454B8:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081454D4 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081454D8
	movs r0, #1
	b _081454DA
	.align 2, 0
_081454D4: .4byte 0x00000474
_081454D8:
	movs r0, #0
_081454DA:
	cmp r0, #0
	beq _081454E6
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_081454E6:
	ldr r1, _08145540 @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _081454FE
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_081454FE:
	ldr r0, _08145544 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08145516
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_08145516:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814552E
	adds r0, r4, #0
	bl FUN_08002a58
_0814552E:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08145548
	movs r0, #1
	b _0814554A
	.align 2, 0
_08145540: .4byte 0x0000044C
_08145544: .4byte 0x0000044D
_08145548:
	movs r0, #0
_0814554A:
	cmp r0, #0
	beq _08145556
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08145556:
	adds r0, r4, #0
	bl FUN_0823b284
	adds r0, r4, #0
	adds r0, #0xd8
	bl FUN_08236424
	adds r0, r4, #0
	bl FUN_080ec6fc
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EnemyCrow_Init
EnemyCrow_Init: @ 0x08145574
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1a4
	adds r7, r0, #0
	str r7, [sp, #0x24]
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r7, r1
	movs r6, #0
	str r6, [r0]
	adds r0, r7, #0
	adds r1, r7, #0
	movs r2, #0
	bl FUN_080e37e8
	ldr r2, _08145600 @ =0x000001DF
	adds r1, r7, r2
	movs r0, #0x13
	strb r0, [r1]
	adds r0, r7, #0
	bl FUN_08144758
	ldr r3, _08145604 @ =0x0000025D
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _08145610
	movs r0, #0x5c
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x5c
	bl ClearMemory
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, r4, #0
	ldr r1, _08145608 @ =0x00005A6E
	bl Video_GetActorSprite
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	adds r0, r5, #0
	ldr r1, _0814560C @ =0x00007B03
	bl FUN_080e3804
	ldr r4, _08145600 @ =0x000001DF
	adds r0, r7, r4
	ldrb r1, [r0]
	str r0, [sp, #0xa0]
	cmp r1, #0x11
	beq _081455EE
	cmp r1, #0x17
	bne _081455F2
_081455EE:
	movs r0, #1
	strb r0, [r5, #7]
_081455F2:
	movs r5, #0xef
	lsls r5, r5, #1
	adds r1, r7, r5
	movs r0, #0
	strb r0, [r1]
	b _08145678
	.align 2, 0
_08145600: .4byte 0x000001DF
_08145604: .4byte 0x0000025D
_08145608: .4byte 0x00005A6E
_0814560C: .4byte 0x00007B03
_08145610:
	movs r0, #0x80
	bl Malloc
	str r0, [r7, #0x44]
	movs r1, #0x80
	bl ClearMemory
	ldr r4, [r7, #0x44]
	add r0, sp, #0x14
	mov r8, r0
	str r6, [sp, #0x10]
	add r0, sp, #0x10
	mov r1, r8
	ldr r2, _081456F4 @ =0x05000002
	bl CpuSet
	ldr r0, _081456F8 @ =0x0000CB05
	ldr r1, _081456FC @ =0x00005A6E
	bl GetFile
	adds r1, r0, #0
	adds r2, r4, #0
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	adds r0, r4, #0
	bl OpenSpriteSetFile
	adds r0, r4, #0
	adds r0, #0x20
	movs r1, #2
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	mov r6, r8
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0822f3fc
	ldr r0, _08145700 @ =0x000004B7
	adds r1, r7, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _08145704 @ =0x000001DF
	adds r1, r7, r1
	str r1, [sp, #0xa0]
_08145678:
	str r7, [sp, #0x28]
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sb, r2
	movs r4, #0
	str r4, [r2]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r3, r3, r7
	mov r8, r3
	str r4, [r3]
	ldr r5, _08145708 @ =0x0000046F
	adds r0, r7, r5
	strb r4, [r0]
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #0
	mov sl, r0
	movs r0, #8
	strh r0, [r1]
	movs r0, #0x4d
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, _0814570C @ =0x00000474
	adds r6, r7, r1
	strh r0, [r6]
	add r5, sp, #0x1c
	str r4, [sp, #0x10]
	add r0, sp, #0x10
	adds r1, r5, #0
	ldr r2, _081456F4 @ =0x05000002
	bl CpuSet
	ldr r3, _08145710 @ =0x000004B6
	adds r2, r7, r3
	mov r4, sl
	strb r4, [r2]
	movs r0, #0x72
	str r2, [sp, #0x19c]
	bl VM_SeekToKeyword
	mov r1, sb
	str r1, [sp, #0x70]
	mov r3, r8
	str r3, [sp, #0x74]
	str r6, [sp, #0x4c]
	ldr r2, [sp, #0x19c]
	adds r6, r2, #0
	cmp r0, #0
	bne _081456E4
	b _08145844
_081456E4:
	bl VM_GetPC
	cmp r0, #0
	beq _08145714
	bl Script_GetValue
	adds r1, r0, #0
	b _08145716
	.align 2, 0
_081456F4: .4byte 0x05000002
_081456F8: .4byte 0x0000CB05
_081456FC: .4byte 0x00005A6E
_08145700: .4byte 0x000004B7
_08145704: .4byte 0x000001DF
_08145708: .4byte 0x0000046F
_0814570C: .4byte 0x00000474
_08145710: .4byte 0x000004B6
_08145714:
	movs r1, #0
_08145716:
	movs r4, #0x94
	lsls r4, r4, #2
	adds r5, r7, r4
	movs r0, #0
	strb r1, [r5]
	ldr r1, _0814573C @ =0x00000251
	adds r4, r7, r1
	strb r0, [r4]
	bl VM_GetPC
	str r5, [sp, #0x118]
	str r4, [sp, #0x11c]
	cmp r0, #0
	beq _08145740
	bl Script_GetValue
	adds r1, r0, #0
	b _08145742
	.align 2, 0
_0814573C: .4byte 0x00000251
_08145740:
	movs r1, #0
_08145742:
	ldr r2, _08145778 @ =0x00000252
	adds r4, r7, r2
	strb r1, [r4]
	movs r3, #0x97
	lsls r3, r3, #2
	adds r0, r7, r3
	strb r1, [r0]
	ldrb r0, [r6]
	ldr r5, _0814577C @ =0x000004B4
	adds r2, r7, r5
	adds r0, r2, r0
	ldr r3, [sp, #0x118]
	ldrb r1, [r3]
	strb r1, [r0]
	ldrb r1, [r6]
	movs r0, #1
	eors r0, r1
	adds r6, r2, r0
	bl VM_GetPC
	str r4, [sp, #0x120]
	cmp r0, #0
	beq _08145780
	bl Script_GetValue
	b _08145784
	.align 2, 0
_08145778: .4byte 0x00000252
_0814577C: .4byte 0x000004B4
_08145780:
	ldr r4, [sp, #0x118]
	ldrb r0, [r4]
_08145784:
	strb r0, [r6]
	ldr r5, [sp, #0x118]
	ldrb r1, [r5]
	ldr r6, [sp, #0x120]
	ldrb r2, [r6]
	add r0, sp, #0x1c
	bl FUN_08234f90
	add r0, sp, #0x1c
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sp
	ldrh r0, [r1, #0x20]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _081457BC
	cmp r1, #0
	blt _081457BC
	ldr r0, _081457C0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _081457BC
	ldr r0, _081457C4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081457C8
_081457BC:
	movs r1, #0
	b _081457D6
	.align 2, 0
_081457C0: .4byte 0x030046A8
_081457C4: .4byte 0x030046AC
_081457C8:
	ldr r0, _081457F0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r2
_081457D6:
	ldr r2, _081457F4 @ =0x00000256
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r6, [r0]
	add r4, sp, #0x1c
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081457F8
	adds r0, #4
	b _08145804
	.align 2, 0
_081457F0: .4byte 0x030046A4
_081457F4: .4byte 0x00000256
_081457F8:
	ldr r0, _08145818 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08145804:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0814581C
	cmp r2, #2
	beq _08145820
	b _08145824
	.align 2, 0
_08145818: .4byte 0x030046A4
_0814581C:
	ldrb r0, [r4, #4]
	b _08145822
_08145820:
	ldrb r0, [r4]
_08145822:
	subs r1, r1, r0
_08145824:
	ldr r3, _0814583C @ =0x00000472
	adds r0, r7, r3
	strh r1, [r0]
	ldr r4, _08145840 @ =0x0000FFFF
	adds r0, r4, #0
	ands r1, r0
	mov r5, sp
	strh r1, [r5, #0x1e]
	movs r6, #1
	str r6, [sp, #0x2c]
	b _08145884
	.align 2, 0
_0814583C: .4byte 0x00000472
_08145840: .4byte 0x0000FFFF
_08145844:
	movs r0, #0x94
	lsls r0, r0, #2
	adds r5, r7, r0
	mov r1, sl
	strb r1, [r5]
	ldr r3, _081458A8 @ =0x00000251
	adds r4, r7, r3
	strb r1, [r4]
	ldr r6, _081458AC @ =0x00000252
	adds r3, r7, r6
	strb r1, [r3]
	movs r1, #0x97
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r6, sl
	strb r6, [r0]
	ldrb r0, [r2]
	ldr r6, _081458B0 @ =0x000004B4
	adds r1, r7, r6
	adds r0, r1, r0
	mov r6, sl
	strb r6, [r0]
	ldrb r2, [r2]
	movs r0, #1
	eors r0, r2
	adds r1, r1, r0
	strb r6, [r1]
	movs r0, #0
	str r0, [sp, #0x2c]
	str r5, [sp, #0x118]
	str r4, [sp, #0x11c]
	str r3, [sp, #0x120]
_08145884:
	movs r0, #0x4e
	movs r1, #0
	bl VM_GetKeywordValue
	mov sb, r0
	movs r0, #0x65
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081458CE
	bl VM_GetPC
	cmp r0, #0
	beq _081458B4
	bl Script_GetValue
	adds r4, r0, #0
	b _081458B6
	.align 2, 0
_081458A8: .4byte 0x00000251
_081458AC: .4byte 0x00000252
_081458B0: .4byte 0x000004B4
_081458B4:
	movs r4, #0x30
_081458B6:
	bl VM_GetPC
	cmp r0, #0
	beq _081458C8
	bl Script_GetValue
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	b _081458CA
_081458C8:
	movs r5, #0x40
_081458CA:
	mov r8, r4
	b _081458D4
_081458CE:
	movs r4, #0x30
	mov r8, r4
	movs r5, #0x40
_081458D4:
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0814590C
	bl VM_GetPC
	cmp r0, #0
	beq _081458EE
	bl Script_GetValue
	adds r6, r0, #0
	b _081458F0
_081458EE:
	movs r6, #0
_081458F0:
	bl VM_GetPC
	cmp r0, #0
	beq _08145900
	bl Script_GetValue
	adds r1, r0, #0
	b _08145902
_08145900:
	movs r1, #0
_08145902:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	b _08145916
_0814590C:
	movs r6, #0
	movs r3, #0xff
	lsls r3, r3, #1
	adds r0, r7, r3
	strh r6, [r0]
_08145916:
	movs r0, #0x61
	bl VM_SeekToKeyword
	ldr r1, _08145B88 @ =0x0000025D
	adds r1, r7, r1
	str r1, [sp, #0x134]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x114]
	movs r3, #0xcb
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x7c]
	movs r1, #0xca
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0x78]
	movs r2, #0x95
	lsls r2, r2, #2
	adds r2, r7, r2
	str r2, [sp, #0x124]
	lsls r4, r4, #0x10
	str r4, [sp, #0x94]
	mov r3, r8
	lsls r3, r3, #0x10
	str r3, [sp, #0x9c]
	lsls r6, r6, #0x10
	str r6, [sp, #0xa4]
	lsls r5, r5, #0x10
	str r5, [sp, #0x98]
	ldr r4, _08145B8C @ =0x0000025A
	adds r4, r7, r4
	str r4, [sp, #0x12c]
	mov r5, sb
	lsls r5, r5, #0x10
	str r5, [sp, #0x8c]
	adds r6, r7, #0
	adds r6, #0x8c
	str r6, [sp, #0x34]
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r1, r7, r1
	str r1, [sp, #0xac]
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0xb0]
	adds r3, r7, #0
	adds r3, #0xa8
	str r3, [sp, #0x38]
	adds r4, r7, #0
	adds r4, #0xac
	str r4, [sp, #0x3c]
	adds r5, r7, #0
	adds r5, #8
	str r5, [sp, #0x30]
	movs r6, #0x90
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x5c]
	ldr r1, _08145B90 @ =0x0000047A
	adds r1, r7, r1
	str r1, [sp, #0x50]
	ldr r2, _08145B94 @ =0x0000047C
	adds r2, r7, r2
	str r2, [sp, #0x54]
	ldr r3, _08145B98 @ =0x0000047E
	adds r3, r7, r3
	str r3, [sp, #0x58]
	ldr r4, _08145B9C @ =0x000004A4
	adds r4, r7, r4
	str r4, [sp, #0x68]
	movs r5, #0x95
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x6c]
	movs r6, #0xb0
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0xe8]
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0xf0]
	movs r2, #0xb2
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0xf8]
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x108]
	ldr r4, _08145BA0 @ =0x000005A4
	adds r4, r7, r4
	str r4, [sp, #0x10c]
	movs r5, #0xb8
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x13c]
	ldr r6, _08145BA4 @ =0x000005C4
	adds r6, r7, r6
	str r6, [sp, #0x140]
	ldr r1, _08145BA8 @ =0x000005CC
	adds r1, r7, r1
	str r1, [sp, #0x148]
	movs r2, #0xba
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x14c]
	ldr r3, _08145BAC @ =0x000005D4
	adds r3, r7, r3
	str r3, [sp, #0x150]
	ldr r4, _08145BB0 @ =0x000005DC
	adds r4, r7, r4
	str r4, [sp, #0x158]
	movs r5, #0xb9
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x144]
	ldr r6, _08145BB4 @ =0x00000584
	adds r6, r7, r6
	str r6, [sp, #0xec]
	ldr r1, _08145BB8 @ =0x00000604
	adds r1, r7, r1
	str r1, [sp, #0x17c]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x180]
	ldr r3, _08145BBC @ =0x0000021D
	adds r3, r7, r3
	str r3, [sp, #0xe4]
	ldr r4, _08145BC0 @ =0x0000060C
	adds r4, r7, r4
	str r4, [sp, #0x184]
	movs r5, #0xbe
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x16c]
	ldr r6, _08145BC4 @ =0x000005E4
	adds r6, r7, r6
	str r6, [sp, #0x160]
	movs r1, #0xbf
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x170]
	ldr r2, _08145BC8 @ =0x000005FC
	adds r2, r7, r2
	str r2, [sp, #0x174]
	movs r3, #0xc0
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x178]
	ldr r4, _08145BCC @ =0x00000614
	adds r4, r7, r4
	str r4, [sp, #0x188]
	movs r5, #0xc3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x18c]
	ldr r6, _08145BD0 @ =0x000005BC
	adds r6, r7, r6
	str r6, [sp, #0x138]
	movs r1, #0xbd
	lsls r1, r1, #3
	adds r1, r7, r1
	str r1, [sp, #0x164]
	movs r2, #0xbc
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x15c]
	ldr r3, _08145BD4 @ =0x000005EC
	adds r3, r7, r3
	str r3, [sp, #0x168]
	movs r4, #0xbb
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0x154]
	movs r5, #0xb5
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x110]
	ldr r6, _08145BD8 @ =0x00000624
	adds r6, r7, r6
	str r6, [sp, #0x190]
	ldr r1, _08145BDC @ =0x0000058C
	adds r1, r7, r1
	str r1, [sp, #0xf4]
	movs r2, #0xc5
	lsls r2, r2, #3
	adds r2, r7, r2
	str r2, [sp, #0x194]
	movs r3, #0xb7
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0x130]
	ldr r4, _08145BE0 @ =0x00000594
	adds r4, r7, r4
	str r4, [sp, #0xfc]
	movs r5, #0xb3
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x100]
	ldr r6, _08145BE4 @ =0x0000059C
	adds r6, r7, r6
	str r6, [sp, #0x104]
	ldr r1, _08145BE8 @ =0x000005B4
	adds r1, r7, r1
	str r1, [sp, #0x128]
	ldr r2, _08145BEC @ =0x00000543
	adds r2, r7, r2
	str r2, [sp, #0xa8]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r3, r7, r3
	str r3, [sp, #0x80]
	movs r4, #0xcd
	lsls r4, r4, #1
	adds r4, r7, r4
	str r4, [sp, #0x84]
	ldr r5, _08145BF0 @ =0x00000496
	adds r5, r7, r5
	str r5, [sp, #0x64]
	movs r6, #0x8d
	lsls r6, r6, #3
	adds r6, r7, r6
	str r6, [sp, #0x40]
	ldr r1, _08145BF4 @ =0x00000469
	adds r1, r7, r1
	str r1, [sp, #0x44]
	ldr r2, _08145BF8 @ =0x0000046A
	adds r2, r7, r2
	str r2, [sp, #0x48]
	ldr r3, _08145BFC @ =0x00000553
	adds r3, r7, r3
	str r3, [sp, #0xb4]
	movs r4, #0xaf
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xe0]
	movs r5, #0x92
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0x60]
	movs r6, #0xea
	lsls r6, r6, #1
	adds r6, r7, r6
	str r6, [sp, #0x90]
	ldr r1, _08145C00 @ =0x00000572
	adds r1, r7, r1
	str r1, [sp, #0xdc]
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r2, r7, r2
	str r2, [sp, #0x88]
	movs r3, #0xae
	lsls r3, r3, #3
	adds r3, r7, r3
	str r3, [sp, #0xd8]
	ldr r4, _08145C04 @ =0x0000055C
	adds r4, r7, r4
	str r4, [sp, #0xb8]
	movs r5, #0xac
	lsls r5, r5, #3
	adds r5, r7, r5
	str r5, [sp, #0xbc]
	ldr r6, _08145C08 @ =0x00000564
	adds r6, r7, r6
	str r6, [sp, #0xc0]
	ldr r1, _08145C0C @ =0x00000565
	adds r1, r7, r1
	str r1, [sp, #0xc4]
	ldr r2, _08145C10 @ =0x00000566
	adds r2, r7, r2
	str r2, [sp, #0xc8]
	ldr r3, _08145C14 @ =0x00000567
	adds r3, r7, r3
	str r3, [sp, #0xcc]
	movs r4, #0xad
	lsls r4, r4, #3
	adds r4, r7, r4
	str r4, [sp, #0xd0]
	ldr r5, _08145C18 @ =0x0000056C
	adds r5, r7, r5
	str r5, [sp, #0xd4]
	cmp r0, #0
	bne _08145B58
	b _08145C72
_08145B58:
	movs r6, #0
	mov sl, r6
	movs r0, #0x8d
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sb, r0
	movs r1, #0x8f
	lsls r1, r1, #2
	adds r1, r1, r7
	mov r8, r1
	movs r2, #0x8b
	lsls r2, r2, #2
	adds r5, r7, r2
	movs r3, #0x89
	lsls r3, r3, #2
	adds r4, r7, r3
_08145B78:
	bl VM_GetPC
	cmp r0, #0
	beq _08145C1C
	bl Script_GetValue
	b _08145C1E
	.align 2, 0
_08145B88: .4byte 0x0000025D
_08145B8C: .4byte 0x0000025A
_08145B90: .4byte 0x0000047A
_08145B94: .4byte 0x0000047C
_08145B98: .4byte 0x0000047E
_08145B9C: .4byte 0x000004A4
_08145BA0: .4byte 0x000005A4
_08145BA4: .4byte 0x000005C4
_08145BA8: .4byte 0x000005CC
_08145BAC: .4byte 0x000005D4
_08145BB0: .4byte 0x000005DC
_08145BB4: .4byte 0x00000584
_08145BB8: .4byte 0x00000604
_08145BBC: .4byte 0x0000021D
_08145BC0: .4byte 0x0000060C
_08145BC4: .4byte 0x000005E4
_08145BC8: .4byte 0x000005FC
_08145BCC: .4byte 0x00000614
_08145BD0: .4byte 0x000005BC
_08145BD4: .4byte 0x000005EC
_08145BD8: .4byte 0x00000624
_08145BDC: .4byte 0x0000058C
_08145BE0: .4byte 0x00000594
_08145BE4: .4byte 0x0000059C
_08145BE8: .4byte 0x000005B4
_08145BEC: .4byte 0x00000543
_08145BF0: .4byte 0x00000496
_08145BF4: .4byte 0x00000469
_08145BF8: .4byte 0x0000046A
_08145BFC: .4byte 0x00000553
_08145C00: .4byte 0x00000572
_08145C04: .4byte 0x0000055C
_08145C08: .4byte 0x00000564
_08145C0C: .4byte 0x00000565
_08145C10: .4byte 0x00000566
_08145C14: .4byte 0x00000567
_08145C18: .4byte 0x0000056C
_08145C1C:
	movs r0, #0x18
_08145C1E:
	strh r0, [r4]
	adds r6, r5, #0
	bl VM_GetPC
	cmp r0, #0
	beq _08145C30
	bl Script_GetValue
	b _08145C32
_08145C30:
	movs r0, #0x18
_08145C32:
	strh r0, [r6]
	mov r6, r8
	bl VM_GetPC
	cmp r0, #0
	beq _08145C44
	bl Script_GetValue
	b _08145C46
_08145C44:
	movs r0, #0
_08145C46:
	str r0, [r6]
	mov r6, sb
	bl VM_GetPC
	cmp r0, #0
	beq _08145C58
	bl Script_GetValue
	b _08145C5A
_08145C58:
	movs r0, #0
_08145C5A:
	strh r0, [r6]
	movs r6, #2
	add sb, r6
	movs r0, #4
	add r8, r0
	adds r5, #2
	adds r4, #2
	movs r1, #1
	add sl, r1
	mov r2, sl
	cmp r2, #3
	ble _08145B78
_08145C72:
	movs r0, #0x6c
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08145CBE
	bl VM_GetPC
	cmp r0, #0
	beq _08145C8C
	bl Script_GetValue
	adds r4, r0, #0
	b _08145C90
_08145C8C:
	movs r4, #0x96
	lsls r4, r4, #1
_08145C90:
	bl VM_GetPC
	cmp r0, #0
	beq _08145CA0
	bl Script_GetValue
	adds r6, r0, #0
	b _08145CA4
_08145CA0:
	movs r6, #0x96
	lsls r6, r6, #1
_08145CA4:
	bl VM_GetPC
	cmp r0, #0
	beq _08145CB2
	bl Script_GetValue
	b _08145CB8
_08145CB2:
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r3, #0
_08145CB8:
	ldr r5, [sp, #0x114]
	strh r0, [r5]
	b _08145CC6
_08145CBE:
	movs r4, #0
	movs r6, #0
	ldr r0, [sp, #0x114]
	strh r6, [r0]
_08145CC6:
	movs r0, #0x62
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08145CDE
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x74]
	ldr r0, [r2]
	orrs r0, r1
	str r0, [r2]
_08145CDE:
	movs r0, #0x46
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x7c]
	strh r0, [r3]
	movs r0, #0x52
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r5, [sp, #0x78]
	strh r0, [r5]
	movs r0, #0x41
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08145DAC
	bl VM_GetPC
	cmp r0, #0
	beq _08145D0E
	bl Script_GetValue
	b _08145D10
_08145D0E:
	movs r0, #0
_08145D10:
	ldr r1, [sp, #0x124]
	strh r0, [r1]
	ldrh r0, [r1]
	cmp r0, #0
	blt _08145D1E
	asrs r1, r0, #1
	b _08145D24
_08145D1E:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08145D24:
	ldr r2, _08145D38 @ =0x00000546
	adds r0, r7, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08145D3C
	bl Script_GetValue
	b _08145D3E
	.align 2, 0
_08145D38: .4byte 0x00000546
_08145D3C:
	movs r0, #0
_08145D3E:
	movs r3, #0xc3
	lsls r3, r3, #1
	adds r1, r7, r3
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08145D54
	bl Script_GetValue
	b _08145D56
_08145D54:
	movs r0, #0
_08145D56:
	ldr r5, _08145D6C @ =0x00000187
	adds r1, r7, r5
	strb r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08145D70
	bl Script_GetValue
	adds r1, r0, #0
	b _08145D72
	.align 2, 0
_08145D6C: .4byte 0x00000187
_08145D70:
	movs r1, #0
_08145D72:
	movs r2, #0xc4
	lsls r2, r2, #1
	adds r0, r7, r2
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08145D88
	bl Script_GetValue
	b _08145D8A
_08145D88:
	movs r0, #0
_08145D8A:
	movs r3, #0xc5
	lsls r3, r3, #1
	adds r1, r7, r3
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _08145DA2
	bl Script_GetValue
	adds r1, r0, #0
	b _08145DA4
_08145DA2:
	movs r1, #0
_08145DA4:
	movs r5, #0xc6
	lsls r5, r5, #1
	adds r0, r7, r5
	strh r1, [r0]
_08145DAC:
	ldr r0, [sp, #0x124]
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r2, r4, #0
	adds r3, r6, #0
	bl FUN_080e48e8
	ldr r1, [sp, #0x94]
	lsrs r2, r1, #0x10
	ldr r4, [sp, #0x9c]
	lsrs r3, r4, #0x10
	ldr r5, [sp, #0xa4]
	lsrs r0, r5, #0x10
	str r0, [sp]
	ldr r6, [sp, #0x98]
	lsrs r0, r6, #0x10
	str r0, [sp, #4]
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080e3a90
	movs r0, #0x58
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08145E0E
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r6, r7, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08145DF4
	bl Script_GetValue
	b _08145DF6
_08145DF4:
	movs r0, #0
_08145DF6:
	str r0, [r6]
	bl VM_GetPC
	cmp r0, #0
	beq _08145E06
	bl Script_GetValue
	b _08145E08
_08145E06:
	movs r0, #0
_08145E08:
	ldr r2, _08145E70 @ =0x00000189
	adds r1, r7, r2
	strb r0, [r1]
_08145E0E:
	movs r0, #0x4b
	movs r1, #2
	bl VM_GetKeywordValue
	ldr r3, [sp, #0x12c]
	strh r0, [r3]
	movs r0, #0x48
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08145E32
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r4, [sp, #0x74]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
_08145E32:
	movs r0, #0x4c
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	beq _08145E4A
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r5, [sp, #0x74]
	ldr r0, [r5]
	orrs r0, r1
	str r0, [r5]
_08145E4A:
	ldr r6, [sp, #0x8c]
	lsrs r1, r6, #0x10
	movs r0, #4
	str r0, [sp]
	str r7, [sp, #4]
	ldr r0, [sp, #0x28]
	add r2, sp, #0x1c
	movs r3, #0
	bl FUN_0823b400
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08145E74
	movs r0, #1
	b _08145E76
	.align 2, 0
_08145E70: .4byte 0x00000189
_08145E74:
	movs r0, #0
_08145E76:
	cmp r0, #0
	beq _08145E86
	adds r0, r7, #0
	adds r0, #0x7c
	ldr r2, _08145EB0 @ =FUN_080f48ac
	ldr r1, [sp, #0x28]
	bl FUN_0807f558
_08145E86:
	ldr r3, [sp, #0x134]
	ldrb r0, [r3]
	movs r1, #0
	cmp r0, #0
	bne _08145E92
	ldr r1, [r7, #0x44]
_08145E92:
	ldr r0, [sp, #0x28]
	bl FUN_0823b46c
	ldr r4, [sp, #0xa0]
	ldrb r0, [r4]
	cmp r0, #0x15
	bne _08145EB4
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x3c
	movs r3, #0x3c
	bl FUN_0823b43c
	b _08145EC0
	.align 2, 0
_08145EB0: .4byte FUN_080f48ac
_08145EB4:
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x34]
	movs r2, #0x40
	movs r3, #0x40
	bl FUN_0823b43c
_08145EC0:
	ldr r5, [sp, #0xa0]
	ldrb r1, [r5]
	adds r0, r1, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _08145F0E
	adds r0, r1, #0
	cmp r0, #0xb
	beq _08145F0E
	cmp r0, #0x16
	beq _08145F0E
	cmp r0, #0x14
	beq _08145F0E
	cmp r0, #9
	beq _08145F0E
	cmp r0, #0x19
	beq _08145F0E
	cmp r0, #0x1a
	beq _08145F0E
	cmp r0, #0xd
	beq _08145F0E
	cmp r0, #0x1b
	beq _08145F0E
	cmp r0, #0x1f
	beq _08145F0E
	adds r1, r7, #0
	adds r1, #0x9c
	ldr r6, [sp, #0x118]
	ldrb r2, [r6]
	ldr r0, [sp, #0x11c]
	ldrb r3, [r0]
	ldr r4, [sp, #0x120]
	ldrb r0, [r4]
	str r0, [sp]
	ldr r0, [sp, #0x28]
	bl FUN_0823b490
_08145F0E:
	movs r1, #8
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _08145F1E
	movs r0, #1
	b _08145F20
_08145F1E:
	movs r0, #0
_08145F20:
	cmp r0, #0
	beq _08145F2E
	ldr r6, [sp, #0xb0]
	ldr r0, [r6]
	ldr r1, [sp, #0xac]
	str r0, [r1]
	b _08145F40
_08145F2E:
	ldr r2, [sp, #0xb0]
	ldr r1, [r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	movs r1, #0xa
	bl Div
	ldr r3, [sp, #0xac]
	str r0, [r3]
_08145F40:
	ldrh r0, [r7]
	ldr r4, [sp, #0x38]
	strh r0, [r4]
	ldr r5, [sp, #0x30]
	ldr r6, [sp, #0x3c]
	str r5, [r6]
	ldr r0, [sp, #0x2c]
	cmp r0, #0
	beq _08145F6A
	adds r0, r7, #0
	adds r0, #0xa4
	ldr r0, [r0]
	ldrh r0, [r0, #4]
	lsrs r0, r0, #0xc
	movs r1, #7
	ands r0, r1
	adds r0, #5
	ands r0, r1
	lsls r0, r0, #5
	ldr r1, [sp, #0x28]
	strb r0, [r1, #5]
_08145F6A:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08146038
	ldr r2, [sp, #0x24]
	ldr r3, _08145F88 @ =0x00000664
	adds r4, r2, r3
	bl VM_GetPC
	cmp r0, #0
	beq _08145F8C
	bl Script_GetValue
	b _08145F8E
	.align 2, 0
_08145F88: .4byte 0x00000664
_08145F8C:
	movs r0, #0
_08145F8E:
	str r0, [r4]
	bl VM_GetPC
	cmp r0, #0
	beq _08145FA0
	bl Script_GetValue
	adds r1, r0, #0
	b _08145FA2
_08145FA0:
	movs r1, #0
_08145FA2:
	ldr r4, [sp, #0x24]
	movs r5, #0xcc
	lsls r5, r5, #3
	adds r0, r4, r5
	strb r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08145FBC
	bl Script_GetValue
	adds r1, r0, #0
	b _08145FBE
_08145FBC:
	movs r1, #0
_08145FBE:
	ldr r6, [sp, #0x24]
	ldr r2, _08145FF0 @ =0x0000065D
	adds r0, r6, r2
	strb r1, [r0]
	ldr r2, _08145FF4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08145FF8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _08145FFC @ =0x0203B400
	adds r0, r0, r3
	ldrh r4, [r0]
	movs r0, #0x3f
	ands r4, r0
	bl VM_GetPC
	cmp r0, #0
	beq _08146000
	bl Script_GetValue
	adds r1, r0, r4
	b _08146002
	.align 2, 0
_08145FF0: .4byte 0x0000065D
_08145FF4: .4byte 0x030046B8
_08145FF8: .4byte 0x000003FF
_08145FFC: .4byte 0x0203B400
_08146000:
	adds r1, r4, #0
_08146002:
	ldr r4, [sp, #0x24]
	ldr r5, _0814605C @ =0x0000065E
	adds r0, r4, r5
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _08146028
	bl Script_GetValue
	cmp r0, #0
	beq _08146028
	movs r2, #4
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r1, r4, r6
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_08146028:
	ldr r1, [sp, #0x24]
	ldr r2, _08146060 @ =0x00000664
	adds r0, r1, r2
	ldr r1, [r0]
	adds r3, r1, #0
	muls r3, r1, r3
	adds r1, r3, #0
	str r1, [r0]
_08146038:
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	strb r0, [r7, #5]
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0814604E
	b _08146160
_0814604E:
	bl VM_GetPC
	cmp r0, #0
	beq _08146064
	bl Script_GetValue
	b _08146066
	.align 2, 0
_0814605C: .4byte 0x0000065E
_08146060: .4byte 0x00000664
_08146064:
	movs r0, #0
_08146066:
	strh r0, [r7, #8]
	bl VM_GetPC
	cmp r0, #0
	beq _08146076
	bl Script_GetValue
	b _08146078
_08146076:
	movs r0, #0
_08146078:
	strh r0, [r7, #0xa]
	bl VM_GetPC
	cmp r0, #0
	beq _08146088
	bl Script_GetValue
	b _0814608A
_08146088:
	movs r0, #0
_0814608A:
	strh r0, [r7, #0xc]
	ldr r4, [sp, #0x24]
	movs r5, #0xd7
	lsls r5, r5, #3
	adds r2, r4, r5
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _081460C0
	cmp r1, #0
	blt _081460C0
	ldr r0, _081460C4 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081460C0
	ldr r0, _081460C8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081460CC
_081460C0:
	movs r1, #0
	b _081460DA
	.align 2, 0
_081460C4: .4byte 0x030046A8
_081460C8: .4byte 0x030046AC
_081460CC:
	ldr r0, _081460FC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_081460DA:
	ldr r6, _08146100 @ =0x00000256
	adds r0, r7, r6
	strh r1, [r0]
	ldrh r4, [r0]
	ldr r0, [sp, #0x24]
	movs r1, #0xd7
	lsls r1, r1, #3
	adds r5, r0, r1
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08146104
	adds r0, #4
	b _08146110
	.align 2, 0
_081460FC: .4byte 0x030046A4
_08146100: .4byte 0x00000256
_08146104:
	ldr r0, _08146124 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08146110:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08146128
	cmp r2, #2
	beq _0814612C
	b _08146130
	.align 2, 0
_08146124: .4byte 0x030046A4
_08146128:
	ldrb r0, [r5, #4]
	b _0814612E
_0814612C:
	ldrb r0, [r5]
_0814612E:
	subs r1, r1, r0
_08146130:
	ldr r3, _081461A0 @ =0x00000472
	adds r2, r7, r3
	strh r1, [r2]
	ldrh r1, [r7, #0xa]
	movs r4, #0xdf
	lsls r4, r4, #1
	adds r0, r7, r4
	strh r1, [r0]
	ldr r5, [sp, #0x24]
	ldr r6, _081461A4 @ =0x0000066E
	adds r0, r5, r6
	strh r1, [r0]
	ldrh r0, [r2]
	strh r0, [r7, #0xa]
	ldr r1, _081461A8 @ =0x00000256
	adds r0, r7, r1
	ldrh r1, [r0]
	ldr r3, _081461AC @ =0x0000066C
	adds r0, r5, r3
	strh r1, [r0]
	ldrh r1, [r2]
	ldr r4, _081461B0 @ =0x00000662
	adds r0, r5, r4
	strh r1, [r0]
_08146160:
	movs r4, #0xa6
	lsls r4, r4, #1
	movs r5, #0x99
	lsls r5, r5, #1
	movs r0, #0x43
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x5c]
	strh r0, [r6]
	ldr r0, [sp, #0x50]
	strh r4, [r0]
	ldr r1, [sp, #0x54]
	strh r5, [r1]
	ldrh r0, [r6]
	ldr r2, _081461B4 @ =0x0000014F
	adds r0, r0, r2
	ldr r3, [sp, #0x58]
	strh r0, [r3]
	ldr r4, [sp, #0x50]
	ldrh r1, [r4]
	ldrh r0, [r6]
	adds r1, r1, r0
	ldr r5, [sp, #0x134]
	ldrb r0, [r5]
	cmp r0, #0
	bne _081461B8
	ldr r0, [r7, #0x44]
	adds r0, #0x2c
	bl FUN_0822b20c
	b _081461C4
	.align 2, 0
_081461A0: .4byte 0x00000472
_081461A4: .4byte 0x0000066E
_081461A8: .4byte 0x00000256
_081461AC: .4byte 0x0000066C
_081461B0: .4byte 0x00000662
_081461B4: .4byte 0x0000014F
_081461B8:
	ldr r2, [r7, #0x44]
	ldr r0, _081461FC @ =0x03003584
	lsls r1, r1, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r2, #0x68]
_081461C4:
	ldr r6, [sp, #0x134]
	ldrb r0, [r6]
	cmp r0, #1
	bne _08146214
	ldr r1, [sp, #0xa0]
	ldrb r0, [r1]
	subs r0, #5
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bhi _08146200
	movs r0, #5
	bl FUN_080ecf60
	adds r4, r0, #1
	movs r0, #6
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #7
	bl FUN_080ecf60
	adds r4, r4, r0
	movs r0, #8
	bl FUN_080ecf60
	adds r4, r4, r0
	b _0814620A
	.align 2, 0
_081461FC: .4byte 0x03003584
_08146200:
	ldr r2, [sp, #0xa0]
	ldrb r0, [r2]
	bl FUN_080ecf60
	adds r4, r0, #1
_0814620A:
	ldr r0, [r7, #0x44]
	adds r0, #0x20
	adds r1, r4, #0
	adds r1, #0xdc
	strh r1, [r0, #0x3a]
_08146214:
	adds r0, r7, #0
	bl FUN_08144668
	ldr r3, [sp, #0x24]
	ldr r5, _081463A8 @ =0x00000674
	adds r4, r3, r5
	movs r6, #0xd3
	lsls r6, r6, #3
	adds r5, r3, r6
	ldr r0, _081463AC @ =FUN_08145438
	str r0, [sp, #0x1a0]
	ldr r1, _081463B0 @ =FUN_081446fc
	mov r8, r1
	ldr r2, _081463B4 @ =FUN_0814312c
	mov sb, r2
	ldr r3, _081463B8 @ =FUN_08142fd8
	mov sl, r3
	ldr r6, _081463BC @ =FUN_08143004
	mov ip, r6
	movs r2, #0
	ldr r3, _081463C0 @ =FUN_080f62b0
	ldr r0, _081463C4 @ =FUN_080f62ac
	str r0, [sp, #0x198]
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x70]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	ldr r0, [sp, #0x68]
	str r4, [r0]
	ldr r1, [sp, #0x6c]
	str r5, [r1]
	ldr r4, [sp, #0x1a0]
	ldr r5, [sp, #0xe8]
	str r4, [r5]
	mov r6, r8
	ldr r0, [sp, #0xf0]
	str r6, [r0]
	mov r1, sb
	ldr r4, [sp, #0xf8]
	str r1, [r4]
	mov r5, sl
	ldr r6, [sp, #0x108]
	str r5, [r6]
	mov r0, ip
	ldr r1, [sp, #0x10c]
	str r0, [r1]
	ldr r4, [sp, #0x13c]
	str r2, [r4]
	ldr r5, [sp, #0x140]
	str r3, [r5]
	ldr r6, _081463C8 @ =FUN_08143310
	ldr r0, [sp, #0x148]
	str r6, [r0]
	ldr r1, _081463CC @ =FUN_081434e0
	ldr r3, [sp, #0x14c]
	str r1, [r3]
	ldr r0, _081463D0 @ =FUN_080f44f4
	ldr r4, [sp, #0x150]
	str r0, [r4]
	ldr r0, _081463D4 @ =FUN_080f410c
	ldr r5, [sp, #0x158]
	str r0, [r5]
	ldr r6, [sp, #0x144]
	str r2, [r6]
	ldr r0, [sp, #0xec]
	str r2, [r0]
	ldr r1, [sp, #0x198]
	ldr r3, [sp, #0x17c]
	str r1, [r3]
	ldr r0, _081463D8 @ =FUN_080f0430
	ldr r4, [sp, #0x180]
	str r0, [r4]
	movs r6, #1
	ldr r5, [sp, #0xe4]
	strb r6, [r5]
	ldr r0, _081463DC @ =0x085AD470
	ldr r1, [sp, #0x184]
	str r0, [r1]
	ldr r0, _081463E0 @ =FUN_080e73c8
	ldr r3, [sp, #0x16c]
	str r0, [r3]
	ldr r4, [sp, #0x160]
	str r2, [r4]
	ldr r5, [sp, #0x170]
	str r2, [r5]
	ldr r6, [sp, #0x174]
	str r2, [r6]
	ldr r0, [sp, #0x178]
	str r2, [r0]
	ldr r1, [sp, #0x188]
	str r2, [r1]
	ldr r0, _081463E4 @ =FUN_080f0320
	ldr r3, [sp, #0x18c]
	str r0, [r3]
	ldr r0, _081463E8 @ =FUN_080eff14
	ldr r4, [sp, #0x138]
	str r0, [r4]
	ldr r0, _081463EC @ =FUN_080e72b0
	ldr r5, [sp, #0x164]
	str r0, [r5]
	ldr r6, [sp, #0x15c]
	str r2, [r6]
	ldr r0, _081463F0 @ =FUN_080f47c8
	ldr r1, [sp, #0x168]
	str r0, [r1]
	ldr r0, _081463F4 @ =FUN_080f54e4
	ldr r3, [sp, #0x154]
	str r0, [r3]
	ldr r4, [sp, #0x110]
	str r2, [r4]
	ldr r0, _081463F8 @ =FUN_080f6e64
	ldr r5, [sp, #0x190]
	str r0, [r5]
	ldr r0, _081463FC @ =FUN_080f64f0
	ldr r6, [sp, #0xf4]
	str r0, [r6]
	ldr r0, _08146400 @ =FUN_080f84d4
	ldr r1, [sp, #0x194]
	str r0, [r1]
	ldr r0, _08146404 @ =FUN_080f624c
	ldr r3, [sp, #0x130]
	str r0, [r3]
	ldr r0, _08146408 @ =FUN_080f56ec
	ldr r4, [sp, #0xfc]
	str r0, [r4]
	ldr r0, _0814640C @ =FUN_080f5b34
	ldr r5, [sp, #0x100]
	str r0, [r5]
	ldr r0, _08146410 @ =FUN_080f5fac
	ldr r6, [sp, #0x104]
	str r0, [r6]
	ldr r0, [sp, #0x128]
	str r2, [r0]
	movs r0, #0x28
	ldr r1, [sp, #0xa8]
	strb r0, [r1]
	ldr r3, _08146414 @ =0x0000060C
	adds r1, r7, r3
	ldr r0, _08146418 @ =0x085AD858
	str r0, [r1]
	movs r4, #0xbf
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _0814641C @ =FUN_08144218
	str r0, [r1]
	ldr r5, _08146420 @ =0x000005FC
	adds r0, r7, r5
	str r2, [r0]
	ldr r6, _08146424 @ =0x000005AC
	adds r1, r7, r6
	ldr r0, _08146428 @ =FUN_08144bfc
	str r0, [r1]
	movs r1, #0xb6
	lsls r1, r1, #3
	adds r0, r7, r1
	str r2, [r0]
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r7, r2
	ldr r0, _0814642C @ =FUN_08144b90
	str r0, [r1]
	subs r3, #0x80
	adds r1, r7, r3
	ldr r0, _08146430 @ =FUN_080f8400
	str r0, [r1]
	ldr r1, _08146434 @ =0x02100408
	ldr r4, [sp, #0x74]
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r0, #0x60
	ldr r5, [sp, #0x4c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	adds r0, r7, #0
	bl Enemy_Init_080e5dd4
	movs r0, #0x49
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r6, [sp, #0x80]
	strh r0, [r6]
	movs r0, #0x47
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08146442
	movs r0, #0xce
	lsls r0, r0, #1
	adds r5, r7, r0
	movs r4, #4
_0814639A:
	bl VM_GetPC
	cmp r0, #0
	beq _08146438
	bl Script_GetValue
	b _0814643A
	.align 2, 0
_081463A8: .4byte 0x00000674
_081463AC: .4byte FUN_08145438
_081463B0: .4byte FUN_081446fc
_081463B4: .4byte FUN_0814312c
_081463B8: .4byte FUN_08142fd8
_081463BC: .4byte FUN_08143004
_081463C0: .4byte FUN_080f62b0
_081463C4: .4byte FUN_080f62ac
_081463C8: .4byte FUN_08143310
_081463CC: .4byte FUN_081434e0
_081463D0: .4byte FUN_080f44f4
_081463D4: .4byte FUN_080f410c
_081463D8: .4byte FUN_080f0430
_081463DC: .4byte 0x085AD470
_081463E0: .4byte FUN_080e73c8
_081463E4: .4byte FUN_080f0320
_081463E8: .4byte FUN_080eff14
_081463EC: .4byte FUN_080e72b0
_081463F0: .4byte FUN_080f47c8
_081463F4: .4byte FUN_080f54e4
_081463F8: .4byte FUN_080f6e64
_081463FC: .4byte FUN_080f64f0
_08146400: .4byte FUN_080f84d4
_08146404: .4byte FUN_080f624c
_08146408: .4byte FUN_080f56ec
_0814640C: .4byte FUN_080f5b34
_08146410: .4byte FUN_080f5fac
_08146414: .4byte 0x0000060C
_08146418: .4byte 0x085AD858
_0814641C: .4byte FUN_08144218
_08146420: .4byte 0x000005FC
_08146424: .4byte 0x000005AC
_08146428: .4byte FUN_08144bfc
_0814642C: .4byte FUN_08144b90
_08146430: .4byte FUN_080f8400
_08146434: .4byte 0x02100408
_08146438:
	movs r0, #0
_0814643A:
	stm r5!, {r0}
	subs r4, #1
	cmp r4, #0
	bge _0814639A
_08146442:
	movs r0, #0x44
	movs r1, #0
	bl VM_GetKeywordValue
	ldr r1, [sp, #0x84]
	strh r0, [r1]
	movs r0, #0x75
	movs r1, #0
	bl VM_GetKeywordValue
	adds r2, r0, #0
	movs r0, #0x21
	ldr r3, [sp, #0x64]
	strh r0, [r3]
	cmp r2, #0
	beq _0814647A
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r4, [sp, #0x70]
	ldr r1, [r4]
	orrs r1, r0
	str r1, [r4]
	cmp r2, #2
	bne _0814647A
	movs r0, #0x80
	lsls r0, r0, #0xc
	orrs r1, r0
	str r1, [r4]
_0814647A:
	movs r2, #0
	movs r1, #4
	ldr r5, [sp, #0x4c]
	ldrh r0, [r5]
	ands r0, r1
	cmp r0, #0
	beq _0814648C
	movs r0, #1
	b _0814648E
_0814648C:
	movs r0, #0
_0814648E:
	cmp r0, #0
	beq _081464A0
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r6, [sp, #0x74]
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	movs r2, #1
_081464A0:
	cmp r2, #1
	beq _081464E0
	movs r1, #0
	ldr r0, [sp, #0x40]
	strb r1, [r0]
	ldr r2, [sp, #0x44]
	strb r1, [r2]
	ldr r3, [sp, #0x48]
	strb r1, [r3]
	ldr r4, _081464F0 @ =0x00000484
	adds r0, r7, r4
	str r1, [r0]
	ldr r5, _081464F4 @ =0x0000046C
	adds r0, r7, r5
	movs r2, #1
	strb r2, [r0]
	ldr r6, [sp, #0x10c]
	ldr r3, [r6]
	subs r4, #0x17
	adds r0, r7, r4
	strb r2, [r0]
	subs r5, #1
	adds r0, r7, r5
	strb r1, [r0]
	ldr r6, [sp, #0xb4]
	strb r1, [r6]
	ldr r0, [sp, #0xe0]
	str r3, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
_081464E0:
	movs r1, #2
	ldr r3, [sp, #0x4c]
	ldrh r0, [r3]
	ands r0, r1
	cmp r0, #0
	beq _081464F8
	movs r0, #1
	b _081464FA
	.align 2, 0
_081464F0: .4byte 0x00000484
_081464F4: .4byte 0x0000046C
_081464F8:
	movs r0, #0
_081464FA:
	cmp r0, #0
	beq _08146514
	ldr r0, _08146510 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x92
	lsls r4, r4, #2
	adds r0, r0, r4
	ldr r0, [r0]
	ldr r5, [sp, #0x60]
	strh r0, [r5]
	b _0814651E
	.align 2, 0
_08146510: .4byte 0x030046A0
_08146514:
	ldr r0, [sp, #0x30]
	bl FUN_08241574
	ldr r6, [sp, #0x60]
	strh r0, [r6]
_0814651E:
	movs r1, #0x40
	ldr r2, [sp, #0x4c]
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0814652E
	movs r0, #1
	b _08146530
_0814652E:
	movs r0, #0
_08146530:
	cmp r0, #0
	beq _08146540
	adds r0, r7, #0
	adds r0, #0xd8
	ldr r1, _08146564 @ =0xFFFFFEFF
	ldrh r2, [r0, #6]
	ands r1, r2
	strh r1, [r0, #6]
_08146540:
	movs r0, #0x53
	movs r1, #0
	bl VM_GetKeywordValue
	cmp r0, #0
	bne _08146572
	ldr r0, _08146568 @ =0x030046A0
	ldr r0, [r0]
	movs r3, #0x92
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	ldr r4, [sp, #0x60]
	ldrh r4, [r4]
	cmp r0, r4
	bne _0814656C
	movs r0, #1
	b _0814656E
	.align 2, 0
_08146564: .4byte 0xFFFFFEFF
_08146568: .4byte 0x030046A0
_0814656C:
	movs r0, #0
_0814656E:
	cmp r0, #0
	bne _0814657A
_08146572:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080f07d0
_0814657A:
	adds r0, r7, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [sp, #0x134]
	ldrb r0, [r5]
	cmp r0, #0
	bne _08146662
	ldr r5, [r7, #0x44]
	adds r4, r5, #0
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r5, #0x48]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081465BC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081465C4
_081465BC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081465C4:
	str r0, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _081465E8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _081465F0
_081465E8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_081465F0:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r6, _08146628 @ =0x0000FFFF
	adds r2, r6, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _0814666C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0814662C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08146620
	ldrb r0, [r4, #5]
_08146620:
	subs r0, #1
	strh r0, [r4, #8]
	b _0814663C
	.align 2, 0
_08146628: .4byte 0x0000FFFF
_0814662C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0814663C
	strh r1, [r4, #8]
_0814663C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r1, [r6]
	movs r0, #0xf
	ands r0, r1
	strb r0, [r4, #6]
	ldrb r1, [r4, #6]
	ldrh r0, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814666C
	movs r0, #1
	strb r0, [r4, #7]
	b _0814666C
_08146662:
	ldr r1, [r7, #0x44]
	adds r0, r1, #0
	adds r0, #0x20
	bl FUN_082372cc
_0814666C:
	movs r0, #0
	ldr r3, [sp, #0x90]
	str r0, [r3]
	ldr r0, _08146684 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _08146688
	movs r0, #1
	b _0814668A
	.align 2, 0
_08146684: .4byte 0x030047A4
_08146688:
	movs r0, #0
_0814668A:
	cmp r0, #0
	bne _081466CA
	ldr r4, [sp, #0xa0]
	ldrb r1, [r4]
	subs r0, r1, #4
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _081466B2
	adds r0, r1, #0
	cmp r0, #7
	beq _081466B2
	cmp r0, #6
	beq _081466B2
	cmp r0, #0x15
	beq _081466B2
	cmp r0, #0x14
	beq _081466B2
	cmp r0, #0x17
	bne _081466CA
_081466B2:
	adds r0, r7, #0
	adds r0, #0x48
	ldrh r1, [r7]
	movs r2, #3
	bl FUN_080223f4
	movs r0, #0x80
	lsls r0, r0, #1
	ldr r5, [sp, #0x4c]
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
_081466CA:
	adds r0, r7, #0
	bl Enemy_Init_080f3680
	adds r0, r7, #0
	bl FUN_0814414c
	adds r0, r7, #0
	bl FUN_08145424
	movs r6, #0xde
	lsls r6, r6, #1
	adds r1, r7, r6
	movs r0, #2
	strh r0, [r1]
	ldr r1, [sp, #0x4c]
	ldrh r0, [r1]
	ldr r2, [sp, #0xdc]
	strh r0, [r2]
	ldr r3, [sp, #0x88]
	ldrh r0, [r3]
	ldr r4, [sp, #0xd8]
	strh r0, [r4]
	ldr r5, [sp, #0x70]
	ldr r0, [r5]
	ldr r6, [sp, #0xb8]
	str r0, [r6]
	ldr r1, [sp, #0x74]
	ldr r0, [r1]
	ldr r2, [sp, #0xbc]
	str r0, [r2]
	ldrb r0, [r7, #5]
	ldr r3, [sp, #0xc0]
	strb r0, [r3]
	ldr r4, [sp, #0x40]
	ldrb r0, [r4]
	ldr r5, [sp, #0xc4]
	strb r0, [r5]
	ldr r6, [sp, #0x44]
	ldrb r0, [r6]
	ldr r1, [sp, #0xc8]
	strb r0, [r1]
	ldr r2, [sp, #0x48]
	ldrb r0, [r2]
	ldr r3, [sp, #0xcc]
	strb r0, [r3]
	ldr r4, [sp, #0xe0]
	ldr r0, [r4]
	ldr r5, [sp, #0xd0]
	str r0, [r5]
	ldr r6, [sp, #0xb4]
	ldrb r0, [r6]
	ldr r1, [sp, #0xd4]
	strb r0, [r1]
	ldr r2, _08146760 @ =0x0000057C
	adds r1, r7, r2
	ldr r0, _08146764 @ =FUN_080f09e0
	str r0, [r1]
	ldr r3, _08146768 @ =0x0000061C
	adds r1, r7, r3
	ldr r0, _0814676C @ =FUN_08145474
	str r0, [r1]
	movs r4, #0xc4
	lsls r4, r4, #3
	adds r1, r7, r4
	ldr r0, _08146770 @ =EnemyCrow_Destroy
	str r0, [r1]
	adds r0, r7, #0
	bl Enemy_Init_080ec640
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08146774
	movs r0, #0
	b _08146778
	.align 2, 0
_08146760: .4byte 0x0000057C
_08146764: .4byte FUN_080f09e0
_08146768: .4byte 0x0000061C
_0814676C: .4byte FUN_08145474
_08146770: .4byte EnemyCrow_Destroy
_08146774:
	movs r0, #1
	rsbs r0, r0, #0
_08146778:
	add sp, #0x1a4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start EnemyCrow_Create
EnemyCrow_Create: @ 0x08146788
	push {r4, r5, lr}
	movs r5, #0xd8
	lsls r5, r5, #3
	adds r0, r5, #0
	bl Malloc
	adds r4, r0, #0
	cmp r4, #0
	beq _081467B6
	adds r1, r5, #0
	bl ClearMemory
	adds r0, r4, #0
	bl EnemyCrow_Init
	cmp r0, #0
	bge _081467B6
	adds r0, r4, #0
	bl EnemyCrow_Destroy
	adds r0, r4, #0
	bl Free
_081467B6:
	pop {r4, r5}
	pop {r0}
	bx r0
