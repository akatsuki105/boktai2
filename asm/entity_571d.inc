	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080beadc
FUN_080beadc: @ 0x080BEADC
	ldr r3, _080BEAEC @ =0x000010E8
	adds r2, r0, r3
	str r1, [r2]
	ldr r1, _080BEAF0 @ =0x00000ECA
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr
	.align 2, 0
_080BEAEC: .4byte 0x000010E8
_080BEAF0: .4byte 0x00000ECA

	thumb_func_start FUN_080beaf4
FUN_080beaf4: @ 0x080BEAF4
	ldr r2, _080BEAFC @ =0x00000EC8
	adds r0, r0, r2
	strb r1, [r0]
	bx lr
	.align 2, 0
_080BEAFC: .4byte 0x00000EC8

	thumb_func_start FUN_080beb00
FUN_080beb00: @ 0x080BEB00
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, _080BEB20 @ =0x000010EC
	adds r0, r4, r3
	str r1, [r0]
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080beaf4
	ldr r0, _080BEB24 @ =0x00000ECA
	adds r4, r4, r0
	movs r0, #0
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BEB20: .4byte 0x000010EC
_080BEB24: .4byte 0x00000ECA

	thumb_func_start FUN_080beb28
FUN_080beb28: @ 0x080BEB28
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	bl FUN_08049e5c
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xec
	lsls r0, r0, #4
	adds r4, r4, r0
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080beb6c
FUN_080beb6c: @ 0x080BEB6C
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080BEB88 @ =0x00000FD1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEB8C
	adds r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	bl GetValuableItemID
	adds r5, r0, #0
	b _080BEBB0
	.align 2, 0
_080BEB88: .4byte 0x00000FD1
_080BEB8C:
	cmp r0, #7
	bhi _080BEBAC
	ldr r1, _080BEBA4 @ =0x00000FD3
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, r4, r0
	ldr r1, _080BEBA8 @ =0x00000EBC
	adds r0, r0, r1
	movs r5, #0
	ldrsb r5, [r0, r5]
	b _080BEBB0
	.align 2, 0
_080BEBA4: .4byte 0x00000FD3
_080BEBA8: .4byte 0x00000EBC
_080BEBAC:
	movs r5, #1
	rsbs r5, r5, #0
_080BEBB0:
	cmp r5, #0
	bge _080BEBCC
	movs r1, #0xb6
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	bl FUN_08047864
	bl FUN_08049e5c
	b _080BEC10
_080BEBCC:
	movs r0, #0xb6
	lsls r0, r0, #4
	adds r2, r4, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080BEC18 @ =0x00000EC4
	adds r4, r4, r1
	ldr r0, [r4]
	bl FUN_080478f0
	movs r0, #2
	movs r1, #0x10
	movs r2, #0x1c
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	adds r0, r5, #0
	bl FUN_08047a28
	ldr r0, [r4]
	bl VM_ParseStringRef
	adds r0, #0x4e
	adds r0, r0, r5
	bl Textbox_LookupString
	bl FUN_08049e30
_080BEC10:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BEC18: .4byte 0x00000EC4

	thumb_func_start FUN_080bec1c
