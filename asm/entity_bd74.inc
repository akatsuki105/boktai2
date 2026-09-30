	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080846c8
FUN_080846c8: @ 0x080846C8
	push {r4, lr}
	ldr r4, _080846F0 @ =0x03002BFC
	ldr r0, [r4]
	cmp r0, #0
	beq _080846E8
	adds r0, #0xb1
	ldrb r0, [r0]
	cmp r0, #6
	bne _080846E8
	ldr r0, _080846F4 @ =0x0000020E
	bl PlaySound_082406e0
	ldr r0, [r4]
	adds r0, #0xb5
	movs r1, #1
	strb r1, [r0]
_080846E8:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080846F0: .4byte 0x03002BFC
_080846F4: .4byte 0x0000020E

	thumb_func_start FUN_080846f8
FUN_080846f8: @ 0x080846F8
	push {lr}
	ldr r0, _0808470C @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _08084708
	movs r1, #7
	bl FUN_08084c30
_08084708:
	pop {r0}
	bx r0
	.align 2, 0
_0808470C: .4byte 0x03002BFC

	thumb_func_start FUN_08084710
FUN_08084710: @ 0x08084710
	push {lr}
	ldr r0, _08084728 @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _08084722
	adds r0, #0xb1
	ldrb r0, [r0]
	cmp r0, #6
	beq _0808472C
_08084722:
	movs r0, #0
	b _0808472E
	.align 2, 0
_08084728: .4byte 0x03002BFC
_0808472C:
	movs r0, #1
