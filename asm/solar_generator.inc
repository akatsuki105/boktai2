	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080b283c
FUN_080b283c: @ 0x080B283C
	push {lr}
	adds r3, r0, #0
	movs r0, #0xcf
	adds r0, r0, r3
	mov ip, r0
	movs r2, #0
	strb r1, [r0]
	adds r0, r3, #0
	adds r0, #0xd0
	strh r2, [r0]
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r2, r3, r1
	ldr r1, _080B2874 @ =0x085AD0B8
	mov r3, ip
	ldrb r0, [r3]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	ldrb r0, [r3]
	cmp r0, #3
	bne _080B2878
	movs r0, #0xfb
	bl PlaySound_082406e0
	b _080B2882
	.align 2, 0
_080B2874: .4byte 0x085AD0B8
_080B2878:
	cmp r0, #5
	bne _080B2882
	movs r0, #0xfc
	bl PlaySound_082406e0
_080B2882:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b2888
FUN_080b2888: @ 0x080B2888
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r0, [r4, #0x60]
	ldr r1, [r4, #0x64]
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0xed
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080B28EC @ =0x0203B400
	mov r8, r0
	ldr r5, _080B28F0 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080B28F4 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	ldrh r1, [r4, #0x34]
	subs r1, #5
	adds r1, r1, r0
	strh r1, [r4, #0x34]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0xa
	bl Mod
	ldrh r1, [r4, #0x38]
	subs r1, #5
	adds r1, r1, r0
	strh r1, [r4, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B28EC: .4byte 0x0203B400
_080B28F0: .4byte 0x030046B8
_080B28F4: .4byte 0x000003FF

	thumb_func_start FUN_080b28f8
FUN_080b28f8: @ 0x080B28F8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	ldr r6, _080B2998 @ =0x03002BE0
	ldr r3, [r6]
	movs r1, #0x2c
	ldrsh r2, [r3, r1]
	adds r7, r0, #0
	adds r7, #0x60
	movs r4, #0
	ldrsh r1, [r7, r4]
	subs r2, r2, r1
	movs r5, #0x30
	ldrsh r1, [r3, r5]
	adds r0, #0x64
	mov r8, r0
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r3, r1, r0
	adds r0, r2, #0
	cmp r2, #0
	bge _080B2926
	rsbs r0, r2, #0
_080B2926:
	cmp r0, #0x7f
	bgt _080B298C
	adds r0, r3, #0
	cmp r3, #0
	bge _080B2932
	rsbs r0, r3, #0
_080B2932:
	cmp r0, #0x7f
	bgt _080B298C
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r0, r1
	ldr r1, _080B299C @ =0x00003FFF
	cmp r0, r1
	bgt _080B298C
	adds r0, r2, #0
	adds r1, r3, #0
	bl FUN_0823785c
	ldr r4, [r6]
	mov ip, r4
	ldr r4, _080B29A0 @ =0x085B0A08
	adds r1, r0, #0
	adds r1, #0x40
	movs r3, #0xff
	ands r1, r3
	lsls r1, r1, #1
	adds r1, r1, r4
	movs r5, #0
	ldrsh r2, [r1, r5]
	lsls r1, r2, #6
	adds r1, r1, r2
	asrs r1, r1, #0xb
	ldrh r7, [r7]
	adds r1, r1, r7
	mov r2, ip
	strh r1, [r2, #0x2c]
	ldr r2, [r6]
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #6
	adds r0, r0, r1
	asrs r0, r0, #0xb
	mov r4, r8
	ldrh r4, [r4]
	adds r0, r0, r4
	strh r0, [r2, #0x30]
_080B298C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B2998: .4byte 0x03002BE0
_080B299C: .4byte 0x00003FFF
_080B29A0: .4byte 0x085B0A08

	thumb_func_start FUN_080b29a4
FUN_080b29a4: @ 0x080B29A4
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r4, r1, #0
	movs r1, #0x7f
	ldr r0, [r3, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080B2A0A
	adds r1, r2, #0
	adds r5, r1, #0
	adds r5, #0xe0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080B2A0A
	adds r0, r1, #0
	adds r0, #0xcf
	ldrb r0, [r0]
	cmp r0, #2
	bne _080B2A0A
	ldrh r1, [r3, #0x3c]
	ldrh r0, [r4, #0x3c]
	subs r1, r1, r0
	cmp r1, #0
	bge _080B29D6
	movs r1, #1
_080B29D6:
	adds r3, r2, #0
	adds r3, #0xeb
	movs r0, #4
	strb r0, [r3]
	subs r3, #0x19
	ldrh r0, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	adds r1, r2, #0
	adds r1, #0xd4
	ldrh r1, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r1
	blo _080B2A00
	strh r1, [r3]
	adds r0, r2, #0
	movs r1, #3
	bl FUN_080b283c
	b _080B2A0A
_080B2A00:
	movs r0, #0xc
	strh r0, [r5]
	ldr r0, _080B2A10 @ =0x00000127
	bl PlaySound_082406e0
_080B2A0A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080B2A10: .4byte 0x00000127

	thumb_func_start FUN_080b2a14
FUN_080b2a14: @ 0x080B2A14
	bx lr
	.align 2, 0

	thumb_func_start FUN_080b2a18
FUN_080b2a18: @ 0x080B2A18
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r1, r5, #0
	adds r1, #0xdc
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B2A2E
	subs r0, #1
	strh r0, [r1]
	b _080B2B60
_080B2A2E:
	ldr r0, [r5, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x18]
	adds r2, r5, #0
	adds r2, #0x6e
	ldrh r1, [r2]
	ldr r0, _080B2A94 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r0, #2
	strb r0, [r5, #0x1f]
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080B2A98
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2AA0
	.align 2, 0
_080B2A94: .4byte 0x0000FFFB
_080B2A98:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2AA0:
	str r0, [r5, #0x18]
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
	beq _080B2AC4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2ACC
_080B2AC4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2ACC:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2B04 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2B4A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2B0E
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2B08
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B2B24
	.align 2, 0
_080B2B04: .4byte 0x0000FFFF
_080B2B08:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2B22
_080B2B0E:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2B22
	strh r1, [r4, #8]
	movs r2, #1
	b _080B2B24
_080B2B22:
	movs r2, #0
_080B2B24:
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
	bne _080B2B4C
	movs r0, #1
	strb r0, [r4, #7]
	b _080B2B4C
_080B2B4A:
	movs r2, #0
_080B2B4C:
	cmp r2, #0
	beq _080B2B60
	adds r0, r5, #0
	adds r0, #0x68
	bl FUN_08236400
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b283c
_080B2B60:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b2b68
FUN_080b2b68: @ 0x080B2B68
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xb8
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B2BB8
	ldr r0, [r6, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2BC0
_080B2BB8:
	ldr r0, [r6, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2BC0:
	str r0, [r6, #0x18]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B2BE4
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2BEC
_080B2BE4:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2BEC:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2C24 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2C5C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2C28
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2C1C
	ldrb r0, [r4, #5]
_080B2C1C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2C38
	.align 2, 0
_080B2C24: .4byte 0x0000FFFF
_080B2C28:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2C38
	strh r1, [r4, #8]
_080B2C38:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _080B2C5C
	movs r0, #1
	strb r0, [r4, #7]
_080B2C5C:
	adds r1, r6, #0
	adds r1, #0xee
	ldr r0, _080B2C6C @ =0x000001C3
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080B2C6C: .4byte 0x000001C3

	thumb_func_start FUN_080b2c70
FUN_080b2c70: @ 0x080B2C70
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0xce
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2CB0
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #5
	bne _080B2C92
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #0
	beq _080B2CC4
_080B2C92:
	ldrh r0, [r2]
	cmp r0, #5
	bls _080B2CCE
	adds r0, r5, #0
	adds r0, #0xea
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2CC4
	adds r1, r5, #0
	adds r1, #0xee
	ldr r0, _080B2CAC @ =0x000001C5
	b _080B2CCC
	.align 2, 0
_080B2CAC: .4byte 0x000001C5
_080B2CB0:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	cmp r0, #5
	bne _080B2CCE
	adds r0, r5, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B2CCE
_080B2CC4:
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #0xe2
	lsls r0, r0, #1
_080B2CCC:
	strh r0, [r1]
_080B2CCE:
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080B2D1A
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2D22
_080B2D1A:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2D22:
	str r0, [r5, #0x18]
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
	beq _080B2D46
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2D4E
_080B2D46:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2D4E:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2D88 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2DCE
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2D92
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2D8C
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B2DA8
	.align 2, 0
_080B2D88: .4byte 0x0000FFFF
_080B2D8C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2DA6
_080B2D92:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2DA6
	strh r1, [r4, #8]
	movs r2, #1
	b _080B2DA8
_080B2DA6:
	movs r2, #0
_080B2DA8:
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
	bne _080B2DD0
	movs r0, #1
	strb r0, [r4, #7]
	b _080B2DD0
_080B2DCE:
	movs r2, #0
_080B2DD0:
	cmp r2, #0
	beq _080B2DE4
	adds r1, r5, #0
	adds r1, #0xec
	movs r0, #1
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080b283c
_080B2DE4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b2dec
FUN_080b2dec: @ 0x080B2DEC
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0xb8
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r7, r6, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B2E3C
	ldr r0, [r6, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2E44
_080B2E3C:
	ldr r0, [r6, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2E44:
	str r0, [r6, #0x18]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080B2E68
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2E70
_080B2E68:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2E70:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B2EA8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B2EE0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B2EAC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B2EA0
	ldrb r0, [r4, #5]
_080B2EA0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B2EBC
	.align 2, 0
_080B2EA8: .4byte 0x0000FFFF
_080B2EAC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B2EBC
	strh r1, [r4, #8]
_080B2EBC:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
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
	bne _080B2EE0
	movs r0, #1
	strb r0, [r4, #7]
_080B2EE0:
	adds r0, r6, #0
	adds r0, #0xea
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B2EF8
	adds r1, r6, #0
	adds r1, #0xee
	ldr r0, _080B2EF4 @ =0x000001C5
	b _080B2F00
	.align 2, 0
_080B2EF4: .4byte 0x000001C5
_080B2EF8:
	adds r1, r6, #0
	adds r1, #0xee
	movs r0, #0xe2
	lsls r0, r0, #1
_080B2F00:
	strh r0, [r1]
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b2f0c
FUN_080b2f0c: @ 0x080B2F0C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r0, #0xce
	ldrb r0, [r0]
	cmp r0, #0
	bne _080B2F1C
	b _080B3076
_080B2F1C:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r1, [r0]
	adds r2, r0, #0
	cmp r1, #5
	bne _080B2F3A
	adds r0, #6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B2F3A
	adds r1, r5, #0
	adds r1, #0xee
	movs r0, #0xe2
	lsls r0, r0, #1
	b _080B2F50
_080B2F3A:
	ldrh r0, [r2]
	cmp r0, #6
	bne _080B2F52
	adds r0, r5, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B2F52
	adds r1, r5, #0
	adds r1, #0xee
	ldr r0, _080B2FA0 @ =0x000001C3
_080B2F50:
	strh r0, [r1]
_080B2F52:
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080B2FA4
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B2FAC
	.align 2, 0
_080B2FA0: .4byte 0x000001C3
_080B2FA4:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B2FAC:
	str r0, [r5, #0x18]
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
	beq _080B2FD0
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B2FD8
_080B2FD0:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B2FD8:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3010 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B3056
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B301A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3014
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B3030
	.align 2, 0
_080B3010: .4byte 0x0000FFFF
_080B3014:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B302E
_080B301A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B302E
	strh r1, [r4, #8]
	movs r2, #1
	b _080B3030
_080B302E:
	movs r2, #0
_080B3030:
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
	bne _080B3058
	movs r0, #1
	strb r0, [r4, #7]
	b _080B3058
_080B3056:
	movs r2, #0
_080B3058:
	cmp r2, #0
	bne _080B305E
	b _080B31AC
_080B305E:
	adds r1, r5, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	adds r1, #0xc
	movs r0, #0x5a
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080b283c
	b _080B31AC
_080B3076:
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	cmp r0, #5
	bne _080B3092
	adds r0, r5, #0
	adds r0, #0xc6
	ldrh r0, [r0]
	cmp r0, #0
	bne _080B3092
	adds r1, r5, #0
	adds r1, #0xee
	ldr r0, _080B30E0 @ =0x000001C3
	strh r0, [r1]
_080B3092:
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, r5, #0
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080B30E4
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B30EC
	.align 2, 0
_080B30E0: .4byte 0x000001C3
_080B30E4:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B30EC:
	str r0, [r5, #0x18]
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
	beq _080B3110
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B3118
_080B3110:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B3118:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3150 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B3196
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B315A
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3154
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080B3170
	.align 2, 0
_080B3150: .4byte 0x0000FFFF
_080B3154:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B316E
_080B315A:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B316E
	strh r1, [r4, #8]
	movs r2, #1
	b _080B3170
_080B316E:
	movs r2, #0
_080B3170:
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
	bne _080B3198
	movs r0, #1
	strb r0, [r4, #7]
	b _080B3198
_080B3196:
	movs r2, #0
_080B3198:
	cmp r2, #0
	beq _080B31AC
	adds r1, r5, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b283c
_080B31AC:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080b31b4
FUN_080b31b4: @ 0x080B31B4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xb8
	adds r0, #0xc8
	ldr r1, [r0]
	adds r0, #4
	ldrb r3, [r0]
	adds r0, #1
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r7, r5, #0
	adds r7, #0x18
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r7, #0x10]
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
	beq _080B3204
	ldr r0, [r5, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B320C
_080B3204:
	ldr r0, [r5, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B320C:
	str r0, [r5, #0x18]
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
	beq _080B3230
	ldr r0, [r7]
	movs r1, #8
	orrs r0, r1
	b _080B3238
_080B3230:
	ldr r0, [r7]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080B3238:
	str r0, [r7]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3270 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B32A8
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3274
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B3268
	ldrb r0, [r4, #5]
_080B3268:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3284
	.align 2, 0
_080B3270: .4byte 0x0000FFFF
_080B3274:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3284
	strh r1, [r4, #8]
_080B3284:
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
	bne _080B32A8
	movs r0, #1
	strb r0, [r4, #7]
_080B32A8:
	adds r1, r5, #0
	adds r1, #0xde
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080B32D0
	adds r1, #0xf
	movs r0, #0
	strb r0, [r1]
	ldr r0, [r5, #0x60]
	ldr r1, [r5, #0x64]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080b283c
	b _080B32D6
_080B32D0:
	adds r0, r5, #0
	bl FUN_080b2888
_080B32D6:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b32e0
FUN_080b32e0: @ 0x080B32E0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xf9
	ldrb r0, [r1]
	cmp r0, #0
	beq _080B32F2
	subs r0, #1
	strb r0, [r1]
_080B32F2:
	adds r2, r4, #0
	adds r2, #0xf2
	ldrh r6, [r2]
	cmp r6, #0
	bne _080B3354
	adds r5, r4, #0
	adds r5, #0xd0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080B3310
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08246790
_080B3310:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080B3344
	ldr r0, [r4, #0x60]
	ldr r1, [r4, #0x64]
	str r0, [r4, #0x34]
	str r1, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0xee
	ldr r0, _080B3340 @ =0x000001C5
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080b283c
	adds r0, r4, #0
	adds r0, #0xa6
	strh r6, [r0]
	strh r6, [r5]
	b _080B3384
	.align 2, 0
_080B3340: .4byte 0x000001C5
_080B3344:
	adds r0, r4, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	subs r0, #1
	adds r1, r4, #0
	adds r1, #0xee
	strh r0, [r1]
	b _080B3384
_080B3354:
	adds r0, r4, #0
	adds r0, #0xf0
	ldrh r0, [r0]
	adds r1, r4, #0
	adds r1, #0xee
	strh r0, [r1]
	ldrh r0, [r2]
	subs r0, #1
	strh r0, [r2]
	adds r5, r4, #0
	adds r5, #0xf4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r1, [r5]
	cmp r0, r1
	bhs _080B3384
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_082466ec
	ldrh r0, [r5]
	subs r0, #0xfa
	strh r0, [r5]
_080B3384:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080b338c
FUN_080b338c: @ 0x080B338C
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r2, #0
	adds r4, #0xe2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080B33B0
	adds r0, r2, #0
	adds r0, #0xe4
	ldrh r3, [r0]
	adds r1, r0, #0
	cmp r3, #0xb
	bhi _080B33AA
	adds r0, r3, #1
	strh r0, [r1]
_080B33AA:
	movs r0, #0
	strh r0, [r4]
	b _080B33C0
_080B33B0:
	adds r0, r2, #0
	adds r0, #0xe4
	ldrh r3, [r0]
	adds r1, r0, #0
	cmp r3, #0
	beq _080B33C0
	subs r0, r3, #1
	strh r0, [r1]
_080B33C0:
	ldrh r0, [r1]
	cmp r0, #0xc
	bne _080B33D8
	adds r0, r2, #0
	adds r0, #0x44
	ldr r1, _080B33D4 @ =0x000001C7
	bl FUN_0822b20c
	b _080B3416
	.align 2, 0
_080B33D4: .4byte 0x000001C7
_080B33D8:
	cmp r0, #0
	beq _080B33EA
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0xe3
	lsls r1, r1, #1
	bl FUN_0822b20c
	b _080B3416
_080B33EA:
	adds r4, r2, #0
	adds r4, #0xeb
	ldrb r0, [r4]
	cmp r0, #0
	beq _080B3408
	adds r0, r2, #0
	adds r0, #0x44
	movs r1, #0x99
	lsls r1, r1, #1
	bl FUN_0822b20c
	ldrb r0, [r4]
	subs r0, #1
	strb r0, [r4]
	b _080B3416
_080B3408:
	adds r0, r2, #0
	adds r0, #0x44
	adds r1, r2, #0
	adds r1, #0xee
	ldrh r1, [r1]
	bl FUN_0822b20c
_080B3416:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start Entity080b3898_Update
Entity080b3898_Update: @ 0x080B341C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xcf
	ldrb r0, [r5]
	cmp r0, #0
	beq _080B3430
	adds r0, r4, #0
	bl FUN_080b28f8
_080B3430:
	adds r1, r4, #0
	adds r1, #0xda
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B343E
	subs r0, #1
	strh r0, [r1]
_080B343E:
	adds r1, r4, #0
	adds r1, #0xe0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080B344C
	subs r0, #1
	strh r0, [r1]
_080B344C:
	movs r1, #0x8e
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080b338c
	adds r2, r4, #0
	adds r2, #0xe8
	ldrh r0, [r2]
	cmp r0, #0
	beq _080B3496
	ldr r0, _080B3484 @ =0x03002C58
	ldr r0, [r0]
	movs r1, #0xc1
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080B3494
	ldrb r0, [r5]
	cmp r0, #4
	beq _080B3488
	movs r0, #0
	b _080B3494
	.align 2, 0
_080B3484: .4byte 0x03002C58
_080B3488:
	adds r1, r4, #0
	adds r1, #0xa6
	movs r0, #0
	strh r0, [r1]
	ldrh r0, [r2]
	subs r0, #1
_080B3494:
	strh r0, [r2]
_080B3496:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080b3898_Destroy
Entity080b3898_Destroy: @ 0x080B34A0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl FUN_0822a4e0
	adds r0, r4, #0
	adds r0, #0x68
	bl FUN_08236424
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r4, r1
	bl FUN_08247504
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080b34c4
FUN_080b34c4: @ 0x080B34C4
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r1, #0
	adds r4, r5, #0
	adds r4, #0x68
	ldr r2, _080B3538 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _080B353C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080B3540 @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	movs r3, #0
	bl FUN_08236514
	adds r1, r5, #0
	adds r1, #0x60
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _080B3544 @ =FUN_080b29a4
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_0823651c
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080B3538: .4byte 0xFFFF0000
_080B353C: .4byte 0x0000FFFF
_080B3540: .4byte 0x00004001
_080B3544: .4byte FUN_080b29a4

	thumb_func_start Entity080b3898_Init
Entity080b3898_Init: @ 0x080B3548
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r4, [sp, #0x2c]
	ldr r6, [sp, #0x30]
	ldr r0, [r1]
	ldr r1, [r1, #4]
	str r0, [r7, #0x60]
	str r1, [r7, #0x64]
	adds r0, r7, #0
	adds r0, #0xce
	strb r4, [r0]
	movs r0, #0xcc
	adds r0, r0, r7
	mov sl, r0
	strb r2, [r0]
	adds r1, r7, #0
	adds r1, #0xcd
	str r1, [sp, #4]
	strb r3, [r1]
	adds r0, r7, #0
	adds r0, #0xdc
	mov r2, sp
	ldrh r2, [r2, #0x38]
	strh r2, [r0]
	movs r0, #0xd4
	adds r0, r0, r7
	mov r8, r0
	strh r6, [r0]
	ldrh r0, [r0]
	movs r1, #6
	bl Div
	adds r1, r7, #0
	adds r1, #0xd8
	strh r0, [r1]
	movs r1, #0x18
	adds r1, r1, r7
	mov sb, r1
	adds r4, r7, #0
	adds r4, #0x44
	ldr r1, _080B35F8 @ =0x0000C038
	adds r0, r4, #0
	bl Video_GetActorSprite
	mov r0, sb
	adds r1, r4, #0
	movs r2, #0
	bl FUN_0822a470
	ldr r0, [r7, #0x60]
	ldr r1, [r7, #0x64]
	mov r2, sb
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, _080B35FC @ =0x0000922E
	ldr r1, _080B3600 @ =0x00003449
	bl GetFile
	adds r6, r7, #0
	adds r6, #0xc8
	str r0, [r6]
	adds r0, r7, #0
	ldr r1, [sp, #0x34]
	bl FUN_080b34c4
	adds r0, r7, #0
	ldr r1, [sp, #0x28]
	bl FUN_080b283c
	adds r0, r7, #0
	adds r0, #0xcf
	ldrb r5, [r0]
	cmp r5, #2
	beq _080B3634
	cmp r5, #2
	bgt _080B3604
	cmp r5, #0
	beq _080B3612
	movs r0, #0xee
	adds r0, r0, r7
	mov r8, r0
	b _080B3854
	.align 2, 0
_080B35F8: .4byte 0x0000C038
_080B35FC: .4byte 0x0000922E
_080B3600: .4byte 0x00003449
_080B3604:
	cmp r5, #4
	bne _080B360A
	b _080B3746
_080B360A:
	movs r1, #0xee
	adds r1, r1, r7
	mov r8, r1
	b _080B3854
_080B3612:
	adds r0, r7, #0
	adds r0, #0xd2
	strh r5, [r0]
	adds r2, r7, #0
	adds r2, #0xee
	ldr r0, _080B3630 @ =0x000001C3
	strh r0, [r2]
	movs r0, #3
	strb r0, [r7, #0x1f]
	ldr r0, [r7, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x18]
	mov r8, r2
	b _080B3854
	.align 2, 0
_080B3630: .4byte 0x000001C3
_080B3634:
	adds r1, r7, #0
	adds r1, #0xd2
	movs r0, #0
	strh r0, [r1]
	movs r2, #0xee
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _080B3690 @ =0x000001C3
	strh r0, [r2]
	adds r4, r7, #0
	adds r4, #0xb8
	ldr r1, [r6]
	mov r0, sl
	ldrb r3, [r0]
	ldr r2, [sp, #4]
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	mov ip, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
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
	beq _080B3694
	ldr r0, [r7, #0x18]
	movs r1, #4
	orrs r0, r1
	b _080B369C
	.align 2, 0
_080B3690: .4byte 0x000001C3
_080B3694:
	ldr r0, [r7, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B369C:
	str r0, [r7, #0x18]
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
	beq _080B36C2
	mov r2, ip
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080B36CE
_080B36C2:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_080B36CE:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3704 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B373C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3708
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B36FE
	ldrb r0, [r4, #5]
_080B36FE:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3718
	.align 2, 0
_080B3704: .4byte 0x0000FFFF
_080B3708:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3718
	strh r1, [r4, #8]
_080B3718:
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
	bne _080B373C
	movs r0, #1
	strb r0, [r4, #7]
_080B373C:
	adds r0, r7, #0
	adds r0, #0x68
	bl FUN_08236400
	b _080B3854
_080B3746:
	mov r1, r8
	ldrh r0, [r1]
	adds r1, r7, #0
	adds r1, #0xd2
	strh r0, [r1]
	movs r2, #0xee
	adds r2, r2, r7
	mov r8, r2
	movs r0, #0xe2
	lsls r0, r0, #1
	strh r0, [r2]
	adds r4, r7, #0
	adds r4, #0xb8
	ldr r1, [r6]
	mov r0, sl
	ldrb r3, [r0]
	ldr r2, [sp, #4]
	ldrb r0, [r2]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	mov ip, sb
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	mov r1, ip
	strh r0, [r1, #0x10]
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
	beq _080B37A2
	ldr r0, [r7, #0x18]
	orrs r0, r5
	b _080B37AA
_080B37A2:
	ldr r0, [r7, #0x18]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080B37AA:
	str r0, [r7, #0x18]
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
	beq _080B37D0
	mov r2, ip
	ldr r0, [r2]
	movs r1, #8
	orrs r0, r1
	b _080B37DC
_080B37D0:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	mov r2, ip
_080B37DC:
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080B3814 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080B384C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080B3818
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080B380C
	ldrb r0, [r4, #5]
_080B380C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080B3828
	.align 2, 0
_080B3814: .4byte 0x0000FFFF
_080B3818:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080B3828
	strh r1, [r4, #8]
_080B3828:
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
	bne _080B384C
	movs r0, #1
	strb r0, [r4, #7]
_080B384C:
	adds r0, r7, #0
	adds r0, #0x68
	bl FUN_08236400
_080B3854:
	adds r0, r7, #0
	adds r0, #0x44
	mov r2, r8
	ldrh r1, [r2]
	bl FUN_0822b20c
	adds r0, r7, #0
	adds r0, #0xda
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	adds r0, #0x12
	strb r4, [r0]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r7, r1
	adds r1, r7, #0
	adds r1, #0x34
	str r2, [sp]
	movs r3, #0
	bl FUN_0824742c
	adds r0, r7, #0
	adds r0, #0xea
	strb r4, [r0]
	movs r0, #0
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity080b3898_Create
Entity080b3898_Create: @ 0x080B3898
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0x8f
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080B38F4
	ldr r1, _080B38EC @ =Entity080b3898_Update
	ldr r2, _080B38F0 @ =Entity080b3898_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x2c]
	str r0, [sp, #4]
	ldr r0, [sp, #0x30]
	str r0, [sp, #8]
	ldr r0, [sp, #0x34]
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x38]
	str r0, [sp, #0x10]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080b3898_Init
	cmp r0, #0
	bge _080B38F4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080B38F6
	.align 2, 0
_080B38EC: .4byte Entity080b3898_Update
_080B38F0: .4byte Entity080b3898_Destroy
_080B38F4:
	adds r0, r4, #0
_080B38F6:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

