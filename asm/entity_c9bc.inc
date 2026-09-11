	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0800cbd0
FUN_0800cbd0: @ 0x0800CBD0
	push {r4, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #4]
	ldrh r1, [r1, #4]
	cmp r0, r1
	beq _0800CBFE
	movs r0, #7
	ldr r1, [r3, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0800CBFE
	adds r4, r2, #0
	adds r4, #0x40
	ldrb r0, [r4]
	cmp r0, #0
	bne _0800CBFE
	movs r0, #1
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	ldr r0, [r3, #0x38]
	str r0, [r2, #0x24]
	movs r0, #0xa
	strb r0, [r4]
_0800CBFE:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800cc04
FUN_0800cc04: @ 0x0800CC04
	bx lr
	.align 2, 0

	thumb_func_start FUN_0800cc08
FUN_0800cc08: @ 0x0800CC08
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	movs r0, #0x90
	lsls r0, r0, #1
	adds r6, r3, r0
	adds r0, r3, #0
	adds r0, #0x31
	ldrb r1, [r0]
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	asrs r1, r1, #6
	adds r1, #1
	movs r2, #3
	ldr r0, _0800CC64 @ =0x030046A4
	ldr r4, [r0]
	ands r1, r2
	lsls r1, r1, #1
	adds r0, r4, #0
	adds r0, #0x1c
	adds r0, r0, r1
	movs r1, #0
	ldrsh r5, [r0, r1]
	adds r1, r3, #0
	adds r1, #0x50
	ldrh r0, [r1]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800CC5E
	cmp r1, #0
	blt _0800CC5E
	ldr r0, _0800CC68 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800CC5E
	ldr r0, _0800CC6C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800CC70
_0800CC5E:
	movs r0, #0
	b _0800CC7C
	.align 2, 0
_0800CC64: .4byte 0x030046A4
_0800CC68: .4byte 0x030046A8
_0800CC6C: .4byte 0x030046AC
_0800CC70:
	lsls r0, r1, #1
	adds r1, r4, #0
	adds r1, #0x24
	adds r1, r1, r0
	ldrh r0, [r1]
	adds r0, r0, r2
_0800CC7C:
	adds r4, r0, r5
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _0800CC8E
	adds r3, r0, #4
	b _0800CC9A
_0800CC8E:
	ldr r0, _0800CCC4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r3, r1, r0
_0800CC9A:
	cmp r3, #0
	beq _0800CCC8
	ldrb r4, [r3]
	lsrs r0, r4, #4
	cmp r0, #0
	bne _0800CCC8
	movs r0, #0xf
	ldrb r2, [r6]
	adds r1, r0, #0
	ands r1, r4
	ands r0, r2
	cmp r1, r0
	bhs _0800CCC8
	ldrh r1, [r3, #2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _0800CCC8
	movs r0, #1
	b _0800CCCA
	.align 2, 0
_0800CCC4: .4byte 0x030046A4
_0800CCC8:
	movs r0, #0
_0800CCCA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800ccd0
FUN_0800ccd0: @ 0x0800CCD0
	push {r4, r5, lr}
	adds r4, r1, #0
	ldrb r5, [r4, #3]
	cmp r5, #1
	bne _0800CD24
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800CCE6
	ldr r0, _0800CD20 @ =0x00000219
	bl PlaySound_082406e0
_0800CCE6:
	ldrb r1, [r4, #2]
	movs r0, #1
	movs r2, #0
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	movs r0, #3
	strb r0, [r4, #3]
	str r2, [r4, #4]
	strb r5, [r4, #1]
	adds r1, r4, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	movs r0, #1
	b _0800CD64
	.align 2, 0
_0800CD20: .4byte 0x00000219
_0800CD24:
	movs r0, #1
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	bne _0800CD62
	cmp r1, #0
	bne _0800CD38
	ldr r0, _0800CD6C @ =0x00000219
	bl PlaySound_082406e0
_0800CD38:
	ldrb r1, [r4, #2]
	movs r0, #1
	orrs r0, r1
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	strb r0, [r4, #2]
	adds r0, r4, #0
	adds r0, #0x42
	ldrh r0, [r0]
	strh r0, [r4, #0x38]
	adds r1, r4, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r4, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
_0800CD62:
	movs r0, #0
_0800CD64:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_0800CD6C: .4byte 0x00000219

	thumb_func_start FUN_0800cd70
FUN_0800cd70: @ 0x0800CD70
	push {lr}
	adds r2, r1, #0
	ldrb r3, [r2, #3]
	cmp r3, #0
	beq _0800CD7E
	movs r0, #0
	b _0800CDAE
_0800CD7E:
	movs r0, #2
	movs r1, #2
	strb r0, [r2, #3]
	str r3, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	ldrb r0, [r2, #2]
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	strb r1, [r2, #2]
	strh r3, [r2, #0x38]
	adds r1, r2, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r2, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	movs r0, #1
_0800CDAE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0800cdb4
FUN_0800cdb4: @ 0x0800CDB4
	push {r4, lr}
	adds r2, r1, #0
	ldrh r1, [r2, #0x3e]
	subs r1, #1
	movs r3, #0
	strh r1, [r2, #0x3e]
	movs r4, #0xa
	movs r0, #0xa
	strh r0, [r2, #0x3a]
	lsls r1, r1, #0x10
	cmp r1, #0
	bgt _0800CE02
	strh r3, [r2, #0x3e]
	ldrb r0, [r2, #3]
	cmp r0, #1
	bhi _0800CE18
	ldrb r1, [r2, #2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2, #2]
	movs r0, #6
	strb r0, [r2, #3]
	str r3, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	adds r0, r2, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, #0x4b
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	movs r0, #0x85
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #1
	b _0800CE1A
_0800CE02:
	adds r0, r2, #0
	adds r0, #0x41
	strb r4, [r0]
	adds r0, #0x4b
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	ldr r0, _0800CE20 @ =0x00000217
	bl PlaySound_082406e0
_0800CE18:
	movs r0, #0
_0800CE1A:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0800CE20: .4byte 0x00000217

	thumb_func_start FUN_0800ce24
FUN_0800ce24: @ 0x0800CE24
	push {r4, r5, r6, r7, lr}
	adds r6, r1, #0
	ldrb r0, [r6, #3]
	cmp r0, #0
	bne _0800CF14
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r3, r6, r0
	ldr r0, _0800CE60 @ =0x03002BE0
	ldr r1, [r0]
	ldrh r0, [r1, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800CE5C
	cmp r1, #0
	blt _0800CE5C
	ldr r0, _0800CE64 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800CE5C
	ldr r0, _0800CE68 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800CE6C
_0800CE5C:
	movs r0, #0
	b _0800CE7A
	.align 2, 0
_0800CE60: .4byte 0x03002BE0
_0800CE64: .4byte 0x030046A8
_0800CE68: .4byte 0x030046AC
_0800CE6C:
	ldr r0, _0800CEA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800CE7A:
	ldrh r1, [r3, #2]
	movs r2, #2
	bl FUN_08232888
	cmp r0, #0
	blt _0800CF04
	adds r1, r6, #0
	adds r1, #0x31
	strb r0, [r1]
	ldr r0, [r6, #0x20]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	beq _0800CEA4
	adds r0, r6, #0
	adds r0, #0x30
	strb r1, [r0]
	adds r7, r0, #0
	b _0800CEAE
	.align 2, 0
_0800CEA0: .4byte 0x030046A4
_0800CEA4:
	adds r1, r6, #0
	adds r1, #0x30
	movs r0, #1
	strb r0, [r1]
	adds r7, r1, #0
_0800CEAE:
	adds r0, r6, #0
	bl FUN_0800cc08
	cmp r0, #0
	beq _0800CF04
	movs r5, #4
	ldrb r1, [r6, #2]
	movs r0, #4
	movs r4, #0
	orrs r0, r1
	strb r0, [r6, #2]
	adds r1, r6, #0
	adds r1, #0x41
	movs r0, #0xa
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x8c
	movs r1, #0x99
	lsls r1, r1, #1
	bl Video_SetActorSpritePltt
	strb r5, [r6, #3]
	str r4, [r6, #4]
	movs r0, #1
	strb r0, [r6, #1]
	movs r0, #0
	ldrsb r0, [r7, r0]
	cmp r0, #2
	bne _0800CEF4
	ldr r0, _0800CEF0 @ =0x00000216
	bl PlaySound_082406e0
	b _0800CEFA
	.align 2, 0
_0800CEF0: .4byte 0x00000216
_0800CEF4:
	ldr r0, _0800CF00 @ =0x00000215
	bl PlaySound_082406e0
_0800CEFA:
	movs r0, #1
	b _0800CF24
	.align 2, 0
_0800CF00: .4byte 0x00000215
_0800CF04:
	movs r0, #0xa
	strh r0, [r6, #0x3a]
	ldr r0, _0800CF10 @ =0x00000217
	bl PlaySound_082406e0
	b _0800CF22
	.align 2, 0
_0800CF10: .4byte 0x00000217
_0800CF14:
	cmp r0, #1
	bne _0800CF22
	movs r0, #0xa
	strh r0, [r6, #0x3a]
	ldr r0, _0800CF2C @ =0x00000217
	bl PlaySound_082406e0
_0800CF22:
	movs r0, #0
_0800CF24:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0800CF2C: .4byte 0x00000217

	thumb_func_start FUN_0800cf30
FUN_0800cf30: @ 0x0800CF30
	push {r4, r5, r6, lr}
	adds r4, r1, #0
	cmp r2, #0
	blt _0800CF44
	movs r1, #1
	ldr r0, [r4, #4]
	ands r0, r1
	ands r1, r2
	cmp r1, r0
	bne _0800CF7E
_0800CF44:
	adds r6, r4, #0
	adds r6, #0x48
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0, #2]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08234224
	cmp r0, #0
	beq _0800CF60
	adds r0, #4
	b _0800CF6C
_0800CF60:
	ldr r0, _0800CF84 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800CF6C:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xa
	ldrsh r0, [r6, r2]
	subs r0, r0, r1
	cmp r0, #0xff
	bgt _0800CF88
_0800CF7E:
	movs r0, #0
	b _0800CF96
	.align 2, 0
_0800CF84: .4byte 0x030046A4
_0800CF88:
	movs r0, #0
	strh r1, [r4, #0x32]
	movs r1, #5
	strb r1, [r4, #3]
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
_0800CF96:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_0800cf9c
FUN_0800cf9c: @ 0x0800CF9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800CFBE
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r1, [r2, #6]
	orrs r0, r1
	strh r0, [r2, #6]
_0800CFBE:
	ldrh r0, [r4, #0x2a]
	movs r1, #1
	orrs r1, r0
	strh r1, [r4, #0x2a]
	movs r2, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0800D062
	str r2, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800CFE4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ccd0
	adds r2, r0, #0
_0800CFE4:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800CFFC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cd70
	adds r2, r0, #0
_0800CFFC:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D014
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cdb4
	adds r2, r0, #0
_0800D014:
	cmp r2, #0
	bne _0800D02C
	ldr r0, [r4, #0x24]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D02C
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ce24
	adds r2, r0, #0
_0800D02C:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D036
	movs r0, #0x78
	b _0800D05C
_0800D036:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D044
	movs r0, #0x7b
	b _0800D05C
_0800D044:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D050
	movs r0, #0x7c
	b _0800D05C
_0800D050:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D05C
	movs r0, #0x79
_0800D05C:
	strh r0, [r4, #0x2e]
	cmp r2, #0
	bne _0800D06C
_0800D062:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0800cf30
_0800D06C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d074
FUN_0800d074: @ 0x0800D074
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D086
	movs r0, #0
	strb r0, [r4, #1]
_0800D086:
	movs r2, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _0800D122
	str r2, [r4, #0x1c]
	ldr r0, [r4, #0x24]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D0A4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ccd0
	adds r2, r0, #0
_0800D0A4:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #8
	ands r0, r1
	cmp r0, #0
	beq _0800D0BC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cd70
	adds r2, r0, #0
_0800D0BC:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0
	beq _0800D0D4
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800cdb4
	adds r2, r0, #0
_0800D0D4:
	cmp r2, #0
	bne _0800D0EC
	ldr r0, [r4, #0x24]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _0800D0EC
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0800ce24
	adds r2, r0, #0
_0800D0EC:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D0F6
	movs r0, #0x78
	b _0800D11C
_0800D0F6:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D104
	movs r0, #0x7b
	b _0800D11C
_0800D104:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D110
	movs r0, #0x7c
	b _0800D11C
_0800D110:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D11C
	movs r0, #0x79
_0800D11C:
	strh r0, [r4, #0x2e]
	cmp r2, #0
	bne _0800D12C
_0800D122:
	adds r0, r5, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0800cf30
_0800D12C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d134
FUN_0800d134: @ 0x0800D134
	push {r4, lr}
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D14A
	movs r0, #0
	strb r0, [r4, #1]
	movs r0, #0x86
	lsls r0, r0, #2
	bl PlaySound_082406e0
_0800D14A:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x34]
	subs r0, #2
	strh r0, [r4, #0x34]
	lsls r0, r0, #0x10
	cmp r0, #0
	bgt _0800D174
	strh r2, [r4, #0x34]
	movs r0, #1
	strb r0, [r4, #3]
	str r2, [r4, #4]
	strb r0, [r4, #1]
	adds r0, r4, #0
	adds r0, #0x50
	movs r1, #0x80
	bl FUN_08003014
_0800D174:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d17c
FUN_0800d17c: @ 0x0800D17C
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D192
	movs r0, #0
	strb r0, [r4, #1]
	ldr r0, _0800D1C8 @ =0x0000021A
	bl PlaySound_082406e0
_0800D192:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r2, #0
	orrs r0, r1
	strh r0, [r4, #0x2a]
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	movs r3, #0x20
	ldrsh r0, [r5, r3]
	adds r1, r1, r0
	ldrh r0, [r4, #0x34]
	adds r0, #2
	strh r0, [r4, #0x34]
	movs r3, #0x34
	ldrsh r0, [r4, r3]
	cmp r0, r1
	blt _0800D1C0
	strh r1, [r4, #0x34]
	strb r2, [r4, #3]
	movs r0, #0
	str r0, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
_0800D1C0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0800D1C8: .4byte 0x0000021A

	thumb_func_start FUN_0800d1cc
FUN_0800d1cc: @ 0x0800D1CC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	mov r8, r0
	adds r4, r1, #0
	adds r3, r4, #0
	adds r3, #0x48
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D1E6
	movs r0, #0
	strb r0, [r4, #1]
_0800D1E6:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	orrs r0, r1
	strh r0, [r4, #0x2a]
	adds r0, r4, #0
	adds r0, #0x31
	mov r5, sp
	ldrb r6, [r0]
	ldr r2, _0800D214 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #4
	cmp r0, #0
	blt _0800D218
	asrs r1, r0, #0xc
	b _0800D21E
	.align 2, 0
_0800D214: .4byte 0x085B0A08
_0800D218:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0800D21E:
	movs r0, #0
	strh r1, [r5]
	strh r0, [r5, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x10
	muls r0, r1, r0
	cmp r0, #0
	blt _0800D238
	asrs r0, r0, #0xc
	b _0800D23E
_0800D238:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D23E:
	strh r0, [r5, #4]
	adds r2, r3, #0
	adds r2, #8
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	ldrh r5, [r3, #8]
	adds r0, r0, r5
	strh r0, [r3, #8]
	ldrh r0, [r1, #2]
	ldrh r5, [r2, #2]
	adds r0, r0, r5
	strh r0, [r2, #2]
	ldrh r1, [r1, #4]
	ldrh r0, [r2, #4]
	adds r1, r1, r0
	strh r1, [r2, #4]
	ldrh r0, [r3, #8]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _0800D282
	cmp r1, #0
	blt _0800D282
	ldr r0, _0800D288 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800D282
	ldr r0, _0800D28C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800D290
_0800D282:
	movs r0, #0
	b _0800D29E
	.align 2, 0
_0800D288: .4byte 0x030046A8
_0800D28C: .4byte 0x030046AC
_0800D290:
	ldr r0, _0800D2E8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800D29E:
	movs r1, #0x8f
	lsls r1, r1, #1
	adds r2, r4, r1
	movs r6, #0
	movs r7, #0
	strh r0, [r2]
	ldr r0, [r4, #4]
	cmp r0, #0xf
	bls _0800D358
	ldrh r2, [r3, #8]
	ldr r1, _0800D2EC @ =0xFFFFFF00
	adds r0, r1, #0
	ands r0, r2
	adds r0, #0x80
	strh r0, [r3, #8]
	ldrh r0, [r3, #0xc]
	ands r1, r0
	adds r1, #0x80
	strh r1, [r3, #0xc]
	adds r5, r4, #0
	adds r5, #0x30
	ldrb r0, [r5]
	subs r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	cmp r0, #0
	bgt _0800D2F0
	strb r6, [r4, #3]
	str r7, [r4, #4]
	movs r0, #1
	strb r0, [r4, #1]
	subs r0, #6
	ldrb r1, [r4, #2]
	ands r0, r1
	strb r0, [r4, #2]
	b _0800D326
	.align 2, 0
_0800D2E8: .4byte 0x030046A4
_0800D2EC: .4byte 0xFFFFFF00
_0800D2F0:
	adds r0, r4, #0
	bl FUN_0800cc08
	cmp r0, #0
	beq _0800D302
	movs r0, #4
	strb r0, [r4, #3]
	str r7, [r4, #4]
	b _0800D322
_0800D302:
	strb r6, [r5]
	movs r0, #5
	rsbs r0, r0, #0
	ldrb r1, [r4, #2]
	ands r0, r1
	strb r0, [r4, #2]
	movs r2, #1
	rsbs r2, r2, #0
	mov r0, r8
	adds r1, r4, #0
	bl FUN_0800cf30
	cmp r0, #0
	bne _0800D326
	strb r6, [r4, #3]
	str r0, [r4, #4]
_0800D322:
	movs r0, #1
	strb r0, [r4, #1]
_0800D326:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _0800D330
	movs r0, #0x78
	b _0800D356
_0800D330:
	movs r0, #8
	ldrb r1, [r4, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D33E
	movs r0, #0x7b
	b _0800D356
_0800D33E:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D34A
	movs r0, #0x7c
	b _0800D356
_0800D34A:
	movs r0, #1
	ands r1, r0
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D356
	movs r0, #0x79
_0800D356:
	strh r0, [r4, #0x2e]
_0800D358:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0800d364
FUN_0800d364: @ 0x0800D364
	push {r4, r5, r6, lr}
	adds r2, r1, #0
	movs r0, #0x8e
	lsls r0, r0, #1
	adds r5, r2, r0
	adds r4, r2, #0
	adds r4, #0x48
	ldrb r0, [r2, #1]
	cmp r0, #0
	beq _0800D37C
	movs r0, #0
	strb r0, [r2, #1]
_0800D37C:
	ldrh r0, [r2, #0x2a]
	movs r1, #0x10
	movs r6, #0
	orrs r1, r0
	strh r1, [r2, #0x2a]
	ldrh r0, [r4, #0xa]
	subs r0, #0x10
	strh r0, [r4, #0xa]
	ldrh r3, [r2, #0x32]
	lsls r0, r0, #0x10
	lsls r1, r3, #0x10
	cmp r0, r1
	bge _0800D3EA
	strh r3, [r4, #0xa]
	asrs r0, r1, #0x18
	movs r1, #0xf
	ands r0, r1
	adds r3, r0, #1
	cmp r3, #0xf
	ble _0800D3A6
	movs r3, #0xf
_0800D3A6:
	ldrb r0, [r5, #4]
	movs r1, #0xf0
	ands r1, r0
	orrs r1, r3
	strb r1, [r5, #4]
	movs r0, #2
	ldrb r1, [r2, #2]
	ands r1, r0
	cmp r1, #0
	beq _0800D3DC
	movs r1, #1
	strb r1, [r2, #3]
	movs r0, #0
	str r0, [r2, #4]
	strb r1, [r2, #1]
	adds r0, r2, #0
	adds r0, #0x50
	movs r1, #0x80
	bl FUN_08003014
	ldr r0, _0800D3D8 @ =0x00000143
	bl PlaySound_082406e0
	b _0800D3EA
	.align 2, 0
_0800D3D8: .4byte 0x00000143
_0800D3DC:
	strb r6, [r2, #3]
	str r1, [r2, #4]
	movs r0, #1
	strb r0, [r2, #1]
	ldr r0, _0800D3F0 @ =0x0000021B
	bl PlaySound_082406e0
_0800D3EA:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0800D3F0: .4byte 0x0000021B

	thumb_func_start FUN_0800d3f4
FUN_0800d3f4: @ 0x0800D3F4
	push {r4, lr}
	sub sp, #0xc
	adds r4, r1, #0
	ldrb r0, [r4, #1]
	cmp r0, #0
	beq _0800D42E
	movs r0, #0
	strb r0, [r4, #1]
	add r2, sp, #4
	ldr r0, [r4, #0x50]
	ldr r1, [r4, #0x54]
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r2, #0
	ldrh r0, [r0]
	adds r0, #0x40
	adds r1, r2, #0
	strh r0, [r1]
	ldrh r0, [r2, #4]
	adds r0, #0x40
	strh r0, [r2, #4]
	movs r0, #7
	str r0, [sp]
	adds r0, r1, #0
	movs r1, #0x90
	movs r2, #0x28
	movs r3, #8
	bl FUN_08019814
_0800D42E:
	ldrh r1, [r4, #0x2a]
	movs r0, #0x10
	movs r3, #0
	orrs r1, r0
	strh r1, [r4, #0x2a]
	ldr r2, [r4, #4]
	cmp r2, #0xf
	bhi _0800D448
	movs r0, #7
	ands r0, r2
	cmp r0, #4
	bne _0800D456
	b _0800D450
_0800D448:
	movs r0, #3
	ands r0, r2
	cmp r0, #2
	bne _0800D456
_0800D450:
	movs r0, #0xc
	orrs r1, r0
	strh r1, [r4, #0x2a]
_0800D456:
	cmp r2, #0x1f
	bls _0800D462
	adds r1, r4, #0
	adds r1, #0x44
	movs r0, #1
	strb r0, [r1]
_0800D462:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0800d46c
FUN_0800d46c: @ 0x0800D46C
	movs r0, #0
	strh r0, [r1, #0x2a]
	ldrb r0, [r1, #3]
	adds r2, r1, #0
	adds r2, #0x45
	strb r0, [r2]
	ldrb r0, [r1, #2]
	adds r1, #0x46
	strb r0, [r1]
	bx lr

	thumb_func_start FUN_0800d480
FUN_0800d480: @ 0x0800D480
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x38
	mov r8, r0
	adds r5, r1, #0
	movs r0, #0x48
	adds r0, r0, r5
	mov sl, r0
	movs r1, #0x8e
	lsls r1, r1, #1
	adds r1, r1, r5
	mov sb, r1
	adds r0, r5, #0
	adds r0, #0x50
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r0, [r0, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _0800D4C6
	cmp r1, #0
	blt _0800D4C6
	ldr r0, _0800D4CC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _0800D4C6
	ldr r0, _0800D4D0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _0800D4D4
_0800D4C6:
	movs r0, #0
	b _0800D4E2
	.align 2, 0
_0800D4CC: .4byte 0x030046A8
_0800D4D0: .4byte 0x030046AC
_0800D4D4:
	ldr r0, _0800D508 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_0800D4E2:
	movs r1, #1
	bl FUN_08234224
	adds r0, r5, #0
	adds r0, #0x48
	bl FUN_0823b4b8
	ldrh r1, [r5, #0x28]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0800D50C
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r5, r2
	bl FUN_08234660
	b _0800D53C
	.align 2, 0
_0800D508: .4byte 0x030046A4
_0800D50C:
	ldrb r0, [r5, #3]
	cmp r0, #1
	bne _0800D530
	adds r2, r5, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	ldr r1, _0800D52C @ =0x0000FFFD
	ands r1, r0
	strh r1, [r2]
	movs r3, #0xe6
	lsls r3, r3, #1
	adds r0, r5, r3
	bl FUN_08234660
	b _0800D53C
	.align 2, 0
_0800D52C: .4byte 0x0000FFFD
_0800D530:
	adds r2, r5, #0
	adds r2, #0x4a
	ldrh r0, [r2]
	movs r1, #2
	orrs r0, r1
	strh r0, [r2]
_0800D53C:
	movs r2, #1
	ldrb r0, [r5, #2]
	ands r0, r2
	cmp r0, #0
	beq _0800D5B0
	mov r4, r8
	movs r6, #0x24
	ldrsh r0, [r4, r6]
	cmp r0, #0xf
	ble _0800D558
	ldrh r1, [r5, #0x2a]
	movs r0, #0x20
	orrs r0, r1
	strh r0, [r5, #0x2a]
_0800D558:
	ldrh r1, [r5, #0x38]
	movs r3, #0x38
	ldrsh r0, [r5, r3]
	cmp r0, #0
	ble _0800D5B0
	adds r0, r5, #0
	adds r0, #0x42
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _0800D5B0
	subs r0, r1, #1
	strh r0, [r5, #0x38]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0800D5B0
	movs r0, #2
	rsbs r0, r0, #0
	ldrb r1, [r5, #2]
	ands r0, r1
	strb r0, [r5, #2]
	cmp r0, #0
	bne _0800D58A
	movs r0, #0x78
	b _0800D5AE
_0800D58A:
	movs r0, #8
	ldrb r1, [r5, #2]
	ands r0, r1
	cmp r0, #0
	beq _0800D598
	movs r0, #0x7b
	b _0800D5AE
_0800D598:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0800D5A4
	movs r0, #0x7c
	b _0800D5AE
_0800D5A4:
	ands r1, r2
	movs r0, #0x7a
	cmp r1, #0
	beq _0800D5AE
	movs r0, #0x79
_0800D5AE:
	strh r0, [r5, #0x2e]
_0800D5B0:
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #0xc
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D5C8
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _0800D5FC
_0800D5C8:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	adds r2, r5, #0
	adds r2, #0xc4
	mov r6, sl
	ldr r0, [r6, #8]
	ldr r1, [r6, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r5, #0x34]
	ldrh r1, [r4, #0x1e]
	adds r0, r0, r1
	strh r0, [r4, #0x1e]
	movs r1, #1
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D5FC
	mov r2, r8
	ldrh r0, [r2, #0x20]
	ldrh r3, [r5, #0x36]
	adds r0, r0, r3
	strh r0, [r5, #0x34]
_0800D5FC:
	adds r4, r5, #0
	adds r4, #0xf0
	movs r1, #4
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D614
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	b _0800D658
_0800D614:
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	movs r6, #0x86
	lsls r6, r6, #1
	adds r2, r5, r6
	mov r3, sl
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	mov r0, sb
	ldrh r6, [r0, #2]
	adds r0, r6, #0
	movs r1, #3
	bl FUN_08234224
	cmp r0, #0
	beq _0800D642
	adds r0, #4
	b _0800D64E
_0800D642:
	ldr r0, _0800D6AC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_0800D64E:
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r0, r0, #8
	strh r0, [r4, #0x1e]
_0800D658:
	ldrh r0, [r5, #0x3a]
	cmp r0, #0
	beq _0800D66C
	subs r0, #1
	strh r0, [r5, #0x3a]
	strh r0, [r5, #0x3c]
	ldrh r1, [r5, #0x2a]
	movs r0, #2
	orrs r0, r1
	strh r0, [r5, #0x2a]
_0800D66C:
	movs r1, #2
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D720
	ldr r2, _0800D6B0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0800D6B4 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800D6B8 @ =0x0203B400
	adds r0, r0, r1
	add r4, sp, #0x20
	ldrh r3, [r0]
	ldrh r6, [r5, #0x3c]
	ldr r2, _0800D6BC @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	adds r7, r4, #0
	cmp r0, #0
	blt _0800D6C0
	asrs r1, r0, #0xc
	b _0800D6C6
	.align 2, 0
_0800D6AC: .4byte 0x030046A4
_0800D6B0: .4byte 0x030046B8
_0800D6B4: .4byte 0x000003FF
_0800D6B8: .4byte 0x0203B400
_0800D6BC: .4byte 0x085B0A08
_0800D6C0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0800D6C6:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	movs r0, #0xff
	ands r3, r0
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r6, r0
	cmp r0, #0
	blt _0800D6E2
	asrs r0, r0, #0xc
	b _0800D6E8
_0800D6E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0800D6E8:
	strh r0, [r4, #4]
	adds r1, r5, #0
	adds r1, #0xc4
	add r0, sp, #0x20
	ldrh r4, [r0]
	ldrh r3, [r1]
	adds r0, r4, r3
	strh r0, [r1]
	ldrh r3, [r7, #2]
	ldrh r6, [r1, #2]
	adds r0, r3, r6
	strh r0, [r1, #2]
	ldrh r2, [r7, #4]
	ldrh r6, [r1, #4]
	adds r0, r2, r6
	strh r0, [r1, #4]
	movs r1, #0x86
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r6, [r0]
	adds r4, r4, r6
	strh r4, [r0]
	ldrh r1, [r0, #2]
	adds r3, r3, r1
	strh r3, [r0, #2]
	ldrh r3, [r0, #4]
	adds r2, r2, r3
	strh r2, [r0, #4]
_0800D720:
	movs r6, #0x96
	lsls r6, r6, #1
	adds r4, r5, r6
	movs r1, #0x10
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D738
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _0800D762
_0800D738:
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r1, r5, #0
	adds r1, #0x40
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800D75A
	subs r0, #1
	strb r0, [r1]
	ldrh r1, [r4, #6]
	movs r0, #4
	orrs r0, r1
	b _0800D762
_0800D75A:
	movs r0, #5
	rsbs r0, r0, #0
	ldrh r1, [r4, #6]
	ands r0, r1
_0800D762:
	strh r0, [r4, #6]
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r4, r5, r0
	movs r1, #0x20
	ldrh r0, [r5, #0x2a]
	ands r0, r1
	cmp r0, #0
	beq _0800D7E4
	ldr r0, [r5, #4]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0800D7A8
	ldr r3, _0800D7A0 @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r1, #0x90
	orrs r0, r1
	ldr r1, _0800D7A4 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x40
	b _0800D7C6
	.align 2, 0
_0800D7A0: .4byte 0xFFFF0000
_0800D7A4: .4byte 0x0000FFFF
_0800D7A8:
	ldr r3, _0800D82C @ =0xFFFF0000
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r1, #0x40
	orrs r0, r1
	ldr r1, _0800D830 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	movs r1, #0x90
_0800D7C6:
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x28]
	ldr r1, [sp, #0x2c]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
_0800D7E4:
	adds r0, r5, #0
	adds r0, #0x45
	ldrb r0, [r0]
	ldrb r1, [r5, #3]
	cmp r0, r1
	beq _0800D7FE
	cmp r1, #0
	beq _0800D7FE
	ldr r0, _0800D834 @ =0xFFFFFDFF
	mov r2, sb
	ldrh r1, [r2, #6]
	ands r0, r1
	strh r0, [r2, #6]
_0800D7FE:
	adds r1, r5, #0
	adds r1, #0x41
	ldrb r0, [r1]
	cmp r0, #0
	beq _0800D838
	subs r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _0800D85A
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r1, [r5, #0x2e]
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800D850
	mov r0, r8
	adds r0, #0x34
	b _0800D858
	.align 2, 0
_0800D82C: .4byte 0xFFFF0000
_0800D830: .4byte 0x0000FFFF
_0800D834: .4byte 0xFFFFFDFF
_0800D838:
	adds r4, r5, #0
	adds r4, #0x8c
	ldrh r1, [r5, #0x2e]
	adds r0, r4, #0
	bl Video_SetActorSpritePltt
	ldrh r0, [r5, #0x2e]
	cmp r0, #0x79
	bne _0800D850
	mov r0, r8
	adds r0, #0x34
	b _0800D858
_0800D850:
	cmp r0, #0x7a
	bne _0800D85A
	mov r0, r8
	adds r0, #0x54
_0800D858:
	str r0, [r4, #0xc]
_0800D85A:
	adds r2, r5, #0
	adds r2, #0x46
	ldrb r3, [r5, #2]
	ldrb r1, [r2]
	cmp r3, r1
	beq _0800D8AC
	ldr r6, [r5, #8]
	cmp r6, #0
	beq _0800D8AC
	mov r4, sl
	ldrh r0, [r4]
	str r0, [sp]
	ldrb r0, [r5, #2]
	str r0, [sp, #4]
	bics r0, r1
	str r0, [sp, #8]
	ldrb r0, [r2]
	bics r0, r3
	str r0, [sp, #0xc]
	add r4, sp, #0x30
	adds r3, r5, #0
	adds r3, #0xc
	add r2, sp, #0x10
	movs r1, #3
_0800D88A:
	ldm r3!, {r0}
	stm r2!, {r0}
	subs r1, #1
	cmp r1, #0
	bge _0800D88A
	ldr r0, _0800D8C4 @ =0xFFFF0000
	ldr r1, [sp, #0x30]
	ands r1, r0
	movs r0, #8
	orrs r1, r0
	str r1, [sp, #0x30]
	mov r0, sp
	str r0, [r4, #4]
	adds r0, r6, #0
	adds r1, r4, #0
	bl Script_ExecById
_0800D8AC:
	ldr r0, [r5, #4]
	adds r0, #1
	str r0, [r5, #4]
	add sp, #0x38
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0800D8C4: .4byte 0xFFFF0000