_0808472E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08084734
FUN_08084734: @ 0x08084734
	push {lr}
	adds r2, r0, #0
	ldr r0, _08084750 @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _0808474A
	adds r0, #0xc0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2]
	str r1, [r2, #4]
_0808474A:
	pop {r0}
	bx r0
	.align 2, 0
_08084750: .4byte 0x03002BFC

	thumb_func_start FUN_08084754
FUN_08084754: @ 0x08084754
	push {lr}
	ldr r3, _08084790 @ =0x03002BFC
	ldr r0, [r3]
	cmp r0, #0
	beq _0808478A
	adds r2, r0, #0
	adds r2, #0xac
	adds r0, #0xae
	ldrb r1, [r0]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	lsls r0, r0, #0x10
	ldr r1, _08084794 @ =0x13FF0000
	cmp r0, r1
	bls _0808477A
	movs r0, #0xa0
	lsls r0, r0, #5
	strh r0, [r2]
_0808477A:
	ldr r0, [r3]
	adds r0, #0xb0
	movs r1, #1
	strb r1, [r0]
	ldr r0, [r3]
	adds r0, #0xb8
	movs r1, #0
	strh r1, [r0]
_0808478A:
	pop {r0}
	bx r0
	.align 2, 0
_08084790: .4byte 0x03002BFC
_08084794: .4byte 0x13FF0000

	thumb_func_start FUN_08084798
FUN_08084798: @ 0x08084798
	push {lr}
	adds r1, r0, #0
	ldr r0, _080847AC @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	beq _080847A8
	adds r0, #0xb8
	strh r1, [r0]
_080847A8:
	pop {r0}
	bx r0
	.align 2, 0
_080847AC: .4byte 0x03002BFC

	thumb_func_start FUN_080847b0
FUN_080847b0: @ 0x080847B0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x2e]
	adds r0, #1
	movs r5, #0
	strh r0, [r3, #0x2e]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _0808485E
	movs r0, #0x18
	ldrsh r2, [r3, r0]
	ldr r1, [r3, #0x28]
	movs r4, #0
	ldrsh r0, [r1, r4]
	subs r2, r2, r0
	adds r4, r1, #0
	cmp r2, #0
	bge _080847D8
	rsbs r2, r2, #0
_080847D8:
	movs r6, #0x1c
	ldrsh r1, [r3, r6]
	movs r6, #4
	ldrsh r0, [r4, r6]
	subs r1, r1, r0
	cmp r1, #0
	bge _080847E8
	rsbs r1, r1, #0
_080847E8:
	cmp r2, #0x7f
	bgt _080847F0
	cmp r1, #0x7f
	ble _0808485E
_080847F0:
	movs r0, #0x32
	ldrsh r2, [r3, r0]
	ldrh r1, [r3, #0x2e]
	movs r0, #0x10
	subs r0, r0, r1
	muls r0, r2, r0
	asrs r5, r0, #4
	ldrh r0, [r3, #0x30]
	adds r0, #1
	movs r1, #0xff
	ands r0, r1
	strh r0, [r3, #0x30]
	ldr r2, _08084828 @ =0x085B0A08
	movs r1, #0x30
	ldrsh r0, [r3, r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r0, [r0, r6]
	muls r0, r5, r0
	cmp r0, #0
	blt _0808482C
	asrs r1, r0, #0xc
	b _08084832
	.align 2, 0
_08084828: .4byte 0x085B0A08
_0808482C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084832:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r3, #0x18]
	ldrh r1, [r3, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08084850
	asrs r1, r0, #0xc
	b _08084856
_08084850:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084856:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	b _08084868
_0808485E:
	strh r5, [r3, #0x2c]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
_08084868:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084870
FUN_08084870: @ 0x08084870
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldr r0, _0808491C @ =0x000003A6
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08084920 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _0808488E
	b _0808499A
_0808488E:
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r1, [r0]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0xd4
	adds r6, r7, r0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	ldr r1, _08084924 @ =0xFFFFFDFF
	ands r0, r1
	str r0, [r6]
	adds r0, r7, #0
	adds r0, #0xc0
	str r0, [r6, #0x28]
	ldr r5, _08084928 @ =0x0203B400
	ldr r4, _0808492C @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	adds r3, #0x5b
	ands r0, r3
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrh r1, [r1]
	ldr r2, _08084930 @ =0x000001FF
	mov ip, r2
	mov r2, ip
	ands r1, r2
	movs r2, #0xc0
	lsls r2, r2, #2
	adds r1, r1, r2
	strh r1, [r6, #0x32]
	adds r0, #1
	ands r0, r3
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	asrs r0, r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r6, #0x30]
	adds r0, r7, #0
	adds r0, #0xd0
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #1
	bl FUN_0822dafc
	ldr r2, _08084934 @ =0x085B0A08
	movs r3, #0x30
	ldrsh r0, [r6, r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0x32
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _08084938
	asrs r1, r0, #0xc
	b _0808493E
	.align 2, 0
_0808491C: .4byte 0x000003A6
_08084920: .4byte 0x0000FFFF
_08084924: .4byte 0xFFFFFDFF
_08084928: .4byte 0x0203B400
_0808492C: .4byte 0x030046B8
_08084930: .4byte 0x000001FF
_08084934: .4byte 0x085B0A08
_08084938:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0808493E:
	ldr r2, [r6, #0x28]
	ldrh r0, [r2]
	adds r0, r0, r1
	strh r0, [r6, #0x18]
	ldrh r0, [r2, #2]
	strh r0, [r6, #0x1a]
	ldr r3, _08084968 @ =0x085B0A08
	ldrh r1, [r6, #0x30]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0x32
	ldrsh r0, [r6, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _0808496C
	asrs r1, r0, #0xc
	b _08084972
	.align 2, 0
_08084968: .4byte 0x085B0A08
_0808496C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084972:
	ldrh r0, [r2, #4]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r6, #0x1c]
	ldr r0, _080849A0 @ =FUN_080847b0
	str r0, [r6, #0x38]
	movs r0, #1
	strh r0, [r6, #0x2c]
	strh r2, [r6, #0x2e]
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _0808499A
	strh r2, [r1]
_0808499A:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080849A0: .4byte FUN_080847b0

	thumb_func_start FUN_080849a4
FUN_080849a4: @ 0x080849A4
	push {r4, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	ldrh r0, [r4, #0x2e]
	adds r2, r0, #1
	strh r2, [r4, #0x2e]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _08084A00
	ldrh r0, [r4, #0x34]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x36]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	movs r0, #0x34
	ldrsh r1, [r4, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r4, #0x34]
	movs r0, #0x36
	ldrsh r1, [r4, r0]
	lsls r0, r1, #3
	subs r0, r0, r1
	asrs r0, r0, #3
	strh r0, [r4, #0x36]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bne _080849F2
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #4
	bl FUN_0822dafc
_080849F2:
	ldrh r0, [r4, #0x2e]
	cmp r0, #0xa
	bne _08084A0C
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	b _08084A08
_08084A00:
	movs r0, #0
	strh r0, [r4, #0x2c]
	ldr r0, [r4]
	movs r1, #1
_08084A08:
	orrs r0, r1
	str r0, [r4]
_08084A0C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084a14
FUN_08084a14: @ 0x08084A14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, _08084AE0 @ =0x0000020D
	bl PlaySound_082406e0
	ldr r7, _08084AE4 @ =0x030046B8
	ldr r0, _08084AE8 @ =0x000003FF
	mov sl, r0
	movs r1, #0
	str r1, [sp]
	adds r6, r5, #0
	adds r6, #0xd4
	adds r4, r6, #0
	movs r2, #0xff
	mov sb, r2
	movs r3, #0xb
	mov r8, r3
_08084A40:
	ldr r1, [r4]
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	ldr r0, _08084AEC @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r4]
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r1, [r0]
	ldr r0, [r7]
	adds r0, #1
	mov r2, sl
	ands r0, r2
	str r0, [r7]
	lsls r0, r0, #1
	ldr r3, _08084AF0 @ =0x0203B400
	adds r0, r0, r3
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	adds r2, #4
	adds r0, r6, #0
	bl FUN_0822dafc
	adds r0, r5, #0
	adds r0, #0xc0
	ldrh r0, [r0]
	strh r0, [r4, #0x18]
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r0, [r0]
	strh r0, [r4, #0x1a]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrh r0, [r0]
	strh r0, [r4, #0x1c]
	ldr r0, [r7]
	adds r0, #1
	mov r1, sl
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r2, _08084AF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0x60
	bl Mod
	adds r2, r0, #0
	adds r2, #0x30
	ldr r0, [r7]
	adds r0, #1
	mov r3, sl
	ands r0, r3
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _08084AF0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	ldr r3, [sp]
	adds r1, r3, r0
	mov r0, sb
	ands r1, r0
	adds r0, r1, #0
	adds r0, #0x40
	mov r3, sb
	ands r0, r3
	lsls r0, r0, #1
	ldr r3, _08084AF4 @ =0x085B0A08
	adds r0, r0, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08084AF8
	asrs r0, r0, #0xc
	b _08084AFE
	.align 2, 0
_08084AE0: .4byte 0x0000020D
_08084AE4: .4byte 0x030046B8
_08084AE8: .4byte 0x000003FF
_08084AEC: .4byte 0xFFFFFDFF
_08084AF0: .4byte 0x0203B400
_08084AF4: .4byte 0x085B0A08
_08084AF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08084AFE:
	strh r0, [r4, #0x34]
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	ldr r1, _08084B18 @ =0x085B0A08
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _08084B1C
	asrs r1, r0, #0xc
	b _08084B22
	.align 2, 0
_08084B18: .4byte 0x085B0A08
_08084B1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08084B22:
	movs r0, #0
	strh r1, [r4, #0x36]
	ldr r1, _08084B58 @ =FUN_080849a4
	str r1, [r4, #0x38]
	movs r1, #1
	strh r1, [r4, #0x2c]
	strh r0, [r4, #0x2e]
	ldr r0, [sp]
	adds r0, #0x14
	str r0, [sp]
	adds r4, #0x3c
	adds r6, #0x3c
	subs r1, #2
	add r8, r1
	mov r2, r8
	cmp r2, #0
	blt _08084B46
	b _08084A40
_08084B46:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084B58: .4byte FUN_080849a4

	thumb_func_start FUN_08084b5c
FUN_08084b5c: @ 0x08084B5C
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xd4
	movs r7, #0
	movs r6, #0xb
_08084B68:
	ldrh r0, [r4, #0x2c]
	cmp r0, #0
	beq _08084B84
	movs r0, #0x86
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r2, r2, r7
	adds r0, r5, #0
	adds r0, #0xd0
	ldr r1, [r0]
	ldr r2, [r2]
	adds r0, r4, #0
	bl _call_via_r2
_08084B84:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _08084B68
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084b94
FUN_08084b94: @ 0x08084B94
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0xd4
	movs r5, #0xb
_08084B9C:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _08084B9C
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_08084bb0
FUN_08084bb0: @ 0x08084BB0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _08084C28 @ =0x000003A6
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _08084C2C @ =0x00001C1E
	bl GetParticleGroup
	adds r1, r4, #0
	adds r1, #0xd0
	str r0, [r1]
	adds r5, r1, #0
	movs r0, #0
	mov r8, r0
	adds r4, #0xd4
	movs r7, #4
	rsbs r7, r7, #0
	movs r6, #0xb
_08084BE2:
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl Particle_SetOffset
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #1
	strb r0, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	mov r1, r8
	strh r1, [r4, #0x2c]
	strh r1, [r4, #0x2e]
	adds r4, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _08084BE2
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08084C28: .4byte 0x000003A6
_08084C2C: .4byte 0x00001C1E

	thumb_func_start FUN_08084c30
FUN_08084c30: @ 0x08084C30
	mov ip, r0
	adds r0, #0xb1
	movs r3, #0
	strb r1, [r0]
	movs r2, #0xea
	lsls r2, r2, #2
	add r2, ip
	ldr r1, _08084C54 @ =0x085ABFC8
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
	mov r0, ip
	adds r0, #0xb2
	strh r3, [r0]
	bx lr
	.align 2, 0
_08084C54: .4byte 0x085ABFC8

	thumb_func_start FUN_08084c58
FUN_08084c58: @ 0x08084C58
	push {lr}
	adds r3, r0, #0
	adds r0, #0xac
	ldrh r0, [r0]
	cmp r0, #0
	beq _08084C96
	ldr r0, [r3, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #0x18]
	ldr r0, [r3, #0x60]
	ands r0, r1
	str r0, [r3, #0x60]
	adds r1, r3, #0
	adds r1, #0xa8
	movs r2, #0
	movs r0, #1
	strh r0, [r1]
	adds r1, #2
	strh r0, [r1]
	adds r1, #0xa
	movs r0, #0x50
	strb r0, [r1]
	adds r0, r3, #0
	adds r0, #0xb5
	strb r2, [r0]
	adds r0, r3, #0
	movs r1, #1
	bl FUN_08084c30
_08084C96:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084c9c
FUN_08084c9c: @ 0x08084C9C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xaa
	ldrh r0, [r4]
	adds r0, #4
	strh r0, [r4]
	ldr r1, _08084CE4 @ =0x0000FFFF
	adds r6, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _08084CC2
	movs r0, #0x20
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08084c30
_08084CC2:
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r5, #0
	adds r1, #0xa8
	strh r0, [r1]
	ands r0, r6
	cmp r0, #0
	bne _08084CDE
	movs r0, #1
	strh r0, [r1]
_08084CDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08084CE4: .4byte 0x0000FFFF

	thumb_func_start FUN_08084ce8
FUN_08084ce8: @ 0x08084CE8
	push {r4, lr}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0xaa
	ldrh r0, [r1]
	cmp r0, #4
	bhi _08084D1C
	adds r0, r4, #0
	bl FUN_08084a14
	adds r1, r4, #0
	adds r1, #0xac
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x18]
	ldr r0, [r4, #0x60]
	orrs r0, r1
	str r0, [r4, #0x60]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08084c30
	b _08084D3C
_08084D1C:
	subs r0, #4
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r4, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r4, #0
	adds r1, #0xa8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _08084D3C
	movs r0, #1
	strh r0, [r1]
_08084D3C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08084d44
FUN_08084d44: @ 0x08084D44
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r2, r4, #0
	adds r2, #0xac
	ldrh r0, [r2]
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bls _08084D62
	strh r1, [r2]
	adds r0, r4, #0
	movs r1, #4
	bl FUN_08084c30
	b _08084D6E
_08084D62:
	cmp r0, #0
	bne _08084D6E
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08084c30
_08084D6E:
	adds r0, r4, #0
	adds r0, #0xac
	ldrh r1, [r0]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r5, r4, #0
	adds r5, #0xaa
	strh r1, [r5]
	ldr r3, _08084DBC @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084DC0 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084DC4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r5]
	adds r1, r1, r0
	strh r1, [r5]
	ldrh r2, [r5]
	adds r1, r4, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084DBC: .4byte 0x030046B8
_08084DC0: .4byte 0x000003FF
_08084DC4: .4byte 0x0203B400

	thumb_func_start FUN_08084dc8
FUN_08084dc8: @ 0x08084DC8
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xac
	ldrh r0, [r4]
	adds r0, #0x60
	strh r0, [r4]
	lsls r0, r0, #0x10
	ldr r1, _08084E44 @ =0x13FF0000
	cmp r0, r1
	bls _08084DF4
	movs r0, #0xba
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0xa0
	lsls r0, r0, #5
	strh r0, [r4]
	adds r0, r5, #0
	movs r1, #6
	bl FUN_08084c30
_08084DF4:
	adds r0, r5, #0
	bl FUN_08084870
	ldrh r1, [r4]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084E48 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084E4C @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084E50 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084E44: .4byte 0x13FF0000
_08084E48: .4byte 0x030046B8
_08084E4C: .4byte 0x000003FF
_08084E50: .4byte 0x0203B400

	thumb_func_start FUN_08084e54
FUN_08084e54: @ 0x08084E54
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xac
	ldrh r0, [r4]
	subs r0, #0x60
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc0
	lsls r1, r1, #4
	cmp r0, r1
	bhi _08084E78
	strh r1, [r4]
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08084c30
_08084E78:
	ldrh r1, [r4]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084EC0 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084EC4 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084EC8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r0, r5, #0
	adds r0, #0xa8
	strh r1, [r0]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084EC0: .4byte 0x030046B8
_08084EC4: .4byte 0x000003FF
_08084EC8: .4byte 0x0203B400

	thumb_func_start FUN_08084ecc
FUN_08084ecc: @ 0x08084ECC
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r0, #0xac
	ldrh r1, [r0]
	ldr r0, _08084EE4 @ =0x000013FF
	cmp r1, r0
	bls _08084EE8
	adds r0, r5, #0
	bl FUN_08084870
	b _08084EF8
	.align 2, 0
_08084EE4: .4byte 0x000013FF
_08084EE8:
	adds r1, r5, #0
	adds r1, #0xb5
	movs r0, #0
	strb r0, [r1]
	adds r0, r5, #0
	movs r1, #5
	bl FUN_08084c30
_08084EF8:
	adds r4, r5, #0
	adds r4, #0xba
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _08084F14
	ldr r0, _08084F6C @ =0x0000020F
	bl PlaySound_082406e0
	movs r0, #0
	strh r0, [r4]
_08084F14:
	adds r0, r5, #0
	adds r0, #0xac
	ldrh r1, [r0]
	lsrs r1, r1, #6
	adds r1, #0x20
	adds r4, r5, #0
	adds r4, #0xaa
	strh r1, [r4]
	ldr r3, _08084F70 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _08084F74 @ =0x000003FF
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _08084F78 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	lsrs r1, r1, #3
	bl Mod
	ldrh r1, [r4]
	adds r1, r1, r0
	strh r1, [r4]
	ldrh r2, [r4]
	adds r1, r5, #0
	adds r1, #0xb4
	ldrb r1, [r1]
	muls r1, r2, r1
	asrs r1, r1, #7
	asrs r0, r0, #1
	adds r1, r1, r0
	adds r2, r5, #0
	adds r2, #0xa8
	strh r1, [r2]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x78
	bls _08084F66
	movs r0, #0x78
	strh r0, [r2]
_08084F66:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_08084F6C: .4byte 0x0000020F
_08084F70: .4byte 0x030046B8
_08084F74: .4byte 0x000003FF
_08084F78: .4byte 0x0203B400

	thumb_func_start FUN_08084f7c
FUN_08084f7c: @ 0x08084F7C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	adds r1, r6, #0
	adds r1, #0xaa
	ldrh r0, [r1]
	cmp r0, #0xc
	bhi _0808506C
	movs r7, #0
	movs r0, #0xc0
	adds r0, r0, r6
	mov sb, r0
	movs r1, #0xc4
	adds r1, r1, r6
	mov r8, r1
	movs r2, #0xac
	adds r2, r2, r6
	mov sl, r2
_08084FA6:
	mov r3, sb
	movs r0, #0
	ldrsh r2, [r3, r0]
	ldr r1, _08085064 @ =0x03002BE0
	lsls r0, r7, #2
	adds r5, r0, r1
	ldr r4, [r5]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	subs r2, r2, r0
	mov r3, r8
	movs r0, #0
	ldrsh r1, [r3, r0]
	movs r3, #0x30
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	adds r0, r2, #0
	cmp r2, #0
	bge _08084FCE
	rsbs r0, r2, #0
_08084FCE:
	movs r1, #0x80
	lsls r1, r1, #1
	cmp r0, r1
	bgt _08085038
	adds r0, r3, #0
	cmp r3, #0
	bge _08084FDE
	rsbs r0, r3, #0
_08084FDE:
	cmp r0, r1
	bgt _08085038
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r3, #0
	muls r1, r3, r1
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #9
	cmp r0, r1
	bgt _08085038
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0x64
	strh r0, [r1]
	ldr r0, [r5]
	ldr r1, _08085068 @ =0x000003D2
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	adds r0, r2, #0
	adds r1, r3, #0
	bl ArcTan2_8
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	ldr r2, [r5]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r2, r3
	strb r0, [r2]
	ldr r0, [r5]
	movs r1, #0x1e
	movs r2, #0xd8
	lsls r2, r2, #1
	adds r0, r0, r2
	strh r1, [r0]
_08085038:
	adds r7, #1
	cmp r7, #1
	ble _08084FA6
	adds r0, r6, #0
	bl FUN_08084a14
	movs r0, #0
	mov r3, sl
	strh r0, [r3]
	ldr r0, [r6, #0x18]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #0x18]
	ldr r0, [r6, #0x60]
	orrs r0, r1
	str r0, [r6, #0x60]
	adds r0, r6, #0
	movs r1, #0
	bl FUN_08084c30
	b _0808508C
	.align 2, 0
_08085064: .4byte 0x03002BE0
_08085068: .4byte 0x000003D2
_0808506C:
	subs r0, #0xc
	strh r0, [r1]
	ldrh r1, [r1]
	adds r0, r6, #0
	adds r0, #0xb4
	ldrb r0, [r0]
	muls r0, r1, r0
	asrs r0, r0, #7
	adds r1, r6, #0
	adds r1, #0xa8
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _0808508C
	movs r0, #1
	strh r0, [r1]
_0808508C:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0808509c
FUN_0808509c: @ 0x0808509C
	push {lr}
	mov ip, r0
	adds r0, #0xb0
	ldrb r0, [r0]
	cmp r0, #0
	bne _080850D0
	mov r1, ip
	adds r1, #0xb8
	ldrh r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	beq _080850B8
	subs r0, #1
	b _080850CE
_080850B8:
	mov r1, ip
	adds r1, #0xac
	mov r0, ip
	adds r0, #0xaf
	ldrb r2, [r0]
	ldrh r0, [r1]
	cmp r0, r2
	bhs _080850CC
	strh r3, [r1]
	b _080850D0
_080850CC:
	subs r0, r0, r2
_080850CE:
	strh r0, [r1]
_080850D0:
	mov r0, ip
	adds r0, #0xb5
	ldrb r0, [r0]
	cmp r0, #0
	beq _08085138
	mov r1, ip
	adds r1, #0xb4
	ldrb r0, [r1]
	adds r0, #6
	strb r0, [r1]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080850EE
	movs r0, #0x7f
	strb r0, [r1]
_080850EE:
	mov r1, ip
	adds r1, #0xb6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _08085118 @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _0808511C
	mov r2, ip
	adds r2, #0xc8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, ip
	str r0, [r3, #0x34]
	str r1, [r3, #0x38]
	adds r0, r2, #0
	b _0808512E
	.align 2, 0
_08085118: .4byte 0x0000FFFF
_0808511C:
	mov r0, ip
	adds r0, #0xc0
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, ip
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	mov r0, ip
	adds r0, #0xc8
_0808512E:
	mov r2, ip
	adds r2, #0x7c
	ldr r1, [r0, #4]
	ldr r0, [r0]
	b _08085162
_08085138:
	mov r1, ip
	adds r1, #0xb4
	ldrb r0, [r1]
	subs r0, #6
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x4f
	bhi _0808514E
	movs r0, #0x50
	strb r0, [r1]
_0808514E:
	mov r3, ip
	adds r3, #0xc0
	ldr r0, [r3]
	ldr r1, [r3, #4]
	mov r2, ip
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	adds r2, #0x7c
	ldr r0, [r3]
	ldr r1, [r3, #4]
_08085162:
	str r0, [r2]
	str r1, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityBD74_Update
EntityBD74_Update: @ 0x0808516C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #4
	ldr r0, _080851BC @ =0x03002BC0
	ldr r5, [r0]
	ands r5, r1
	cmp r5, #0
	bne _080851B4
	adds r0, r4, #0
	bl FUN_08084b5c
	adds r0, r4, #0
	bl FUN_0808509c
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	adds r0, #0xa8
	ldrh r1, [r0]
	subs r0, #0x87
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x8a
	ldrh r1, [r0]
	subs r0, #0x41
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x48
	strb r5, [r0]
_080851B4:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080851BC: .4byte 0x03002BC0

	thumb_func_start EntityBD74_Destroy
EntityBD74_Destroy: @ 0x080851C0
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	bl AuxSprite_Remove
	adds r0, r4, #0
	adds r0, #0x60
	bl AuxSprite_Remove
	adds r0, r4, #0
	bl FUN_08084b94
	ldr r1, _080851E4 @ =0x03002BFC
	movs r0, #0
	str r0, [r1]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080851E4: .4byte 0x03002BFC

	thumb_func_start EntityBD74_Init
EntityBD74_Init: @ 0x080851E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	mov r8, r0
	movs r0, #0x63
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08085240
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08085238 @ =0xFFFF0000
	mov sb, r1
	mov r2, sb
	ands r2, r6
	orrs r2, r0
	str r2, [sp]
	adds r6, r2, #0
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r1, _0808523C @ =0x0000FFFF
	adds r2, r6, #0
	ands r2, r1
	adds r6, r2, #0
	orrs r6, r0
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r1, sb
	ands r1, r7
	adds r7, r1, #0
	orrs r7, r0
	b _08085246
	.align 2, 0
_08085238: .4byte 0xFFFF0000
_0808523C: .4byte 0x0000FFFF
_08085240:
	ldr r0, _08085298 @ =0xFFFF0000
	movs r6, #0
	ands r7, r0
_08085246:
	movs r2, #0xa8
	add r2, r8
	mov sl, r2
	movs r2, #0
	movs r3, #0
	movs r0, #1
	mov r1, sl
	strh r0, [r1]
	movs r1, #0xaa
	add r1, r8
	mov sb, r1
	strh r0, [r1]
	mov r1, r8
	adds r1, #0xb4
	movs r0, #0x50
	strb r0, [r1]
	mov r0, r8
	adds r0, #0xb5
	strb r2, [r0]
	subs r0, #9
	strh r3, [r0]
	movs r0, #0x70
	bl VM_SeekToKeyword
	mov r2, sl
	str r2, [sp, #8]
	mov r1, sb
	str r1, [sp, #0xc]
	cmp r0, #0
	beq _0808529C
	bl VM_GetValue
	mov r1, r8
	adds r1, #0xae
	strb r0, [r1]
	bl VM_GetValue
	mov r1, r8
	adds r1, #0xaf
	b _080852A8
	.align 2, 0
_08085298: .4byte 0xFFFF0000
_0808529C:
	mov r1, r8
	adds r1, #0xae
	movs r0, #8
	strb r0, [r1]
	adds r1, #1
	movs r0, #0xc
_080852A8:
	strb r0, [r1]
	mov r4, r8
	adds r4, #0x18
	mov r5, r8
	adds r5, #0x44
	ldr r2, _08085368 @ =0x00003641
	mov sl, r2
	adds r0, r5, #0
	mov r1, sl
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #3
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	movs r0, #0
	strh r0, [r4, #0x10]
	ldr r1, [sp, #8]
	ldrh r0, [r1]
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	movs r2, #2
	mov sb, r2
	mov r0, sb
	strb r0, [r4, #7]
	str r6, [r4, #0x1c]
	str r7, [r4, #0x20]
	adds r4, #0x48
	adds r5, #0x48
	adds r0, r5, #0
	mov r1, sl
	bl Video_GetAuxSprite
	ldr r2, _0808536C @ =0x00000203
	adds r0, r4, #0
	adds r1, r5, #0
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	movs r0, #1
	strh r0, [r4, #0x10]
	ldr r1, [sp, #0xc]
	ldrh r0, [r1]
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	mov r2, sb
	strb r2, [r4, #7]
	str r6, [r4, #0x1c]
	str r7, [r4, #0x20]
	mov r0, r8
	adds r0, #0xc0
	str r6, [r0]
	str r7, [r0, #4]
	mov r1, r8
	adds r1, #0xc8
	str r6, [r1]
	str r7, [r1, #4]
	mov r2, r8
	adds r2, #0xca
	ldrh r0, [r2]
	subs r0, #0x40
	strh r0, [r2]
	ldrh r0, [r1]
	subs r0, #0x2d
	strh r0, [r1]
	adds r1, #4
	ldrh r0, [r1]
	subs r0, #0x2d
	strh r0, [r1]
	mov r0, r8
	bl FUN_08084bb0
	mov r0, r8
	movs r1, #0
	bl FUN_08084c30
	ldr r0, _08085370 @ =0x03002BFC
	mov r1, r8
	str r1, [r0]
	movs r0, #0
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08085368: .4byte 0x00003641
_0808536C: .4byte 0x00000203
_08085370: .4byte 0x03002BFC

	thumb_func_start EntityBD74_Create
EntityBD74_Create: @ 0x08085374
	push {r4, lr}
	ldr r0, _080853AC @ =0x03002BFC
	ldr r0, [r0]
	cmp r0, #0
	bne _080853BA
	movs r1, #0xeb
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080853B8
	ldr r1, _080853B0 @ =EntityBD74_Update
	ldr r2, _080853B4 @ =EntityBD74_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityBD74_Init
	cmp r0, #0
	bge _080853B8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080853BA
	.align 2, 0
_080853AC: .4byte 0x03002BFC
_080853B0: .4byte EntityBD74_Update
_080853B4: .4byte EntityBD74_Destroy
_080853B8:
	adds r0, r4, #0
_080853BA:
	pop {r4}
	pop {r1}
	bx r1
