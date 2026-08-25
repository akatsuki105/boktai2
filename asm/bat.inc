	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0813e6c0
FUN_0813e6c0: @ 0x0813E6C0
	push {r4, r5, r6, lr}
	sub sp, #0x14
	adds r6, r0, #0
	adds r4, r1, #0
	ldrh r0, [r4, #0xa]
	cmp r0, #1
	beq _0813E6D0
	b _0813E928
_0813E6D0:
	adds r5, r2, #0
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813E6E0
	b _0813E928
_0813E6E0:
	adds r0, r5, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813E70E
	ldrh r1, [r4, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _0813E70E
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r4, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _0813E760 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0813E70E:
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_08236524
	movs r2, #0x90
	lsls r2, r2, #3
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #1
	beq _0813E72E
	subs r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _0813E72E
	b _0813E87A
_0813E72E:
	ldrh r0, [r4, #0x3e]
	cmp r0, #0
	bne _0813E736
	b _0813E87A
_0813E736:
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r6, #0
	ldrsh r0, [r2, r6]
	ldrh r3, [r4, #0x3e]
	adds r0, r0, r3
	movs r1, #0x95
	lsls r1, r1, #2
	adds r6, r5, r1
	ldrh r1, [r6]
	cmp r0, r1
	ble _0813E764
	ldrh r0, [r2]
	subs r0, r1, r0
	movs r3, #0x8b
	lsls r3, r3, #1
	adds r1, r5, r3
	strh r0, [r1]
	ldrh r0, [r6]
	b _0813E772
	.align 2, 0
_0813E760: .4byte 0xFEFFFFFF
_0813E764:
	movs r6, #0x8b
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r3, [r0]
	ldrh r0, [r4, #0x3e]
	ldrh r1, [r2]
	adds r0, r0, r1
_0813E772:
	strh r0, [r2]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ldr r3, _0813E79C @ =0x0000048A
	adds r1, r5, r3
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _0813E87A
	ldr r0, _0813E7A0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0813E7A4
	movs r0, #1
	b _0813E7A6
	.align 2, 0
_0813E79C: .4byte 0x0000048A
_0813E7A0: .4byte 0x030047A4
_0813E7A4:
	movs r0, #0
_0813E7A6:
	cmp r0, #0
	beq _0813E814
	movs r4, #0x94
	lsls r4, r4, #3
	adds r1, r5, r4
	ldr r2, [r1]
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	bne _0813E814
	cmp r2, #0
	beq _0813E814
	ldr r0, _0813E7CC @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0813E7D0
	movs r0, #1
	rsbs r0, r0, #0
	b _0813E7D4
	.align 2, 0
_0813E7CC: .4byte 0x03002C68
_0813E7D0:
	movs r6, #0x18
	ldrsh r0, [r0, r6]
_0813E7D4:
	cmp r0, #1
	beq _0813E7F6
	cmp r0, #1
	bgt _0813E7E2
	cmp r0, #0
	beq _0813E7EC
	b _0813E814
_0813E7E2:
	cmp r0, #2
	beq _0813E800
	cmp r0, #3
	beq _0813E80A
	b _0813E814
_0813E7EC:
	ldr r0, [r1]
	cmp r0, #1
	beq _0813E814
	movs r0, #0
	b _0813E816
_0813E7F6:
	ldr r0, [r1]
	cmp r0, #2
	beq _0813E814
	movs r0, #0
	b _0813E816
_0813E800:
	ldr r0, [r1]
	cmp r0, #4
	beq _0813E814
	movs r0, #0
	b _0813E816
_0813E80A:
	ldr r0, [r1]
	cmp r0, #8
	beq _0813E814
	movs r0, #0
	b _0813E816
_0813E814:
	movs r0, #1
_0813E816:
	cmp r0, #0
	beq _0813E87A
	ldrh r0, [r5]
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0x95
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r2, [r2]
	ldr r6, _0813E8B4 @ =0x0000025A
	adds r3, r5, r6
	ldrh r3, [r3]
	movs r4, #0
	str r4, [sp]
	bl FUN_0809c344
	add r6, sp, #0xc
	str r4, [sp, #8]
	add r0, sp, #8
	adds r1, r6, #0
	ldr r2, _0813E8B8 @ =0x05000002
	bl CpuSet
	ldr r0, _0813E8BC @ =0x0000048A
	adds r2, r5, r0
	ldrh r0, [r2]
	cmp r0, #0
	bne _0813E866
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	bne _0813E87A
_0813E866:
	adds r0, r5, #0
	adds r0, #0xd8
	ldrh r1, [r2]
	adds r3, r5, #0
	adds r3, #8
	str r6, [sp]
	movs r2, #1
	str r2, [sp, #4]
	bl FUN_0805fe7c
_0813E87A:
	movs r3, #0x97
	lsls r3, r3, #1
	adds r2, r5, r3
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	movs r4, #0xe6
	lsls r4, r4, #1
	adds r3, r5, r4
	ldr r1, [r3]
	movs r6, #0xcb
	lsls r6, r6, #3
	adds r1, r1, r6
	movs r2, #9
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r0, [r3]
	movs r1, #4
	adds r0, r0, r6
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813E8C0
	movs r0, #1
	b _0813E8C2
	.align 2, 0
_0813E8B4: .4byte 0x0000025A
_0813E8B8: .4byte 0x05000002
_0813E8BC: .4byte 0x0000048A
_0813E8C0:
	movs r0, #0
_0813E8C2:
	adds r4, r0, #0
	cmp r4, #0
	bne _0813E928
	ldr r2, _0813E930 @ =FUN_080e48d0
	movs r1, #0x10
	ldr r3, _0813E934 @ =0x0000046D
	adds r0, r5, r3
	movs r3, #1
	strb r3, [r0]
	ldr r6, _0813E938 @ =0x0000046B
	adds r0, r5, r6
	strb r4, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r1, #0
	strh r4, [r0]
	movs r2, #2
	subs r6, #0xeb
	adds r0, r5, r6
	strb r1, [r0]
	ldr r1, _0813E93C @ =0x00000469
	adds r0, r5, r1
	strb r2, [r0]
	ldr r2, _0813E940 @ =0x0000046A
	adds r0, r5, r2
	strb r3, [r0]
	adds r6, #0x1c
	adds r0, r5, r6
	str r4, [r0]
	adds r1, #3
	adds r0, r5, r1
	strb r3, [r0]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	movs r2, #4
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r1, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
_0813E928:
	add sp, #0x14
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813E930: .4byte FUN_080e48d0
_0813E934: .4byte 0x0000046D
_0813E938: .4byte 0x0000046B
_0813E93C: .4byte 0x00000469
_0813E940: .4byte 0x0000046A

	thumb_func_start FUN_0813e944
FUN_0813e944: @ 0x0813E944
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
	beq _0813E964
	b _0813F04A
_0813E964:
	movs r1, #0x80
	lsls r1, r1, #4
	ldrh r0, [r7, #6]
	ands r0, r1
	cmp r0, #0
	beq _0813E972
	b _0813F04A
_0813E972:
	adds r0, r6, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	movs r0, #0x40
	add r0, r8
	mov sb, r0
	cmp r2, #0
	beq _0813E988
	b _0813F00A
_0813E988:
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _0813E9B4
	ldr r3, _0813E9B0 @ =0x0000048C
	adds r0, r6, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813E9A0
	b _0813F00A
_0813E9A0:
	movs r1, #0
	mov r4, r8
	strh r2, [r4, #0x3e]
	mov r0, r8
	adds r0, #0x43
	strb r1, [r0]
	b _0813F00A
	.align 2, 0
_0813E9B0: .4byte 0x0000048C
_0813E9B4:
	adds r0, r6, #0
	adds r0, #0xd8
	movs r5, #4
	ldrh r0, [r0, #6]
	ands r0, r5
	cmp r0, #0
	beq _0813E9C4
	b _0813F00A
_0813E9C4:
	movs r4, #1
	ldrh r3, [r7, #6]
	adds r0, r3, #0
	ands r0, r4
	cmp r0, #0
	beq _0813E9D2
	b _0813ECDC
_0813E9D2:
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r7, #0x34]
	ands r0, r1
	mov ip, r1
	cmp r0, #0
	bne _0813E9E2
	b _0813F00A
_0813E9E2:
	ldr r2, _0813EA74 @ =0x0000A007
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	ands r0, r2
	mov sl, r1
	cmp r0, #0
	beq _0813E9F6
	b _0813F00A
_0813E9F6:
	movs r2, #0x91
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _0813EA04
	b _0813F00A
_0813EA04:
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
	bne _0813EA1C
	b _0813EB64
_0813EA1C:
	movs r1, #0x80
	lsls r1, r1, #1
	mov r2, r8
	ldrh r0, [r2, #6]
	ands r0, r1
	cmp r0, #0
	beq _0813EA84
	ands r3, r1
	cmp r3, #0
	beq _0813EA84
	mov r0, r8
	adds r0, #0x42
	ldrb r1, [r0]
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813EA44
	rsbs r1, r1, #0
_0813EA44:
	cmp r1, #0x20
	bgt _0813EA84
	ldrh r0, [r7, #0x3c]
	ldr r3, _0813EA78 @ =0x000004BE
	adds r1, r6, r3
	strh r0, [r1]
	ldr r2, _0813EA7C @ =0x0000048C
	adds r0, r6, r2
	strb r4, [r0]
	ldrh r0, [r1]
	movs r1, #3
	bl Div
	ldr r3, _0813EA80 @ =0x0000044E
	adds r1, r6, r3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #6
	mov r4, sl
	ldrh r1, [r4]
	orrs r0, r1
	strh r0, [r4]
	b _0813F00A
	.align 2, 0
_0813EA74: .4byte 0x0000A007
_0813EA78: .4byte 0x000004BE
_0813EA7C: .4byte 0x0000048C
_0813EA80: .4byte 0x0000044E
_0813EA84:
	movs r1, #0
	mov r0, r8
	strh r1, [r0, #0x3e]
	ldr r2, _0813EAAC @ =0x0000048A
	adds r0, r6, r2
	strh r1, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0813EAB4
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EAB0 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813EB22
	.align 2, 0
_0813EAAC: .4byte 0x0000048A
_0813EAB0: .4byte 0x03002BE0
_0813EAB4:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813EAD0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EACC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813EB22
	.align 2, 0
_0813EACC: .4byte 0x03002BE0
_0813EAD0:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0813EAEC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813EAE8 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813EB22
	.align 2, 0
_0813EAE8: .4byte 0x03002BE0
_0813EAEC:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813EB08
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EB04 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813EB22
	.align 2, 0
_0813EB04: .4byte 0x03002BE0
_0813EB08:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813EB1A
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0813EB22
_0813EB1A:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813EB24
_0813EB22:
	movs r3, #1
_0813EB24:
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
	bne _0813EB44
	b _0813EC98
_0813EB44:
	movs r1, #2
	ldr r3, _0813EB58 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813EB5C
	movs r0, #1
	b _0813EB5E
	.align 2, 0
_0813EB58: .4byte 0x00000474
_0813EB5C:
	movs r0, #0
_0813EB5E:
	cmp r0, #0
	bne _0813EC3E
	b _0813EC54
_0813EB64:
	mov r3, r8
	strh r2, [r3, #0x3e]
	ldr r1, _0813EB8C @ =0x0000048A
	adds r0, r6, r1
	strh r2, [r0]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	adds r0, r2, #0
	ands r0, r4
	cmp r0, #0
	beq _0813EB94
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EB90 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813EC02
	.align 2, 0
_0813EB8C: .4byte 0x0000048A
_0813EB90: .4byte 0x03002BE0
_0813EB94:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813EBB0
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EBAC @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813EC02
	.align 2, 0
_0813EBAC: .4byte 0x03002BE0
_0813EBB0:
	adds r0, r2, #0
	ands r0, r5
	cmp r0, #0
	beq _0813EBCC
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813EBC8 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813EC02
	.align 2, 0
_0813EBC8: .4byte 0x03002BE0
_0813EBCC:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813EBE8
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EBE4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813EC02
	.align 2, 0
_0813EBE4: .4byte 0x03002BE0
_0813EBE8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813EBFA
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	str r3, [r0]
	b _0813EC02
_0813EBFA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813EC04
_0813EC02:
	movs r3, #1
_0813EC04:
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
	beq _0813EC98
	movs r1, #2
	ldr r3, _0813EC34 @ =0x00000474
	adds r0, r6, r3
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813EC38
	movs r0, #1
	b _0813EC3A
	.align 2, 0
_0813EC34: .4byte 0x00000474
_0813EC38:
	movs r0, #0
_0813EC3A:
	cmp r0, #0
	beq _0813EC54
_0813EC3E:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EC50 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0813EC60
	.align 2, 0
_0813EC50: .4byte 0x03002BE0
_0813EC54:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _0813EC98
_0813EC60:
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
_0813EC98:
	movs r1, #0x80
	mov r4, sl
	ldrh r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _0813ECC4
	ldr r0, _0813ECD4 @ =0x0000024E
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
	bls _0813ECC4
	strh r1, [r2]
_0813ECC4:
	ldr r0, _0813ECD8 @ =0x0000048C
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x40
	add r1, r8
	mov sb, r1
	b _0813F00A
	.align 2, 0
_0813ECD4: .4byte 0x0000024E
_0813ECD8: .4byte 0x0000048C
_0813ECDC:
	ldr r0, _0813ECF0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0813ECF4
	movs r0, #1
	b _0813ECF6
	.align 2, 0
_0813ECF0: .4byte 0x030047A4
_0813ECF4:
	movs r0, #0
_0813ECF6:
	cmp r0, #0
	beq _0813ED04
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236640
	b _0813ED0C
_0813ED04:
	adds r0, r7, #0
	mov r1, r8
	bl FUN_08236524
_0813ED0C:
	adds r0, r7, #0
	adds r0, #0x44
	ldrh r1, [r0]
	mov r0, r8
	adds r0, #0x44
	strh r1, [r0]
	subs r0, #1
	ldrb r0, [r0]
	ldr r2, _0813ED44 @ =0x0000048C
	adds r1, r6, r2
	strb r0, [r1]
	ldr r3, _0813ED48 @ =0x000001DF
	adds r0, r6, r3
	ldrb r2, [r0]
	adds r0, r2, #0
	subs r0, #0x12
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r1, [sp, #8]
	cmp r0, #2
	bls _0813ED3A
	cmp r2, #0x17
	bne _0813ED4C
_0813ED3A:
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	b _0813ED6C
	.align 2, 0
_0813ED44: .4byte 0x0000048C
_0813ED48: .4byte 0x000001DF
_0813ED4C:
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r7, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _0813ED3A
	adds r0, r7, #0
	adds r0, #0x40
	ldrh r1, [r0]
	ldr r4, _0813ED9C @ =0x00000187
	adds r0, r6, r4
	ldrb r0, [r0]
	subs r1, r1, r0
	cmp r1, #0
	bge _0813ED6C
	movs r1, #0
_0813ED6C:
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
	beq _0813EDAA
	mov r1, r8
	ldrh r0, [r1, #0x3e]
	lsls r0, r0, #1
	strh r0, [r1, #0x3e]
	mov r2, sb
	ldrh r0, [r2]
	cmp r0, #0
	blt _0813EDA0
	asrs r0, r0, #1
	b _0813EDA6
	.align 2, 0
_0813ED9C: .4byte 0x00000187
_0813EDA0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_0813EDA6:
	mov r3, sb
	strh r0, [r3]
_0813EDAA:
	ldrh r1, [r7, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0813EDC8
	adds r0, r7, #0
	adds r0, #0x42
	ldrb r0, [r0]
	ldr r4, _0813EDC4 @ =0x000001DD
	adds r1, r6, r4
	b _0813EE3C
	.align 2, 0
_0813EDC4: .4byte 0x000001DD
_0813EDC8:
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
	bne _0813EE28
	lsls r0, r1, #0x10
	cmp r0, #0
	bne _0813EE28
	ldr r2, _0813EE18 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813EE1C @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0813EE20 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	ldr r4, _0813EE24 @ =0x000001DD
	adds r1, r6, r4
	b _0813EE3C
	.align 2, 0
_0813EE18: .4byte 0x030046B8
_0813EE1C: .4byte 0x000003FF
_0813EE20: .4byte 0x0203B400
_0813EE24: .4byte 0x000001DD
_0813EE28:
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r1, sp
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl FUN_0823785c
	ldr r3, _0813EE5C @ =0x000001DD
	adds r1, r6, r3
_0813EE3C:
	strb r0, [r1]
	movs r3, #0
	ldrh r2, [r7, #0xa]
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _0813EE64
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EE60 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	b _0813EED2
	.align 2, 0
_0813EE5C: .4byte 0x000001DD
_0813EE60: .4byte 0x03002BE0
_0813EE64:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _0813EE80
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _0813EE7C @ =0x03002BE0
	ldr r0, [r0, #4]
	adds r0, #0x24
	str r0, [r1]
	b _0813EED2
	.align 2, 0
_0813EE7C: .4byte 0x03002BE0
_0813EE80:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _0813EE9C
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EE98 @ =0x03002BE0
	ldr r0, [r0, #8]
	adds r0, #0x24
	str r0, [r1]
	b _0813EED2
	.align 2, 0
_0813EE98: .4byte 0x03002BE0
_0813EE9C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _0813EEB8
	movs r4, #0xec
	lsls r4, r4, #1
	adds r1, r6, r4
	ldr r0, _0813EEB4 @ =0x03002BE0
	ldr r0, [r0, #0xc]
	adds r0, #0x24
	str r0, [r1]
	b _0813EED2
	.align 2, 0
_0813EEB4: .4byte 0x03002BE0
_0813EEB8:
	movs r0, #0x10
	ands r0, r2
	cmp r0, #0
	beq _0813EECA
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	str r3, [r0]
	b _0813EED2
_0813EECA:
	movs r0, #0x20
	ands r0, r2
	cmp r0, #0
	beq _0813EED4
_0813EED2:
	movs r3, #1
_0813EED4:
	movs r4, #0x94
	lsls r4, r4, #3
	adds r0, r6, r4
	str r2, [r0]
	ldr r1, [r7, #0x34]
	ldr r2, [r7, #0x38]
	subs r4, #8
	adds r0, r6, r4
	str r1, [r0]
	ldr r1, _0813EF04 @ =0x0000049C
	adds r0, r6, r1
	str r2, [r0]
	cmp r3, #0
	beq _0813EF6C
	movs r1, #2
	ldr r2, _0813EF08 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813EF0C
	movs r0, #1
	b _0813EF0E
	.align 2, 0
_0813EF04: .4byte 0x0000049C
_0813EF08: .4byte 0x00000474
_0813EF0C:
	movs r0, #0
_0813EF0E:
	cmp r0, #0
	beq _0813EF28
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, _0813EF24 @ =0x03002BE0
	ldr r0, [r0]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _0813EF34
	.align 2, 0
_0813EF24: .4byte 0x03002BE0
_0813EF28:
	movs r4, #0xec
	lsls r4, r4, #1
	adds r0, r6, r4
	ldr r1, [r0]
	cmp r1, #0
	beq _0813EF6C
_0813EF34:
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
_0813EF6C:
	ldr r4, [sp, #8]
	ldrb r0, [r4]
	cmp r0, #0
	beq _0813EFA0
	movs r1, #0x80
	mov r2, sl
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _0813EFA0
	ldr r3, _0813EFB8 @ =0x0000024E
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
	bls _0813EFA0
	strh r1, [r2]
_0813EFA0:
	movs r1, #0x80
	lsls r1, r1, #3
	ldr r0, _0813EFBC @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _0813EFC0 @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0813EFC4
	movs r0, #1
	b _0813EFC6
	.align 2, 0
_0813EFB8: .4byte 0x0000024E
_0813EFBC: .4byte 0x030046A0
_0813EFC0: .4byte 0x00000934
_0813EFC4:
	movs r0, #0
_0813EFC6:
	ldr r1, _0813F05C @ =0x0000048A
	adds r4, r6, r1
	cmp r0, #0
	beq _0813EFE0
	movs r0, #0
	mov r2, r8
	strh r0, [r2, #0x3e]
	mov r3, sb
	strh r0, [r3]
	strh r0, [r4]
	movs r0, #1
	ldr r1, [sp, #8]
	strb r0, [r1]
_0813EFE0:
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
_0813F00A:
	ldr r2, _0813F060 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813F064 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0813F068 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r3, sb
	ldrh r2, [r3]
	movs r1, #0xf
	ands r0, r1
	subs r2, r2, r0
	cmp r2, #0x14
	bge _0813F02E
	movs r2, #0x14
_0813F02E:
	mov r4, sb
	strh r2, [r4]
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r1, r1, r2
	movs r2, #9
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
_0813F04A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813F05C: .4byte 0x0000048A
_0813F060: .4byte 0x030046B8
_0813F064: .4byte 0x000003FF
_0813F068: .4byte 0x0203B400

	thumb_func_start FUN_0813f06c
FUN_0813f06c: @ 0x0813F06C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0813F08C @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F090
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F092
	.align 2, 0
_0813F08C: .4byte 0x0000046D
_0813F090:
	movs r0, #0
_0813F092:
	cmp r0, #0
	beq _0813F0B8
	ldr r0, _0813F10C @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	ldr r2, _0813F110 @ =0x0000066B
	adds r0, r5, r2
	strb r1, [r0]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	ldrb r1, [r4, #5]
	ldr r3, _0813F114 @ =0x00000661
	adds r0, r5, r3
	strb r1, [r0]
_0813F0B8:
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldr r2, _0813F118 @ =0x0000065E
	adds r1, r5, r2
	ldrb r1, [r1]
	bl Mod
	cmp r0, #0
	bne _0813F0DC
	movs r3, #0x97
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	ldr r0, _0813F11C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0813F0DC:
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0xb
	bls _0813F0EE
	adds r0, r4, #0
	bl FUN_08140dd0
_0813F0EE:
	ldr r2, _0813F110 @ =0x0000066B
	adds r0, r5, r2
	ldrb r2, [r0]
	ldr r0, _0813F10C @ =0x03002BE0
	ldr r0, [r0]
	movs r3, #0x80
	lsls r3, r3, #3
	adds r0, r0, r3
	ldrb r1, [r0]
	cmp r1, r2
	bge _0813F124
	ldr r3, _0813F120 @ =0xFFFFFF00
	adds r0, r2, r3
	subs r2, r1, r0
	b _0813F126
	.align 2, 0
_0813F10C: .4byte 0x03002BE0
_0813F110: .4byte 0x0000066B
_0813F114: .4byte 0x00000661
_0813F118: .4byte 0x0000065E
_0813F11C: .4byte 0x0000FFFB
_0813F120: .4byte 0xFFFFFF00
_0813F124:
	subs r2, r1, r2
_0813F126:
	ldr r1, _0813F144 @ =0x0000066A
	adds r0, r5, r1
	strb r2, [r0]
	movs r3, #0xcc
	lsls r3, r3, #3
	adds r1, r5, r3
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	ldrb r1, [r1]
	cmp r0, r1
	bls _0813F14C
	ldr r0, _0813F148 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	b _0813F172
	.align 2, 0
_0813F144: .4byte 0x0000066A
_0813F148: .4byte 0x0000046B
_0813F14C:
	ldr r1, _0813F168 @ =0x00000661
	adds r5, r5, r1
	ldrb r0, [r5]
	ldrb r2, [r4, #5]
	cmp r0, r2
	beq _0813F16C
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	ldrb r0, [r4, #5]
	strb r0, [r5]
	b _0813F174
	.align 2, 0
_0813F168: .4byte 0x00000661
_0813F16C:
	ldr r3, _0813F17C @ =0x0000046E
	adds r1, r4, r3
	movs r0, #0
_0813F172:
	strb r0, [r1]
_0813F174:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813F17C: .4byte 0x0000046E

	thumb_func_start FUN_0813f180
FUN_0813f180: @ 0x0813F180
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0813F1A0 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F1A4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F1A6
	.align 2, 0
_0813F1A0: .4byte 0x0000046D
_0813F1A4:
	movs r0, #0
_0813F1A6:
	adds r1, r0, #0
	cmp r1, #0
	beq _0813F1C0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	ldrb r1, [r4, #5]
	ldr r2, _0813F1BC @ =0x00000661
	adds r0, r5, r2
	b _0813F1E4
	.align 2, 0
_0813F1BC: .4byte 0x00000661
_0813F1C0:
	ldr r0, _0813F1DC @ =0x00000661
	adds r5, r5, r0
	ldrb r0, [r5]
	ldrb r2, [r4, #5]
	cmp r0, r2
	beq _0813F1E0
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	ldrb r0, [r4, #5]
	strb r0, [r5]
	b _0813F1E6
	.align 2, 0
_0813F1DC: .4byte 0x00000661
_0813F1E0:
	ldr r2, _0813F1EC @ =0x0000046E
	adds r0, r4, r2
_0813F1E4:
	strb r1, [r0]
_0813F1E6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813F1EC: .4byte 0x0000046E

	thumb_func_start FUN_0813f1f0
FUN_0813f1f0: @ 0x0813F1F0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	ldr r2, _0813F210 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F214
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F216
	.align 2, 0
_0813F210: .4byte 0x0000046D
_0813F214:
	movs r0, #0
_0813F216:
	adds r6, r0, #0
	cmp r6, #0
	beq _0813F234
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	ldrb r1, [r4, #5]
	ldr r2, _0813F230 @ =0x00000661
	adds r0, r5, r2
	strb r1, [r0]
	b _0813F25E
	.align 2, 0
_0813F230: .4byte 0x00000661
_0813F234:
	adds r0, r4, #0
	bl FUN_08140dd0
	ldr r0, _0813F254 @ =0x00000661
	adds r5, r5, r0
	ldrb r0, [r5]
	ldrb r1, [r4, #5]
	cmp r0, r1
	beq _0813F258
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ef86c
	ldrb r0, [r4, #5]
	strb r0, [r5]
	b _0813F25E
	.align 2, 0
_0813F254: .4byte 0x00000661
_0813F258:
	ldr r2, _0813F264 @ =0x0000046E
	adds r0, r4, r2
	strb r6, [r0]
_0813F25E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813F264: .4byte 0x0000046E

	thumb_func_start FUN_0813f268
FUN_0813f268: @ 0x0813F268
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0813F280 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F284
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F286
	.align 2, 0
_0813F280: .4byte 0x0000046D
_0813F284:
	movs r0, #0
_0813F286:
	cmp r0, #0
	beq _0813F294
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #0
	bl FUN_080efc44
_0813F294:
	ldr r0, _0813F2A4 @ =0x0000046E
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813F2A4: .4byte 0x0000046E

	thumb_func_start FUN_0813f2a8
FUN_0813f2a8: @ 0x0813F2A8
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _0813F2C0 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F2C4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F2C6
	.align 2, 0
_0813F2C0: .4byte 0x0000046D
_0813F2C4:
	movs r0, #0
_0813F2C6:
	cmp r0, #0
	beq _0813F2D4
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl FUN_080efc44
_0813F2D4:
	ldr r1, _0813F2F8 @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813F2F0
	subs r1, #3
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08013698
_0813F2F0:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813F2F8: .4byte 0x0000046E

	thumb_func_start FUN_0813f2fc
FUN_0813f2fc: @ 0x0813F2FC
	push {lr}
	adds r2, r0, #0
	ldr r0, _0813F31C @ =0x0000046D
	adds r1, r2, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F30E
	movs r0, #0
	strb r0, [r1]
_0813F30E:
	adds r0, r2, #0
	movs r1, #0
	bl FUN_080ef86c
	pop {r0}
	bx r0
	.align 2, 0
_0813F31C: .4byte 0x0000046D

	thumb_func_start FUN_0813f320
FUN_0813f320: @ 0x0813F320
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	adds r5, r0, #0
	mov sb, r1
	ldr r0, _0813F37C @ =0x0000046D
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F33C
	movs r0, #0
	strb r0, [r1]
_0813F33C:
	ldrb r0, [r5, #5]
	add r2, sp, #8
	add r1, sp, #4
	bl FUN_08140940
	ldr r1, _0813F380 @ =0x000004EC
	adds r0, r5, r1
	ldrb r2, [r0]
	ldr r3, [sp, #4]
	ldr r4, [sp, #8]
	ldr r1, _0813F384 @ =0x0000025D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _0813F390
	ldr r1, _0813F388 @ =0x000004B7
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
	ldr r0, _0813F38C @ =0x0000046E
	adds r7, r5, r0
	b _0813F412
	.align 2, 0
_0813F37C: .4byte 0x0000046D
_0813F380: .4byte 0x000004EC
_0813F384: .4byte 0x0000025D
_0813F388: .4byte 0x000004B7
_0813F38C: .4byte 0x0000046E
_0813F390:
	ldr r0, [r5, #0x44]
	adds r6, r0, #0
	adds r6, #0x20
	adds r2, r2, r3
	ldr r1, _0813F400 @ =0x000004B7
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r3, r0, #0
	ldr r0, _0813F404 @ =0x0000046E
	adds r7, r5, r0
	cmp r1, r2
	bne _0813F3CA
	ldrb r0, [r7]
	cmp r0, #0
	bne _0813F3CA
	cmp r4, #1
	bne _0813F3BC
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _0813F416
_0813F3BC:
	cmp r4, #0
	bne _0813F3CA
	ldr r0, [r6, #8]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0813F416
_0813F3CA:
	strb r2, [r3]
	movs r1, #4
	mov r8, r1
	adds r0, r4, #0
	ands r0, r1
	movs r3, #4
	cmp r0, #0
	beq _0813F3DC
	movs r3, #6
_0813F3DC:
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
	beq _0813F408
	ldr r0, [r6, #8]
	mov r1, r8
	orrs r0, r1
	b _0813F410
	.align 2, 0
_0813F400: .4byte 0x000004B7
_0813F404: .4byte 0x0000046E
_0813F408:
	ldr r0, [r6, #8]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_0813F410:
	str r0, [r6, #8]
_0813F412:
	movs r0, #0
	strb r0, [r7]
_0813F416:
	mov r0, sb
	cmp r0, #0x1d
	bgt _0813F42A
	movs r0, #0x20
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
_0813F42A:
	mov r0, sb
	cmp r0, #0x3b
	ble _0813F438
	ldr r0, _0813F448 @ =0x0000046B
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_0813F438:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813F448: .4byte 0x0000046B

	thumb_func_start FUN_0813f44c
FUN_0813f44c: @ 0x0813F44C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0813F49C @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F45E
	movs r0, #0
	strb r0, [r1]
_0813F45E:
	movs r0, #0x10
	movs r1, #0xc1
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r5, #0x83
	lsls r5, r5, #2
	adds r0, r6, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r3, #0x98
	adds r1, r6, r3
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	adds r4, r1, #0
	cmp r0, #0
	blt _0813F4A0
	asrs r0, r0, #2
	b _0813F4A6
	.align 2, 0
_0813F49C: .4byte 0x0000046D
_0813F4A0:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813F4A6:
	adds r3, r0, #0
	movs r1, #0x84
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r5, #0
	ldrsh r2, [r0, r5]
	movs r0, #0x86
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _0813F4C6
	asrs r0, r0, #2
	b _0813F4CC
_0813F4C6:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813F4CC:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0813F4D6
	movs r3, #0xc8
	b _0813F4E0
_0813F4D6:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0813F4E0
	adds r3, r0, #0
_0813F4E0:
	cmp r2, #0xc8
	ble _0813F4E8
	movs r2, #0xc8
	b _0813F4F2
_0813F4E8:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0813F4F2
	adds r2, r0, #0
_0813F4F2:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0813F516
	cmp r2, #0
	bne _0813F516
	movs r0, #1
	b _0813F518
_0813F516:
	movs r0, #0
_0813F518:
	cmp r0, #0
	beq _0813F5E4
	adds r0, r6, #0
	bl FUN_08140904
	ldr r0, _0813F57C @ =0x0000024E
	adds r3, r6, r0
	ldrh r4, [r3]
	cmp r4, #0
	beq _0813F58C
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r6, r1
	ldrh r1, [r2]
	movs r4, #0
	movs r5, #0
	orrs r0, r1
	strh r0, [r2]
	movs r2, #0x93
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r0, [r0]
	strh r0, [r3]
	ldr r0, _0813F580 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r6, #0
	bl FUN_08140970
	movs r1, #2
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	strb r4, [r0]
	ldr r2, _0813F584 @ =0x00000469
	adds r0, r6, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r6, r3
	strb r4, [r0]
	ldr r1, _0813F588 @ =0x00000484
	adds r0, r6, r1
	str r5, [r0]
	adds r2, #3
	adds r1, r6, r2
	movs r0, #1
	strb r0, [r1]
	b _0813F5E4
	.align 2, 0
_0813F57C: .4byte 0x0000024E
_0813F580: .4byte 0x03002BE0
_0813F584: .4byte 0x00000469
_0813F588: .4byte 0x00000484
_0813F58C:
	ldr r3, _0813F5EC @ =FUN_0813f320
	movs r1, #0xa
	ldr r5, _0813F5F0 @ =0x0000046D
	adds r0, r6, r5
	movs r2, #1
	strb r2, [r0]
	subs r5, #2
	adds r0, r6, r5
	strb r4, [r0]
	adds r5, #0xe8
	adds r0, r6, r5
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r1, #0
	strh r4, [r0]
	subs r5, #0xeb
	adds r0, r6, r5
	strb r1, [r0]
	ldr r1, _0813F5F4 @ =0x00000469
	adds r0, r6, r1
	strb r2, [r0]
	ldr r3, _0813F5F8 @ =0x0000046A
	adds r0, r6, r3
	strb r2, [r0]
	adds r5, #0x1c
	adds r0, r6, r5
	str r4, [r0]
	adds r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r6, #5]
	subs r5, #2
	adds r0, r6, r5
	strh r2, [r0]
_0813F5E4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813F5EC: .4byte FUN_0813f320
_0813F5F0: .4byte 0x0000046D
_0813F5F4: .4byte 0x00000469
_0813F5F8: .4byte 0x0000046A

	thumb_func_start FUN_0813f5fc
FUN_0813f5fc: @ 0x0813F5FC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r0, [r0]
	mov r8, r0
	ldr r2, _0813F620 @ =0x0000046D
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F624
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F626
	.align 2, 0
_0813F620: .4byte 0x0000046D
_0813F624:
	movs r0, #0
_0813F626:
	cmp r0, #0
	beq _0813F64E
	movs r0, #0x20
	movs r3, #0xc0
	lsls r3, r3, #1
	adds r2, r4, r3
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080ef86c
	movs r6, #0x94
	lsls r6, r6, #1
	adds r2, r4, r6
	ldrh r1, [r2, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2, #6]
_0813F64E:
	movs r2, #0x80
	lsls r2, r2, #0xd
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x83
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r3, #0
	ldrsh r2, [r0, r3]
	movs r6, #0x85
	lsls r6, r6, #2
	adds r1, r4, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r0, r2, r0
	adds r5, r1, #0
	cmp r0, #0
	blt _0813F67E
	asrs r0, r0, #2
	b _0813F684
_0813F67E:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813F684:
	adds r3, r0, #0
	movs r6, #0x84
	lsls r6, r6, #2
	adds r0, r4, r6
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r6, #8
	adds r1, r4, r6
	movs r6, #0
	ldrsh r0, [r1, r6]
	subs r0, r2, r0
	cmp r0, #0
	blt _0813F6A2
	asrs r0, r0, #2
	b _0813F6A8
_0813F6A2:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_0813F6A8:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _0813F6B2
	movs r3, #0xc8
	b _0813F6BC
_0813F6B2:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _0813F6BC
	adds r3, r0, #0
_0813F6BC:
	cmp r2, #0xc8
	ble _0813F6C4
	movs r2, #0xc8
	b _0813F6CE
_0813F6C4:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _0813F6CE
	adds r2, r0, #0
_0813F6CE:
	ldrh r0, [r4, #0x10]
	adds r0, r0, r3
	strh r0, [r4, #0x10]
	ldrh r0, [r4, #0x14]
	adds r0, r0, r2
	strh r0, [r4, #0x14]
	ldrh r0, [r5]
	adds r0, r0, r3
	strh r0, [r5]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0813F6F2
	cmp r2, #0
	bne _0813F6F2
	movs r0, #1
	b _0813F6F4
_0813F6F2:
	movs r0, #0
_0813F6F4:
	cmp r0, #0
	beq _0813F7C2
	ldr r1, _0813F778 @ =0x0000046B
	adds r0, r4, r1
	movs r7, #1
	strb r7, [r0]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r5, r4, r2
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r5]
	ands r0, r1
	movs r6, #0
	strh r0, [r5]
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r2, r4, r3
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r0, _0813F77C @ =0x00000666
	add r0, r8
	strb r6, [r0]
	movs r1, #0x80
	lsls r1, r1, #0x13
	ldr r0, [r2]
	adds r3, r0, #0
	ands r3, r1
	cmp r3, #0
	beq _0813F78C
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	ldr r0, _0813F780 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_08140970
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r6, [r0]
	ldr r3, _0813F784 @ =0x00000469
	adds r0, r4, r3
	strb r1, [r0]
	ldr r1, _0813F788 @ =0x0000046A
	adds r0, r4, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r1, r4, r2
	movs r0, #0
	str r0, [r1]
	adds r3, #3
	adds r0, r4, r3
	strb r7, [r0]
	adds r0, r4, #0
	bl FUN_08140904
	b _0813F7C2
	.align 2, 0
_0813F778: .4byte 0x0000046B
_0813F77C: .4byte 0x00000666
_0813F780: .4byte 0x03002BE0
_0813F784: .4byte 0x00000469
_0813F788: .4byte 0x0000046A
_0813F78C:
	orrs r0, r1
	str r0, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ldrh r1, [r5]
	orrs r0, r1
	strh r0, [r5]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	strb r6, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r6, [r0]
	ldr r6, _0813F7CC @ =0x0000046A
	adds r0, r4, r6
	strb r1, [r0]
	ldr r1, _0813F7D0 @ =0x00000484
	adds r0, r4, r1
	str r3, [r0]
	adds r2, #3
	adds r0, r4, r2
	strb r7, [r0]
	adds r0, r4, #0
	bl FUN_08140904
_0813F7C2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813F7CC: .4byte 0x0000046A
_0813F7D0: .4byte 0x00000484

	thumb_func_start FUN_0813f7d4
FUN_0813f7d4: @ 0x0813F7D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x28
	adds r6, r0, #0
	adds r4, r1, #0
	ldr r0, _0813F7F0 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F7F4
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F7F6
	.align 2, 0
_0813F7F0: .4byte 0x0000046D
_0813F7F4:
	movs r0, #0
_0813F7F6:
	cmp r0, #0
	beq _0813F838
	adds r0, r6, #0
	movs r1, #0xa
	bl FUN_080ef86c
	adds r0, r6, #0
	bl FUN_080e8360
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r1, _0813F8E0 @ =0xFFFEBE3F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _0813F8E4 @ =0x0000021E
	adds r0, r6, r2
	movs r1, #0
	strh r1, [r0]
	movs r3, #0x88
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r1, [r0]
	ldr r7, _0813F8E8 @ =0x00000202
	adds r0, r6, r7
	strh r1, [r0]
	adds r2, r6, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
_0813F838:
	ldr r0, [r6, #0x44]
	adds r1, r4, #0
	movs r2, #0xa
	movs r3, #0x1e
	bl FUN_082375c8
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813F84C
	b _0813F98A
_0813F84C:
	ldr r1, _0813F8EC @ =0x0000046B
	adds r0, r6, r1
	movs r4, #1
	strb r4, [r0]
	movs r3, #0xcd
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r2]
	cmp r0, #0
	beq _0813F8B6
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
	ldr r1, _0813F8F0 @ =0xFFFF0000
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
_0813F8B6:
	ldr r1, _0813F8F4 @ =0x000001DF
	adds r0, r6, r1
	ldrb r0, [r0]
	movs r2, #0x90
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r1, [r1]
	bl FUN_0820ccd0
	adds r3, r0, #0
	cmp r3, #0x1f
	bgt _0813F8FC
	ldr r0, _0813F8F8 @ =0x030046A0
	ldr r2, [r0]
	movs r7, #0xe2
	lsls r7, r7, #2
	adds r2, r2, r7
	adds r1, r4, #0
	lsls r1, r3
	b _0813F90E
	.align 2, 0
_0813F8E0: .4byte 0xFFFEBE3F
_0813F8E4: .4byte 0x0000021E
_0813F8E8: .4byte 0x00000202
_0813F8EC: .4byte 0x0000046B
_0813F8F0: .4byte 0xFFFF0000
_0813F8F4: .4byte 0x000001DF
_0813F8F8: .4byte 0x030046A0
_0813F8FC:
	ldr r0, _0813F994 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0xe3
	lsls r0, r0, #2
	adds r2, r2, r0
	adds r0, r3, #0
	subs r0, #0x20
	adds r1, r4, #0
	lsls r1, r0
_0813F90E:
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
	bne _0813F92C
	adds r0, r6, #0
	bl FUN_080e6658
_0813F92C:
	movs r3, #0xc9
	lsls r3, r3, #1
	adds r0, r6, r3
	movs r5, #0
	movs r2, #0
	strh r2, [r0]
	ldr r4, _0813F998 @ =FUN_080e48d0
	movs r3, #0x10
	ldr r7, _0813F99C @ =0x0000046D
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
	ldr r4, _0813F9A0 @ =0x00000469
	adds r0, r6, r4
	strb r5, [r0]
	adds r7, #2
	adds r0, r6, r7
	strb r3, [r0]
	ldr r3, _0813F9A4 @ =0x00000484
	adds r0, r6, r3
	str r2, [r0]
	adds r4, #3
	adds r0, r6, r4
	strb r1, [r0]
	movs r7, #0x9a
	lsls r7, r7, #2
	adds r0, r6, r7
	bl FUN_080136b4
_0813F98A:
	add sp, #0x28
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813F994: .4byte 0x030046A0
_0813F998: .4byte FUN_080e48d0
_0813F99C: .4byte 0x0000046D
_0813F9A0: .4byte 0x00000469
_0813F9A4: .4byte 0x00000484

	thumb_func_start FUN_0813f9a8
FUN_0813f9a8: @ 0x0813F9A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r7, [r0]
	ldr r2, _0813F9C8 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813F9CC
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813F9CE
	.align 2, 0
_0813F9C8: .4byte 0x0000046C
_0813F9CC:
	movs r0, #0
_0813F9CE:
	cmp r0, #0
	beq _0813FA14
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r1, [r0]
	movs r4, #1
	ldr r2, _0813FA64 @ =0x0000046D
	adds r0, r5, r2
	movs r2, #0
	strb r4, [r0]
	ldr r3, _0813FA68 @ =0x0000046B
	adds r0, r5, r3
	strb r2, [r0]
	adds r3, #0xe8
	adds r0, r5, r3
	strb r4, [r0]
	adds r3, #0x25
	adds r0, r5, r3
	str r1, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r3, #0xd6
	lsls r3, r3, #3
	adds r1, r7, r3
	str r2, [sp]
	mov r0, sp
	ldr r2, _0813FA6C @ =0x05000002
	bl CpuSet
	ldr r1, _0813FA70 @ =0x00000667
	adds r0, r7, r1
	strb r4, [r0]
_0813FA14:
	movs r2, #0xb1
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r6, r0, #0
	adds r0, r5, #0
	bl FUN_081404c0
	ldr r3, _0813FA74 @ =0x000004A4
	adds r0, r5, r3
	ldr r1, [r0]
	ldrh r2, [r1, #0xc]
	ldrh r0, [r5, #8]
	subs r2, r2, r0
	lsls r2, r2, #0x10
	ldrh r0, [r1, #0x10]
	ldrh r1, [r5, #0xc]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	lsrs r3, r2, #0x10
	asrs r2, r2, #0x10
	cmp r2, #0
	bge _0813FA4C
	rsbs r2, r2, #0
_0813FA4C:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0813FA78
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0813FA5A
	rsbs r2, r2, #0
_0813FA5A:
	cmp r2, #0x20
	bgt _0813FA78
	movs r0, #1
	b _0813FAE2
	.align 2, 0
_0813FA64: .4byte 0x0000046D
_0813FA68: .4byte 0x0000046B
_0813FA6C: .4byte 0x05000002
_0813FA70: .4byte 0x00000667
_0813FA74: .4byte 0x000004A4
_0813FA78:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _0813FA84
	cmp r1, #0
	beq _0813FAE0
_0813FA84:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r5, #5]
	ldr r2, _0813FAA8 @ =0x085B0A08
	ldrb r0, [r5, #5]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813FAAC
	asrs r1, r0, #0xc
	b _0813FAB2
	.align 2, 0
_0813FAA8: .4byte 0x085B0A08
_0813FAAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813FAB2:
	ldrh r0, [r5, #0x10]
	adds r0, r0, r1
	strh r0, [r5, #0x10]
	ldr r1, _0813FAD0 @ =0x085B0A08
	ldrb r0, [r5, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813FAD4
	asrs r1, r0, #0xc
	b _0813FADA
	.align 2, 0
_0813FAD0: .4byte 0x085B0A08
_0813FAD4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813FADA:
	ldrh r0, [r5, #0x14]
	adds r0, r0, r1
	strh r0, [r5, #0x14]
_0813FAE0:
	movs r0, #0
_0813FAE2:
	cmp r0, #0
	bne _0813FAE8
	b _0813FBE2
_0813FAE8:
	adds r0, r5, #0
	bl FUN_081406b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0813FBE2
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r3, r7, r0
	ldrb r4, [r5, #5]
	ldr r2, _0813FB18 @ =0x085B0A08
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
	blt _0813FB1C
	asrs r1, r0, #0xc
	b _0813FB22
	.align 2, 0
_0813FB18: .4byte 0x085B0A08
_0813FB1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813FB22:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0813FB3A
	asrs r0, r0, #0xc
	b _0813FB40
_0813FB3A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813FB40:
	strh r0, [r3, #4]
	adds r0, r5, #0
	bl FUN_08140520
	add r6, sp, #4
	adds r0, r5, #0
	adds r0, #0x9c
	ldr r1, [r0, #8]
	ldrh r0, [r1]
	strh r0, [r6]
	ldrh r1, [r1, #2]
	strh r1, [r6, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	adds r7, r6, #0
	cmp r2, #0
	blt _0813FB7A
	cmp r1, #0
	blt _0813FB7A
	ldr r0, _0813FB80 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0813FB7A
	ldr r0, _0813FB84 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0813FB88
_0813FB7A:
	movs r4, #0
	b _0813FB96
	.align 2, 0
_0813FB80: .4byte 0x030046A8
_0813FB84: .4byte 0x030046AC
_0813FB88:
	ldr r0, _0813FBA8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_0813FB96:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0813FBAC
	adds r0, #4
	b _0813FBB8
	.align 2, 0
_0813FBA8: .4byte 0x030046A4
_0813FBAC:
	ldr r0, _0813FBCC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0813FBB8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _0813FBD0
	cmp r2, #2
	beq _0813FBD4
	b _0813FBD8
	.align 2, 0
_0813FBCC: .4byte 0x030046A4
_0813FBD0:
	ldrb r0, [r6, #4]
	b _0813FBD6
_0813FBD4:
	ldrb r0, [r6]
_0813FBD6:
	subs r1, r1, r0
_0813FBD8:
	strh r1, [r6, #2]
	adds r0, r5, #0
	adds r1, r7, #0
	bl FUN_08140970
_0813FBE2:
	ldr r3, _0813FBF4 @ =0x00000484
	adds r1, r5, r3
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0813FBF4: .4byte 0x00000484

	thumb_func_start FUN_0813fbf8
FUN_0813fbf8: @ 0x0813FBF8
	push {r4, lr}
	adds r3, r0, #0
	ldr r0, _0813FC10 @ =0x0000046C
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813FC14
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813FC16
	.align 2, 0
_0813FC10: .4byte 0x0000046C
_0813FC14:
	movs r0, #0
_0813FC16:
	cmp r0, #0
	beq _0813FC24
	movs r1, #0xfe
	lsls r1, r1, #1
	adds r0, r3, r1
	ldrb r0, [r0]
	strb r0, [r3, #5]
_0813FC24:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r3, r2
	ldrh r0, [r0]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _0813FC68
	movs r2, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r3, r4
	movs r1, #0
	strb r1, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	ldr r2, _0813FC60 @ =0x0000046A
	adds r0, r3, r2
	strb r1, [r0]
	adds r4, #0x1b
	adds r0, r3, r4
	str r1, [r0]
	ldr r0, _0813FC64 @ =0x0000046C
	adds r1, r3, r0
	b _0813FC88
	.align 2, 0
_0813FC60: .4byte 0x0000046A
_0813FC64: .4byte 0x0000046C
_0813FC68:
	movs r1, #2
	movs r4, #0x8d
	lsls r4, r4, #3
	adds r0, r3, r4
	strb r2, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r2, [r0]
	adds r4, #1
	adds r0, r3, r4
	strb r1, [r0]
	ldr r1, _0813FC94 @ =0x00000484
	adds r0, r3, r1
	str r2, [r0]
	ldr r2, _0813FC98 @ =0x0000046C
	adds r1, r3, r2
_0813FC88:
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0813FC94: .4byte 0x00000484
_0813FC98: .4byte 0x0000046C

	thumb_func_start FUN_0813fc9c
FUN_0813fc9c: @ 0x0813FC9C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0813FCB4 @ =0x0000046C
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813FCB8
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813FCBA
	.align 2, 0
_0813FCB4: .4byte 0x0000046C
_0813FCB8:
	movs r0, #0
_0813FCBA:
	cmp r0, #0
	beq _0813FCEE
	ldr r4, _0813FD14 @ =FUN_0813f268
	movs r3, #0x21
	ldr r0, _0813FD18 @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813FD1C @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	adds r1, #0xa0
	adds r0, r5, r1
	bl FUN_080136b4
_0813FCEE:
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0813FD0C
	ldr r0, _0813FD20 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813FD0C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0813FD14: .4byte FUN_0813f268
_0813FD18: .4byte 0x0000046D
_0813FD1C: .4byte 0x0000046B
_0813FD20: .4byte 0x00000484

	thumb_func_start FUN_0813fd24
FUN_0813fd24: @ 0x0813FD24
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r6, [r0]
	ldr r2, _0813FD44 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813FD48
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813FD4A
	.align 2, 0
_0813FD44: .4byte 0x0000046C
_0813FD48:
	movs r0, #0
_0813FD4A:
	cmp r0, #0
	beq _0813FDEE
	ldr r4, _0813FDA8 @ =FUN_0813f2a8
	movs r3, #0x22
	ldr r0, _0813FDAC @ =0x0000046D
	adds r1, r5, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _0813FDB0 @ =0x0000046B
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #0xe8
	adds r0, r5, r1
	strb r3, [r0]
	adds r1, #0x25
	adds r0, r5, r1
	str r4, [r0]
	movs r1, #0xe4
	lsls r1, r1, #1
	adds r0, r5, r1
	strh r2, [r0]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r2, r5, r0
	ldr r1, _0813FDB4 @ =0xFFEFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r1, #0xe0
	lsls r1, r1, #1
	adds r3, r5, r1
	ldrb r4, [r5, #5]
	ldr r2, _0813FDB8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #2
	cmp r0, #0
	blt _0813FDBC
	asrs r1, r0, #0xc
	b _0813FDC2
	.align 2, 0
_0813FDA8: .4byte FUN_0813f2a8
_0813FDAC: .4byte 0x0000046D
_0813FDB0: .4byte 0x0000046B
_0813FDB4: .4byte 0xFFEFFFFF
_0813FDB8: .4byte 0x085B0A08
_0813FDBC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0813FDC2:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _0813FDDC
	asrs r0, r0, #0xc
	b _0813FDE2
_0813FDDC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0813FDE2:
	strh r0, [r3, #4]
	movs r0, #0xe1
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r0, #0xa
	strh r0, [r1]
_0813FDEE:
	ldr r1, _0813FE18 @ =0x0000046B
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0813FE20
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _0813FE1C @ =0x0000065C
	adds r0, r6, r2
	ldrh r0, [r0]
	subs r0, #0x14
	cmp r1, r0
	bge _0813FE20
	adds r0, r5, #0
	bl FUN_08140c14
	b _0813FE2A
	.align 2, 0
_0813FE18: .4byte 0x0000046B
_0813FE1C: .4byte 0x0000065C
_0813FE20:
	ldr r0, _0813FE30 @ =0x00000484
	adds r1, r5, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0813FE2A:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0813FE30: .4byte 0x00000484

	thumb_func_start FUN_0813fe34
FUN_0813fe34: @ 0x0813FE34
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _0813FE54 @ =0x0000046C
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _0813FE58
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _0813FE5A
	.align 2, 0
_0813FE54: .4byte 0x0000046C
_0813FE58:
	movs r0, #0
_0813FE5A:
	cmp r0, #0
	beq _0813FF26
	movs r3, #0xb4
	lsls r3, r3, #3
	adds r0, r5, r3
	ldr r3, [r0]
	movs r1, #1
	ldr r6, _0813FECC @ =0x0000046D
	adds r0, r5, r6
	movs r2, #0
	strb r1, [r0]
	subs r6, #2
	adds r0, r5, r6
	strb r2, [r0]
	adds r6, #0xe8
	adds r0, r5, r6
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r5, r1
	str r3, [r0]
	movs r3, #0xe4
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r2, [r0]
	movs r6, #0xd6
	lsls r6, r6, #3
	adds r1, r4, r6
	str r2, [sp]
	mov r0, sp
	ldr r2, _0813FED0 @ =0x05000002
	bl CpuSet
	ldr r2, _0813FED4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0813FED8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0813FEDC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r1, r4, r2
	strb r0, [r1]
	ldr r2, _0813FEE0 @ =0x085B0A08
	ldrb r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _0813FEE4
	asrs r1, r0, #7
	b _0813FEEA
	.align 2, 0
_0813FECC: .4byte 0x0000046D
_0813FED0: .4byte 0x05000002
_0813FED4: .4byte 0x030046B8
_0813FED8: .4byte 0x000003FF
_0813FEDC: .4byte 0x0203B400
_0813FEE0: .4byte 0x085B0A08
_0813FEE4:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r1, r0, #0
_0813FEEA:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r1, [r0]
	ldr r2, _0813FF14 @ =0x085B0A08
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0813FF18
	asrs r1, r0, #7
	b _0813FF1E
	.align 2, 0
_0813FF14: .4byte 0x085B0A08
_0813FF18:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r1, r0, #0
_0813FF1E:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_0813FF26:
	ldr r6, _0813FF4C @ =0x00000484
	adds r0, r5, r6
	ldr r0, [r0]
	cmp r0, #5
	bgt _0813FF8E
	ldr r1, _0813FF50 @ =0x085B0A08
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r2, r1, #0
	cmp r0, #0
	blt _0813FF54
	asrs r1, r0, #7
	b _0813FF5A
	.align 2, 0
_0813FF4C: .4byte 0x00000484
_0813FF50: .4byte 0x085B0A08
_0813FF54:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r1, r0, #0
_0813FF5A:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r0, r5, r6
	strh r1, [r0]
	movs r1, #0xce
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _0813FF80
	asrs r1, r0, #7
	b _0813FF86
_0813FF80:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r1, r0, #0
_0813FF86:
	movs r3, #0xe2
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r1, [r0]
_0813FF8E:
	movs r6, #0xe0
	lsls r6, r6, #1
	adds r4, r5, r6
	movs r1, #0
	ldrsh r0, [r4, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r4, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r6, r1, r0
	cmp r6, #0
	bne _0813FFEE
	adds r0, r5, #0
	bl FUN_08140904
	str r6, [sp]
	mov r0, sp
	adds r1, r4, #0
	ldr r2, _08140000 @ =0x05000002
	bl CpuSet
	ldr r0, _08140004 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_08140970
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r6, [r0]
	ldr r3, _08140008 @ =0x00000469
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _0814000C @ =0x0000046A
	adds r0, r5, r1
	strb r6, [r0]
	adds r2, #0x1c
	adds r0, r5, r2
	str r6, [r0]
	adds r3, #3
	adds r1, r5, r3
	movs r0, #1
	strb r0, [r1]
_0813FFEE:
	ldr r6, _08140010 @ =0x00000484
	adds r1, r5, r6
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08140000: .4byte 0x05000002
_08140004: .4byte 0x03002BE0
_08140008: .4byte 0x00000469
_0814000C: .4byte 0x0000046A
_08140010: .4byte 0x00000484

	thumb_func_start FUN_08140014
FUN_08140014: @ 0x08140014
	ldr r1, _08140020 @ =0x00000634
	adds r0, r0, r1
	ldr r1, _08140024 @ =0x085AD7D0
	str r1, [r0]
	bx lr
	.align 2, 0
_08140020: .4byte 0x00000634
_08140024: .4byte 0x085AD7D0

	thumb_func_start FUN_08140028
FUN_08140028: @ 0x08140028
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r5, [r0]
	ldr r2, _081400A8 @ =0x0000065F
	adds r0, r5, r2
	movs r3, #0
	strb r3, [r0]
	ldr r1, _081400AC @ =0x00000664
	adds r0, r5, r1
	movs r2, #0
	strh r3, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _081400B0 @ =0x00000667
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r0, r5, r1
	strh r3, [r0]
	adds r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r5, r1
	strb r2, [r0]
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r5, r2
	str r3, [r0]
	movs r3, #0xd7
	lsls r3, r3, #3
	adds r2, r5, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r6, #8]
	str r1, [r6, #0xc]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _081400A2
	cmp r1, #0
	blt _081400A2
	ldr r0, _081400B4 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _081400A2
	ldr r0, _081400B8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _081400BC
_081400A2:
	movs r1, #0
	b _081400CA
	.align 2, 0
_081400A8: .4byte 0x0000065F
_081400AC: .4byte 0x00000664
_081400B0: .4byte 0x00000667
_081400B4: .4byte 0x030046A8
_081400B8: .4byte 0x030046AC
_081400BC:
	ldr r0, _081400E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r1, r0, r3
_081400CA:
	ldr r2, _081400EC @ =0x00000256
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r4, [r0]
	movs r3, #0xd7
	lsls r3, r3, #3
	adds r7, r5, r3
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _081400F0
	adds r0, #4
	b _081400FC
	.align 2, 0
_081400E8: .4byte 0x030046A4
_081400EC: .4byte 0x00000256
_081400F0:
	ldr r0, _08140110 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_081400FC:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _08140114
	cmp r3, #2
	beq _08140118
	b _0814011C
	.align 2, 0
_08140110: .4byte 0x030046A4
_08140114:
	ldrb r0, [r7, #4]
	b _0814011A
_08140118:
	ldrb r0, [r7]
_0814011A:
	subs r2, r2, r0
_0814011C:
	ldr r0, _08140148 @ =0x00000472
	adds r1, r6, r0
	strh r2, [r1]
	ldrh r0, [r6, #0xa]
	subs r0, r0, r2
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r2, r6, r3
	strh r0, [r2]
	ldrh r0, [r1]
	strh r0, [r6, #0xa]
	ldr r1, _0814014C @ =0x0000025D
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _08140150
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	b _0814015A
	.align 2, 0
_08140148: .4byte 0x00000472
_0814014C: .4byte 0x0000025D
_08140150:
	ldr r2, [r6, #0x44]
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2, #0x40]
	str r1, [r2, #0x44]
_0814015A:
	movs r2, #0xd4
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r4, #0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081401C8 @ =0x05000002
	bl CpuSet
	movs r3, #0xd5
	lsls r3, r3, #3
	adds r1, r5, r3
	str r4, [sp]
	mov r0, sp
	ldr r2, _081401C8 @ =0x05000002
	bl CpuSet
	movs r0, #0xd6
	lsls r0, r0, #3
	adds r1, r5, r0
	str r4, [sp]
	mov r0, sp
	ldr r2, _081401C8 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	movs r1, #0
	bl FUN_080ef86c
	ldr r5, [r6, #0x44]
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
	beq _081401CC
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _081401D4
	.align 2, 0
_081401C8: .4byte 0x05000002
_081401CC:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_081401D4:
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
	beq _081401F8
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _08140200
_081401F8:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_08140200:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _08140238 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _08140270
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _0814023C
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _08140230
	ldrb r0, [r4, #5]
_08140230:
	subs r0, #1
	strh r0, [r4, #8]
	b _0814024C
	.align 2, 0
_08140238: .4byte 0x0000FFFF
_0814023C:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _0814024C
	strh r1, [r4, #8]
_0814024C:
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
	bne _08140270
	movs r0, #1
	strb r0, [r4, #7]
_08140270:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08140278
FUN_08140278: @ 0x08140278
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0814030E
	ldr r0, _081402AC @ =0x03002BE0
	ldr r0, [r0]
	cmp r0, #0
	beq _0814030E
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, [r0]
	movs r1, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081402B0
	movs r0, #1
	b _081402B2
	.align 2, 0
_081402AC: .4byte 0x03002BE0
_081402B0:
	movs r0, #0
_081402B2:
	cmp r0, #0
	beq _0814030E
	movs r0, #0xcb
	lsls r0, r0, #3
	adds r2, r2, r0
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r3, #0xbc
	lsls r3, r3, #1
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	movs r3, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	ldr r3, _08140314 @ =0x0000046A
	adds r0, r5, r3
	strb r1, [r0]
	ldr r1, _08140318 @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #3
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_0814030E:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08140314: .4byte 0x0000046A
_08140318: .4byte 0x00000484

	thumb_func_start FUN_0814031c
FUN_0814031c: @ 0x0814031C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r5, [r0]
	adds r0, r4, #0
	bl FUN_080e8a60
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _08140336
	b _081404B0
_08140336:
	movs r2, #2
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	adds r2, r1, #0
	cmp r0, #0
	beq _0814034C
	movs r0, #1
	b _0814034E
_0814034C:
	movs r0, #0
_0814034E:
	cmp r0, #0
	beq _0814036C
	ldr r6, _08140368 @ =0x00000662
	adds r1, r5, r6
	movs r2, #0xdf
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0xa]
	b _081404B0
	.align 2, 0
_08140368: .4byte 0x00000662
_0814036C:
	movs r3, #0xdf
	lsls r3, r3, #1
	adds r0, r4, r3
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldr r0, _0814038C @ =0x00000103
	cmp r1, r0
	bgt _081403E4
	movs r1, #1
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _08140390
	movs r0, #1
	b _08140392
	.align 2, 0
_0814038C: .4byte 0x00000103
_08140390:
	movs r0, #0
_08140392:
	cmp r0, #0
	beq _081403A4
	ldr r1, _081403A0 @ =0x00000472
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r4, #0xa]
	b _081404B0
	.align 2, 0
_081403A0: .4byte 0x00000472
_081403A4:
	ldr r1, _081403BC @ =0x085B0A08
	ldr r2, _081403C0 @ =0x00000666
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	blt _081403C4
	asrs r2, r0, #9
	b _081403CA
	.align 2, 0
_081403BC: .4byte 0x085B0A08
_081403C0: .4byte 0x00000666
_081403C4:
	rsbs r0, r0, #0
	asrs r0, r0, #9
	rsbs r2, r0, #0
_081403CA:
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r1, r4, r6
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _08140410 @ =0x00000666
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0x3f
	bhi _081403E4
	adds r0, #1
	strb r0, [r1]
_081403E4:
	ldr r1, _08140414 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0xa
	ldrsh r0, [r4, r2]
	ldr r3, _08140418 @ =0xFFFFFEFC
	adds r0, r0, r3
	subs r1, r1, r0
	adds r0, r1, #0
	cmp r1, #0
	bge _081403FC
	rsbs r0, r1, #0
_081403FC:
	cmp r0, #0x10
	ble _08140428
	cmp r1, #0
	bge _0814041C
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r1, r4, r6
	ldrh r0, [r1]
	subs r0, #2
	b _08140426
	.align 2, 0
_08140410: .4byte 0x00000666
_08140414: .4byte 0x00000472
_08140418: .4byte 0xFFFFFEFC
_0814041C:
	movs r0, #0xdf
	lsls r0, r0, #1
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #2
_08140426:
	strh r0, [r1]
_08140428:
	ldr r1, _08140470 @ =0x00000472
	adds r3, r4, r1
	ldr r2, _08140474 @ =0x0000066E
	adds r0, r5, r2
	ldrh r1, [r3]
	ldrh r0, [r0]
	cmp r1, r0
	beq _08140446
	movs r6, #0xdf
	lsls r6, r6, #1
	adds r2, r4, r6
	subs r1, r1, r0
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
_08140446:
	movs r1, #0xdf
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r3, [r3]
	adds r0, r0, r3
	strh r0, [r4, #0xa]
	ldr r2, [r4, #0x44]
	ldr r1, _08140478 @ =0x085B0A08
	ldr r3, _0814047C @ =0x00000666
	adds r0, r5, r3
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, #0
	blt _08140480
	asrs r1, r0, #5
	b _08140486
	.align 2, 0
_08140470: .4byte 0x00000472
_08140474: .4byte 0x0000066E
_08140478: .4byte 0x085B0A08
_0814047C: .4byte 0x00000666
_08140480:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r1, r0, #0
_08140486:
	ldrh r0, [r2, #0x1e]
	subs r0, r0, r1
	strh r0, [r2, #0x1e]
	ldr r0, _0814049C @ =0x00000666
	adds r1, r5, r0
	ldrb r0, [r1]
	cmp r0, #0x40
	bls _081404A0
	movs r0, #0
	b _081404A2
	.align 2, 0
_0814049C: .4byte 0x00000666
_081404A0:
	adds r0, #8
_081404A2:
	strb r0, [r1]
	ldr r1, _081404B8 @ =0x00000472
	adds r0, r4, r1
	ldrh r1, [r0]
	ldr r2, _081404BC @ =0x0000066E
	adds r0, r5, r2
	strh r1, [r0]
_081404B0:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081404B8: .4byte 0x00000472
_081404BC: .4byte 0x0000066E

	thumb_func_start FUN_081404c0
FUN_081404c0: @ 0x081404C0
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	movs r0, #0xcd
	lsls r0, r0, #3
	adds r2, r3, r0
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r4, #0xa0
	lsls r4, r4, #1
	cmp r0, r4
	ble _081404E8
	ldr r0, _081404E4 @ =0x00000667
	adds r1, r3, r0
	movs r0, #0xff
	b _081404F4
	.align 2, 0
_081404E4: .4byte 0x00000667
_081404E8:
	ldr r4, _08140518 @ =0xFFFFFEC0
	cmp r0, r4
	bge _081404F8
	ldr r0, _0814051C @ =0x00000667
	adds r1, r3, r0
	movs r0, #1
_081404F4:
	strb r0, [r1]
	strh r4, [r2]
_081404F8:
	movs r1, #0xcd
	lsls r1, r1, #3
	adds r2, r3, r1
	subs r1, #1
	adds r0, r3, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08140518: .4byte 0xFFFFFEC0
_0814051C: .4byte 0x00000667

	thumb_func_start FUN_08140520
FUN_08140520: @ 0x08140520
	push {r4, lr}
	adds r4, r0, #0
	adds r4, #0x9c
	ldr r2, _08140574 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08140578 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0814057C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	ldrb r0, [r4, #2]
	cmp r1, r0
	bne _0814055A
	adds r0, r1, #1
	ldr r1, [r4, #4]
	ldrb r1, [r1]
	bl Mod
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
_0814055A:
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
_08140574: .4byte 0x030046B8
_08140578: .4byte 0x000003FF
_0814057C: .4byte 0x0203B400

	thumb_func_start FUN_08140580
FUN_08140580: @ 0x08140580
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	sub sp, #0x28
	mov r8, r0
	ldr r4, _08140604 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	movs r5, #0x20
	orrs r0, r5
	ldr r1, _08140608 @ =0x0000FFFF
	mov sb, r1
	ands r0, r1
	movs r1, #0xa4
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r4
	orrs r0, r5
	str r0, [sp, #0xc]
	movs r6, #0
	str r6, [sp, #0x10]
	add r2, sp, #0x10
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _0814060C @ =FUN_0813e944
	mov r0, r8
	str r0, [sp]
	add r1, sp, #8
	bl FUN_080e3834
	ldr r0, [sp, #0x18]
	ands r0, r4
	orrs r0, r5
	mov r1, sb
	ands r0, r1
	movs r1, #0xa8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r4
	orrs r0, r5
	str r0, [r1, #4]
	str r6, [sp, #0x20]
	add r2, sp, #0x20
	ldr r0, [r2, #4]
	ands r0, r4
	str r0, [r2, #4]
	ldr r3, _08140610 @ =FUN_0813e6c0
	str r6, [sp]
	mov r0, r8
	str r0, [sp, #4]
	bl FUN_080e3984
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08140604: .4byte 0xFFFF0000
_08140608: .4byte 0x0000FFFF
_0814060C: .4byte FUN_0813e944
_08140610: .4byte FUN_0813e6c0

	thumb_func_start FUN_08140614
FUN_08140614: @ 0x08140614
	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r3, [r0]
	ldr r4, _0814062C @ =0x00000664
	adds r0, r3, r4
	ldrh r0, [r0]
	cmp r0, #0
	blt _08140630
	asrs r0, r0, #7
	b _08140636
	.align 2, 0
_0814062C: .4byte 0x00000664
_08140630:
	rsbs r0, r0, #0
	asrs r0, r0, #7
	rsbs r0, r0, #0
_08140636:
	cmp r0, #0
	bge _0814063C
	rsbs r0, r0, #0
_0814063C:
	adds r2, r0, #0
	cmp r2, #7
	ble _08140644
	movs r2, #7
_08140644:
	movs r1, #8
	movs r4, #0xcb
	lsls r4, r4, #3
	adds r0, r3, r4
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08140658
	movs r0, #1
	b _0814065A
_08140658:
	movs r0, #0
_0814065A:
	cmp r0, #0
	bne _0814066C
	ldr r0, _08140668 @ =0x085AD7E4
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	b _08140676
	.align 2, 0
_08140668: .4byte 0x085AD7E4
_0814066C:
	ldr r0, _0814067C @ =0x085AD7E4
	lsls r1, r2, #2
	adds r1, r1, r0
	ldr r0, [r1]
	adds r0, #6
_08140676:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814067C: .4byte 0x085AD7E4

	thumb_func_start FUN_08140680
FUN_08140680: @ 0x08140680
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
	adds r2, r4, r3
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r0, _081406B4 @ =0x00000664
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081406B4: .4byte 0x00000664

	thumb_func_start FUN_081406b8
FUN_081406b8: @ 0x081406B8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x34
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	mov r8, r1
	movs r1, #0xd4
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #4]
	str r2, [sp, #8]
	movs r1, #0xd5
	lsls r1, r1, #3
	add r1, r8
	ldr r2, [r1, #4]
	ldr r1, [r1]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	ldr r2, _08140754 @ =0x0000FFFF
	ldr r1, [sp, #4]
	ands r1, r2
	str r1, [sp, #4]
	ldr r1, [sp, #0xc]
	ands r1, r2
	str r1, [sp, #0xc]
	ldr r1, _08140758 @ =0x00000664
	add r1, r8
	movs r3, #0xcd
	lsls r3, r3, #3
	add r3, r8
	ldr r5, _0814075C @ =0x000004A4
	adds r0, r0, r5
	ldr r0, [r0]
	adds r0, #0xc
	mov sb, r0
	add r7, sp, #4
	add r2, sp, #0xc
	ldrh r6, [r1]
	movs r1, #0
	ldrsh r0, [r3, r1]
	str r0, [sp, #0x24]
	add r4, sp, #0x14
	ldrh r0, [r2]
	ldrh r1, [r7]
	subs r0, r0, r1
	movs r3, #0
	strh r0, [r4]
	ldrh r0, [r2, #2]
	ldrh r1, [r7, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r7, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	add r5, sp, #0x1c
	str r3, [sp]
	mov r0, sp
	adds r1, r5, #0
	ldr r2, _08140760 @ =0x05000002
	bl CpuSet
	adds r0, r6, #0
	muls r0, r6, r0
	mov sl, r4
	mov ip, r5
	cmp r0, #0
	blt _08140764
	asrs r0, r0, #0xa
	b _0814076A
	.align 2, 0
_08140754: .4byte 0x0000FFFF
_08140758: .4byte 0x00000664
_0814075C: .4byte 0x000004A4
_08140760: .4byte 0x05000002
_08140764:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r0, r0, #0
_0814076A:
	adds r1, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	cmp r0, #0
	blt _08140778
	asrs r3, r0, #0xa
	b _0814077E
_08140778:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r3, r0, #0
_0814077E:
	lsls r2, r3, #1
	lsls r0, r1, #1
	adds r4, r0, r1
	subs r0, r3, r0
	adds r0, r0, r6
	ldr r5, [sp, #0x24]
	adds r3, r0, #0
	muls r3, r5, r3
	str r3, [sp, #0x30]
	subs r0, r2, r4
	adds r0, #1
	mov r6, ip
	movs r3, #0
	ldrsh r1, [r6, r3]
	adds r5, r0, #0
	muls r5, r1, r5
	subs r6, r4, r2
	mov r1, sl
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r5, [sp, #0x30]
	adds r0, r0, r5
	cmp r0, #0
	blt _081407B6
	asrs r1, r0, #0xa
	b _081407BC
_081407B6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081407BC:
	ldrh r0, [r7]
	adds r0, r0, r1
	mov r6, sb
	strh r0, [r6]
	subs r3, r2, r4
	adds r0, r3, #1
	str r0, [sp, #0x28]
	mov r1, ip
	movs r5, #2
	ldrsh r0, [r1, r5]
	ldr r6, [sp, #0x28]
	adds r5, r6, #0
	muls r5, r0, r5
	rsbs r2, r2, #0
	adds r0, r2, r4
	mov r1, sl
	movs r6, #2
	ldrsh r1, [r1, r6]
	adds r6, r0, #0
	adds r0, r1, #0
	muls r0, r6, r0
	adds r0, r5, r0
	ldr r1, [sp, #0x30]
	adds r0, r0, r1
	adds r0, #0
	cmp r0, #0
	blt _081407F6
	asrs r1, r0, #0xa
	b _081407FC
_081407F6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_081407FC:
	ldrh r0, [r7, #2]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #2]
	adds r1, r3, #1
	mov r6, ip
	movs r3, #4
	ldrsh r0, [r6, r3]
	adds r5, r1, #0
	muls r5, r0, r5
	adds r1, r2, r4
	mov r6, sl
	movs r2, #4
	ldrsh r0, [r6, r2]
	muls r0, r1, r0
	adds r0, r5, r0
	ldr r3, [sp, #0x30]
	adds r0, r0, r3
	adds r0, #0
	cmp r0, #0
	blt _0814082A
	asrs r1, r0, #0xa
	b _08140830
_0814082A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xa
	rsbs r1, r0, #0
_08140830:
	ldrh r0, [r7, #4]
	adds r0, r0, r1
	mov r5, sb
	strh r0, [r5, #4]
	ldr r3, _0814084C @ =0x00000664
	add r3, r8
	ldrh r4, [r3]
	ldr r2, _08140850 @ =0x000003FF
	cmp r4, r2
	bls _08140854
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
	b _08140882
	.align 2, 0
_0814084C: .4byte 0x00000664
_08140850: .4byte 0x000003FF
_08140854:
	ldr r1, _08140894 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r6, _08140898 @ =0x0203B400
	adds r0, r0, r6
	ldrb r0, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r2, #0
	adds r0, r0, r1
	adds r0, r4, r0
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #3
	cmp r0, r1
	bls _08140880
	strh r1, [r3]
_08140880:
	movs r0, #0
_08140882:
	add sp, #0x34
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08140894: .4byte 0x030046B8
_08140898: .4byte 0x0203B400

	thumb_func_start FUN_0814089c
FUN_0814089c: @ 0x0814089C
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xf
	movs r2, #2
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x10
	movs r2, #3
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #4
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0x12
	movs r2, #5
	movs r3, #0
	bl FUN_080ef84c
	adds r0, r4, #0
	movs r1, #0xa
	movs r2, #1
	movs r3, #0
	bl FUN_080ef84c
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_08140904
FUN_08140904: @ 0x08140904
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
	movs r2, #8
	rsbs r2, r2, #0
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	movs r2, #0x94
	lsls r2, r2, #1
	add r2, ip
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
	bx lr

	thumb_func_start FUN_08140940
FUN_08140940: @ 0x08140940
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
	ble _08140964
	movs r0, #8
	subs r0, r0, r1
	str r0, [r3]
	movs r0, #1
	b _08140968
_08140964:
	str r1, [r3]
	movs r0, #0
_08140968:
	str r0, [r2]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08140970
FUN_08140970: @ 0x08140970
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
	bl FUN_08140680
	adds r0, r4, #0
	bl FUN_081406b8
	movs r1, #1
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	ldr r3, _08140A08 @ =0x00000469
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
	ldr r2, _08140A0C @ =0x05000002
	bl CpuSet
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08140A08: .4byte 0x00000469
_08140A0C: .4byte 0x05000002

	thumb_func_start FUN_08140a10
FUN_08140a10: @ 0x08140A10
	push {r4, lr}
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r1, _08140A3C @ =0xFFFFFEFF
	ldrh r2, [r3]
	ands r1, r2
	movs r4, #0
	strh r1, [r3]
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r3, r0, r1
	ldr r2, _08140A40 @ =0xFBFFFFFF
	ldr r1, [r3]
	ands r1, r2
	str r1, [r3]
	ldr r1, _08140A44 @ =0x0000024E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08140A3C: .4byte 0xFFFFFEFF
_08140A40: .4byte 0xFBFFFFFF
_08140A44: .4byte 0x0000024E

	thumb_func_start FUN_08140a48
FUN_08140a48: @ 0x08140A48
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
	bne _08140A6C
	adds r2, #0xce
	adds r0, r5, r2
	strh r1, [r0]
	b _08140B28
_08140A6C:
	ldr r0, _08140A7C @ =0x0000024E
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08140A80
	subs r0, #1
	strh r0, [r1]
	b _08140B28
	.align 2, 0
_08140A7C: .4byte 0x0000024E
_08140A80:
	adds r0, r5, #0
	bl FUN_08140520
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
	blt _08140ABA
	cmp r1, #0
	blt _08140ABA
	ldr r0, _08140AC0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08140ABA
	ldr r0, _08140AC4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08140AC8
_08140ABA:
	movs r4, #0
	b _08140AD6
	.align 2, 0
_08140AC0: .4byte 0x030046A8
_08140AC4: .4byte 0x030046AC
_08140AC8:
	ldr r0, _08140AE8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08140AD6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08140AEC
	adds r0, #4
	b _08140AF8
	.align 2, 0
_08140AE8: .4byte 0x030046A4
_08140AEC:
	ldr r0, _08140B0C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08140AF8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08140B10
	cmp r2, #2
	beq _08140B14
	b _08140B18
	.align 2, 0
_08140B0C: .4byte 0x030046A4
_08140B10:
	ldrb r0, [r6, #4]
	b _08140B16
_08140B14:
	ldrb r0, [r6]
_08140B16:
	subs r1, r1, r0
_08140B18:
	strh r1, [r6, #2]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_08140970
	adds r0, r5, #0
	bl FUN_08140a10
_08140B28:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08140b30
FUN_08140b30: @ 0x08140B30
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	mov r4, sp
	adds r3, r5, #0
	adds r3, #8
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r0, [r5, #8]
	ldrh r1, [r2]
	adds r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r3, #2]
	ldrh r1, [r2, #2]
	adds r0, r0, r1
	strh r0, [r4, #2]
	ldrh r1, [r3, #4]
	ldrh r2, [r2, #4]
	adds r1, r1, r2
	strh r1, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _08140B80
	cmp r1, #0
	blt _08140B80
	ldr r0, _08140B84 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08140B80
	ldr r0, _08140B88 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08140B8C
_08140B80:
	movs r4, #0
	b _08140B9A
	.align 2, 0
_08140B84: .4byte 0x030046A8
_08140B88: .4byte 0x030046AC
_08140B8C:
	ldr r0, _08140BAC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_08140B9A:
	mov r6, sp
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08140BB0
	adds r0, #4
	b _08140BBC
	.align 2, 0
_08140BAC: .4byte 0x030046A4
_08140BB0:
	ldr r0, _08140BD0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08140BBC:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _08140BD4
	cmp r2, #2
	beq _08140BD8
	b _08140BDC
	.align 2, 0
_08140BD0: .4byte 0x030046A4
_08140BD4:
	ldrb r0, [r6, #4]
	b _08140BDA
_08140BD8:
	ldrb r0, [r6]
_08140BDA:
	subs r1, r1, r0
_08140BDC:
	ldr r2, _08140C10 @ =0x00000472
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, r1
	bge _08140C06
	movs r3, #0xe0
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0
	ldrsh r0, [r1, r2]
	rsbs r0, r0, #0
	movs r2, #0
	strh r0, [r1]
	adds r3, #4
	adds r1, r5, r3
	movs r3, #0
	ldrsh r0, [r1, r3]
	rsbs r0, r0, #0
	strh r0, [r1]
	strh r2, [r5, #0x10]
	strh r2, [r5, #0x14]
_08140C06:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08140C10: .4byte 0x00000472

	thumb_func_start FUN_08140c14
FUN_08140c14: @ 0x08140C14
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r4, [r0]
	ldr r2, _08140CC0 @ =0x00000666
	adds r0, r4, r2
	movs r6, #0
	strb r6, [r0]
	movs r0, #0xe0
	lsls r0, r0, #1
	adds r1, r5, r0
	str r6, [sp]
	mov r0, sp
	ldr r2, _08140CC4 @ =0x05000002
	bl CpuSet
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r4, r4, r1
	movs r1, #8
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
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
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	movs r3, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #2
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08140CC8 @ =0x0000046A
	adds r0, r5, r1
	strb r3, [r0]
	adds r2, #0x1b
	adds r0, r5, r2
	str r6, [r0]
	ldr r0, _08140CCC @ =0x0000046C
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_08013698
	ldr r0, _08140CD0 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r5, #0
	bl FUN_08140970
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08140CC0: .4byte 0x00000666
_08140CC4: .4byte 0x05000002
_08140CC8: .4byte 0x0000046A
_08140CCC: .4byte 0x0000046C
_08140CD0: .4byte 0x03002BE0

	thumb_func_start FUN_08140cd4
FUN_08140cd4: @ 0x08140CD4
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #8
	movs r1, #0xbc
	lsls r1, r1, #1
	adds r4, r3, r1
	ldr r1, [r4]
	ands r0, r1
	cmp r0, #0
	beq _08140D20
	movs r0, #9
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r4]
	movs r2, #0xa
	ldrsh r1, [r3, r2]
	ldr r0, _08140D24 @ =0x03002BE0
	ldr r0, [r0]
	movs r2, #0x2e
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _08140D04
	rsbs r1, r1, #0
_08140D04:
	movs r0, #0x80
	lsls r0, r0, #2
	cmp r1, r0
	bgt _08140D20
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r3, r1
	movs r2, #0xf6
	lsls r2, r2, #1
	adds r1, r3, r2
	ldr r2, [r0]
	ldr r0, [r1]
	cmp r2, r0
	blo _08140D28
_08140D20:
	movs r0, #0
	b _08140D42
	.align 2, 0
_08140D24: .4byte 0x03002BE0
_08140D28:
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
_08140D42:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08140d48
FUN_08140d48: @ 0x08140D48
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r2, #0x80
	lsls r2, r2, #0x13
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08140DC6
	adds r1, #0xcc
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #2
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r0, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _08140D88
	movs r0, #1
	b _08140D8A
_08140D88:
	movs r0, #0
_08140D8A:
	cmp r0, #0
	beq _08140DC6
	movs r0, #0x80
	lsls r0, r0, #1
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	movs r3, #0
	movs r4, #0
	orrs r0, r1
	strh r0, [r2]
	movs r1, #3
	movs r2, #0x8d
	lsls r2, r2, #3
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	strb r1, [r0]
	ldr r1, _08140DCC @ =0x00000484
	adds r0, r5, r1
	str r4, [r0]
	adds r2, #2
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_08140DC6:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08140DCC: .4byte 0x00000484

	thumb_func_start FUN_08140dd0
FUN_08140dd0: @ 0x08140DD0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r7, r0, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r1, #6
	bl Mod
	cmp r0, #0
	bne _08140E94
	ldrb r0, [r7, #5]
	adds r0, #0x20
	movs r3, #0xff
	mov r8, r3
	ands r0, r3
	lsrs r2, r0, #6
	adds r2, #2
	ldr r6, _08140E4C @ =0x0203B400
	ldr r5, _08140E50 @ =0x030046B8
	ldr r1, [r5]
	adds r1, #1
	ldr r4, _08140E54 @ =0x000003FF
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r3, [r0]
	lsls r2, r2, #0x1e
	asrs r2, r2, #0x18
	subs r2, #0x20
	movs r0, #0x3f
	ands r3, r0
	adds r2, r2, r3
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r1, #1
	ands r1, r4
	str r1, [r5]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r0, [r1]
	movs r1, #7
	ands r0, r1
	add r4, sp, #4
	adds r5, r0, #1
	ldr r1, _08140E58 @ =0x085B0A08
	adds r0, r2, #0
	adds r0, #0x40
	mov r3, r8
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r5, r0
	cmp r0, #0
	blt _08140E5C
	asrs r3, r0, #0xc
	b _08140E62
	.align 2, 0
_08140E4C: .4byte 0x0203B400
_08140E50: .4byte 0x030046B8
_08140E54: .4byte 0x000003FF
_08140E58: .4byte 0x085B0A08
_08140E5C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08140E62:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r2, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08140E7A
	asrs r0, r0, #0xc
	b _08140E80
_08140E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08140E80:
	strh r0, [r4, #4]
	adds r0, r7, #0
	adds r0, #8
	movs r1, #1
	str r1, [sp]
	add r1, sp, #4
	movs r2, #0x28
	movs r3, #2
	bl FUN_081f9f4c
_08140E94:
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08140ea0
FUN_08140ea0: @ 0x08140EA0
	push {lr}
	bl FUN_0814031c
	movs r0, #1
	pop {r1}
	bx r1

	thumb_func_start FUN_08140eac
FUN_08140eac: @ 0x08140EAC
	movs r0, #1
	bx lr

	thumb_func_start FUN_08140eb0
FUN_08140eb0: @ 0x08140EB0
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
	bl FUN_081404c0
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
	bl FUN_0823785c
	strb r0, [r6, #5]
	ldr r2, _08140FAC @ =0x085B0A08
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
_08140FAC: .4byte 0x085B0A08
_08140FB0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08140FB6:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r1, _08140FD4 @ =0x085B0A08
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
_08140FD4: .4byte 0x085B0A08
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
	ldr r1, _0814103C @ =0x085B0A08
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
_0814103C: .4byte 0x085B0A08
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
	bl FUN_08140970
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

	thumb_func_start FUN_081410cc
FUN_081410cc: @ 0x081410CC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r6, r0, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r7, [r0]
	ldr r2, _081410EC @ =0x0000046C
	adds r1, r6, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _081410F0
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _081410F2
	.align 2, 0
_081410EC: .4byte 0x0000046C
_081410F0:
	movs r0, #0
_081410F2:
	cmp r0, #0
	bne _081410F8
	b _0814120A
_081410F8:
	ldr r2, _08141170 @ =FUN_0813f06c
	movs r1, #0x23
	ldr r3, _08141174 @ =0x0000046D
	adds r0, r6, r3
	movs r4, #0
	movs r5, #1
	strb r5, [r0]
	subs r3, #2
	adds r0, r6, r3
	strb r4, [r0]
	adds r3, #0xe8
	adds r0, r6, r3
	strb r1, [r0]
	movs r1, #0xaf
	lsls r1, r1, #3
	adds r0, r6, r1
	str r2, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	movs r3, #0xd6
	lsls r3, r3, #3
	adds r1, r7, r3
	str r4, [sp]
	mov r0, sp
	ldr r2, _08141178 @ =0x05000002
	bl CpuSet
	ldr r1, _0814117C @ =0x00000667
	adds r0, r7, r1
	strb r5, [r0]
	ldr r2, _08141180 @ =0x0000066C
	adds r0, r7, r2
	strh r4, [r0]
	ldr r2, _08141184 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08141188 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _0814118C @ =0x0203B400
	adds r0, r0, r3
	ldrb r4, [r0]
	ldr r0, _08141190 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r1, _08141194 @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08141198
	asrs r0, r0, #3
	b _0814119E
	.align 2, 0
_08141170: .4byte FUN_0813f06c
_08141174: .4byte 0x0000046D
_08141178: .4byte 0x05000002
_0814117C: .4byte 0x00000667
_08141180: .4byte 0x0000066C
_08141184: .4byte 0x030046B8
_08141188: .4byte 0x000003FF
_0814118C: .4byte 0x0203B400
_08141190: .4byte 0x03002BE0
_08141194: .4byte 0x085B0A08
_08141198:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_0814119E:
	add r3, sp, #4
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081411CC @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	ldr r2, _081411D0 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _081411D4
	asrs r0, r0, #3
	b _081411DA
	.align 2, 0
_081411CC: .4byte 0xFFFF0000
_081411D0: .4byte 0x085B0A08
_081411D4:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_081411DA:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0814123C @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	adds r0, r6, #0
	adds r1, r3, #0
	bl FUN_08140680
	adds r0, r6, #0
	bl FUN_081406b8
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r2, r7, r3
	movs r1, #9
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_0814120A:
	ldr r0, _08141240 @ =0x0000066C
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _08141248
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	beq _08141220
	b _081413F4
_08141220:
	ldr r0, _08141244 @ =0x03002BE0
	ldr r1, [r0]
	adds r1, #0x2c
	adds r0, r6, #0
	bl FUN_08140970
	movs r2, #8
	movs r3, #0xcb
	lsls r3, r3, #3
	adds r1, r7, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _081413F4
	.align 2, 0
_0814123C: .4byte 0xFFFF0000
_08141240: .4byte 0x0000066C
_08141244: .4byte 0x03002BE0
_08141248:
	adds r0, r6, #0
	bl FUN_081404c0
	movs r1, #0xb1
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	adds r4, r0, #0
	ldr r2, _08141298 @ =0x000004A4
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
	bge _08141280
	rsbs r2, r2, #0
_08141280:
	lsls r1, r0, #0x10
	cmp r2, #0x20
	bgt _0814129C
	asrs r2, r1, #0x10
	cmp r2, #0
	bge _0814128E
	rsbs r2, r2, #0
_0814128E:
	cmp r2, #0x20
	bgt _0814129C
	movs r0, #1
	b _08141306
	.align 2, 0
_08141298: .4byte 0x000004A4
_0814129C:
	lsls r0, r3, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0
	bne _081412A8
	cmp r1, #0
	beq _08141304
_081412A8:
	asrs r1, r1, #0x10
	bl FUN_0823785c
	strb r0, [r6, #5]
	ldr r2, _081412CC @ =0x085B0A08
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
	blt _081412D0
	asrs r1, r0, #0xc
	b _081412D6
	.align 2, 0
_081412CC: .4byte 0x085B0A08
_081412D0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081412D6:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r1
	strh r0, [r6, #0x10]
	ldr r1, _081412F4 @ =0x085B0A08
	ldrb r0, [r6, #5]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _081412F8
	asrs r1, r0, #0xc
	b _081412FE
	.align 2, 0
_081412F4: .4byte 0x085B0A08
_081412F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_081412FE:
	ldrh r0, [r6, #0x14]
	adds r0, r0, r1
	strh r0, [r6, #0x14]
_08141304:
	movs r0, #0
_08141306:
	cmp r0, #0
	beq _081413BE
	adds r0, r6, #0
	bl FUN_081406b8
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081413BE
	ldr r2, _0814134C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08141350 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _08141354 @ =0x0203B400
	adds r0, r0, r2
	ldrb r4, [r0]
	ldr r0, _08141358 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r1, _0814135C @ =0x085B0A08
	lsls r0, r4, #1
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r5, r1, #0
	cmp r0, #0
	blt _08141360
	asrs r0, r0, #3
	b _08141366
	.align 2, 0
_0814134C: .4byte 0x030046B8
_08141350: .4byte 0x000003FF
_08141354: .4byte 0x0203B400
_08141358: .4byte 0x03002BE0
_0814135C: .4byte 0x085B0A08
_08141360:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_08141366:
	add r3, sp, #0xc
	ldrh r1, [r3]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _08141394 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	blt _08141398
	asrs r1, r0, #3
	b _0814139E
	.align 2, 0
_08141394: .4byte 0xFFFF0000
_08141398:
	rsbs r0, r0, #0
	asrs r0, r0, #3
	rsbs r1, r0, #0
_0814139E:
	ldrh r0, [r3, #4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _081413E8 @ =0xFFFF0000
	ldr r1, [r3, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [r3, #4]
	adds r0, r6, #0
	adds r1, r3, #0
	bl FUN_08140680
	adds r0, r6, #0
	bl FUN_081406b8
_081413BE:
	movs r2, #0xf2
	lsls r2, r2, #1
	adds r0, r6, r2
	ldr r1, [r0]
	ldr r0, _081413EC @ =0x0000FDE8
	cmp r1, r0
	bls _081413F4
	adds r0, r6, #0
	bl FUN_08140904
	movs r3, #0xfe
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrb r0, [r0]
	strb r0, [r6, #5]
	ldr r0, _081413F0 @ =0x0000066C
	adds r1, r7, r0
	movs r0, #0x1e
	strh r0, [r1]
	b _0814143A
	.align 2, 0
_081413E8: .4byte 0xFFFF0000
_081413EC: .4byte 0x0000FDE8
_081413F0: .4byte 0x0000066C
_081413F4:
	ldr r1, _08141428 @ =0x0000046B
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08141430
	movs r2, #4
	movs r3, #0x8d
	lsls r3, r3, #3
	adds r0, r6, r3
	movs r1, #0
	strb r1, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r1, [r0]
	adds r3, #1
	adds r0, r6, r3
	strb r2, [r0]
	ldr r2, _0814142C @ =0x00000484
	adds r0, r6, r2
	str r1, [r0]
	adds r3, #2
	adds r1, r6, r3
	movs r0, #1
	strb r0, [r1]
	b _0814143A
	.align 2, 0
_08141428: .4byte 0x0000046B
_0814142C: .4byte 0x00000484
_08141430:
	ldr r0, _08141444 @ =0x00000484
	adds r1, r6, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
_0814143A:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08141444: .4byte 0x00000484

	thumb_func_start FUN_08141448
FUN_08141448: @ 0x08141448
	ldr r1, _08141454 @ =0x0000063C
	adds r0, r0, r1
	ldr r1, _08141458 @ =0x085AD804
	str r1, [r0]
	bx lr
	.align 2, 0
_08141454: .4byte 0x0000063C
_08141458: .4byte 0x085AD804

	thumb_func_start FUN_0814145c
FUN_0814145c: @ 0x0814145C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_08140ea0
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrb r0, [r0]
	ldr r2, _0814148C @ =0x0000062C
	adds r1, r4, r2
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080e4964
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0814148C: .4byte 0x0000062C

	thumb_func_start FUN_08141490
FUN_08141490: @ 0x08141490
	push {lr}
	movs r1, #0xec
	lsls r1, r1, #1
	adds r2, r0, r1
	ldr r1, _081414AC @ =0x03002BE0
	ldr r1, [r1]
	adds r1, #0x24
	str r1, [r2]
	bl FUN_080f06b0
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_081414AC: .4byte 0x03002BE0

	thumb_func_start EnemyBat_Destroy
EnemyBat_Destroy: @ 0x081414B0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _081414C8 @ =0x0000025D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _081414CC
	ldr r0, [r4, #0x44]
	bl FUN_0822a4e0
	b _081414D4
	.align 2, 0
_081414C8: .4byte 0x0000025D
_081414CC:
	ldr r0, [r4, #0x44]
	adds r0, #0x20
	bl FUN_0822f1c0
_081414D4:
	ldr r0, [r4, #0x44]
	bl Free
	movs r2, #0x80
	lsls r2, r2, #1
	ldr r0, _081414F0 @ =0x00000474
	adds r1, r4, r0
	ldrh r0, [r1]
	ands r0, r2
	adds r6, r1, #0
	cmp r0, #0
	beq _081414F4
	movs r0, #1
	b _081414F6
	.align 2, 0
_081414F0: .4byte 0x00000474
_081414F4:
	movs r0, #0
_081414F6:
	cmp r0, #0
	beq _08141502
	adds r0, r4, #0
	adds r0, #0x48
	bl FUN_08022428
_08141502:
	ldr r1, _0814155C @ =0x0000044C
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	bne _0814151A
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	bl FUN_080138fc
	movs r0, #1
	strb r0, [r5]
_0814151A:
	ldr r0, _08141560 @ =0x0000044D
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	bne _08141532
	movs r1, #0xc5
	lsls r1, r1, #2
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #1
	strb r0, [r5]
_08141532:
	movs r1, #0x80
	lsls r1, r1, #0x12
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _0814154A
	adds r0, r4, #0
	bl FUN_08002a58
_0814154A:
	movs r1, #0x80
	lsls r1, r1, #2
	ldrh r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _08141564
	movs r0, #1
	b _08141566
	.align 2, 0
_0814155C: .4byte 0x0000044C
_08141560: .4byte 0x0000044D
_08141564:
	movs r0, #0
_08141566:
	cmp r0, #0
	beq _08141572
	adds r0, r4, #0
	adds r0, #0x7c
	bl FUN_0807f598
_08141572:
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

