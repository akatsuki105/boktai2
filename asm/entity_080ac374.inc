	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080abd74
FUN_080abd74: @ 0x080ABD74
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x2a
	ldrb r0, [r4]
	adds r2, r0, #1
	strb r2, [r4]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080ABD9C
	ldr r0, [r6]
	movs r1, #1
	orrs r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x28
	movs r0, #0
	strb r0, [r1]
	b _080ABE40
_080ABD9C:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _080ABDB2
	adds r0, r6, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r6, #0
	bl FUN_0822dafc
_080ABDB2:
	ldrb r0, [r4]
	movs r1, #0x2b
	adds r1, r1, r6
	mov ip, r1
	adds r1, r6, #0
	adds r1, #0x2e
	cmp r0, #3
	bls _080ABDD6
	mov r2, ip
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	ldrb r0, [r4]
	cmp r0, #8
	bls _080ABDD6
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
_080ABDD6:
	adds r2, r6, #0
	adds r2, #0x2d
	ldrb r0, [r1]
	ldrb r1, [r2]
	adds r0, r0, r1
	strb r0, [r2]
	adds r4, r6, #0
	adds r4, #0x2c
	ldrb r5, [r4]
	ldr r3, _080ABE04 @ =0x085B0A08
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _080ABE08
	asrs r5, r0, #0xc
	b _080ABE0E
	.align 2, 0
