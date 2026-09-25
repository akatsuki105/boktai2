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

	thumb_func_start Entity080dc44c_Update
Entity080dc44c_Update: @ 0x080DC35C
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

	thumb_func_start Entity080dc44c_Destroy
Entity080dc44c_Destroy: @ 0x080DC3C4
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

	thumb_func_start Entity080dc44c_Init
Entity080dc44c_Init: @ 0x080DC440
	push {lr}
	bl FUN_080dc418
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start Entity080dc44c_Create
Entity080dc44c_Create: @ 0x080DC44C
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
	ldr r1, _080DC488 @ =Entity080dc44c_Update
	ldr r2, _080DC48C @ =Entity080dc44c_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity080dc44c_Init
	cmp r0, #0
	bge _080DC490
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080DC492
	.align 2, 0
_080DC484: .4byte 0x03000168
_080DC488: .4byte Entity080dc44c_Update
_080DC48C: .4byte Entity080dc44c_Destroy
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
