	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080dbeb0
FUN_080dbeb0: @ 0x080DBEB0
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dbeb4
FUN_080dbeb4: @ 0x080DBEB4
	push {r4, r5, r6, r7, lr}
	adds r2, r0, #0
	mov ip, r1
	movs r0, #0x17
	ldrsb r0, [r1, r0]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, #0x20
	adds r5, r2, r1
	mov r0, ip
	ldrh r1, [r0, #0x1a]
	movs r3, #0x1a
	ldrsh r0, [r0, r3]
	cmp r0, #0
	ble _080DBEDC
	subs r0, r1, #1
	mov r4, ip
	strh r0, [r4, #0x1a]
	b _080DC004
_080DBEDC:
	ldr r6, [r5]
	movs r0, #2
	rsbs r0, r0, #0
	ands r6, r0
	str r6, [r5]
	mov r0, ip
	ldr r1, [r0]
	ldrh r0, [r0, #4]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r5, #0x18]
	mov r4, ip
	ldrh r0, [r4, #6]
	ldrh r3, [r1, #2]
	adds r0, r0, r3
	strh r0, [r5, #0x1a]
	ldrh r0, [r4, #8]
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	movs r0, #0x17
	ldrsb r0, [r4, r0]
	ldr r3, [r2, #0x1c]
	lsls r0, r0, #4
	adds r4, r0, r2
	movs r0, #0xb0
	lsls r0, r0, #1
	adds r4, r4, r0
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r2, [r7]
	lsrs r2, r2, #6
	ldrb r1, [r5, #0xa]
	lsrs r1, r1, #3
	ldrb r0, [r5, #0xb]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldrb r0, [r4, #4]
	movs r3, #1
	adds r1, r3, #0
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DBF4E
	movs r0, #4
	orrs r6, r0
	b _080DBF54
_080DBF4E:
	movs r0, #5
	rsbs r0, r0, #0
	ands r6, r0
_080DBF54:
	str r6, [r5]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DBF78
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080DBF80
_080DBF78:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DBF80:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DBFB8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DBFF0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DBFC2
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DBFBC
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DBFD8
	.align 2, 0
_080DBFB8: .4byte 0x0000FFFF
_080DBFBC:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DBFD6
_080DBFC2:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DBFD6
	strh r1, [r4, #8]
	movs r2, #1
	b _080DBFD8
_080DBFD6:
	movs r2, #0
_080DBFD8:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _080DBFF2
_080DBFF0:
	movs r2, #0
_080DBFF2:
	cmp r2, #0
	beq _080DBFFC
	movs r0, #2
	mov r3, ip
	strb r0, [r3, #0x16]
_080DBFFC:
	mov r4, ip
	ldrh r0, [r4, #0x18]
	adds r0, #1
	strh r0, [r4, #0x18]
_080DC004:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dc00c
FUN_080dc00c: @ 0x080DC00C
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	movs r1, #0x17
	ldrsb r1, [r5, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r4, r0
	bl Particle_Remove
	movs r0, #0
	strb r0, [r5, #0x16]
	movs r0, #0x17
	ldrsb r0, [r5, r0]
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r4, r4, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r4]
	bics r0, r1
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x1c
	bl ClearMemory
	movs r0, #0xff
	strb r0, [r5, #0x17]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dc050
FUN_080dc050: @ 0x080DC050
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r4, r2, r0
	movs r5, #1
	mov ip, r3
_080DC060:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DC070
	movs r0, #1
	b _080DC072
_080DC070:
	movs r0, #0
_080DC072:
	cmp r0, #0
	bne _080DC08C
	movs r0, #0xf2
	lsls r0, r0, #1
	add r0, ip
	adds r0, r2, r0
	strb r3, [r0, #0x17]
	adds r2, r5, #0
	lsls r2, r3
	ldr r1, [r4]
	orrs r1, r2
	str r1, [r4]
	b _080DC098
_080DC08C:
	movs r0, #0x1c
	add ip, r0
	adds r3, #1
	cmp r3, #7
	ble _080DC060
	movs r0, #0
_080DC098:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dc0a0
FUN_080dc0a0: @ 0x080DC0A0
	push {r4, r5, lr}
	sub sp, #8
	ldr r4, [sp, #0x14]
	ldr r5, [sp, #0x18]
	str r4, [sp]
	str r5, [sp, #4]
	bl FUN_080dc0d0
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc0b8
FUN_080dc0b8: @ 0x080DC0B8
	push {r4, lr}
	sub sp, #8
	ldr r4, [sp, #0x10]
	str r4, [sp]
	movs r4, #2
	str r4, [sp, #4]
	bl FUN_080dc0d0
	add sp, #8
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc0d0
FUN_080dc0d0: @ 0x080DC0D0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov sb, r2
	mov r8, r3
	cmp r0, #0
	beq _080DC0F2
	ldr r0, _080DC0F8 @ =0x03000168
	ldr r0, [r0]
	str r0, [sp, #0xc]
	cmp r0, #0
	bne _080DC0FC
_080DC0F2:
	movs r0, #1
	rsbs r0, r0, #0
	b _080DC340
	.align 2, 0
_080DC0F8: .4byte 0x03000168
_080DC0FC:
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, [sp, #0x38]
	cmp r0, r1
	blt _080DC108
	b _080DC33E
_080DC108:
	ldr r2, _080DC144 @ =0x030046B8
	mov sl, r2
_080DC10C:
	ldr r0, [sp, #0xc]
	bl FUN_080dc050
	adds r7, r0, #0
	cmp r7, #0
	beq _080DC0F2
	movs r1, #0x17
	ldrsb r1, [r7, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	ldr r3, [sp, #0xc]
	adds r0, r3, r0
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	str r0, [r7]
	ldr r1, [sp, #8]
	cmp r1, #0
	bne _080DC148
	strh r1, [r7, #4]
	mov r3, sp
	ldrh r3, [r3, #8]
	strh r3, [r7, #6]
	mov r0, sp
	ldrh r0, [r0, #8]
	strh r0, [r7, #8]
	b _080DC152
	.align 2, 0
_080DC144: .4byte 0x030046B8
_080DC148:
	ldr r2, [sp, #8]
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #4]
	str r1, [r7, #8]
_080DC152:
	mov r3, r8
	cmp r3, #0
	beq _080DC1F8
	movs r1, #0
	ldrsh r0, [r3, r1]
	cmp r0, #0
	beq _080DC18C
	mov r2, sl
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _080DC208 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080DC20C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #0
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, r8
	ldrh r1, [r2]
	subs r0, r0, r1
	ldrh r3, [r7, #4]
	adds r0, r0, r3
	strh r0, [r7, #4]
_080DC18C:
	mov r1, r8
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	beq _080DC1C2
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC208 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC20C @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, r8
	movs r2, #2
	ldrsh r1, [r3, r2]
	lsls r1, r1, #1
	bl Mod
	mov r3, r8
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	ldrh r1, [r7, #6]
	adds r0, r0, r1
	strh r0, [r7, #6]
_080DC1C2:
	mov r2, r8
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmp r0, #0
	beq _080DC1F8
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DC208 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _080DC20C @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, r8
	movs r3, #4
	ldrsh r1, [r2, r3]
	lsls r1, r1, #1
	bl Mod
	mov r2, r8
	ldrh r1, [r2, #4]
	subs r0, r0, r1
	ldrh r3, [r7, #8]
	adds r0, r0, r3
	strh r0, [r7, #8]
_080DC1F8:
	mov r0, sb
	cmp r0, #0
	bne _080DC210
	strh r0, [r7, #0xc]
	mov r1, sb
	strh r1, [r7, #0xe]
	strh r1, [r7, #0x10]
	b _080DC2E6
	.align 2, 0
_080DC208: .4byte 0x000003FF
_080DC20C: .4byte 0x0203B400
_080DC210:
	mov r2, sb
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r0, #0
	bne _080DC224
	ldr r0, _080DC220 @ =0xFFFF0000
	ands r5, r0
	b _080DC24E
	.align 2, 0
_080DC220: .4byte 0xFFFF0000
_080DC224:
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DC260 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r3, _080DC264 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r2, sb
	movs r3, #0
	ldrsh r1, [r2, r3]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DC268 @ =0xFFFF0000
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DC24E:
	mov r1, sb
	movs r2, #2
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080DC270
	ldr r0, _080DC26C @ =0x0000FFFF
	ands r5, r0
	b _080DC298
	.align 2, 0
_080DC260: .4byte 0x000003FF
_080DC264: .4byte 0x0203B400
_080DC268: .4byte 0xFFFF0000
_080DC26C: .4byte 0x0000FFFF
_080DC270:
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC2A8 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC2AC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	movs r2, #2
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	ldr r1, _080DC2B0 @ =0x0000FFFF
	ands r1, r5
	adds r5, r1, #0
	orrs r5, r0
_080DC298:
	mov r3, sb
	movs r1, #4
	ldrsh r0, [r3, r1]
	cmp r0, #0
	bne _080DC2B8
	ldr r2, _080DC2B4 @ =0xFFFF0000
	ands r6, r2
	b _080DC2E2
	.align 2, 0
_080DC2A8: .4byte 0x000003FF
_080DC2AC: .4byte 0x0203B400
_080DC2B0: .4byte 0x0000FFFF
_080DC2B4: .4byte 0xFFFF0000
_080DC2B8:
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _080DC350 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _080DC354 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r3, sb
	movs r2, #4
	ldrsh r1, [r3, r2]
	bl Mod
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080DC358 @ =0xFFFF0000
	ands r1, r6
	adds r6, r1, #0
	orrs r6, r0
_080DC2E2:
	str r5, [r7, #0xc]
	str r6, [r7, #0x10]
_080DC2E6:
	movs r4, #0
	strh r4, [r7, #0x1a]
	ldr r3, [sp, #0xc]
	ldr r1, [r3, #0x1c]
	ldr r0, [sp, #0x10]
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #8
	rsbs r2, r2, #0
	ldr r0, [sp, #0x10]
	adds r1, r2, #0
	bl Particle_SetOffset
	movs r0, #0x17
	ldrsb r0, [r7, r0]
	lsls r0, r0, #4
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r2, [sp, #0xc]
	adds r0, r2, r0
	ldr r1, [r2, #0x18]
	str r4, [sp]
	movs r2, #0xc
	movs r3, #0
	bl FUN_08236fac
	ldr r3, [sp, #0x10]
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	add r0, sp, #0x3c
	ldrb r0, [r0]
	strb r0, [r3, #0xf]
	strb r1, [r7, #0x16]
	ldr r1, [sp, #0x14]
	adds r1, #1
	str r1, [sp, #0x14]
	ldr r2, [sp, #0x38]
	cmp r1, r2
	bge _080DC33E
	b _080DC10C
_080DC33E:
	movs r0, #0
_080DC340:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DC350: .4byte 0x000003FF
_080DC354: .4byte 0x0203B400
_080DC358: .4byte 0xFFFF0000

	thumb_func_start FUN_080dc35c
FUN_080dc35c: @ 0x080DC35C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0xf0
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DC3B6
	movs r5, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r7, r6, r0
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r4, r6, r1
	ldr r0, _080DC394 @ =0x085AD32C
	mov r8, r0
_080DC382:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DC398
	movs r0, #1
	b _080DC39A
	.align 2, 0
_080DC394: .4byte 0x085AD32C
_080DC398:
	movs r0, #0
_080DC39A:
	cmp r0, #0
	beq _080DC3AE
	ldrb r0, [r4, #0x16]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_080DC3AE:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #7
	ble _080DC382
_080DC3B6:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dc3c4
FUN_080dc3c4: @ 0x080DC3C4
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r5, #0
	movs r0, #0xf0
	lsls r0, r0, #1
	adds r7, r6, r0
	adds r0, #4
	adds r4, r6, r0
_080DC3D4:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DC3E4
	movs r0, #1
	b _080DC3E6
_080DC3E4:
	movs r0, #0
_080DC3E6:
	cmp r0, #0
	beq _080DC3FC
	movs r1, #0x17
	ldrsb r1, [r4, r1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x20
	adds r0, r6, r0
	bl Particle_Remove
_080DC3FC:
	adds r4, #0x1c
	adds r5, #1
	cmp r5, #7
	ble _080DC3D4
	movs r1, #0
	ldr r0, _080DC414 @ =0x03000168
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DC414: .4byte 0x03000168

	thumb_func_start FUN_080dc418
FUN_080dc418: @ 0x080DC418
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080DC434 @ =0x00001C1A
	bl GetParticleGroup
	str r0, [r4, #0x1c]
	ldr r0, _080DC438 @ =0x0000922E
	ldr r1, _080DC43C @ =0x0000D1B8
	bl GetFile
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080DC434: .4byte 0x00001C1A
_080DC438: .4byte 0x0000922E
_080DC43C: .4byte 0x0000D1B8

	thumb_func_start FUN_080dc440
FUN_080dc440: @ 0x080DC440
	push {lr}
	bl FUN_080dc418
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc44c
FUN_080dc44c: @ 0x080DC44C
	push {r4, r5, lr}
	ldr r5, _080DC484 @ =0x03000168
	ldr r0, [r5]
	cmp r0, #0
	bne _080DC492
	movs r1, #0xb1
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	str r4, [r5]
	cmp r4, #0
	beq _080DC490
	ldr r1, _080DC488 @ =FUN_080dc35c
	ldr r2, _080DC48C @ =FUN_080dc3c4
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080dc440
	cmp r0, #0
	bge _080DC490
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DC492
	.align 2, 0
_080DC484: .4byte 0x03000168
_080DC488: .4byte FUN_080dc35c
_080DC48C: .4byte FUN_080dc3c4
_080DC490:
	adds r0, r4, #0
_080DC492:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc498
FUN_080dc498: @ 0x080DC498
	ldr r1, _080DC4A0 @ =0x03000168
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DC4A0: .4byte 0x03000168

	thumb_func_start FUN_080dc4a4
FUN_080dc4a4: @ 0x080DC4A4
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dc4a8
FUN_080dc4a8: @ 0x080DC4A8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r2, #0
	mov r4, sp
	adds r3, r1, #0
	adds r3, #0xc
	adds r2, r0, #0
	adds r2, #0xc
	ldrh r0, [r0, #0xc]
	ldrh r1, [r1, #0xc]
	subs r0, r0, r1
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r3, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r3, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r3, r0, #0
	adds r0, #0x10
	movs r5, #0xff
	ands r0, r5
	asrs r0, r0, #5
	lsls r3, r0, #5
	ldrh r0, [r4, #2]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _080DC570
	add r2, sp, #8
	ldr r0, _080DC514 @ =0x085B0A08
	adds r1, r3, #0
	adds r1, #0x40
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r1, [r1, r4]
	lsls r1, r1, #2
	adds r4, r2, #0
	adds r5, r0, #0
	cmp r1, #0
	blt _080DC518
	asrs r1, r1, #0xc
	b _080DC51E
	.align 2, 0
_080DC514: .4byte 0x085B0A08
_080DC518:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DC51E:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #4
	muls r0, r1, r0
	cmp r0, #0
	blt _080DC53C
	asrs r0, r0, #0xc
	b _080DC542
_080DC53C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DC542:
	strh r0, [r2, #4]
	ldr r0, _080DC56C @ =0x0000FFFC
	strh r0, [r4, #2]
	add r0, sp, #8
	ldrh r1, [r0]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r1, [r0]
	ldrh r0, [r4, #2]
	movs r3, #0x8f
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	ldrh r1, [r4, #4]
	movs r4, #0x90
	lsls r4, r4, #1
	adds r0, r6, r4
	strh r1, [r0]
	b _080DC5F2
	.align 2, 0
_080DC56C: .4byte 0x0000FFFC
_080DC570:
	add r2, sp, #8
	movs r7, #0x12
	ldr r0, _080DC594 @ =0x085B0A08
	adds r1, r3, #0
	adds r1, #0x40
	ands r1, r5
	lsls r1, r1, #1
	adds r1, r1, r0
	movs r4, #0
	ldrsh r1, [r1, r4]
	muls r1, r7, r1
	adds r4, r2, #0
	adds r5, r0, #0
	cmp r1, #0
	blt _080DC598
	asrs r1, r1, #0xc
	b _080DC59E
	.align 2, 0
_080DC594: .4byte 0x085B0A08
_080DC598:
	rsbs r0, r1, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080DC59E:
	movs r0, #0
	strh r1, [r2]
	strh r0, [r2, #2]
	movs r0, #0xff
	ands r0, r3
	lsls r0, r0, #1
	adds r0, r0, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080DC5BA
	asrs r0, r0, #0xc
	b _080DC5C0
_080DC5BA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DC5C0:
	strh r0, [r2, #4]
	movs r0, #0x20
	strh r0, [r4, #2]
	movs r2, #0x8e
	lsls r2, r2, #1
	adds r1, r6, r2
	add r0, sp, #8
	ldrh r0, [r0]
	ldrh r3, [r1]
	adds r0, r0, r3
	strh r0, [r1]
	movs r0, #0x8f
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r4, #2]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r3, #0x90
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r4, #4]
	ldrh r4, [r1]
	adds r0, r0, r4
	strh r0, [r1]
_080DC5F2:
	ldrh r0, [r6, #0x1e]
	adds r0, #1
	strh r0, [r6, #0x1e]
	ldr r0, _080DC610 @ =0x00000131
	adds r1, r6, r0
	movs r0, #0xc
	strb r0, [r1]
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC610: .4byte 0x00000131

	thumb_func_start FUN_080dc614
FUN_080dc614: @ 0x080DC614
	push {lr}
	adds r3, r2, #0
	mov ip, r3
	movs r1, #4
	ldr r2, [r0, #0x38]
	ands r1, r2
	cmp r1, #0
	beq _080DC62E
	movs r0, #0x99
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r0, #0
	b _080DC64A
_080DC62E:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _080DC64C
	movs r1, #0x99
	lsls r1, r1, #1
	add r1, ip
	ldrh r0, [r1]
	cmp r0, #0x59
	bls _080DC64C
	movs r0, #0x9f
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
_080DC64A:
	strh r0, [r1]
_080DC64C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080dc650
FUN_080dc650: @ 0x080DC650
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r2, _080DC74C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x20
	orrs r0, r3
	ldr r1, _080DC750 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	mov r0, sp
	adds r0, #0xc
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r6, sp, #0x14
	ldr r0, [r6, #4]
	ands r0, r2
	str r0, [r6, #4]
	movs r1, #0x3c
	adds r1, r1, r7
	mov sb, r1
	movs r2, #0x9e
	lsls r2, r2, #1
	adds r2, r2, r7
	mov sl, r2
	ldrh r1, [r2]
	ldr r2, _080DC754 @ =0x00002003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	mov r0, sb
	movs r3, #0
	bl Hitbox_Init
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	movs r1, #0
	mov r8, r1
	str r1, [sp]
	str r1, [sp, #4]
	mov r0, sb
	adds r1, r4, #0
	adds r2, r5, #0
	movs r3, #0
	bl Hitbox_SetAttack
	adds r5, r7, #0
	adds r5, #0x1c
	mov r0, sb
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080DC758 @ =FUN_080dc4a8
	mov r0, sb
	adds r2, r7, #0
	bl Hitbox_SetHandler
	movs r1, #0x40
	add r0, sp, #0xc
	strh r1, [r0]
	movs r0, #0x80
	ldr r2, [sp, #0x1c]
	strh r0, [r2, #2]
	strh r1, [r2, #4]
	mov r1, r8
	strh r1, [r6]
	strh r0, [r6, #2]
	strh r1, [r6, #4]
	adds r4, r7, #0
	adds r4, #0x8c
	mov r2, sl
	ldrh r1, [r2]
	ldr r2, _080DC75C @ =0x00004001
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r6, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080DC760 @ =FUN_080dc614
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DC74C: .4byte 0xFFFF0000
_080DC750: .4byte 0x0000FFFF
_080DC754: .4byte 0x00002003
_080DC758: .4byte FUN_080dc4a8
_080DC75C: .4byte 0x00004001
_080DC760: .4byte FUN_080dc614

	thumb_func_start FUN_080dc764
FUN_080dc764: @ 0x080DC764
	push {r4, r5, r6, lr}
	movs r3, #0
	ldr r1, _080DC788 @ =0x00000F68
	adds r4, r0, r1
	movs r5, #1
	adds r2, r0, #0
	adds r2, #0x38
	movs r6, #0xa2
	lsls r6, r6, #1
_080DC776:
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	ands r0, r1
	cmp r0, #0
	beq _080DC78C
	movs r0, #1
	b _080DC78E
	.align 2, 0
_080DC788: .4byte 0x00000F68
_080DC78C:
	movs r0, #0
_080DC78E:
	cmp r0, #0
	bne _080DC7AC
	adds r1, r5, #0
	lsls r1, r3
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	ldr r1, _080DC7A8 @ =0x0000012F
	adds r0, r2, r1
	strb r3, [r0]
	adds r0, r2, #0
	b _080DC7B6
	.align 2, 0
_080DC7A8: .4byte 0x0000012F
_080DC7AC:
	adds r2, r2, r6
	adds r3, #1
	cmp r3, #0xb
	ble _080DC776
	movs r0, #0
_080DC7B6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dc7bc
FUN_080dc7bc: @ 0x080DC7BC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	str r0, [sp, #0x14]
	adds r6, r1, #0
	mov sl, r6
	movs r0, #0x98
	lsls r0, r0, #1
	adds r3, r6, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080DC7F2
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r3]
_080DC7F2:
	adds r0, r6, #0
	adds r0, #0x1c
	ldrh r1, [r6, #0x1c]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	str r0, [sp, #0x24]
	cmp r2, #0
	blt _080DC81C
	cmp r1, #0
	blt _080DC81C
	ldr r0, _080DC820 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080DC81C
	ldr r0, _080DC824 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DC828
_080DC81C:
	movs r0, #0
	b _080DC836
	.align 2, 0
_080DC820: .4byte 0x030046A8
_080DC824: .4byte 0x030046AC
_080DC828:
	ldr r0, _080DC870 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r0, r0, r2
_080DC836:
	movs r3, #0x9a
	lsls r3, r3, #1
	adds r1, r6, r3
	strh r0, [r1]
	movs r5, #0x96
	lsls r5, r5, #1
	adds r5, r5, r6
	mov r8, r5
	ldrh r5, [r5]
	movs r0, #1
	ands r0, r5
	cmp r0, #0
	beq _080DC8AC
	mov r0, sl
	movs r2, #0x1e
	ldrsh r7, [r0, r2]
	ldrh r5, [r1]
	mov r4, sl
	adds r4, #0x1c
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	adds r3, r4, #0
	cmp r0, #0
	beq _080DC874
	adds r0, #4
	b _080DC880
	.align 2, 0
_080DC870: .4byte 0x030046A4
_080DC874:
	ldr r0, _080DC894 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DC880:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DC898
	cmp r2, #2
	beq _080DC89C
	b _080DC8A0
	.align 2, 0
_080DC894: .4byte 0x030046A4
_080DC898:
	ldrb r0, [r4, #4]
	b _080DC89E
_080DC89C:
	ldrb r0, [r4]
_080DC89E:
	subs r1, r1, r0
_080DC8A0:
	cmp r7, r1
	bls _080DC912
	movs r5, #0x8f
	lsls r5, r5, #1
	adds r1, r6, r5
	b _080DC90C
_080DC8AC:
	add r3, sp, #4
	mov r4, sl
	adds r4, #0x1c
	movs r7, #0x92
	lsls r7, r7, #1
	adds r2, r6, r7
	ldrh r0, [r2]
	mov r7, sl
	ldrh r1, [r7, #0x1c]
	subs r0, r0, r1
	adds r1, r3, #0
	strh r0, [r1]
	ldrh r0, [r2, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r3, #2]
	ldrh r0, [r2, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r3, #4]
	adds r0, r3, #0
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r0, #0
	muls r1, r0, r1
	movs r2, #4
	ldrsh r0, [r3, r2]
	adds r3, r0, #0
	muls r3, r0, r3
	adds r0, r3, #0
	adds r1, r1, r0
	ldr r0, _080DC940 @ =0x0003FFFF
	adds r3, r4, #0
	cmp r1, r0
	ble _080DC8FE
	movs r7, #0xa0
	lsls r7, r7, #1
	adds r0, r6, r7
	ldrh r0, [r0]
	cmp r0, #8
	bls _080DC912
_080DC8FE:
	movs r0, #1
	orrs r0, r5
	mov r1, r8
	strh r0, [r1]
	movs r2, #0x8f
	lsls r2, r2, #1
	adds r1, r6, r2
_080DC90C:
	ldrh r0, [r1]
	subs r0, #4
	strh r0, [r1]
_080DC912:
	movs r5, #0x9a
	lsls r5, r5, #1
	adds r0, r6, r5
	mov r8, r3
	movs r7, #0x8e
	lsls r7, r7, #1
	adds r4, r6, r7
	ldrh r0, [r0]
	str r0, [sp, #0x18]
	movs r1, #0
	ldrsh r0, [r4, r1]
	movs r2, #4
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	ldr r0, [sp, #0x18]
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DC944
	adds r0, #4
	b _080DC952
	.align 2, 0
_080DC940: .4byte 0x0003FFFF
_080DC944:
	ldr r0, _080DC968 @ =0x030046A4
	ldr r1, [r0]
	ldr r3, [sp, #0x18]
	lsls r0, r3, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DC952:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DC96C
	cmp r2, #2
	beq _080DC972
	b _080DC978
	.align 2, 0
_080DC968: .4byte 0x030046A4
_080DC96C:
	mov r5, r8
	ldrb r0, [r5, #4]
	b _080DC976
_080DC972:
	mov r7, r8
	ldrb r0, [r7]
_080DC976:
	subs r1, r1, r0
_080DC978:
	str r1, [sp, #0x1c]
	movs r0, #0
	ldrsh r2, [r4, r0]
	movs r1, #4
	ldrsh r0, [r4, r1]
	adds r0, r2, r0
	movs r3, #2
	ldrsh r1, [r4, r3]
	adds r5, r6, #0
	adds r5, #0x8c
	cmn r0, r1
	bne _080DC992
	b _080DCBE4
_080DC992:
	mov r5, r8
	movs r7, #2
	ldrsh r0, [r5, r7]
	ldr r1, [sp, #0x1c]
	cmp r0, r1
	bgt _080DCA02
	lsls r0, r2, #1
	adds r0, r0, r2
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	movs r5, #0
	strh r0, [r4]
	movs r2, #2
	ldrsh r0, [r4, r2]
	lsls r0, r0, #2
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #2]
	movs r3, #4
	ldrsh r1, [r4, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	movs r1, #0xa
	bl Div
	strh r0, [r4, #4]
	movs r7, #0
	ldrsh r0, [r4, r7]
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #2
	ldrsh r2, [r4, r3]
	adds r0, r0, r1
	adds r0, r0, r2
	cmp r0, #0
	bge _080DC9E6
	rsbs r0, r0, #0
_080DC9E6:
	cmp r0, #2
	bgt _080DC9F2
	strh r5, [r4]
	strh r5, [r4, #2]
	strh r5, [r4, #4]
	b _080DC9FA
_080DC9F2:
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080DC9FA:
	mov r5, sp
	ldrh r7, [r5, #0x1c]
	mov r5, r8
	strh r7, [r5, #2]
_080DCA02:
	ldrh r0, [r4]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080DCA68 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r3
	orrs r2, r0
	str r2, [sp, #0xc]
	ldrh r1, [r4, #2]
	mov r5, r8
	ldrh r5, [r5, #2]
	adds r1, r1, r5
	lsls r1, r1, #0x10
	ldr r0, _080DCA6C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r4, #4]
	mov r7, r8
	ldrh r7, [r7, #4]
	adds r1, r1, r7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r2, sp, #0xc
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldrh r0, [r2]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080DCA64
	cmp r1, #0
	blt _080DCA64
	ldr r0, _080DCA70 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080DCA64
	ldr r0, _080DCA74 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080DCA78
_080DCA64:
	movs r5, #0
	b _080DCA86
	.align 2, 0
_080DCA68: .4byte 0xFFFF0000
_080DCA6C: .4byte 0x0000FFFF
_080DCA70: .4byte 0x030046A8
_080DCA74: .4byte 0x030046AC
_080DCA78:
	ldr r0, _080DCA98 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r3
_080DCA86:
	add r7, sp, #0xc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCA9C
	adds r0, #4
	b _080DCAA8
	.align 2, 0
_080DCA98: .4byte 0x030046A4
_080DCA9C:
	ldr r0, _080DCABC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCAA8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080DCAC0
	cmp r2, #2
	beq _080DCAC4
	b _080DCAC8
	.align 2, 0
_080DCABC: .4byte 0x030046A4
_080DCAC0:
	ldrb r0, [r7, #4]
	b _080DCAC6
_080DCAC4:
	ldrb r0, [r7]
_080DCAC6:
	subs r1, r1, r0
_080DCAC8:
	mov sb, r1
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCADA
	adds r0, #4
	b _080DCAE6
_080DCADA:
	ldr r0, _080DCB04 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCAE6:
	ldrh r7, [r0, #2]
	ldr r0, [sp, #0x18]
	cmp r0, r5
	beq _080DCB4A
	ldr r1, [sp, #0x1c]
	cmp r1, sb
	blt _080DCB1E
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080DCB08
	adds r0, #4
	b _080DCB14
	.align 2, 0
_080DCB04: .4byte 0x030046A4
_080DCB08:
	ldr r0, _080DCBB4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080DCB14:
	ldrh r0, [r0, #2]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080DCB4A
_080DCB1E:
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4]
	movs r3, #4
	ldrsh r1, [r4, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0xa
	bl Div
	rsbs r0, r0, #0
	strh r0, [r4, #4]
	movs r0, #0xb3
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080DCB4A:
	mov r5, sb
	cmp r5, #0
	ble _080DCB58
	movs r0, #0x40
	ands r7, r0
	cmp r7, #0
	beq _080DCBC4
_080DCB58:
	mov r7, sp
	movs r1, #0xe
	ldrsh r0, [r7, r1]
	cmp r0, sb
	bgt _080DCBC4
	ldr r0, _080DCBB8 @ =0x0300016C
	ldr r2, [r0]
	ldr r3, _080DCBBC @ =0x0000012F
	adds r7, r6, r3
	movs r0, #0
	ldrsb r0, [r7, r0]
	ldr r5, _080DCBC0 @ =0x00000F68
	adds r2, r2, r5
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r4, #0
	strb r4, [r0]
	adds r0, r6, #0
	bl AuxSprite_Remove
	adds r0, r6, #0
	adds r0, #0xdc
	bl ParticleShadow_Remove
	adds r5, r6, #0
	adds r5, #0x8c
	adds r0, r5, #0
	bl Hitbox_Unregister
	movs r0, #0xff
	strb r0, [r7]
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r6, r2
	strh r4, [r0]
	movs r3, #0x99
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	b _080DCBE4
	.align 2, 0
_080DCBB4: .4byte 0x030046A4
_080DCBB8: .4byte 0x0300016C
_080DCBBC: .4byte 0x0000012F
_080DCBC0: .4byte 0x00000F68
_080DCBC4:
	ldrh r0, [r4]
	mov r5, r8
	ldrh r5, [r5]
	adds r0, r0, r5
	mov r7, r8
	strh r0, [r7]
	ldrh r0, [r4, #2]
	ldrh r1, [r7, #2]
	adds r0, r0, r1
	strh r0, [r7, #2]
	ldrh r0, [r4, #4]
	ldrh r2, [r7, #4]
	adds r0, r0, r2
	strh r0, [r7, #4]
	adds r5, r6, #0
	adds r5, #0x8c
_080DCBE4:
	adds r0, r5, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl Hitbox_SetPos
	ldr r3, _080DCC00 @ =0x00000131
	adds r1, r6, r3
	ldrb r0, [r1]
	cmp r0, #0
	beq _080DCC04
	subs r0, #1
	strb r0, [r1]
	b _080DCC18
	.align 2, 0
_080DCC00: .4byte 0x00000131
_080DCC04:
	adds r4, r6, #0
	adds r4, #0x3c
	adds r0, r4, #0
	ldr r1, [sp, #0x24]
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
_080DCC18:
	movs r5, #0x9d
	lsls r5, r5, #1
	adds r0, r6, r5
	ldrb r1, [r0]
	str r0, [sp, #0x20]
	cmp r1, #0
	beq _080DCC32
	subs r0, r1, #1
	ldr r7, [sp, #0x20]
	strb r0, [r7]
	adds r4, r6, #0
	adds r4, #0x2c
	b _080DCCB0
_080DCC32:
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0x1d
	bhi _080DCC42
	movs r7, #3
	b _080DCC54
_080DCC42:
	cmp r0, #0x31
	bhi _080DCC4A
	movs r7, #2
	b _080DCC54
_080DCC4A:
	adds r4, r6, #0
	adds r4, #0x2c
	cmp r0, #0x59
	bhi _080DCCB0
	movs r7, #1
_080DCC54:
	ldrh r2, [r6, #0x3a]
	mov r8, r2
	ldrh r3, [r6, #0x34]
	mov sb, r3
	ldr r0, _080DCC80 @ =0x0000013B
	adds r5, r6, r0
	ldrb r0, [r5]
	cmp r0, #1
	bne _080DCC84
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r2, [sp, #0x14]
	ldr r1, [r2, #0x34]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	movs r0, #2
	b _080DCC9C
	.align 2, 0
_080DCC80: .4byte 0x0000013B
_080DCC84:
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r3, [sp, #0x14]
	ldr r1, [r3, #0x34]
	movs r0, #0
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	movs r0, #1
_080DCC9C:
	strb r0, [r5]
	mov r5, r8
	strh r5, [r6, #0x3a]
	mov r0, sb
	strh r0, [r6, #0x34]
	ldr r0, _080DCCE4 @ =0x085AD338
	adds r0, r7, r0
	ldrb r0, [r0]
	ldr r1, [sp, #0x20]
	strb r0, [r1]
_080DCCB0:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	mov r2, sl
	strh r0, [r2, #0x10]
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
	beq _080DCCE8
	mov r3, sl
	ldr r0, [r3]
	movs r1, #4
	orrs r0, r1
	str r0, [r3]
	b _080DCCF4
	.align 2, 0
_080DCCE4: .4byte 0x085AD338
_080DCCE8:
	mov r7, sl
	ldr r0, [r7]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
_080DCCF4:
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
	beq _080DCD1C
	mov r1, sl
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, sl
	str r0, [r2]
	b _080DCD28
_080DCD1C:
	mov r3, sl
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080DCD28:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r5, _080DCD5C @ =0x0000FFFF
	adds r2, r5, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r7, [r4, #7]
	cmp r0, r7
	blo _080DCD94
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DCD60
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DCD56
	ldrb r0, [r4, #5]
_080DCD56:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DCD70
	.align 2, 0
_080DCD5C: .4byte 0x0000FFFF
_080DCD60:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DCD70
	strh r1, [r4, #8]
_080DCD70:
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
	bne _080DCD94
	movs r0, #1
	strb r0, [r4, #7]
_080DCD94:
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r6, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r5, #0x99
	lsls r5, r5, #1
	adds r1, r6, r5
	ldrh r0, [r1]
	cmp r0, #0
	beq _080DCDB2
	subs r0, #1
	strh r0, [r1]
	b _080DCDC6
_080DCDB2:
	movs r7, #0x97
	lsls r7, r7, #1
	adds r1, r6, r7
	movs r0, #2
	strb r0, [r1]
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
_080DCDC6:
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dcdd8
FUN_080dcdd8: @ 0x080DCDD8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r1, #0
	movs r0, #0x98
	lsls r0, r0, #1
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080DCE2A
	adds r0, r5, #0
	adds r0, #0x1c
	movs r2, #0x9b
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r2, [r1]
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r5, r3
	ldrh r3, [r1]
	movs r4, #0
	str r4, [sp]
	movs r1, #0x20
	bl Entity080d84f8_Create
	movs r7, #0x1c
	ldrsh r0, [r5, r7]
	movs r2, #0x20
	ldrsh r1, [r5, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #1
	str r3, [sp]
	movs r7, #0x9e
	lsls r7, r7, #1
	adds r3, r5, r7
	ldrh r3, [r3]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	strb r4, [r6]
_080DCE2A:
	ldr r0, _080DCE80 @ =0x0300016C
	ldr r2, [r0]
	ldr r0, _080DCE84 @ =0x0000012F
	adds r6, r5, r0
	movs r0, #0
	ldrsb r0, [r6, r0]
	ldr r1, _080DCE88 @ =0x00000F68
	adds r2, r2, r1
	movs r1, #1
	lsls r1, r0
	ldr r0, [r2]
	bics r0, r1
	str r0, [r2]
	movs r2, #0x97
	lsls r2, r2, #1
	adds r0, r5, r2
	movs r4, #0
	strb r4, [r0]
	adds r0, r5, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	adds r0, #0xdc
	bl ParticleShadow_Remove
	adds r0, r5, #0
	adds r0, #0x8c
	bl Hitbox_Unregister
	movs r0, #0xff
	strb r0, [r6]
	movs r3, #0x96
	lsls r3, r3, #1
	adds r0, r5, r3
	strh r4, [r0]
	movs r7, #0x99
	lsls r7, r7, #1
	adds r0, r5, r7
	strh r4, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DCE80: .4byte 0x0300016C
_080DCE84: .4byte 0x0000012F
_080DCE88: .4byte 0x00000F68

	thumb_func_start FUN_080dce8c
FUN_080dce8c: @ 0x080DCE8C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	str r0, [sp, #4]
	mov r8, r1
	adds r4, r2, #0
	mov sl, r3
	ldr r0, _080DCEE4 @ =0x0300016C
	ldr r5, [r0]
	cmp r5, #0
	bne _080DCEB2
	bl FUN_080dd1f8
	adds r5, r0, #0
	cmp r5, #0
	beq _080DCEDE
_080DCEB2:
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DCEE8 @ =0x030047A4
	ldr r1, _080DCEEC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DCEDE
	ldr r0, _080DCEF0 @ =0x03002BC0
	ldr r7, [r0]
	movs r0, #4
	ands r7, r0
	cmp r7, #0
	bne _080DCEDE
	adds r0, r5, #0
	bl FUN_080dc764
	adds r6, r0, #0
	cmp r6, #0
	bne _080DCEF4
_080DCEDE:
	movs r0, #0
	b _080DD0A2
	.align 2, 0
_080DCEE4: .4byte 0x0300016C
_080DCEE8: .4byte 0x030047A4
_080DCEEC: .4byte 0x030047A0
_080DCEF0: .4byte 0x03002BC0
_080DCEF4:
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #1
	mov sb, r2
	mov r3, sb
	strb r3, [r0]
	subs r1, #2
	adds r0, r6, r1
	strh r7, [r0]
	movs r3, #0x92
	lsls r3, r3, #1
	adds r2, r6, r3
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x98
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	subs r3, #8
	adds r2, r6, r3
	mov r3, r8
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0x9b
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sl
	strh r2, [r0]
	movs r3, #0x9c
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [sp, #0x28]
	strh r0, [r1]
	movs r1, #0x9f
	lsls r1, r1, #1
	adds r0, r6, r1
	mov r2, sp
	ldrh r2, [r2, #0x2c]
	strh r2, [r0]
	subs r3, #6
	adds r0, r6, r3
	mov r1, sp
	ldrh r1, [r1, #0x2c]
	strh r1, [r0]
	ldr r2, _080DCFC8 @ =0x00000131
	adds r1, r6, r2
	movs r0, #0x1e
	strb r0, [r1]
	adds r3, #0xa
	adds r1, r6, r3
	ldr r0, [sp, #0x30]
	strh r0, [r1]
	ldr r1, _080DCFCC @ =0x0000013B
	adds r0, r6, r1
	mov r2, sb
	strb r2, [r0]
	mov r8, r6
	ldr r3, [sp, #4]
	ldr r0, [r3]
	ldr r1, [r3, #4]
	str r0, [r6, #0x1c]
	str r1, [r6, #0x20]
	adds r1, r5, #0
	adds r1, #0x18
	adds r0, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r4, r6, #0
	adds r4, #0x2c
	ldr r1, [r5, #0x34]
	str r7, [sp]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r6, #0x2c]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sb
	ands r1, r0
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sb
	ands r0, r2
	cmp r1, r0
	beq _080DCFD0
	ldr r0, [r6]
	movs r3, #4
	orrs r0, r3
	b _080DCFD8
	.align 2, 0
_080DCFC8: .4byte 0x00000131
_080DCFCC: .4byte 0x0000013B
_080DCFD0:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DCFD8:
	str r0, [r6]
	ldrb r0, [r4, #4]
	movs r3, #2
	adds r1, r3, #0
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r7]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	ands r0, r3
	cmp r1, r0
	beq _080DD002
	mov r1, r8
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	mov r2, r8
	str r0, [r2]
	b _080DD00E
_080DD002:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3]
_080DD00E:
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080DD044 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DD07C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DD048
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DD03C
	ldrb r0, [r4, #5]
_080DD03C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DD058
	.align 2, 0
_080DD044: .4byte 0x0000FFFF
_080DD048:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DD058
	strh r1, [r4, #8]
_080DD058:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r1, [r7]
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
	bne _080DD07C
	movs r0, #1
	strb r0, [r4, #7]
_080DD07C:
	mov r3, r8
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	strb r1, [r3, #7]
	adds r0, r6, #0
	adds r0, #0xdc
	mov r1, r8
	adds r1, #0x1c
	movs r2, #0
	bl ParticleShadow_Init
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080dc650
	adds r0, r6, #0
_080DD0A2:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dd0b4
FUN_080dd0b4: @ 0x080DD0B4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r3, r7, #0
	adds r3, #0x38
	ldr r1, _080DD114 @ =0x00000F68
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080DD14C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DD118 @ =0x030047A4
	ldr r1, _080DD11C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DD14C
	movs r1, #4
	ldr r0, _080DD120 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080DD14C
	movs r6, #0
	ldr r2, _080DD114 @ =0x00000F68
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _080DD124 @ =0x085AD33C
	mov sb, r0
	movs r1, #0xb3
	lsls r1, r1, #1
	adds r5, r7, r1
	adds r4, r3, #0
_080DD100:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080DD128
	movs r0, #1
	b _080DD12A
	.align 2, 0
_080DD114: .4byte 0x00000F68
_080DD118: .4byte 0x030047A4
_080DD11C: .4byte 0x030047A0
_080DD120: .4byte 0x03002BC0
_080DD124: .4byte 0x085AD33C
_080DD128:
	movs r0, #0
_080DD12A:
	cmp r0, #0
	beq _080DD13E
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_080DD13E:
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0xb
	ble _080DD100
_080DD14C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dd15c
FUN_080dd15c: @ 0x080DD15C
	push {r4, r5, r6, r7, lr}
	movs r6, #0
	ldr r1, _080DD180 @ =0x00000F68
	adds r7, r0, r1
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r5, r0, r1
	adds r4, r0, #0
	adds r4, #0x38
_080DD16E:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DD184
	movs r0, #1
	b _080DD186
	.align 2, 0
_080DD180: .4byte 0x00000F68
_080DD184:
	movs r0, #0
_080DD186:
	cmp r0, #0
	beq _080DD196
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r0, r5, #0
	bl ParticleShadow_Remove
_080DD196:
	movs r0, #0xa2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #0xb
	ble _080DD16E
	movs r1, #0
	ldr r0, _080DD1B4 @ =0x0300016C
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1B4: .4byte 0x0300016C

	thumb_func_start FUN_080dd1b8
FUN_080dd1b8: @ 0x080DD1B8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x18
	ldr r1, _080DD1E4 @ =0x0000E74B
	bl Video_GetAuxSprite
	ldr r0, _080DD1E8 @ =0x0000922E
	ldr r1, _080DD1EC @ =0x0000871C
	bl GetFile
	str r0, [r4, #0x34]
	ldr r0, _080DD1F0 @ =0x00000F68
	adds r1, r4, r0
	movs r0, #0
	str r0, [r1]
	ldr r0, _080DD1F4 @ =0x0300016C
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DD1E4: .4byte 0x0000E74B
_080DD1E8: .4byte 0x0000922E
_080DD1EC: .4byte 0x0000871C
_080DD1F0: .4byte 0x00000F68
_080DD1F4: .4byte 0x0300016C

	thumb_func_start FUN_080dd1f8
FUN_080dd1f8: @ 0x080DD1F8
	push {r4, lr}
	ldr r0, _080DD22C @ =0x0300016C
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD23E
	ldr r1, _080DD230 @ =0x00000F6C
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DD23C
	ldr r1, _080DD234 @ =FUN_080dd0b4
	ldr r2, _080DD238 @ =0x080DD15D
	bl SetEntityRoutine
	adds r0, r4, #0
	bl FUN_080dd1b8
	cmp r0, #0
	bge _080DD23C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DD23E
	.align 2, 0
_080DD22C: .4byte 0x0300016C
_080DD230: .4byte 0x00000F6C
_080DD234: .4byte FUN_080dd0b4
_080DD238: .4byte 0x080DD15D
_080DD23C:
	adds r0, r4, #0
_080DD23E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dd244
FUN_080dd244: @ 0x080DD244
	ldr r1, _080DD24C @ =0x0300016C
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DD24C: .4byte 0x0300016C

	thumb_func_start FUN_080dd250
FUN_080dd250: @ 0x080DD250
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	ldr r0, _080DD274 @ =0x0300016C
	ldr r0, [r0]
	cmp r0, #0
	beq _080DD30C
	adds r2, r0, #0
	adds r2, #0x38
	ldr r3, _080DD278 @ =0x00000F68
	adds r1, r0, r3
	ldr r0, [r1]
	cmp r0, #0
	bne _080DD286
	b _080DD30C
	.align 2, 0
_080DD274: .4byte 0x0300016C
_080DD278: .4byte 0x00000F68
_080DD27C:
	adds r0, r3, #0
	adds r1, r2, #0
	bl ArcTan2_8
	b _080DD310
_080DD286:
	movs r5, #0
	adds r7, r1, #0
	mov r4, sp
	mov ip, r2
	movs r0, #0xa2
	lsls r0, r0, #1
	mov r8, r0
_080DD294:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _080DD2A4
	movs r0, #1
	b _080DD2A6
_080DD2A4:
	movs r0, #0
_080DD2A6:
	cmp r0, #0
	beq _080DD304
	ldr r0, _080DD31C @ =0x0000012F
	add r0, ip
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080DD304
	movs r0, #0x99
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	cmp r0, #0
	beq _080DD304
	movs r0, #0x97
	lsls r0, r0, #1
	add r0, ip
	ldrb r0, [r0]
	cmp r0, #2
	beq _080DD304
	mov r1, ip
	ldrh r0, [r1, #0x1c]
	ldrh r1, [r6]
	subs r0, r0, r1
	strh r0, [r4]
	mov r3, ip
	ldrh r0, [r3, #0x1e]
	ldrh r1, [r6, #2]
	subs r0, r0, r1
	strh r0, [r4, #2]
	ldrh r0, [r3, #0x20]
	ldrh r1, [r6, #4]
	subs r0, r0, r1
	strh r0, [r4, #4]
	movs r0, #0
	ldrsh r3, [r4, r0]
	adds r1, r3, #0
	muls r1, r3, r1
	movs r0, #4
	ldrsh r2, [r4, r0]
	adds r0, r2, #0
	muls r0, r2, r0
	adds r1, r1, r0
	ldr r0, _080DD320 @ =0x00018FFF
	cmp r1, r0
	ble _080DD27C
_080DD304:
	add ip, r8
	adds r5, #1
	cmp r5, #0xb
	ble _080DD294
_080DD30C:
	movs r0, #1
	rsbs r0, r0, #0
_080DD310:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD31C: .4byte 0x0000012F
_080DD320: .4byte 0x00018FFF

	thumb_func_start FUN_080dd324
FUN_080dd324: @ 0x080DD324
	push {lr}
	adds r1, r0, #0
	adds r2, r1, #0
	cmp r1, #0
	beq _080DD35C
	ldr r3, _080DD358 @ =0x0000012F
	adds r0, r1, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080DD35C
	movs r3, #0x99
	lsls r3, r3, #1
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _080DD35C
	movs r1, #0x97
	lsls r1, r1, #1
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080DD35C
	movs r0, #1
	b _080DD35E
	.align 2, 0
_080DD358: .4byte 0x0000012F
_080DD35C:
	movs r0, #0
_080DD35E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080dd364
FUN_080dd364: @ 0x080DD364
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x28
	movs r0, #0
	mov sb, r0
	mov sl, r0
	movs r0, #0x70
	bl VM_SeekToKeyword
	add r1, sp, #0x10
	mov r8, r1
	cmp r0, #0
	beq _080DD3E8
	bl VM_GetPC
	cmp r0, #0
	beq _080DD392
	bl Script_GetValue
	b _080DD394
_080DD392:
	movs r0, #0
_080DD394:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080DD3B0 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD3B4
	bl Script_GetValue
	b _080DD3B6
	.align 2, 0
_080DD3B0: .4byte 0xFFFF0000
_080DD3B4:
	movs r0, #0
_080DD3B6:
	lsls r2, r0, #0x10
	ldr r1, _080DD3D0 @ =0x0000FFFF
	ldr r0, [sp, #0x10]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x10]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD3D4
	bl Script_GetValue
	b _080DD3D6
	.align 2, 0
_080DD3D0: .4byte 0x0000FFFF
_080DD3D4:
	movs r0, #0
_080DD3D6:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _080DD400 @ =0xFFFF0000
	add r1, sp, #0x10
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	str r0, [r1, #4]
	mov r8, r1
_080DD3E8:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD41C
	bl VM_GetPC
	cmp r0, #0
	beq _080DD404
	bl Script_GetValue
	b _080DD406
	.align 2, 0
_080DD400: .4byte 0xFFFF0000
_080DD404:
	movs r0, #0
_080DD406:
	mov sl, r0
	bl VM_GetPC
	cmp r0, #0
	beq _080DD418
	bl Script_GetValue
	mov sb, r0
	b _080DD41C
_080DD418:
	movs r1, #0
	mov sb, r1
_080DD41C:
	movs r0, #0x76
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD490
	bl VM_GetPC
	cmp r0, #0
	beq _080DD434
	bl Script_GetValue
	b _080DD436
_080DD434:
	movs r0, #0
_080DD436:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080DD454 @ =0xFFFF0000
	ldr r0, [sp, #0x18]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD458
	bl Script_GetValue
	b _080DD45A
	.align 2, 0
_080DD454: .4byte 0xFFFF0000
_080DD458:
	movs r0, #0
_080DD45A:
	lsls r2, r0, #0x10
	ldr r1, _080DD474 @ =0x0000FFFF
	ldr r0, [sp, #0x18]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x18]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD478
	bl Script_GetValue
	b _080DD47A
	.align 2, 0
_080DD474: .4byte 0x0000FFFF
_080DD478:
	movs r0, #0
_080DD47A:
	lsls r2, r0, #0x10
	lsrs r2, r2, #0x10
	ldr r3, _080DD48C @ =0xFFFF0000
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r3
	orrs r0, r2
	b _080DD49A
	.align 2, 0
_080DD48C: .4byte 0xFFFF0000
_080DD490:
	ldr r2, _080DD4F4 @ =0xFFFF0000
	str r0, [sp, #0x18]
	add r1, sp, #0x18
	ldr r0, [r1, #4]
	ands r0, r2
_080DD49A:
	str r0, [r1, #4]
	adds r7, r1, #0
	movs r0, #0x6c
	movs r1, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #0
	bl VM_GetKeywordValue
	adds r5, r0, #0
	add r4, sp, #0x20
	movs r0, #0
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	adds r1, r4, #0
	ldr r2, _080DD4F8 @ =0x05000002
	bl CpuSet
	mov r0, sb
	str r0, [sp]
	str r6, [sp, #4]
	str r5, [sp, #8]
	mov r0, r8
	adds r1, r7, #0
	adds r2, r4, #0
	mov r3, sl
	bl FUN_080dce8c
	movs r1, #0x96
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r1, #1
	orrs r1, r2
	strh r1, [r0]
	add sp, #0x28
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD4F4: .4byte 0xFFFF0000
_080DD4F8: .4byte 0x05000002

	thumb_func_start FUN_080dd4fc
FUN_080dd4fc: @ 0x080DD4FC
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r6, r0, #0
	adds r0, #0x58
	ldrh r0, [r0]
	cmp r0, #5
	bls _080DD512
	b _080DD6E6
_080DD512:
	lsls r0, r0, #2
	ldr r1, _080DD51C @ =_080DD520
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DD51C: .4byte _080DD520
_080DD520: @ jump table
	.4byte _080DD538 @ case 0
	.4byte _080DD570 @ case 1
	.4byte _080DD5B4 @ case 2
	.4byte _080DD5FC @ case 3
	.4byte _080DD644 @ case 4
	.4byte _080DD6A4 @ case 5
_080DD538:
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bne _080DD544
	ldr r0, _080DD56C @ =0x00000165
	bl PlaySound_082406e0
_080DD544:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
_080DD54A:
	lsls r3, r5, #6
	movs r0, #0x54
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #5
	ble _080DD54A
	b _080DD6E6
	.align 2, 0
_080DD56C: .4byte 0x00000165
_080DD570:
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x50
	movs r0, #1
	mov r8, r0
_080DD57A:
	lsls r4, r5, #6
	movs r0, #0x22
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #8
	adds r3, r4, #0
	bl FUN_081eec74
	movs r0, #0x40
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0xe
	adds r3, r4, #0
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #3
	ble _080DD57A
	b _080DD6E6
_080DD5B4:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r7, _080DD5F0 @ =0x030046B8
_080DD5BC:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DD5F4 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DD5F8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0xf
	ands r2, r0
	lsls r3, r5, #6
	movs r0, #0x96
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #5
	ble _080DD5BC
	b _080DD6E6
	.align 2, 0
_080DD5F0: .4byte 0x030046B8
_080DD5F4: .4byte 0x000003FF
_080DD5F8: .4byte 0x0203B400
_080DD5FC:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r7, _080DD638 @ =0x030046B8
_080DD604:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DD63C @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DD640 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0x1f
	ands r2, r0
	lsls r3, r5, #5
	movs r0, #0x64
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #7
	ble _080DD604
	b _080DD6E6
	.align 2, 0
_080DD638: .4byte 0x030046B8
_080DD63C: .4byte 0x000003FF
_080DD640: .4byte 0x0203B400
_080DD644:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r0, _080DD698 @ =0x0203B400
	mov sb, r0
	ldr r1, _080DD69C @ =0x030046B8
	mov r8, r1
	ldr r7, _080DD6A0 @ =0x000003FF
_080DD654:
	mov r0, r8
	ldr r1, [r0]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	movs r0, #0xf
	ands r2, r0
	adds r2, #5
	adds r1, #1
	ands r1, r7
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x50
	lsls r3, r5, #4
	str r1, [sp]
	movs r0, #2
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #0xf
	ble _080DD654
	b _080DD6E6
	.align 2, 0
_080DD698: .4byte 0x0203B400
_080DD69C: .4byte 0x030046B8
_080DD6A0: .4byte 0x000003FF
_080DD6A4:
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bne _080DD6E6
	movs r7, #2
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	movs r6, #8
_080DD6B4:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r5, #5
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r6, [sp, #0x20]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee4ec
	adds r5, #1
	cmp r5, #7
	ble _080DD6B4
_080DD6E6:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080dd6f4
FUN_080dd6f4: @ 0x080DD6F4
	push {lr}
	adds r2, r0, #0
	ldr r0, _080DD740 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080DD73A
	ldr r0, [r2, #0x60]
	cmp r0, #0
	bne _080DD73A
	adds r0, r2, #0
	adds r0, #0x58
	ldrh r0, [r0]
	ldr r3, _080DD744 @ =0x030046B8
	ldr r1, [r3]
	adds r1, #1
	ldr r2, _080DD748 @ =0x000003FF
	ands r1, r2
	str r1, [r3]
	lsls r1, r1, #1
	ldr r2, _080DD74C @ =0x0203B400
	adds r1, r1, r2
	ldrh r1, [r1]
	movs r2, #3
	ands r1, r2
	adds r1, #9
	bl Mod
	cmp r0, #0
	bne _080DD73A
	ldr r0, _080DD750 @ =0x00000339
	bl PlaySound_082406e0
_080DD73A:
	pop {r0}
	bx r0
	.align 2, 0
_080DD740: .4byte 0x030047A4
_080DD744: .4byte 0x030046B8
_080DD748: .4byte 0x000003FF
_080DD74C: .4byte 0x0203B400
_080DD750: .4byte 0x00000339

	thumb_func_start FUN_080dd754
FUN_080dd754: @ 0x080DD754
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x1c
	adds r5, r0, #0
	mov r8, r1
	mov sb, r2
	adds r7, r3, #0
	ldr r3, [sp, #0x38]
	adds r6, r5, #0
	ldr r2, _080DD7C8 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r4, #0x80
	lsls r4, r4, #1
	orrs r0, r4
	ldr r1, _080DD7CC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x11
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r4
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	ldr r2, _080DD7D0 @ =0x00002001
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	str r3, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r5, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r0, [r5, #0x60]
	cmp r0, #0
	bne _080DD7D8
	ldr r0, _080DD7D4 @ =0x00240004
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x40
	bl Hitbox_SetAttack
	b _080DD7EC
	.align 2, 0
_080DD7C8: .4byte 0xFFFF0000
_080DD7CC: .4byte 0x0000FFFF
_080DD7D0: .4byte 0x00002001
_080DD7D4: .4byte 0x00240004
_080DD7D8:
	movs r0, #0x80
	lsls r0, r0, #0xb
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	mov r1, r8
	mov r2, sb
	movs r3, #0x40
	bl Hitbox_SetAttack
_080DD7EC:
	ldr r0, _080DD814 @ =0x00003246
	strh r0, [r6, #4]
	adds r1, r5, #0
	adds r1, #0x50
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	add sp, #0x1c
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080DD814: .4byte 0x00003246

	thumb_func_start FUN_080dd818
FUN_080dd818: @ 0x080DD818
	bx lr
	.align 2, 0

	thumb_func_start FUN_080dd81c
FUN_080dd81c: @ 0x080DD81C
	push {r4, r5, lr}
	adds r4, r1, #0
	adds r0, r4, #0
	bl FUN_080dd4fc
	adds r0, r4, #0
	bl FUN_080dd6f4
	adds r5, r4, #0
	adds r5, #0x58
	ldrh r0, [r5]
	subs r0, #0xa
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080DD842
	adds r0, r4, #0
	bl Hitbox_Register
_080DD842:
	ldrh r0, [r5]
	cmp r0, #0x28
	bls _080DD852
	adds r1, r4, #0
	adds r1, #0x5d
	movs r0, #2
	strb r0, [r1]
	b _080DD856
_080DD852:
	adds r0, #1
	strh r0, [r5]
_080DD856:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080dd85c
FUN_080dd85c: @ 0x080DD85C
	push {lr}
	adds r3, r1, #0
	adds r3, #0x5d
	movs r2, #0
	strb r2, [r3]
	movs r2, #0x5e
	adds r2, r2, r1
	mov ip, r2
	ldrb r2, [r2]
	lsls r2, r2, #0x18
	asrs r2, r2, #0x18
	movs r3, #1
	lsls r3, r2
	ldr r2, [r0, #0x18]
	bics r2, r3
	str r2, [r0, #0x18]
	movs r0, #0xff
	mov r3, ip
	strb r0, [r3]
	adds r0, r1, #0
	movs r1, #0x64
	bl ClearMemory
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080dd890
FUN_080dd890: @ 0x080DD890
	push {r4, lr}
	adds r3, r0, #0
	movs r4, #0
	movs r2, #1
_080DD898:
	adds r1, r2, #0
	lsls r1, r4
	ldr r0, [r3, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _080DD8A8
	movs r0, #1
	b _080DD8AA
_080DD8A8:
	movs r0, #0
_080DD8AA:
	cmp r0, #0
	bne _080DD8C6
	movs r0, #0x64
	muls r0, r4, r0
	adds r0, #0x1c
	adds r0, r3, r0
	adds r1, r0, #0
	adds r1, #0x5e
	strb r4, [r1]
	lsls r2, r4
	ldr r1, [r3, #0x18]
	orrs r1, r2
	str r1, [r3, #0x18]
	b _080DD8CE
_080DD8C6:
	adds r4, #1
	cmp r4, #4
	ble _080DD898
	movs r0, #0
_080DD8CE:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080dd8d4
FUN_080dd8d4: @ 0x080DD8D4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r4, r0, #0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r3, #0
	cmp r4, #0
	beq _080DD92C
	ldr r0, _080DD938 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD8F4
	bl Entity080ddad0_Create
	cmp r0, #0
	beq _080DD92C
_080DD8F4:
	bl FUN_080dd890
	adds r3, r0, #0
	cmp r3, #0
	beq _080DD92C
	adds r1, r3, #0
	adds r1, #0x5d
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r3, #0x50]
	str r1, [r3, #0x54]
	adds r0, r3, #0
	adds r0, #0x58
	strh r2, [r0]
	adds r0, #4
	strb r5, [r0]
	str r6, [r3, #0x60]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	adds r0, r3, #0
	adds r1, r7, #0
	ldr r2, [sp, #0x18]
	ldr r3, [sp, #0x1c]
	bl FUN_080dd754
_080DD92C:
	movs r0, #0
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DD938: .4byte 0x03000170

	thumb_func_start FUN_080dd93c
FUN_080dd93c: @ 0x080DD93C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	ldr r0, _080DD978 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DD954
	bl Entity080ddad0_Create
	cmp r0, #0
	beq _080DDA46
_080DD954:
	bl FUN_080dd890
	adds r5, r0, #0
	cmp r5, #0
	beq _080DDA46
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DD9B2
	bl VM_GetPC
	cmp r0, #0
	beq _080DD97C
	bl Script_GetValue
	adds r1, r0, #0
	b _080DD97E
	.align 2, 0
_080DD978: .4byte 0x03000170
_080DD97C:
	movs r1, #0
_080DD97E:
	adds r0, r5, #0
	adds r0, #0x50
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD992
	bl Script_GetValue
	b _080DD994
_080DD992:
	movs r0, #0
_080DD994:
	adds r1, r5, #0
	adds r1, #0x52
	strh r0, [r1]
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9AA
	bl Script_GetValue
	adds r1, r0, #0
	b _080DD9AC
_080DD9AA:
	movs r1, #0
_080DD9AC:
	adds r0, r5, #0
	adds r0, #0x54
	strh r1, [r0]
_080DD9B2:
	movs r0, #0x50
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080DDA0C
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9CE
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	b _080DD9D0
_080DD9CE:
	movs r0, #0
_080DD9D0:
	mov r8, r0
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9E4
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r7, r0, #0x10
	b _080DD9E6
_080DD9E4:
	movs r7, #0
_080DD9E6:
	bl VM_GetPC
	cmp r0, #0
	beq _080DD9F8
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r6, r0, #0x10
	b _080DD9FA
_080DD9F8:
	movs r6, #0
_080DD9FA:
	bl VM_GetPC
	cmp r0, #0
	beq _080DDA14
	bl Script_GetValue
	lsls r0, r0, #0x10
	asrs r4, r0, #0x10
	b _080DDA16
_080DDA0C:
	movs r0, #0
	mov r8, r0
	movs r7, #0
	movs r6, #0
_080DDA14:
	movs r4, #0
_080DDA16:
	movs r0, #0x63
	movs r1, #0
	bl VM_GetKeywordValue
	str r0, [r5, #0x60]
	adds r2, r5, #0
	adds r2, #0x5d
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0x58
	strh r1, [r0]
	adds r1, r5, #0
	adds r1, #0x5c
	movs r0, #2
	strb r0, [r1]
	str r4, [sp]
	adds r0, r5, #0
	mov r1, r8
	adds r2, r7, #0
	adds r3, r6, #0
	bl FUN_080dd754
_080DDA46:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity080ddad0_Update
Entity080ddad0_Update: @ 0x080DDA54
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, [r4, #0x18]
	cmp r0, #0
	beq _080DDAA0
	movs r5, #0
	ldr r6, _080DDA74 @ =0x085AD348
_080DDA62:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r4, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _080DDA78
	movs r0, #1
	b _080DDA7A
	.align 2, 0
_080DDA74: .4byte 0x085AD348
_080DDA78:
	movs r0, #0
_080DDA7A:
	cmp r0, #0
	beq _080DDA9A
	movs r0, #0x64
	adds r1, r5, #0
	muls r1, r0, r1
	adds r1, #0x1c
	adds r1, r4, r1
	adds r0, r1, #0
	adds r0, #0x5d
	ldrb r0, [r0]
	lsls r0, r0, #2
	adds r0, r0, r6
	ldr r2, [r0]
	adds r0, r4, #0
	bl _call_via_r2
_080DDA9A:
	adds r5, #1
	cmp r5, #4
	ble _080DDA62
_080DDAA0:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity080ddad0_Destroy
Entity080ddad0_Destroy: @ 0x080DDAA8
	ldr r1, _080DDAB0 @ =0x03000170
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DDAB0: .4byte 0x03000170

	thumb_func_start FUN_080ddab4
FUN_080ddab4: @ 0x080DDAB4
	bx lr
	.align 2, 0

	thumb_func_start Entity080ddad0_Init
Entity080ddad0_Init: @ 0x080DDAB8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ddab4
	ldr r0, _080DDACC @ =0x03000170
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080DDACC: .4byte 0x03000170

	thumb_func_start Entity080ddad0_Create
Entity080ddad0_Create: @ 0x080DDAD0
	push {r4, lr}
	ldr r0, _080DDB08 @ =0x03000170
	ldr r0, [r0]
	cmp r0, #0
	bne _080DDB16
	movs r1, #0x84
	lsls r1, r1, #2
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080DDB14
	ldr r1, _080DDB0C @ =Entity080ddad0_Update
	ldr r2, _080DDB10 @ =Entity080ddad0_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	movs r1, #0
	bl Entity080ddad0_Init
	cmp r0, #0
	bge _080DDB14
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DDB16
	.align 2, 0
_080DDB08: .4byte 0x03000170
_080DDB0C: .4byte Entity080ddad0_Update
_080DDB10: .4byte Entity080ddad0_Destroy
_080DDB14:
	adds r0, r4, #0
_080DDB16:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080ddb1c
FUN_080ddb1c: @ 0x080DDB1C
	ldr r1, _080DDB24 @ =0x03000170
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080DDB24: .4byte 0x03000170

	thumb_func_start Entity080de11c_Update
Entity080de11c_Update: @ 0x080DDB28
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0xce
	lsls r0, r0, #4
	adds r1, r7, r0
	ldr r0, [r1]
	cmp r0, #0
	bne _080DDB42
	b _080DDC90
_080DDB42:
	movs r2, #1
	mov sb, r2
	movs r3, #2
	mov sl, r3
	adds r6, r7, #0
	adds r6, #0x58
	adds r4, r7, #0
	adds r4, #0x18
	mov ip, r1
	movs r0, #0x2f
	mov r8, r0
_080DDB58:
	ldrb r0, [r6]
	cmp r0, #0
	bne _080DDB60
	b _080DDC7E
_080DDB60:
	ldrh r0, [r4, #0x38]
	ldrh r1, [r4, #0x28]
	adds r0, r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x3a]
	ldrh r2, [r4, #0x2a]
	adds r0, r0, r2
	strh r0, [r4, #0x2a]
	ldrh r0, [r4, #0x3c]
	ldrh r3, [r4, #0x2c]
	adds r0, r0, r3
	strh r0, [r4, #0x2c]
	ldr r1, _080DDBBC @ =0x00000CDC
	adds r0, r7, r1
	ldr r3, [r0]
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r2, [r5]
	lsrs r2, r2, #6
	ldrb r1, [r4, #0x1a]
	lsrs r1, r1, #3
	ldrb r0, [r4, #0x1b]
	lsrs r0, r0, #3
	muls r0, r1, r0
	muls r0, r2, r0
	ldrh r3, [r3, #4]
	adds r0, r0, r3
	strh r0, [r4, #0x18]
	ldrb r0, [r4, #4]
	mov r2, sb
	ands r2, r0
	ldrh r1, [r5]
	movs r0, #0x30
	ands r0, r1
	lsrs r0, r0, #4
	mov r3, sb
	ands r0, r3
	cmp r2, r0
	beq _080DDBC0
	ldr r0, [r4, #0x10]
	movs r1, #4
	orrs r0, r1
	b _080DDBC8
	.align 2, 0
_080DDBBC: .4byte 0x00000CDC
_080DDBC0:
	ldr r0, [r4, #0x10]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080DDBC8:
	str r0, [r4, #0x10]
	ldrb r0, [r4, #4]
	mov r1, sl
	ands r1, r0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	ldrh r2, [r5]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, sl
	ands r0, r2
	cmp r1, r0
	beq _080DDBEC
	ldr r0, [r4, #0x10]
	movs r1, #8
	orrs r0, r1
	b _080DDBF4
_080DDBEC:
	ldr r0, [r4, #0x10]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080DDBF4:
	str r0, [r4, #0x10]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	movs r1, #0
	strh r0, [r4, #0xe]
	ldr r3, _080DDC2C @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080DDC64
	strh r1, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080DDC36
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080DDC30
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080DDC4C
	.align 2, 0
_080DDC2C: .4byte 0x0000FFFF
_080DDC30:
	subs r0, #1
	strh r0, [r4, #8]
	b _080DDC4A
_080DDC36:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080DDC4A
	strh r1, [r4, #8]
	movs r2, #1
	b _080DDC4C
_080DDC4A:
	movs r2, #0
_080DDC4C:
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r1, [r5]
	movs r0, #0xf
	ands r0, r1
	ldrh r1, [r4, #0xc]
	muls r0, r1, r0
	asrs r0, r0, #6
	strb r0, [r4, #7]
	b _080DDC66
_080DDC64:
	movs r2, #0
_080DDC66:
	cmp r2, #0
	beq _080DDC7E
	movs r0, #0
	strb r0, [r6]
	ldr r0, [r4, #0x10]
	mov r3, sb
	orrs r0, r3
	str r0, [r4, #0x10]
	mov r1, ip
	ldr r0, [r1]
	subs r0, #1
	str r0, [r1]
_080DDC7E:
	adds r6, #0x44
	adds r4, #0x44
	movs r2, #1
	rsbs r2, r2, #0
	add r8, r2
	mov r3, r8
	cmp r3, #0
	blt _080DDC90
	b _080DDB58
_080DDC90:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity080de11c_Destroy
Entity080de11c_Destroy: @ 0x080DDCA0
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x28
	movs r5, #0x2f
_080DDCA8:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x44
	subs r5, #1
	cmp r5, #0
	bge _080DDCA8
	movs r1, #0
	ldr r0, _080DDCC4 @ =0x03000174
	str r1, [r0]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080DDCC4: .4byte 0x03000174

	thumb_func_start FUN_080ddcc8
FUN_080ddcc8: @ 0x080DDCC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x1c
	adds r7, r0, #0
	adds r6, r2, #0
	str r3, [sp, #0xc]
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	str r1, [sp, #8]
	ldr r0, _080DDCF8 @ =0x03000174
	ldr r0, [r0]
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _080DDCFC
	bl Entity080de11c_Create
	str r0, [sp, #0x10]
	cmp r0, #0
	bne _080DDCFC
	movs r0, #0
	b _080DDF74
	.align 2, 0
_080DDCF8: .4byte 0x03000174
_080DDCFC:
	movs r0, #0
	str r0, [sp, #0x14]
	ldr r1, _080DDD34 @ =0x030046B8
	mov sb, r1
	ldr r2, [sp, #0x10]
	adds r2, #0x50
	mov sl, r2
	ldr r0, [sp, #0x10]
	adds r0, #0x28
	mov r8, r0
	mov r4, r8
	ldr r1, [sp, #0x10]
	adds r1, #0x18
	str r1, [sp, #0x18]
_080DDD18:
	mov r2, sl
	ldrb r0, [r2, #8]
	cmp r0, #0
	beq _080DDD22
	b _080DDF58
_080DDD22:
	cmp r6, #0
	beq _080DDE0E
	movs r1, #0
	ldrsh r0, [r6, r1]
	cmp r0, #0
	bne _080DDD38
	ldrh r0, [r7]
	b _080DDD78
	.align 2, 0
_080DDD34: .4byte 0x030046B8
_080DDD38:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080DDD64 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080DDD68 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #0
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDD6C
	asrs r0, r0, #1
	b _080DDD72
	.align 2, 0
_080DDD64: .4byte 0x000003FF
_080DDD68: .4byte 0x0203B400
_080DDD6C:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDD72:
	subs r0, r1, r0
	ldrh r1, [r7]
	adds r0, r0, r1
_080DDD78:
	strh r0, [r4, #0x18]
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, #0
	bne _080DDD86
	ldrh r0, [r7, #2]
	b _080DDDC4
_080DDD86:
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDDB0 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDDB4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #2
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #2
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDDB8
	asrs r0, r0, #1
	b _080DDDBE
	.align 2, 0
_080DDDB0: .4byte 0x000003FF
_080DDDB4: .4byte 0x0203B400
_080DDDB8:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDDBE:
	subs r0, r1, r0
	ldrh r1, [r7, #2]
	adds r0, r0, r1
_080DDDC4:
	strh r0, [r4, #0x1a]
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0
	beq _080DDE16
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDDF8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDDFC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r2, #4
	ldrsh r1, [r6, r2]
	bl Mod
	adds r1, r0, #0
	movs r2, #4
	ldrsh r0, [r6, r2]
	cmp r0, #0
	blt _080DDE00
	asrs r0, r0, #1
	b _080DDE06
	.align 2, 0
_080DDDF8: .4byte 0x000003FF
_080DDDFC: .4byte 0x0203B400
_080DDE00:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_080DDE06:
	subs r0, r1, r0
	ldrh r1, [r7, #4]
	adds r0, r0, r1
	b _080DDE18
_080DDE0E:
	ldrh r0, [r7]
	strh r0, [r4, #0x18]
	ldrh r0, [r7, #2]
	strh r0, [r4, #0x1a]
_080DDE16:
	ldrh r0, [r7, #4]
_080DDE18:
	strh r0, [r4, #0x1c]
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	add r2, sp, #0x48
	ldrb r2, [r2]
	strb r2, [r4, #0xf]
	movs r0, #1
	mov r1, sl
	strb r0, [r1, #8]
	movs r2, #0
	str r2, [sp, #4]
	add r0, sp, #4
	ldr r2, _080DDE64 @ =0x05000002
	bl CpuSet
	ldr r0, [sp, #0x3c]
	cmp r0, #0
	beq _080DDE9A
	mov r3, sl
	ldr r2, _080DDE68 @ =0x085B0A08
	ldr r0, [sp, #0xc]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp, #0x3c]
	muls r0, r1, r0
	cmp r0, #0
	blt _080DDE6C
	asrs r0, r0, #0xc
	b _080DDE72
	.align 2, 0
_080DDE64: .4byte 0x05000002
_080DDE68: .4byte 0x085B0A08
_080DDE6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DDE72:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	movs r0, #0xff
	ldr r1, [sp, #0xc]
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r1, [sp, #0x3c]
	muls r0, r1, r0
	cmp r0, #0
	blt _080DDE92
	asrs r0, r0, #0xc
	b _080DDE98
_080DDE92:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080DDE98:
	strh r0, [r3, #4]
_080DDE9A:
	ldr r2, [sp, #0x40]
	cmp r2, #0
	bne _080DDEC0
	mov r1, sb
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080DDEB8 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	ldr r1, _080DDEBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x20
	b _080DDED6
	.align 2, 0
_080DDEB8: .4byte 0x000003FF
_080DDEBC: .4byte 0x0203B400
_080DDEC0:
	mov r2, sb
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080DDEEC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080DDEF0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	ldr r1, [sp, #0x40]
_080DDED6:
	bl Mod
	strh r0, [r4, #0x2a]
	ldr r0, [sp, #0x44]
	cmp r0, #1
	beq _080DDF00
	cmp r0, #1
	bgt _080DDEF4
	cmp r0, #0
	beq _080DDF00
	b _080DDF1C
	.align 2, 0
_080DDEEC: .4byte 0x000003FF
_080DDEF0: .4byte 0x0203B400
_080DDEF4:
	ldr r1, [sp, #0x44]
	cmp r1, #2
	beq _080DDF0C
	cmp r1, #3
	beq _080DDF10
	b _080DDF1C
_080DDF00:
	movs r5, #0xf
	mov r0, r8
	movs r1, #1
	bl FUN_0822dadc
	b _080DDF26
_080DDF0C:
	movs r5, #0x10
	b _080DDF12
_080DDF10:
	movs r5, #0x11
_080DDF12:
	mov r0, r8
	movs r1, #0
	bl FUN_0822dadc
	b _080DDF26
_080DDF1C:
	movs r5, #0xf
	mov r0, r8
	movs r1, #0
	bl FUN_0822dadc
_080DDF26:
	ldr r2, [sp, #0x10]
	ldr r1, _080DDF84 @ =0x00000CD8
	adds r0, r2, r1
	ldr r1, [r0]
	adds r2, r5, #0
	movs r0, #0
	str r0, [sp]
	ldr r0, [sp, #0x18]
	movs r3, #0
	bl FUN_08236fac
	ldr r2, [sp, #0x10]
	movs r0, #0xce
	lsls r0, r0, #4
	adds r1, r2, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	ldr r0, [sp, #8]
	subs r0, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	str r0, [sp, #8]
	cmp r0, #0
	beq _080DDF72
_080DDF58:
	movs r1, #0x44
	add sl, r1
	adds r4, #0x44
	add r8, r1
	ldr r2, [sp, #0x18]
	adds r2, #0x44
	str r2, [sp, #0x18]
	ldr r0, [sp, #0x14]
	adds r0, #1
	str r0, [sp, #0x14]
	cmp r0, #0x2f
	bgt _080DDF72
	b _080DDD18
_080DDF72:
	movs r0, #1
_080DDF74:
	add sp, #0x1c
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DDF84: .4byte 0x00000CD8