_080ABE04: .4byte 0x085B0A08
_080ABE08:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r5, r0, #0
_080ABE0E:
	ldrh r0, [r6, #0x30]
	adds r0, r0, r5
	strh r0, [r6, #0x18]
	ldrb r1, [r4]
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080ABE2A
	asrs r1, r0, #0xc
	b _080ABE30
_080ABE2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ABE30:
	ldrh r0, [r6, #0x34]
	adds r0, r0, r1
	strh r0, [r6, #0x1c]
	ldrh r0, [r6, #0x1a]
	mov r1, ip
	ldrb r1, [r1]
	adds r0, r0, r1
	strh r0, [r6, #0x1a]
_080ABE40:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080abe48
FUN_080abe48: @ 0x080ABE48
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov ip, r1
	mov r5, sb
	adds r5, #0x9c
	ldrb r0, [r5, #1]
	adds r0, #1
	strb r0, [r5, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080ABE68
	b _080ABF90
_080ABE68:
	ldrb r1, [r5]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #8
	adds r7, r5, r0
	adds r1, r7, #0
	adds r1, #0x28
	movs r0, #1
	strb r0, [r1]
	ldr r4, _080ABF20 @ =0x0203B400
	ldr r0, _080ABF24 @ =0x030046B8
	mov r8, r0
	ldr r1, [r0]
	adds r1, #1
	ldr r2, _080ABF28 @ =0x000003FF
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r3, #0xf
	ands r0, r3
	adds r0, #0x10
	adds r6, r7, #0
	adds r6, #0x2b
	strb r0, [r6]
	adds r1, #1
	ands r1, r2
	lsls r0, r1, #1
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r3
	adds r0, #0x40
	adds r6, #1
	strb r0, [r6]
	adds r1, #1
	ands r1, r2
	mov r2, r8
	str r1, [r2]
	lsls r1, r1, #1
	adds r1, r1, r4
	ldrh r0, [r1]
	movs r1, #0x2d
	adds r1, r1, r7
	mov r8, r1
	strb r0, [r1]
	adds r1, r7, #0
	adds r1, #0x2e
	movs r0, #8
	strb r0, [r1]
	subs r1, #4
	movs r0, #0
	strb r0, [r1]
	mov r2, ip
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x30]
	str r1, [r7, #0x34]
	ldr r0, _080ABF2C @ =FUN_080abd74
	str r0, [r7, #0x38]
	adds r4, r7, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	mov r0, sb
	adds r0, #0xa0
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x29
	ldrb r2, [r0]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrb r3, [r6]
	ldr r2, _080ABF30 @ =0x085B0A08
	mov r1, r8
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080ABF34
	asrs r3, r0, #0xc
	b _080ABF3A
	.align 2, 0
_080ABF20: .4byte 0x0203B400
_080ABF24: .4byte 0x030046B8
_080ABF28: .4byte 0x000003FF
_080ABF2C: .4byte FUN_080abd74
_080ABF30: .4byte 0x085B0A08
_080ABF34:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080ABF3A:
	ldrh r0, [r7, #0x30]
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #0x32]
	strh r0, [r4, #0x1a]
	adds r0, r7, #0
	adds r0, #0x2c
	ldrb r2, [r0]
	ldr r1, _080ABF64 @ =0x085B0A08
	adds r0, #1
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080ABF68
	asrs r1, r0, #0xc
	b _080ABF6E
	.align 2, 0
_080ABF64: .4byte 0x085B0A08
_080ABF68:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080ABF6E:
	ldrh r0, [r7, #0x34]
	adds r0, r0, r1
	movs r1, #0
	strh r0, [r4, #0x1c]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080ABF86
	strb r1, [r5]
_080ABF86:
	strb r1, [r5, #1]
	mov r1, sb
	adds r1, #0x9e
	movs r0, #1
	strb r0, [r1]
_080ABF90:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080abf9c
FUN_080abf9c: @ 0x080ABF9C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r0, #0x9e
	ldrb r0, [r0]
	cmp r0, #0
	beq _080ABFE4
	movs r3, #0
	adds r4, r6, #0
	adds r4, #0xcc
	adds r5, r6, #0
	adds r5, #0xa4
	movs r7, #7
_080ABFB6:
	ldrb r0, [r4]
	cmp r0, #0
	beq _080ABFD0
	adds r0, r6, #0
	adds r0, #0xa0
	ldr r1, [r0]
	ldr r2, [r4, #0x10]
	adds r0, r5, #0
	str r3, [sp]
	bl _call_via_r2
	ldr r3, [sp]
	adds r3, #1
_080ABFD0:
	adds r4, #0x3c
	adds r5, #0x3c
	subs r7, #1
	cmp r7, #0
	bge _080ABFB6
	cmp r3, #0
	bne _080ABFE4
	adds r0, r6, #0
	adds r0, #0x9e
	strb r3, [r0]
_080ABFE4:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080abfec
FUN_080abfec: @ 0x080ABFEC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0xa4
	movs r5, #7
_080ABFF4:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080ABFF4
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac008
FUN_080ac008: @ 0x080AC008
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x9c
	ldr r0, _080AC030 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #4]
	movs r0, #0
	strb r0, [r6]
	strb r0, [r6, #1]
	adds r4, #0x24
	ldrb r0, [r4]
	cmp r0, #7
	bne _080AC034
	movs r0, #0xe
	b _080AC03A
	.align 2, 0
_080AC030: .4byte 0x00001C1E
_080AC034:
	ldrb r0, [r4]
	adds r0, #1
	lsls r0, r0, #1
_080AC03A:
	mov sb, r0
	movs r0, #4
	rsbs r0, r0, #0
	mov r8, r0
	adds r4, r6, #0
	adds r4, #0x17
	adds r5, r6, #0
	adds r5, #8
	movs r7, #7
_080AC04C:
	movs r0, #0
	strb r0, [r4, #0x19]
	mov r0, sb
	strb r0, [r4, #0x1a]
	ldr r1, [r6, #4]
	adds r0, r5, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r5, #0
	mov r1, r8
	mov r2, r8
	bl Particle_SetOffset
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #0xf8
	strb r0, [r4, #1]
	movs r0, #2
	strb r0, [r4]
	adds r4, #0x3c
	adds r5, #0x3c
	subs r7, #1
	cmp r7, #0
	bge _080AC04C
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac090
FUN_080ac090: @ 0x080AC090
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	ldr r7, [r0, #0x48]
	adds r0, #0x6d
	ldrb r0, [r0]
	movs r1, #0x10
	subs r1, r1, r0
	lsls r0, r1, #4
	subs r5, r0, r1
	movs r6, #0
	movs r0, #0x1f
	mov r8, r0
_080AC0AC:
	ldrh r1, [r7]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	mov r2, r8
	ands r3, r2
	lsrs r1, r1, #0x1a
	ands r1, r2
	mov r2, ip
	adds r2, #0x6d
	ldrb r2, [r2]
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r4, r0, #4
	adds r0, r3, #0
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r3, r0, #4
	adds r0, r1, #0
	muls r0, r2, r0
	adds r0, r5, r0
	asrs r1, r0, #4
	lsls r0, r6, #1
	mov r2, ip
	adds r2, #0x4c
	adds r2, r2, r0
	lsls r0, r1, #0xa
	lsls r1, r3, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r2]
	adds r7, #2
	adds r6, #1
	cmp r6, #0xf
	ble _080AC0AC
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac100
FUN_080ac100: @ 0x080AC100
	push {lr}
	adds r2, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AC116
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AC11C
_080AC116:
	ldr r0, [r2]
	ldr r1, _080AC138 @ =0xFFFFFBFF
	ands r0, r1
_080AC11C:
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	cmp r0, #0xf
	bhi _080AC132
	adds r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080ac090
_080AC132:
	pop {r0}
	bx r0
	.align 2, 0
_080AC138: .4byte 0xFFFFFBFF

	thumb_func_start FUN_080ac13c
FUN_080ac13c: @ 0x080AC13C
	push {lr}
	adds r2, r0, #0
	adds r0, #0x6d
	ldrb r0, [r0]
	cmp r0, #5
	bhi _080AC152
	ldr r0, [r2]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	b _080AC158
_080AC152:
	ldr r0, [r2]
	ldr r1, _080AC178 @ =0xFFFFFBFF
	ands r0, r1
_080AC158:
	str r0, [r2]
	adds r1, r2, #0
	adds r1, #0x6d
	ldrb r0, [r1]
	adds r3, r0, #0
	cmp r3, #0
	bne _080AC17C
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	adds r0, r2, #0
	adds r0, #0x6c
	strb r3, [r0]
	b _080AC186
	.align 2, 0
_080AC178: .4byte 0xFFFFFBFF
_080AC17C:
	subs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl FUN_080ac090
_080AC186:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac18c
FUN_080ac18c: @ 0x080AC18C
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x98
	ldrb r0, [r0]
	cmp r0, #0
	beq _080AC214
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x26]
	adds r2, r0, #0
	cmp r1, r2
	bhs _080AC1B8
	adds r1, r4, #0
	adds r1, #0x25
	ldr r0, [r4, #0x18]
	movs r3, #0xdf
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r1, [r1]
	ldrb r0, [r0]
	cmp r1, r0
	beq _080AC1B8
	strh r2, [r4, #0x26]
_080AC1B8:
	ldrh r0, [r4, #0x26]
	adds r0, #1
	strh r0, [r4, #0x26]
	lsls r0, r0, #0x10
	lsls r1, r2, #0x10
	cmp r0, r1
	bhs _080AC20C
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_080ac100
	ldr r0, [r4, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r4, #0x48]
	str r1, [r4, #0x4c]
	adds r2, r4, #0
	adds r2, #0x48
	ldrh r0, [r4, #0x1c]
	ldrh r1, [r2]
	adds r0, r0, r1
	strh r0, [r2]
	adds r1, r4, #0
	adds r1, #0x4a
	ldrh r0, [r4, #0x1e]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	adds r1, #2
	ldrh r0, [r4, #0x20]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	ldrh r0, [r4, #0x26]
	ldrh r1, [r4, #0x28]
	cmp r0, r1
	bhs _080AC214
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080abe48
	b _080AC214
_080AC20C:
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_080ac13c
_080AC214:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ac21c
FUN_080ac21c: @ 0x080AC21C
	push {lr}
	adds r0, #0x2c
	bl AuxSprite_Remove
	pop {r0}
	bx r0

	thumb_func_start FUN_080ac228
FUN_080ac228: @ 0x080AC228
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	mov sb, r1
	adds r4, r5, #0
	adds r4, #0x2c
	adds r0, #0x24
	ldrb r7, [r0]
	adds r0, r7, #0
	movs r1, #0x63
	mov r8, r1
	cmp r0, #0
	beq _080AC252
	movs r2, #0x6c
	mov r8, r2
	cmp r0, #1
	bne _080AC252
	movs r0, #0x62
	mov r8, r0
_080AC252:
	adds r6, r4, #0
	adds r6, #0x2c
	ldr r1, _080AC2D4 @ =0x00000BA8
	adds r0, r6, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	strh r7, [r4, #0x10]
	movs r0, #3
	strb r0, [r4, #7]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r5, #0x1c]
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	ldrh r0, [r5, #0x1e]
	ldrh r2, [r4, #0x1e]
	adds r0, r0, r2
	strh r0, [r4, #0x1e]
	ldrh r0, [r5, #0x20]
	ldrh r1, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #3
	orrs r0, r1
	str r0, [r4]
	ldr r0, _080AC2D8 @ =0x03003584
	mov r2, r8
	lsls r1, r2, #5
	ldr r0, [r0]
	adds r0, r0, r1
	str r0, [r4, #0x48]
	ldr r5, _080AC2DC @ =0x00003DEF
	adds r2, r4, #0
	adds r2, #0x4c
	adds r3, r4, #0
	adds r3, #0x6c
	adds r1, r2, #0
	adds r0, r4, #0
	adds r0, #0x6a
_080AC2B6:
	strh r5, [r0]
	subs r0, #2
	cmp r0, r1
	bge _080AC2B6
	mov r0, r8
	strh r0, [r6, #6]
	str r2, [r6, #0xc]
	movs r0, #1
	strb r0, [r3]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AC2D4: .4byte 0x00000BA8
_080AC2D8: .4byte 0x03003584
_080AC2DC: .4byte 0x00003DEF

	thumb_func_start Entity080ac374_Update
Entity080ac374_Update: @ 0x080AC2E0
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ac18c
	adds r0, r4, #0
	bl FUN_080abf9c
	adds r1, r4, #0
	adds r1, #0x98
	ldrb r1, [r1]
	cmp r1, #0
	bne _080AC308
	adds r1, r4, #0
	adds r1, #0x9e
	ldrb r1, [r1]
	cmp r1, #0
	bne _080AC308
	adds r0, r4, #0
	bl KillEntity
_080AC308:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080ac374_Destroy
Entity080ac374_Destroy: @ 0x080AC310
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ac21c
	adds r0, r4, #0
	bl FUN_080abfec
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity080ac374_Init
Entity080ac374_Init: @ 0x080AC324
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	strb r2, [r0]
	str r1, [r4, #0x18]
	cmp r3, #0
	bne _080AC33A
	strh r3, [r4, #0x1c]
	strh r3, [r4, #0x1e]
	strh r3, [r4, #0x20]
	b _080AC342
_080AC33A:
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
_080AC342:
	ldr r0, [r4, #0x18]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r1, r4, #0
	adds r1, #0x25
	strb r0, [r1]
	ldr r0, [sp, #8]
	strh r0, [r4, #0x28]
	ldr r0, [sp, #0xc]
	strh r0, [r4, #0x2a]
	ldr r1, [r4, #0x18]
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_080ac228
	adds r0, r4, #0
	bl FUN_080ac008
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity080ac374_Create
Entity080ac374_Create: @ 0x080AC374
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xa1
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AC3C4
	ldr r1, _080AC3BC @ =Entity080ac374_Update
	ldr r2, _080AC3C0 @ =Entity080ac374_Destroy
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl Entity080ac374_Init
	cmp r0, #0
	bge _080AC3C4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AC3C6
	.align 2, 0
_080AC3BC: .4byte Entity080ac374_Update
_080AC3C0: .4byte Entity080ac374_Destroy
_080AC3C4:
	adds r0, r4, #0
_080AC3C6:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