FUN_080bec1c: @ 0x080BEC1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov sl, r0
	movs r7, #0
	adds r0, #0x80
	str r0, [sp]
	movs r1, #0
	str r1, [sp, #8]
	mov sb, r1
_080BEC36:
	movs r2, #0
	mov r8, r2
	mov r1, sb
	adds r1, #1
	mov r0, sl
	adds r0, #0xd8
	ldr r2, [sp, #8]
	adds r6, r2, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r5, r0, r1
_080BEC50:
	mov r1, sb
	add r1, r8
	adds r0, r1, #0
	bl GetValuableItemID
	adds r4, r0, #0
	cmp r4, #0
	blt _080BECA0
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	adds r0, r4, #0
	subs r0, #0x38
	cmp r0, #7
	bhi _080BEC94
	adds r0, r6, #0
	ldr r1, _080BEC90 @ =0x000002DF
	bl FUN_080b95bc
	b _080BECA8
	.align 2, 0
_080BEC90: .4byte 0x000002DF
_080BEC94:
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BECA8
_080BECA0:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BECA8:
	adds r5, #0x60
	adds r6, #0x60
	movs r2, #1
	add r8, r2
	mov r0, r8
	cmp r0, #3
	ble _080BEC50
	ldr r1, [sp, #8]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r1, r1, r2
	str r1, [sp, #8]
	movs r0, #4
	add sb, r0
	adds r7, #1
	cmp r7, #3
	ble _080BEC36
	movs r7, #0
_080BECCC:
	movs r1, #0
	mov r8, r1
	lsls r2, r7, #2
	mov sb, r2
	adds r0, r7, #1
	str r0, [sp, #4]
	adds r2, #0x11
	lsls r0, r7, #3
	add r0, sb
	lsls r0, r0, #5
	movs r1, #0xdb
	lsls r1, r1, #3
	add r1, sl
	adds r6, r0, r1
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #5
	ldr r1, [sp]
	adds r5, r0, r1
_080BECF2:
	mov r1, sb
	add r1, r8
	ldr r0, _080BED48 @ =0x00000ECC
	add r0, sl
	adds r0, r0, r1
	movs r4, #0
	ldrsb r4, [r0, r4]
	cmp r4, #0
	blt _080BED64
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r2, r4, #0
	adds r2, #0x68
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	adds r0, r6, #0
	mov r1, sl
	adds r1, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldr r0, _080BED4C @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #4
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r4, #4
	ldr r2, _080BED50 @ =0x08DAA8E4
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bhs _080BED54
	adds r0, r6, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_080b95bc
	b _080BED6C
	.align 2, 0
_080BED48: .4byte 0x00000ECC
_080BED4C: .4byte 0x030046A0
_080BED50: .4byte 0x08DAA8E4
_080BED54:
	adds r0, r6, #0
	ldr r1, _080BED60 @ =0x000002DF
	bl FUN_080b95bc
	b _080BED6C
	.align 2, 0
_080BED60: .4byte 0x000002DF
_080BED64:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
_080BED6C:
	adds r5, #0x60
	adds r6, #0x60
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #3
	ble _080BECF2
	ldr r7, [sp, #4]
	cmp r7, #2
	ble _080BECCC
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080bed90
FUN_080bed90: @ 0x080BED90
	push {r4, r5, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r1, _080BEDD4 @ =0x00000FD3
	adds r0, r5, r1
	ldrb r2, [r0]
	adds r0, r5, r2
	ldr r1, _080BEDD8 @ =0x00000EBC
	adds r0, r0, r1
	movs r1, #0
	ldrsb r1, [r0, r1]
	cmp r1, #0
	blt _080BEDE4
	ldr r0, _080BEDDC @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r4, [r1]
	add r0, sp, #4
	adds r1, r2, #0
	bl FUN_080b9938
	adds r0, r5, #0
	adds r0, #0x58
	ldr r2, _080BEDE0 @ =0x00000C78
	adds r1, r5, r2
	movs r2, #0
	str r2, [sp]
	add r2, sp, #4
	adds r3, r4, #0
	bl FUN_080b9658
	b _080BEDEC
	.align 2, 0
_080BEDD4: .4byte 0x00000FD3
_080BEDD8: .4byte 0x00000EBC
_080BEDDC: .4byte 0x08DAA8D8
_080BEDE0: .4byte 0x00000C78
_080BEDE4:
	ldr r1, _080BEDF4 @ =0x00000C78
	adds r0, r5, r1
	bl FUN_080b9724
_080BEDEC:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BEDF4: .4byte 0x00000C78

	thumb_func_start FUN_080bedf8
FUN_080bedf8: @ 0x080BEDF8
	push {r4, lr}
	movs r4, #0
_080BEDFC:
	adds r0, r4, #0
	bl GetValuableItemID
	subs r0, #0x38
	cmp r0, #7
	bhi _080BEE0C
	adds r0, r4, #0
	b _080BEE14
_080BEE0C:
	adds r4, #1
	cmp r4, #0xf
	ble _080BEDFC
	movs r0, #0x38
_080BEE14:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080bee1c
FUN_080bee1c: @ 0x080BEE1C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x44
	mov sb, r0
	bl FUN_080bedf8
	adds r6, r0, #0
	bl GetValuableItemID
	adds r4, r0, #0
	adds r1, r6, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	mov r5, sb
	adds r5, #0x80
	adds r0, r5, r0
	ldr r1, [r0]
	movs r2, #1
	mov r8, r2
	orrs r1, r2
	str r1, [r0]
	str r2, [sp, #0x2c]
	adds r0, r4, #0
	adds r0, #0x68
	str r0, [sp, #0x34]
	ldr r0, _080BEEE8 @ =0x000002DF
	mov sl, r0
	str r0, [sp, #0x3c]
	add r0, sp, #0xc
	adds r1, r6, #0
	bl FUN_080b9938
	add r7, sp, #0x1c
	subs r4, #0x28
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080b9938
	ldr r2, _080BEEEC @ =0x00000FD6
	add r2, sb
	ldrb r1, [r2]
	adds r1, #1
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r5, r0
	ldr r0, [r5]
	mov r1, r8
	orrs r0, r1
	str r0, [r5]
	add r6, sp, #0x2c
	str r1, [r6, #4]
	ldrb r0, [r2]
	add r0, sb
	ldr r1, _080BEEF0 @ =0x00000EBC
	adds r0, r0, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, #0x68
	add r5, sp, #0x34
	str r0, [r5, #4]
	add r4, sp, #0x3c
	mov r0, sl
	str r0, [r4, #4]
	add r0, sp, #0x14
	ldrb r1, [r2]
	bl FUN_080b9938
	add r0, sp, #0x24
	ldr r1, _080BEEF4 @ =0x00000FD3
	add r1, sb
	ldrb r1, [r1]
	bl FUN_080b9938
	ldr r1, _080BEEF8 @ =0x00000EDC
	add sb, r1
	str r5, [sp]
	str r4, [sp, #4]
	movs r0, #0xc
	str r0, [sp, #8]
	mov r0, sb
	adds r1, r6, #0
	add r2, sp, #0xc
	adds r3, r7, #0
	bl FUN_080b9a28
	ldr r0, _080BEEFC @ =0x0000038A
	bl PlaySound_082406e0
	add sp, #0x44
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BEEE8: .4byte 0x000002DF
_080BEEEC: .4byte 0x00000FD6
_080BEEF0: .4byte 0x00000EBC
_080BEEF4: .4byte 0x00000FD3
_080BEEF8: .4byte 0x00000EDC
_080BEEFC: .4byte 0x0000038A

	thumb_func_start FUN_080bef00
FUN_080bef00: @ 0x080BEF00
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	cmp r1, #0
	bne _080BEF1A
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #0
	bl FUN_080b98c0
	b _080BEF80
_080BEF1A:
	movs r2, #0
	ldr r0, _080BEF30 @ =0x00000FD3
	adds r4, r5, r0
	adds r0, #3
	adds r1, r5, r0
	ldrb r0, [r4]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BEF34
	movs r2, #4
	b _080BEF56
	.align 2, 0
_080BEF30: .4byte 0x00000FD3
_080BEF34:
	ldr r1, _080BEF6C @ =0x00000FD1
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEF56
	ldrb r0, [r4]
	bl GetValuableItemID
	adds r6, r0, #0
	ldrb r4, [r4]
	bl FUN_080bedf8
	movs r2, #4
	cmp r4, r0
	beq _080BEF56
	asrs r0, r6, #0x1f
	ands r2, r0
_080BEF56:
	cmp r2, #4
	bne _080BEF70
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	movs r1, #7
	bl FUN_080b98c0
	b _080BEF80
	.align 2, 0
_080BEF6C: .4byte 0x00000FD1
_080BEF70:
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
_080BEF80:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bef88
FUN_080bef88: @ 0x080BEF88
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080BEFBC @ =0x00000FD3
	adds r5, r4, r0
	ldr r2, _080BEFC0 @ =0x00000FD6
	adds r1, r4, r2
	ldrb r0, [r5]
	ldrb r1, [r1]
	cmp r0, r1
	bne _080BEFC8
	bl FUN_080bedf8
	strb r0, [r5]
	movs r1, #3
	ands r1, r0
	ldr r2, _080BEFC4 @ =0x00000FD1
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r5]
	lsrs r0, r0, #2
	adds r2, #1
	adds r1, r4, r2
	strb r0, [r1]
_080BEFB6:
	movs r0, #4
	b _080BEFEA
	.align 2, 0
_080BEFBC: .4byte 0x00000FD3
_080BEFC0: .4byte 0x00000FD6
_080BEFC4: .4byte 0x00000FD1
_080BEFC8:
	ldr r1, _080BEFF0 @ =0x00000FD1
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	bhi _080BEFE8
	ldrb r0, [r5]
	bl GetValuableItemID
	adds r6, r0, #0
	ldrb r4, [r5]
	bl FUN_080bedf8
	cmp r4, r0
	beq _080BEFB6
	cmp r6, #0
	blt _080BEFB6
_080BEFE8:
	movs r0, #0
_080BEFEA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080BEFF0: .4byte 0x00000FD1

	thumb_func_start FUN_080beff4
FUN_080beff4: @ 0x080BEFF4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xc2
	lsls r0, r0, #4
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fe8
	ldr r0, _080BF050 @ =0x00000BB8
	adds r1, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	movs r1, #0x1d
	bl FUN_080b9d94
	adds r0, r5, #0
	bl FUN_080beb6c
	adds r0, r5, #0
	bl FUN_080bec1c
	adds r0, r5, #0
	bl FUN_080bed90
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bef00
	ldr r1, _080BF054 @ =FUN_080bf058
	adds r0, r5, #0
	movs r2, #1
	bl FUN_080beb00
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF050: .4byte 0x00000BB8
_080BF054: .4byte FUN_080bf058

	thumb_func_start FUN_080bf058
FUN_080bf058: @ 0x080BF058
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r4, _080BF0B0 @ =0x030044E0
	ldrh r1, [r4]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080BF0B8
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080beaf4
	ldr r1, _080BF0B4 @ =0x00000BB8
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x18
	movs r2, #0x38
	movs r3, #1
	bl MainSprite_SetPose
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080BF08C
	b _080BF1B8
_080BF08C:
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r2, #0x87
	lsls r2, r2, #5
	adds r1, r5, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bhi _080BF0A8
	b _080BF1B8
_080BF0A8:
	movs r0, #0
	strb r0, [r1]
	b _080BF1B8
	.align 2, 0
_080BF0B0: .4byte 0x030044E0
_080BF0B4: .4byte 0x00000BB8
_080BF0B8:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080beaf4
	ldr r0, _080BF11C @ =0x00000BB8
	adds r6, r5, r0
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r6, #0
	bl MainSprite_AdvanceAnim
	ldrh r1, [r4, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF18C
	ldr r1, _080BF120 @ =0x00000FD3
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, r5, r0
	ldr r2, _080BF124 @ =0x00000EBC
	adds r0, r0, r2
	movs r1, #0
	ldrsb r1, [r0, r1]
	movs r3, #1
	cmp r1, #0
	blt _080BF110
	ldr r0, _080BF128 @ =0x030046A0
	ldr r0, [r0]
	movs r4, #0x91
	lsls r4, r4, #4
	adds r0, r0, r4
	movs r4, #0
	ldrsh r2, [r0, r4]
	ldr r0, _080BF12C @ =0x08DAA8D8
	lsls r1, r1, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r0, [r1]
	cmp r2, r0
	bhs _080BF10C
	movs r3, #0
_080BF10C:
	cmp r3, #0
	bne _080BF130
_080BF110:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BF1B8
	.align 2, 0
_080BF11C: .4byte 0x00000BB8
_080BF120: .4byte 0x00000FD3
_080BF124: .4byte 0x00000EBC
_080BF128: .4byte 0x030046A0
_080BF12C: .4byte 0x08DAA8D8
_080BF130:
	movs r0, #0xdd
	bl PlaySound_082406e0
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	bl FUN_080b9fd8
	movs r1, #0xc2
	lsls r1, r1, #4
	adds r2, r5, r1
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _080BF180 @ =0x00000C38
	adds r2, r5, r0
	ldr r1, _080BF184 @ =0x00000BD8
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
	adds r0, r4, #0
	movs r1, #0x3c
	bl FUN_080b9d94
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bef00
	ldr r1, _080BF188 @ =FUN_080bf1c0
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080beb00
	b _080BF1B8
	.align 2, 0
_080BF180: .4byte 0x00000C38
_080BF184: .4byte 0x00000BD8
_080BF188: .4byte FUN_080bf1c0
_080BF18C:
	movs r2, #0xfd
	lsls r2, r2, #4
	adds r4, r5, r2
	adds r0, r4, #0
	bl FUN_080b9f70
	cmp r0, #0
	beq _080BF1B8
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080beb6c
	adds r0, r5, #0
	bl FUN_080bed90
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080bef00
_080BF1B8:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bf1c0
FUN_080bf1c0: @ 0x080BF1C0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080BF224 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080BF242
	adds r0, r5, #0
	bl FUN_080bef88
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #5
	adds r0, r5, r1
	movs r2, #1
	rsbs r2, r2, #0
	adds r1, r2, #0
	bl FUN_080b98c0
	cmp r4, #4
	bne _080BF238
	ldr r0, _080BF228 @ =0x00000107
	bl PlaySound_082406e0
	ldr r1, _080BF22C @ =0x00000EC4
	adds r0, r5, r1
	ldr r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl FUN_080beb28
	ldr r1, _080BF230 @ =0x00000E58
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0x18
	adds r1, #0x71
	adds r2, r5, r1
	adds r1, r4, #0
	movs r3, #1
	bl FUN_080b9740
	ldr r1, _080BF234 @ =FUN_080bf29c
	adds r0, r5, #0
	movs r2, #0
	bl FUN_080beb00
	b _080BF288
	.align 2, 0
_080BF224: .4byte 0x030044E0
_080BF228: .4byte 0x00000107
_080BF22C: .4byte 0x00000EC4
_080BF230: .4byte 0x00000E58
_080BF234: .4byte FUN_080bf29c
_080BF238:
	movs r0, #0xc9
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _080BF256
_080BF242:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BF25C
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_080beff4
_080BF256:
	adds r4, r5, #0
	adds r4, #0x18
	b _080BF288
_080BF25C:
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r6, r5, r0
	adds r0, r6, #0
	bl FUN_080b9f70
	adds r4, r5, #0
	adds r4, #0x18
	cmp r0, #0
	beq _080BF288
	ldr r0, _080BF298 @ =0x00000BB8
	adds r1, r5, r0
	adds r0, r6, #0
	bl FUN_080b9fc4
	adds r0, r5, #0
	bl FUN_080beb6c
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080bef00
_080BF288:
	ldr r1, _080BF298 @ =0x00000BB8
	adds r0, r5, r1
	adds r1, r4, #0
	bl MainSprite_AdvanceAnim
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080BF298: .4byte 0x00000BB8

	thumb_func_start FUN_080bf29c
FUN_080bf29c: @ 0x080BF29C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080BF2CC @ =0x00000E58
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x18
	ldr r3, _080BF2D0 @ =0x00000EC9
	adds r2, r4, r3
	bl FUN_080b977c
	cmp r0, #1
	bne _080BF2D8
	bl FUN_08047864
	adds r0, r4, #0
	bl FUN_080bee1c
	ldr r1, _080BF2D4 @ =FUN_080bf2f0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_080beb00
	b _080BF2E8
	.align 2, 0
_080BF2CC: .4byte 0x00000E58
_080BF2D0: .4byte 0x00000EC9
_080BF2D4: .4byte FUN_080bf2f0
_080BF2D8:
	cmp r0, #0
	bne _080BF2E8
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_080beff4
_080BF2E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080bf2f0
FUN_080bf2f0: @ 0x080BF2F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	ldr r1, _080BF380 @ =0x00000EDC
	adds r0, r7, r1
	bl FUN_080b9adc
	cmp r0, #0
	beq _080BF374
	bl FUN_080bedf8
	adds r6, r0, #0
	bl GetValuableItemID
	mov r8, r0
	ldr r1, _080BF384 @ =0x00000FD6
	adds r0, r7, r1
	ldrb r0, [r0]
	subs r0, #0x10
	ldr r1, _080BF388 @ =0x00000ECC
	adds r5, r7, r1
	adds r0, r5, r0
	movs r4, #0
	ldrsb r4, [r0, r4]
	adds r0, r6, #0
	bl RemoveValuable
	ldr r1, _080BF38C @ =0x00000FD3
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r1, r4, #0
	bl SetValuable
	ldr r0, _080BF390 @ =0x030046A0
	ldr r2, [r0]
	movs r0, #0x91
	lsls r0, r0, #4
	adds r2, r2, r0
	ldr r0, _080BF394 @ =0x08DAA8D8
	lsls r1, r4, #4
	adds r0, #0xc
	adds r1, r1, r0
	ldr r1, [r1]
	ldrh r0, [r2]
	subs r0, r0, r1
	strh r0, [r2]
	mov r0, r8
	subs r0, #0x38
	adds r0, r5, r0
	mov r1, r8
	strb r1, [r0]
	subs r4, #0x38
	adds r5, r5, r4
	movs r0, #0xff
	strb r0, [r5]
	ldr r0, _080BF398 @ =0x000010E1
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080BF39C @ =0x00000111
	bl PlaySound_082406e0
	adds r0, r7, #0
	bl FUN_080beff4
_080BF374:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF380: .4byte 0x00000EDC
_080BF384: .4byte 0x00000FD6
_080BF388: .4byte 0x00000ECC
_080BF38C: .4byte 0x00000FD3
_080BF390: .4byte 0x030046A0
_080BF394: .4byte 0x08DAA8D8
_080BF398: .4byte 0x000010E1
_080BF39C: .4byte 0x00000111

	thumb_func_start FUN_080bf3a0
FUN_080bf3a0: @ 0x080BF3A0
	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	movs r0, #0xfd
	lsls r0, r0, #4
	adds r5, r4, r0
	movs r0, #0x1d
	str r0, [sp]
	adds r0, r5, #0
	movs r1, #1
	movs r2, #4
	movs r3, #0
	bl FUN_080b9ff8
	ldr r0, _080BF3F4 @ =0x00000BB8
	adds r1, r4, r0
	adds r0, r5, #0
	bl FUN_080b9fc4
	adds r0, r4, #0
	bl FUN_080bec1c
	adds r0, r4, #0
	bl FUN_080bed90
	adds r0, r4, #0
	bl FUN_080beb6c
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080bef00
	ldr r1, _080BF3F8 @ =FUN_080bf058
	adds r0, r4, #0
	movs r2, #1
	bl FUN_080beb00
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF3F4: .4byte 0x00000BB8
_080BF3F8: .4byte FUN_080bf058

	thumb_func_start FUN_080bf3fc
FUN_080bf3fc: @ 0x080BF3FC
	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BF44C @ =0x0000C091
	ldr r1, _080BF450 @ =0x00009F57
	bl GetFile
	adds r2, r0, #0
	ldr r0, _080BF454 @ =0x00000EB8
	adds r4, r4, r0
	str r2, [r4]
	movs r5, #0
	str r5, [sp, #0xc]
	str r5, [sp]
	movs r0, #1
	str r0, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	ldr r1, [r4]
	movs r0, #0
	movs r2, #3
	bl FUN_0822c398
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080BF44C: .4byte 0x0000C091
_080BF450: .4byte 0x00009F57
_080BF454: .4byte 0x00000EB8

	thumb_func_start FUN_080bf458
FUN_080bf458: @ 0x080BF458
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080BF480 @ =0x000092B3
	ldr r1, _080BF484 @ =0x0000A41A
	bl GetFile
	ldr r1, _080BF488 @ =0x00000EBC
	adds r4, r4, r1
	movs r1, #0xda
	lsls r1, r1, #1
	adds r0, r0, r1
	str r0, [r4]
	ldr r1, _080BF48C @ =0x030043F0
	ldr r2, _080BF490 @ =0x04000018
	bl CpuSet
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF480: .4byte 0x000092B3
_080BF484: .4byte 0x0000A41A
_080BF488: .4byte 0x00000EBC
_080BF48C: .4byte 0x030043F0
_080BF490: .4byte 0x04000018

	thumb_func_start FUN_080bf494
FUN_080bf494: @ 0x080BF494
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	ldr r4, _080BF6E4 @ =0x0000CB05
	ldr r1, _080BF6E8 @ =0x00005D04
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x38
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	movs r6, #0x38
	adds r6, r6, r7
	mov sb, r6
	mov r0, sb
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BF6EC @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x18
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r1!, {r3, r5}
	adds r0, r7, #0
	adds r0, #0x18
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BF6F0 @ =0x0000414C
	adds r0, r4, #0
	bl GetFile
	adds r2, r0, #0
	adds r1, r7, #0
	adds r1, #0x58
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r3, r5, r6}
	stm r1!, {r3, r5, r6}
	ldm r0!, {r4, r5}
	stm r1!, {r4, r5}
	adds r4, r7, #0
	adds r4, #0x58
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	ldr r1, _080BF6F4 @ =0xFFFF0000
	movs r0, #0
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r1
	str r0, [sp, #0x14]
	movs r1, #0
	adds r0, r7, #0
	adds r0, #0x78
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	add r6, sp, #0x10
	str r6, [sp, #0xc]
	adds r1, r4, #0
	movs r2, #0x29
	movs r3, #0x30
	bl MainSprite_Add
	movs r4, #0
	add r6, sp, #0x10
	mov r8, r4
	mov sl, sb
	adds r5, r7, #0
	adds r5, #0xd8
_080BF54A:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x90
	strh r0, [r6]
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0x38
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xf
	ble _080BF54A
	movs r4, #0
	adds r1, r7, #0
	adds r1, #0x18
	str r1, [sp, #0x1c]
	adds r2, r7, #0
	adds r2, #0x58
	str r2, [sp, #0x18]
	add r6, sp, #0x10
	mov sb, r4
	movs r3, #0xdb
	lsls r3, r3, #3
	adds r5, r7, r3
_080BF59E:
	asrs r1, r4, #2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	strh r0, [r6, #2]
	movs r1, #3
	ands r1, r4
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #8
	strh r0, [r6]
	mov r0, sb
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov r8, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	mov r1, sl
	movs r2, #0x68
	movs r3, #0x30
	bl MainSprite_Add
	adds r5, #0x60
	adds r4, #1
	cmp r4, #0xb
	ble _080BF59E
	movs r4, #0
	add r0, sp, #0x10
	strh r4, [r0]
	adds r5, r0, #0
	movs r0, #0x80
	strh r0, [r5, #2]
	ldr r2, _080BF6F8 @ =0x00000B58
	adds r0, r7, r2
	str r4, [sp]
	str r4, [sp, #4]
	mov r3, r8
	str r3, [sp, #8]
	str r5, [sp, #0xc]
	mov r1, sl
	movs r2, #0xcf
	movs r3, #0x30
	bl MainSprite_Add
	ldr r6, _080BF6FC @ =0x00000C18
	adds r0, r7, r6
	str r4, [sp]
	str r4, [sp, #4]
	mov r1, r8
	str r1, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x3c
	movs r3, #0x31
	bl MainSprite_Add
	movs r1, #0x90
	add r0, sp, #0x10
	strh r1, [r0]
	movs r0, #0x20
	strh r0, [r5, #2]
	ldr r3, _080BF700 @ =0x00000BB8
	adds r5, r7, r3
	str r4, [sp]
	str r4, [sp, #4]
	mov r6, r8
	str r6, [sp, #8]
	add r0, sp, #0x10
	str r0, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0x39
	movs r3, #0x30
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	ldr r1, [sp, #0x1c]
	movs r2, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _080BF704 @ =0x00000C78
	adds r0, r7, r1
	str r4, [sp]
	str r4, [sp, #4]
	str r6, [sp, #8]
	add r2, sp, #0x10
	str r2, [sp, #0xc]
	ldr r1, [sp, #0x18]
	movs r2, #0x18
	movs r3, #0x30
	bl MainSprite_Add
	add r0, sp, #0x10
	ldrh r0, [r0]
	subs r0, #0xb
	add r1, sp, #0x10
	strh r0, [r1]
	adds r6, r1, #0
	ldr r3, _080BF708 @ =0x00000CD8
	adds r5, r7, r3
	mov r8, r4
	movs r4, #3
_080BF678:
	mov r0, r8
	str r0, [sp]
	str r0, [sp, #4]
	movs r1, #0x3c
	mov sb, r1
	str r1, [sp, #8]
	str r6, [sp, #0xc]
	adds r0, r5, #0
	ldr r1, [sp, #0x18]
	movs r2, #0x19
	movs r3, #0x30
	bl MainSprite_Add
	ldrh r0, [r6]
	adds r0, #6
	strh r0, [r6]
	adds r5, #0x60
	subs r4, #1
	cmp r4, #0
	bge _080BF678
	movs r1, #0
	add r0, sp, #0x10
	strh r1, [r0]
	strh r1, [r0, #2]
	ldr r2, _080BF70C @ =0x00000E58
	adds r0, r7, r2
	str r1, [sp]
	str r1, [sp, #4]
	mov r3, sb
	str r3, [sp, #8]
	add r4, sp, #0x10
	str r4, [sp, #0xc]
	ldr r1, [sp, #0x1c]
	movs r2, #0x94
	movs r3, #0x11
	bl MainSprite_Add
	ldr r5, _080BF710 @ =0x00000EDC
	adds r0, r7, r5
	bl FUN_080b99a0
	movs r6, #0x80
	lsls r6, r6, #5
	adds r0, r7, r6
	bl FUN_080b9814
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF6E4: .4byte 0x0000CB05
_080BF6E8: .4byte 0x00005D04
_080BF6EC: .4byte 0x0000B343
_080BF6F0: .4byte 0x0000414C
_080BF6F4: .4byte 0xFFFF0000
_080BF6F8: .4byte 0x00000B58
_080BF6FC: .4byte 0x00000C18
_080BF700: .4byte 0x00000BB8
_080BF704: .4byte 0x00000C78
_080BF708: .4byte 0x00000CD8
_080BF70C: .4byte 0x00000E58
_080BF710: .4byte 0x00000EDC

	thumb_func_start FUN_080bf714
FUN_080bf714: @ 0x080BF714
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BF72E
	bl FUN_0823d340
	movs r2, #0xec
	lsls r2, r2, #4
	adds r1, r4, r2
	str r0, [r1]
_080BF72E:
	bl FUN_08049f5c
	movs r0, #0
	movs r1, #0x10
	movs r2, #0x1e
	movs r3, #2
	bl FUN_08047b8c
	movs r0, #1
	bl FUN_080477e4
	ldr r0, _080BF750 @ =0x0000A41A
	bl FUN_08047dc0
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF750: .4byte 0x0000A41A

	thumb_func_start FUN_080bf754
FUN_080bf754: @ 0x080BF754
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0x43
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BF76A
	bl Script_GetValue
	adds r5, r0, #0
	b _080BF76C
_080BF76A:
	movs r5, #0
_080BF76C:
	bl FUN_080bedf8
	bl GetValuableItemID
	adds r7, r0, #0
	movs r0, #0x4f
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BF7D2
	movs r4, #0
	cmp r4, r5
	bge _080BF7A8
_080BF786:
	bl Script_GetValue
	adds r1, r0, #0
	ldr r2, _080BF7EC @ =0x00000ECC
	adds r0, r6, r2
	adds r2, r0, r4
	strb r1, [r2]
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r7, r0
	bne _080BF7A2
	movs r0, #0xff
	orrs r1, r0
	strb r1, [r2]
_080BF7A2:
	adds r4, #1
	cmp r4, r5
	blt _080BF786
_080BF7A8:
	cmp r4, #0xb
	bgt _080BF7C0
	ldr r0, _080BF7EC @ =0x00000ECC
	adds r2, r6, r0
	movs r3, #0xff
_080BF7B2:
	adds r1, r2, r4
	ldrb r0, [r1]
	orrs r0, r3
	strb r0, [r1]
	adds r4, #1
	cmp r4, #0xb
	ble _080BF7B2
_080BF7C0:
	ldr r2, _080BF7F0 @ =0x00000ED4
	adds r1, r6, r2
	movs r4, #3
_080BF7C6:
	ldrb r0, [r1]
	strb r0, [r1, #4]
	adds r1, #1
	subs r4, #1
	cmp r4, #0
	bge _080BF7C6
_080BF7D2:
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080BF7E6
	bl FUN_0823d340
	ldr r2, _080BF7F4 @ =0x00000EC4
	adds r1, r6, r2
	str r0, [r1]
_080BF7E6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080BF7EC: .4byte 0x00000ECC
_080BF7F0: .4byte 0x00000ED4
_080BF7F4: .4byte 0x00000EC4

	thumb_func_start FUN_080bf7f8
FUN_080bf7f8: @ 0x080BF7F8
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x65
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080BF818
	bl Script_GetValue
	ldr r2, _080BF814 @ =0x000010E4
	adds r1, r4, r2
	str r0, [r1]
	b _080BF81E
	.align 2, 0
_080BF814: .4byte 0x000010E4
_080BF818:
	ldr r2, _080BF824 @ =0x000010E4
	adds r0, r4, r2
	str r1, [r0]
_080BF81E:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF824: .4byte 0x000010E4

	thumb_func_start FUN_080bf828
FUN_080bf828: @ 0x080BF828
	push {lr}
	adds r2, r0, #0
	ldr r0, _080BF84C @ =0x00000ECA
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BF846
	ldr r1, _080BF850 @ =FUN_080bf854
	adds r0, r2, #0
	bl FUN_080beadc
_080BF846:
	pop {r0}
	bx r0
	.align 2, 0
_080BF84C: .4byte 0x00000ECA
_080BF850: .4byte FUN_080bf854

	thumb_func_start FUN_080bf854
FUN_080bf854: @ 0x080BF854
	push {r4, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r1, _080BF898 @ =0x00000EC8
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080BF8AC
	ldr r0, _080BF89C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080BF8AC
	ldr r0, _080BF8A0 @ =0x00000119
	bl PlaySound_082406e0
	movs r0, #4
	str r0, [sp]
	ldr r0, _080BF8A4 @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	ldr r1, _080BF8A8 @ =FUN_080bf8c4
	adds r0, r4, #0
	bl FUN_080beadc
	b _080BF8B8
	.align 2, 0
_080BF898: .4byte 0x00000EC8
_080BF89C: .4byte 0x030044E0
_080BF8A0: .4byte 0x00000119
_080BF8A4: .4byte 0x0000FFFF
_080BF8A8: .4byte FUN_080bf8c4
_080BF8AC:
	ldr r1, _080BF8C0 @ =0x000010EC
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080BF8B8:
	add sp, #0xc
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF8C0: .4byte 0x000010EC

	thumb_func_start FUN_080bf8c4
FUN_080bf8c4: @ 0x080BF8C4
	push {r4, lr}
	sub sp, #0x10
	adds r4, r0, #0
	ldr r0, _080BF91C @ =0x00000ECA
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080BF914
	ldr r1, _080BF920 @ =0x000010E4
	adds r0, r4, r1
	ldr r2, [r0]
	cmp r2, #0
	beq _080BF90E
	ldr r1, _080BF924 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r1
	movs r1, #2
	orrs r0, r1
	str r0, [sp, #8]
	ldr r1, _080BF928 @ =0x000010E1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp]
	adds r1, #1
	adds r0, r4, r1
	ldrb r0, [r0]
	str r0, [sp, #4]
	add r1, sp, #8
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl Script_ExecById
_080BF90E:
	adds r0, r4, #0
	bl KillEntity
_080BF914:
	add sp, #0x10
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080BF91C: .4byte 0x00000ECA
_080BF920: .4byte 0x000010E4
_080BF924: .4byte 0xFFFF0000
_080BF928: .4byte 0x000010E1

