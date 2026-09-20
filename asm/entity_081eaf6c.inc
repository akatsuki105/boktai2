	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081ea878
FUN_081ea878: @ 0x081EA878
	bx lr
	.align 2, 0

	thumb_func_start FUN_081ea87c
FUN_081ea87c: @ 0x081EA87C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _081EA8D4 @ =0x030001C0
	ldr r4, [r0]
	ldrb r1, [r5, #0x1d]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _081EA892
	b _081EA9E0
_081EA892:
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _081EA8DC
	movs r3, #0x97
	lsls r3, r3, #1
	adds r1, r5, r3
	movs r2, #0x9a
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r1, r0
	ble _081EA8DC
	adds r1, r4, #0
	adds r1, #0x18
	ldr r0, _081EA8D8 @ =0x085AE478
	ldrb r2, [r0, #0x12]
_081EA8C4:
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #2
	bl FUN_082370cc
	b _081EAA04
	.align 2, 0
_081EA8D4: .4byte 0x030001C0
_081EA8D8: .4byte 0x085AE478
_081EA8DC:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _081EA900
	ldr r0, _081EA938 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _081EA900
	movs r0, #0xd4
	lsls r0, r0, #1
	bl PlaySound_082406e0
_081EA900:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #1
	bne _081EA940
	adds r3, #8
	adds r0, r5, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _081EA940
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _081EA93C @ =0x085AE478
	movs r4, #0x95
	lsls r4, r4, #1
	adds r0, r5, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	movs r4, #0
	ldrsh r2, [r2, r4]
	adds r0, r0, r2
	adds r0, r0, r3
	ldrb r2, [r0]
	b _081EA8C4
	.align 2, 0
_081EA938: .4byte 0x030047A4
_081EA93C: .4byte 0x085AE478
_081EA940:
	movs r0, #0x94
	lsls r0, r0, #1
	adds r1, r5, r0
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r3, #0x95
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r3, #0
	ldrsh r2, [r2, r3]
	movs r3, #0
	ldrsh r1, [r1, r3]
	adds r2, r2, r1
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #3
	bne _081EA9C4
	movs r0, #0x9b
	lsls r0, r0, #1
	adds r7, r5, r0
	movs r1, #0
	ldrsh r0, [r7, r1]
	ldr r3, _081EA9BC @ =0x0000052C
	adds r2, r4, r3
	movs r4, #1
	adds r1, r4, #0
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl MainSprite_Remove
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	ands r4, r0
	adds r6, r5, #0
	adds r6, #0x60
	cmp r4, #0
	beq _081EA9A4
	adds r0, r6, #0
	bl FUN_08002a58
_081EA9A4:
	adds r0, r6, #0
	bl FUN_0823b284
	ldr r0, _081EA9C0 @ =0x0000FFFF
	strh r0, [r7]
	movs r2, #0x99
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #2
	strh r0, [r1]
	movs r0, #1
	b _081EAA06
	.align 2, 0
_081EA9BC: .4byte 0x0000052C
_081EA9C0: .4byte 0x0000FFFF
_081EA9C4:
	adds r1, r4, #0
	adds r1, #0x18
	ldr r0, _081EA9DC @ =0x085AE478
	adds r0, r2, r0
	ldrb r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r0, r5, #0
	movs r3, #2
	bl FUN_082370cc
	b _081EA9EA
	.align 2, 0
_081EA9DC: .4byte 0x085AE478
_081EA9E0:
	adds r1, r4, #0
	adds r1, #0x18
	adds r0, r5, #0
	bl MainSprite_AdvanceAnim
_081EA9EA:
	movs r3, #0x94
	lsls r3, r3, #1
	adds r0, r5, r3
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #1
	bne _081EAA04
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
_081EAA04:
	movs r0, #0
_081EAA06:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081eaa10
FUN_081eaa10: @ 0x081EAA10
	push {r4, r5, lr}
	adds r5, r0, #0
	bl FUN_081ea87c
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081EAA4E
	movs r1, #0x94
	lsls r1, r1, #1
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #1
	bne _081EAA42
	adds r4, r5, #0
	adds r4, #0xd8
	adds r1, r5, #0
	adds r1, #0xd0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_081EAA42:
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081EAA4E:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081eaa54
FUN_081eaa54: @ 0x081EAA54
	bx lr
	.align 2, 0

	thumb_func_start Entity081eaf6c_Destroy
Entity081eaf6c_Destroy: @ 0x081EAA58
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	movs r7, #0
	ldr r1, _081EAA8C @ =0x0000052C
	adds r1, r1, r0
	mov sb, r1
	adds r6, r0, #0
	adds r6, #0x9c
	movs r2, #0xba
	lsls r2, r2, #1
	adds r5, r0, r2
	adds r4, r0, #0
	adds r4, #0x3c
	movs r0, #1
	mov r8, r0
_081EAA7A:
	mov r1, r8
	lsls r1, r7
	mov r2, sb
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081EAA90
	movs r0, #1
	b _081EAA92
	.align 2, 0
_081EAA8C: .4byte 0x0000052C
_081EAA90:
	movs r0, #0
_081EAA92:
	cmp r0, #0
	beq _081EAAB4
	adds r0, r4, #0
	bl MainSprite_Remove
	ldrh r1, [r5]
	mov r0, r8
	ands r0, r1
	cmp r0, #0
	beq _081EAAAC
	adds r0, r6, #0
	bl FUN_08002a58
_081EAAAC:
	adds r0, r4, #0
	adds r0, #0x60
	bl FUN_0823b284
_081EAAB4:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, #1
	cmp r7, #3
	ble _081EAA7A
	movs r1, #0
	ldr r0, _081EAAD8 @ =0x030001C0
	str r1, [r0]
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EAAD8: .4byte 0x030001C0

	thumb_func_start Entity081eaf6c_Update
Entity081eaf6c_Update: @ 0x081EAADC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x3c
	ldr r1, _081EAB34 @ =0x0000052C
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EAB6C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EAB38 @ =0x030047A4
	ldr r1, _081EAB3C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EAB6C
	movs r1, #4
	ldr r0, _081EAB40 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081EAB6C
	movs r6, #0
	ldr r0, _081EAB34 @ =0x0000052C
	adds r7, r3, r0
	ldr r1, _081EAB44 @ =0x085AE48C
	mov r8, r1
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r5, r3, r0
_081EAB22:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EAB48
	movs r0, #1
	b _081EAB4A
	.align 2, 0
_081EAB34: .4byte 0x0000052C
_081EAB38: .4byte 0x030047A4
_081EAB3C: .4byte 0x030047A0
_081EAB40: .4byte 0x03002BC0
_081EAB44: .4byte 0x085AE48C
_081EAB48:
	movs r0, #0
_081EAB4A:
	cmp r0, #0
	beq _081EAB5E
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081EAB5E:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #3
	ble _081EAB22
_081EAB6C:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_081eab78
FUN_081eab78: @ 0x081EAB78
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r1, _081EAB9C @ =0x0000052C
	adds r4, r0, r1
	movs r5, #1
	adds r2, r0, #0
	adds r2, #0x3c
	movs r6, #0x9e
	lsls r6, r6, #1
_081EAB8A:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _081EABA0
	movs r0, #1
	b _081EABA2
	.align 2, 0
_081EAB9C: .4byte 0x0000052C
_081EABA0:
	movs r0, #0
_081EABA2:
	cmp r0, #0
	bne _081EABBC
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r2, r1
	strh r3, [r0]
	adds r0, r2, #0
	b _081EABC6
_081EABBC:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #3
	ble _081EAB8A
	movs r0, #0
_081EABC6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_081eabcc
FUN_081eabcc: @ 0x081EABCC
	bx lr
	.align 2, 0

	thumb_func_start FUN_081eabd0
FUN_081eabd0: @ 0x081EABD0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r6, r0, #0
	adds r5, r1, #0
	adds r7, r3, #0
	cmp r5, #0
	bne _081EAC30
	cmp r2, #1
	beq _081EABFC
	cmp r2, #1
	bgt _081EABEC
	cmp r2, #0
	beq _081EABF2
	b _081EAC0E
_081EABEC:
	cmp r2, #2
	beq _081EAC04
	b _081EAC0E
_081EABF2:
	ldr r0, _081EABF8 @ =0x085AE498
	b _081EAC06
	.align 2, 0
_081EABF8: .4byte 0x085AE498
_081EABFC:
	ldr r0, _081EAC00 @ =0x085AE4A0
	b _081EAC06
	.align 2, 0
_081EAC00: .4byte 0x085AE4A0
_081EAC04:
	ldr r0, _081EAC28 @ =0x085AE4A8
_081EAC06:
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
_081EAC0E:
	ldr r3, _081EAC2C @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x14]
	add r0, sp, #0xc
	ldrh r2, [r0, #4]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	movs r5, #0x40
	b _081EAC7E
	.align 2, 0
_081EAC28: .4byte 0x085AE4A8
_081EAC2C: .4byte 0xFFFF0000
_081EAC30:
	cmp r2, #1
	beq _081EAC4C
	cmp r2, #1
	bgt _081EAC3E
	cmp r2, #0
	beq _081EAC44
	b _081EAC6C
_081EAC3E:
	cmp r2, #2
	beq _081EAC54
	b _081EAC6C
_081EAC44:
	ldr r2, _081EAC48 @ =0x085AE498
	b _081EAC56
	.align 2, 0
_081EAC48: .4byte 0x085AE498
_081EAC4C:
	ldr r2, _081EAC50 @ =0x085AE4A0
	b _081EAC56
	.align 2, 0
_081EAC50: .4byte 0x085AE4A0
_081EAC54:
	ldr r2, _081EACD4 @ =0x085AE4A8
_081EAC56:
	ldr r3, _081EACD8 @ =0xFFFF0000
	ldrh r1, [r2, #2]
	lsls r1, r1, #0x10
	ldrh r0, [r2, #4]
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r2]
	ldr r0, [sp, #0x10]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x10]
_081EAC6C:
	add r0, sp, #0xc
	ldr r2, _081EACD8 @ =0xFFFF0000
	ldrh r0, [r0]
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r5, #0
_081EAC7E:
	adds r4, r6, #0
	adds r4, #0xd8
	ldr r2, _081EACDC @ =0x00002101
	movs r0, #0x20
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r4, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	ldr r0, _081EACE0 @ =0x00200004
	str r0, [sp]
	ldr r0, [sp, #0x34]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r7, #0
	ldr r2, [sp, #0x30]
	movs r3, #0x40
	bl FUN_082364f8
	adds r1, r6, #0
	adds r1, #0xd0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	ldr r1, _081EACE4 @ =FUN_081eabcc
	adds r0, r4, #0
	adds r2, r6, #0
	bl FUN_0823651c
	movs r1, #0x8d
	lsls r1, r1, #1
	adds r0, r6, r1
	strb r5, [r0]
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EACD4: .4byte 0x085AE4A8
_081EACD8: .4byte 0xFFFF0000
_081EACDC: .4byte 0x00002101
_081EACE0: .4byte 0x00200004
_081EACE4: .4byte FUN_081eabcc

	thumb_func_start FUN_081eace8
FUN_081eace8: @ 0x081EACE8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	ldr r0, _081EAD4C @ =0x030001C0
	ldr r5, [r0]
	lsls r4, r2, #1
	adds r4, r4, r2
	lsls r0, r1, #3
	adds r0, r0, r1
	adds r4, r4, r0
	movs r1, #0x95
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r6, #0
	strh r4, [r0]
	subs r1, #2
	adds r0, r7, r1
	strh r3, [r0]
	adds r1, #4
	adds r0, r7, r1
	movs r1, #1
	strh r1, [r0]
	adds r5, #0x18
	str r1, [sp]
	movs r0, #2
	str r0, [sp, #4]
	movs r0, #0x78
	str r0, [sp, #8]
	adds r0, r7, #0
	adds r0, #0xd0
	str r0, [sp, #0xc]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r2, #0xd
	movs r3, #0
	bl MainSprite_Add
	ldr r0, _081EAD50 @ =0x085AE478
	ldrb r2, [r0, #0x12]
	str r6, [sp]
	adds r0, r7, #0
	adds r1, r5, #0
	movs r3, #2
	bl FUN_082370cc
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081EAD4C: .4byte 0x030001C0
_081EAD50: .4byte 0x085AE478

	thumb_func_start FUN_081ead54
FUN_081ead54: @ 0x081EAD54
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r6, r0, #0
	str r1, [sp, #8]
	mov sb, r2
	mov sl, r3
	ldr r0, [sp, #0x2c]
	mov r8, r0
	ldr r5, [sp, #0x44]
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EADA4 @ =0x030047A4
	ldr r1, _081EADA8 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EADA0
	movs r1, #4
	ldr r0, _081EADAC @ =0x03002BC0
	ldr r4, [r0]
	ands r4, r1
	cmp r4, #0
	bne _081EADA0
	ldr r0, _081EADB0 @ =0x030001C0
	ldr r0, [r0]
	cmp r0, #0
	beq _081EADA0
	bl FUN_081eab78
	adds r7, r0, #0
	cmp r7, #0
	bne _081EADB4
_081EADA0:
	movs r0, #0
	b _081EAED8
	.align 2, 0
_081EADA4: .4byte 0x030047A4
_081EADA8: .4byte 0x030047A0
_081EADAC: .4byte 0x03002BC0
_081EADB0: .4byte 0x030001C0
_081EADB4:
	adds r2, r7, #0
	adds r2, #0xd0
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r7, r1
	mov r1, sb
	strh r1, [r0]
	movs r1, #0x9a
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r4, [r0]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r7, r0
	ldr r0, [sp, #0x40]
	strh r0, [r1]
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r7, r1
	movs r1, #1
	mov sb, r1
	mov r1, sb
	strh r1, [r0]
	adds r6, r7, #0
	adds r6, #0x60
	ldr r0, [sp, #8]
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r6, #0
	movs r3, #0
	bl FUN_0823b400
	adds r4, r7, #0
	adds r4, #0xa4
	adds r0, r6, #0
	adds r1, r4, #0
	bl FUN_0823b46c
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	mov r0, sb
	ands r5, r0
	cmp r5, #0
	beq _081EAEB6
	mov r1, sl
	cmp r1, #0
	bne _081EAE74
	mov r0, r8
	cmp r0, #1
	beq _081EAE54
	cmp r0, #1
	bgt _081EAE3E
	cmp r0, #0
	beq _081EAE46
	b _081EAEB0
_081EAE3E:
	mov r1, r8
	cmp r1, #2
	beq _081EAE60
	b _081EAEB0
_081EAE46:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE50 @ =0x085AE498
	adds r0, #0x20
	b _081EAE66
	.align 2, 0
_081EAE50: .4byte 0x085AE498
_081EAE54:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE5C @ =0x085AE4A0
	adds r0, #0x64
	b _081EAE66
	.align 2, 0
_081EAE5C: .4byte 0x085AE4A0
_081EAE60:
	ldrh r0, [r6, #0xc]
	ldr r1, _081EAE70 @ =0x085AE4A8
	adds r0, #0xc8
_081EAE66:
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #0xc]
	b _081EAEB0
	.align 2, 0
_081EAE70: .4byte 0x085AE4A8
_081EAE74:
	mov r0, r8
	cmp r0, #1
	beq _081EAE98
	cmp r0, #1
	bgt _081EAE84
	cmp r0, #0
	beq _081EAE8C
	b _081EAEB0
_081EAE84:
	mov r1, r8
	cmp r1, #2
	beq _081EAEA4
	b _081EAEB0
_081EAE8C:
	ldrh r0, [r6, #8]
	ldr r1, _081EAE94 @ =0x085AE498
	adds r0, #0x20
	b _081EAEAA
	.align 2, 0
_081EAE94: .4byte 0x085AE498
_081EAE98:
	ldrh r0, [r6, #8]
	ldr r1, _081EAEA0 @ =0x085AE4A0
	adds r0, #0x64
	b _081EAEAA
	.align 2, 0
_081EAEA0: .4byte 0x085AE4A0
_081EAEA4:
	ldrh r0, [r6, #8]
	ldr r1, _081EAEE8 @ =0x085AE4A8
	adds r0, #0xc8
_081EAEAA:
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r6, #8]
_081EAEB0:
	adds r0, r6, #0
	bl FUN_08002a48
_081EAEB6:
	ldr r0, [sp, #0x38]
	str r0, [sp]
	ldr r0, [sp, #0x3c]
	str r0, [sp, #4]
	adds r0, r7, #0
	mov r1, sl
	mov r2, r8
	ldr r3, [sp, #0x34]
	bl FUN_081eabd0
	adds r0, r7, #0
	mov r1, sl
	mov r2, r8
	ldr r3, [sp, #0x30]
	bl FUN_081eace8
	adds r0, r7, #0
_081EAED8:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EAEE8: .4byte 0x085AE4A8

	thumb_func_start FUN_081eaeec
FUN_081eaeec: @ 0x081EAEEC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081EAF1C @ =0x0000CB05
	ldr r1, _081EAF20 @ =0x00001BC7
	bl GetFile
	str r0, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0x18
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3, r5}
	stm r1!, {r2, r3, r5}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	adds r0, r4, #0
	adds r0, #0x18
	ldr r1, [r4, #0x38]
	bl OpenMainSpriteFile
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081EAF1C: .4byte 0x0000CB05
_081EAF20: .4byte 0x00001BC7

	thumb_func_start Entity081eaf6c_Init
Entity081eaf6c_Init: @ 0x081EAF24
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081EAF60 @ =0x030001C0
	str r4, [r0]
	adds r0, r4, #0
	bl FUN_081eaeec
	ldr r0, _081EAF64 @ =0x0000FFFF
	adds r5, r0, #0
	movs r2, #0xb9
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r3, #0x9e
	lsls r3, r3, #1
	movs r2, #3
_081EAF42:
	ldrh r0, [r1]
	orrs r0, r5
	strh r0, [r1]
	adds r1, r1, r3
	subs r2, #1
	cmp r2, #0
	bge _081EAF42
	movs r1, #0
	ldr r2, _081EAF68 @ =0x0000052C
	adds r0, r4, r2
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_081EAF60: .4byte 0x030001C0
_081EAF64: .4byte 0x0000FFFF
_081EAF68: .4byte 0x0000052C

	thumb_func_start Entity081eaf6c_Create
Entity081eaf6c_Create: @ 0x081EAF6C
	push {r4, lr}
	ldr r0, _081EAFA4 @ =0x030001C0
	ldr r0, [r0]
	cmp r0, #0
	bne _081EAF9E
	movs r1, #0xa6
	lsls r1, r1, #3
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081EAF9E
	ldr r1, _081EAFA8 @ =Entity081eaf6c_Update
	ldr r2, _081EAFAC @ =Entity081eaf6c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity081eaf6c_Init
	cmp r0, #0
	bge _081EAF9E
	adds r0, r4, #0
	bl KillEntity
_081EAF9E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081EAFA4: .4byte 0x030001C0
_081EAFA8: .4byte Entity081eaf6c_Update
_081EAFAC: .4byte Entity081eaf6c_Destroy

	thumb_func_start FUN_081eafb0
FUN_081eafb0: @ 0x081EAFB0
	ldr r1, _081EAFB8 @ =0x030001C0
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_081EAFB8: .4byte 0x030001C0
