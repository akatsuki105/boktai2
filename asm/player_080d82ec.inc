	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080cc1e8
FUN_080cc1e8: @ 0x080CC1E8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	adds r7, r2, #0
	movs r3, #0
	movs r0, #0xb9
	lsls r0, r0, #2
	adds r2, r6, r0
	ldrh r0, [r2]
	cmp r0, r1
	bne _080CC200
	movs r3, #1
_080CC200:
	strh r1, [r2]
	adds r4, r6, #0
	adds r4, #0x88
	adds r5, r6, #0
	adds r5, #0x68
	ldr r2, _080CC238 @ =0x000002E6
	adds r0, r6, r2
	ldrb r2, [r0]
	adds r2, r1, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r3, [sp]
	adds r0, r4, #0
	adds r1, r5, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _080CC23C @ =0x000002E7
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CC240
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _080CC24C
	.align 2, 0
_080CC238: .4byte 0x000002E6
_080CC23C: .4byte 0x000002E7
_080CC240:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080CC24C:
	str r1, [r0]
	lsls r1, r7, #0x10
	lsrs r1, r1, #0x10
	adds r0, r4, #0
	bl MainSprite_SetAnimSpeed
	adds r0, r4, #0
	adds r1, r5, #0
	bl MainSprite_AdvanceAnim
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cc268
FUN_080cc268: @ 0x080CC268
	push {r4, lr}
	mov ip, r0
	adds r4, r1, #0
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080CC29C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CC2A0
	asrs r0, r0, #0xc
	b _080CC2A6
	.align 2, 0
_080CC29C: .4byte 0x085B0A08
_080CC2A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC2A6:
	mov r1, ip
	strh r0, [r1, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	cmp r0, #0
	blt _080CC2BC
	asrs r0, r0, #0xc
	b _080CC2C2
_080CC2BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC2C2:
	mov r1, ip
	strh r0, [r1, #0x38]
	ldr r3, _080CC2E8 @ =0x000001C7
	add r3, ip
	ldrb r3, [r3]
	cmp r3, #1
	bne _080CC30A
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _080CC2EC
	movs r2, #0x38
	ldrsh r1, [r1, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080CC2FA
	b _080CC2FE
	.align 2, 0
_080CC2E8: .4byte 0x000001C7
_080CC2EC:
	mov r2, ip
	movs r0, #0x38
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC2FE
_080CC2FA:
	asrs r0, r0, #6
	b _080CC304
_080CC2FE:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080CC304:
	mov r1, ip
	strh r0, [r1, #0x38]
	b _080CC342
_080CC30A:
	cmp r3, #2
	bne _080CC342
	mov r2, ip
	movs r1, #0x34
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bge _080CC326
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	bge _080CC334
	b _080CC338
_080CC326:
	mov r2, ip
	movs r0, #0x34
	ldrsh r1, [r2, r0]
	movs r0, #0x34
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC338
_080CC334:
	asrs r0, r0, #6
	b _080CC33E
_080CC338:
	rsbs r0, r0, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_080CC33E:
	mov r1, ip
	strh r0, [r1, #0x34]
_080CC342:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cc348
FUN_080cc348: @ 0x080CC348
	push {r4, lr}
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r3, r0, r4
	movs r4, #0
	strb r1, [r3]
	ldr r3, _080CC368 @ =0x0000037D
	adds r1, r0, r3
	strb r2, [r1]
	ldr r1, _080CC36C @ =0x0000037E
	adds r0, r0, r1
	strh r4, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC368: .4byte 0x0000037D
_080CC36C: .4byte 0x0000037E

	thumb_func_start FUN_080cc370
FUN_080cc370: @ 0x080CC370
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #1
	str r0, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_0809ebf4
	cmp r0, #0
	beq _080CC38A
	movs r1, #0x10
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
_080CC38A:
	ldr r1, _080CC3B8 @ =0x00000604
	adds r0, r4, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _080CC3BC @ =0x00000606
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r2, _080CC3C0 @ =0x0000035A
	adds r0, r4, r2
	strh r1, [r0]
	movs r0, #0xd9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrb r1, [r2]
	movs r0, #0xfd
	ands r0, r1
	strb r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CC3B8: .4byte 0x00000604
_080CC3BC: .4byte 0x00000606
_080CC3C0: .4byte 0x0000035A

	thumb_func_start FUN_080cc3c4
FUN_080cc3c4: @ 0x080CC3C4
	ldr r2, _080CC3D0 @ =0x0000035A
	adds r0, r0, r2
	ldrh r2, [r0]
	orrs r1, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CC3D0: .4byte 0x0000035A

	thumb_func_start FUN_080cc3d4
FUN_080cc3d4: @ 0x080CC3D4
	ldr r2, _080CC3E0 @ =0x0000035A
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	bx lr
	.align 2, 0
_080CC3E0: .4byte 0x0000035A

	thumb_func_start FUN_080cc3e4
FUN_080cc3e4: @ 0x080CC3E4
	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC3F8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC3FC
	movs r0, #1
	rsbs r0, r0, #0
	b _080CC400
	.align 2, 0
_080CC3F8: .4byte 0x03002C68
_080CC3FC:
	movs r3, #0x18
	ldrsh r0, [r0, r3]
_080CC400:
	cmp r2, r0
	bne _080CC40A
	adds r0, r1, #0
	bl PlaySound_082406e0
_080CC40A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cc410
FUN_080cc410: @ 0x080CC410
	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC424 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC428
	movs r0, #1
	rsbs r0, r0, #0
	b _080CC42C
	.align 2, 0
_080CC424: .4byte 0x03002C68
_080CC428:
	movs r3, #0x18
	ldrsh r0, [r0, r3]
_080CC42C:
	cmp r2, r0
	bne _080CC436
	adds r0, r1, #0
	bl sound_08240740
_080CC436:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cc43c
FUN_080cc43c: @ 0x080CC43C
	push {lr}
	adds r2, r0, #0
	ldr r0, _080CC450 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC454
	movs r1, #1
	rsbs r1, r1, #0
	b _080CC458
	.align 2, 0
_080CC450: .4byte 0x03002C68
_080CC454:
	movs r3, #0x18
	ldrsh r1, [r0, r3]
_080CC458:
	ldr r0, [r2, #0x18]
	cmp r0, r1
	bne _080CC484
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #5
	beq _080CC472
	movs r0, #0xd8
	bl sound_08240740
	b _080CC484
_080CC472:
	ldr r0, _080CC488 @ =0x00000239
	bl sound_08240740
	ldr r0, _080CC48C @ =0x00000202
	bl sound_08240740
	ldr r0, _080CC490 @ =0x00000366
	bl sound_08240740
_080CC484:
	pop {r0}
	bx r0
	.align 2, 0
_080CC488: .4byte 0x00000239
_080CC48C: .4byte 0x00000202
_080CC490: .4byte 0x00000366

	thumb_func_start FUN_080cc494
FUN_080cc494: @ 0x080CC494
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r1, [r2, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CC4B2
	adds r0, r2, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _080CC4E4
_080CC4B2:
	movs r0, #0x24
	ldrsh r1, [r2, r0]
	movs r4, #0x24
	ldrsh r0, [r3, r4]
	subs r4, r1, r0
	movs r0, #0x28
	ldrsh r1, [r2, r0]
	movs r2, #0x28
	ldrsh r0, [r3, r2]
	subs r1, r1, r0
	cmp r4, #0
	bne _080CC4DA
	cmp r1, #0
	bne _080CC4DA
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0xe0
	b _080CC4E4
_080CC4DA:
	adds r0, r4, #0
	bl ArcTan2_8
	adds r1, r0, #0
	adds r1, #0x60
_080CC4E4:
	movs r0, #0xff
	ands r1, r0
	asrs r0, r1, #6
	lsls r0, r0, #1
	adds r0, #1
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cc4f4
FUN_080cc4f4: @ 0x080CC4F4
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r3, r1, #0
	adds r5, r2, #0
	adds r1, #0x40
	ldrh r0, [r1]
	adds r6, r5, #0
	adds r6, #0x40
	movs r7, #0
	strh r0, [r6]
	ldrh r0, [r1]
	cmp r0, #0xc8
	bls _080CC512
	movs r0, #0xc8
	strh r0, [r6]
_080CC512:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ldr r2, [r3, #0x38]
	ands r2, r0
	cmp r2, #0
	beq _080CC53C
	ldr r0, _080CC538 @ =0x000003D2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_080cc494
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	b _080CC60C
	.align 2, 0
_080CC538: .4byte 0x000003D2
_080CC53C:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080CC554
	ldrh r0, [r5, #6]
	movs r1, #4
	orrs r0, r1
	strh r0, [r5, #6]
	strh r2, [r6]
	b _080CC60E
_080CC554:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r4, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080CC5F8
	ldrh r1, [r3, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CC588
	adds r0, r3, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r1, r4, r2
	b _080CC5D8
_080CC588:
	movs r0, #0x24
	ldrsh r1, [r3, r0]
	movs r2, #0x24
	ldrsh r0, [r5, r2]
	subs r2, r1, r0
	movs r0, #0x28
	ldrsh r1, [r3, r0]
	movs r3, #0x28
	ldrsh r0, [r5, r3]
	subs r1, r1, r0
	cmp r2, #0
	bne _080CC5B6
	cmp r1, #0
	bne _080CC5B6
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r2, #0xfa
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _080CC5DA
_080CC5B6:
	adds r0, r2, #0
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #4
	ands r0, r1
	movs r3, #0xfa
	lsls r3, r3, #2
	adds r1, r4, r3
_080CC5D8:
	strh r0, [r1]
_080CC5DA:
	adds r3, r5, #0
	adds r3, #0x40
	ldrh r2, [r3]
	ldr r1, _080CC5F4 @ =0x000003E6
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	strh r1, [r3]
	ldrh r1, [r5, #6]
	movs r0, #4
	orrs r0, r1
	strh r0, [r5, #6]
	b _080CC60E
	.align 2, 0
_080CC5F4: .4byte 0x000003E6
_080CC5F8:
	ldr r2, _080CC614 @ =0x000003D2
	adds r0, r4, r2
	strb r7, [r0]
	adds r0, r3, #0
	adds r1, r5, #0
	bl FUN_080cc494
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r4, r3
_080CC60C:
	strb r0, [r1]
_080CC60E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CC614: .4byte 0x000003D2

	thumb_func_start FUN_080cc618
FUN_080cc618: @ 0x080CC618
	push {lr}
	ldr r0, _080CC628 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CC62C
	movs r1, #0
	b _080CC634
	.align 2, 0
_080CC628: .4byte 0x03002C68
_080CC62C:
	movs r1, #0xf4
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r1, [r0]
_080CC634:
	subs r0, r1, #4
	cmp r0, #1
	bls _080CC63E
	cmp r1, #0
	bne _080CC642
_080CC63E:
	movs r0, #1
	b _080CC644
_080CC642:
	movs r0, #0
_080CC644:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cc648
FUN_080cc648: @ 0x080CC648
	push {r4, r5, lr}
	adds r2, r0, #0
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r3, r2, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _080CC6A0
	ldr r5, _080CC680 @ =0x00000679
	adds r1, r2, r5
	ldrb r0, [r1]
	adds r4, r0, #1
	strb r4, [r1]
	lsls r0, r4, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080CC684
	movs r0, #0xca
	lsls r0, r0, #3
	adds r2, r2, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r3]
	b _080CC6A0
	.align 2, 0
_080CC680: .4byte 0x00000679
_080CC684:
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r3, _080CC6A8 @ =0x0000064C
	adds r1, r2, r3
	ldr r1, [r1]
	ldr r5, _080CC6AC @ =0x0000067A
	adds r3, r2, r5
	lsls r2, r4, #0x18
	lsrs r2, r2, #0x1a
	ldrb r3, [r3]
	adds r2, r2, r3
	bl FUN_0822dafc
_080CC6A0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CC6A8: .4byte 0x0000064C
_080CC6AC: .4byte 0x0000067A

	thumb_func_start FUN_080cc6b0
FUN_080cc6b0: @ 0x080CC6B0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r6, r1, #0
	movs r0, #0xca
	lsls r0, r0, #3
	adds r5, r4, r0
	cmp r2, #0
	beq _080CC6CC
	ldr r2, _080CC6C8 @ =0x0000067A
	adds r1, r4, r2
	movs r0, #0x48
	b _080CC6D2
	.align 2, 0
_080CC6C8: .4byte 0x0000067A
_080CC6CC:
	ldr r0, _080CC710 @ =0x0000067A
	adds r1, r4, r0
	movs r0, #4
_080CC6D2:
	strb r0, [r1]
	ldr r1, _080CC714 @ =0x0000064C
	adds r0, r4, r1
	ldr r1, [r0]
	ldr r2, _080CC710 @ =0x0000067A
	adds r0, r4, r2
	ldrb r2, [r0]
	adds r0, r5, #0
	bl FUN_0822dafc
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r5, #0x18]
	str r1, [r5, #0x1c]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080CC718 @ =0x00000679
	adds r0, r4, r1
	strb r2, [r0]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC710: .4byte 0x0000067A
_080CC714: .4byte 0x0000064C
_080CC718: .4byte 0x00000679

	thumb_func_start FUN_080cc71c
FUN_080cc71c: @ 0x080CC71C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080CC774 @ =0x00001C1C
	bl GetParticleGroup
	adds r1, r0, #0
	ldr r0, _080CC778 @ =0x0000064C
	adds r6, r5, r0
	str r1, [r6]
	adds r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r2, #0
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	movs r1, #0xcf
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _080CC77C @ =0x00000679
	adds r5, r5, r0
	strb r2, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC774: .4byte 0x00001C1C
_080CC778: .4byte 0x0000064C
_080CC77C: .4byte 0x00000679

	thumb_func_start FUN_080cc780
FUN_080cc780: @ 0x080CC780
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xd5
	lsls r0, r0, #3
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _080CC870
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	bne _080CC7A2
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080CC7B6
_080CC7A2:
	movs r4, #0xd0
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	strb r0, [r6]
	b _080CC8CC
_080CC7B6:
	ldr r1, _080CC7E4 @ =0x000006A9
	adds r0, r5, r1
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r3, r0, r1
	movs r1, #0xff
	ands r3, r1
	ldr r2, _080CC7E8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080CC7EC
	asrs r1, r0, #0xc
	b _080CC7F2
	.align 2, 0
_080CC7E4: .4byte 0x000006A9
_080CC7E8: .4byte 0x085B0A08
_080CC7EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CC7F2:
	ldrh r0, [r5, #0x2c]
	adds r0, r0, r1
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r1, r5, r4
	strh r0, [r1]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x46
	muls r0, r1, r0
	cmp r0, #0
	blt _080CC812
	asrs r0, r0, #0xc
	b _080CC818
_080CC812:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CC818:
	movs r1, #0xaf
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrh r4, [r5, #0x2e]
	adds r0, r0, r4
	ldr r4, _080CC848 @ =0x0000069A
	adds r1, r5, r4
	strh r0, [r1]
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #3
	subs r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080CC84C
	asrs r2, r0, #0xc
	b _080CC852
	.align 2, 0
_080CC848: .4byte 0x0000069A
_080CC84C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CC852:
	ldrh r0, [r5, #0x30]
	subs r0, r0, r2
	ldr r4, _080CC868 @ =0x0000069C
	adds r1, r5, r4
	strh r0, [r1]
	ldr r0, _080CC86C @ =0x000006A9
	adds r1, r5, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	b _080CC8CC
	.align 2, 0
_080CC868: .4byte 0x0000069C
_080CC86C: .4byte 0x000006A9
_080CC870:
	ldr r7, [r5, #0x1c]
	cmp r7, #1
	bne _080CC8CC
	movs r1, #0x88
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080CC8CC
	movs r4, #0xd3
	lsls r4, r4, #3
	adds r2, r5, r4
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldrh r0, [r2]
	adds r0, #0x38
	movs r4, #0
	strh r0, [r2]
	ldr r0, _080CC8D4 @ =0x0000069A
	adds r1, r5, r0
	movs r2, #0xaf
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r2, _080CC8D8 @ =0x0000067C
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0x10
	bl FUN_0822dafc
	ldr r1, _080CC8DC @ =0x000006A9
	adds r0, r5, r1
	strb r4, [r0]
	strb r7, [r6]
_080CC8CC:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CC8D4: .4byte 0x0000069A
_080CC8D8: .4byte 0x0000067C
_080CC8DC: .4byte 0x000006A9

	thumb_func_start FUN_080cc8e0
FUN_080cc8e0: @ 0x080CC8E0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _080CC938 @ =0x00001C1C
	bl GetParticleGroup
	adds r1, r0, #0
	ldr r0, _080CC93C @ =0x0000067C
	adds r6, r5, r0
	str r1, [r6]
	adds r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r6]
	adds r0, r4, #0
	movs r2, #0x10
	bl FUN_0822dafc
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r2, #0
	strb r1, [r4, #0xf]
	movs r0, #0x14
	strb r0, [r4, #0x10]
	movs r1, #0xd5
	lsls r1, r1, #3
	adds r0, r5, r1
	strb r2, [r0]
	ldr r0, _080CC940 @ =0x000006A9
	adds r5, r5, r0
	strb r2, [r5]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CC938: .4byte 0x00001C1C
_080CC93C: .4byte 0x0000067C
_080CC940: .4byte 0x000006A9

	thumb_func_start FUN_080cc944
FUN_080cc944: @ 0x080CC944
	push {r4, r5, lr}
	mov ip, r0
	adds r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CC952
	b _080CCA7A
_080CC952:
	mov r4, ip
	adds r4, #0x48
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	mov r2, ip
	ldr r1, [r2, #0x48]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
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
	beq _080CC986
	mov r1, ip
	ldr r0, [r1]
	movs r1, #4
	orrs r0, r1
	b _080CC990
_080CC986:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080CC990:
	mov r2, ip
	str r0, [r2]
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
	beq _080CC9B8
	mov r1, ip
	ldr r0, [r1]
	movs r1, #8
	orrs r0, r1
	b _080CC9C2
_080CC9B8:
	mov r1, ip
	ldr r0, [r1]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080CC9C2:
	mov r2, ip
	str r0, [r2]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080CC9FC @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080CCA42
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080CCA06
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080CCA00
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080CCA1C
	.align 2, 0
_080CC9FC: .4byte 0x0000FFFF
_080CCA00:
	subs r0, #1
	strh r0, [r4, #8]
	b _080CCA1A
_080CCA06:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080CCA1A
	strh r1, [r4, #8]
	movs r2, #1
	b _080CCA1C
_080CCA1A:
	movs r2, #0
_080CCA1C:
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
	bne _080CCA44
	movs r0, #1
	strb r0, [r4, #7]
	b _080CCA44
_080CCA42:
	movs r2, #0
_080CCA44:
	cmp r2, #0
	beq _080CCA5E
	mov r1, ip
	adds r1, #0x64
	movs r0, #0
	strb r0, [r1]
	mov r1, ip
	ldr r0, [r1]
	movs r1, #1
	orrs r0, r1
	mov r2, ip
	str r0, [r2]
	b _080CCA7A
_080CCA5E:
	mov r0, ip
	adds r0, #0x5c
	ldrh r0, [r0]
	mov r1, ip
	ldrh r1, [r1, #0x1c]
	adds r0, r0, r1
	mov r2, ip
	strh r0, [r2, #0x1c]
	mov r0, ip
	adds r0, #0x60
	ldrh r0, [r0]
	ldrh r1, [r2, #0x20]
	adds r0, r0, r1
	strh r0, [r2, #0x20]
_080CCA7A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cca80
FUN_080cca80: @ 0x080CCA80
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x64
	ldrb r0, [r1]
	cmp r0, #0
	beq _080CCA94
	movs r0, #0
	strb r0, [r1]
	b _080CCA9C
_080CCA94:
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
_080CCA9C:
	pop {r0}
	bx r0

	thumb_func_start FUN_080ccaa0
FUN_080ccaa0: @ 0x080CCAA0
	push {lr}
	adds r3, r0, #0
	movs r0, #3
	ands r0, r3
	cmp r0, #1
	beq _080CCABC
	cmp r0, #1
	bgt _080CCAB6
	cmp r0, #0
	beq _080CCABC
	b _080CCABA
_080CCAB6:
	cmp r0, #2
	beq _080CCABC
_080CCABA:
	movs r0, #1
_080CCABC:
	str r0, [r1]
	cmp r3, #2
	bhi _080CCAC6
	movs r0, #0
	b _080CCADA
_080CCAC6:
	subs r0, r3, #3
	cmp r0, #1
	bhi _080CCAD0
	movs r0, #2
	b _080CCADA
_080CCAD0:
	cmp r3, #5
	bne _080CCAD8
	movs r0, #3
	b _080CCADA
_080CCAD8:
	movs r0, #1
_080CCADA:
	str r0, [r2]
	pop {r0}
	bx r0

	thumb_func_start FUN_080ccae0
FUN_080ccae0: @ 0x080CCAE0
	adds r1, r0, #0
	adds r1, #0xc2
	ldrh r2, [r1]
	ldr r3, _080CCB14 @ =0x000006DE
	adds r1, r0, r3
	strh r2, [r1]
	ldr r1, _080CCB18 @ =0x000006E4
	adds r2, r0, r1
	adds r1, r0, #0
	adds r1, #0xd0
	ldr r1, [r1]
	str r1, [r2]
	ldr r1, _080CCB1C @ =0x000006AC
	adds r3, r0, r1
	ldr r1, [r3]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r3]
	movs r3, #0xe2
	lsls r3, r3, #3
	adds r0, r0, r3
	movs r1, #1
	strb r1, [r0]
	bx lr
	.align 2, 0
_080CCB14: .4byte 0x000006DE
_080CCB18: .4byte 0x000006E4
_080CCB1C: .4byte 0x000006AC

	thumb_func_start FUN_080ccb20
FUN_080ccb20: @ 0x080CCB20
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _080CCB6C @ =0x000006AC
	adds r3, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldrh r0, [r3, #0x1e]
	adds r0, #0xbe
	strh r0, [r3, #0x1e]
	ldr r2, _080CCB70 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080CCB74
	asrs r1, r0, #0xc
	b _080CCB7A
	.align 2, 0
_080CCB6C: .4byte 0x000006AC
_080CCB70: .4byte 0x085B0A08
_080CCB74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCB7A:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080CCB96
	asrs r1, r0, #0xc
	b _080CCB9C
_080CCB96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCB9C:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCBC0
	asrs r1, r0, #0xc
	b _080CCBC6
_080CCBC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCBC6:
	movs r7, #0xe1
	lsls r7, r7, #3
	adds r0, r4, r7
	strh r1, [r0]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCBE4
	asrs r2, r0, #0xc
	b _080CCBEA
_080CCBE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CCBEA:
	ldr r3, _080CCC28 @ =0x0000070C
	adds r0, r4, r3
	strh r2, [r0]
	add r2, sp, #8
	adds r0, r6, #0
	add r1, sp, #4
	bl FUN_080ccaa0
	ldr r7, _080CCC2C @ =0x000006F4
	adds r0, r4, r7
	ldr r2, _080CCC30 @ =0x00000704
	adds r1, r4, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	bl FUN_08236fac
	adds r0, r4, #0
	bl FUN_080ccae0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCC28: .4byte 0x0000070C
_080CCC2C: .4byte 0x000006F4
_080CCC30: .4byte 0x00000704

	thumb_func_start FUN_080ccc34
FUN_080ccc34: @ 0x080CCC34
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r5, r0, #0
	mov ip, r1
	ldr r0, _080CCC4C @ =0x000006AC
	adds r4, r5, r0
	cmp r3, #0
	bne _080CCC50
	movs r3, #0xa0
	movs r7, #0xe1
	lsls r7, r7, #1
	b _080CCC60
	.align 2, 0
_080CCC4C: .4byte 0x000006AC
_080CCC50:
	cmp r3, #1
	bne _080CCC5C
	movs r3, #0x8c
	movs r7, #0xa9
	lsls r7, r7, #1
	b _080CCC60
_080CCC5C:
	movs r3, #0x78
	movs r7, #0xe0
_080CCC60:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r6, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldrh r0, [r4, #0x1e]
	adds r0, r0, r3
	strh r0, [r4, #0x1e]
	ldr r2, _080CCC9C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r7, r0
	cmp r0, #0
	blt _080CCCA0
	asrs r1, r0, #0xc
	b _080CCCA6
	.align 2, 0
_080CCC9C: .4byte 0x085B0A08
_080CCCA0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCA6:
	ldrh r0, [r4, #0x1c]
	adds r0, r0, r1
	strh r0, [r4, #0x1c]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080CCCBE
	asrs r1, r0, #0xc
	b _080CCCC4
_080CCCBE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCC4:
	ldrh r0, [r4, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0x20]
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCCE8
	asrs r1, r0, #0xc
	b _080CCCEE
_080CCCE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCCEE:
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r5, r3
	strh r1, [r0]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCD0C
	asrs r2, r0, #0xc
	b _080CCD12
_080CCD0C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CCD12:
	ldr r3, _080CCD50 @ =0x0000070C
	adds r0, r5, r3
	strh r2, [r0]
	add r2, sp, #8
	mov r0, ip
	add r1, sp, #4
	bl FUN_080ccaa0
	ldr r1, _080CCD54 @ =0x000006F4
	adds r0, r5, r1
	ldr r2, _080CCD58 @ =0x00000704
	adds r1, r5, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #1
	bl FUN_08236fac
	adds r0, r5, #0
	bl FUN_080ccae0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCD50: .4byte 0x0000070C
_080CCD54: .4byte 0x000006F4
_080CCD58: .4byte 0x00000704

	thumb_func_start FUN_080ccd5c
FUN_080ccd5c: @ 0x080CCD5C
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080CCD9C @ =0x000006AC
	adds r3, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r2, _080CCDA0 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	blt _080CCDA4
	asrs r1, r0, #0xc
	b _080CCDAA
	.align 2, 0
_080CCD9C: .4byte 0x000006AC
_080CCDA0: .4byte 0x085B0A08
_080CCDA4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCDAA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	blt _080CCDC4
	asrs r1, r0, #0xc
	b _080CCDCA
_080CCDC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCDCA:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r3, #0x20]
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r4, r3
	strh r2, [r0]
	ldr r6, _080CCE04 @ =0x0000070C
	adds r0, r4, r6
	strh r2, [r0]
	ldr r1, _080CCE08 @ =0x000006F4
	adds r0, r4, r1
	subs r3, #4
	adds r1, r4, r3
	ldr r1, [r1]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl FUN_08236fac
	adds r0, r4, #0
	bl FUN_080ccae0
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CCE04: .4byte 0x0000070C
_080CCE08: .4byte 0x000006F4

	thumb_func_start FUN_080cce0c
FUN_080cce0c: @ 0x080CCE0C
	push {r4, lr}
	ldr r1, _080CCE50 @ =0x000006AC
	adds r4, r0, r1
	ldr r1, [r4]
	movs r3, #2
	rsbs r3, r3, #0
	ands r1, r3
	str r1, [r4]
	movs r1, #0xd9
	lsls r1, r1, #3
	adds r3, r0, r1
	ldr r1, [r2]
	ldr r2, [r2, #4]
	str r1, [r3]
	str r2, [r3, #4]
	ldr r3, _080CCE54 @ =0x000006CA
	adds r2, r0, r3
	ldrh r1, [r2]
	adds r1, #0xe6
	strh r1, [r2]
	ldr r2, _080CCE58 @ =0x00000A8A
	adds r1, r0, r2
	ldrh r2, [r1]
	subs r3, #0x18
	adds r1, r0, r3
	strb r2, [r1]
	movs r1, #0xe2
	lsls r1, r1, #3
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CCE50: .4byte 0x000006AC
_080CCE54: .4byte 0x000006CA
_080CCE58: .4byte 0x00000A8A

	thumb_func_start FUN_080cce5c
FUN_080cce5c: @ 0x080CCE5C
	push {lr}
	ldr r1, _080CCE6C @ =0x000006AC
	adds r0, r0, r1
	bl AuxSprite_Remove
	pop {r0}
	bx r0
	.align 2, 0
_080CCE6C: .4byte 0x000006AC

	thumb_func_start FUN_080cce70
FUN_080cce70: @ 0x080CCE70
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080CCEC4 @ =0x000006AC
	adds r4, r6, r0
	movs r1, #0xdb
	lsls r1, r1, #3
	adds r5, r6, r1
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #5
	bne _080CCED4
	ldr r1, _080CCEC8 @ =0x00002110
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #0x43
	bl AuxSprite_Add
	movs r0, #4
	strh r0, [r4, #0x10]
	adds r0, r5, #0
	movs r1, #0x32
	bl Video_SetAuxSpritePltt
	movs r0, #1
	strb r0, [r4, #7]
	movs r0, #0x7f
	strb r0, [r4, #9]
	strb r0, [r4, #8]
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r4, #0x1c]
	str r1, [r4, #0x20]
	ldr r0, _080CCECC @ =0x00000714
	adds r1, r6, r0
	ldr r0, _080CCED0 @ =FUN_080cca80
	b _080CCF02
	.align 2, 0
_080CCEC4: .4byte 0x000006AC
_080CCEC8: .4byte 0x00002110
_080CCECC: .4byte 0x00000714
_080CCED0: .4byte FUN_080cca80
_080CCED4:
	ldr r1, _080CCF14 @ =0x00008F5D
	adds r0, r5, #0
	bl Video_GetAuxSprite
	adds r0, r4, #0
	adds r1, r5, #0
	movs r2, #1
	bl AuxSprite_Add
	adds r0, r5, #0
	movs r1, #0x1d
	bl Video_SetAuxSpritePltt
	ldr r0, _080CCF18 @ =0x0000922E
	ldr r1, _080CCF1C @ =0x00000837
	bl GetFile
	ldr r2, _080CCF20 @ =0x00000704
	adds r1, r6, r2
	str r0, [r1]
	ldr r0, _080CCF24 @ =0x00000714
	adds r1, r6, r0
	ldr r0, _080CCF28 @ =FUN_080cc944
_080CCF02:
	str r0, [r1]
	movs r2, #0xe2
	lsls r2, r2, #3
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CCF14: .4byte 0x00008F5D
_080CCF18: .4byte 0x0000922E
_080CCF1C: .4byte 0x00000837
_080CCF20: .4byte 0x00000704
_080CCF24: .4byte 0x00000714
_080CCF28: .4byte FUN_080cc944

	thumb_func_start FUN_080ccf2c
FUN_080ccf2c: @ 0x080CCF2C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	ldr r1, _080CCF84 @ =0x0000071C
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CCFD4
	movs r2, #0
	mov r8, r2
	movs r7, #0
_080CCF44:
	movs r0, #0x34
	adds r1, r7, #0
	muls r1, r0, r1
	adds r0, r5, r1
	movs r2, #0xea
	lsls r2, r2, #3
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CCFC2
	subs r2, #0x30
	adds r0, r1, r2
	adds r3, r5, r0
	adds r4, r3, #0
	adds r1, r3, #0
	adds r1, #0x31
	ldrb r0, [r1]
	adds r2, r0, #1
	movs r6, #0
	strb r2, [r1]
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xb
	bls _080CCF88
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	adds r0, r3, #0
	adds r0, #0x30
	strb r6, [r0]
	b _080CCFC2
	.align 2, 0
_080CCF84: .4byte 0x0000071C
_080CCF88:
	lsls r0, r2, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _080CCFA6
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r3, #0
	adds r0, #0x32
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r3, #0
	bl FUN_0822dafc
_080CCFA6:
	ldrh r0, [r4, #0x28]
	ldrh r2, [r4, #0x18]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	ldrh r0, [r4, #0x2a]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r0, [r4, #0x2c]
	ldrh r2, [r4, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	movs r0, #1
	add r8, r0
_080CCFC2:
	adds r7, #1
	cmp r7, #5
	ble _080CCF44
	mov r1, r8
	cmp r1, #0
	bne _080CCFD4
	ldr r2, _080CCFE0 @ =0x0000071C
	adds r0, r5, r2
	strb r1, [r0]
_080CCFD4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCFE0: .4byte 0x0000071C

	thumb_func_start FUN_080ccfe4
FUN_080ccfe4: @ 0x080CCFE4
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	ldr r0, _080CD070 @ =0x0000071D
	adds r7, r5, r0
	ldrb r1, [r7]
	movs r0, #0x34
	adds r4, r1, #0
	muls r4, r0, r4
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r4, r1
	adds r4, r5, r4
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	lsls r3, r3, #1
	adds r3, #2
	adds r2, r4, #0
	adds r2, #0x32
	movs r0, #0
	mov sb, r0
	strb r3, [r2]
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	ldrb r2, [r2]
	adds r0, r4, #0
	bl FUN_0822dafc
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r4, #0x18]
	str r1, [r4, #0x1c]
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x28]
	str r1, [r4, #0x2c]
	adds r0, r4, #0
	adds r0, #0x31
	mov r1, sb
	strb r1, [r0]
	adds r4, #0x30
	movs r0, #1
	strb r0, [r4]
	ldr r2, _080CD074 @ =0x0000071C
	adds r5, r5, r2
	strb r0, [r5]
	ldrb r0, [r7]
	adds r0, #1
	strb r0, [r7]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #5
	bls _080CD064
	strb r1, [r7]
_080CD064:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD070: .4byte 0x0000071D
_080CD074: .4byte 0x0000071C

	thumb_func_start FUN_080cd078
FUN_080cd078: @ 0x080CD078
	push {r4, r5, lr}
	movs r1, #0xe4
	lsls r1, r1, #3
	adds r4, r0, r1
	movs r5, #5
_080CD082:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080CD082
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cd098
FUN_080cd098: @ 0x080CD098
	push {r4, r5, r6, r7, lr}
	movs r1, #0xe3
	lsls r1, r1, #3
	adds r5, r0, r1
	ldr r0, _080CD0EC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5]
	movs r6, #0
	movs r7, #4
	rsbs r7, r7, #0
_080CD0AE:
	movs r0, #0x34
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #8
	adds r4, r5, r4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl Particle_SetOffset
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r6, #1
	cmp r6, #5
	ble _080CD0AE
	movs r0, #0
	strb r0, [r5, #4]
	strb r0, [r5, #5]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD0EC: .4byte 0x00001C1E

	thumb_func_start FUN_080cd0f0
FUN_080cd0f0: @ 0x080CD0F0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	ldr r1, _080CD158 @ =0x0000085C
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD108
	b _080CD21A
_080CD108:
	movs r2, #0
	mov sb, r2
	movs r7, #0
	ldr r0, _080CD15C @ =0x085B0A08
	mov sl, r0
	movs r1, #0xff
	mov r8, r1
_080CD116:
	movs r0, #0x34
	muls r0, r7, r0
	movs r2, #0x86
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r4, r6, r0
	adds r2, r4, #0
	adds r2, #0x28
	ldrb r0, [r2]
	cmp r0, #0
	beq _080CD208
	adds r5, r4, #0
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _080CD138
	rsbs r0, r0, #0
_080CD138:
	cmp r0, #0xf
	bgt _080CD160
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	cmp r0, #0
	bge _080CD146
	rsbs r0, r0, #0
_080CD146:
	cmp r0, #0xf
	bgt _080CD160
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	movs r0, #0
	strb r0, [r2]
	b _080CD208
	.align 2, 0
_080CD158: .4byte 0x0000085C
_080CD15C: .4byte 0x085B0A08
_080CD160:
	movs r2, #0x2c
	ldrsh r0, [r4, r2]
	movs r2, #0x30
	ldrsh r1, [r4, r2]
	bl ArcTan2_8
	adds r3, r0, #0
	adds r1, r4, #0
	adds r1, #0x2a
	ldrb r0, [r1]
	mov ip, r0
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	mov r2, ip
	muls r2, r0, r2
	adds r0, r2, #0
	cmp r0, #0
	blt _080CD194
	asrs r2, r0, #0xc
	b _080CD19A
_080CD194:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CD19A:
	ldrh r0, [r4, #0x2c]
	subs r0, r0, r2
	strh r0, [r4, #0x2c]
	ldrb r1, [r1]
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sl
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080CD1B8
	asrs r1, r0, #0xc
	b _080CD1BE
_080CD1B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CD1BE:
	ldrh r0, [r4, #0x30]
	subs r0, r0, r1
	strh r0, [r4, #0x30]
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x18]
	ldr r2, _080CD228 @ =0x00000934
	adds r1, r6, r2
	ldrh r0, [r4, #0x30]
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	adds r1, r4, #0
	adds r1, #0x29
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	mov r1, r8
	ands r0, r1
	cmp r0, #4
	bne _080CD204
	subs r2, #0xdc
	adds r0, r6, r2
	ldr r1, [r0]
	adds r0, r4, #0
	adds r0, #0x2b
	ldrb r2, [r0]
	adds r2, #1
	adds r0, r5, #0
	bl FUN_0822dafc
_080CD204:
	movs r0, #1
	add sb, r0
_080CD208:
	adds r7, #1
	cmp r7, #3
	ble _080CD116
	mov r1, sb
	cmp r1, #0
	bne _080CD21A
	ldr r2, _080CD22C @ =0x0000085C
	adds r0, r6, r2
	strb r1, [r0]
_080CD21A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD228: .4byte 0x00000934
_080CD22C: .4byte 0x0000085C

	thumb_func_start FUN_080cd230
FUN_080cd230: @ 0x080CD230
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	mov sb, r1
	ldr r1, [r7, #0x18]
	ldr r0, _080CD24C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CD250
	movs r2, #0
	b _080CD258
	.align 2, 0
_080CD24C: .4byte 0x03002C68
_080CD250:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
	adds r2, r0, #0
_080CD258:
	ldr r0, _080CD2E8 @ =0x0000085E
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #2
	adds r0, r2, r0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x27
	bhi _080CD26E
	b _080CD39C
_080CD26E:
	ldr r1, _080CD2EC @ =0x0000085D
	adds r0, r7, r1
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r2, #0x86
	lsls r2, r2, #4
	adds r0, r0, r2
	adds r6, r7, r0
	mov r8, r6
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #2
	strb r0, [r1]
	ldr r3, _080CD2F0 @ =0x00000858
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, _080CD2F4 @ =0x0203B400
	mov ip, r0
	ldr r3, _080CD2F8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080CD2FC @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x3f
	ands r0, r1
	adds r2, r0, #0
	adds r2, #0x80
	ldr r1, _080CD300 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD304
	asrs r0, r0, #0xc
	b _080CD30A
	.align 2, 0
_080CD2E8: .4byte 0x0000085E
_080CD2EC: .4byte 0x0000085D
_080CD2F0: .4byte 0x00000858
_080CD2F4: .4byte 0x0203B400
_080CD2F8: .4byte 0x030046B8
_080CD2FC: .4byte 0x000003FF
_080CD300: .4byte 0x085B0A08
_080CD304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD30A:
	strh r0, [r6, #0x2c]
	ldr r0, _080CD320 @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD324
	asrs r0, r0, #0xc
	b _080CD32A
	.align 2, 0
_080CD320: .4byte 0x085B0A08
_080CD324:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD32A:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r2, r8
	str r0, [r2, #0x18]
	str r1, [r2, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r2, #0x18]
	adds r0, r0, r1
	strh r0, [r2, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r2, #0x1c]
	adds r0, r0, r2
	mov r1, r8
	strh r0, [r1, #0x1c]
	ldr r2, _080CD3A8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080CD3AC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080CD3B0 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	ands r0, r1
	adds r0, #0xe
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r2, #1
	strb r2, [r0]
	ldr r0, _080CD3B4 @ =0x0000085D
	adds r1, r7, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080CD38C
	strb r3, [r1]
_080CD38C:
	ldr r1, _080CD3B8 @ =0x0000085E
	adds r0, r7, r1
	ldrb r1, [r0]
	subs r1, #0x28
	strb r1, [r0]
	ldr r3, _080CD3BC @ =0x0000085C
	adds r0, r7, r3
	strb r2, [r0]
_080CD39C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD3A8: .4byte 0x030046B8
_080CD3AC: .4byte 0x000003FF
_080CD3B0: .4byte 0x0203B400
_080CD3B4: .4byte 0x0000085D
_080CD3B8: .4byte 0x0000085E
_080CD3BC: .4byte 0x0000085C

	thumb_func_start FUN_080cd3c0
FUN_080cd3c0: @ 0x080CD3C0
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov r8, r0
	mov sb, r1
	ldr r1, _080CD460 @ =0x0000085E
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	movs r1, #0xff
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	beq _080CD3E4
	b _080CD506
_080CD3E4:
	ldr r0, _080CD464 @ =0x0000085D
	add r0, r8
	ldrb r1, [r0]
	movs r0, #0x34
	muls r0, r1, r0
	movs r1, #0x86
	lsls r1, r1, #4
	adds r0, r0, r1
	mov r2, r8
	adds r6, r2, r0
	adds r7, r6, #0
	ldr r0, [r6]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6]
	adds r1, r6, #0
	adds r1, #0x2b
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080CD468 @ =0x00000858
	add r0, r8
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #4
	bl FUN_0822dafc
	ldr r3, _080CD46C @ =0x0203B400
	mov ip, r3
	ldr r3, _080CD470 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r2, _080CD474 @ =0x000003FF
	ands r0, r2
	lsls r1, r0, #1
	add r1, ip
	movs r5, #0xff
	ldrb r4, [r1]
	adds r0, #1
	ands r0, r2
	str r0, [r3]
	lsls r0, r0, #1
	add r0, ip
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r1, #0x81
	adds r2, r0, r1
	ldr r1, _080CD478 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD47C
	asrs r0, r0, #0xc
	b _080CD482
	.align 2, 0
_080CD460: .4byte 0x0000085E
_080CD464: .4byte 0x0000085D
_080CD468: .4byte 0x00000858
_080CD46C: .4byte 0x0203B400
_080CD470: .4byte 0x030046B8
_080CD474: .4byte 0x000003FF
_080CD478: .4byte 0x085B0A08
_080CD47C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD482:
	strh r0, [r6, #0x2c]
	ldr r0, _080CD498 @ =0x085B0A08
	lsls r1, r4, #1
	adds r1, r1, r0
	movs r3, #0
	ldrsh r0, [r1, r3]
	muls r0, r2, r0
	cmp r0, #0
	blt _080CD49C
	asrs r0, r0, #0xc
	b _080CD4A2
	.align 2, 0
_080CD498: .4byte 0x085B0A08
_080CD49C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CD4A2:
	movs r3, #0
	strh r0, [r6, #0x30]
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x18]
	str r1, [r7, #0x1c]
	ldrh r0, [r6, #0x2c]
	ldrh r1, [r7, #0x18]
	adds r0, r0, r1
	strh r0, [r7, #0x18]
	ldrh r0, [r6, #0x30]
	ldrh r2, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r7, #0x1c]
	ldr r2, _080CD514 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080CD518 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080CD51C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #7
	ands r0, r1
	adds r0, #0x1c
	adds r1, r6, #0
	adds r1, #0x2a
	strb r0, [r1]
	adds r0, r6, #0
	adds r0, #0x29
	strb r3, [r0]
	subs r0, #1
	movs r1, #1
	strb r1, [r0]
	ldr r0, _080CD520 @ =0x0000085C
	add r0, r8
	strb r1, [r0]
	ldr r1, _080CD524 @ =0x0000085D
	add r1, r8
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080CD506
	strb r3, [r1]
_080CD506:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD514: .4byte 0x030046B8
_080CD518: .4byte 0x000003FF
_080CD51C: .4byte 0x0203B400
_080CD520: .4byte 0x0000085C
_080CD524: .4byte 0x0000085D

	thumb_func_start FUN_080cd528
FUN_080cd528: @ 0x080CD528
	push {r4, r5, lr}
	movs r1, #0x86
	lsls r1, r1, #4
	adds r4, r0, r1
	movs r5, #3
_080CD532:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x34
	subs r5, #1
	cmp r5, #0
	bge _080CD532
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cd548
FUN_080cd548: @ 0x080CD548
	push {r4, r5, r6, r7, lr}
	ldr r1, _080CD598 @ =0x00000858
	adds r5, r0, r1
	ldr r0, _080CD59C @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r5]
	movs r6, #0
	movs r7, #4
	rsbs r7, r7, #0
_080CD55C:
	movs r0, #0x34
	adds r4, r6, #0
	muls r4, r0, r4
	adds r4, #8
	adds r4, r5, r4
	ldr r1, [r5]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	adds r0, r4, #0
	adds r1, r7, #0
	adds r2, r7, #0
	bl Particle_SetOffset
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	movs r0, #2
	strb r0, [r4, #0xf]
	adds r6, #1
	cmp r6, #3
	ble _080CD55C
	movs r0, #0
	strb r0, [r5, #5]
	strb r0, [r5, #6]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD598: .4byte 0x00000858
_080CD59C: .4byte 0x00001C1E

	thumb_func_start FUN_080cd5a0
FUN_080cd5a0: @ 0x080CD5A0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r2, _080CD5F8 @ =0x03003584
	ldr r1, _080CD5FC @ =0x0000094C
	adds r0, r3, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r1, r1, #1
	ldr r4, _080CD600 @ =0x00000938
	adds r0, r3, r4
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r6, r1, r0
	ldr r0, _080CD604 @ =0x0000094E
	adds r1, r3, r0
	ldrb r0, [r1]
	cmp r0, #0
	bne _080CD624
	ldr r1, _080CD608 @ =0x00000359
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD60C
	movs r5, #0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r1, r3, r2
_080CD5DE:
	subs r0, r5, #5
	cmp r0, #1
	bls _080CD5EC
	cmp r5, #0xd
	beq _080CD5EC
	ldrh r0, [r6]
	strh r0, [r1]
_080CD5EC:
	adds r6, #2
	adds r1, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080CD5DE
	b _080CD6E2
	.align 2, 0
_080CD5F8: .4byte 0x03003584
_080CD5FC: .4byte 0x0000094C
_080CD600: .4byte 0x00000938
_080CD604: .4byte 0x0000094E
_080CD608: .4byte 0x00000359
_080CD60C:
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r1, r3, r4
	movs r5, #0xf
_080CD614:
	ldrh r0, [r6]
	strh r0, [r1]
	adds r6, #2
	adds r1, #2
	subs r5, #1
	cmp r5, #0
	bge _080CD614
	b _080CD6E2
_080CD624:
	ldr r2, _080CD68C @ =0x00000359
	adds r0, r3, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD690
	movs r5, #0
	mov r8, r1
	movs r4, #0xa9
	lsls r4, r4, #2
	adds r7, r3, r4
_080CD638:
	subs r0, r5, #5
	cmp r0, #1
	bls _080CD680
	cmp r5, #0xd
	beq _080CD680
	ldrh r1, [r6]
	movs r0, #0x1f
	mov ip, r0
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _080CD658
	movs r4, #0x1f
_080CD658:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _080CD668
	movs r1, #0x1f
_080CD668:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080CD676
	movs r0, #0x1f
_080CD676:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
_080CD680:
	adds r6, #2
	adds r7, #2
	adds r5, #1
	cmp r5, #0xf
	ble _080CD638
	b _080CD6E2
	.align 2, 0
_080CD68C: .4byte 0x00000359
_080CD690:
	movs r4, #0x1f
	mov ip, r4
	mov r8, r1
	movs r0, #0xa9
	lsls r0, r0, #2
	adds r7, r3, r0
	movs r5, #0xf
_080CD69E:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	mov r3, r8
	ldrb r2, [r3]
	adds r4, r0, r2
	cmp r4, #0x1f
	ble _080CD6B0
	movs r4, #0x1f
_080CD6B0:
	lsls r3, r1, #0x10
	lsrs r0, r3, #0x15
	mov r1, ip
	ands r0, r1
	adds r1, r0, r2
	cmp r1, #0x1f
	ble _080CD6C0
	movs r1, #0x1f
_080CD6C0:
	lsrs r0, r3, #0x1a
	mov r3, ip
	ands r0, r3
	adds r0, r0, r2
	cmp r0, #0x1f
	ble _080CD6CE
	movs r0, #0x1f
_080CD6CE:
	lsls r0, r0, #0xa
	lsls r1, r1, #5
	orrs r0, r1
	orrs r0, r4
	strh r0, [r7]
	adds r6, #2
	adds r7, #2
	subs r5, #1
	cmp r5, #0
	bge _080CD69E
_080CD6E2:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cd6ec
FUN_080cd6ec: @ 0x080CD6EC
	push {r4, lr}
	adds r2, r0, #0
	movs r3, #0
	movs r1, #2
	ldr r0, _080CD708 @ =0x030046A0
	ldr r0, [r0]
	ldr r4, _080CD70C @ =0x00000934
	adds r0, r0, r4
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CD710
	movs r0, #1
	b _080CD712
	.align 2, 0
_080CD708: .4byte 0x030046A0
_080CD70C: .4byte 0x00000934
_080CD710:
	movs r0, #0
_080CD712:
	cmp r0, #0
	bne _080CD724
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CD730
	movs r3, #4
	b _080CD730
_080CD724:
	ldr r0, [r2, #0x20]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080CD730
	movs r3, #8
_080CD730:
	adds r0, r3, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cd738
FUN_080cd738: @ 0x080CD738
	push {r4, lr}
	ldr r1, _080CD774 @ =0x03003584
	ldr r2, [r1]
	movs r1, #0xa0
	lsls r1, r1, #3
	adds r2, r2, r1
	movs r3, #0x95
	lsls r3, r3, #4
	adds r1, r0, r3
	ldrb r3, [r1]
	lsls r1, r3, #1
	adds r1, r1, r3
	lsls r1, r1, #1
	adds r2, r2, r1
	ldrh r3, [r2]
	ldr r4, _080CD778 @ =0x000002AE
	adds r1, r0, r4
	strh r3, [r1]
	adds r2, #2
	ldrh r3, [r2]
	adds r4, #2
	adds r1, r0, r4
	strh r3, [r1]
	ldrh r1, [r2, #2]
	ldr r2, _080CD77C @ =0x000002BE
	adds r0, r0, r2
	strh r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CD774: .4byte 0x03003584
_080CD778: .4byte 0x000002AE
_080CD77C: .4byte 0x000002BE

	thumb_func_start FUN_080cd780
FUN_080cd780: @ 0x080CD780
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov sl, r0
	mov ip, r2
	mov sb, r3
	cmp r2, #0
	bne _080CD7C2
	ldr r0, _080CD7B0 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD7B4
	mov r1, sl
	adds r1, #0xd0
	movs r0, #0xa9
	lsls r0, r0, #2
	add r0, sl
	str r0, [r1]
	b _080CD942
	.align 2, 0
_080CD7B0: .4byte 0x00000359
_080CD7B4:
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xa9
	lsls r0, r0, #2
	b _080CD93E
_080CD7C2:
	mov r8, r1
	ldr r0, _080CD7F8 @ =0x00000359
	add r0, sl
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CD898
	movs r0, #0
	str r0, [sp]
	mov r1, sl
	adds r1, #0xd0
	str r1, [sp, #0xc]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
	ldr r2, _080CD7FC @ =0x0000094E
	add r2, sl
	str r2, [sp, #4]
_080CD7E4:
	ldr r0, [sp]
	subs r0, #5
	cmp r0, #1
	bls _080CD7F2
	ldr r3, [sp]
	cmp r3, #0xd
	bne _080CD800
_080CD7F2:
	ldrh r0, [r6]
	b _080CD87A
	.align 2, 0
_080CD7F8: .4byte 0x00000359
_080CD7FC: .4byte 0x0000094E
_080CD800:
	mov r4, r8
	ldrh r2, [r4]
	movs r7, #0x1f
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #4]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _080CD816
	movs r4, #0x1f
_080CD816:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _080CD824
	movs r2, #0x1f
_080CD824:
	lsrs r0, r3, #0x1a
	ands r0, r7
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _080CD830
	movs r5, #0x1f
_080CD830:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	adds r4, r7, #0
	mov r7, sb
	muls r7, r0, r7
	adds r0, r7, #0
	adds r4, r4, r0
	ldr r0, [sp, #0x34]
	asrs r4, r0
	mov r7, ip
	muls r7, r2, r7
	adds r2, r7, #0
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	ldr r0, [sp, #0x34]
	asrs r2, r0
	mov r0, ip
	muls r0, r5, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	ldr r7, [sp, #0x34]
	asrs r0, r7
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
_080CD87A:
	strh r0, [r6, #0x20]
	movs r0, #2
	add r8, r0
	adds r6, #2
	ldr r1, [sp]
	adds r1, #1
	str r1, [sp]
	cmp r1, #0xf
	ble _080CD7E4
	movs r0, #0xb1
	lsls r0, r0, #2
	add r0, sl
	ldr r2, [sp, #0xc]
	str r0, [r2]
	b _080CD942
_080CD898:
	movs r3, #0
	str r3, [sp]
	ldr r4, _080CD954 @ =0x0000094E
	add r4, sl
	str r4, [sp, #8]
	movs r6, #0xa9
	lsls r6, r6, #2
	add r6, sl
_080CD8A8:
	mov r7, r8
	ldrh r2, [r7]
	movs r0, #0x1f
	ands r0, r2
	ldr r3, [sp, #8]
	ldrb r1, [r3]
	adds r4, r0, r1
	cmp r4, #0x1f
	ble _080CD8BC
	movs r4, #0x1f
_080CD8BC:
	lsls r3, r2, #0x10
	lsrs r0, r3, #0x15
	movs r7, #0x1f
	ands r0, r7
	adds r2, r0, r1
	cmp r2, #0x1f
	ble _080CD8CC
	movs r2, #0x1f
_080CD8CC:
	lsrs r0, r3, #0x1a
	movs r3, #0x1f
	ands r0, r3
	adds r5, r0, r1
	cmp r5, #0x1f
	ble _080CD8DA
	movs r5, #0x1f
_080CD8DA:
	ldrh r1, [r6]
	movs r0, #0x1f
	ands r0, r1
	lsls r1, r1, #0x10
	lsrs r3, r1, #0x15
	movs r7, #0x1f
	ands r3, r7
	lsrs r1, r1, #0x1a
	ands r1, r7
	mov r7, ip
	muls r7, r4, r7
	mov r4, sb
	muls r4, r0, r4
	adds r0, r4, #0
	adds r4, r7, r0
	ldr r7, [sp, #0x34]
	asrs r4, r7
	mov r0, ip
	muls r0, r2, r0
	adds r2, r0, #0
	mov r0, sb
	muls r0, r3, r0
	adds r2, r2, r0
	asrs r2, r7
	mov r0, ip
	muls r0, r5, r0
	mov r3, sb
	muls r3, r1, r3
	adds r1, r3, #0
	adds r0, r0, r1
	asrs r0, r7
	lsls r0, r0, #0xa
	lsls r2, r2, #5
	orrs r0, r2
	orrs r0, r4
	strh r0, [r6, #0x20]
	movs r4, #2
	add r8, r4
	adds r6, #2
	ldr r7, [sp]
	adds r7, #1
	str r7, [sp]
	cmp r7, #0xf
	ble _080CD8A8
	movs r0, #0x8a
	lsls r0, r0, #1
	add r0, sl
	ldr r1, [r0]
	movs r0, #0xb1
	lsls r0, r0, #2
_080CD93E:
	add r0, sl
	str r0, [r1, #0xc]
_080CD942:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CD954: .4byte 0x0000094E

	thumb_func_start FUN_080cd958
FUN_080cd958: @ 0x080CD958
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	adds r4, r1, #0
	ldr r1, _080CD9E0 @ =0x00000951
	adds r0, r5, r1
	movs r2, #0x95
	lsls r2, r2, #4
	adds r1, r5, r2
	ldrb r0, [r0]
	ldrb r3, [r1]
	cmp r0, r3
	beq _080CD97A
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cd738
_080CD97A:
	adds r0, r5, #0
	bl FUN_080cd6ec
	adds r2, r0, #0
	ldr r6, _080CD9E4 @ =0x0000094C
	adds r1, r5, r6
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r0, r4
	bne _080CD998
	adds r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, r2
	beq _080CD9A6
_080CD998:
	strh r4, [r1]
	ldr r1, _080CD9E8 @ =0x0000094E
	adds r0, r5, r1
	strb r2, [r0]
	adds r0, r5, #0
	bl FUN_080cd5a0
_080CD9A6:
	movs r3, #0x96
	lsls r3, r3, #4
	adds r2, r5, r3
	ldrh r4, [r2]
	cmp r4, #0
	beq _080CD9B4
	b _080CDADE
_080CD9B4:
	adds r0, r5, #0
	bl FUN_080ced00
	cmp r0, #0
	blt _080CDA40
	ldr r6, _080CD9EC @ =0x00000121
	adds r0, r0, r6
	ldr r2, _080CD9F0 @ =0x00000962
	adds r1, r5, r2
	strh r0, [r1]
	ldr r2, _080CD9F4 @ =0x03003584
	ldrh r0, [r1]
	lsls r0, r0, #5
	ldr r1, [r2]
	adds r4, r1, r0
	ldr r3, _080CD9F8 @ =0x00000964
	adds r0, r5, r3
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080CD9FC
	adds r2, r1, #0
	b _080CDA12
	.align 2, 0
_080CD9E0: .4byte 0x00000951
_080CD9E4: .4byte 0x0000094C
_080CD9E8: .4byte 0x0000094E
_080CD9EC: .4byte 0x00000121
_080CD9F0: .4byte 0x00000962
_080CD9F4: .4byte 0x03003584
_080CD9F8: .4byte 0x00000964
_080CD9FC:
	cmp r1, #0x2f
	bhi _080CDA04
	movs r2, #0x20
	b _080CDA12
_080CDA04:
	cmp r1, #0x4f
	bhi _080CDA10
	ldrh r1, [r0]
	movs r0, #0x50
	subs r2, r0, r1
	b _080CDA12
_080CDA10:
	movs r2, #0
_080CDA12:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cd780
	ldr r6, _080CDA3C @ =0x00000964
	adds r1, r5, r6
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bhi _080CDA36
	b _080CDBA0
_080CDA36:
	movs r0, #0
	b _080CDB9E
	.align 2, 0
_080CDA3C: .4byte 0x00000964
_080CDA40:
	ldr r0, _080CDA7C @ =0x00000964
	adds r3, r5, r0
	ldrh r2, [r3]
	subs r0, r2, #1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4e
	bhi _080CDAAE
	ldr r1, _080CDA80 @ =0x03003584
	ldr r6, _080CDA84 @ =0x00000962
	adds r0, r5, r6
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r6, r1, r0
	adds r0, r2, #0
	subs r0, #0x21
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080CDA6E
	movs r0, #0x30
	strh r0, [r3]
_080CDA6E:
	ldrh r0, [r3]
	cmp r0, #0x20
	bhi _080CDA88
	adds r2, r0, #0
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDA9C
	.align 2, 0
_080CDA7C: .4byte 0x00000964
_080CDA80: .4byte 0x03003584
_080CDA84: .4byte 0x00000962
_080CDA88:
	ldrh r0, [r3]
	movs r1, #0x50
	subs r2, r1, r0
	adds r0, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x4f
	bls _080CDA9C
	strh r4, [r3]
_080CDA9C:
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_080cd780
	b _080CDBA0
_080CDAAE:
	strh r4, [r3]
	ldr r1, _080CDAC8 @ =0x00000359
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CDACC
	adds r1, r5, #0
	adds r1, #0xd0
	movs r2, #0xa9
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1]
	b _080CDBA0
	.align 2, 0
_080CDAC8: .4byte 0x00000359
_080CDACC:
	movs r3, #0x8a
	lsls r3, r3, #1
	adds r0, r5, r3
	ldr r1, [r0]
	movs r6, #0xa9
	lsls r6, r6, #2
	adds r0, r5, r6
	str r0, [r1, #0xc]
	b _080CDBA0
_080CDADE:
	ldr r1, _080CDB24 @ =0x00000964
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldrh r0, [r2]
	cmp r0, #0x1f
	bls _080CDB76
	ldr r1, _080CDB28 @ =0x03003584
	ldr r2, _080CDB2C @ =0x0000095E
	adds r0, r5, r2
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldr r3, _080CDB30 @ =0x00000359
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CDB4E
	movs r3, #0
	adds r6, r5, #0
	adds r6, #0xd0
	movs r0, #0xb1
	lsls r0, r0, #2
	adds r2, r5, r0
	subs r0, #0x20
	adds r4, r5, r0
_080CDB14:
	subs r0, r3, #5
	cmp r0, #1
	bls _080CDB1E
	cmp r3, #0xd
	bne _080CDB34
_080CDB1E:
	ldrh r0, [r4]
	b _080CDB36
	.align 2, 0
_080CDB24: .4byte 0x00000964
_080CDB28: .4byte 0x03003584
_080CDB2C: .4byte 0x0000095E
_080CDB30: .4byte 0x00000359
_080CDB34:
	ldrh r0, [r1]
_080CDB36:
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	adds r4, #2
	adds r3, #1
	cmp r3, #0xf
	ble _080CDB14
	movs r1, #0xb1
	lsls r1, r1, #2
	adds r0, r5, r1
	str r0, [r6]
	b _080CDB94
_080CDB4E:
	movs r3, #0xb1
	lsls r3, r3, #2
	adds r2, r5, r3
	movs r3, #0xf
_080CDB56:
	ldrh r0, [r1]
	strh r0, [r2]
	adds r1, #2
	adds r2, #2
	subs r3, #1
	cmp r3, #0
	bge _080CDB56
	movs r6, #0x8a
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r1, [r0]
	movs r2, #0xb1
	lsls r2, r2, #2
	adds r0, r5, r2
	str r0, [r1, #0xc]
	b _080CDB94
_080CDB76:
	ldr r1, _080CDBA8 @ =0x03003584
	ldr r3, _080CDBAC @ =0x0000095E
	adds r0, r5, r3
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r1, [r1]
	adds r1, r1, r0
	ldrh r2, [r2]
	movs r3, #0x20
	subs r3, r3, r2
	movs r0, #5
	str r0, [sp]
	adds r0, r5, #0
	bl FUN_080cd780
_080CDB94:
	movs r6, #0x96
	lsls r6, r6, #4
	adds r1, r5, r6
	ldrh r0, [r1]
	subs r0, #1
_080CDB9E:
	strh r0, [r1]
_080CDBA0:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CDBA8: .4byte 0x03003584
_080CDBAC: .4byte 0x0000095E

	thumb_func_start FUN_080cdbb0
FUN_080cdbb0: @ 0x080CDBB0
	ldr r1, [r0, #0x18]
	adds r1, #0x22
	ldr r3, _080CDBF4 @ =0x00000938
	adds r2, r0, r3
	strh r1, [r2]
	ldr r1, _080CDBF8 @ =0x0000093A
	adds r2, r0, r1
	ldr r1, _080CDBFC @ =0x00000121
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x20
	strh r1, [r2]
	ldr r1, _080CDC00 @ =0x0000093E
	adds r2, r0, r1
	ldr r1, _080CDC04 @ =0x00000123
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	adds r1, #1
	strh r1, [r2]
	ldr r1, _080CDC08 @ =0x00000942
	adds r2, r0, r1
	movs r1, #0x1f
	strh r1, [r2]
	adds r3, #4
	adds r2, r0, r3
	movs r1, #0x21
	strh r1, [r2]
	ldr r1, _080CDC0C @ =0x00000946
	adds r0, r0, r1
	movs r1, #0x1e
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CDBF4: .4byte 0x00000938
_080CDBF8: .4byte 0x0000093A
_080CDBFC: .4byte 0x00000121
_080CDC00: .4byte 0x0000093E
_080CDC04: .4byte 0x00000123
_080CDC08: .4byte 0x00000942
_080CDC0C: .4byte 0x00000946

	thumb_func_start FUN_080cdc10
FUN_080cdc10: @ 0x080CDC10
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080cdbb0
	ldr r0, _080CDC60 @ =0x0000094C
	adds r1, r4, r0
	ldr r0, _080CDC64 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0x95
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xff
	strb r0, [r1]
	ldr r1, _080CDC68 @ =0x00000938
	adds r5, r4, r1
	ldrh r0, [r5]
	adds r1, r4, #0
	adds r1, #0xc2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xd0
	movs r1, #0xa9
	lsls r1, r1, #2
	adds r3, r4, r1
	str r3, [r0]
	movs r0, #0x8a
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r1, [r2]
	ldrh r0, [r5]
	strh r0, [r1, #6]
	ldr r0, [r2]
	str r3, [r0, #0xc]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080cd958
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CDC60: .4byte 0x0000094C
_080CDC64: .4byte 0x0000FFFF
_080CDC68: .4byte 0x00000938

	thumb_func_start FUN_080cdc6c
FUN_080cdc6c: @ 0x080CDC6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	adds r7, r0, #0
	ldr r1, _080CDC90 @ =0x000004C5
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080CDC98
	ldr r2, _080CDC94 @ =0x000004C4
	adds r0, r7, r2
	bl SSEEmitter_FadeParticle
	b _080CDD7A
	.align 2, 0
_080CDC90: .4byte 0x000004C5
_080CDC94: .4byte 0x000004C4
_080CDC98:
	cmp r0, #2
	bne _080CDCA8
	ldr r0, [r7, #0x18]
	movs r1, #0x9a
	lsls r1, r1, #1
	bl FUN_080cc3e4
	b _080CDCB6
_080CDCA8:
	cmp r0, #3
	bne _080CDCB6
	ldr r0, [r7, #0x18]
	movs r1, #0x9a
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080CDCB6:
	ldr r1, _080CDD8C @ =0x000004CC
	adds r0, r7, r1
	ldr r3, [r0]
	ldrh r0, [r3]
	ldr r6, _080CDD90 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r6
	orrs r2, r0
	str r2, [sp, #0xc]
	ldrh r1, [r3, #2]
	adds r1, #0x80
	lsls r1, r1, #0x10
	ldr r0, _080CDD94 @ =0x0000FFFF
	mov r8, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	ldrh r1, [r3, #4]
	ldr r0, [sp, #0x10]
	ands r0, r6
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r5, _080CDD98 @ =0x0203B400
	ldr r1, _080CDD9C @ =0x030046B8
	mov sl, r1
	ldr r2, [r1]
	adds r2, #1
	ldr r4, _080CDDA0 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0xf
	mov sb, r1
	mov r1, sb
	ands r0, r1
	subs r0, #7
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, [sp, #0x14]
	ands r3, r6
	orrs r3, r0
	str r3, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	lsls r0, r2, #1
	adds r0, r0, r5
	ldrh r1, [r0]
	movs r0, #0x1f
	ands r1, r0
	subs r1, #0x10
	lsls r1, r1, #0x10
	mov r0, r8
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #0x14]
	adds r2, #1
	ands r2, r4
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	adds r2, r2, r5
	ldrh r1, [r2]
	mov r2, sb
	ands r1, r2
	subs r1, #7
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r6
	orrs r0, r1
	str r0, [r3, #4]
	ldr r0, [sp, #0x1c]
	ands r0, r6
	movs r2, #5
	orrs r0, r2
	mov r1, r8
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xc
	orrs r0, r1
	str r0, [sp, #0x1c]
	add r1, sp, #0x1c
	ldr r0, [r1, #4]
	ands r0, r6
	orrs r0, r2
	str r0, [r1, #4]
	ldr r2, _080CDDA4 @ =0x000004C4
	adds r0, r7, r2
	str r1, [sp]
	movs r1, #0x28
	str r1, [sp, #4]
	str r1, [sp, #8]
	movs r1, #3
	add r2, sp, #0xc
	bl SSEEmitter_BurstParticle
_080CDD7A:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CDD8C: .4byte 0x000004CC
_080CDD90: .4byte 0xFFFF0000
_080CDD94: .4byte 0x0000FFFF
_080CDD98: .4byte 0x0203B400
_080CDD9C: .4byte 0x030046B8
_080CDDA0: .4byte 0x000003FF
_080CDDA4: .4byte 0x000004C4

	thumb_func_start FUN_080cdda8
FUN_080cdda8: @ 0x080CDDA8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _080CDDCC @ =0x000004C7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CDDC4
	adds r4, r0, #0
_080CDDB8:
	adds r0, r5, #0
	bl FUN_080cdc6c
	subs r4, #1
	cmp r4, #0
	bne _080CDDB8
_080CDDC4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CDDCC: .4byte 0x000004C7

	thumb_func_start FUN_080cddd0
FUN_080cddd0: @ 0x080CDDD0
	adds r1, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r1, r2
	ldrb r0, [r0]
	adds r2, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	subs r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	bx lr
	.align 2, 0

	thumb_func_start FUN_080cddf0
FUN_080cddf0: @ 0x080CDDF0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r1, #0
	mov r8, r5
	ldr r0, _080CDE44 @ =0x000004C7
	adds r7, r4, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CDE5E
	adds r0, r4, #0
	bl FUN_080cddd0
	ldr r2, _080CDE48 @ =0x085AD148
	ldr r1, _080CDE4C @ =0x000004C5
	adds r6, r4, r1
	ldrb r1, [r6]
	subs r1, #1
	adds r1, r1, r2
	ldrb r1, [r1]
	cmp r0, r1
	blt _080CDE32
	adds r0, r4, #0
	bl FUN_080cdc6c
	movs r2, #0x80
	lsls r2, r2, #3
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, #1
	adds r0, r4, r2
	strb r1, [r0]
_080CDE32:
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CDE5E
	ldrb r0, [r6]
	cmp r0, #1
	bne _080CDE50
	movs r5, #3
	b _080CDE5E
	.align 2, 0
_080CDE44: .4byte 0x000004C7
_080CDE48: .4byte 0x085AD148
_080CDE4C: .4byte 0x000004C5
_080CDE50:
	cmp r0, #2
	bne _080CDE58
	movs r5, #4
	b _080CDE5E
_080CDE58:
	cmp r0, #3
	bne _080CDE5E
	movs r5, #5
_080CDE5E:
	cmp r5, r8
	bne _080CDE8C
	ldr r0, _080CDE84 @ =0x00000954
	adds r3, r4, r0
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080CDE9A
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDE7E
	ldr r1, _080CDE88 @ =0x00000952
	adds r0, r4, r1
	ldrh r5, [r0]
_080CDE7E:
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDE9A
	.align 2, 0
_080CDE84: .4byte 0x00000954
_080CDE88: .4byte 0x00000952
_080CDE8C:
	ldr r2, _080CDEA8 @ =0x00000952
	adds r0, r4, r2
	strh r5, [r0]
	ldr r0, _080CDEAC @ =0x00000954
	adds r1, r4, r0
	movs r0, #0x40
	strh r0, [r1]
_080CDE9A:
	adds r0, r5, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CDEA8: .4byte 0x00000952
_080CDEAC: .4byte 0x00000954

	thumb_func_start FUN_080cdeb0
FUN_080cdeb0: @ 0x080CDEB0
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r6, r1, #0
	movs r5, #0
_080CDEBA:
	cmp r5, #1
	beq _080CDECE
	cmp r5, #1
	bgt _080CDEC8
	cmp r5, #0
	beq _080CDF1C
	b _080CDFBC
_080CDEC8:
	cmp r5, #2
	beq _080CDF8C
	b _080CDFBC
_080CDECE:
	ldr r0, _080CDEF0 @ =0x0000043E
	adds r2, r4, r0
	ldrh r1, [r2]
	cmp r1, #0
	beq _080CDEF8
	ldr r0, [r4, #0x1c]
	ands r0, r5
	cmp r0, #0
	beq _080CDEE4
	subs r0, r1, #1
	strh r0, [r2]
_080CDEE4:
	movs r6, #2
	ldr r2, _080CDEF4 @ =0x00000956
	adds r1, r4, r2
	movs r0, #0x40
	strh r0, [r1]
	b _080CDFBC
	.align 2, 0
_080CDEF0: .4byte 0x0000043E
_080CDEF4: .4byte 0x00000956
_080CDEF8:
	ldr r7, _080CDF18 @ =0x00000956
	adds r3, r4, r7
	ldrh r2, [r3]
	lsls r0, r2, #0x10
	cmp r0, #0
	beq _080CDFBC
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDF10
	movs r6, #2
_080CDF10:
	subs r0, r2, #1
	strh r0, [r3]
	b _080CDFBC
	.align 2, 0
_080CDF18: .4byte 0x00000956
_080CDF1C:
	ldr r0, _080CDF40 @ =0x0000043C
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080CDFBC
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	subs r0, r2, #1
	strh r0, [r3]
	ldr r0, _080CDF44 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CDF48
	subs r1, #2
	b _080CDF4C
	.align 2, 0
_080CDF40: .4byte 0x0000043C
_080CDF44: .4byte 0x03002C68
_080CDF48:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080CDF4C:
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bne _080CDFBC
	movs r7, #0xa3
	lsls r7, r7, #2
	adds r0, r4, r7
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	movs r1, #0x98
	lsls r1, r1, #4
	adds r0, r4, r1
	str r0, [sp]
	ldr r2, _080CDF84 @ =0x00000984
	adds r0, r4, r2
	str r0, [sp, #4]
	movs r0, #2
	movs r1, #1
	movs r2, #0x1e
	ldr r7, _080CDF88 @ =0x0000097C
	adds r3, r4, r7
	bl MosaicFader_Start
	b _080CDFBC
	.align 2, 0
_080CDF84: .4byte 0x00000984
_080CDF88: .4byte 0x0000097C
_080CDF8C:
	movs r0, #0x88
	lsls r0, r0, #3
	adds r3, r4, r0
	ldrh r2, [r3]
	cmp r2, #0
	beq _080CDFBC
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CDFBC
	subs r0, r2, #1
	strh r0, [r3]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CDFBC
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080CDFD0 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
_080CDFBC:
	adds r5, #1
	cmp r5, #2
	bgt _080CDFC4
	b _080CDEBA
_080CDFC4:
	adds r0, r6, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CDFD0: .4byte 0x00000456

	thumb_func_start FUN_080cdfd4
FUN_080cdfd4: @ 0x080CDFD4
	push {lr}
	adds r3, r0, #0
	adds r2, r1, #0
	ldr r0, _080CDFF8 @ =0x0000095C
	adds r1, r3, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080CDFF4
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x12
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080CDFFC
_080CDFF4:
	adds r0, r2, #0
	b _080CE002
	.align 2, 0
_080CDFF8: .4byte 0x0000095C
_080CDFFC:
	ldr r1, _080CE008 @ =0x0000095A
	adds r0, r3, r1
	ldrh r0, [r0]
_080CE002:
	pop {r1}
	bx r1
	.align 2, 0
_080CE008: .4byte 0x0000095A

	thumb_func_start FUN_080ce00c
FUN_080ce00c: @ 0x080CE00C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	ldr r1, _080CE084 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	mov r8, r0
	cmp r0, #0
	bne _080CE022
	b _080CE1C4
_080CE022:
	ldr r2, _080CE088 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080CE094
	ldr r3, _080CE08C @ =0x0000097A
	adds r5, r4, r3
	ldrh r0, [r5]
	cmp r0, #0x3f
	bhi _080CE052
	cmp r0, #0
	bne _080CE04C
	ldr r0, [r4, #0x18]
	movs r1, #0xf7
	lsls r1, r1, #1
	bl FUN_080cc3e4
	ldr r0, _080CE090 @ =0x000003F1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080CE04C:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080CE052:
	adds r2, r4, #0
	adds r2, #0x90
	ldr r0, [r2]
	movs r1, #2
	orrs r0, r1
	str r0, [r2]
	ldr r1, _080CE08C @ =0x0000097A
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r1, #0xa0
	lsls r1, r1, #0xb
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	adds r5, r2, #0
	b _080CE0FE
	.align 2, 0
_080CE084: .4byte 0x00000446
_080CE088: .4byte 0x00000442
_080CE08C: .4byte 0x0000097A
_080CE090: .4byte 0x000003F1
_080CE094:
	ldr r2, _080CE0D8 @ =0x0000097A
	adds r6, r4, r2
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080CE0FE
	ldr r3, _080CE0DC @ =0x000003F1
	adds r7, r4, r3
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CE0B8
	ldr r0, [r4, #0x18]
	ldr r1, _080CE0E0 @ =0x00000336
	bl FUN_080cc3e4
	movs r0, #0
	strb r0, [r7]
_080CE0B8:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CE0E4
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080CE0F8
	.align 2, 0
_080CE0D8: .4byte 0x0000097A
_080CE0DC: .4byte 0x000003F1
_080CE0E0: .4byte 0x00000336
_080CE0E4:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080CE0F8:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080CE0FE:
	ldr r1, _080CE118 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _080CE192
	ldr r0, _080CE11C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CE120
	movs r2, #1
	rsbs r2, r2, #0
	b _080CE124
	.align 2, 0
_080CE118: .4byte 0x00000442
_080CE11C: .4byte 0x03002C68
_080CE120:
	movs r3, #0x18
	ldrsh r2, [r0, r3]
_080CE124:
	ldr r0, [r4, #0x18]
	cmp r0, r2
	bne _080CE136
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	b _080CE17C
_080CE136:
	ldr r1, _080CE168 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	ldr r2, _080CE16C @ =0x00000446
	adds r0, r1, r2
	ldrh r0, [r0]
	movs r2, #0
	cmp r0, #0
	beq _080CE156
	ldr r3, _080CE170 @ =0x00000442
	adds r0, r1, r3
	ldrh r0, [r0]
	cmp r0, #4
	bne _080CE156
	movs r2, #1
_080CE156:
	cmp r2, #0
	beq _080CE174
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #2
	b _080CE17C
	.align 2, 0
_080CE168: .4byte 0x03002BE0
_080CE16C: .4byte 0x00000446
_080CE170: .4byte 0x00000442
_080CE174:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	movs r2, #1
_080CE17C:
	orrs r0, r2
	str r0, [r1]
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	b _080CE1A4
_080CE192:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r0, [r1]
	ldr r2, _080CE1BC @ =0xFFFFFDFF
	ands r0, r2
	str r0, [r1]
	ldr r0, [r5]
	ands r0, r2
	str r0, [r5]
_080CE1A4:
	ldr r0, [r4, #0x1c]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080CE256
	ldr r0, _080CE1C0 @ =0x00000446
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	b _080CE256
	.align 2, 0
_080CE1BC: .4byte 0xFFFFFDFF
_080CE1C0: .4byte 0x00000446
_080CE1C4:
	ldr r1, _080CE208 @ =0x0000097A
	adds r6, r4, r1
	ldrh r0, [r6]
	adds r5, r4, #0
	adds r5, #0x90
	cmp r0, #0
	beq _080CE22E
	ldr r2, _080CE20C @ =0x000003F1
	adds r7, r4, r2
	ldrb r0, [r7]
	cmp r0, #0
	beq _080CE1E8
	ldr r0, [r4, #0x18]
	ldr r1, _080CE210 @ =0x00000336
	bl FUN_080cc3e4
	mov r3, r8
	strb r3, [r7]
_080CE1E8:
	ldrh r0, [r6]
	subs r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080CE214
	ldr r0, [r5]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #0x40
	b _080CE228
	.align 2, 0
_080CE208: .4byte 0x0000097A
_080CE20C: .4byte 0x000003F1
_080CE210: .4byte 0x00000336
_080CE214:
	ldr r0, [r5]
	movs r1, #2
	orrs r0, r1
	str r0, [r5]
	ldrh r0, [r6]
	lsrs r0, r0, #1
	movs r1, #0x40
	subs r1, r1, r0
	adds r0, r4, #0
	adds r0, #0xbc
_080CE228:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
_080CE22E:
	ldr r1, [r5]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r1, #0
	ands r0, r2
	cmp r0, #0
	beq _080CE242
	ldr r0, _080CE260 @ =0xFFFFFDFF
	ands r1, r0
	str r1, [r5]
_080CE242:
	adds r1, r4, #0
	adds r1, #0xe8
	ldr r3, [r1]
	adds r0, r3, #0
	ands r0, r2
	cmp r0, #0
	beq _080CE256
	ldr r0, _080CE260 @ =0xFFFFFDFF
	ands r3, r0
	str r3, [r1]
_080CE256:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CE260: .4byte 0xFFFFFDFF

	thumb_func_start FUN_080ce264
FUN_080ce264: @ 0x080CE264
	push {lr}
	adds r2, r0, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0xf0
	ands r0, r1
	cmp r0, #0
	beq _080CE286
	movs r0, #0x80
	lsls r0, r0, #3
	adds r1, r2, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_080CE286:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ce28c
FUN_080ce28c: @ 0x080CE28C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ce00c
	adds r0, r4, #0
	bl FUN_080ce264
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080cdeb0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cddf0
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cdfd4
	adds r1, r0, #0
	adds r0, r4, #0
	bl FUN_080cd958
	adds r0, r4, #0
	bl FUN_080cc648
	adds r0, r4, #0
	bl FUN_080cc780
	adds r0, r4, #0
	bl FUN_080ccf2c
	adds r0, r4, #0
	bl FUN_080cd0f0
	ldr r0, _080CE318 @ =0x00000714
	adds r1, r4, r0
	ldr r2, _080CE31C @ =0x000006AC
	adds r0, r4, r2
	ldr r1, [r1]
	bl _call_via_r1
	ldr r1, _080CE320 @ =0x00000604
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2c]
	adds r0, r0, r2
	ldr r2, _080CE324 @ =0x000005FC
	adds r1, r4, r2
	strh r0, [r1]
	ldr r1, _080CE328 @ =0x00000606
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2e]
	adds r0, r0, r2
	ldr r2, _080CE32C @ =0x000005FE
	adds r1, r4, r2
	strh r0, [r1]
	movs r1, #0xc1
	lsls r1, r1, #3
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x30]
	adds r0, r0, r2
	subs r1, #8
	adds r4, r4, r1
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CE318: .4byte 0x00000714
_080CE31C: .4byte 0x000006AC
_080CE320: .4byte 0x00000604
_080CE324: .4byte 0x000005FC
_080CE328: .4byte 0x00000606
_080CE32C: .4byte 0x000005FE

	thumb_func_start FUN_080ce330
FUN_080ce330: @ 0x080CE330
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080CE370 @ =0x000004C4
	adds r0, r4, r1
	bl SSEEmitter_Destroy
	ldr r1, _080CE374 @ =0x0000060C
	adds r0, r4, r1
	bl ParticleShadow_Remove
	movs r1, #0xca
	lsls r1, r1, #3
	adds r0, r4, r1
	bl Particle_Remove
	movs r1, #0xd0
	lsls r1, r1, #3
	adds r0, r4, r1
	bl Particle_Remove
	adds r0, r4, #0
	bl FUN_080cd078
	adds r0, r4, #0
	bl FUN_080cd528
	adds r0, r4, #0
	bl FUN_080cce5c
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CE370: .4byte 0x000004C4
_080CE374: .4byte 0x0000060C

	thumb_func_start FUN_080ce378
FUN_080ce378: @ 0x080CE378
	push {r4, r5, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _080CE440 @ =0x000004C4
	adds r0, r5, r1
	adds r4, r5, #0
	adds r4, #0xa8
	movs r1, #1
	str r1, [sp]
	adds r1, r4, #0
	movs r2, #0
	movs r3, #0
	bl SSEEmitter_Init
	ldr r2, _080CE444 @ =0x000005FC
	adds r1, r5, r2
	ldr r2, [r4]
	ldr r3, [r4, #4]
	str r2, [r1]
	str r3, [r1, #4]
	ldr r3, _080CE448 @ =0x00000604
	adds r0, r5, r3
	movs r4, #0
	movs r2, #0
	strh r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r2, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r2, [r0]
	ldr r2, _080CE44C @ =0x0000060C
	adds r0, r5, r2
	movs r2, #0
	bl ParticleShadow_Init
	bl FUN_080dc44c
	adds r0, r5, #0
	bl FUN_080cdc10
	adds r0, r5, #0
	bl FUN_080cc71c
	adds r0, r5, #0
	bl FUN_080cc8e0
	adds r0, r5, #0
	bl FUN_080cd098
	adds r0, r5, #0
	bl FUN_080cd548
	adds r0, r5, #0
	bl FUN_080cce70
	ldr r3, _080CE450 @ =0x0000097C
	adds r0, r5, r3
	movs r1, #4
	strb r1, [r0]
	ldr r2, _080CE454 @ =0x0000097D
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r1, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strb r4, [r0]
	adds r2, #2
	adds r0, r5, r2
	strb r4, [r0]
	adds r3, #2
	adds r0, r5, r3
	strh r1, [r0]
	adds r2, #3
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	adds r2, #4
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _080CE458 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CE45C
	subs r1, #5
	b _080CE460
	.align 2, 0
_080CE440: .4byte 0x000004C4
_080CE444: .4byte 0x000005FC
_080CE448: .4byte 0x00000604
_080CE44C: .4byte 0x0000060C
_080CE450: .4byte 0x0000097C
_080CE454: .4byte 0x0000097D
_080CE458: .4byte 0x03002C68
_080CE45C:
	movs r3, #0x18
	ldrsh r1, [r0, r3]
_080CE460:
	ldr r0, [r5, #0x18]
	cmp r0, r1
	bne _080CE474
	ldr r0, _080CE470 @ =0x00000978
	adds r1, r5, r0
	movs r0, #0
	b _080CE47A
	.align 2, 0
_080CE470: .4byte 0x00000978
_080CE474:
	ldr r2, _080CE4B4 @ =0x00000978
	adds r1, r5, r2
	movs r0, #1
_080CE47A:
	strb r0, [r1]
	movs r3, #0x97
	lsls r3, r3, #4
	adds r0, r5, r3
	movs r1, #0
	strh r1, [r0]
	ldr r2, _080CE4B8 @ =0x00000972
	adds r0, r5, r2
	strh r1, [r0]
	adds r3, #4
	adds r0, r5, r3
	strh r1, [r0]
	ldr r0, _080CE4BC @ =0x03002BAC
	strh r1, [r0]
	ldr r0, _080CE4C0 @ =0x03002B90
	strh r1, [r0]
	ldr r2, _080CE4C4 @ =0x03002B84
	movs r0, #1
	strh r0, [r2]
	ldr r0, _080CE4C8 @ =0x03002BF0
	strh r1, [r0]
	ldr r0, _080CE4CC @ =0x000003FF
	adds r1, r5, r0
	movs r0, #0xff
	strb r0, [r1]
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CE4B4: .4byte 0x00000978
_080CE4B8: .4byte 0x00000972
_080CE4BC: .4byte 0x03002BAC
_080CE4C0: .4byte 0x03002B90
_080CE4C4: .4byte 0x03002B84
_080CE4C8: .4byte 0x03002BF0
_080CE4CC: .4byte 0x000003FF

	thumb_func_start FUN_080ce4d0
FUN_080ce4d0: @ 0x080CE4D0
	push {lr}
	ldr r1, [r0, #0x18]
	ldr r0, _080CE4E0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CE4E4
	movs r0, #0
	b _080CE4EA
	.align 2, 0
_080CE4E0: .4byte 0x03002C68
_080CE4E4:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080CE4EA:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ce4f0
FUN_080ce4f0: @ 0x080CE4F0
	push {lr}
	bl FUN_080cc618
	cmp r0, #0
	bne _080CE4FE
	movs r0, #0
	b _080CE500
_080CE4FE:
	movs r0, #0xa
_080CE500:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ce504
FUN_080ce504: @ 0x080CE504
	push {lr}
	movs r0, #0x80
	ldr r1, [r2, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #3
	ands r0, r1
	cmp r0, #0
	bne _080CE538
	movs r0, #0x80
	lsls r0, r0, #4
	ands r1, r0
	cmp r1, #0
	beq _080CE53C
_080CE538:
	movs r0, #0xa
	b _080CE53E
_080CE53C:
	movs r0, #0
_080CE53E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ce544
FUN_080ce544: @ 0x080CE544
	push {lr}
	adds r2, r0, #0
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080CE554
	movs r2, #0
	b _080CE576
_080CE554:
	movs r0, #2
	ands r0, r2
	cmp r0, #0
	beq _080CE560
	movs r2, #1
	b _080CE576
_080CE560:
	movs r0, #4
	ands r0, r2
	cmp r0, #0
	beq _080CE56C
	movs r2, #2
	b _080CE576
_080CE56C:
	movs r0, #8
	ands r0, r2
	cmp r0, #0
	beq _080CE596
	movs r2, #3
_080CE576:
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	beq _080CE596
	ldr r1, _080CE59C @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _080CE596
	ldr r0, [r1, #0x1c]
	cmp r0, #1
	bne _080CE596
	adds r0, r1, #0
	bl FUN_08064058
_080CE596:
	pop {r0}
	bx r0
	.align 2, 0
_080CE59C: .4byte 0x03002BE0

	thumb_func_start FUN_080ce5a0
FUN_080ce5a0: @ 0x080CE5A0
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r6, r1, #0
	movs r1, #0
	ldr r2, _080CE5EC @ =0x00000A9C
	adds r0, r3, r2
	movs r5, #2
_080CE5AE:
	str r1, [r0]
	str r1, [r0, #0xc]
	str r1, [r0, #0x18]
	adds r0, #4
	subs r5, #1
	cmp r5, #0
	bge _080CE5AE
	movs r1, #0xde
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0x10
	rsbs r2, r2, #0
	ldr r1, [r0]
	ands r1, r2
	str r1, [r0]
	movs r5, #0
	adds r4, r0, #0
_080CE5D0:
	lsls r0, r5, #2
	adds r1, r6, r0
	ldrb r1, [r1, #0x18]
	subs r1, #1
	adds r2, r0, #0
	cmp r1, #0x1e
	bls _080CE5E0
	b _080CE858
_080CE5E0:
	lsls r0, r1, #2
	ldr r1, _080CE5F0 @ =_080CE5F4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CE5EC: .4byte 0x00000A9C
_080CE5F0: .4byte _080CE5F4
_080CE5F4: @ jump table
	.4byte _080CE670 @ case 0
	.4byte _080CE698 @ case 1
	.4byte _080CE710 @ case 2
	.4byte _080CE724 @ case 3
	.4byte _080CE858 @ case 4
	.4byte _080CE858 @ case 5
	.4byte _080CE858 @ case 6
	.4byte _080CE6C0 @ case 7
	.4byte _080CE6D4 @ case 8
	.4byte _080CE6AC @ case 9
	.4byte _080CE6FC @ case 10
	.4byte _080CE6E8 @ case 11
	.4byte _080CE684 @ case 12
	.4byte _080CE670 @ case 13
	.4byte _080CE698 @ case 14
	.4byte _080CE74C @ case 15
	.4byte _080CE738 @ case 16
	.4byte _080CE7C4 @ case 17
	.4byte _080CE7D8 @ case 18
	.4byte _080CE7EC @ case 19
	.4byte _080CE800 @ case 20
	.4byte _080CE760 @ case 21
	.4byte _080CE774 @ case 22
	.4byte _080CE788 @ case 23
	.4byte _080CE79C @ case 24
	.4byte _080CE7B0 @ case 25
	.4byte _080CE814 @ case 26
	.4byte _080CE828 @ case 27
	.4byte _080CE850 @ case 28
	.4byte _080CE846 @ case 29
	.4byte _080CE83C @ case 30
_080CE670:
	ldr r1, _080CE67C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE680 @ =FUN_080ce4d0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE67C: .4byte 0x00000A9C
_080CE680: .4byte FUN_080ce4d0
_080CE684:
	ldr r1, _080CE690 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE694 @ =Player_WeaponEffectStatCond
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE690: .4byte 0x00000A9C
_080CE694: .4byte Player_WeaponEffectStatCond
_080CE698:
	ldr r1, _080CE6A4 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6A8 @ =FUN_080ce4f0
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6A4: .4byte 0x00000A9C
_080CE6A8: .4byte FUN_080ce4f0
_080CE6AC:
	ldr r1, _080CE6B8 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6BC @ =Player_WeaponEffectAgility
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6B8: .4byte 0x00000A9C
_080CE6BC: .4byte Player_WeaponEffectAgility
_080CE6C0:
	ldr r1, _080CE6CC @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6D0 @ =Player_WeaponEffectVitality
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6CC: .4byte 0x00000A9C
_080CE6D0: .4byte Player_WeaponEffectVitality
_080CE6D4:
	ldr r1, _080CE6E0 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6E4 @ =Player_WeaponEffectSpirit
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6E0: .4byte 0x00000A9C
_080CE6E4: .4byte Player_WeaponEffectSpirit
_080CE6E8:
	ldr r1, _080CE6F4 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE6F8 @ =Player_WeaponEffectENE
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE6F4: .4byte 0x00000A9C
_080CE6F8: .4byte Player_WeaponEffectENE
_080CE6FC:
	ldr r1, _080CE708 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE70C @ =Player_WeaponEffectHP
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE708: .4byte 0x00000A9C
_080CE70C: .4byte Player_WeaponEffectHP
_080CE710:
	ldr r1, _080CE71C @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE720 @ =Player_WeaponEffectKajiba
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE71C: .4byte 0x00000A9C
_080CE720: .4byte Player_WeaponEffectKajiba
_080CE724:
	ldr r1, _080CE730 @ =0x00000A9C
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE734 @ =Player_WeaponEffectGyakuKajiba
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE730: .4byte 0x00000A9C
_080CE734: .4byte Player_WeaponEffectGyakuKajiba
_080CE738:
	ldr r1, _080CE744 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE748 @ =FUN_080ce504
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE744: .4byte 0x00000AB4
_080CE748: .4byte FUN_080ce504
_080CE74C:
	ldr r1, _080CE758 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE75C @ =Player_WeaponEffectRandom
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE758: .4byte 0x00000AB4
_080CE75C: .4byte Player_WeaponEffectRandom
_080CE760:
	ldr r1, _080CE76C @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE770 @ =Player_WeaponEffectAntiBeast
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE76C: .4byte 0x00000AB4
_080CE770: .4byte Player_WeaponEffectAntiBeast
_080CE774:
	ldr r1, _080CE780 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE784 @ =Player_WeaponEffectAntiThing
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE780: .4byte 0x00000AB4
_080CE784: .4byte Player_WeaponEffectAntiThing
_080CE788:
	ldr r1, _080CE794 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE798 @ =Player_WeaponEffectAntiPhantom
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE794: .4byte 0x00000AB4
_080CE798: .4byte Player_WeaponEffectAntiPhantom
_080CE79C:
	ldr r1, _080CE7A8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7AC @ =Player_WeaponEffectAntiUndead
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7A8: .4byte 0x00000AB4
_080CE7AC: .4byte Player_WeaponEffectAntiUndead
_080CE7B0:
	ldr r1, _080CE7BC @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7C0 @ =Player_WeaponEffectAntiImmortal
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7BC: .4byte 0x00000AB4
_080CE7C0: .4byte Player_WeaponEffectAntiImmortal
_080CE7C4:
	ldr r1, _080CE7D0 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7D4 @ =Player_WeaponEffectFlame
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7D0: .4byte 0x00000AB4
_080CE7D4: .4byte Player_WeaponEffectFlame
_080CE7D8:
	ldr r1, _080CE7E4 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7E8 @ =Player_WeaponEffectFrost
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7E4: .4byte 0x00000AB4
_080CE7E8: .4byte Player_WeaponEffectFrost
_080CE7EC:
	ldr r1, _080CE7F8 @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE7FC @ =Player_WeaponEffectCloud
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE7F8: .4byte 0x00000AB4
_080CE7FC: .4byte Player_WeaponEffectCloud
_080CE800:
	ldr r1, _080CE80C @ =0x00000AB4
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE810 @ =Player_WeaponEffectEarth
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE80C: .4byte 0x00000AB4
_080CE810: .4byte Player_WeaponEffectEarth
_080CE814:
	ldr r1, _080CE820 @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE824 @ =CheckNamakuraProc
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE820: .4byte 0x00000AA8
_080CE824: .4byte CheckNamakuraProc
_080CE828:
	ldr r1, _080CE834 @ =0x00000AA8
	adds r0, r3, r1
	adds r0, r0, r2
	ldr r1, _080CE838 @ =CheckParalyzeProc
	str r1, [r0]
	b _080CE858
	.align 2, 0
_080CE834: .4byte 0x00000AA8
_080CE838: .4byte CheckParalyzeProc
_080CE83C:
	movs r1, #2
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	b _080CE856
_080CE846:
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r4]
	ands r0, r1
	b _080CE856
_080CE850:
	movs r1, #4
	ldr r0, [r4]
	orrs r0, r1
_080CE856:
	str r0, [r4]
_080CE858:
	adds r5, #1
	cmp r5, #2
	bgt _080CE860
	b _080CE5D0
_080CE860:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080ce868
FUN_080ce868: @ 0x080CE868
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r6, r4, r0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080CE8FC
	ldr r2, _080CE8EC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0xaa
	orrs r0, r3
	ldr r1, _080CE8F0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	ldr r0, _080CE8F4 @ =0xFFEC0000
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	ldr r2, _080CE8F8 @ =0x00002101
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	movs r0, #2
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0x32
	movs r3, #0x10
	bl Hitbox_SetAttack
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	b _080CEA82
	.align 2, 0
_080CE8EC: .4byte 0xFFFF0000
_080CE8F0: .4byte 0x0000FFFF
_080CE8F4: .4byte 0xFFEC0000
_080CE8F8: .4byte 0x00002101
_080CE8FC:
	ldr r1, _080CE914 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080CE908
	b _080CEA82
_080CE908:
	lsls r0, r0, #2
	ldr r1, _080CE918 @ =_080CE91C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080CE914: .4byte 0x00000A75
_080CE918: .4byte _080CE91C
_080CE91C: @ jump table
	.4byte _080CE930 @ case 0
	.4byte _080CE968 @ case 1
	.4byte _080CE99C @ case 2
	.4byte _080CE9D0 @ case 3
	.4byte _080CEA08 @ case 4
_080CE930:
	movs r3, #0
	movs r2, #0x5a
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x32
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CE95C @ =0x0000FFE7
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #1
	ldr r3, _080CE960 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _080CE964 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x14
	b _080CEA32
	.align 2, 0
_080CE95C: .4byte 0x0000FFE7
_080CE960: .4byte 0x00000A7C
_080CE964: .4byte 0x00000A7E
_080CE968:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	strh r3, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #2
	ldr r3, _080CE994 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x40
	strh r0, [r1]
	ldr r0, _080CE998 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x28
	b _080CEA32
	.align 2, 0
_080CE994: .4byte 0x00000A7C
_080CE998: .4byte 0x00000A7E
_080CE99C:
	movs r3, #0
	movs r2, #0x50
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x46
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	movs r0, #0x1e
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #4
	ldr r3, _080CE9C8 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x30
	strh r0, [r1]
	ldr r0, _080CE9CC @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x28
	b _080CEA32
	.align 2, 0
_080CE9C8: .4byte 0x00000A7C
_080CE9CC: .4byte 0x00000A7E
_080CE9D0:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x64
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CE9FC @ =0x0000FFB0
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #8
	ldr r3, _080CEA00 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #1
	strh r0, [r1]
	ldr r0, _080CEA04 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x14
	b _080CEA32
	.align 2, 0
_080CE9FC: .4byte 0x0000FFB0
_080CEA00: .4byte 0x00000A7C
_080CEA04: .4byte 0x00000A7E
_080CEA08:
	movs r3, #0
	movs r2, #0x3c
	add r0, sp, #0xc
	strh r2, [r0]
	adds r1, r0, #0
	movs r0, #0x32
	strh r0, [r1, #2]
	strh r2, [r1, #4]
	add r2, sp, #0x14
	strh r3, [r2]
	ldr r0, _080CEA8C @ =0x0000FFE7
	strh r0, [r2, #2]
	strh r3, [r2, #4]
	movs r5, #0x10
	ldr r3, _080CEA90 @ =0x00000A7C
	adds r1, r4, r3
	movs r0, #0x20
	strh r0, [r1]
	ldr r0, _080CEA94 @ =0x00000A7E
	adds r1, r4, r0
	movs r0, #0x1e
_080CEA32:
	strh r0, [r1]
	adds r3, r2, #0
	ldr r2, _080CEA98 @ =0x00002101
	adds r1, r4, #0
	adds r1, #0x28
	movs r0, #0x80
	lsls r0, r0, #9
	ldrb r1, [r1]
	lsls r0, r1
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r1, sp, #0xc
	str r1, [sp, #4]
	str r3, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r2, _080CEA9C @ =0x00000A7A
	adds r0, r4, r2
	ldrh r1, [r0]
	ldr r3, _080CEA90 @ =0x00000A7C
	adds r0, r4, r3
	ldrh r2, [r0]
	movs r0, #0
	str r0, [sp]
	adds r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r3, r5, #0
	bl Hitbox_SetAttack
	ldr r1, _080CEAA0 @ =FUN_080d1b68
	adds r0, r6, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
_080CEA82:
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CEA8C: .4byte 0x0000FFE7
_080CEA90: .4byte 0x00000A7C
_080CEA94: .4byte 0x00000A7E
_080CEA98: .4byte 0x00002101
_080CEA9C: .4byte 0x00000A7A
_080CEAA0: .4byte FUN_080d1b68

	thumb_func_start FUN_080ceaa4
FUN_080ceaa4: @ 0x080CEAA4
	push {r4, lr}
	adds r2, r0, #0
	adds r4, r1, #0
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r2, r2, r1
	ldrh r1, [r2]
	adds r1, #0x63
	asrs r1, r1, #1
	ldrb r2, [r4, #1]
	cmp r2, #3
	beq _080CEADC
	cmp r2, #3
	ble _080CEAC6
	cmp r2, #4
	beq _080CEAE0
	b _080CEAF6
_080CEAC6:
	cmp r2, #0
	blt _080CEAF6
	ldrb r0, [r4, #4]
	adds r0, r1, r0
	movs r2, #8
	ldrsh r1, [r4, r2]
	adds r0, r0, r1
	cmp r0, #0
	bgt _080CEAF6
	movs r0, #1
	b _080CEAF6
_080CEADC:
	adds r0, r1, #0
	b _080CEAF6
_080CEAE0:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	adds r1, r0, #0
	subs r1, #8
	lsls r0, r1, #2
	adds r0, r0, r1
	ldrb r4, [r4, #4]
	adds r0, r0, r4
	lsls r0, r0, #1
_080CEAF6:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start player_weapon_080ceafc
player_weapon_080ceafc: @ 0x080CEAFC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	adds r4, r1, #0
	ldrb r0, [r4]
	ldr r1, _080CEB58 @ =0x00000A74
	adds r5, r7, r1
	movs r2, #0
	mov r8, r2
	strb r0, [r5]
	ldrb r0, [r4, #1]
	adds r1, #1
	adds r6, r7, r1
	strb r0, [r6]
	ldrb r1, [r4, #4]
	ldr r2, _080CEB5C @ =0x00000A78
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r1, [r4, #8]
	adds r2, #0x1e
	adds r0, r7, r2
	strh r1, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080ceaa4
	ldr r2, _080CEB60 @ =0x00000A7A
	adds r1, r7, r2
	strh r0, [r1]
	ldr r1, _080CEB64 @ =0x00000A7C
	adds r0, r7, r1
	mov r2, r8
	strh r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl FUN_080ce5a0
	ldrb r0, [r5]
	cmp r0, #0x3d
	bne _080CEB70
	ldr r0, _080CEB68 @ =0x00000A98
	adds r1, r7, r0
	ldr r0, _080CEB6C @ =FUN_080d3b14
	str r0, [r1]
	b _080CEB80
	.align 2, 0
_080CEB58: .4byte 0x00000A74
_080CEB5C: .4byte 0x00000A78
_080CEB60: .4byte 0x00000A7A
_080CEB64: .4byte 0x00000A7C
_080CEB68: .4byte 0x00000A98
_080CEB6C: .4byte FUN_080d3b14
_080CEB70:
	ldr r1, _080CEB90 @ =0x00000A98
	adds r2, r7, r1
	ldr r1, _080CEB94 @ =0x085AD14C
	ldrb r0, [r6]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r0, [r0]
	str r0, [r2]
_080CEB80:
	adds r0, r7, #0
	bl FUN_080ce868
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CEB90: .4byte 0x00000A98
_080CEB94: .4byte 0x085AD14C

	thumb_func_start FUN_080ceb98
FUN_080ceb98: @ 0x080CEB98
	ldr r1, _080CEBA4 @ =0x085AD160
	lsls r0, r0, #1
	adds r0, r0, r1
	ldrh r0, [r0]
	bx lr
	.align 2, 0
_080CEBA4: .4byte 0x085AD160

	thumb_func_start FUN_080ceba8
FUN_080ceba8: @ 0x080CEBA8
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	bge _080CEBBE
	movs r0, #0
	b _080CEBF0
_080CEBBE:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_080ceb98
	adds r2, r0, #0
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #5
	bgt _080CEBEE
	movs r1, #2
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CEBEE
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #4
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
_080CEBEE:
	adds r0, r2, #0
_080CEBF0:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cebf8
FUN_080cebf8: @ 0x080CEBF8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ceba8
	movs r1, #0xda
	lsls r1, r1, #2
	adds r4, r4, r1
	ldrh r1, [r4]
	cmp r1, r0
	bge _080CEC10
	movs r0, #0
	b _080CEC12
_080CEC10:
	movs r0, #1
_080CEC12:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cec18
FUN_080cec18: @ 0x080CEC18
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ceba8
	adds r2, r0, #0
	movs r0, #0xda
	lsls r0, r0, #2
	adds r4, r4, r0
	ldrh r3, [r4]
	cmp r3, r2
	bge _080CEC4C
	ldr r0, _080CEC48 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _080CEC42
	movs r2, #0xa0
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r0, [r1]
	adds r0, r0, r3
	str r0, [r1]
_080CEC42:
	movs r0, #0
	b _080CEC64
	.align 2, 0
_080CEC48: .4byte 0x03002C68
_080CEC4C:
	ldr r0, _080CEC6C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	beq _080CEC60
	movs r3, #0xa0
	lsls r3, r3, #1
	adds r1, r0, r3
	ldr r0, [r1]
	adds r0, r0, r2
	str r0, [r1]
_080CEC60:
	ldrh r0, [r4]
	subs r0, r0, r2
_080CEC64:
	strh r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CEC6C: .4byte 0x03002C68

	thumb_func_start FUN_080cec70
FUN_080cec70: @ 0x080CEC70
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	cmp r4, #0
	blt _080CECA0
	adds r0, r4, #0
	bl GetMagicCategory
	adds r2, r0, #0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r1, r5, r3
	ldrb r1, [r1]
	cmp r1, #0
	bne _080CECA4
	cmp r2, #0
	bne _080CEC98
	cmp r4, #1
	beq _080CECA0
	b _080CECF4
_080CEC98:
	cmp r2, #1
	beq _080CECF4
	cmp r2, #2
	bne _080CECFA
_080CECA0:
	movs r0, #0
	b _080CECFA
_080CECA4:
	cmp r1, #1
	bne _080CECE8
	cmp r2, #0
	bne _080CECC2
	cmp r4, #0
	beq _080CECA0
	cmp r4, #2
	beq _080CECA0
	cmp r4, #3
	beq _080CECA0
	cmp r4, #4
	beq _080CECA0
	cmp r4, #5
	beq _080CECA0
	b _080CECF4
_080CECC2:
	cmp r2, #1
	beq _080CECA0
	cmp r2, #2
	bne _080CECFA
	cmp r4, #0xe
	bne _080CECF4
	ldr r0, _080CECE0 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080CECE4 @ =0x00000252
	adds r0, r0, r1
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	bge _080CECA0
	b _080CECF4
	.align 2, 0
_080CECE0: .4byte 0x030046A0
_080CECE4: .4byte 0x00000252
_080CECE8:
	cmp r1, #5
	beq _080CECF4
	cmp r1, #3
	bne _080CECF8
	cmp r4, #0x10
	bne _080CECA0
_080CECF4:
	movs r0, #1
	b _080CECFA
_080CECF8:
	movs r0, #0
_080CECFA:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080ced00
FUN_080ced00: @ 0x080CED00
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080CED3C @ =0x00000283
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CED44
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #5
	bgt _080CED44
	adds r0, r4, #0
	bl FUN_080cebf8
	cmp r0, #0
	beq _080CED44
	ldr r1, _080CED40 @ =0x00000A75
	adds r0, r4, r1
	ldrb r0, [r0]
	subs r0, #3
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080CED44
	movs r0, #0
	ldrsb r0, [r5, r0]
	b _080CED48
	.align 2, 0
_080CED3C: .4byte 0x00000283
_080CED40: .4byte 0x00000A75
_080CED44:
	movs r0, #1
	rsbs r0, r0, #0
_080CED48:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ced50
FUN_080ced50: @ 0x080CED50
	push {lr}
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r0, [r0]
	cmp r0, r1
	blt _080CED62
	movs r0, #1
	b _080CED64
_080CED62:
	movs r0, #0
_080CED64:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ced68
FUN_080ced68: @ 0x080CED68
	push {lr}
	ldr r2, [r0, #0x18]
	ldr r0, _080CED78 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CED7C
	movs r0, #0
	b _080CED82
	.align 2, 0
_080CED78: .4byte 0x03002C68
_080CED7C:
	adds r0, #0x60
	adds r0, r0, r2
	ldrb r0, [r0]
_080CED82:
	cmp r0, r1
	blt _080CED8A
	movs r0, #1
	b _080CED8C
_080CED8A:
	movs r0, #0
_080CED8C:
	pop {r1}
	bx r1

	thumb_func_start FUN_080ced90
FUN_080ced90: @ 0x080CED90
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0
	ldrsb r1, [r4, r1]
	cmp r1, #0
	bge _080CEDAE
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	b _080CEEB6
_080CEDAE:
	ldrb r0, [r4, #2]
	cmp r0, #0
	bne _080CEDBE
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	b _080CEEB6
_080CEDBE:
	cmp r1, #5
	bgt _080CEE10
	ldrb r0, [r4, #3]
	cmp r0, #0
	beq _080CEDD8
	movs r1, #0
	strb r1, [r4, #3]
	ldr r2, _080CEDD4 @ =0x00000951
	adds r0, r6, r2
	strb r1, [r0]
	b _080CEDFE
	.align 2, 0
_080CEDD4: .4byte 0x00000951
_080CEDD8:
	movs r5, #1
	strb r5, [r4, #3]
	adds r0, r6, #0
	bl FUN_080ced00
	cmp r0, #0
	blt _080CEDFE
	ldr r1, _080CEE08 @ =0x00000979
	adds r0, r6, r1
	strb r5, [r0]
	ldr r2, _080CEE0C @ =0x00000964
	adds r1, r6, r2
	movs r0, #0x20
	strh r0, [r1]
	ldrb r0, [r4]
	adds r0, #1
	subs r2, #0x13
	adds r1, r6, r2
	strb r0, [r1]
_080CEDFE:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	b _080CEEB6
	.align 2, 0
_080CEE08: .4byte 0x00000979
_080CEE0C: .4byte 0x00000964
_080CEE10:
	cmp r1, #0x10
	bne _080CEE72
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r4, r6, r2
	ldrb r0, [r4]
	cmp r0, #1
	bhi _080CEEB6
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080CEE6E
	adds r0, r6, #0
	bl FUN_080cebf8
	cmp r0, #0
	beq _080CEEB4
	movs r2, #0x8a
	lsls r2, r2, #1
	adds r0, r6, r2
	adds r2, #0x20
	adds r1, r6, r2
	str r1, [r0]
	adds r5, r6, #0
	adds r5, #0xe8
	adds r0, r5, #0
	bl FUN_0822a4fc
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r1, r6, r2
	ldr r1, [r1]
	movs r4, #0
	str r4, [sp]
	movs r2, #0
	movs r3, #0
	bl FUN_08237040
	str r4, [r5]
	adds r0, r6, #0
	bl FUN_080cec18
_080CEE6E:
	movs r0, #0xd
	b _080CEEB6
_080CEE72:
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r4, r6, r0
	ldrb r0, [r4]
	cmp r0, #1
	bhi _080CEEB6
	cmp r1, #8
	bne _080CEE96
	adds r0, r6, #0
	bl FUN_080cebf8
	cmp r0, #0
	beq _080CEEB4
	adds r0, r6, #0
	bl FUN_080cec18
	movs r0, #2
	b _080CEEB6
_080CEE96:
	cmp r1, #0xb
	bne _080CEE9E
	movs r0, #2
	b _080CEEB6
_080CEE9E:
	cmp r1, #0xd
	bne _080CEEB4
	ldr r1, _080CEEB0 @ =0x000003FB
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CEEB4
	movs r0, #0x11
	b _080CEEB6
	.align 2, 0
_080CEEB0: .4byte 0x000003FB
_080CEEB4:
	ldrb r0, [r4]
_080CEEB6:
	add sp, #4
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080ceec0
FUN_080ceec0: @ 0x080CEEC0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r0, #0xa0
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	adds r0, #0x42
	ldrb r0, [r0]
	movs r6, #0
	strb r0, [r4]
	lsls r0, r0, #0x18
	cmp r0, #0
	bge _080CEEEA
	movs r0, #0xff
	strb r0, [r4, #1]
	strb r6, [r4, #4]
	strb r6, [r4, #2]
	b _080CEF0A
_080CEEEA:
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl GetMagicCategory
	strb r0, [r4, #1]
	movs r0, #0
	ldrsb r0, [r4, r0]
	bl FUN_080ceb98
	strb r0, [r4, #4]
	movs r1, #0
	ldrsb r1, [r4, r1]
	adds r0, r5, #0
	bl FUN_080cec70
	strb r0, [r4, #2]
_080CEF0A:
	strb r6, [r4, #3]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cef14
FUN_080cef14: @ 0x080CEF14
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080CEF26
	bl Script_GetValue
_080CEF26:
	str r0, [r4, #0x18]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cef30
FUN_080cef30: @ 0x080CEF30
	push {lr}
	ldr r1, [r0, #0x18]
	ldr r0, _080CEF44 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _080CEF40
	cmp r1, #0
	bge _080CEF48
_080CEF40:
	movs r0, #0
	b _080CEF56
	.align 2, 0
_080CEF44: .4byte 0x03002C68
_080CEF48:
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r2, r0
_080CEF56:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080cef5c
FUN_080cef5c: @ 0x080CEF5C
	push {r4, lr}
	adds r3, r0, #0
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r3, r2
	ldr r1, [r1]
	adds r1, #0x40
	ldrb r2, [r1]
	cmp r2, #1
	beq _080CEF8A
	cmp r2, #1
	bgt _080CEF7A
	cmp r2, #0
	beq _080CEF80
	b _080CEFAC
_080CEF7A:
	cmp r2, #2
	beq _080CEF94
	b _080CEFAC
_080CEF80:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r1, r3, r4
	strb r2, [r1]
	b _080CEFB6
_080CEF8A:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r1, r3, r4
	strb r2, [r1]
	b _080CEFB6
_080CEF94:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r2, r3, r4
	movs r1, #5
	strb r1, [r2]
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r3, r1
	ldr r1, _080CEFA8 @ =FUN_080d6ea0
	b _080CEFBE
	.align 2, 0
_080CEFA8: .4byte FUN_080d6ea0
_080CEFAC:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r2, r3, r4
	movs r1, #0
	strb r1, [r2]
_080CEFB6:
	movs r1, #0xac
	lsls r1, r1, #4
	adds r2, r3, r1
	ldr r1, _080CEFC8 @ =FUN_080d6b24
_080CEFBE:
	str r1, [r2]
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080CEFC8: .4byte FUN_080d6b24

	thumb_func_start FUN_080cefcc
FUN_080cefcc: @ 0x080CEFCC
	push {r4, lr}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	adds r0, #0x41
	ldrb r0, [r0]
	add r2, sp, #8
	add r3, sp, #0xc
	add r1, sp, #0x10
	str r1, [sp]
	add r1, sp, #4
	bl FUN_081dfa20
	ldr r1, [sp, #8]
	movs r2, #0xd7
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [sp, #0xc]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r1, [sp, #4]
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, [sp, #0x10]
	ldr r1, _080CF018 @ =0x00000362
	adds r4, r4, r1
	strh r0, [r4]
	add sp, #0x14
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF018: .4byte 0x00000362

	thumb_func_start FUN_080cf01c
FUN_080cf01c: @ 0x080CF01C
	movs r2, #0xd7
	lsls r2, r2, #2
	adds r1, r0, r2
	ldrh r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	lsls r1, r1, #1
	ldr r3, _080CF03C @ =0x00000366
	adds r2, r0, r3
	strh r1, [r2]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CF03C: .4byte 0x00000366

	thumb_func_start FUN_080cf040
FUN_080cf040: @ 0x080CF040
	ldr r2, _080CF05C @ =0x0000035E
	adds r1, r0, r2
	ldrh r2, [r1]
	lsls r1, r2, #2
	adds r1, r1, r2
	adds r1, #0x64
	ldr r3, _080CF060 @ =0x0000036A
	adds r2, r0, r3
	strh r1, [r2]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	strh r1, [r0]
	bx lr
	.align 2, 0
_080CF05C: .4byte 0x0000035E
_080CF060: .4byte 0x0000036A

	thumb_func_start FUN_080cf064
FUN_080cf064: @ 0x080CF064
	push {r4, lr}
	adds r3, r0, #0
	movs r0, #0xa3
	lsls r0, r0, #2
	adds r2, r3, r0
	ldr r0, [r3, #0x18]
	lsls r0, r0, #3
	ldr r1, _080CF0A8 @ =0x030044E0
	adds r0, r0, r1
	str r0, [r2]
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r3, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080CF0AC @ =0x00000456
	adds r0, r3, r2
	strb r1, [r0]
	ldr r0, _080CF0B0 @ =0x0000FFFF
	adds r4, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r2, r3, r1
	movs r1, #9
_080CF094:
	ldrh r0, [r2]
	orrs r0, r4
	strh r0, [r2]
	adds r2, #2
	subs r1, #1
	cmp r1, #0
	bge _080CF094
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF0A8: .4byte 0x030044E0
_080CF0AC: .4byte 0x00000456
_080CF0B0: .4byte 0x0000FFFF

	thumb_func_start FUN_080cf0b4
FUN_080cf0b4: @ 0x080CF0B4
	push {r4, r5, lr}
	adds r4, r0, #0
	bl FUN_080cef30
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r4, r2
	str r0, [r1]
	movs r0, #1
	str r0, [r4, #0x1c]
	ldr r1, _080CF144 @ =0x030046A0
	ldr r0, [r1]
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	movs r5, #0
	str r5, [r0]
	ldr r2, [r1]
	adds r3, #4
	adds r0, r2, r3
	str r5, [r0]
	subs r3, #0x1c
	adds r0, r2, r3
	strh r5, [r0]
	ldr r0, [r1]
	ldr r1, _080CF148 @ =0x000002B2
	adds r0, r0, r1
	strh r5, [r0]
	adds r0, r4, #0
	bl FUN_080cef5c
	adds r0, r4, #0
	bl FUN_080cefcc
	adds r0, r4, #0
	bl FUN_080cf01c
	adds r0, r4, #0
	bl FUN_080cf040
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	adds r0, r4, #0
	bl FUN_080cf064
	ldr r2, _080CF14C @ =0x00000442
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _080CF150 @ =0x00000444
	adds r0, r4, r3
	strh r5, [r0]
	ldr r1, _080CF154 @ =0x00000446
	adds r0, r4, r1
	strh r5, [r0]
	ldr r1, [r4, #0x18]
	adds r2, #0x13
	adds r0, r4, r2
	strb r1, [r0]
	adds r3, #0x16
	adds r0, r4, r3
	strh r5, [r0]
	ldr r0, _080CF158 @ =0x0000045C
	adds r4, r4, r0
	str r5, [r4]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080CF144: .4byte 0x030046A0
_080CF148: .4byte 0x000002B2
_080CF14C: .4byte 0x00000442
_080CF150: .4byte 0x00000444
_080CF154: .4byte 0x00000446
_080CF158: .4byte 0x0000045C

	thumb_func_start FUN_080cf15c
FUN_080cf15c: @ 0x080CF15C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r0, _080CF1CC @ =0x0000CB05
	ldr r1, _080CF1D0 @ =0x0000DE23
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	beq _080CF23E
	adds r1, r6, #0
	adds r1, #0x68
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x68
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	adds r5, r6, #0
	adds r5, #0x88
	movs r3, #0x90
	lsls r3, r3, #8
	movs r0, #2
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0x2c
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_Add
	movs r0, #0x64
	bl VM_SeekToKeyword
	adds r1, r0, #0
	adds r7, r4, #0
	cmp r1, #0
	beq _080CF1D8
	bl Script_GetValue
	ldr r2, _080CF1D4 @ =0x00000454
	adds r1, r6, r2
	strb r0, [r1]
	b _080CF1DE
	.align 2, 0
_080CF1CC: .4byte 0x0000CB05
_080CF1D0: .4byte 0x0000DE23
_080CF1D4: .4byte 0x00000454
_080CF1D8:
	ldr r3, _080CF224 @ =0x00000454
	adds r0, r6, r3
	strb r1, [r0]
_080CF1DE:
	ldr r4, _080CF224 @ =0x00000454
	adds r0, r6, r4
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r4, #0
	strb r1, [r0]
	adds r0, r6, #0
	bl FUN_080cc1a0
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r6, r3
	strh r4, [r0]
	ldr r1, _080CF228 @ =0x000002E6
	adds r0, r6, r1
	ldrb r2, [r0]
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r2, _080CF22C @ =0x000002E7
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CF230
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #4
	orrs r1, r2
	b _080CF23C
	.align 2, 0
_080CF224: .4byte 0x00000454
_080CF228: .4byte 0x000002E6
_080CF22C: .4byte 0x000002E7
_080CF230:
	adds r0, r6, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #5
	rsbs r2, r2, #0
	ands r1, r2
_080CF23C:
	str r1, [r0]
_080CF23E:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cf248
FUN_080cf248: @ 0x080CF248
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r4, r7, r0
	ldr r1, _080CF2F8 @ =0x0000D495
	adds r0, r4, #0
	bl Video_GetAuxSprite
	ldr r0, _080CF2FC @ =0x0000922E
	ldr r1, _080CF300 @ =0x0000AF44
	bl GetFile
	mov r8, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	mov r2, r8
	str r2, [r0]
	adds r6, r7, #0
	adds r6, #0xe8
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r7, r1
	str r4, [r0]
	movs r5, #0
	ldr r2, _080CF304 @ =0x00001001
	adds r0, r6, #0
	adds r1, r4, #0
	bl AuxSprite_Add
	ldrh r1, [r7, #0x2c]
	movs r2, #0x82
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	ldrh r0, [r7, #0x2e]
	adds r2, #2
	adds r1, r7, r2
	strh r0, [r1]
	ldrh r1, [r7, #0x30]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	ldr r1, _080CF308 @ =0x000003F6
	adds r0, r7, r1
	strh r5, [r0]
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r7, r2
	ldr r1, _080CF30C @ =0x000002E6
	adds r0, r7, r1
	ldrb r3, [r0]
	subs r2, #0x55
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	mov r1, r8
	movs r2, #0
	bl FUN_08236fac
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r5, r1, r0
	ldrh r0, [r5]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _080CF310
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080CF318
	.align 2, 0
_080CF2F8: .4byte 0x0000D495
_080CF2FC: .4byte 0x0000922E
_080CF300: .4byte 0x0000AF44
_080CF304: .4byte 0x00001001
_080CF308: .4byte 0x000003F6
_080CF30C: .4byte 0x000002E6
_080CF310:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080CF318:
	str r0, [r6]
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
	beq _080CF33C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080CF344
_080CF33C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080CF344:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080CF37C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080CF3B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080CF380
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080CF374
	ldrb r0, [r4, #5]
_080CF374:
	subs r0, #1
	strh r0, [r4, #8]
	b _080CF390
	.align 2, 0
_080CF37C: .4byte 0x0000FFFF
_080CF380:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080CF390
	strh r1, [r4, #8]
_080CF390:
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
	bne _080CF3B4
	movs r0, #1
	strb r0, [r4, #7]
_080CF3B4:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cf3c0
FUN_080cf3c0: @ 0x080CF3C0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r7, r0, #0
	adds r6, r1, #0
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r1, r0, #0
	cmp r1, #0
	beq _080CF400
	bl Script_GetValue
	ldr r2, _080CF3F8 @ =0x0000044C
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	ldr r2, _080CF3FC @ =0x0000044E
	adds r1, r7, r2
	strh r0, [r1]
	bl Script_GetValue
	movs r2, #0x8a
	lsls r2, r2, #3
	adds r1, r7, r2
	strh r0, [r1]
	b _080CF412
	.align 2, 0
_080CF3F8: .4byte 0x0000044C
_080CF3FC: .4byte 0x0000044E
_080CF400:
	ldr r2, _080CF440 @ =0x0000044C
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r7, r2
	strh r1, [r0]
_080CF412:
	ldr r0, _080CF440 @ =0x0000044C
	adds r5, r7, r0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CF43A
	cmp r1, #0
	blt _080CF43A
	ldr r0, _080CF444 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CF43A
	ldr r0, _080CF448 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CF44C
_080CF43A:
	movs r4, #0
	b _080CF45A
	.align 2, 0
_080CF440: .4byte 0x0000044C
_080CF444: .4byte 0x030046A8
_080CF448: .4byte 0x030046AC
_080CF44C:
	ldr r0, _080CF46C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CF45A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CF470
	adds r0, #4
	b _080CF47C
	.align 2, 0
_080CF46C: .4byte 0x030046A4
_080CF470:
	ldr r0, _080CF490 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CF47C:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CF494
	cmp r2, #2
	beq _080CF498
	b _080CF49C
	.align 2, 0
_080CF490: .4byte 0x030046A4
_080CF494:
	ldrb r0, [r5, #4]
	b _080CF49A
_080CF498:
	ldrb r0, [r5]
_080CF49A:
	subs r1, r1, r0
_080CF49C:
	ldr r2, _080CF538 @ =0x0000044E
	adds r0, r7, r2
	movs r4, #0
	strh r1, [r0]
	adds r5, r7, #0
	adds r5, #0x24
	lsls r1, r6, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _080CF53C @ =0x0000044C
	adds r6, r7, r0
	ldrb r0, [r7, #0x18]
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	adds r2, r6, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r7, #0
	bl FUN_080cf15c
	adds r0, r7, #0
	bl FUN_080cf248
	ldr r1, _080CF540 @ =0x00000359
	adds r0, r7, r1
	strb r4, [r0]
	adds r1, r7, #0
	adds r1, #0x88
	adds r0, r5, #0
	bl FUN_0823b474
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r7, r2
	adds r0, r4, #0
	adds r1, r6, #0
	bl FUN_0823280c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0x1e
	movs r3, #0x1e
	bl FUN_0823b43c
	ldr r1, _080CF544 @ =0xFFFF0000
	movs r0, #0x96
	lsls r0, r0, #0x11
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
	adds r0, r5, #0
	add r1, sp, #8
	bl FUN_0823b47c
	ldrh r1, [r7, #0x24]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r1, #0x88
	lsls r1, r1, #2
	adds r0, r7, r1
	adds r1, r5, #0
	movs r2, #2
	bl FUN_080f8c58
	ldr r2, _080CF548 @ =0x03002B68
	ldr r1, [r7, #0x18]
	lsls r1, r1, #1
	adds r1, r1, r2
	ldrh r2, [r7, #0x24]
	strh r2, [r1]
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080CF538: .4byte 0x0000044E
_080CF53C: .4byte 0x0000044C
_080CF540: .4byte 0x00000359
_080CF544: .4byte 0xFFFF0000
_080CF548: .4byte 0x03002B68

	thumb_func_start FUN_080cf54c
FUN_080cf54c: @ 0x080CF54C
	push {lr}
	movs r2, #0xa2
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r1, [r1]
	adds r1, #0x1c
	bl player_weapon_080ceafc
	pop {r0}
	bx r0

	thumb_func_start FUN_080cf560
FUN_080cf560: @ 0x080CF560
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	movs r0, #0xb6
	lsls r0, r0, #1
	adds r6, r5, r0
	ldr r2, _080CF5CC @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x32
	orrs r0, r3
	ldr r1, _080CF5D0 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xfe
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r4, sp, #0x14
	ldr r0, [r4, #4]
	ands r0, r2
	str r0, [r4, #4]
	ldrh r1, [r5, #0x24]
	ldr r2, _080CF5D4 @ =0x00004001
	ldr r3, [r5, #0x18]
	movs r0, #0x80
	lsls r0, r0, #9
	lsls r0, r3
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r4, [sp, #8]
	adds r0, r6, #0
	movs r3, #0
	bl Hitbox_Init
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CF5D8
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #1
	movs r3, #2
	bl Hitbox_SetPowerAndAttributes
	b _080CF5E4
	.align 2, 0
_080CF5CC: .4byte 0xFFFF0000
_080CF5D0: .4byte 0x0000FFFF
_080CF5D4: .4byte 0x00004001
_080CF5D8:
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #2
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
_080CF5E4:
	ldr r1, _080CF60C @ =FUN_080d787c
	adds r0, r6, #0
	adds r2, r5, #0
	bl Hitbox_SetHandler
	movs r0, #0x82
	lsls r0, r0, #1
	adds r1, r5, r0
	adds r0, r6, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	bl Hitbox_Register
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF60C: .4byte FUN_080d787c

	thumb_func_start FUN_080cf610
FUN_080cf610: @ 0x080CF610
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080CF648 @ =0x08DAA7E8
	ldr r0, _080CF64C @ =0x00000266
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r1, [r2, #2]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CF654
	subs r2, #0xfc
	adds r0, r4, r2
	ldr r2, _080CF650 @ =0x00000362
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r2, #1
	movs r3, #2
	bl Hitbox_SetPowerAndAttributes
	b _080CF668
	.align 2, 0
_080CF648: .4byte 0x08DAA7E8
_080CF64C: .4byte 0x00000266
_080CF650: .4byte 0x00000362
_080CF654:
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldr r2, _080CF67C @ =0x00000362
	adds r1, r4, r2
	ldrh r1, [r1]
	movs r2, #2
	movs r3, #1
	bl Hitbox_SetPowerAndAttributes
_080CF668:
	movs r0, #0xde
	lsls r0, r0, #2
	adds r2, r4, r0
	ldr r1, _080CF680 @ =0xF000000F
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CF67C: .4byte 0x00000362
_080CF680: .4byte 0xF000000F

	thumb_func_start FUN_080cf684
FUN_080cf684: @ 0x080CF684
	push {r4, r5, lr}
	sub sp, #0x20
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bhi _080CF6D0
	movs r1, #0x82
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r3, _080CF6C8 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r3
	movs r2, #0x20
	orrs r0, r2
	ldr r1, _080CF6CC @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r3
	b _080CF702
	.align 2, 0
_080CF6C8: .4byte 0xFFFF0000
_080CF6CC: .4byte 0x0000FFFF
_080CF6D0:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	ldr r2, [sp, #0x18]
	asrs r1, r2, #0x10
	adds r1, #0x50
	lsls r1, r1, #0x10
	ldr r3, _080CF734 @ =0x0000FFFF
	adds r0, r3, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x18]
	ldr r4, _080CF738 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r4
	movs r2, #0x40
	orrs r0, r2
	ands r0, r3
	movs r1, #0xf0
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x14]
	ands r0, r4
_080CF702:
	orrs r0, r2
	str r0, [sp, #0x14]
	add r0, sp, #0x18
	movs r1, #0
	str r1, [sp]
	movs r1, #0xc
	str r1, [sp, #4]
	movs r1, #2
	str r1, [sp, #8]
	str r1, [sp, #0xc]
	movs r1, #1
	add r2, sp, #0x10
	movs r3, #0
	bl FUN_080ddcc8
	ldr r0, _080CF73C @ =0x00000376
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #0x20
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF734: .4byte 0x0000FFFF
_080CF738: .4byte 0xFFFF0000
_080CF73C: .4byte 0x00000376

	thumb_func_start FUN_080cf740
FUN_080cf740: @ 0x080CF740
	push {r4, r5, r6, lr}
	mov ip, r0
	ldr r0, _080CF784 @ =0x000003CA
	add r0, ip
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	movs r3, #0
	ldrsh r0, [r1, r3]
	subs r6, r0, r2
	movs r4, #0xf3
	lsls r4, r4, #2
	add r4, ip
	movs r3, #0
	ldrsh r0, [r4, r3]
	subs r5, r0, r2
	subs r3, r5, r6
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r3, r0
	ble _080CF78C
	ldr r2, _080CF788 @ =0xFFFFFCE0
	adds r0, r3, r2
	asrs r2, r0, #1
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	subs r0, r0, r2
	b _080CF7A0
	.align 2, 0
_080CF784: .4byte 0x000003CA
_080CF788: .4byte 0xFFFFFCE0
_080CF78C:
	ldr r0, _080CF7F4 @ =0xFFFFFCE0
	cmp r3, r0
	bge _080CF7A2
	subs r0, r0, r3
	asrs r2, r0, #1
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	ldrh r0, [r4]
	adds r0, r0, r2
_080CF7A0:
	strh r0, [r4]
_080CF7A2:
	adds r3, r5, r6
	movs r0, #0xc8
	lsls r0, r0, #2
	cmp r3, r0
	ble _080CF7CA
	ldr r1, _080CF7F4 @ =0xFFFFFCE0
	adds r0, r3, r1
	asrs r2, r0, #1
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	movs r1, #0xf3
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
_080CF7CA:
	ldr r0, _080CF7F4 @ =0xFFFFFCE0
	cmp r3, r0
	bge _080CF7EC
	subs r0, r0, r3
	asrs r2, r0, #1
	movs r1, #0xf2
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	movs r1, #0xf3
	lsls r1, r1, #2
	add r1, ip
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
_080CF7EC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CF7F4: .4byte 0xFFFFFCE0

	thumb_func_start FUN_080cf7f8
FUN_080cf7f8: @ 0x080CF7F8
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _080CF880 @ =0x000003CE
	adds r3, r4, r0
	movs r1, #0
	ldrsh r2, [r3, r1]
	cmp r2, #0
	bne _080CF842
	ldrh r1, [r4, #0x2c]
	movs r5, #0xf0
	lsls r5, r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	ldrh r0, [r4, #0x2e]
	adds r0, #0x96
	adds r5, #2
	adds r1, r4, r5
	strh r0, [r1]
	ldrh r1, [r4, #0x30]
	adds r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	movs r1, #0xf2
	lsls r1, r1, #2
	adds r0, r4, r1
	strh r2, [r0]
	adds r5, #6
	adds r0, r4, r5
	strh r2, [r0]
	adds r1, #4
	adds r0, r4, r1
	strh r2, [r0]
	movs r0, #1
	strh r0, [r3]
	adds r0, r4, #0
	bl FUN_080cf740
_080CF842:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r2, r4, r3
	movs r5, #0
	ldrsh r1, [r2, r5]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080CF8C8
	adds r0, r1, #0
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080CF884 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CF888
	asrs r3, r0, #0xc
	b _080CF88E
	.align 2, 0
_080CF880: .4byte 0x000003CE
_080CF884: .4byte 0x085B0A08
_080CF888:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080CF88E:
	movs r0, #0xf2
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r0, [r1]
	subs r0, r0, r3
	strh r0, [r1]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CF8B0
	asrs r2, r0, #0xc
	b _080CF8B6
_080CF8B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CF8B6:
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r1, r4, r3
	ldrh r0, [r1]
	subs r0, r0, r2
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080cf740
_080CF8C8:
	movs r5, #0xf2
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r2, #0
	ldrsh r0, [r1, r2]
	cmp r0, #0
	bne _080CF8E4
	movs r3, #0xf3
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r5, #0
	ldrsh r0, [r0, r5]
	cmp r0, #0
	beq _080CF94A
_080CF8E4:
	ldr r2, _080CF934 @ =0x000003D1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080CF94A
	movs r3, #0
	ldrsh r0, [r1, r3]
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	adds r0, #3
	movs r1, #7
	ands r1, r0
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r4, r3
	adds r2, r1, #0
	strb r1, [r0]
	cmp r2, #4
	bls _080CF93C
	movs r0, #8
	subs r0, r0, r2
	subs r5, #0xe6
	adds r1, r4, r5
	strb r0, [r1]
	ldr r0, _080CF938 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	b _080CF948
	.align 2, 0
_080CF934: .4byte 0x000003D1
_080CF938: .4byte 0x000002E7
_080CF93C:
	ldr r2, _080CF950 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080CF954 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_080CF948:
	strb r0, [r1]
_080CF94A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CF950: .4byte 0x000002E6
_080CF954: .4byte 0x000002E7

	thumb_func_start FUN_080cf958
FUN_080cf958: @ 0x080CF958
	push {r4, r5, lr}
	adds r3, r0, #0
	ldr r1, _080CF9B8 @ =0x000003CE
	adds r0, r3, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080CFA18
	ldrh r1, [r3, #0x2c]
	movs r5, #0xf0
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	ldrh r0, [r3, #0x2e]
	adds r0, #0x96
	ldr r2, _080CF9BC @ =0x000003C2
	adds r1, r3, r2
	strh r0, [r1]
	ldrh r1, [r3, #0x30]
	adds r5, #4
	adds r0, r3, r5
	strh r1, [r0]
	ldr r1, _080CF9C0 @ =0x000003BD
	adds r0, r3, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _080CF9C4 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r5, r2, #0
	cmp r0, #0
	blt _080CF9C8
	asrs r0, r0, #0xc
	b _080CF9CE
	.align 2, 0
_080CF9B8: .4byte 0x000003CE
_080CF9BC: .4byte 0x000003C2
_080CF9C0: .4byte 0x000003BD
_080CF9C4: .4byte 0x085B0A08
_080CF9C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CF9CE:
	rsbs r1, r0, #0
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r0, r3, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080CF9FC @ =0x000003CA
	adds r0, r3, r1
	strh r2, [r0]
	lsls r0, r4, #1
	adds r0, r0, r5
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r1
	lsls r0, r0, #5
	cmp r0, #0
	blt _080CFA00
	asrs r0, r0, #0xc
	b _080CFA06
	.align 2, 0
_080CF9FC: .4byte 0x000003CA
_080CFA00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080CFA06:
	rsbs r1, r0, #0
	movs r5, #0xf3
	lsls r5, r5, #2
	adds r0, r3, r5
	strh r1, [r0]
	ldr r0, _080CFA20 @ =0x000003CE
	adds r1, r3, r0
	movs r0, #1
	strh r0, [r1]
_080CFA18:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080CFA20: .4byte 0x000003CE

	thumb_func_start FUN_080cfa24
FUN_080cfa24: @ 0x080CFA24
	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _080CFA38 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CFA3C
	movs r1, #1
	rsbs r1, r1, #0
	b _080CFA40
	.align 2, 0
_080CFA38: .4byte 0x03002C68
_080CFA3C:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080CFA40:
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bne _080CFA4C
	movs r0, #8
	bl FUN_0823bca8
_080CFA4C:
	ldr r0, _080CFA5C @ =0x000003CE
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CFA5C: .4byte 0x000003CE

	thumb_func_start FUN_080cfa60
FUN_080cfa60: @ 0x080CFA60
	push {lr}
	adds r2, r0, #0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #1
	bls _080CFA74
	cmp r0, #5
	bne _080CFA92
_080CFA74:
	cmp r1, #0
	beq _080CFA9A
	cmp r1, #3
	beq _080CFA9A
	cmp r1, #6
	beq _080CFA9A
	cmp r1, #4
	bne _080CFA9E
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CFA9A
	b _080CFA9E
_080CFA92:
	cmp r1, #0
	beq _080CFA9A
	cmp r1, #4
	bne _080CFA9E
_080CFA9A:
	movs r0, #1
	b _080CFAA0
_080CFA9E:
	movs r0, #0
_080CFAA0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfaa4
FUN_080cfaa4: @ 0x080CFAA4
	push {r4, lr}
	adds r4, r0, #0
	adds r2, r1, #0
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080CFAF6
	adds r0, r4, #0
	adds r1, r2, #0
	bl FUN_080cfa60
	cmp r0, #0
	beq _080CFAF6
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bls _080CFADA
	cmp r0, #5
	bne _080CFAEE
_080CFADA:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080CFAEE
	adds r0, r4, #0
	bl FUN_080cf958
	b _080CFB08
_080CFAEE:
	adds r0, r4, #0
	bl FUN_080cf7f8
	b _080CFB08
_080CFAF6:
	ldr r1, _080CFB18 @ =0x000003CE
	adds r0, r4, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080CFB08
	adds r0, r4, #0
	bl FUN_080cfa24
_080CFB08:
	ldr r0, _080CFB1C @ =0x000003D1
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080CFB18: .4byte 0x000003CE
_080CFB1C: .4byte 0x000003D1

	thumb_func_start FUN_080cfb20
FUN_080cfb20: @ 0x080CFB20
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	ldr r2, _080CFBA8 @ =0x000003CA
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	ldr r1, _080CFBAC @ =0x000003C2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r1, #0x96
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r1, [r0]
	ldr r0, _080CFBB0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CFBB4
	movs r0, #1
	rsbs r0, r0, #0
	b _080CFBB8
	.align 2, 0
_080CFBA8: .4byte 0x000003CA
_080CFBAC: .4byte 0x000003C2
_080CFBB0: .4byte 0x03002C68
_080CFBB4:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_080CFBB8:
	cmp r1, r0
	bne _080CFBC6
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r5, r1
	bl FUN_0823bac8
_080CFBC6:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_080cfbcc
FUN_080cfbcc: @ 0x080CFBCC
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFBFE
	movs r1, #0x18
	ldr r0, _080CFBEC @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFBF0 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFBF4
	movs r0, #1
	b _080CFBF6
	.align 2, 0
_080CFBEC: .4byte 0x030046A0
_080CFBF0: .4byte 0x00000934
_080CFBF4:
	movs r0, #0
_080CFBF6:
	cmp r0, #0
	bne _080CFBFE
	movs r0, #1
	b _080CFC00
_080CFBFE:
	movs r0, #0
_080CFC00:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfc04
FUN_080cfc04: @ 0x080CFC04
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFC36
	movs r1, #0x10
	ldr r0, _080CFC24 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFC28 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFC2C
	movs r0, #1
	b _080CFC2E
	.align 2, 0
_080CFC24: .4byte 0x030046A0
_080CFC28: .4byte 0x00000934
_080CFC2C:
	movs r0, #0
_080CFC2E:
	cmp r0, #0
	beq _080CFC36
	movs r0, #1
	b _080CFC38
_080CFC36:
	movs r0, #0
_080CFC38:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfc3c
FUN_080cfc3c: @ 0x080CFC3C
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFC72
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, _080CFC60 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFC64 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFC68
	movs r0, #1
	b _080CFC6A
	.align 2, 0
_080CFC60: .4byte 0x030046A0
_080CFC64: .4byte 0x00000934
_080CFC68:
	movs r0, #0
_080CFC6A:
	cmp r0, #0
	beq _080CFC72
	movs r0, #1
	b _080CFC74
_080CFC72:
	movs r0, #0
_080CFC74:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfc78
FUN_080cfc78: @ 0x080CFC78
	push {lr}
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0
	beq _080CFCAA
	movs r1, #8
	ldr r0, _080CFC98 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080CFC9C @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080CFCA0
	movs r0, #1
	b _080CFCA2
	.align 2, 0
_080CFC98: .4byte 0x030046A0
_080CFC9C: .4byte 0x00000934
_080CFCA0:
	movs r0, #0
_080CFCA2:
	cmp r0, #0
	beq _080CFCAA
	movs r0, #1
	b _080CFCAC
_080CFCAA:
	movs r0, #0
_080CFCAC:
	pop {r1}
	bx r1

	thumb_func_start FUN_080cfcb0
FUN_080cfcb0: @ 0x080CFCB0
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	ldrh r0, [r7, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r7, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFCD8
	cmp r1, #0
	blt _080CFCD8
	ldr r0, _080CFCDC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFCD8
	ldr r0, _080CFCE0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFCE4
_080CFCD8:
	movs r4, #0
	b _080CFCF2
	.align 2, 0
_080CFCDC: .4byte 0x030046A8
_080CFCE0: .4byte 0x030046AC
_080CFCE4:
	ldr r0, _080CFD04 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFCF2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CFD08
	adds r0, #4
	b _080CFD14
	.align 2, 0
_080CFD04: .4byte 0x030046A4
_080CFD08:
	ldr r0, _080CFDA0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFD14:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080CFDE4
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080CFDE4
	ldr r2, _080CFDA4 @ =0x00000395
	adds r0, r7, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080CFDE4
	adds r0, r7, #0
	adds r0, #0x2c
	bl FUN_081d2230
	cmp r0, #0
	bne _080CFDE4
	movs r5, #0xe0
	lsls r5, r5, #1
	adds r6, r7, r5
	ldrh r0, [r6]
	ldr r5, _080CFDA0 @ =0x030046A4
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r2, #4
	ldrsh r1, [r1, r2]
	bl Mod
	adds r4, r0, #0
	ldrh r0, [r6]
	ldr r1, [r5]
	ldr r1, [r1, #4]
	movs r5, #4
	ldrsh r1, [r1, r5]
	bl Div
	lsls r4, r4, #8
	adds r1, r4, #0
	adds r1, #0x80
	movs r2, #0xe7
	lsls r2, r2, #2
	adds r3, r7, r2
	strh r1, [r3]
	lsls r0, r0, #8
	adds r2, r0, #0
	adds r2, #0x80
	movs r5, #0xe8
	lsls r5, r5, #2
	adds r1, r7, r5
	strh r2, [r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r7, r2
	str r3, [r1]
	adds r2, r4, #1
	adds r4, #0xff
	adds r3, r0, #1
	adds r0, #0xff
	movs r5, #0x2c
	ldrsh r1, [r7, r5]
	cmp r1, r2
	bge _080CFDA8
	strh r2, [r7, #0x2c]
	b _080CFDAE
	.align 2, 0
_080CFDA0: .4byte 0x030046A4
_080CFDA4: .4byte 0x00000395
_080CFDA8:
	cmp r1, r4
	ble _080CFDAE
	strh r4, [r7, #0x2c]
_080CFDAE:
	movs r2, #0x30
	ldrsh r1, [r7, r2]
	cmp r1, r3
	bge _080CFDBA
	strh r3, [r7, #0x30]
	b _080CFDC0
_080CFDBA:
	cmp r1, r0
	ble _080CFDC0
	strh r0, [r7, #0x30]
_080CFDC0:
	movs r5, #0x82
	lsls r5, r5, #1
	adds r2, r7, r5
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r2, r7, #0
	adds r2, #0xa8
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r0, #0xe5
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
_080CFDE4:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080cfdec
FUN_080cfdec: @ 0x080CFDEC
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080CFE74 @ =0x00000395
	adds r0, r4, r1
	movs r2, #0
	movs r6, #1
	strb r6, [r0]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r1, r4, r3
	movs r5, #0
	movs r0, #0x32
	strh r0, [r1]
	movs r1, #0x3c
	adds r3, #4
	adds r0, r4, r3
	strh r1, [r0]
	ldr r1, _080CFE78 @ =0x000003D2
	adds r0, r4, r1
	strb r5, [r0]
	ldr r3, _080CFE7C @ =0x000003F6
	adds r0, r4, r3
	strh r2, [r0]
	movs r1, #0x2c
	ldrsh r0, [r4, r1]
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r1, r4, r2
	ldr r2, [r1]
	movs r3, #0
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r3, #0x30
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r2, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	adds r0, #1
	movs r1, #3
	ands r1, r0
	lsls r1, r1, #1
	adds r1, #1
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	strb r1, [r2]
	lsls r0, r1, #0x18
	cmp r1, #4
	bls _080CFE88
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080CFE80 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080CFE84 @ =0x000002E7
	adds r0, r4, r3
	strb r6, [r0]
	b _080CFE96
	.align 2, 0
_080CFE74: .4byte 0x00000395
_080CFE78: .4byte 0x000003D2
_080CFE7C: .4byte 0x000003F6
_080CFE80: .4byte 0x000002E6
_080CFE84: .4byte 0x000002E7
_080CFE88:
	lsrs r0, r0, #0x19
	ldr r2, _080CFEB0 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080CFEB4 @ =0x000002E7
	adds r0, r4, r3
	strb r5, [r0]
_080CFE96:
	ldr r0, _080CFEB8 @ =0x000003D6
	adds r1, r4, r0
	movs r2, #0
	ldr r0, _080CFEBC @ =0x00000191
	strh r0, [r1]
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0x32
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080CFEB0: .4byte 0x000002E6
_080CFEB4: .4byte 0x000002E7
_080CFEB8: .4byte 0x000003D6
_080CFEBC: .4byte 0x00000191

	thumb_func_start FUN_080cfec0
FUN_080cfec0: @ 0x080CFEC0
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFEEA
	cmp r1, #0
	blt _080CFEEA
	ldr r0, _080CFEF0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFEEA
	ldr r0, _080CFEF4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFEF8
_080CFEEA:
	movs r4, #0
	b _080CFF06
	.align 2, 0
_080CFEF0: .4byte 0x030046A8
_080CFEF4: .4byte 0x030046AC
_080CFEF8:
	ldr r0, _080CFF18 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFF06:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CFF1C
	adds r0, #4
	b _080CFF28
	.align 2, 0
_080CFF18: .4byte 0x030046A4
_080CFF1C:
	ldr r0, _080CFF3C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFF28:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080CFF40
	cmp r2, #2
	beq _080CFF44
	b _080CFF48
	.align 2, 0
_080CFF3C: .4byte 0x030046A4
_080CFF40:
	ldrb r0, [r5, #4]
	b _080CFF46
_080CFF44:
	ldrb r0, [r5]
_080CFF46:
	subs r1, r1, r0
_080CFF48:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r1, r0
	bne _080CFFC4
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080CFF74
	cmp r1, #0
	blt _080CFF74
	ldr r0, _080CFF78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080CFF74
	ldr r0, _080CFF7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080CFF80
_080CFF74:
	movs r4, #0
	b _080CFF8E
	.align 2, 0
_080CFF78: .4byte 0x030046A8
_080CFF7C: .4byte 0x030046AC
_080CFF80:
	ldr r0, _080CFFA0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080CFF8E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080CFFA4
	adds r0, #4
	b _080CFFB0
	.align 2, 0
_080CFFA0: .4byte 0x030046A4
_080CFFA4:
	ldr r0, _080CFFC0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080CFFB0:
	ldrh r0, [r0, #2]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _080CFFC4
	movs r0, #0
	b _080CFFC6
	.align 2, 0
_080CFFC0: .4byte 0x030046A4
_080CFFC4:
	movs r0, #1
_080CFFC6:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080cffcc
FUN_080cffcc: @ 0x080CFFCC
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _080CFFE8 @ =0x000003A7
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D0084
	cmp r0, #2
	bgt _080CFFEC
	cmp r0, #0
	beq _080CFFFA
	b _080D01BA
	.align 2, 0
_080CFFE8: .4byte 0x000003A7
_080CFFEC:
	cmp r0, #4
	bne _080CFFF2
	b _080D00EA
_080CFFF2:
	cmp r0, #6
	bne _080CFFF8
	b _080D0150
_080CFFF8:
	b _080D01BA
_080CFFFA:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D0080 @ =0xFFFF0000
	ldr r3, [sp]
	ands r3, r2
	orrs r3, r0
	str r3, [sp]
	mov r4, sp
	ldrh r0, [r4, #4]
	subs r0, #0x1e
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ands r2, r3
	orrs r2, r0
	str r2, [sp]
	adds r0, r5, #0
	mov r1, sp
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D0060
	b _080D01B6
_080D0060:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	b _080D01B6
	.align 2, 0
_080D0080: .4byte 0xFFFF0000
_080D0084:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	subs r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D00E6
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	subs r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D014C
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D014C
_080D00E6:
	movs r0, #1
	b _080D01BE
_080D00EA:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	adds r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D014C
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
_080D014C:
	movs r0, #3
	b _080D01BE
_080D0150:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x1e
	mov r1, sp
	strh r0, [r1]
	mov r4, sp
	ldrh r0, [r4, #4]
	adds r0, #0x1e
	strh r0, [r4, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B2
	mov r0, sp
	ldrh r0, [r0]
	adds r0, #0x64
	mov r1, sp
	strh r0, [r1]
	ldrh r0, [r4, #4]
	adds r0, #0x64
	strh r0, [r4, #4]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	bne _080D01B6
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	subs r0, #0x64
	mov r1, sp
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080cfec0
	cmp r0, #0
	beq _080D01B6
_080D01B2:
	movs r0, #5
	b _080D01BE
_080D01B6:
	movs r0, #7
	b _080D01BE
_080D01BA:
	movs r0, #1
	rsbs r0, r0, #0
_080D01BE:
	add sp, #8
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d01c8
FUN_080d01c8: @ 0x080D01C8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r0, #0xe9
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	bne _080D01DA
	b _080D02E2
_080D01DA:
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	adds r1, r0, #0
	cmp r1, #0
	bne _080D0200
	ldr r2, _080D01F8 @ =0x000003A5
	adds r0, r5, r2
	strb r1, [r0]
	ldr r4, _080D01FC @ =0x000003A6
	adds r0, r5, r4
	b _080D022C
	.align 2, 0
_080D01F8: .4byte 0x000003A5
_080D01FC: .4byte 0x000003A6
_080D0200:
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r7, #1
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080D02B0
	ldr r2, _080D0234 @ =0x000003A7
	adds r4, r5, r2
	ldrb r1, [r4]
	adds r0, r7, #0
	ands r0, r1
	cmp r0, #0
	beq _080D023C
	ldr r4, _080D0238 @ =0x000003A5
	adds r0, r5, r4
	movs r1, #0
	strb r1, [r0]
	subs r2, #1
	adds r0, r5, r2
_080D022C:
	strb r1, [r0]
	strb r1, [r6]
	b _080D038E
	.align 2, 0
_080D0234: .4byte 0x000003A7
_080D0238: .4byte 0x000003A5
_080D023C:
	adds r0, r5, #0
	bl FUN_080cffcc
	strb r0, [r4]
	ldrb r0, [r4]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D0270 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D0274
	asrs r1, r0, #0xc
	b _080D027A
	.align 2, 0
_080D0270: .4byte 0x085B0A08
_080D0274:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D027A:
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r1, _080D029C @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D02A0
	asrs r1, r0, #0xc
	b _080D02A6
	.align 2, 0
_080D029C: .4byte 0x085B0A08
_080D02A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D02A6:
	movs r2, #0xeb
	lsls r2, r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	b _080D038E
_080D02B0:
	ldr r0, _080D02D0 @ =0x000003A5
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	bne _080D038E
	ldr r2, _080D02D4 @ =0x000003A6
	adds r1, r5, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D02DC
	ldr r0, [r5, #0x18]
	ldr r1, _080D02D8 @ =0x00000335
	bl FUN_080cc3e4
	strb r7, [r4]
	b _080D038E
	.align 2, 0
_080D02D0: .4byte 0x000003A5
_080D02D4: .4byte 0x000003A6
_080D02D8: .4byte 0x00000335
_080D02DC:
	adds r0, #1
	strb r0, [r1]
	b _080D038E
_080D02E2:
	movs r4, #0xe5
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	beq _080D038E
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #1
	bls _080D0316
	cmp r1, #6
	bne _080D038E
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	blt _080D038E
_080D0316:
	movs r0, #1
	strb r0, [r6]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r2, _080D0354 @ =0x000003A7
	adds r0, r5, r2
	strb r1, [r0]
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D0358 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D035C
	asrs r1, r0, #0xc
	b _080D0362
	.align 2, 0
_080D0354: .4byte 0x000003A7
_080D0358: .4byte 0x085B0A08
_080D035C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D0362:
	movs r4, #0xea
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r1, [r0]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D0380
	asrs r2, r0, #0xc
	b _080D0386
_080D0380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0386:
	movs r4, #0xeb
	lsls r4, r4, #2
	adds r0, r5, r4
	strh r2, [r0]
_080D038E:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d0394
FUN_080d0394: @ 0x080D0394
	push {r4, lr}
	movs r2, #0xf7
	lsls r2, r2, #2
	adds r4, r0, r2
	adds r1, #2
	ldrh r2, [r4]
	adds r1, r1, r2
	strh r1, [r4]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, #0x63
	bls _080D03B6
	bl FUN_080cf684
	ldrh r0, [r4]
	subs r0, #0x64
	strh r0, [r4]
_080D03B6:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d03bc
FUN_080d03bc: @ 0x080D03BC
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r5, [sp, #0x1c]
	ldr r6, [sp, #0x24]
	movs r7, #0
	ldrsh r0, [r1, r7]
	movs r7, #4
	ldrsh r1, [r1, r7]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	str r3, [sp]
	ldrh r3, [r4, #0x24]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	cmp r5, #0
	beq _080D03F8
	ldr r0, [r4, #0x18]
	adds r1, r5, #0
	bl FUN_0801a0a0
	adds r0, r4, #0
	adds r1, r5, #0
	ldr r2, [sp, #0x20]
	bl FUN_080cc6b0
_080D03F8:
	cmp r6, #0
	beq _080D0404
	ldr r0, [r4, #0x18]
	adds r1, r6, #0
	bl FUN_080cc3e4
_080D0404:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d040c
FUN_080d040c: @ 0x080D040C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #3
	bne _080D044A
	movs r2, #0
	movs r0, #1
	strb r0, [r1]
	movs r3, #0xac
	lsls r3, r3, #4
	adds r1, r4, r3
	ldr r0, _080D0478 @ =FUN_080d6b24
	str r0, [r1]
	ldr r1, _080D047C @ =0x00000359
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	adds r0, #0x88
	str r0, [r4, #0x50]
	str r2, [r4, #0x4c]
	ldr r2, _080D0480 @ =0x000004CC
	adds r1, r4, r2
	adds r0, #0x20
	str r0, [r1]
	ldr r3, _080D0484 @ =0x0000094C
	adds r1, r4, r3
	ldr r0, _080D0488 @ =0x0000FFFF
	strh r0, [r1]
_080D044A:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D0494
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D048C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r3, _080D0490 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #1
	b _080D04A2
	.align 2, 0
_080D0478: .4byte FUN_080d6b24
_080D047C: .4byte 0x00000359
_080D0480: .4byte 0x000004CC
_080D0484: .4byte 0x0000094C
_080D0488: .4byte 0x0000FFFF
_080D048C: .4byte 0x000002E6
_080D0490: .4byte 0x000002E7
_080D0494:
	lsrs r1, r1, #0x19
	ldr r2, _080D0570 @ =0x000002E6
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D0574 @ =0x000002E7
	adds r1, r4, r3
	movs r0, #0
_080D04A2:
	strb r0, [r1]
	movs r0, #8
	str r0, [r4, #0x1c]
	ldr r1, _080D0578 @ =0x0000037D
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	ldr r2, _080D057C @ =0x0000037E
	adds r0, r4, r2
	movs r6, #0
	strh r5, [r0]
	movs r3, #0xd8
	lsls r3, r3, #1
	adds r0, r4, r3
	strh r5, [r0]
	subs r1, #0xfa
	adds r0, r4, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl FUN_080cdda8
	adds r0, r4, #0
	bl FUN_080cc43c
	ldr r2, _080D0580 @ =0x000003CE
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	cmp r0, #0
	beq _080D04E4
	adds r0, r4, #0
	bl FUN_080cfa24
_080D04E4:
	ldr r1, _080D0584 @ =0x00000442
	adds r0, r4, r1
	strh r5, [r0]
	ldr r2, _080D0588 @ =0x00000444
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _080D058C @ =0x00000446
	adds r0, r4, r3
	strh r5, [r0]
	subs r1, #0x51
	adds r0, r4, r1
	strb r6, [r0]
	subs r2, #0xa0
	adds r0, r4, r2
	strb r6, [r0]
	movs r2, #0
	movs r1, #2
	subs r3, #6
	adds r0, r4, r3
_080D050A:
	strh r2, [r0]
	subs r0, #2
	subs r1, #1
	cmp r1, #0
	bge _080D050A
	movs r1, #0xa2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #0x14]
	ldr r2, _080D0590 @ =0x00000456
	adds r0, r4, r2
	strb r1, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #5
	beq _080D054C
	ldr r0, _080D0594 @ =0x00000455
	adds r5, r4, r0
	movs r0, #0
	ldrsb r0, [r5, r0]
	cmp r0, #0
	blt _080D0548
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #0
	ldrsb r1, [r5, r1]
	bl FUN_081df9ac
_080D0548:
	movs r0, #0xff
	strb r0, [r5]
_080D054C:
	ldr r0, [r4, #0x18]
	bl FUN_081df7e8
	ldr r1, _080D0598 @ =0x0000045A
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _080D05DC
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D059C
	movs r0, #0
	bl FUN_081df7bc
	b _080D05CA
	.align 2, 0
_080D0570: .4byte 0x000002E6
_080D0574: .4byte 0x000002E7
_080D0578: .4byte 0x0000037D
_080D057C: .4byte 0x0000037E
_080D0580: .4byte 0x000003CE
_080D0584: .4byte 0x00000442
_080D0588: .4byte 0x00000444
_080D058C: .4byte 0x00000446
_080D0590: .4byte 0x00000456
_080D0594: .4byte 0x00000455
_080D0598: .4byte 0x0000045A
_080D059C:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D05AC
	movs r0, #1
	bl FUN_081df7bc
	b _080D05CA
_080D05AC:
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _080D05BC
	movs r0, #2
	bl FUN_081df7bc
	b _080D05CA
_080D05BC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D05CA
	movs r0, #3
	bl FUN_081df7bc
_080D05CA:
	ldr r2, _080D05E4 @ =0x0000045A
	adds r0, r4, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	adds r2, #2
	adds r1, r4, r2
	ldr r1, [r1]
	bl FUN_080ce544
_080D05DC:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D05E4: .4byte 0x0000045A

	thumb_func_start FUN_080d05e8
FUN_080d05e8: @ 0x080D05E8
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r6, r7, r0
	ldrb r0, [r6]
	cmp r0, #5
	beq _080D0606
	ldr r1, _080D06B8 @ =0x08DA9E68
	adds r0, r7, #0
	bl player_weapon_080ceafc
_080D0606:
	movs r1, #1
	mov r8, r1
	str r1, [r7, #0x1c]
	ldr r2, _080D06BC @ =0x00000366
	adds r0, r7, r2
	ldrh r1, [r0]
	subs r2, #2
	adds r0, r7, r2
	movs r2, #0
	mov sb, r2
	movs r5, #0
	strh r1, [r0]
	ldr r1, _080D06C0 @ =0x0000036A
	adds r0, r7, r1
	ldrh r1, [r0]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r7, r2
	strh r1, [r0]
	ldr r1, _080D06C4 @ =0x0000044C
	adds r0, r7, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x2c]
	str r1, [r7, #0x30]
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r7, r2
	adds r1, r7, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0823280c
	str r4, [r7, #0x3c]
	movs r1, #0xd5
	lsls r1, r1, #1
	adds r0, r7, r1
	strh r5, [r0]
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r5, [r0]
	ldr r1, _080D06C8 @ =0x00000395
	adds r0, r7, r1
	mov r2, sb
	strb r2, [r0]
	movs r0, #0xd8
	lsls r0, r0, #1
	adds r1, r7, r0
	movs r0, #0x5a
	strh r0, [r1]
	ldr r1, _080D06CC @ =0x000003F6
	adds r0, r7, r1
	strh r5, [r0]
	ldr r2, _080D06D0 @ =0x00000457
	adds r0, r7, r2
	mov r1, r8
	strb r1, [r0]
	subs r2, #3
	adds r0, r7, r2
	ldrb r1, [r0]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r7, r2
	strb r1, [r0]
	adds r0, r7, #0
	bl FUN_080cc1a0
	ldrb r0, [r6]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D06B8: .4byte 0x08DA9E68
_080D06BC: .4byte 0x00000366
_080D06C0: .4byte 0x0000036A
_080D06C4: .4byte 0x0000044C
_080D06C8: .4byte 0x00000395
_080D06CC: .4byte 0x000003F6
_080D06D0: .4byte 0x00000457

	thumb_func_start FUN_080d06d4
FUN_080d06d4: @ 0x080D06D4
	push {r4, r5, r6, r7, lr}
	mov ip, r0
	ldr r0, _080D06F4 @ =0x00000292
	add r0, ip
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r2, r1
	beq _080D0728
	movs r0, #1
	ands r0, r2
	cmp r0, #0
	beq _080D06F8
_080D06F0:
	adds r0, r2, #0
	b _080D0730
	.align 2, 0
_080D06F4: .4byte 0x00000292
_080D06F8:
	adds r4, r2, #1
	movs r0, #7
	ands r4, r0
	adds r3, r2, #7
	ands r3, r0
	movs r5, #2
	adds r6, r1, #0
	movs r1, #0xa5
	lsls r1, r1, #2
	add r1, ip
_080D070C:
	movs r7, #0
	ldrsh r0, [r1, r7]
	cmp r0, r6
	beq _080D0720
	cmp r0, r4
	beq _080D0730
	cmp r0, r3
	beq _080D0730
	cmp r0, r2
	bne _080D06F0
_080D0720:
	adds r1, #2
	adds r5, #1
	cmp r5, #9
	ble _080D070C
_080D0728:
	movs r0, #0xba
	lsls r0, r0, #2
	add r0, ip
	ldrb r0, [r0]
_080D0730:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d0738
FUN_080d0738: @ 0x080D0738
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0766
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	adds r0, r4, #0
	bl FUN_080d06d4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080cc1a0
_080D0766:
	ldr r0, [r4, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x20]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d0790
FUN_080d0790: @ 0x080D0790
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080D07D8 @ =0x00000446
	adds r0, r4, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D07AC
	ldr r2, _080D07DC @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D07AC
	movs r1, #1
_080D07AC:
	cmp r1, #0
	bne _080D07D4
	ldr r1, _080D07E0 @ =0x00000362
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0x9a
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	subs r0, #0x64
	subs r1, r1, r0
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	cmp r1, #0x10
	ble _080D07E4
_080D07D4:
	movs r1, #0x10
	b _080D07EA
	.align 2, 0
_080D07D8: .4byte 0x00000446
_080D07DC: .4byte 0x00000442
_080D07E0: .4byte 0x00000362
_080D07E4:
	cmp r1, #8
	bgt _080D07EA
	movs r1, #9
_080D07EA:
	ldr r2, _080D0814 @ =0x000004C5
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #2
	bne _080D0800
	adds r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0800
	subs r1, #4
_080D0800:
	ldr r0, _080D0818 @ =0x00000402
	adds r2, r4, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D080C
	subs r1, r1, r0
_080D080C:
	cmp r1, #1
	ble _080D081C
	adds r0, r1, #0
	b _080D081E
	.align 2, 0
_080D0814: .4byte 0x000004C5
_080D0818: .4byte 0x00000402
_080D081C:
	movs r0, #2
_080D081E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d0824
FUN_080d0824: @ 0x080D0824
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r2, r0, #0
	movs r0, #0xa4
	lsls r0, r0, #2
	adds r1, r2, r0
	movs r3, #0
	ldrsh r4, [r1, r3]
	movs r0, #1
	ands r0, r4
	cmp r0, #0
	bne _080D087E
	adds r5, r4, #1
	movs r0, #7
	ands r5, r0
	mov sb, r5
	adds r3, r4, #7
	ands r3, r0
	movs r6, #1
	mov r8, r1
	movs r7, #1
	rsbs r7, r7, #0
	mov ip, r7
	ldr r0, _080D088C @ =0x00000292
	adds r1, r2, r0
_080D085A:
	movs r5, #0
	ldrsh r2, [r1, r5]
	cmp r2, ip
	beq _080D0876
	adds r0, r2, #0
	cmp r0, sb
	beq _080D0880
	cmp r0, r3
	beq _080D0880
	mov r5, r8
	movs r7, #0
	ldrsh r0, [r5, r7]
	cmp r2, r0
	bne _080D087E
_080D0876:
	adds r1, #2
	adds r6, #1
	cmp r6, #4
	ble _080D085A
_080D087E:
	adds r0, r4, #0
_080D0880:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D088C: .4byte 0x00000292

	thumb_func_start FUN_080d0890
FUN_080d0890: @ 0x080D0890
	push {lr}
	adds r1, r0, #0
	cmp r1, #0xc
	bne _080D089C
	movs r0, #0x40
	b _080D08B2
_080D089C:
	cmp r1, #0xb
	ble _080D08AA
	subs r1, #0xc
	lsls r1, r1, #2
	movs r0, #0x40
	subs r0, r0, r1
	b _080D08B2
_080D08AA:
	movs r0, #0xc
	subs r0, r0, r1
	lsls r0, r0, #3
	adds r0, #0x40
_080D08B2:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d08b8
FUN_080d08b8: @ 0x080D08B8
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	adds r0, #0x9c
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _080D08CE
	b _080D09F8
_080D08CE:
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D08DA
	b _080D09F8
_080D08DA:
	ldr r1, _080D093C @ =0x00000446
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0
	adds r5, r0, #0
	cmp r1, #0
	beq _080D08F4
	ldr r1, _080D0940 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D08F4
	movs r2, #1
_080D08F4:
	cmp r2, #0
	beq _080D08FA
	b _080D09F8
_080D08FA:
	movs r2, #0xe5
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrh r0, [r0]
	bl FUN_080cfbcc
	cmp r0, #0
	beq _080D0960
	ldrh r0, [r5]
	movs r2, #0
	cmp r0, #0
	beq _080D091E
	ldr r1, _080D0940 @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D091E
	movs r2, #1
_080D091E:
	cmp r2, #0
	bne _080D0960
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D0944
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [sp]
	str r2, [sp, #4]
	movs r0, #0xca
	lsls r0, r0, #1
	b _080D094E
	.align 2, 0
_080D093C: .4byte 0x00000446
_080D0940: .4byte 0x00000442
_080D0944:
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [sp]
	str r2, [sp, #4]
	ldr r0, _080D095C @ =0x00000193
_080D094E:
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r2, #1
	movs r3, #1
	bl FUN_080d03bc
	b _080D09F8
	.align 2, 0
_080D095C: .4byte 0x00000193
_080D0960:
	cmp r6, #0
	bne _080D09F8
	ldrh r0, [r5]
	movs r1, #0
	cmp r0, #0
	beq _080D0978
	ldr r2, _080D0990 @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D0978
	movs r1, #1
_080D0978:
	cmp r1, #0
	beq _080D099E
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D0994
	ldr r0, [r4, #0x18]
	movs r1, #0xc8
	bl FUN_080cc3e4
	b _080D09F8
	.align 2, 0
_080D0990: .4byte 0x00000442
_080D0994:
	ldr r0, [r4, #0x18]
	movs r1, #0xc7
	bl FUN_080cc3e4
	b _080D09F8
_080D099E:
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09B4
	ldr r2, _080D09C8 @ =0x000001C7
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D09D6
_080D09B4:
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09CC
	ldr r0, [r4, #0x18]
	movs r1, #0xca
	bl FUN_080cc3e4
	b _080D09F8
	.align 2, 0
_080D09C8: .4byte 0x000001C7
_080D09CC:
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	bl FUN_080cc3e4
	b _080D09F8
_080D09D6:
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D09F0
	ldr r0, [r4, #0x18]
	ldr r1, _080D09EC @ =0x0000028E
	bl FUN_080cc3e4
	b _080D09F8
	.align 2, 0
_080D09EC: .4byte 0x0000028E
_080D09F0:
	ldr r0, [r4, #0x18]
	ldr r1, _080D0A00 @ =0x0000028D
	bl FUN_080cc3e4
_080D09F8:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D0A00: .4byte 0x0000028D

	thumb_func_start FUN_080d0a04
FUN_080d0a04: @ 0x080D0A04
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0xdf
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r4, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4, #0x20]
	adds r0, r4, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D0A70
	adds r0, r4, #0
	bl FUN_080d0790
	adds r5, r0, #0
	bl FUN_080d0890
	ldr r2, _080D0A9C @ =0x00000446
	adds r0, r4, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D0A5A
	subs r2, #4
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D0A5A
	movs r1, #1
_080D0A5A:
	cmp r1, #0
	beq _080D0A68
	adds r0, r4, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	muls r0, r5, r0
	asrs r5, r0, #6
_080D0A68:
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080cc268
_080D0A70:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_080d08b8
	adds r0, r4, #0
	bl FUN_080cc1a0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D0A9C: .4byte 0x00000446

	thumb_func_start FUN_080d0aa0
FUN_080d0aa0: @ 0x080D0AA0
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D0B30
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080ced68
	cmp r0, #0
	beq _080D0B1C
	ldr r0, [r4, #0x18]
	ldr r1, _080D0AD4 @ =0x00000392
	bl FUN_080cc3e4
	ldr r1, [r4, #0x18]
	ldr r0, _080D0AD8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D0ADC
	movs r0, #0
	b _080D0AE2
	.align 2, 0
_080D0AD4: .4byte 0x00000392
_080D0AD8: .4byte 0x03002C68
_080D0ADC:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D0AE2:
	lsls r0, r0, #1
	adds r0, #0xe
	movs r2, #0xff
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x20
	bls _080D0AFA
	movs r0, #0x20
	strb r0, [r1]
_080D0AFA:
	movs r0, #0x80
	lsls r0, r0, #2
	ldrb r1, [r1]
	bl Div
	ldr r3, _080D0B18 @ =0x000003FD
	adds r1, r4, r3
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080cc348
	b _080D0B30
	.align 2, 0
_080D0B18: .4byte 0x000003FD
_080D0B1C:
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	lsls r1, r1, #1
	bl FUN_080cc3e4
	adds r0, r4, #0
	movs r1, #2
	movs r2, #1
	bl FUN_080cc348
_080D0B30:
	ldr r1, _080D0B40 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D0B44
	cmp r0, #1
	beq _080D0BF8
	b _080D0C2C
	.align 2, 0
_080D0B40: .4byte 0x0000037D
_080D0B44:
	ldr r3, _080D0B68 @ =0x0000037E
	adds r2, r4, r3
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	adds r3, #0x7f
	adds r1, r4, r3
	ldrb r3, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, r3
	blo _080D0B6C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	b _080D0C2C
	.align 2, 0
_080D0B68: .4byte 0x0000037E
_080D0B6C:
	ldrh r1, [r2]
	adds r0, r3, #0
	subs r0, #8
	cmp r1, r0
	bge _080D0B88
	ldr r0, _080D0BEC @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D0BF0 @ =0x00000125
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_080D0B88:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D0BB4
	ldr r3, _080D0BF4 @ =0x000003CE
	adds r0, r4, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	bne _080D0BB4
	adds r0, r4, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
_080D0BB4:
	movs r3, #0xff
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrb r1, [r0]
	adds r0, r4, #0
	bl FUN_080cc268
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080d08b8
	adds r0, r4, #0
	bl FUN_080cc1a0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x20
	bl FUN_080cc1e8
	b _080D0C2C
	.align 2, 0
_080D0BEC: .4byte 0x0000095E
_080D0BF0: .4byte 0x00000125
_080D0BF4: .4byte 0x000003CE
_080D0BF8:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r3, _080D0C34 @ =0x0000037E
	adds r1, r4, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080D0C2C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D0C2C:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D0C34: .4byte 0x0000037E

	thumb_func_start FUN_080d0c38
FUN_080d0c38: @ 0x080D0C38
	push {lr}
	adds r1, r0, #0
	ldr r2, _080D0C50 @ =0x000003BD
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D0C4A
	cmp r0, #5
	bne _080D0C54
_080D0C4A:
	ldrh r1, [r1, #0x2c]
	b _080D0C56
	.align 2, 0
_080D0C50: .4byte 0x000003BD
_080D0C54:
	ldrh r1, [r1, #0x30]
_080D0C56:
	movs r0, #0xff
	ands r0, r1
	subs r0, #0x1f
	cmp r0, #0xc2
	bhi _080D0C64
	movs r0, #1
	b _080D0C66
_080D0C64:
	movs r0, #0
_080D0C66:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d0c6c
FUN_080d0c6c: @ 0x080D0C6C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x20
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	movs r1, #4
	strb r1, [r0]
	ldr r2, _080D0CBC @ =0x0000037D
	adds r0, r7, r2
	ldrb r1, [r0]
	cmp r1, #1
	bne _080D0CA8
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r7, r3
	ldr r0, [r0]
	ldrh r0, [r0, #2]
	ands r1, r0
	cmp r1, #0
	beq _080D0CA8
	adds r0, r7, #0
	movs r1, #4
	movs r2, #2
	bl FUN_080cc348
_080D0CA8:
	ldr r1, _080D0CBC @ =0x0000037D
	adds r0, r7, r1
	ldrb r4, [r0]
	cmp r4, #1
	beq _080D0D68
	cmp r4, #1
	bgt _080D0CC0
	cmp r4, #0
	beq _080D0CC8
	b _080D12F4
	.align 2, 0
_080D0CBC: .4byte 0x0000037D
_080D0CC0:
	cmp r4, #2
	bne _080D0CC6
	b _080D117E
_080D0CC6:
	b _080D12F4
_080D0CC8:
	movs r1, #4
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	movs r1, #2
	bl FUN_08066ee4
	mov sb, r0
	movs r3, #0xb9
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	cmp r0, sb
	beq _080D0D42
	ldr r0, [r7, #0x18]
	movs r1, #0xd0
	bl FUN_080cc3e4
	ldr r0, _080D0D2C @ =0x000003BD
	adds r2, r7, r0
	ldrb r0, [r2]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r3, #0xba
	lsls r3, r3, #2
	adds r1, r7, r3
	strb r0, [r1]
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D0D34
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D0D30 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	subs r3, #1
	adds r1, r7, r3
	movs r0, #1
	strb r0, [r1]
	b _080D0D42
	.align 2, 0
_080D0D2C: .4byte 0x000003BD
_080D0D30: .4byte 0x000002E6
_080D0D34:
	lsrs r0, r1, #0x19
	ldr r2, _080D0D60 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r3, _080D0D64 @ =0x000002E7
	adds r0, r7, r3
	strb r4, [r0]
_080D0D42:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D0D52
	b _080D12F4
_080D0D52:
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl FUN_080cc348
	b _080D12F4
	.align 2, 0
_080D0D60: .4byte 0x000002E6
_080D0D64: .4byte 0x000002E7
_080D0D68:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r7, r1
	strb r4, [r0]
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r7, r2
	movs r3, #0
	ldrsh r6, [r0, r3]
	ldr r0, _080D0DEC @ =0x000003BD
	adds r0, r0, r7
	mov r8, r0
	ldrb r0, [r0]
	adds r4, r0, #7
	movs r2, #7
	ands r4, r2
	adds r5, r0, #1
	ands r5, r2
	subs r1, #0x64
	adds r0, r7, r1
	ldrb r0, [r0]
	movs r1, #3
	str r2, [sp, #0x1c]
	bl FUN_08066ee4
	mov sb, r0
	ldr r2, [sp, #0x1c]
	cmp r6, r4
	beq _080D0DB0
	cmp r6, r5
	beq _080D0DB0
	b _080D1144
_080D0DB0:
	mov r3, r8
	ldrb r1, [r3]
	subs r0, r6, r1
	lsls r0, r0, #1
	adds r0, #8
	adds r1, r1, r0
	ands r1, r2
	adds r6, r1, #1
	ands r6, r2
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, _080D0DF0 @ =0x085B0A08
	lsls r0, r6, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	cmp r0, #0
	blt _080D0DF4
	asrs r2, r0, #0xc
	b _080D0DFA
	.align 2, 0
_080D0DEC: .4byte 0x000003BD
_080D0DF0: .4byte 0x085B0A08
_080D0DF4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0DFA:
	add r0, sp, #0xc
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D0E2C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r2, r6, #5
	movs r0, #0xff
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov sl, r2
	cmp r0, #0
	blt _080D0E30
	asrs r0, r0, #0xc
	b _080D0E36
	.align 2, 0
_080D0E2C: .4byte 0xFFFF0000
_080D0E30:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D0E36:
	add r3, sp, #0xc
	ldrh r1, [r3, #4]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D0E74 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r3, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D0E70
	cmp r1, #0
	blt _080D0E70
	ldr r0, _080D0E78 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0E70
	ldr r0, _080D0E7C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D0E80
_080D0E70:
	movs r6, #0
	b _080D0E8E
	.align 2, 0
_080D0E74: .4byte 0xFFFF0000
_080D0E78: .4byte 0x030046A8
_080D0E7C: .4byte 0x030046AC
_080D0E80:
	ldr r0, _080D0EBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r6, r0, r2
_080D0E8E:
	add r5, sp, #0xc
	adds r0, r5, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D0EB6
	cmp r1, #0
	blt _080D0EB6
	ldr r0, _080D0EC0 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0EB6
	ldr r0, _080D0EC4 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D0EC8
_080D0EB6:
	movs r4, #0
	b _080D0ED6
	.align 2, 0
_080D0EBC: .4byte 0x030046A4
_080D0EC0: .4byte 0x030046A8
_080D0EC4: .4byte 0x030046AC
_080D0EC8:
	ldr r0, _080D0EE8 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D0ED6:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D0EEC
	adds r0, #4
	b _080D0EF8
	.align 2, 0
_080D0EE8: .4byte 0x030046A4
_080D0EEC:
	ldr r0, _080D0F0C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D0EF8:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D0F10
	cmp r2, #2
	beq _080D0F14
	b _080D0F18
	.align 2, 0
_080D0F0C: .4byte 0x030046A4
_080D0F10:
	ldrb r0, [r5, #4]
	b _080D0F16
_080D0F14:
	ldrb r0, [r5]
_080D0F16:
	subs r1, r1, r0
_080D0F18:
	adds r5, r1, #0
	movs r0, #0x2e
	ldrsh r1, [r7, r0]
	adds r0, r1, #0
	subs r0, #0x80
	cmp r5, r0
	bgt _080D0F28
	b _080D1144
_080D0F28:
	adds r0, r1, #0
	adds r0, #0x80
	cmp r5, r0
	blt _080D0F32
	b _080D1144
_080D0F32:
	adds r0, r6, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D0F42
	adds r0, #4
	b _080D0F4E
_080D0F42:
	ldr r0, _080D0F88 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r6, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D0F4E:
	ldrh r0, [r0, #2]
	bl FUN_080cfc78
	cmp r0, #0
	beq _080D0F5A
	b _080D1144
_080D0F5A:
	ldr r2, _080D0F8C @ =0x085B0A08
	ldr r1, _080D0F90 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	cmp r0, #0
	blt _080D0F94
	asrs r1, r0, #0xc
	b _080D0F9A
	.align 2, 0
_080D0F88: .4byte 0x030046A4
_080D0F8C: .4byte 0x085B0A08
_080D0F90: .4byte 0x000003BD
_080D0F94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D0F9A:
	add r0, sp, #0xc
	ldrh r0, [r0]
	subs r0, r0, r1
	add r1, sp, #0xc
	strh r0, [r1]
	ldr r1, _080D0FC4 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D0FC8
	asrs r2, r0, #0xc
	b _080D0FCE
	.align 2, 0
_080D0FC4: .4byte 0x000003BD
_080D0FC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D0FCE:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	strh r1, [r0, #4]
	adds r6, r0, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	cmp r2, #0
	blt _080D0FFA
	cmp r1, #0
	blt _080D0FFA
	ldr r0, _080D1000 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D0FFA
	ldr r0, _080D1004 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D1008
_080D0FFA:
	movs r4, #0
	b _080D1016
	.align 2, 0
_080D1000: .4byte 0x030046A8
_080D1004: .4byte 0x030046AC
_080D1008:
	ldr r0, _080D1028 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D1016:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D102C
	adds r0, #4
	b _080D1038
	.align 2, 0
_080D1028: .4byte 0x030046A4
_080D102C:
	ldr r0, _080D104C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D1038:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D1050
	cmp r2, #2
	beq _080D1054
	b _080D1058
	.align 2, 0
_080D104C: .4byte 0x030046A4
_080D1050:
	ldrb r0, [r6, #4]
	b _080D1056
_080D1054:
	ldrb r0, [r6]
_080D1056:
	subs r1, r1, r0
_080D1058:
	adds r0, r5, #0
	adds r0, #0xc8
	cmp r1, r0
	blt _080D1144
	add r1, sp, #0xc
	adds r0, r1, #0
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D1088
	cmp r1, #0
	blt _080D1088
	ldr r0, _080D108C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D1088
	ldr r0, _080D1090 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D1094
_080D1088:
	movs r4, #0
	b _080D10A2
	.align 2, 0
_080D108C: .4byte 0x030046A8
_080D1090: .4byte 0x030046AC
_080D1094:
	ldr r0, _080D10B4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D10A2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D10B8
	adds r0, #4
	b _080D10C4
	.align 2, 0
_080D10B4: .4byte 0x030046A4
_080D10B8:
	ldr r0, _080D1110 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D10C4:
	ldrh r0, [r0, #2]
	movs r1, #4
	ands r0, r1
	cmp r0, #0
	bne _080D1144
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	bl FUN_08066ee4
	mov sb, r0
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	movs r3, #0
	cmp r0, #0
	beq _080D10F0
	movs r3, #3
	cmp r0, #2
	bne _080D10F0
	movs r3, #6
_080D10F0:
	ldr r2, _080D1114 @ =0x085B0A08
	mov r0, sl
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov r8, r2
	cmp r0, #0
	blt _080D1118
	asrs r0, r0, #0xc
	b _080D111E
	.align 2, 0
_080D1110: .4byte 0x030046A4
_080D1114: .4byte 0x085B0A08
_080D1118:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D111E:
	rsbs r0, r0, #0
	strh r0, [r7, #0x34]
	movs r0, #0xff
	mov r2, sl
	ands r0, r2
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D113A
	asrs r0, r0, #0xc
	b _080D1140
_080D113A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1140:
	rsbs r0, r0, #0
	strh r0, [r7, #0x38]
_080D1144:
	adds r0, r7, #0
	mov r1, sb
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xb9
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0x18
	beq _080D115C
	b _080D12F4
_080D115C:
	adds r0, r7, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D1168
	b _080D12F4
_080D1168:
	adds r0, r7, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	beq _080D1174
	b _080D12F4
_080D1174:
	ldr r0, [r7, #0x18]
	movs r1, #0xdb
	bl FUN_080cc3e4
	b _080D12F4
_080D117E:
	movs r1, #8
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	movs r1, #5
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r7, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D11A4
	b _080D12F4
_080D11A4:
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0x14]
	str r1, [sp, #0x18]
	ldr r1, _080D11DC @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D11E8
	add r3, sp, #0x14
	ldrh r0, [r3]
	adds r0, #0x1c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D11E0 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _080D11E4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r3, #4]
	subs r0, #0x4c
	b _080D1248
	.align 2, 0
_080D11DC: .4byte 0x000003BD
_080D11E0: .4byte 0xFFFF0000
_080D11E4: .4byte 0x0000FFFF
_080D11E8:
	cmp r0, #3
	bne _080D1220
	add r3, sp, #0x14
	ldrh r0, [r3]
	subs r0, #0x34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D1218 @ =0xFFFF0000
	ldr r1, [sp, #0x14]
	ands r1, r4
	orrs r1, r0
	lsrs r2, r1, #0x10
	lsls r2, r2, #0x10
	ldr r0, _080D121C @ =0x0000FFFF
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #0x14]
	ldrh r1, [r3, #4]
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r1
	str r0, [r3, #4]
	adds r4, r3, #0
	b _080D1294
	.align 2, 0
_080D1218: .4byte 0xFFFF0000
_080D121C: .4byte 0x0000FFFF
_080D1220:
	cmp r0, #5
	bne _080D1260
	add r3, sp, #0x14
	ldrh r0, [r3]
	adds r0, #0xc
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080D1258 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r4
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x2c
	lsls r1, r1, #0x10
	ldr r0, _080D125C @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r3, #4]
	subs r0, #0x20
_080D1248:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r4
	orrs r1, r0
	str r1, [r3, #4]
	adds r4, r3, #0
	b _080D1294
	.align 2, 0
_080D1258: .4byte 0xFFFF0000
_080D125C: .4byte 0x0000FFFF
_080D1260:
	add r4, sp, #0x14
	cmp r0, #7
	bne _080D1294
	ldrh r0, [r4]
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r3, _080D1304 @ =0xFFFF0000
	ldr r2, [sp, #0x14]
	ands r2, r3
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x44
	lsls r1, r1, #0x10
	ldr r0, _080D1308 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
	ldrh r0, [r4, #4]
	adds r0, #0x2c
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r4, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r4, #4]
_080D1294:
	ldr r2, _080D130C @ =0x085B0A08
	ldr r3, _080D1310 @ =0x000003BD
	adds r0, r7, r3
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x32
	muls r0, r1, r0
	mov r8, r2
	ldr r1, _080D1310 @ =0x000003BD
	adds r0, r7, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #6
	add r0, r8
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	adds r1, r7, #0
	adds r1, #0x2c
	movs r2, #0x80
	lsls r2, r2, #1
	str r4, [sp]
	movs r0, #0
	str r0, [sp, #4]
	movs r0, #0xec
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r3, #1
	bl FUN_080d03bc
	adds r0, r7, #0
	movs r1, #4
	movs r2, #1
	bl FUN_080cc348
_080D12F4:
	add sp, #0x20
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1304: .4byte 0xFFFF0000
_080D1308: .4byte 0x0000FFFF
_080D130C: .4byte 0x085B0A08
_080D1310: .4byte 0x000003BD

	thumb_func_start FUN_080d1314
FUN_080d1314: @ 0x080D1314
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _080D133C
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _080D1338 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080D133C
	movs r0, #1
	b _080D133E
	.align 2, 0
_080D1338: .4byte 0x0000036A
_080D133C:
	movs r0, #0
_080D133E:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d1344
FUN_080d1344: @ 0x080D1344
	push {lr}
	adds r3, r0, #0
	movs r0, #0x93
	lsls r0, r0, #4
	adds r2, r3, r0
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r3, r1
	ldrb r0, [r0]
	cmp r0, #4
	bne _080D138C
	ldrh r0, [r2]
	subs r0, #0x14
	strh r0, [r2]
	ldr r2, _080D1384 @ =0x00000932
	adds r1, r3, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080D1388 @ =0x00000934
	adds r1, r3, r0
	ldrh r0, [r1]
	adds r0, #0x3c
	b _080D13AA
	.align 2, 0
_080D1384: .4byte 0x00000932
_080D1388: .4byte 0x00000934
_080D138C:
	ldrh r0, [r2]
	adds r0, #0x14
	strh r0, [r2]
	ldr r2, _080D13B0 @ =0x00000932
	adds r1, r3, r2
	movs r2, #0xa5
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r0, _080D13B4 @ =0x00000934
	adds r1, r3, r0
	ldrh r0, [r1]
	subs r0, #0x1e
_080D13AA:
	strh r0, [r1]
	pop {r0}
	bx r0
	.align 2, 0
_080D13B0: .4byte 0x00000932
_080D13B4: .4byte 0x00000934

	thumb_func_start FUN_080d13b8
FUN_080d13b8: @ 0x080D13B8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080D13DA
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_080cc348
	ldr r2, _080D13F0 @ =0x00000951
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
_080D13DA:
	ldr r1, _080D13F4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D13E6
	b _080D169A
_080D13E6:
	lsls r0, r0, #2
	ldr r1, _080D13F8 @ =_080D13FC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D13F0: .4byte 0x00000951
_080D13F4: .4byte 0x0000037D
_080D13F8: .4byte _080D13FC
_080D13FC: @ jump table
	.4byte _080D1410 @ case 0
	.4byte _080D1434 @ case 1
	.4byte _080D150C @ case 2
	.4byte _080D15D4 @ case 3
	.4byte _080D1654 @ case 4
_080D1410:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_080cc348
	b _080D169A
_080D1434:
	ldr r1, _080D1460 @ =0x0000037E
	adds r0, r4, r1
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D148A
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080D146C
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080D1464 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080D1468 @ =0x000002E7
	b _080D1476
	.align 2, 0
_080D1460: .4byte 0x0000037E
_080D1464: .4byte 0x000002E6
_080D1468: .4byte 0x000002E7
_080D146C:
	strb r2, [r1]
	ldr r1, _080D14F0 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080D1476:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_080d1344
	ldr r2, _080D14F4 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080D148A:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D14B2
	b _080D169A
_080D14B2:
	ldr r0, [r4, #0x18]
	movs r1, #0xcb
	bl FUN_080cc3e4
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D14CE
	b _080D1610
_080D14CE:
	adds r0, r4, #0
	bl FUN_080d1314
	adds r1, r0, #0
	cmp r1, #0
	beq _080D1500
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc3e4
	ldr r0, _080D14F8 @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D14FC @ =0x00000404
	adds r1, r4, r2
	b _080D163A
	.align 2, 0
_080D14F0: .4byte 0x000002E6
_080D14F4: .4byte 0x0000037E
_080D14F8: .4byte 0x00000409
_080D14FC: .4byte 0x00000404
_080D1500:
	ldr r2, _080D1508 @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _080D15C4
	.align 2, 0
_080D1508: .4byte 0x00000404
_080D150C:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _080D1540 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080D154E
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080D154E
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1544
	ldr r0, [r4, #0x18]
	subs r1, #0x50
	bl FUN_080cc3e4
	b _080D154E
	.align 2, 0
_080D1540: .4byte 0x00000404
_080D1544:
	ldr r0, [r4, #0x18]
	movs r1, #0x94
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D154E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r5, #0
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1344
	movs r2, #0x93
	lsls r2, r2, #4
	adds r1, r4, r2
	adds r0, r4, #0
	bl FUN_080cd230
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D15AC
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc410
	ldr r2, _080D15A8 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080D1610
	.align 2, 0
_080D15A8: .4byte 0x00000409
_080D15AC:
	adds r0, r4, #0
	bl FUN_080d1314
	cmp r0, #0
	bne _080D169A
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc410
	ldr r1, _080D15D0 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_080D15C4:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_080cc348
	b _080D169A
	.align 2, 0
_080D15D0: .4byte 0x00000409
_080D15D4:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D161C
_080D1610:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_080cc348
	b _080D169A
_080D161C:
	adds r0, r4, #0
	bl FUN_080d1314
	cmp r0, #0
	beq _080D169A
	ldr r0, [r4, #0x18]
	movs r1, #0xd8
	bl FUN_080cc3e4
	ldr r2, _080D164C @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D1650 @ =0x00000404
	adds r1, r4, r0
_080D163A:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_080cc348
	b _080D169A
	.align 2, 0
_080D164C: .4byte 0x00000409
_080D1650: .4byte 0x00000404
_080D1654:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D169A
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080D16A0 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D169A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D16A0: .4byte 0x000002E7

	thumb_func_start FUN_080d16a4
FUN_080d16a4: @ 0x080D16A4
	push {lr}
	adds r2, r0, #0
	movs r1, #0x10
	ldr r0, [r2, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _080D16CC
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r3, _080D16C8 @ =0x0000036A
	adds r1, r2, r3
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _080D16CC
	movs r0, #1
	b _080D16CE
	.align 2, 0
_080D16C8: .4byte 0x0000036A
_080D16CC:
	movs r0, #0
_080D16CE:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d16d4
FUN_080d16d4: @ 0x080D16D4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #7
	beq _080D16EE
	adds r0, r4, #0
	movs r1, #7
	movs r2, #0
	bl FUN_080cc348
_080D16EE:
	ldr r2, _080D1704 @ =0x0000037D
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D16FA
	b _080D19F2
_080D16FA:
	lsls r0, r0, #2
	ldr r1, _080D1708 @ =_080D170C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D1704: .4byte 0x0000037D
_080D1708: .4byte _080D170C
_080D170C: @ jump table
	.4byte _080D1720 @ case 0
	.4byte _080D1744 @ case 1
	.4byte _080D1820 @ case 2
	.4byte _080D1928 @ case 3
	.4byte _080D19AC @ case 4
_080D1720:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r0, r4, #0
	movs r1, #7
	movs r2, #1
	bl FUN_080cc348
	b _080D19F2
_080D1744:
	ldr r2, _080D1770 @ =0x0000037E
	adds r0, r4, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D179A
	movs r0, #0xba
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrb r0, [r1]
	subs r0, #2
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #4
	bhi _080D177C
	movs r0, #4
	strb r0, [r1]
	ldr r0, _080D1774 @ =0x000002E6
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _080D1778 @ =0x000002E7
	b _080D1786
	.align 2, 0
_080D1770: .4byte 0x0000037E
_080D1774: .4byte 0x000002E6
_080D1778: .4byte 0x000002E7
_080D177C:
	strb r2, [r1]
	ldr r1, _080D1804 @ =0x000002E6
	adds r0, r4, r1
	strb r2, [r0]
	adds r1, #1
_080D1786:
	adds r0, r4, r1
	strb r2, [r0]
	adds r0, r4, #0
	bl FUN_080d1344
	ldr r2, _080D1808 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080D179A:
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #8
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D17C2
	b _080D19F2
_080D17C2:
	ldr r0, [r4, #0x18]
	movs r1, #0xcb
	bl FUN_080cc3e4
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D17DE
	b _080D1964
_080D17DE:
	adds r0, r4, #0
	bl FUN_080d16a4
	adds r1, r0, #0
	cmp r1, #0
	beq _080D1814
	ldr r0, [r4, #0x18]
	movs r1, #0xb9
	lsls r1, r1, #2
	bl FUN_080cc3e4
	ldr r0, _080D180C @ =0x00000409
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D1810 @ =0x00000404
	adds r1, r4, r2
	b _080D198E
	.align 2, 0
_080D1804: .4byte 0x000002E6
_080D1808: .4byte 0x0000037E
_080D180C: .4byte 0x00000409
_080D1810: .4byte 0x00000404
_080D1814:
	ldr r2, _080D181C @ =0x00000404
	adds r0, r4, r2
	strh r1, [r0]
	b _080D1914
	.align 2, 0
_080D181C: .4byte 0x00000404
_080D1820:
	movs r1, #0xa0
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	ldr r0, _080D1898 @ =0x00000404
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #4
	bhi _080D1846
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bne _080D1846
	ldr r0, [r4, #0x18]
	ldr r1, _080D189C @ =0x00000239
	bl FUN_080cc3e4
_080D1846:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #9
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0x1e
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1344
	movs r0, #0x93
	lsls r0, r0, #4
	adds r1, r4, r0
	adds r0, r4, #0
	bl FUN_080cd3c0
	ldr r2, _080D18A0 @ =0x0000095E
	adds r1, r4, r2
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	ldr r1, _080D18A4 @ =0x0000037E
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0x1f
	bhi _080D18A8
	adds r2, #2
	adds r0, r4, r2
	strh r1, [r0]
	b _080D18B4
	.align 2, 0
_080D1898: .4byte 0x00000404
_080D189C: .4byte 0x00000239
_080D18A0: .4byte 0x0000095E
_080D18A4: .4byte 0x0000037E
_080D18A8:
	movs r0, #0x40
	subs r0, r0, r1
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	strh r0, [r1]
_080D18B4:
	ldr r0, _080D18F0 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	movs r5, #0
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x40
	bls _080D18CC
	movs r0, #0
	strh r0, [r1]
_080D18CC:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D18FC
	ldr r0, [r4, #0x18]
	ldr r1, _080D18F4 @ =0x00000239
	bl FUN_080cc410
	ldr r2, _080D18F8 @ =0x00000409
	adds r0, r4, r2
	strb r5, [r0]
	b _080D1964
	.align 2, 0
_080D18F0: .4byte 0x0000037E
_080D18F4: .4byte 0x00000239
_080D18F8: .4byte 0x00000409
_080D18FC:
	adds r0, r4, #0
	bl FUN_080d16a4
	cmp r0, #0
	bne _080D19F2
	ldr r0, [r4, #0x18]
	ldr r1, _080D1920 @ =0x00000239
	bl FUN_080cc410
	ldr r1, _080D1924 @ =0x00000409
	adds r0, r4, r1
	strb r5, [r0]
_080D1914:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #3
	bl FUN_080cc348
	b _080D19F2
	.align 2, 0
_080D1920: .4byte 0x00000239
_080D1924: .4byte 0x00000409
_080D1928:
	movs r1, #0x80
	ldr r0, [r4, #0x20]
	orrs r0, r1
	str r0, [r4, #0x20]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0xa
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r0, #0xc1
	lsls r0, r0, #3
	adds r1, r4, r0
	movs r0, #0x1e
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D1970
_080D1964:
	adds r0, r4, #0
	movs r1, #7
	movs r2, #4
	bl FUN_080cc348
	b _080D19F2
_080D1970:
	adds r0, r4, #0
	bl FUN_080d16a4
	cmp r0, #0
	beq _080D19F2
	ldr r0, [r4, #0x18]
	ldr r1, _080D19A0 @ =0x00000239
	bl FUN_080cc3e4
	ldr r2, _080D19A4 @ =0x00000409
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D19A8 @ =0x00000404
	adds r1, r4, r0
_080D198E:
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #7
	movs r2, #2
	bl FUN_080cc348
	b _080D19F2
	.align 2, 0
_080D19A0: .4byte 0x00000239
_080D19A4: .4byte 0x00000409
_080D19A8: .4byte 0x00000404
_080D19AC:
	movs r2, #0xc1
	lsls r2, r2, #3
	adds r1, r4, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0xb
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D19F2
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	subs r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldr r0, _080D19F8 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D19F2:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D19F8: .4byte 0x000002E7

	thumb_func_start FUN_080d19fc
FUN_080d19fc: @ 0x080D19FC
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D1A30
	ldr r1, _080D1A40 @ =0x000003CE
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _080D1A30
	adds r0, r4, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r4, r2
	strb r0, [r1]
	movs r5, #1
_080D1A30:
	adds r0, r4, #0
	bl FUN_080cc1a0
	adds r0, r5, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_080D1A40: .4byte 0x000003CE

	thumb_func_start FUN_080d1a44
FUN_080d1a44: @ 0x080D1A44
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080ced00
	adds r1, r0, #0
	ldr r2, _080D1A64 @ =0x00000A8D
	adds r0, r4, r2
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _080D1A6C
	adds r1, #1
	ldr r2, _080D1A68 @ =0x00000951
	adds r0, r4, r2
	strb r1, [r0]
	b _080D1A74
	.align 2, 0
_080D1A64: .4byte 0x00000A8D
_080D1A68: .4byte 0x00000951
_080D1A6C:
	ldr r0, _080D1A7C @ =0x00000951
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
_080D1A74:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D1A7C: .4byte 0x00000951

	thumb_func_start FUN_080d1a80
FUN_080d1a80: @ 0x080D1A80
	push {r4, lr}
	adds r4, r0, #0
	ldr r2, _080D1A98 @ =0x00000A75
	adds r1, r4, r2
	ldrb r1, [r1]
	cmp r1, #3
	beq _080D1AD0
	cmp r1, #3
	ble _080D1A9C
	cmp r1, #4
	beq _080D1AE0
	b _080D1AF8
	.align 2, 0
_080D1A98: .4byte 0x00000A75
_080D1A9C:
	cmp r1, #0
	blt _080D1AF8
	movs r3, #0xd8
	lsls r3, r3, #2
	adds r0, r4, r3
	ldrh r0, [r0]
	adds r0, #0x63
	asrs r2, r0, #1
	ldr r0, _080D1AC8 @ =0x00000A78
	adds r1, r4, r0
	ldr r3, _080D1ACC @ =0x00000A96
	adds r0, r4, r3
	movs r3, #0
	ldrsh r0, [r0, r3]
	ldrh r1, [r1]
	adds r0, r0, r1
	cmp r0, #0
	bge _080D1AC2
	movs r0, #0
_080D1AC2:
	adds r0, r2, r0
	b _080D1AF8
	.align 2, 0
_080D1AC8: .4byte 0x00000A78
_080D1ACC: .4byte 0x00000A96
_080D1AD0:
	movs r1, #0xd8
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	lsrs r0, r0, #1
	adds r0, #0x63
	asrs r0, r0, #1
	b _080D1AF8
_080D1AE0:
	movs r0, #0x28
	movs r1, #0xa
	bl Div
	ldr r3, _080D1B00 @ =0x00000A78
	adds r2, r4, r3
	subs r0, #8
	lsls r1, r0, #2
	adds r1, r1, r0
	ldrh r2, [r2]
	adds r0, r1, r2
	lsls r0, r0, #1
_080D1AF8:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D1B00: .4byte 0x00000A78

	thumb_func_start FUN_080d1b04
FUN_080d1b04: @ 0x080D1B04
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	bl FUN_080d1a80
	adds r5, r0, #0
	movs r7, #0
	ldr r0, _080D1B34 @ =0x00000A9C
	adds r4, r6, r0
_080D1B14:
	ldr r1, [r4]
	cmp r1, #0
	beq _080D1B22
	adds r0, r6, #0
	bl _call_via_r1
	adds r5, r5, r0
_080D1B22:
	adds r4, #4
	adds r7, #1
	cmp r7, #2
	ble _080D1B14
	adds r0, r5, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D1B34: .4byte 0x00000A9C

	thumb_func_start FUN_080d1b38
FUN_080d1b38: @ 0x080D1B38
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r7, #0
	movs r6, #0
	ldr r0, _080D1B64 @ =0x00000AA8
	adds r4, r5, r0
_080D1B44:
	ldr r1, [r4]
	cmp r1, #0
	beq _080D1B52
	adds r0, r5, #0
	bl _call_via_r1
	orrs r7, r0
_080D1B52:
	adds r4, #4
	adds r6, #1
	cmp r6, #2
	ble _080D1B44
	adds r0, r7, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D1B64: .4byte 0x00000AA8

	thumb_func_start FUN_080d1b68
FUN_080d1b68: @ 0x080D1B68
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r1, #0
	movs r1, #0x1f
	ldrh r0, [r6, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080D1BF8
	ldr r5, [r7, #0x4c]
	adds r0, r7, #0
	adds r1, r6, #0
	bl Hitbox_ApplyDamageAlt
	movs r4, #0
_080D1B84:
	lsls r1, r4, #2
	ldr r2, _080D1C00 @ =0x00000AB4
	adds r0, r5, r2
	adds r0, r0, r1
	ldr r3, [r0]
	cmp r3, #0
	beq _080D1BA2
	adds r0, r5, #0
	adds r1, r7, #0
	adds r2, r6, #0
	bl _call_via_r3
	ldrh r1, [r6, #0x3e]
	adds r1, r1, r0
	strh r1, [r6, #0x3e]
_080D1BA2:
	adds r4, #1
	cmp r4, #2
	ble _080D1B84
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1BF8
	ldr r2, _080D1C04 @ =0x00000A8D
	adds r0, r5, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #1
	bne _080D1BF8
	adds r0, r5, #0
	bl FUN_080cc618
	cmp r0, #0
	beq _080D1BF8
	adds r2, r6, #0
	adds r2, #0x43
	ldrb r1, [r2]
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	bne _080D1BF8
	ldrh r1, [r6, #0x3e]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsrs r0, r0, #1
	strh r0, [r6, #0x3e]
	ldrh r1, [r6, #6]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D1BF8
	ldrb r1, [r2]
	movs r0, #8
	orrs r0, r1
	strb r0, [r2]
_080D1BF8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1C00: .4byte 0x00000AB4
_080D1C04: .4byte 0x00000A8D

	thumb_func_start FUN_080d1c08
FUN_080d1c08: @ 0x080D1C08
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D1C88 @ =0x000009C8
	adds r6, r4, r0
	ldr r1, _080D1C8C @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D1C90 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1b04
	mov r8, r0
	adds r0, r4, #0
	bl FUN_080d1b38
	adds r5, r0, #0
	ldr r1, _080D1C94 @ =0x00000A7E
	adds r0, r4, r1
	ldrh r7, [r0]
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D1CA0
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _080D1C98 @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _080D1C9C @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r5, r0
	b _080D1CEC
	.align 2, 0
_080D1C88: .4byte 0x000009C8
_080D1C8C: .4byte 0x00000A68
_080D1C90: .4byte 0x00000A6A
_080D1C94: .4byte 0x00000A7E
_080D1C98: .4byte 0x00000A84
_080D1C9C: .4byte 0x00000A88
_080D1CA0:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D1CD4
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0xc
	strh r0, [r1]
	ldr r2, _080D1CCC @ =0x00000A84
	adds r1, r4, r2
	movs r0, #5
	strh r0, [r1]
	ldr r0, _080D1CD0 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #3
	b _080D1CEA
	.align 2, 0
_080D1CCC: .4byte 0x00000A84
_080D1CD0: .4byte 0x00000A88
_080D1CD4:
	movs r1, #0xa8
	lsls r1, r1, #4
	adds r0, r4, r1
	movs r1, #8
	strh r1, [r0]
	ldr r2, _080D1D3C @ =0x00000A84
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080D1D40 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #4
_080D1CEA:
	strh r0, [r1]
_080D1CEC:
	adds r1, r6, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D1D06
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r5, r0
	adds r0, r4, #0
	bl FUN_080cec18
_080D1D06:
	adds r0, r6, #0
	adds r0, #0x48
	adds r1, r6, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r5, [sp]
	str r7, [sp, #4]
	mov r1, r8
	movs r3, #1
	bl Hitbox_SetAttack
	adds r0, r6, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r2, r6, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r6, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1D3C: .4byte 0x00000A84
_080D1D40: .4byte 0x00000A88

	thumb_func_start FUN_080d1d44
FUN_080d1d44: @ 0x080D1D44
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	mov ip, r0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r2, _080D1D8C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080D1D90 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080D1D94 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r3, r0, #0
	adds r3, #0x70
	ldr r2, _080D1D98 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _080D1D9C
	asrs r1, r0, #0xc
	b _080D1DA2
	.align 2, 0
_080D1D8C: .4byte 0x030046B8
_080D1D90: .4byte 0x000003FF
_080D1D94: .4byte 0x0203B400
_080D1D98: .4byte 0x085B0A08
_080D1D9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D1DA2:
	ldrh r0, [r4]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldrh r1, [r4, #2]
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D1DC8
	asrs r0, r0, #0xc
	b _080D1DCE
_080D1DC8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1DCE:
	ldrh r1, [r4, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D1DFC @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	movs r0, #0xff
	ands r0, r5
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D1E00
	asrs r0, r0, #0xc
	b _080D1E06
	.align 2, 0
_080D1DFC: .4byte 0xFFFF0000
_080D1E00:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1E06:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080D1E2A
	asrs r0, r0, #0xc
	b _080D1E30
_080D1E2A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D1E30:
	rsbs r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080D1E78 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	cmp r7, #0
	beq _080D1E66
	ldrh r0, [r2]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	ldrh r0, [r2, #4]
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r2, #4]
	ands r1, r3
	orrs r1, r0
	str r1, [r2, #4]
_080D1E66:
	mov r0, ip
	mov r1, sp
	ldr r3, [sp, #0x24]
	bl FUN_080ccfe4
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D1E78: .4byte 0xFFFF0000

	thumb_func_start FUN_080d1e7c
FUN_080d1e7c: @ 0x080D1E7C
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _080D1EB0 @ =0x000009C8
	adds r5, r7, r0
	ldr r1, _080D1EB4 @ =0x00000A8A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D1EC0
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D1EB8
	ldr r0, [r7, #0x18]
	movs r1, #0xe3
	lsls r1, r1, #2
	bl FUN_080cc3e4
	b _080D1EC0
	.align 2, 0
_080D1EB0: .4byte 0x000009C8
_080D1EB4: .4byte 0x00000A8A
_080D1EB8:
	ldr r0, [r7, #0x18]
	ldr r1, _080D1F04 @ =0x0000038B
	bl FUN_080cc3e4
_080D1EC0:
	adds r0, r5, #0
	adds r0, #0xc2
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	adds r2, r5, #0
	adds r2, #0xbc
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r0
	ldrh r2, [r2]
	cmp r1, r2
	bls _080D1EDC
	b _080D1FF8
_080D1EDC:
	ldr r4, _080D1F08 @ =0x000002E7
	adds r0, r7, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D1F0C
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r1, [r0]
	mov r0, r8
	ldrh r2, [r0]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r2, r0
	subs r1, r1, r0
	movs r3, #0x90
	lsls r3, r3, #1
	adds r6, r1, r3
	b _080D1F2A
	.align 2, 0
_080D1F04: .4byte 0x0000038B
_080D1F08: .4byte 0x000002E7
_080D1F0C:
	adds r2, r5, #0
	adds r2, #0xc4
	mov r4, r8
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r1, r0
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r2, [r2]
	adds r0, r0, r2
	adds r6, r0, #0
	subs r6, #0x20
_080D1F2A:
	movs r0, #0xff
	ands r6, r0
	ldr r2, _080D1F50 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	adds r4, r2, #0
	cmp r0, #0
	blt _080D1F54
	asrs r1, r0, #0xc
	b _080D1F5A
	.align 2, 0
_080D1F50: .4byte 0x085B0A08
_080D1F54:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D1F5A:
	adds r3, r5, #0
	adds r3, #0xa0
	ldrh r0, [r3]
	adds r0, r0, r1
	adds r2, r5, #0
	adds r2, #0x98
	strh r0, [r2]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, r5, #0
	adds r1, #0x9a
	strh r0, [r1]
	lsls r0, r6, #1
	adds r0, r0, r4
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #5
	mov sb, r3
	adds r3, r2, #0
	cmp r0, #0
	blt _080D1F8E
	asrs r2, r0, #0xc
	b _080D1F94
_080D1F8E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D1F94:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r2, r5, #0
	adds r2, #0xc5
	movs r0, #0
	ldrsb r0, [r2, r0]
	cmp r0, #0
	blt _080D1FEE
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r7, #0x20]
	orrs r0, r1
	str r0, [r7, #0x20]
	mov r0, r8
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D1FEE
	ldr r1, _080D1FF4 @ =0x000002E7
	adds r0, r7, r1
	ldrb r3, [r0]
	movs r0, #0
	ldrsb r0, [r2, r0]
	str r0, [sp]
	adds r0, r7, #0
	mov r1, sb
	adds r2, r6, #0
	bl FUN_080d1d44
_080D1FEE:
	movs r0, #0
	b _080D1FFA
	.align 2, 0
_080D1FF4: .4byte 0x000002E7
_080D1FF8:
	movs r0, #1
_080D1FFA:
	add sp, #4
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d2008
FUN_080d2008: @ 0x080D2008
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D202A
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D202E
_080D202A:
	movs r6, #0x30
	b _080D2030
_080D202E:
	movs r6, #0x40
_080D2030:
	ldr r3, _080D2044 @ =0x0000037D
	adds r4, r5, r3
	ldrb r0, [r4]
	cmp r0, #1
	beq _080D2084
	cmp r0, #1
	bgt _080D2048
	cmp r0, #0
	beq _080D2054
	b _080D21C2
	.align 2, 0
_080D2044: .4byte 0x0000037D
_080D2048:
	cmp r0, #4
	beq _080D20DC
	cmp r0, #6
	bne _080D2052
	b _080D2160
_080D2052:
	b _080D21C2
_080D2054:
	adds r0, r5, #0
	bl FUN_080d1a44
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x15
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D2078
	b _080D21C2
_080D2078:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D21C2
_080D2084:
	adds r0, r5, #0
	bl FUN_080d1a44
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x16
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D20CC
	adds r0, r5, #0
	bl FUN_080d1c08
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D21C2
_080D20CC:
	ldr r0, _080D20D8 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D21C2
	.align 2, 0
_080D20D8: .4byte 0x0000037E
_080D20DC:
	ldr r2, _080D2158 @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D20FE
	ldr r0, _080D215C @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D20FE:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	movs r1, #0x17
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_080cc1e8
	ldrb r0, [r4]
	cmp r0, #1
	bne _080D2142
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #2
	bne _080D2142
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2142
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	bl FUN_080ccb20
_080D2142:
	adds r0, r5, #0
	bl FUN_080d1e7c
	cmp r0, #0
	beq _080D21C2
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D21C2
	.align 2, 0
_080D2158: .4byte 0x000003D1
_080D215C: .4byte 0x00000A76
_080D2160:
	ldr r3, _080D2194 @ =0x000003D1
	adds r0, r5, r3
	movs r3, #0
	strb r3, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2182
	ldr r2, _080D2198 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D2182:
	ldr r0, _080D2198 @ =0x00000A76
	adds r2, r5, r0
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D219C
	strb r3, [r2]
	strb r3, [r4]
	b _080D21C2
	.align 2, 0
_080D2194: .4byte 0x000003D1
_080D2198: .4byte 0x00000A76
_080D219C:
	ldr r1, _080D21C8 @ =0x0000037E
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	ldr r3, _080D21CC @ =0x00000A88
	adds r0, r5, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrh r0, [r0]
	cmp r1, r0
	blo _080D21C2
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D21C2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D21C8: .4byte 0x0000037E
_080D21CC: .4byte 0x00000A88

	thumb_func_start FUN_080d21d0
FUN_080d21d0: @ 0x080D21D0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r1, #0
	adds r6, r2, #0
	ldr r2, _080D21F4 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D21F8
	asrs r1, r0, #0xc
	b _080D21FE
	.align 2, 0
_080D21F4: .4byte 0x085B0A08
_080D21F8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D21FE:
	ldrh r0, [r4]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r4, #2]
	strh r0, [r5, #2]
	movs r0, #0xff
	ands r0, r6
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D221E
	asrs r1, r0, #0xc
	b _080D2224
_080D221E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2224:
	ldrh r0, [r4, #4]
	adds r0, r0, r1
	strh r0, [r5, #4]
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d2230
FUN_080d2230: @ 0x080D2230
	push {lr}
	adds r3, r1, #0
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	lsrs r1, r1, #4
	cmp r1, #1
	beq _080D2248
	cmp r1, #2
	beq _080D224C
	b _080D2250
_080D2248:
	ldrb r0, [r3, #4]
	b _080D224E
_080D224C:
	ldrb r0, [r3]
_080D224E:
	subs r2, r2, r0
_080D2250:
	adds r0, r2, #0
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d2258
FUN_080d2258: @ 0x080D2258
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	adds r5, r1, #0
	adds r3, r2, #0
	mov r6, sp
	mov r0, sp
	adds r1, r4, #0
	adds r2, r5, #0
	bl FUN_080d21d0
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080D2294
	cmp r1, #0
	blt _080D2294
	ldr r0, _080D229C @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080D2294
	ldr r0, _080D22A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D22A8
_080D2294:
	movs r4, #0
	ldr r2, _080D22A4 @ =0x030046A4
	b _080D22B6
	.align 2, 0
_080D229C: .4byte 0x030046A8
_080D22A0: .4byte 0x030046AC
_080D22A4: .4byte 0x030046A4
_080D22A8:
	ldr r2, _080D22C4 @ =0x030046A4
	ldr r0, [r2]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080D22B6:
	ldr r0, [r2]
	ldr r2, [r0, #4]
	cmp r2, #0
	bne _080D22C8
	movs r0, #0
	b _080D22CE
	.align 2, 0
_080D22C4: .4byte 0x030046A4
_080D22C8:
	lsls r0, r4, #2
	adds r0, #0xc
	adds r0, r2, r0
_080D22CE:
	mov r5, sp
	mov r1, sp
	bl FUN_080d2230
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080D22E2
	movs r0, #1
	b _080D2304
_080D22E2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D2302
	adds r0, #4
	mov r1, sp
	bl FUN_080d2230
	movs r2, #2
	ldrsh r1, [r5, r2]
	cmp r0, r1
	ble _080D2302
	movs r0, #2
	b _080D2304
_080D2302:
	movs r0, #0
_080D2304:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d230c
FUN_080d230c: @ 0x080D230C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x10
	adds r5, r0, #0
	ldr r0, _080D236C @ =0x000009C8
	adds r4, r5, r0
	ldr r1, _080D2370 @ =0x00000A68
	adds r2, r5, r1
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D2374 @ =0x00000A6A
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #0x96
	strh r0, [r1]
	movs r3, #0xba
	lsls r3, r3, #2
	adds r0, r5, r3
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r6, _080D2378 @ =0x00000A8C
	adds r1, r5, r6
	strb r0, [r1]
	ldr r2, _080D237C @ =0x085B0A08
	ldrb r0, [r1]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xcc
	muls r0, r1, r0
	adds r6, r2, #0
	cmp r0, #0
	blt _080D2380
	asrs r1, r0, #0xc
	b _080D2386
	.align 2, 0
_080D236C: .4byte 0x000009C8
_080D2370: .4byte 0x00000A68
_080D2374: .4byte 0x00000A6A
_080D2378: .4byte 0x00000A8C
_080D237C: .4byte 0x085B0A08
_080D2380:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2386:
	adds r3, r4, #0
	adds r3, #0xa0
	ldrh r0, [r3]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r2, r4, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0xcc
	muls r0, r1, r0
	mov r8, r3
	mov sl, r2
	cmp r0, #0
	blt _080D23BC
	asrs r1, r0, #0xc
	b _080D23C2
_080D23BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D23C2:
	adds r0, r4, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r4, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080d1b04
	str r0, [sp, #8]
	adds r0, r5, #0
	bl FUN_080d1b38
	mov sb, r0
	movs r0, #0xd6
	lsls r0, r0, #2
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #1
	bne _080D23F6
	movs r0, #0x80
	lsls r0, r0, #0xb
	mov r1, sb
	orrs r1, r0
	mov sb, r1
_080D23F6:
	adds r0, r4, #0
	adds r0, #0xb4
	ldrh r0, [r0]
	str r0, [sp, #0xc]
	mov r2, sl
	ldrb r1, [r2]
	mov r0, r8
	movs r2, #0xe0
	bl FUN_080d2258
	adds r7, r0, #0
	cmp r7, #0
	beq _080D24DE
	adds r0, r4, #0
	adds r0, #0xc5
	movs r1, #0
	ldrsb r1, [r0, r1]
	adds r3, r0, #0
	cmp r1, #2
	beq _080D2422
	cmp r1, #4
	bne _080D247E
_080D2422:
	cmp r7, #2
	bne _080D247E
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1b
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2446
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r6, #0xde
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D2462
_080D2446:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbe
	strh r7, [r0]
	adds r1, #4
	movs r0, #3
	strh r0, [r1]
	b _080D25A2
_080D2462:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r2, [r0]
	adds r1, #6
	movs r0, #3
	strh r0, [r1]
	adds r1, #2
	movs r0, #6
	strh r0, [r1]
	b _080D25A2
_080D247E:
	adds r1, r4, #0
	adds r1, #0xba
	movs r6, #0
	movs r0, #0x1a
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D24A6
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D24C2
_080D24A6:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r6, [r0]
	adds r1, #6
	movs r0, #2
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r6, [r0]
	b _080D25A2
_080D24C2:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	strh r2, [r0]
	adds r1, #6
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r2, [r0]
	b _080D25A2
_080D24DE:
	mov r3, sl
	ldrb r1, [r3]
	movs r2, #0xa8
	lsls r2, r2, #1
	mov r0, r8
	bl FUN_080d2258
	cmp r0, #0
	beq _080D2548
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1b
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2510
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r6, #0xde
	lsls r6, r6, #2
	adds r0, r5, r6
	ldr r2, [r0]
	ands r2, r1
	cmp r2, #0
	beq _080D252C
_080D2510:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #2
	strh r0, [r1]
	adds r1, #2
	movs r0, #3
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r7, [r0]
	b _080D259E
_080D252C:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #2
	strh r0, [r1]
	adds r1, #2
	movs r0, #7
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xc0
	strh r2, [r0]
	b _080D259E
_080D2548:
	adds r1, r4, #0
	adds r1, #0xba
	movs r0, #0x1c
	strh r0, [r1]
	ldrb r0, [r6]
	cmp r0, #1
	beq _080D2568
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D2584
_080D2568:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xbc
	movs r1, #4
	strh r1, [r0]
	adds r0, #2
	strh r1, [r0]
	adds r1, r4, #0
	adds r1, #0xc0
	movs r0, #1
	b _080D259C
_080D2584:
	adds r1, r4, #0
	adds r1, #0xb8
	movs r0, #0x38
	strh r0, [r1]
	adds r1, #4
	movs r0, #4
	strh r0, [r1]
	adds r1, #2
	movs r0, #7
	strh r0, [r1]
	adds r1, #2
	movs r0, #5
_080D259C:
	strh r0, [r1]
_080D259E:
	adds r3, r4, #0
	adds r3, #0xc5
_080D25A2:
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _080D25BC
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	mov r3, sb
	orrs r3, r0
	mov sb, r3
	adds r0, r5, #0
	bl FUN_080cec18
_080D25BC:
	adds r0, r4, #0
	adds r0, #0x48
	mov r6, sb
	str r6, [sp]
	adds r1, r4, #0
	adds r1, #0xb6
	ldrh r1, [r1]
	str r1, [sp, #4]
	ldr r1, [sp, #8]
	ldr r2, [sp, #0xc]
	movs r3, #2
	bl Hitbox_SetAttack
	mov r1, sl
	ldrb r0, [r1]
	adds r3, r4, #0
	adds r3, #0x8a
	movs r1, #0
	strb r0, [r3]
	adds r0, r4, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #0x10
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d25f8
FUN_080d25f8: @ 0x080D25F8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	mov ip, r0
	adds r7, r2, #0
	str r3, [sp, #0x10]
	ldr r0, _080D26B0 @ =0x0203B400
	mov sb, r0
	ldr r6, _080D26B4 @ =0x030046B8
	ldr r3, [r6]
	adds r3, #1
	ldr r2, _080D26B8 @ =0x000003FF
	mov r8, r2
	ands r3, r2
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	movs r5, #0x1f
	ands r0, r5
	ldrh r2, [r1]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D26BC @ =0xFFFF0000
	mov sl, r2
	ldr r4, [sp]
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	ldr r2, _080D26C0 @ =0x0000FFFF
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r3, r3, #1
	add r3, sb
	ldrh r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #3
	ldr r2, _080D26C4 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D26C8
	asrs r0, r0, #0xc
	b _080D26CE
	.align 2, 0
_080D26B0: .4byte 0x0203B400
_080D26B4: .4byte 0x030046B8
_080D26B8: .4byte 0x000003FF
_080D26BC: .4byte 0xFFFF0000
_080D26C0: .4byte 0x0000FFFF
_080D26C4: .4byte 0x085B0A08
_080D26C8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D26CE:
	rsbs r0, r0, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #8]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D26EC
	asrs r0, r0, #0xc
	b _080D26F2
_080D26EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D26F2:
	rsbs r1, r0, #0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080D2720 @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	mov r0, ip
	mov r1, sp
	ldr r3, [sp, #0x10]
	bl FUN_080ccfe4
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2720: .4byte 0xFFFF0000

	thumb_func_start FUN_080d2724
FUN_080d2724: @ 0x080D2724
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _080D2758 @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _080D275C @ =0x00000A8A
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D276C
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D2764
	ldr r0, [r6, #0x18]
	ldr r1, _080D2760 @ =0x0000038F
	bl FUN_080cc3e4
	b _080D276C
	.align 2, 0
_080D2758: .4byte 0x000009C8
_080D275C: .4byte 0x00000A8A
_080D2760: .4byte 0x0000038F
_080D2764:
	ldr r0, [r6, #0x18]
	ldr r1, _080D27B0 @ =0x0000038D
	bl FUN_080cc3e4
_080D276C:
	adds r0, r5, #0
	adds r0, #0xc2
	adds r1, r5, #0
	adds r1, #0xbc
	ldrh r2, [r0]
	mov sb, r0
	mov sl, r1
	ldrh r3, [r1]
	cmp r2, r3
	bhs _080D284A
	subs r0, #0xa
	ldrh r1, [r0]
	mov r2, sb
	ldrh r0, [r2]
	muls r0, r1, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _080D27B4 @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _080D27B8
	asrs r1, r0, #0xc
	b _080D27BE
	.align 2, 0
_080D27B0: .4byte 0x0000038D
_080D27B4: .4byte 0x085B0A08
_080D27B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D27BE:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r7, r1, #0
	cmp r0, #0
	blt _080D27F0
	asrs r2, r0, #0xc
	b _080D27F6
_080D27F0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D27F6:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	adds r1, r5, #0
	adds r1, #0xbe
	str r1, [sp]
	cmp r0, #0
	bge _080D282C
	b _080D2928
_080D282C:
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
	mov r0, r8
	ldrb r2, [r0]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080d25f8
	b _080D2928
_080D284A:
	mov r1, sb
	ldrh r2, [r1]
	mov r0, sl
	ldrh r3, [r0]
	adds r1, r5, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, r3, r0
	str r1, [sp]
	cmp r2, r0
	bge _080D2928
	adds r0, r5, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r0, r3, r0
	adds r4, r0, #0
	adds r4, #0xcc
	ldr r2, _080D2890 @ =0x085B0A08
	adds r3, r5, #0
	adds r3, #0xc4
	ldrb r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	mov r8, r3
	cmp r0, #0
	blt _080D2894
	asrs r1, r0, #0xc
	b _080D289A
	.align 2, 0
_080D2890: .4byte 0x085B0A08
_080D2894:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D289A:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r3, r5, #0
	adds r3, #0x9a
	strh r0, [r3]
	mov r3, r8
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r4, r0
	adds r7, r1, #0
	cmp r0, #0
	blt _080D28CC
	asrs r2, r0, #0xc
	b _080D28D2
_080D28CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D28D2:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r2
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	adds r4, r5, #0
	adds r4, #0x48
	adds r0, r4, #0
	adds r1, r7, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	adds r3, r5, #0
	adds r3, #0xc5
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r0, #0
	blt _080D2928
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r6, #0x20]
	orrs r0, r1
	str r0, [r6, #0x20]
	mov r0, sb
	ldrh r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D2928
	mov r1, r8
	ldrb r2, [r1]
	ldrb r3, [r3]
	lsls r3, r3, #0x18
	asrs r3, r3, #0x18
	adds r0, r6, #0
	adds r1, r7, #0
	bl FUN_080d25f8
_080D2928:
	mov r2, sb
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r3, sl
	ldrh r1, [r3]
	ldr r3, [sp]
	ldrh r2, [r3]
	adds r3, r5, #0
	adds r3, #0xc0
	adds r1, r1, r2
	ldrh r3, [r3]
	adds r1, r1, r3
	cmp r0, r1
	bge _080D294E
	movs r0, #0
	b _080D2956
_080D294E:
	movs r0, #0
	mov r1, sb
	strh r0, [r1]
	movs r0, #1
_080D2956:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d2968
FUN_080d2968: @ 0x080D2968
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D298A
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D298E
_080D298A:
	movs r7, #0x30
	b _080D2990
_080D298E:
	movs r7, #0x40
_080D2990:
	ldr r1, _080D29A8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080D299C
	b _080D2BF8
_080D299C:
	lsls r0, r0, #2
	ldr r1, _080D29AC @ =_080D29B0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D29A8: .4byte 0x0000037D
_080D29AC: .4byte _080D29B0
_080D29B0: @ jump table
	.4byte _080D29CC @ case 0
	.4byte _080D29FC @ case 1
	.4byte _080D2BF8 @ case 2
	.4byte _080D2BF8 @ case 3
	.4byte _080D2A64 @ case 4
	.4byte _080D2B38 @ case 5
	.4byte _080D2B8C @ case 6
_080D29CC:
	adds r0, r5, #0
	bl FUN_080d1a44
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D29F0
	b _080D2BF8
_080D29F0:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D2BF8
_080D29FC:
	adds r0, r5, #0
	bl FUN_080d1a44
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D2A50 @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #6
	bls _080D2A54
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D2A54
	adds r0, r5, #0
	bl FUN_080d230c
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D2BF8
	.align 2, 0
_080D2A50: .4byte 0x0000037E
_080D2A54:
	ldr r2, _080D2A60 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D2BF8
	.align 2, 0
_080D2A60: .4byte 0x0000037E
_080D2A64:
	ldr r0, _080D2AC0 @ =0x000003D1
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r4, r5, r1
	ldrb r0, [r4]
	ldr r2, _080D2AC4 @ =0x00000A82
	adds r6, r5, r2
	ldrh r1, [r6]
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_080cc1e8
	ldrb r0, [r4]
	cmp r0, #1
	bne _080D2B22
	ldrh r0, [r6]
	cmp r0, #0x1c
	bne _080D2AC8
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #0
	bl FUN_080ccc34
	b _080D2B22
	.align 2, 0
_080D2AC0: .4byte 0x000003D1
_080D2AC4: .4byte 0x00000A82
_080D2AC8:
	cmp r0, #0x1b
	bne _080D2AF6
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #1
	bl FUN_080ccc34
	b _080D2B22
_080D2AF6:
	cmp r0, #0x1a
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D2B22
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #1
	bne _080D2B22
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r2, r5, #0
	adds r2, #0x2c
	adds r0, r5, #0
	movs r3, #2
	bl FUN_080ccc34
_080D2B22:
	adds r0, r5, #0
	bl FUN_080d2724
	cmp r0, #0
	beq _080D2BF8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D2BF8
_080D2B38:
	ldr r2, _080D2B84 @ =0x000003D1
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2B5A
	ldr r2, _080D2B88 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D2B5A:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x18
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D2BF8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D2BF8
	.align 2, 0
_080D2B84: .4byte 0x000003D1
_080D2B88: .4byte 0x00000A76
_080D2B8C:
	ldr r2, _080D2BC4 @ =0x000003D1
	adds r0, r5, r2
	movs r2, #0
	strb r2, [r0]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D2BAE
	ldr r0, _080D2BC8 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D2BAE:
	ldr r1, _080D2BC8 @ =0x00000A76
	adds r4, r5, r1
	ldrb r6, [r4]
	cmp r6, #0
	beq _080D2BD0
	strb r2, [r4]
	ldr r1, _080D2BCC @ =0x0000037D
	adds r0, r5, r1
	strb r2, [r0]
	b _080D2BF8
	.align 2, 0
_080D2BC4: .4byte 0x000003D1
_080D2BC8: .4byte 0x00000A76
_080D2BCC: .4byte 0x0000037D
_080D2BD0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x19
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	adds r2, r7, #0
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D2BF8
	strb r6, [r4]
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D2BF8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d2c00
FUN_080d2c00: @ 0x080D2C00
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D2C7C @ =0x000009C8
	adds r5, r4, r0
	ldr r1, _080D2C80 @ =0x00000A68
	adds r2, r4, r1
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D2C84 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r1, r4, r2
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080d1b04
	adds r7, r0, #0
	adds r0, r4, #0
	bl FUN_080d1b38
	adds r6, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D2C90
	movs r2, #0xa8
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x1d
	strh r0, [r1]
	ldr r0, _080D2C88 @ =0x00000A88
	adds r1, r4, r0
	movs r0, #7
	strh r0, [r1]
	adds r2, #4
	adds r1, r4, r2
	movs r0, #4
	strh r0, [r1]
	ldr r0, _080D2C8C @ =0x00000A86
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	movs r0, #0x80
	lsls r0, r0, #0xb
	orrs r6, r0
	b _080D2CEE
	.align 2, 0
_080D2C7C: .4byte 0x000009C8
_080D2C80: .4byte 0x00000A68
_080D2C84: .4byte 0x00000A6A
_080D2C88: .4byte 0x00000A88
_080D2C8C: .4byte 0x00000A86
_080D2C90:
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D2CCC
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x1d
	strh r0, [r1]
	ldr r2, _080D2CC4 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #7
	strh r0, [r1]
	ldr r0, _080D2CC8 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #4
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #6
	b _080D2CEC
	.align 2, 0
_080D2CC4: .4byte 0x00000A88
_080D2CC8: .4byte 0x00000A84
_080D2CCC:
	movs r0, #0xa8
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x13
	strh r0, [r1]
	ldr r2, _080D2D40 @ =0x00000A88
	adds r1, r4, r2
	movs r0, #0xb
	strh r0, [r1]
	ldr r0, _080D2D44 @ =0x00000A84
	adds r1, r4, r0
	movs r0, #6
	strh r0, [r1]
	subs r2, #2
	adds r1, r4, r2
	movs r0, #9
_080D2CEC:
	strh r0, [r1]
_080D2CEE:
	adds r1, r5, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D2D08
	adds r1, r0, #0
	movs r0, #1
	lsls r0, r1
	orrs r6, r0
	adds r0, r4, #0
	bl FUN_080cec18
_080D2D08:
	adds r0, r5, #0
	adds r0, #0x48
	adds r1, r5, #0
	adds r1, #0xb4
	ldrh r2, [r1]
	str r6, [sp]
	adds r1, #2
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r7, #0
	movs r3, #4
	bl Hitbox_SetAttack
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	adds r2, r5, #0
	adds r2, #0x8a
	movs r1, #0
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xc2
	strh r1, [r0]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2D40: .4byte 0x00000A88
_080D2D44: .4byte 0x00000A84

	thumb_func_start FUN_080d2d48
FUN_080d2d48: @ 0x080D2D48
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	str r0, [sp, #0x10]
	adds r7, r2, #0
	mov ip, r3
	ldr r0, _080D2E04 @ =0x0203B400
	mov sb, r0
	ldr r6, _080D2E08 @ =0x030046B8
	ldr r3, [r6]
	adds r3, #1
	ldr r2, _080D2E0C @ =0x000003FF
	mov r8, r2
	ands r3, r2
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	movs r5, #0x1f
	ands r0, r5
	ldrh r2, [r1]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D2E10 @ =0xFFFF0000
	mov sl, r2
	ldr r4, [sp]
	ands r4, r2
	orrs r4, r0
	str r4, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r2, [r1, #2]
	adds r0, r0, r2
	subs r0, #0xf
	lsls r0, r0, #0x10
	ldr r2, _080D2E14 @ =0x0000FFFF
	ands r2, r4
	orrs r2, r0
	str r2, [sp]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	ands r0, r5
	ldrh r1, [r1, #4]
	adds r0, r0, r1
	subs r0, #0xf
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	mov r2, sl
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	adds r3, #1
	mov r0, r8
	ands r3, r0
	str r3, [r6]
	lsls r3, r3, #1
	add r3, sb
	ldrh r0, [r3]
	movs r1, #3
	ands r0, r1
	adds r3, r0, #5
	ldr r2, _080D2E18 @ =0x085B0A08
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D2E1C
	asrs r0, r0, #0xc
	b _080D2E22
	.align 2, 0
_080D2E04: .4byte 0x0203B400
_080D2E08: .4byte 0x030046B8
_080D2E0C: .4byte 0x000003FF
_080D2E10: .4byte 0xFFFF0000
_080D2E14: .4byte 0x0000FFFF
_080D2E18: .4byte 0x085B0A08
_080D2E1C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2E22:
	lsls r2, r0, #0x10
	ldr r1, _080D2E44 @ =0x0000FFFF
	ldr r0, [sp, #8]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, #8]
	movs r0, #0xff
	ands r0, r7
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D2E48
	asrs r0, r0, #0xc
	b _080D2E4E
	.align 2, 0
_080D2E44: .4byte 0x0000FFFF
_080D2E48:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2E4E:
	rsbs r3, r0, #0
	mov r0, ip
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D2E6A
	asrs r0, r0, #0xc
	b _080D2E70
_080D2E6A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2E70:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D2E98 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	movs r0, #0xff
	mov r2, ip
	ands r0, r2
	lsls r0, r0, #1
	adds r0, r0, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D2E9C
	asrs r0, r0, #0xc
	b _080D2EA2
	.align 2, 0
_080D2E98: .4byte 0xFFFF0000
_080D2E9C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2EA2:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _080D2ECC @ =0xFFFF0000
	add r2, sp, #8
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [r2, #4]
	ldr r0, [sp, #0x10]
	mov r1, sp
	ldr r3, [sp, #0x34]
	bl FUN_080ccfe4
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D2ECC: .4byte 0xFFFF0000

	thumb_func_start FUN_080d2ed0
FUN_080d2ed0: @ 0x080D2ED0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x14
	adds r5, r0, #0
	ldr r0, _080D2F00 @ =0x000009C8
	adds r6, r5, r0
	ldr r1, _080D2F04 @ =0x00000A8A
	adds r3, r5, r1
	ldrh r0, [r3]
	adds r0, #1
	strh r0, [r3]
	ldr r2, _080D2F08 @ =0x00000A88
	adds r1, r5, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrh r4, [r1]
	cmp r0, r4
	bhi _080D2F0C
_080D2EFA:
	movs r0, #0
	b _080D317A
	.align 2, 0
_080D2F00: .4byte 0x000009C8
_080D2F04: .4byte 0x00000A8A
_080D2F08: .4byte 0x00000A88
_080D2F0C:
	ldrh r2, [r3]
	ldrh r0, [r1]
	ldr r7, _080D2F38 @ =0x00000A84
	adds r1, r5, r7
	ldrh r1, [r1]
	adds r1, r0, r1
	cmp r2, r1
	ble _080D2F1E
	b _080D313C
_080D2F1E:
	cmp r2, r1
	bne _080D2F44
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D2F3C
	ldr r0, [r5, #0x18]
	adds r1, #0x38
	bl FUN_080cc3e4
	b _080D2F44
	.align 2, 0
_080D2F38: .4byte 0x00000A84
_080D2F3C:
	ldr r0, [r5, #0x18]
	ldr r1, _080D2F8C @ =0x0000038E
	bl FUN_080cc3e4
_080D2F44:
	adds r4, r6, #0
	adds r4, #0xc2
	ldrh r1, [r4]
	adds r3, r6, #0
	adds r3, #0xc0
	ldrh r0, [r3]
	subs r1, r1, r0
	adds r0, r6, #0
	adds r0, #0xb8
	ldrh r0, [r0]
	muls r1, r0, r1
	movs r0, #0xa8
	lsls r0, r0, #1
	subs r7, r0, r1
	movs r1, #0xff
	ands r7, r1
	ldr r2, _080D2F90 @ =0x085B0A08
	adds r0, r7, #0
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r8, r0
	movs r0, #0xfa
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	mov sb, r4
	mov r8, r3
	mov ip, r2
	cmp r0, #0
	blt _080D2F94
	asrs r1, r0, #0xc
	b _080D2F9A
	.align 2, 0
_080D2F8C: .4byte 0x0000038E
_080D2F90: .4byte 0x085B0A08
_080D2F94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2F9A:
	adds r2, r6, #0
	adds r2, #0xa2
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r3, r6, #0
	adds r3, #0x9a
	strh r0, [r3]
	adds r0, r7, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0xfa
	muls r0, r1, r0
	str r2, [sp, #0xc]
	cmp r0, #0
	blt _080D2FC6
	asrs r0, r0, #0xc
	b _080D2FCC
_080D2FC6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D2FCC:
	mov sl, r0
	adds r2, r6, #0
	adds r2, #0xc4
	ldrb r0, [r2]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, ip
	movs r4, #0
	ldrsh r0, [r0, r4]
	mov r1, sl
	muls r1, r0, r1
	adds r0, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D2FF2
	asrs r1, r0, #0xc
	b _080D2FF8
_080D2FF2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D2FF8:
	adds r2, r6, #0
	adds r2, #0xa0
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x98
	strh r0, [r1]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r3, #0
	ldrsh r0, [r0, r3]
	mov r3, sl
	muls r3, r0, r3
	adds r0, r3, #0
	mov sl, r2
	mov ip, r1
	cmp r0, #0
	blt _080D3022
	asrs r1, r0, #0xc
	b _080D3028
_080D3022:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D3028:
	adds r2, r6, #0
	adds r2, #0xa4
	ldrh r0, [r2]
	adds r0, r0, r1
	adds r1, r6, #0
	adds r1, #0x9c
	strh r0, [r1]
	mov r0, sb
	ldrh r1, [r0]
	mov r3, r8
	ldrh r0, [r3]
	adds r0, #2
	str r2, [sp, #0x10]
	cmp r1, r0
	ble _080D3060
	adds r1, r6, #0
	adds r1, #0xc5
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r0, #0
	blt _080D3060
	ldrb r3, [r4]
	str r0, [sp]
	adds r0, r5, #0
	mov r1, ip
	adds r2, r7, #0
	bl FUN_080d2d48
_080D3060:
	mov r7, sb
	ldrh r3, [r7]
	mov r1, r8
	ldrh r0, [r1]
	adds r2, r6, #0
	adds r2, #0xbc
	ldrh r1, [r2]
	adds r0, r0, r1
	subs r0, #2
	adds r7, r2, #0
	cmp r3, r0
	bgt _080D307A
	b _080D2EFA
_080D307A:
	movs r3, #0xaa
	ldr r2, _080D309C @ =0x085B0A08
	ldrb r0, [r4]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	mov ip, r2
	cmp r0, #0
	blt _080D30A0
	asrs r0, r0, #0xc
	b _080D30A6
	.align 2, 0
_080D309C: .4byte 0x085B0A08
_080D30A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D30A6:
	mov r1, sl
	ldrh r2, [r1]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	mov r1, r8
	ldrh r0, [r1]
	ldrh r1, [r7]
	adds r0, r0, r1
	mov r7, sb
	ldrh r1, [r7]
	subs r0, r0, r1
	adds r0, #1
	movs r1, #0x5a
	muls r0, r1, r0
	ldr r1, [sp, #0xc]
	ldrh r1, [r1]
	adds r0, r0, r1
	ldr r7, _080D30E8 @ =0xFFFFFEFC
	adds r0, r0, r7
	lsls r0, r0, #0x10
	lsrs r2, r2, #0x10
	orrs r2, r0
	str r2, [sp, #4]
	ldrb r0, [r4]
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D30EC
	asrs r0, r0, #0xc
	b _080D30F2
	.align 2, 0
_080D30E8: .4byte 0xFFFFFEFC
_080D30EC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D30F2:
	ldr r2, [sp, #0x10]
	ldrh r1, [r2]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D3138 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r6, #0
	adds r0, #0xc5
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080D311E
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
_080D311E:
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r0, r5, r3
	add r1, sp, #4
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r6, #0
	adds r0, #0x48
	bl Hitbox_Register
	b _080D2EFA
	.align 2, 0
_080D3138: .4byte 0xFFFF0000
_080D313C:
	ldr r4, _080D316C @ =0x00000A86
	adds r0, r5, r4
	ldrh r0, [r0]
	adds r0, r1, r0
	cmp r2, r0
	bgt _080D3174
	ldr r7, _080D3170 @ =0x00000A8D
	adds r0, r5, r7
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	blt _080D3160
	movs r1, #0x80
	lsls r1, r1, #0xc
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
_080D3160:
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r5, r1
	bl Hitbox_Register
	b _080D2EFA
	.align 2, 0
_080D316C: .4byte 0x00000A86
_080D3170: .4byte 0x00000A8D
_080D3174:
	movs r0, #0
	strh r0, [r3]
	movs r0, #1
_080D317A:
	add sp, #0x14
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d318c
FUN_080d318c: @ 0x080D318C
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D31AE
	movs r1, #0x80
	lsls r1, r1, #0xf
	movs r2, #0xde
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D31B2
_080D31AE:
	movs r5, #0x30
	b _080D31B4
_080D31B2:
	movs r5, #0x40
_080D31B4:
	ldr r1, _080D31C8 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D31FC
	cmp r0, #1
	bgt _080D31CC
	cmp r0, #0
	beq _080D31D6
	b _080D3330
	.align 2, 0
_080D31C8: .4byte 0x0000037D
_080D31CC:
	cmp r0, #4
	beq _080D3254
	cmp r0, #5
	beq _080D3290
	b _080D3330
_080D31D6:
	adds r0, r4, #0
	bl FUN_080d1a44
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x1d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D31FA
	b _080D3330
_080D31FA:
	b _080D330E
_080D31FC:
	adds r0, r4, #0
	bl FUN_080d1a44
	adds r0, r4, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3244
	adds r0, r4, #0
	bl FUN_080d2c00
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D3330
_080D3244:
	ldr r0, _080D3250 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D3330
	.align 2, 0
_080D3250: .4byte 0x0000037E
_080D3254:
	ldr r2, _080D328C @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080cc1e8
	adds r0, r4, #0
	bl FUN_080d2ed0
	cmp r0, #0
	beq _080D3330
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D3330
	.align 2, 0
_080D328C: .4byte 0x000003D1
_080D3290:
	ldr r2, _080D331C @ =0x000003D1
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D32B2
	ldr r2, _080D3320 @ =0x00000A76
	adds r1, r4, r2
	movs r0, #1
	strb r0, [r1]
_080D32B2:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D32E4
	adds r0, r4, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D32E4
	adds r0, r4, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D32E4
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r1, [r0]
	adds r2, r4, #0
	adds r2, #0x2c
	adds r0, r4, #0
	bl FUN_080ccd5c
_080D32E4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x1f
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	adds r2, r5, #0
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D3330
	ldr r2, _080D3320 @ =0x00000A76
	adds r1, r4, r2
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D3324
	movs r0, #0
	strb r0, [r1]
_080D330E:
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D3330
	.align 2, 0
_080D331C: .4byte 0x000003D1
_080D3320: .4byte 0x00000A76
_080D3324:
	strb r0, [r1]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D3330:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d3338
FUN_080d3338: @ 0x080D3338
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, _080D33C0 @ =0x00000A68
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	ldr r2, _080D33C4 @ =0x00000A6A
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #0xe6
	movs r3, #0
	mov r8, r3
	strh r0, [r1]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	adds r2, #0x22
	adds r6, r4, r2
	strb r0, [r6]
	adds r0, r4, #0
	bl FUN_080d1b04
	adds r5, r0, #0
	ldr r3, _080D33C8 @ =0x000009F4
	adds r0, r4, r3
	movs r1, #0x2d
	bl Video_SetAuxSpritePltt
	movs r1, #0xa1
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r2, _080D33CC @ =0x00000A7C
	adds r1, r4, r2
	ldrh r2, [r1]
	mov r3, r8
	str r3, [sp]
	ldr r3, _080D33D0 @ =0x00000A7E
	adds r1, r4, r3
	ldrh r1, [r1]
	str r1, [sp, #4]
	adds r1, r5, #0
	movs r3, #8
	bl Hitbox_SetAttack
	ldrb r1, [r6]
	ldr r2, _080D33D4 @ =0x00000A52
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D33D8 @ =0x00000A8A
	adds r4, r4, r3
	mov r0, r8
	strh r0, [r4]
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D33C0: .4byte 0x00000A68
_080D33C4: .4byte 0x00000A6A
_080D33C8: .4byte 0x000009F4
_080D33CC: .4byte 0x00000A7C
_080D33D0: .4byte 0x00000A7E
_080D33D4: .4byte 0x00000A52
_080D33D8: .4byte 0x00000A8A

	thumb_func_start FUN_080d33dc
FUN_080d33dc: @ 0x080D33DC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _080D3428 @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _080D342C @ =0x00000A8A
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _080D33F6
	ldr r0, [r6, #0x18]
	ldr r1, _080D3430 @ =0x00000391
	bl FUN_080cc3e4
_080D33F6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _080D34A6
	ldr r2, _080D3434 @ =0x085B0A08
	ldr r3, _080D3438 @ =0x00000A8C
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080D343C
	asrs r1, r0, #0xc
	b _080D3442
	.align 2, 0
_080D3428: .4byte 0x000009C8
_080D342C: .4byte 0x00000A8A
_080D3430: .4byte 0x00000391
_080D3434: .4byte 0x085B0A08
_080D3438: .4byte 0x00000A8C
_080D343C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D3442:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _080D3474
	asrs r1, r0, #0xc
	b _080D347A
_080D3474:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D347A:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r4, r6, r3
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0
	b _080D34AC
_080D34A6:
	movs r0, #0
	strh r0, [r4]
	movs r0, #1
_080D34AC:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d34b4
FUN_080d34b4: @ 0x080D34B4
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080D34D0 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #6
	bls _080D34C4
	b _080D369C
_080D34C4:
	lsls r0, r0, #2
	ldr r1, _080D34D4 @ =_080D34D8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D34D0: .4byte 0x0000037D
_080D34D4: .4byte _080D34D8
_080D34D8: @ jump table
	.4byte _080D34F4 @ case 0
	.4byte _080D3530 @ case 1
	.4byte _080D369C @ case 2
	.4byte _080D369C @ case 3
	.4byte _080D3584 @ case 4
	.4byte _080D35DC @ case 5
	.4byte _080D3660 @ case 6
_080D34F4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D3512
	b _080D369C
_080D3512:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3560
	adds r0, r4, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D369C
_080D3530:
	adds r0, r4, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3572
_080D3560:
	adds r0, r4, #0
	bl FUN_080d3338
	adds r0, r4, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D369C
_080D3572:
	ldr r0, _080D3580 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D369C
	.align 2, 0
_080D3580: .4byte 0x0000037E
_080D3584:
	ldr r0, _080D35D4 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x22
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D35BE
	ldr r0, _080D35D8 @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080D35BE:
	adds r0, r4, #0
	bl FUN_080d33dc
	cmp r0, #0
	beq _080D369C
	adds r0, r4, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D369C
	.align 2, 0
_080D35D4: .4byte 0x000003D1
_080D35D8: .4byte 0x00000A76
_080D35DC:
	ldr r1, _080D362C @ =0x000003D1
	adds r0, r4, r1
	movs r5, #0
	strb r5, [r0]
	subs r1, #0x79
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x21
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3614
	ldr r0, _080D3630 @ =0x00000A76
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_080D3614:
	ldr r1, _080D3630 @ =0x00000A76
	adds r2, r4, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3638
	strb r5, [r2]
	ldr r0, _080D3634 @ =0x0000037D
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D369C
	.align 2, 0
_080D362C: .4byte 0x000003D1
_080D3630: .4byte 0x00000A76
_080D3634: .4byte 0x0000037D
_080D3638:
	ldr r0, _080D365C @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #9
	bls _080D369C
	movs r0, #0
	strb r0, [r2]
	adds r0, r4, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D369C
	.align 2, 0
_080D365C: .4byte 0x0000037E
_080D3660:
	ldr r0, _080D36A4 @ =0x000003D1
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x20
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D36A8 @ =0x0000037E
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D369C
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D369C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D36A4: .4byte 0x000003D1
_080D36A8: .4byte 0x0000037E

	thumb_func_start FUN_080d36ac
FUN_080d36ac: @ 0x080D36AC
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _080D36C8 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080D36BE
	b _080D3AD8
_080D36BE:
	lsls r0, r0, #2
	ldr r1, _080D36CC @ =_080D36D0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D36C8: .4byte 0x0000037D
_080D36CC: .4byte _080D36D0
_080D36D0: @ jump table
	.4byte _080D36F0 @ case 0
	.4byte _080D371A @ case 1
	.4byte _080D37F6 @ case 2
	.4byte _080D3AD8 @ case 3
	.4byte _080D38A8 @ case 4
	.4byte _080D38FC @ case 5
	.4byte _080D3A28 @ case 6
	.4byte _080D3AA4 @ case 7
_080D36F0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D370E
	b _080D3AD8
_080D370E:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D3AD8
_080D371A:
	ldr r0, _080D377C @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _080D372C
	ldr r0, [r5, #0x18]
	ldr r1, _080D3780 @ =0x000001F7
	bl FUN_080cc3e4
_080D372C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D375A
	b _080D3AD8
_080D375A:
	ldr r2, _080D3784 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	ldr r0, _080D3788 @ =0x000003E6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x18
	bhi _080D378C
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D38E8
	.align 2, 0
_080D377C: .4byte 0x0000037E
_080D3780: .4byte 0x000001F7
_080D3784: .4byte 0x00000A8F
_080D3788: .4byte 0x000003E6
_080D378C:
	ldr r2, _080D37BC @ =0x00000A92
	adds r1, r5, r2
	movs r0, #0xf
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D37C0
	ldr r0, [r5, #0x18]
	movs r1, #0xcd
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D37CA
	.align 2, 0
_080D37BC: .4byte 0x00000A92
_080D37C0:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_080cc348
_080D37CA:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2c
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #1
	str r0, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #3
	str r0, [sp, #0x14]
	movs r0, #0x19
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xb4
	movs r3, #0
	bl Entity08080be8_Create
	b _080D3AD8
_080D37F6:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D388C @ =0x00000A92
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r1, _080D3890 @ =0x0000037E
	adds r4, r5, r1
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D3832
	ldr r0, [r5, #0x18]
	movs r1, #0xfc
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D3832:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D38E4
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080D3854
	b _080D3AD8
_080D3854:
	ldr r0, _080D3894 @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	ldr r2, _080D3898 @ =0x000003E6
	adds r1, r5, r2
	movs r0, #0x1e
	strh r0, [r1]
	ldr r0, _080D389C @ =0x0000095E
	adds r1, r5, r0
	ldr r0, _080D38A0 @ =0x00000121
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D38A4 @ =0x000001F9
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D3AD8
	.align 2, 0
_080D388C: .4byte 0x00000A92
_080D3890: .4byte 0x0000037E
_080D3894: .4byte 0x00000A8F
_080D3898: .4byte 0x000003E6
_080D389C: .4byte 0x0000095E
_080D38A0: .4byte 0x00000121
_080D38A4: .4byte 0x000001F9
_080D38A8:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D38F8 @ =0x00000A92
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D38E4
	b _080D3AD8
_080D38E4:
	ldr r0, [r5, #0x18]
	movs r1, #0xcd
_080D38E8:
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D3AD8
	.align 2, 0
_080D38F8: .4byte 0x00000A92
_080D38FC:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D392E
	ldr r2, _080D39A8 @ =0x00000A76
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
_080D392E:
	ldr r0, _080D39AC @ =0x000003E6
	adds r6, r5, r0
	ldrh r0, [r6]
	cmp r0, #0
	beq _080D3A04
	cmp r0, #5
	bls _080D397A
	ldr r3, _080D39B0 @ =0xFFFF0000
	ldr r1, _080D39B4 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_080D397A:
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _080D39B8 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D39BC
	asrs r0, r0, #0xc
	b _080D39C2
	.align 2, 0
_080D39A8: .4byte 0x00000A76
_080D39AC: .4byte 0x000003E6
_080D39B0: .4byte 0xFFFF0000
_080D39B4: .4byte 0x0000FFFF
_080D39B8: .4byte 0x085B0A08
_080D39BC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D39C2:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D39E0 @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D39E4
	asrs r0, r0, #0xc
	b _080D39EA
	.align 2, 0
_080D39E0: .4byte 0x000003E6
_080D39E4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D39EA:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _080D3A00 @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080D3AD8
	.align 2, 0
_080D3A00: .4byte 0x000003E6
_080D3A04:
	ldr r2, _080D3A24 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3AD8
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D3AD8
	.align 2, 0
_080D3A24: .4byte 0x0000037E
_080D3A28:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3A5A
	ldr r0, _080D3A74 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3A5A:
	ldr r1, _080D3A74 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3A7C
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D3A78 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D3AD8
	.align 2, 0
_080D3A74: .4byte 0x00000A76
_080D3A78: .4byte 0x0000037D
_080D3A7C:
	ldr r0, _080D3AA0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080D3AD8
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_080cc348
	b _080D3AD8
	.align 2, 0
_080D3AA0: .4byte 0x0000037E
_080D3AA4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D3B08 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3AD8
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D3AD8:
	ldr r0, _080D3B0C @ =0x00000A92
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0xe
	bls _080D3AF8
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D3AF4
	adds r0, r5, #0
	bl FUN_080cf684
_080D3AF4:
	movs r0, #0
	strh r0, [r4]
_080D3AF8:
	ldr r2, _080D3B10 @ =0x00000951
	adds r1, r5, r2
	movs r0, #8
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D3B08: .4byte 0x0000037E
_080D3B0C: .4byte 0x00000A92
_080D3B10: .4byte 0x00000951

	thumb_func_start FUN_080d3b14
FUN_080d3b14: @ 0x080D3B14
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r1, _080D3B30 @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #7
	bls _080D3B26
	b _080D3F04
_080D3B26:
	lsls r0, r0, #2
	ldr r1, _080D3B34 @ =_080D3B38
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3B30: .4byte 0x0000037D
_080D3B34: .4byte _080D3B38
_080D3B38: @ jump table
	.4byte _080D3B58 @ case 0
	.4byte _080D3B82 @ case 1
	.4byte _080D3C3C @ case 2
	.4byte _080D3F04 @ case 3
	.4byte _080D3CE0 @ case 4
	.4byte _080D3D28 @ case 5
	.4byte _080D3E54 @ case 6
	.4byte _080D3ED0 @ case 7
_080D3B58:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D3B76
	b _080D3F04
_080D3B76:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D3F04
_080D3B82:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D3BD8 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D3BB4
	b _080D3F04
_080D3BB4:
	ldr r0, _080D3BDC @ =0x00000A8F
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	adds r2, #0x68
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bhi _080D3BE0
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D3D18
	.align 2, 0
_080D3BD8: .4byte 0x0000037E
_080D3BDC: .4byte 0x00000A8F
_080D3BE0:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D3C08
	ldr r0, [r5, #0x18]
	movs r1, #0xfb
	lsls r1, r1, #1
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D3C12
_080D3C08:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
_080D3C12:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x2e
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r1, #0
	str r1, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #0x11
	str r0, [sp, #0x14]
	movs r0, #0x14
	str r0, [sp, #0x18]
	str r1, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xc8
	movs r2, #0xaa
	movs r3, #8
	bl Entity08080be8_Create
	b _080D3F04
_080D3C3C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D3CC8 @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D3C6E
	ldr r0, [r5, #0x18]
	movs r1, #0xfa
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D3C6E:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D12
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bhi _080D3C90
	b _080D3F04
_080D3C90:
	ldr r2, _080D3CCC @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D3CD0 @ =0x000003E6
	adds r1, r5, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, _080D3CD4 @ =0x0000095E
	adds r1, r5, r2
	ldr r0, _080D3CD8 @ =0x00000121
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r5, r0
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D3CDC @ =0x000001F5
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D3F04
	.align 2, 0
_080D3CC8: .4byte 0x0000037E
_080D3CCC: .4byte 0x00000A8F
_080D3CD0: .4byte 0x000003E6
_080D3CD4: .4byte 0x0000095E
_080D3CD8: .4byte 0x00000121
_080D3CDC: .4byte 0x000001F5
_080D3CE0:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D12
	b _080D3F04
_080D3D12:
	ldr r0, [r5, #0x18]
	movs r1, #0xfb
	lsls r1, r1, #1
_080D3D18:
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D3F04
_080D3D28:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x28
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3D5A
	ldr r0, _080D3DD4 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3D5A:
	ldr r1, _080D3DD8 @ =0x000003E6
	adds r6, r5, r1
	ldrh r0, [r6]
	cmp r0, #0
	beq _080D3E30
	cmp r0, #5
	bls _080D3DA6
	ldr r3, _080D3DDC @ =0xFFFF0000
	ldr r1, _080D3DE0 @ =0x0000FFFF
	movs r0, #0
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r3
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r3
	movs r4, #0x20
	orrs r0, r4
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r3
	orrs r0, r4
	str r0, [r2, #4]
	adds r0, r5, #0
	adds r0, #0x2c
	movs r1, #3
	str r1, [sp]
	movs r1, #4
	str r1, [sp, #4]
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbd08
_080D3DA6:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldrh r3, [r6]
	ldr r2, _080D3DE4 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080D3DE8
	asrs r0, r0, #0xc
	b _080D3DEE
	.align 2, 0
_080D3DD4: .4byte 0x00000A76
_080D3DD8: .4byte 0x000003E6
_080D3DDC: .4byte 0xFFFF0000
_080D3DE0: .4byte 0x0000FFFF
_080D3DE4: .4byte 0x085B0A08
_080D3DE8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D3DEE:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D3E0C @ =0x000003E6
	adds r0, r5, r1
	ldrh r1, [r0]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D3E10
	asrs r0, r0, #0xc
	b _080D3E16
	.align 2, 0
_080D3E0C: .4byte 0x000003E6
_080D3E10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D3E16:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	ldr r0, _080D3E2C @ =0x000003E6
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	b _080D3F04
	.align 2, 0
_080D3E2C: .4byte 0x000003E6
_080D3E30:
	ldr r2, _080D3E50 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3F04
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D3F04
	.align 2, 0
_080D3E50: .4byte 0x0000037E
_080D3E54:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x27
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D3E86
	ldr r0, _080D3EA0 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D3E86:
	ldr r1, _080D3EA0 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D3EA8
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D3EA4 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D3F04
	.align 2, 0
_080D3EA0: .4byte 0x00000A76
_080D3EA4: .4byte 0x0000037D
_080D3EA8:
	ldr r0, _080D3ECC @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bls _080D3F04
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_080cc348
	b _080D3F04
	.align 2, 0
_080D3ECC: .4byte 0x0000037E
_080D3ED0:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x26
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D3F14 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bls _080D3F04
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D3F04:
	ldr r0, _080D3F18 @ =0x00000951
	adds r1, r5, r0
	movs r0, #4
	strb r0, [r1]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D3F14: .4byte 0x0000037E
_080D3F18: .4byte 0x00000951

	thumb_func_start FUN_080d3f1c
FUN_080d3f1c: @ 0x080D3F1C
	push {r4, r5, r6, lr}
	sub sp, #0x38
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D3F38
	adds r0, r5, #0
	movs r1, #3
	movs r2, #0
	bl FUN_080cc348
_080D3F38:
	ldr r2, _080D3F50 @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #8
	bls _080D3F44
	b _080D4462
_080D3F44:
	lsls r0, r0, #2
	ldr r1, _080D3F54 @ =_080D3F58
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D3F50: .4byte 0x0000037D
_080D3F54: .4byte _080D3F58
_080D3F58: @ jump table
	.4byte _080D3F7C @ case 0
	.4byte _080D3FA6 @ case 1
	.4byte _080D405E @ case 2
	.4byte _080D4462 @ case 3
	.4byte _080D410C @ case 4
	.4byte _080D419C @ case 5
	.4byte _080D41F8 @ case 6
	.4byte _080D4274 @ case 7
	.4byte _080D42B0 @ case 8
_080D3F7C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	bne _080D3F9A
	b _080D4462
_080D3F9A:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #1
	bl FUN_080cc348
	b _080D4462
_080D3FA6:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D3FF4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #6
	bhi _080D3FD8
	b _080D4462
_080D3FD8:
	ldr r2, _080D3FF8 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #0
	strb r0, [r1]
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #9
	bhi _080D3FFC
	ldr r0, [r5, #0x18]
	movs r1, #0xd5
	b _080D40A6
	.align 2, 0
_080D3FF4: .4byte 0x0000037E
_080D3FF8: .4byte 0x00000A8F
_080D3FFC:
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D4028
	ldr r0, [r5, #0x18]
	ldr r1, _080D4024 @ =0x00000203
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D4032
	.align 2, 0
_080D4024: .4byte 0x00000203
_080D4028:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #2
	bl FUN_080cc348
_080D4032:
	movs r1, #0x20
	str r1, [sp]
	movs r0, #0x32
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #2
	str r0, [sp, #0xc]
	movs r0, #0x1e
	str r0, [sp, #0x10]
	movs r0, #5
	str r0, [sp, #0x14]
	movs r0, #0xa
	str r0, [sp, #0x18]
	movs r0, #0
	str r0, [sp, #0x1c]
	adds r0, r5, #0
	movs r1, #0xe6
	movs r2, #0xaa
	movs r3, #0
	bl Entity08080be8_Create
	b _080D4462
_080D405E:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D40B8 @ =0x0000037E
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #6
	bne _080D4090
	ldr r0, [r5, #0x18]
	movs r1, #0xfc
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D4090:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D40C0
	ldr r0, [r5, #0x18]
	ldr r1, _080D40BC @ =0x00000203
_080D40A6:
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #5
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D40B8: .4byte 0x0000037E
_080D40BC: .4byte 0x00000203
_080D40C0:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bhi _080D40D0
	b _080D4462
_080D40D0:
	ldr r2, _080D4100 @ =0x00000A8F
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	ldr r0, _080D4104 @ =0x0000095E
	adds r1, r5, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r5, r2
	movs r0, #0x24
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D4108 @ =0x000001F9
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #4
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D4100: .4byte 0x00000A8F
_080D4104: .4byte 0x0000095E
_080D4108: .4byte 0x000001F9
_080D410C:
	adds r0, r5, #0
	bl FUN_080d19fc
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0]
	movs r4, #2
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _080D4140
	b _080D4462
_080D4140:
	ldr r0, [r5, #0x18]
	ldr r1, _080D4190 @ =0x000002E9
	bl FUN_080cc3e4
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	movs r0, #8
	subs r0, r0, r1
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	ldr r2, _080D4194 @ =0x00000A8A
	adds r1, r5, r2
	strh r0, [r1]
	adds r0, r5, #0
	bl FUN_080d1b04
	adds r1, r0, #0
	movs r2, #0xa1
	lsls r2, r2, #4
	adds r0, r5, r2
	str r4, [sp]
	movs r2, #0x1e
	str r2, [sp, #4]
	movs r2, #0x20
	movs r3, #0x10
	bl Hitbox_SetAttack
	ldr r0, [r5, #0x18]
	ldr r1, _080D4198 @ =0x00000202
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #3
	movs r2, #8
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D4190: .4byte 0x000002E9
_080D4194: .4byte 0x00000A8A
_080D4198: .4byte 0x00000202
_080D419C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D41CE
	ldr r0, _080D41F0 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D41CE:
	ldr r2, _080D41F4 @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080D41E2
	b _080D4462
_080D41E2:
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D41F0: .4byte 0x00000A76
_080D41F4: .4byte 0x0000037E
_080D41F8:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x24
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r2, #0xa3
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D422A
	ldr r0, _080D4244 @ =0x00000A76
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
_080D422A:
	ldr r1, _080D4244 @ =0x00000A76
	adds r2, r5, r1
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D424C
	movs r0, #0
	strb r0, [r2]
	ldr r2, _080D4248 @ =0x0000037D
	adds r1, r5, r2
	movs r0, #1
	strb r0, [r1]
	b _080D4462
	.align 2, 0
_080D4244: .4byte 0x00000A76
_080D4248: .4byte 0x0000037D
_080D424C:
	ldr r0, _080D4270 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xe
	bhi _080D4260
	b _080D4462
_080D4260:
	movs r0, #0
	strb r0, [r2]
	adds r0, r5, #0
	movs r1, #3
	movs r2, #7
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D4270: .4byte 0x0000037E
_080D4274:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x23
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D42AC @ =0x0000037E
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #4
	bhi _080D42A0
	b _080D4462
_080D42A0:
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	b _080D4462
	.align 2, 0
_080D42AC: .4byte 0x0000037E
_080D42B0:
	ldr r1, _080D4358 @ =0x000003D1
	adds r0, r5, r1
	movs r1, #0
	strb r1, [r0]
	adds r0, r5, #0
	bl FUN_080d19fc
	cmp r0, #0
	beq _080D42CA
	adds r0, r5, #0
	movs r1, #6
	bl FUN_080cc268
_080D42CA:
	ldr r2, _080D435C @ =0x0000037E
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r3, #3
	ands r3, r0
	adds r6, r5, #0
	adds r6, #0x2c
	cmp r3, #0
	bne _080D4310
	ldr r1, _080D4360 @ =0xFFFF0000
	ldr r2, _080D4364 @ =0x0000FFFF
	str r3, [sp, #0x20]
	ldr r0, [sp, #0x24]
	ands r0, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ands r0, r1
	movs r3, #0x20
	orrs r0, r3
	ands r0, r2
	str r0, [sp, #0x28]
	add r2, sp, #0x28
	ldr r0, [r2, #4]
	ands r0, r1
	orrs r0, r3
	str r0, [r2, #4]
	movs r0, #2
	str r0, [sp]
	movs r0, #4
	str r0, [sp, #4]
	adds r0, r6, #0
	add r1, sp, #0x20
	movs r3, #1
	bl FUN_080dbcec
_080D4310:
	ldr r0, _080D4368 @ =0x00000A8A
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #0x10
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4]
	ldrh r1, [r4]
	adds r0, r5, #0
	adds r2, r6, #0
	bl FUN_080cce0c
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #0x30]
	str r1, [sp, #0x34]
	ldrh r1, [r4]
	movs r0, #0xd0
	lsls r0, r0, #1
	subs r6, r0, r1
	movs r1, #0xff
	ands r6, r1
	ldr r2, _080D436C @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4370
	asrs r1, r0, #0xc
	b _080D4376
	.align 2, 0
_080D4358: .4byte 0x000003D1
_080D435C: .4byte 0x0000037E
_080D4360: .4byte 0xFFFF0000
_080D4364: .4byte 0x0000FFFF
_080D4368: .4byte 0x00000A8A
_080D436C: .4byte 0x085B0A08
_080D4370:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D4376:
	add r3, sp, #0x30
	ldrh r0, [r3]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D43AC @ =0xFFFF0000
	ldr r2, [sp, #0x30]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0xe6
	lsls r1, r1, #0x10
	ldr r0, _080D43B0 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x30]
	ldr r1, _080D43B4 @ =0x085B0A08
	lsls r0, r6, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xaa
	muls r0, r1, r0
	cmp r0, #0
	blt _080D43B8
	asrs r0, r0, #0xc
	b _080D43BE
	.align 2, 0
_080D43AC: .4byte 0xFFFF0000
_080D43B0: .4byte 0x0000FFFF
_080D43B4: .4byte 0x085B0A08
_080D43B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D43BE:
	ldrh r1, [r3, #4]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D4474 @ =0xFFFF0000
	ldr r0, [r3, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [r3, #4]
	movs r0, #0xa1
	lsls r0, r0, #4
	adds r4, r5, r0
	adds r0, r4, #0
	adds r1, r3, #0
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _080D4478 @ =0x00000A52
	adds r0, r5, r1
	strb r6, [r0]
	adds r0, r4, #0
	bl Hitbox_Register
	ldr r2, _080D447C @ =0x00000A8A
	adds r0, r5, r2
	ldrh r1, [r0]
	ldr r0, _080D4480 @ =0x0000010F
	subs r0, r0, r1
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #5
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cc1a0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x25
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D4484 @ =0x0000037E
	adds r4, r5, r2
	ldrh r1, [r4]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _080D443A
	ldr r0, [r5, #0x18]
	movs r1, #0x81
	lsls r1, r1, #2
	bl FUN_080cc3e4
_080D443A:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, _080D4488 @ =0x00000A8F
	adds r1, r5, r2
	ldrb r1, [r1]
	lsls r1, r1, #5
	cmp r0, r1
	blt _080D4462
	ldr r0, [r5, #0x18]
	ldr r1, _080D448C @ =0x00000202
	bl FUN_080cc410
	adds r0, r5, #0
	movs r1, #3
	movs r2, #6
	bl FUN_080cc348
_080D4462:
	ldr r0, _080D4490 @ =0x00000951
	adds r1, r5, r0
	movs r0, #9
	strb r0, [r1]
	add sp, #0x38
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D4474: .4byte 0xFFFF0000
_080D4478: .4byte 0x00000A52
_080D447C: .4byte 0x00000A8A
_080D4480: .4byte 0x0000010F
_080D4484: .4byte 0x0000037E
_080D4488: .4byte 0x00000A8F
_080D448C: .4byte 0x00000202
_080D4490: .4byte 0x00000951

	thumb_func_start FUN_080d4494
FUN_080d4494: @ 0x080D4494
	push {r4, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #3
	beq _080D44AE
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0
	bl FUN_080cc348
_080D44AE:
	ldr r1, _080D44C0 @ =0x00000A98
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D44C0: .4byte 0x00000A98

	thumb_func_start FUN_080d44c4
FUN_080d44c4: @ 0x080D44C4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x11
	beq _080D4528
	movs r2, #0xe4
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D44F0
	ldr r0, _080D44EC @ =0x000003FA
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	b _080D451E
	.align 2, 0
_080D44EC: .4byte 0x000003FA
_080D44F0:
	adds r0, r4, #0
	movs r1, #3
	bl FUN_080ced68
	adds r1, r0, #0
	cmp r1, #0
	beq _080D4518
	ldr r1, _080D4514 @ =0x000003FA
	adds r0, r4, r1
	movs r1, #1
	strb r1, [r0]
	adds r1, r4, #0
	adds r1, #0x2c
	adds r0, r4, #0
	movs r2, #0
	bl Entity080a8ff8_Create
	b _080D451E
	.align 2, 0
_080D4514: .4byte 0x000003FA
_080D4518:
	ldr r2, _080D453C @ =0x000003FA
	adds r0, r4, r2
	strb r1, [r0]
_080D451E:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #0
	bl FUN_080cc348
_080D4528:
	ldr r1, _080D4540 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D45A4
	cmp r0, #1
	bgt _080D4544
	cmp r0, #0
	beq _080D454E
	b _080D4630
	.align 2, 0
_080D453C: .4byte 0x000003FA
_080D4540: .4byte 0x0000037D
_080D4544:
	cmp r0, #2
	beq _080D45DC
	cmp r0, #3
	beq _080D4618
	b _080D4630
_080D454E:
	ldr r2, _080D458C @ =0x000003FA
	adds r5, r4, r2
	ldrb r0, [r5]
	cmp r0, #0
	beq _080D456A
	ldr r0, _080D4590 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D4594 @ =0x00000123
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r4, r2
	movs r0, #0x20
	strh r0, [r1]
_080D456A:
	adds r0, r4, #0
	movs r1, #0xb8
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4630
	ldrb r0, [r5]
	cmp r0, #0
	beq _080D4598
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #1
	bl FUN_080cc348
	b _080D4630
	.align 2, 0
_080D458C: .4byte 0x000003FA
_080D4590: .4byte 0x0000095E
_080D4594: .4byte 0x00000123
_080D4598:
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #2
	bl FUN_080cc348
	b _080D4630
_080D45A4:
	ldr r1, _080D45CC @ =0x000003FA
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D45C0
	ldr r2, _080D45D0 @ =0x0000095E
	adds r1, r4, r2
	ldr r0, _080D45D4 @ =0x00000123
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x20
	strh r0, [r1]
_080D45C0:
	ldr r2, _080D45D8 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _080D4600
	.align 2, 0
_080D45CC: .4byte 0x000003FA
_080D45D0: .4byte 0x0000095E
_080D45D4: .4byte 0x00000123
_080D45D8: .4byte 0x0000037E
_080D45DC:
	ldr r0, _080D4614 @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080D45F0
	ldr r0, [r4, #0x18]
	movs r1, #0xc9
	lsls r1, r1, #1
	bl FUN_080cc3e4
_080D45F0:
	adds r0, r4, #0
	movs r1, #0xc2
	movs r2, #0x40
	bl FUN_080cc1e8
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
_080D4600:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bls _080D4630
	adds r0, r4, #0
	movs r1, #0x11
	movs r2, #3
	bl FUN_080cc348
	b _080D4630
	.align 2, 0
_080D4614: .4byte 0x0000037E
_080D4618:
	adds r0, r4, #0
	movs r1, #0xbd
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4630
	adds r0, r4, #0
	movs r1, #0
	movs r2, #1
	bl FUN_080cc348
_080D4630:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d4638
FUN_080d4638: @ 0x080D4638
	push {r4, r5, lr}
	sub sp, #0x14
	adds r4, r0, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r1, _080D465C @ =0x0000037D
	adds r0, r4, r1
	ldrb r5, [r0]
	cmp r5, #1
	bne _080D4650
	b _080D475C
_080D4650:
	cmp r5, #1
	bgt _080D4660
	cmp r5, #0
	beq _080D466E
	b _080D4820
	.align 2, 0
_080D465C: .4byte 0x0000037D
_080D4660:
	cmp r5, #2
	bne _080D4666
	b _080D479C
_080D4666:
	cmp r5, #3
	bne _080D466C
	b _080D4810
_080D466C:
	b _080D4820
_080D466E:
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r2, [sp, #0xc]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080D46B4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	bl FUN_0823bac8
	movs r2, #0xfc
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D46BC
	movs r0, #4
	str r0, [sp]
	ldr r0, _080D46B8 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #0x10
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _080D46D4
	.align 2, 0
_080D46B4: .4byte 0x0000FFFF
_080D46B8: .4byte 0x00001FFF
_080D46BC:
	movs r0, #4
	str r0, [sp]
	ldr r0, _080D4704 @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #3
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080D46D4:
	ldr r0, [r4, #0x18]
	ldr r1, _080D4708 @ =0x000001AD
	bl FUN_080cc3e4
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r4, r0
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4714
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D470C @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	ldr r0, _080D4710 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D4724
	.align 2, 0
_080D4704: .4byte 0x00001FFF
_080D4708: .4byte 0x000001AD
_080D470C: .4byte 0x000002E6
_080D4710: .4byte 0x000002E7
_080D4714:
	lsrs r1, r1, #0x19
	ldr r2, _080D4750 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r1, _080D4754 @ =0x000002E7
	adds r0, r4, r1
	strb r2, [r0]
_080D4724:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #1
	bl FUN_080cc348
	ldr r0, _080D4758 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	b _080D4820
	.align 2, 0
_080D4750: .4byte 0x000002E6
_080D4754: .4byte 0x000002E7
_080D4758: .4byte 0x000003F6
_080D475C:
	ldr r2, _080D4794 @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080D4820
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #2
	bl FUN_080cc348
	ldr r0, _080D4798 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	adds r0, #0xef
	strb r5, [r0]
	ldr r0, [r4, #0x18]
	movs r1, #0xd7
	lsls r1, r1, #1
	bl FUN_080cc3e4
	b _080D4820
	.align 2, 0
_080D4794: .4byte 0x0000037E
_080D4798: .4byte 0x000003F6
_080D479C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r5, r4, r1
	ldrb r0, [r5]
	movs r1, #0x12
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r2, _080D47D8 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	subs r0, #0x3c
	strh r0, [r1]
	ldr r1, _080D47DC @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #4
	bne _080D47E8
	ldrb r0, [r5]
	cmp r0, #5
	bne _080D47E0
	ldr r0, [r4, #0x18]
	subs r1, #0x91
	bl FUN_080cc3e4
	b _080D47E8
	.align 2, 0
_080D47D8: .4byte 0x000003F6
_080D47DC: .4byte 0x0000037E
_080D47E0:
	ldr r0, [r4, #0x18]
	ldr r1, _080D4808 @ =0x00000305
	bl FUN_080cc3e4
_080D47E8:
	ldr r2, _080D480C @ =0x0000037E
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080D4820
	adds r0, r4, #0
	movs r1, #0x16
	movs r2, #3
	bl FUN_080cc348
	b _080D4820
	.align 2, 0
_080D4808: .4byte 0x00000305
_080D480C: .4byte 0x0000037E
_080D4810:
	ldr r0, _080D4828 @ =0x000003F6
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3c4
_080D4820:
	add sp, #0x14
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4828: .4byte 0x000003F6

	thumb_func_start FUN_080d482c
FUN_080d482c: @ 0x080D482C
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D48B6
	adds r0, r4, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_080cc348
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r4, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4878
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _080D4870 @ =0x000002E6
	adds r1, r4, r6
	strb r0, [r1]
	ldr r0, _080D4874 @ =0x000002E7
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	b _080D4888
	.align 2, 0
_080D4870: .4byte 0x000002E6
_080D4874: .4byte 0x000002E7
_080D4878:
	lsrs r1, r1, #0x19
	ldr r2, _080D48F4 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080D48F8 @ =0x000002E7
	adds r0, r4, r3
	strb r2, [r0]
_080D4888:
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D48FC @ =0x000003D6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _080D48B6
	ldr r0, [r4, #0x18]
	ldrh r1, [r5]
	bl FUN_080cc3e4
	movs r0, #0
	strh r0, [r5]
_080D48B6:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #0
	bne _080D48C4
	b _080D49CA
_080D48C4:
	ldr r2, _080D4900 @ =0x00000395
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D4950
	movs r3, #0xe6
	lsls r3, r3, #2
	adds r0, r4, r3
	ldr r2, [r0]
	movs r6, #0
	ldrsh r1, [r2, r6]
	movs r3, #0x2c
	ldrsh r0, [r4, r3]
	subs r3, r1, r0
	movs r6, #4
	ldrsh r1, [r2, r6]
	movs r2, #0x30
	ldrsh r0, [r4, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _080D4904
	asrs r0, r3, #3
	b _080D490A
	.align 2, 0
_080D48F4: .4byte 0x000002E6
_080D48F8: .4byte 0x000002E7
_080D48FC: .4byte 0x000003D6
_080D4900: .4byte 0x00000395
_080D4904:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D490A:
	strh r0, [r4, #0x34]
	cmp r1, #0
	blt _080D4914
	asrs r0, r1, #3
	b _080D491A
_080D4914:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D491A:
	strh r0, [r4, #0x38]
	ldr r3, _080D4948 @ =0x0000037E
	adds r5, r4, r3
	ldrh r1, [r5]
	cmp r1, #5
	bhi _080D49B2
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D493E
	ldr r0, [r4, #0x18]
	ldr r1, _080D494C @ =0x00000191
	bl FUN_080cc3e4
	adds r0, r4, #0
	adds r0, #0x2c
	bl FUN_080acd98
_080D493E:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	b _080D49B2
	.align 2, 0
_080D4948: .4byte 0x0000037E
_080D494C: .4byte 0x00000191
_080D4950:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r2, _080D4980 @ =0x085B0A08
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4984
	asrs r0, r0, #0xc
	b _080D498A
	.align 2, 0
_080D4980: .4byte 0x085B0A08
_080D4984:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D498A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r4, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D49A8
	asrs r0, r0, #0xc
	b _080D49AE
_080D49A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D49AE:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
_080D49B2:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r4, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _080D4A2C
_080D49CA:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _080D49F4 @ =0x00000395
	adds r0, r4, r2
	strb r1, [r0]
	ldr r3, _080D49F8 @ =0x000004C5
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D4A00
	ldr r6, _080D49FC @ =0x000004C7
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D4A00
	adds r0, r4, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_080cc348
	b _080D4A2C
	.align 2, 0
_080D49F4: .4byte 0x00000395
_080D49F8: .4byte 0x000004C5
_080D49FC: .4byte 0x000004C7
_080D4A00:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2a
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4A2C
	adds r0, r4, #0
	bl FUN_080cc1a0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D4A2C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d4a34
FUN_080d4a34: @ 0x080D4A34
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x19
	beq _080D4AA2
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #0
	bl FUN_080cc348
	movs r5, #0xba
	lsls r5, r5, #2
	adds r2, r4, r5
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4A7C
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D4A78 @ =0x000002E6
	adds r1, r4, r2
	strb r0, [r1]
	subs r5, #1
	adds r1, r4, r5
	movs r0, #1
	strb r0, [r1]
	b _080D4A8C
	.align 2, 0
_080D4A78: .4byte 0x000002E6
_080D4A7C:
	lsrs r1, r1, #0x19
	ldr r2, _080D4AB8 @ =0x000002E6
	adds r0, r4, r2
	movs r2, #0
	strb r1, [r0]
	ldr r5, _080D4ABC @ =0x000002E7
	adds r0, r4, r5
	strb r2, [r0]
_080D4A8C:
	ldr r0, _080D4AC0 @ =0x000003D6
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	beq _080D4AA2
	ldr r0, [r4, #0x18]
	ldrh r1, [r5]
	bl FUN_080cc3e4
	movs r0, #0
	strh r0, [r5]
_080D4AA2:
	ldr r1, _080D4AC4 @ =0x0000037D
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D4AAE
	b _080D4D28
_080D4AAE:
	lsls r0, r0, #2
	ldr r1, _080D4AC8 @ =_080D4ACC
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D4AB8: .4byte 0x000002E6
_080D4ABC: .4byte 0x000002E7
_080D4AC0: .4byte 0x000003D6
_080D4AC4: .4byte 0x0000037D
_080D4AC8: .4byte _080D4ACC
_080D4ACC: @ jump table
	.4byte _080D4AE0 @ case 0
	.4byte _080D4B1C @ case 1
	.4byte _080D4C38 @ case 2
	.4byte _080D4CD0 @ case 3
	.4byte _080D4CF4 @ case 4
_080D4AE0:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r5, _080D4B18 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bhi _080D4B0C
	b _080D4D28
_080D4B0C:
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #1
	bl FUN_080cc348
	b _080D4D28
	.align 2, 0
_080D4B18: .4byte 0x0000037E
_080D4B1C:
	ldr r1, _080D4B7C @ =0x0000037E
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4B30
	ldr r2, _080D4B80 @ =0x000003F6
	adds r1, r4, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
_080D4B30:
	movs r5, #0xd6
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4B84 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4B88
	asrs r0, r0, #0xc
	b _080D4B8E
	.align 2, 0
_080D4B7C: .4byte 0x0000037E
_080D4B80: .4byte 0x000003F6
_080D4B84: .4byte 0x085B0A08
_080D4B88:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4B8E:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	ldr r1, _080D4BB0 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4BB4
	asrs r0, r0, #0xc
	b _080D4BBA
	.align 2, 0
_080D4BB0: .4byte 0x085B0A08
_080D4BB4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4BBA:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r1, _080D4BE8 @ =0x0000037E
	adds r3, r4, r1
	ldrh r0, [r3]
	cmp r0, #3
	bls _080D4BF4
	ldr r2, _080D4BEC @ =0x000003F6
	adds r1, r4, r2
	ldrh r2, [r1]
	lsls r0, r0, #3
	cmp r2, r0
	blt _080D4BF0
	subs r0, r2, r0
	b _080D4BF2
	.align 2, 0
_080D4BE8: .4byte 0x0000037E
_080D4BEC: .4byte 0x000003F6
_080D4BF0:
	movs r0, #0
_080D4BF2:
	strh r0, [r1]
_080D4BF4:
	ldr r5, _080D4C30 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _080D4C0C
	b _080D4D28
_080D4C0C:
	ldr r2, _080D4C34 @ =0x000003F6
	adds r1, r4, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _080D4C18
	b _080D4D28
_080D4C18:
	strh r0, [r1]
	ldr r0, [r4, #0x18]
	movs r1, #0xaa
	lsls r1, r1, #2
	bl FUN_080cc3e4
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #2
	bl FUN_080cc348
	b _080D4D28
	.align 2, 0
_080D4C30: .4byte 0x0000037E
_080D4C34: .4byte 0x000003F6
_080D4C38:
	movs r5, #0xba
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4C6C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r5, #0
	ldrsh r1, [r0, r5]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4C70
	asrs r0, r0, #0xc
	b _080D4C76
	.align 2, 0
_080D4C6C: .4byte 0x085B0A08
_080D4C70:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4C76:
	rsbs r0, r0, #0
	strh r0, [r4, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r5, #0xd6
	lsls r5, r5, #1
	adds r0, r4, r5
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4C94
	asrs r0, r0, #0xc
	b _080D4C9A
_080D4C94:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4C9A:
	rsbs r0, r0, #0
	strh r0, [r4, #0x38]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4D28
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r4, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #3
	bl FUN_080cc348
	b _080D4D28
_080D4CD0:
	ldr r5, _080D4CF0 @ =0x0000037E
	adds r1, r4, r5
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x13
	bls _080D4D28
	adds r0, r4, #0
	movs r1, #0x19
	movs r2, #4
	bl FUN_080cc348
	b _080D4D28
	.align 2, 0
_080D4CF0: .4byte 0x0000037E
_080D4CF4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #0x2d
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4D28
	ldr r2, _080D4D30 @ =0x000003D2
	adds r1, r4, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_080cc1a0
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D4D28:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4D30: .4byte 0x000003D2

	thumb_func_start FUN_080d4d34
FUN_080d4d34: @ 0x080D4D34
	push {r4, r5, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x1a
	beq _080D4D96
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r4, r5, r2
	ldrb r0, [r4]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r0, #0xf5
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldrb r0, [r4]
	cmp r0, #5
	bne _080D4D7C
	ldr r0, [r5, #0x18]
	ldr r1, _080D4D78 @ =0x000002EB
	bl FUN_080cc3e4
	b _080D4D84
	.align 2, 0
_080D4D78: .4byte 0x000002EB
_080D4D7C:
	ldr r0, [r5, #0x18]
	movs r1, #0xe7
	bl FUN_080cc3e4
_080D4D84:
	ldr r0, [r5, #0x18]
	movs r1, #0xe6
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #0
	bl FUN_080cc348
_080D4D96:
	ldr r1, _080D4DAC @ =0x0000037D
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D4DA2
	b _080D4EF8
_080D4DA2:
	cmp r0, #1
	bgt _080D4DB0
	cmp r0, #0
	beq _080D4DBE
	b _080D4F98
	.align 2, 0
_080D4DAC: .4byte 0x0000037D
_080D4DB0:
	cmp r0, #2
	bne _080D4DB6
	b _080D4F46
_080D4DB6:
	cmp r0, #3
	bne _080D4DBC
	b _080D4F68
_080D4DBC:
	b _080D4F98
_080D4DBE:
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D4DF4 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4DF8
	asrs r0, r0, #0xc
	b _080D4DFE
	.align 2, 0
_080D4DF4: .4byte 0x085B0A08
_080D4DF8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4DFE:
	strh r0, [r5, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D4E1A
	asrs r0, r0, #0xc
	b _080D4E20
_080D4E1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D4E20:
	strh r0, [r5, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	ldrh r2, [r5, #0x34]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D4E90 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r5, #0x38]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D4E8A
	cmp r1, #0
	blt _080D4E8A
	ldr r0, _080D4E94 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D4E8A
	ldr r0, _080D4E98 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D4E9C
_080D4E8A:
	movs r4, #0
	b _080D4EAA
	.align 2, 0
_080D4E90: .4byte 0xFFFF0000
_080D4E94: .4byte 0x030046A8
_080D4E98: .4byte 0x030046AC
_080D4E9C:
	ldr r0, _080D4EBC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D4EAA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D4EC0
	adds r0, #4
	b _080D4ECC
	.align 2, 0
_080D4EBC: .4byte 0x030046A4
_080D4EC0:
	ldr r0, _080D4EF4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D4ECC:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080D4EDC
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D4EDC:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #1
	bl FUN_080cc348
	b _080D4F98
	.align 2, 0
_080D4EF4: .4byte 0x030046A4
_080D4EF8:
	adds r0, r5, #0
	adds r0, #0x9c
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D4F1E
	adds r0, r5, #0
	adds r0, #0x94
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D4F1E
	ldr r0, [r5, #0x18]
	movs r1, #0xd1
	bl FUN_080cc3e4
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
_080D4F1E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	movs r1, #0x2e
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #2
	bl FUN_080cc348
	b _080D4F98
_080D4F46:
	ldr r4, _080D4F64 @ =0x0000037E
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D4F98
	adds r0, r5, #0
	movs r1, #0x1a
	movs r2, #3
	bl FUN_080cc348
	b _080D4F98
	.align 2, 0
_080D4F64: .4byte 0x0000037E
_080D4F68:
	ldr r0, _080D4FA0 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _080D4F84
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D4F84:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080D4F98
	adds r0, r5, #0
	bl FUN_080d05e8
_080D4F98:
	add sp, #8
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D4FA0: .4byte 0x0000037E

	thumb_func_start FUN_080d4fa4
FUN_080d4fa4: @ 0x080D4FA4
	push {r4, r5, lr}
	sub sp, #0x10
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x1b
	beq _080D502E
	movs r4, #0xba
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D4FE4
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D4FE0 @ =0x000002E6
	adds r1, r5, r2
	strb r0, [r1]
	subs r4, #1
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _080D4FF4
	.align 2, 0
_080D4FE0: .4byte 0x000002E6
_080D4FE4:
	lsrs r1, r1, #0x19
	ldr r2, _080D500C @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r4, _080D5010 @ =0x000002E7
	adds r0, r5, r4
	strb r2, [r0]
_080D4FF4:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080D5014
	ldr r0, [r5, #0x18]
	subs r1, #0x6d
	bl FUN_080cc3e4
	b _080D501C
	.align 2, 0
_080D500C: .4byte 0x000002E6
_080D5010: .4byte 0x000002E7
_080D5014:
	ldr r0, [r5, #0x18]
	movs r1, #0xe7
	bl FUN_080cc3e4
_080D501C:
	ldr r0, [r5, #0x18]
	movs r1, #0xe6
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #0
	bl FUN_080cc348
_080D502E:
	ldr r2, _080D5044 @ =0x0000037D
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #4
	bls _080D503A
	b _080D53D8
_080D503A:
	lsls r0, r0, #2
	ldr r1, _080D5048 @ =_080D504C
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D5044: .4byte 0x0000037D
_080D5048: .4byte _080D504C
_080D504C: @ jump table
	.4byte _080D5060 @ case 0
	.4byte _080D50AC @ case 1
	.4byte _080D5244 @ case 2
	.4byte _080D5384 @ case 3
	.4byte _080D53A8 @ case 4
_080D5060:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D50A4 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bhi _080D508C
	b _080D53D8
_080D508C:
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #1
	bl FUN_080cc348
	ldr r2, _080D50A8 @ =0x000003F6
	adds r1, r5, r2
	movs r0, #0x96
	lsls r0, r0, #1
	strh r0, [r1]
	b _080D53D8
	.align 2, 0
_080D50A4: .4byte 0x0000037E
_080D50A8: .4byte 0x000003F6
_080D50AC:
	movs r4, #0xd6
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	movs r1, #0x2b
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D50F8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D50FC
	asrs r0, r0, #0xc
	b _080D5102
	.align 2, 0
_080D50F8: .4byte 0x085B0A08
_080D50FC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D5102:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	ldr r1, _080D5124 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D5128
	asrs r0, r0, #0xc
	b _080D512E
	.align 2, 0
_080D5124: .4byte 0x085B0A08
_080D5128:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D512E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r2]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	mov r0, sp
	ldrh r1, [r0]
	ldrh r2, [r5, #0x34]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D51A0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	mov r3, sp
	ldrh r0, [r3, #4]
	ldrh r4, [r5, #0x38]
	adds r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #4]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D519A
	cmp r1, #0
	blt _080D519A
	ldr r0, _080D51A4 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D519A
	ldr r0, _080D51A8 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D51AC
_080D519A:
	movs r4, #0
	b _080D51BA
	.align 2, 0
_080D51A0: .4byte 0xFFFF0000
_080D51A4: .4byte 0x030046A8
_080D51A8: .4byte 0x030046AC
_080D51AC:
	ldr r0, _080D51CC @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D51BA:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D51D0
	adds r0, #4
	b _080D51DC
	.align 2, 0
_080D51CC: .4byte 0x030046A4
_080D51D0:
	ldr r0, _080D51FC @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D51DC:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080D51EC
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D51EC:
	ldr r0, _080D5200 @ =0x000003F6
	adds r1, r5, r0
	ldrh r0, [r1]
	cmp r0, #0xe
	bls _080D5204
	subs r0, #0xf
	b _080D5206
	.align 2, 0
_080D51FC: .4byte 0x030046A4
_080D5200: .4byte 0x000003F6
_080D5204:
	movs r0, #0
_080D5206:
	strh r0, [r1]
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x13
	bls _080D5216
	b _080D53D8
_080D5216:
	ldr r2, _080D5240 @ =0x000003F6
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	movs r1, #0xaa
	lsls r1, r1, #2
	bl FUN_080cc3e4
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #2
	bl FUN_080cc348
	b _080D53D8
	.align 2, 0
_080D5240: .4byte 0x000003F6
_080D5244:
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D5278 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D527C
	asrs r0, r0, #0xc
	b _080D5282
	.align 2, 0
_080D5278: .4byte 0x085B0A08
_080D527C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D5282:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xd6
	lsls r4, r4, #1
	adds r0, r5, r4
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D52A0
	asrs r0, r0, #0xc
	b _080D52A6
_080D52A0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D52A6:
	rsbs r2, r0, #0
	strh r2, [r5, #0x38]
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	add r3, sp, #8
	ldrh r1, [r3]
	ldrh r0, [r5, #0x34]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r4, _080D5300 @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r4
	orrs r0, r1
	str r0, [sp, #8]
	ldrh r0, [r3, #4]
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r0, [r3, #4]
	ands r0, r4
	orrs r0, r2
	str r0, [r3, #4]
	ldrh r0, [r3]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r3, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D52FC
	cmp r1, #0
	blt _080D52FC
	ldr r0, _080D5304 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D52FC
	ldr r0, _080D5308 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D530C
_080D52FC:
	movs r4, #0
	b _080D531A
	.align 2, 0
_080D5300: .4byte 0xFFFF0000
_080D5304: .4byte 0x030046A8
_080D5308: .4byte 0x030046AC
_080D530C:
	ldr r0, _080D532C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D531A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D5330
	adds r0, #4
	b _080D533C
	.align 2, 0
_080D532C: .4byte 0x030046A4
_080D5330:
	ldr r0, _080D5380 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D533C:
	ldrh r0, [r0, #2]
	bl FUN_080cfc04
	cmp r0, #0
	beq _080D534C
	movs r0, #0
	strh r0, [r5, #0x34]
	strh r0, [r5, #0x38]
_080D534C:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x2c
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	cmp r0, #0
	beq _080D53D8
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r1, r5, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #3
	bl FUN_080cc348
	b _080D53D8
	.align 2, 0
_080D5380: .4byte 0x030046A4
_080D5384:
	ldr r4, _080D53A4 @ =0x0000037E
	adds r1, r5, r4
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D53D8
	adds r0, r5, #0
	movs r1, #0x1b
	movs r2, #4
	bl FUN_080cc348
	b _080D53D8
	.align 2, 0
_080D53A4: .4byte 0x0000037E
_080D53A8:
	ldr r0, _080D53E0 @ =0x0000037E
	adds r4, r5, r0
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #3
	subs r1, r1, r0
	cmp r2, r1
	blt _080D53C4
	adds r0, r5, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D53C4:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x37
	bls _080D53D8
	adds r0, r5, #0
	bl FUN_080d05e8
_080D53D8:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D53E0: .4byte 0x0000037E

	thumb_func_start FUN_080d53e4
FUN_080d53e4: @ 0x080D53E4
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r1, _080D5404 @ =0x0000037D
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #1
	beq _080D5458
	cmp r4, #1
	bgt _080D5408
	cmp r4, #0
	beq _080D5412
	b _080D5504
	.align 2, 0
_080D5404: .4byte 0x0000037D
_080D5408:
	cmp r4, #2
	beq _080D5494
	cmp r4, #3
	beq _080D54E4
	b _080D5504
_080D5412:
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r1, #0x29
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r5, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r1, _080D5450 @ =0x000003F6
	adds r0, r5, r1
	strh r4, [r0]
	str r4, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x2c
	ldr r1, [r5, #0x18]
	bl FUN_081df64c
	ldr r0, [r5, #0x18]
	ldr r1, _080D5454 @ =0x000001AD
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #1
	bl FUN_080cc348
	b _080D5504
	.align 2, 0
_080D5450: .4byte 0x000003F6
_080D5454: .4byte 0x000001AD
_080D5458:
	ldr r0, _080D5488 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080D5504
	ldr r0, _080D548C @ =0x000003F6
	adds r1, r5, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r5, #0x18]
	ldr r1, _080D5490 @ =0x000001AF
	bl FUN_080cc3e4
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #2
	bl FUN_080cc348
	b _080D5504
	.align 2, 0
_080D5488: .4byte 0x0000037E
_080D548C: .4byte 0x000003F6
_080D5490: .4byte 0x000001AF
_080D5494:
	adds r0, r5, #0
	movs r1, #0x2c
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r1, _080D54DC @ =0x000003F6
	adds r2, r5, r1
	ldrh r0, [r2]
	subs r0, #0x1e
	movs r3, #0
	strh r0, [r2]
	ldr r0, _080D54E0 @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #8
	bls _080D5504
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r3, [r0]
	strh r3, [r2]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3c4
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #3
	bl FUN_080cc348
	b _080D5504
	.align 2, 0
_080D54DC: .4byte 0x000003F6
_080D54E0: .4byte 0x0000037E
_080D54E4:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3c4
	ldr r0, _080D550C @ =0x0000037E
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080D5504
	adds r0, r5, #0
	bl FUN_080d05e8
_080D5504:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D550C: .4byte 0x0000037E

	thumb_func_start FUN_080d5510
FUN_080d5510: @ 0x080D5510
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D5534
	adds r0, r4, #0
	movs r1, #2
	movs r2, #0
	bl FUN_080cc348
	ldr r0, [r4, #0x18]
	movs r1, #0xd1
	lsls r1, r1, #2
	bl FUN_080cc3e4
_080D5534:
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3c4
	ldr r0, _080D555C @ =0x0000037E
	adds r5, r4, r0
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D5560
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
	b _080D55C8
	.align 2, 0
_080D555C: .4byte 0x0000037E
_080D5560:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_080cc3c4
	ldrh r0, [r5]
	subs r0, #5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080D557C
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3c4
_080D557C:
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080cc3c4
	ldr r0, _080D55D0 @ =0x0000095E
	adds r1, r4, r0
	ldr r0, _080D55D4 @ =0x00000127
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r4, r0
	movs r0, #0x18
	strh r0, [r1]
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D55AA
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_080cc268
_080D55AA:
	adds r0, r4, #0
	bl FUN_080cc1a0
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	movs r1, #1
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r4, #0
	movs r2, #0x40
	bl FUN_080cc1e8
_080D55C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D55D0: .4byte 0x0000095E
_080D55D4: .4byte 0x00000127

	thumb_func_start FUN_080d55d8
FUN_080d55d8: @ 0x080D55D8
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _080D561C
	adds r0, r6, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_080cc348
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080cdda8
	ldr r0, [r6, #0x18]
	ldr r1, _080D56E4 @ =0x0000039A
	bl FUN_080cc3e4
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl Entity080ac374_Create
_080D561C:
	ldr r0, _080D56E8 @ =0x0000037E
	adds r4, r6, r0
	ldrh r0, [r4]
	cmp r0, #0x10
	bne _080D562E
	ldr r0, [r6, #0x18]
	ldr r1, _080D56EC @ =0x000003A1
	bl FUN_080cc3e4
_080D562E:
	ldrh r0, [r4]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _080D5654
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_080cc3c4
	movs r1, #0x82
	lsls r1, r1, #1
	adds r2, r6, r1
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_080D5654:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrb r0, [r0]
	movs r1, #0
	bl FUN_08066ee4
	adds r1, r0, #0
	adds r0, r6, #0
	movs r2, #0x40
	bl FUN_080cc1e8
	ldr r0, _080D56F0 @ =0x0000095E
	adds r1, r6, r0
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080D568E
	movs r0, #0x20
	strh r0, [r1]
_080D568E:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D56F4 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _080D56F8
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5700
	.align 2, 0
_080D56E4: .4byte 0x0000039A
_080D56E8: .4byte 0x0000037E
_080D56EC: .4byte 0x000003A1
_080D56F0: .4byte 0x0000095E
_080D56F4: .4byte 0x000002E6
_080D56F8:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5700:
	str r0, [r5]
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
	beq _080D5724
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D572C
_080D5724:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D572C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5764 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D579C
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5768
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D575C
	ldrb r0, [r4, #5]
_080D575C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5778
	.align 2, 0
_080D5764: .4byte 0x0000FFFF
_080D5768:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5778
	strh r1, [r4, #8]
_080D5778:
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
	bne _080D579C
	movs r0, #1
	strb r0, [r4, #7]
_080D579C:
	movs r1, #0x8a
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	adds r1, #0xe
	bl Video_SetAuxSpritePltt
	ldr r2, _080D57E0 @ =0x0000037E
	adds r1, r6, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1f
	bls _080D57D8
	movs r0, #0xe0
	lsls r0, r0, #2
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	adds r2, #3
	adds r1, r6, r2
	movs r0, #3
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D57D8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D57E0: .4byte 0x0000037E

	thumb_func_start FUN_080d57e4
FUN_080d57e4: @ 0x080D57E4
	push {r4, r5, r6, lr}
	sub sp, #4
	adds r5, r0, #0
	ldr r0, [r5, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x20]
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D580A
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D580A:
	movs r2, #0xcf
	lsls r2, r2, #2
	adds r4, r5, r2
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	subs r2, #0x56
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r5, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080D585C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5864
_080D585C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5864:
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
	beq _080D5888
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5890
_080D5888:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5890:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D58C8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5900
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D58CC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D58C0
	ldrb r0, [r4, #5]
_080D58C0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D58DC
	.align 2, 0
_080D58C8: .4byte 0x0000FFFF
_080D58CC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D58DC
	strh r1, [r4, #8]
_080D58DC:
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
	bne _080D5900
	movs r0, #1
	strb r0, [r4, #7]
_080D5900:
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d5908
FUN_080d5908: @ 0x080D5908
	push {lr}
	adds r1, r0, #0
	movs r2, #0xc
	ldr r3, _080D5938 @ =0x000004C5
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #2
	bne _080D5924
	adds r3, #2
	adds r0, r1, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D5924
	movs r2, #8
_080D5924:
	ldr r0, _080D593C @ =0x00000402
	adds r1, r1, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D5930
	subs r2, r2, r0
_080D5930:
	cmp r2, #1
	ble _080D5940
	adds r0, r2, #0
	b _080D5942
	.align 2, 0
_080D5938: .4byte 0x000004C5
_080D593C: .4byte 0x00000402
_080D5940:
	movs r0, #2
_080D5942:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d5948
FUN_080d5948: @ 0x080D5948
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _080D596C
	ldr r2, _080D59EC @ =0x00000386
	adds r1, r6, r2
	movs r0, #0
	strb r0, [r1]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	bl FUN_080cc348
_080D596C:
	ldr r0, [r6, #0x20]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #0x20]
	adds r0, r6, #0
	bl FUN_080d0824
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r6, r2
	strb r0, [r1]
	adds r0, r6, #0
	bl FUN_080d5908
	adds r1, r0, #0
	adds r0, r6, #0
	bl FUN_080cc268
	adds r0, r6, #0
	bl FUN_080cc1a0
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r6, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D59F0 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _080D59F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D59FC
	.align 2, 0
_080D59EC: .4byte 0x00000386
_080D59F0: .4byte 0x000002E6
_080D59F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D59FC:
	str r0, [r5]
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
	beq _080D5A20
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5A28
_080D5A20:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5A28:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5A60 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5A98
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5A64
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5A58
	ldrb r0, [r4, #5]
_080D5A58:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5A74
	.align 2, 0
_080D5A60: .4byte 0x0000FFFF
_080D5A64:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5A74
	strh r1, [r4, #8]
_080D5A74:
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
	bne _080D5A98
	movs r0, #1
	strb r0, [r4, #7]
_080D5A98:
	movs r1, #0xd1
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #2
	bne _080D5AD8
	ldr r2, _080D5AC4 @ =0x0000034A
	adds r0, r6, r2
	ldrh r2, [r0]
	cmp r2, #0
	bne _080D5AD8
	ldr r0, _080D5AC8 @ =0x00000386
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _080D5ACC
	strb r2, [r1]
	ldr r0, [r6, #0x18]
	movs r1, #0xc7
	bl FUN_080cc3e4
	b _080D5AD8
	.align 2, 0
_080D5AC4: .4byte 0x0000034A
_080D5AC8: .4byte 0x00000386
_080D5ACC:
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r6, #0x18]
	movs r1, #0xc8
	bl FUN_080cc3e4
_080D5AD8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d5ae0
FUN_080d5ae0: @ 0x080D5AE0
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	adds r7, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _080D5BAA
	ldr r0, [r7, #0x2c]
	ldr r1, [r7, #0x30]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	movs r2, #0xba
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D5B28 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	lsls r0, r0, #6
	adds r4, r2, #0
	cmp r0, #0
	blt _080D5B2C
	asrs r1, r0, #0xc
	b _080D5B32
	.align 2, 0
_080D5B28: .4byte 0x085B0A08
_080D5B2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080D5B32:
	add r0, sp, #0xc
	ldrh r0, [r0]
	adds r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _080D5B64 @ =0xFFFF0000
	ldr r2, [sp, #0xc]
	ands r2, r1
	orrs r2, r0
	asrs r1, r2, #0x10
	adds r1, #0x40
	lsls r1, r1, #0x10
	ldr r0, _080D5B68 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0xc]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r0, [r0, r2]
	lsls r0, r0, #6
	cmp r0, #0
	blt _080D5B6C
	asrs r2, r0, #0xc
	b _080D5B72
	.align 2, 0
_080D5B64: .4byte 0xFFFF0000
_080D5B68: .4byte 0x0000FFFF
_080D5B6C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D5B72:
	add r0, sp, #0xc
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D5C00 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	adds r0, r7, #0
	movs r1, #4
	movs r2, #0
	bl FUN_080cc348
	adds r1, r7, #0
	adds r1, #0x2c
	add r0, sp, #0xc
	str r0, [sp]
	movs r0, #0
	str r0, [sp, #4]
	ldr r0, _080D5C04 @ =0x000003A1
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r2, #1
	movs r3, #1
	bl FUN_080d03bc
_080D5BAA:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r7, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080D5C08
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5C10
	.align 2, 0
_080D5C00: .4byte 0xFFFF0000
_080D5C04: .4byte 0x000003A1
_080D5C08:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5C10:
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
	beq _080D5C34
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5C3C
_080D5C34:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5C3C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5C74 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5CAC
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5C78
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5C6C
	ldrb r0, [r4, #5]
_080D5C6C:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5C88
	.align 2, 0
_080D5C74: .4byte 0x0000FFFF
_080D5C78:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5C88
	strh r1, [r4, #8]
_080D5C88:
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
	bne _080D5CAC
	movs r0, #1
	strb r0, [r4, #7]
_080D5CAC:
	ldr r0, _080D5CD0 @ =0x0000037E
	adds r1, r7, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080D5CC8
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D5CC8:
	add sp, #0x14
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D5CD0: .4byte 0x0000037E

	thumb_func_start FUN_080d5cd4
FUN_080d5cd4: @ 0x080D5CD4
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0x14
	beq _080D5CF0
	adds r0, r6, #0
	movs r1, #0x14
	movs r2, #0
	bl FUN_080cc348
_080D5CF0:
	movs r2, #0xa4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080D5D44
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r6, r0
	movs r0, #0xfe
	ands r0, r1
	adds r0, #1
	strb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D5D34
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D5D2C @ =0x000002E6
	adds r1, r6, r2
	strb r0, [r1]
	ldr r0, _080D5D30 @ =0x000002E7
	adds r1, r6, r0
	movs r0, #1
	b _080D5D42
	.align 2, 0
_080D5D2C: .4byte 0x000002E6
_080D5D30: .4byte 0x000002E7
_080D5D34:
	lsrs r1, r1, #0x19
	ldr r2, _080D5D98 @ =0x000002E6
	adds r0, r6, r2
	strb r1, [r0]
	ldr r0, _080D5D9C @ =0x000002E7
	adds r1, r6, r0
	movs r0, #0
_080D5D42:
	strb r0, [r1]
_080D5D44:
	movs r1, #0xcf
	lsls r1, r1, #2
	adds r4, r6, r1
	movs r2, #0xd4
	lsls r2, r2, #2
	adds r0, r6, r2
	ldr r1, [r0]
	subs r2, #0x6a
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _080D5DA0
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5DA8
	.align 2, 0
_080D5D98: .4byte 0x000002E6
_080D5D9C: .4byte 0x000002E7
_080D5DA0:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5DA8:
	str r0, [r5]
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
	beq _080D5DCC
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5DD4
_080D5DCC:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5DD4:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5E0C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5E44
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5E10
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5E04
	ldrb r0, [r4, #5]
_080D5E04:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5E20
	.align 2, 0
_080D5E0C: .4byte 0x0000FFFF
_080D5E10:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5E20
	strh r1, [r4, #8]
_080D5E20:
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
	bne _080D5E44
	movs r0, #1
	strb r0, [r4, #7]
_080D5E44:
	ldr r1, _080D5E6C @ =0x000003FF
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0
	bge _080D5E62
	adds r0, r6, #0
	bl FUN_080cc1a0
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D5E62:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D5E6C: .4byte 0x000003FF

	thumb_func_start FUN_080d5e70
FUN_080d5e70: @ 0x080D5E70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #8
	bl FUN_080cc3c4
	ldr r1, _080D5E94 @ =0x0000037D
	adds r0, r7, r1
	ldrb r0, [r0]
	mov r8, r0
	cmp r0, #0
	beq _080D5E98
	cmp r0, #1
	bne _080D5E92
	b _080D600E
_080D5E92:
	b _080D6130
	.align 2, 0
_080D5E94: .4byte 0x0000037D
_080D5E98:
	movs r0, #0xba
	lsls r0, r0, #2
	adds r2, r7, r0
	ldrb r0, [r2]
	movs r1, #1
	orrs r1, r0
	strb r1, [r2]
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D5ED0
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r2, _080D5EC8 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r0, _080D5ECC @ =0x000002E7
	adds r1, r7, r0
	movs r0, #1
	strb r0, [r1]
	b _080D5EE0
	.align 2, 0
_080D5EC8: .4byte 0x000002E6
_080D5ECC: .4byte 0x000002E7
_080D5ED0:
	lsrs r0, r1, #0x19
	ldr r2, _080D5F34 @ =0x000002E6
	adds r1, r7, r2
	strb r0, [r1]
	ldr r1, _080D5F38 @ =0x000002E7
	adds r0, r7, r1
	mov r2, r8
	strb r2, [r0]
_080D5EE0:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _080D5F34 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
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
	beq _080D5F3C
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D5F44
	.align 2, 0
_080D5F34: .4byte 0x000002E6
_080D5F38: .4byte 0x000002E7
_080D5F3C:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D5F44:
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
	beq _080D5F68
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D5F70
_080D5F68:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D5F70:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D5FA8 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D5FE0
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D5FAC
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D5FA0
	ldrb r0, [r4, #5]
_080D5FA0:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D5FBC
	.align 2, 0
_080D5FA8: .4byte 0x0000FFFF
_080D5FAC:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D5FBC
	strh r1, [r4, #8]
_080D5FBC:
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
	bne _080D5FE0
	movs r0, #1
	strb r0, [r4, #7]
_080D5FE0:
	movs r0, #0xfe
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r0, [r1]
	cmp r0, #0x1e
	bhi _080D6008
	movs r0, #0
	strh r0, [r1]
	ldr r0, [r7, #0x18]
	movs r1, #0xd8
	lsls r1, r1, #1
	bl FUN_080cc3e4
	ldr r2, _080D6004 @ =0x0000037D
	adds r1, r7, r2
	movs r0, #1
	strb r0, [r1]
	b _080D6130
	.align 2, 0
_080D6004: .4byte 0x0000037D
_080D6008:
	subs r0, #0x1e
	strh r0, [r1]
	b _080D6130
_080D600E:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r7, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r7, r1
	ldr r1, [r0]
	ldr r2, _080D6064 @ =0x000002E6
	adds r0, r7, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r7, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #3
	bl FUN_08236fac
	adds r5, r7, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r6, r1, r0
	ldrh r0, [r6]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
	ldrb r0, [r4, #4]
	mov r1, r8
	ands r1, r0
	ldrh r2, [r6]
	movs r0, #0x30
	ands r0, r2
	lsrs r0, r0, #4
	mov r2, r8
	ands r0, r2
	cmp r1, r0
	beq _080D6068
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D6070
	.align 2, 0
_080D6064: .4byte 0x000002E6
_080D6068:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D6070:
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
	beq _080D6094
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D609C
_080D6094:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D609C:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D60D4 @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D611A
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D60DE
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D60D8
	ldrb r0, [r4, #5]
	subs r0, #1
	strh r0, [r4, #8]
	movs r2, #1
	b _080D60F4
	.align 2, 0
_080D60D4: .4byte 0x0000FFFF
_080D60D8:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D60F2
_080D60DE:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D60F2
	strh r1, [r4, #8]
	movs r2, #1
	b _080D60F4
_080D60F2:
	movs r2, #0
_080D60F4:
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
	bne _080D611C
	movs r0, #1
	strb r0, [r4, #7]
	b _080D611C
_080D611A:
	movs r2, #0
_080D611C:
	cmp r2, #0
	beq _080D6130
	adds r0, r7, #0
	bl FUN_080cc1a0
	adds r0, r7, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D6130:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d613c
FUN_080d613c: @ 0x080D613C
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D61B0
	movs r3, #0xba
	lsls r3, r3, #2
	adds r2, r5, r3
	ldrb r0, [r2]
	lsls r1, r0, #0x18
	lsrs r0, r1, #0x18
	cmp r0, #4
	bls _080D6180
	ldrb r1, [r2]
	movs r0, #8
	subs r0, r0, r1
	asrs r0, r0, #1
	ldr r6, _080D6178 @ =0x000002E6
	adds r1, r5, r6
	strb r0, [r1]
	ldr r0, _080D617C @ =0x000002E7
	adds r1, r5, r0
	movs r0, #1
	strb r0, [r1]
	b _080D6190
	.align 2, 0
_080D6178: .4byte 0x000002E6
_080D617C: .4byte 0x000002E7
_080D6180:
	lsrs r1, r1, #0x19
	ldr r2, _080D6204 @ =0x000002E6
	adds r0, r5, r2
	movs r2, #0
	strb r1, [r0]
	ldr r3, _080D6208 @ =0x000002E7
	adds r0, r5, r3
	strb r2, [r0]
_080D6190:
	ldr r6, _080D620C @ =0x000003D6
	adds r4, r5, r6
	ldrh r0, [r4]
	cmp r0, #0
	beq _080D61A6
	ldr r0, [r5, #0x18]
	ldrh r1, [r4]
	bl FUN_080cc3e4
	movs r0, #0
	strh r0, [r4]
_080D61A6:
	adds r0, r5, #0
	movs r1, #0x18
	movs r2, #0
	bl FUN_080cc348
_080D61B0:
	movs r0, #0xcf
	lsls r0, r0, #2
	adds r4, r5, r0
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0]
	ldr r2, _080D6204 @ =0x000002E6
	adds r0, r5, r2
	ldrb r3, [r0]
	ldr r6, _080D6208 @ =0x000002E7
	adds r0, r5, r6
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_08236fac
	adds r6, r5, #0
	adds r6, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r6, #0x10]
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
	beq _080D6210
	ldr r0, [r6]
	movs r1, #4
	orrs r0, r1
	b _080D6218
	.align 2, 0
_080D6204: .4byte 0x000002E6
_080D6208: .4byte 0x000002E7
_080D620C: .4byte 0x000003D6
_080D6210:
	ldr r0, [r6]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D6218:
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
	beq _080D623C
	ldr r0, [r6]
	movs r1, #8
	orrs r0, r1
	b _080D6244
_080D623C:
	ldr r0, [r6]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D6244:
	str r0, [r6]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r1, _080D627C @ =0x0000FFFF
	adds r2, r1, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r3, [r4, #7]
	cmp r0, r3
	blo _080D62B4
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D6280
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D6274
	ldrb r0, [r4, #5]
_080D6274:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D6290
	.align 2, 0
_080D627C: .4byte 0x0000FFFF
_080D6280:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r6, [r4, #5]
	cmp r0, r6
	blo _080D6290
	strh r1, [r4, #8]
_080D6290:
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
	bne _080D62B4
	movs r0, #1
	strb r0, [r4, #7]
_080D62B4:
	movs r0, #0xd6
	lsls r0, r0, #1
	adds r3, r5, r0
	ldrh r0, [r3]
	cmp r0, #0
	bne _080D62C2
	b _080D63BA
_080D62C2:
	ldr r1, _080D62F0 @ =0x00000395
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6340
	movs r2, #0xe6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r2, [r0]
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r6, #0x2c
	ldrsh r0, [r5, r6]
	subs r3, r1, r0
	movs r0, #4
	ldrsh r1, [r2, r0]
	movs r2, #0x30
	ldrsh r0, [r5, r2]
	subs r1, r1, r0
	cmp r3, #0
	blt _080D62F4
	asrs r0, r3, #3
	b _080D62FA
	.align 2, 0
_080D62F0: .4byte 0x00000395
_080D62F4:
	rsbs r0, r3, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D62FA:
	strh r0, [r5, #0x34]
	cmp r1, #0
	blt _080D6304
	asrs r0, r1, #3
	b _080D630A
_080D6304:
	rsbs r0, r1, #0
	asrs r0, r0, #3
	rsbs r0, r0, #0
_080D630A:
	strh r0, [r5, #0x38]
	ldr r3, _080D6338 @ =0x0000037E
	adds r4, r5, r3
	ldrh r1, [r4]
	cmp r1, #5
	bhi _080D63A2
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D632E
	ldr r0, [r5, #0x18]
	ldr r1, _080D633C @ =0x00000191
	bl FUN_080cc3e4
	adds r0, r5, #0
	adds r0, #0x2c
	bl FUN_080acd98
_080D632E:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	b _080D63A2
	.align 2, 0
_080D6338: .4byte 0x0000037E
_080D633C: .4byte 0x00000191
_080D6340:
	movs r6, #0xba
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r4, r0, #5
	ldr r2, _080D6370 @ =0x085B0A08
	adds r0, r4, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	ldrh r0, [r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6374
	asrs r0, r0, #0xc
	b _080D637A
	.align 2, 0
_080D6370: .4byte 0x085B0A08
_080D6374:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D637A:
	rsbs r0, r0, #0
	strh r0, [r5, #0x34]
	lsls r0, r4, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xd6
	lsls r3, r3, #1
	adds r0, r5, r3
	ldrh r0, [r0]
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6398
	asrs r0, r0, #0xc
	b _080D639E
_080D6398:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D639E:
	rsbs r0, r0, #0
	strh r0, [r5, #0x38]
_080D63A2:
	movs r6, #0xd6
	lsls r6, r6, #1
	adds r4, r5, r6
	ldrh r0, [r4]
	bl FUN_0823b9cc
	ldrh r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	asrs r0, r0, #2
	strh r0, [r4]
	b _080D6400
_080D63BA:
	movs r1, #0
	strh r0, [r3]
	ldr r2, _080D63E4 @ =0x00000395
	adds r0, r5, r2
	strb r1, [r0]
	ldr r3, _080D63E8 @ =0x000004C5
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D63F0
	ldr r6, _080D63EC @ =0x000004C7
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D63F0
	adds r0, r5, #0
	movs r1, #0x13
	movs r2, #0
	bl FUN_080cc348
	b _080D6400
	.align 2, 0
_080D63E4: .4byte 0x00000395
_080D63E8: .4byte 0x000004C5
_080D63EC: .4byte 0x000004C7
_080D63F0:
	adds r0, r5, #0
	bl FUN_080cc1a0
	adds r0, r5, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D6400:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d6408
FUN_080d6408: @ 0x080D6408
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	beq _080D644C
	adds r0, r6, #0
	movs r1, #0xd
	movs r2, #0
	bl FUN_080cc348
	movs r2, #0x96
	lsls r2, r2, #4
	adds r1, r6, r2
	movs r0, #0
	strh r0, [r1]
	adds r0, r6, #0
	bl FUN_080cdda8
	ldr r0, [r6, #0x18]
	ldr r1, _080D64E4 @ =0x0000039A
	bl FUN_080cc3e4
	movs r0, #0x38
	str r0, [sp]
	adds r0, r6, #0
	movs r1, #1
	movs r2, #0
	movs r3, #0x20
	bl Entity080ac374_Create
_080D644C:
	ldr r3, _080D64E8 @ =0x0000037E
	adds r0, r6, r3
	ldrh r0, [r0]
	movs r1, #7
	adds r2, r1, #0
	ands r2, r0
	lsrs r0, r0, #2
	subs r1, r1, r0
	cmp r2, r1
	blt _080D6474
	adds r0, r6, #0
	movs r1, #0x41
	bl FUN_080cc3c4
	adds r2, r6, #0
	adds r2, #0xa8
	ldr r0, [r6, #0x2c]
	ldr r1, [r6, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
_080D6474:
	adds r0, r6, #0
	movs r1, #0xc7
	movs r2, #0x40
	bl FUN_080cc1e8
	adds r1, r6, #0
	adds r1, #0xd0
	ldr r0, _080D64EC @ =0x03003584
	ldr r0, [r0]
	movs r2, #0x91
	lsls r2, r2, #6
	adds r0, r0, r2
	str r0, [r1]
	movs r3, #0xcf
	lsls r3, r3, #2
	adds r4, r6, r3
	movs r1, #0xd4
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r1, [r0]
	ldr r2, _080D64F0 @ =0x000002E6
	adds r0, r6, r2
	ldrb r3, [r0]
	adds r2, #1
	adds r0, r6, r2
	ldrb r0, [r0]
	str r0, [sp]
	adds r0, r4, #0
	movs r2, #0
	bl FUN_08236fac
	adds r5, r6, #0
	adds r5, #0xe8
	ldrh r0, [r4, #8]
	lsls r0, r0, #1
	ldr r1, [r4]
	adds r7, r1, r0
	ldrh r0, [r7]
	lsrs r0, r0, #6
	strh r0, [r5, #0x10]
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
	beq _080D64F4
	ldr r0, [r5]
	movs r1, #4
	orrs r0, r1
	b _080D64FC
	.align 2, 0
_080D64E4: .4byte 0x0000039A
_080D64E8: .4byte 0x0000037E
_080D64EC: .4byte 0x03003584
_080D64F0: .4byte 0x000002E6
_080D64F4:
	ldr r0, [r5]
	movs r1, #5
	rsbs r1, r1, #0
	ands r0, r1
_080D64FC:
	str r0, [r5]
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
	beq _080D6520
	ldr r0, [r5]
	movs r1, #8
	orrs r0, r1
	b _080D6528
_080D6520:
	ldr r0, [r5]
	movs r1, #9
	rsbs r1, r1, #0
	ands r0, r1
_080D6528:
	str r0, [r5]
	ldrh r0, [r4, #0xe]
	adds r0, #1
	strh r0, [r4, #0xe]
	ldr r3, _080D6560 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldrb r1, [r4, #7]
	cmp r0, r1
	blo _080D6598
	movs r0, #0
	strh r0, [r4, #0xe]
	ldrb r1, [r4, #4]
	movs r0, #4
	ands r0, r1
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0
	beq _080D6564
	ldrh r0, [r4, #8]
	cmp r0, #0
	bne _080D6558
	ldrb r0, [r4, #5]
_080D6558:
	subs r0, #1
	strh r0, [r4, #8]
	b _080D6574
	.align 2, 0
_080D6560: .4byte 0x0000FFFF
_080D6564:
	ldrh r0, [r4, #8]
	adds r0, #1
	strh r0, [r4, #8]
	ands r0, r2
	ldrb r2, [r4, #5]
	cmp r0, r2
	blo _080D6574
	strh r1, [r4, #8]
_080D6574:
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
	bne _080D6598
	movs r0, #1
	strb r0, [r4, #7]
_080D6598:
	ldr r3, _080D65F0 @ =0x0000095E
	adds r1, r6, r3
	movs r0, #0x91
	lsls r0, r0, #1
	strh r0, [r1]
	movs r0, #0x96
	lsls r0, r0, #4
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #3
	strh r0, [r1]
	ldr r3, _080D65F4 @ =0x0000FFFF
	adds r2, r3, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x20
	bls _080D65BE
	movs r0, #0x20
	strh r0, [r1]
_080D65BE:
	ldr r0, _080D65F8 @ =0x0000037E
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ands r0, r2
	cmp r0, #0x1f
	bls _080D65E8
	movs r1, #0xe0
	lsls r1, r1, #2
	adds r0, r6, r1
	movs r1, #1
	strb r1, [r0]
	ldr r2, _080D65FC @ =0x00000381
	adds r0, r6, r2
	strb r1, [r0]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_080cc348
_080D65E8:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080D65F0: .4byte 0x0000095E
_080D65F4: .4byte 0x0000FFFF
_080D65F8: .4byte 0x0000037E
_080D65FC: .4byte 0x00000381

	thumb_func_start FUN_080d6600
FUN_080d6600: @ 0x080D6600
	push {r4, lr}
	adds r4, r0, #0
	movs r2, #9
	movs r0, #0xa8
	lsls r0, r0, #2
	adds r1, r4, r0
_080D660C:
	ldrh r0, [r1]
	strh r0, [r1, #2]
	subs r1, #2
	subs r2, #1
	cmp r2, #0
	bgt _080D660C
	adds r0, r4, #0
	bl FUN_0807849c
	adds r1, r0, #0
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r2, r4, r3
	strh r1, [r2]
	lsls r0, r1, #0x10
	cmp r0, #0
	blt _080D6642
	ldr r3, _080D6648 @ =0x00000456
	adds r0, r4, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	adds r0, r1, r0
	adds r0, #7
	movs r1, #7
	ands r0, r1
	strh r0, [r2]
_080D6642:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D6648: .4byte 0x00000456

	thumb_func_start FUN_080d664c
FUN_080d664c: @ 0x080D664C
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _080D66C0 @ =0x000003F3
	adds r0, r5, r1
	ldrb r4, [r0]
	cmp r4, #0
	beq _080D665E
	b _080D67AE
_080D665E:
	ldr r2, _080D66C4 @ =0x000003BD
	adds r0, r5, r2
	ldrb r3, [r0]
	adds r2, r3, #7
	movs r0, #7
	ands r2, r0
	adds r1, r3, #0
	adds r1, #9
	ands r1, r0
	movs r6, #0xa4
	lsls r6, r6, #2
	adds r0, r5, r6
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r0, r3
	beq _080D6688
	cmp r0, r2
	beq _080D6688
	cmp r0, r1
	beq _080D6688
	b _080D67DC
_080D6688:
	ldr r1, _080D66C4 @ =0x000003BD
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #1
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, _080D66C8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D66CC
	asrs r2, r0, #0xc
	b _080D66D2
	.align 2, 0
_080D66C0: .4byte 0x000003F3
_080D66C4: .4byte 0x000003BD
_080D66C8: .4byte 0x085B0A08
_080D66CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D66D2:
	mov r0, sp
	ldrh r1, [r0]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D66FC @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6700
	asrs r2, r0, #0xc
	b _080D6706
	.align 2, 0
_080D66FC: .4byte 0xFFFF0000
_080D6700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6706:
	mov r0, sp
	ldrh r1, [r0, #4]
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6748 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6742
	cmp r1, #0
	blt _080D6742
	ldr r0, _080D674C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6742
	ldr r0, _080D6750 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6754
_080D6742:
	movs r4, #0
	b _080D6762
	.align 2, 0
_080D6748: .4byte 0xFFFF0000
_080D674C: .4byte 0x030046A8
_080D6750: .4byte 0x030046AC
_080D6754:
	ldr r0, _080D6774 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6762:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D6778
	adds r0, #4
	b _080D6784
	.align 2, 0
_080D6774: .4byte 0x030046A4
_080D6778:
	ldr r0, _080D6798 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6784:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D679C
	cmp r2, #2
	beq _080D67A0
	b _080D67A4
	.align 2, 0
_080D6798: .4byte 0x030046A4
_080D679C:
	ldrb r0, [r6, #4]
	b _080D67A2
_080D67A0:
	ldrb r0, [r6]
_080D67A2:
	subs r1, r1, r0
_080D67A4:
	movs r2, #0x2e
	ldrsh r0, [r5, r2]
	adds r0, #0xc8
	cmp r1, r0
	blo _080D67B2
_080D67AE:
	movs r0, #1
	b _080D67FA
_080D67B2:
	ldr r4, _080D67D8 @ =0x000003BD
	adds r0, r5, r4
	ldrb r0, [r0]
	adds r0, #4
	movs r1, #7
	ands r0, r1
	movs r6, #0xba
	lsls r6, r6, #2
	adds r1, r5, r6
	movs r4, #0
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cc1a0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	b _080D67F6
	.align 2, 0
_080D67D8: .4byte 0x000003BD
_080D67DC:
	adds r0, r3, #4
	movs r1, #7
	ands r0, r1
	movs r2, #0xba
	lsls r2, r2, #2
	adds r1, r5, r2
	strb r0, [r1]
	adds r0, r5, #0
	bl FUN_080cc1a0
	movs r6, #0xdf
	lsls r6, r6, #2
	adds r0, r5, r6
_080D67F6:
	strb r4, [r0]
	movs r0, #0
_080D67FA:
	add sp, #8
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d6804
FUN_080d6804: @ 0x080D6804
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r4, [r0]
	ldr r2, _080D686C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6828
	ldr r3, _080D6870 @ =0x00000442
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6828
	movs r1, #1
_080D6828:
	cmp r1, #0
	bne _080D6848
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r0, [r0]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D6848
	adds r0, r5, #0
	bl FUN_080ced90
	adds r4, r0, #0
_080D6848:
	movs r2, #0xd6
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D6878
	ldr r3, _080D6874 @ =0x000003D2
	adds r0, r5, r3
	ldrb r0, [r0]
	movs r4, #0x18
	cmp r0, #0
	beq _080D6862
	movs r4, #0x19
_080D6862:
	adds r0, r5, #0
	bl FUN_08078548
	b _080D69D4
	.align 2, 0
_080D686C: .4byte 0x00000446
_080D6870: .4byte 0x00000442
_080D6874: .4byte 0x000003D2
_080D6878:
	adds r0, r4, #0
	subs r0, #0x18
	cmp r0, #1
	bls _080D68A2
	cmp r4, #0x16
	beq _080D68A2
	cmp r4, #0x17
	beq _080D68A2
	cmp r4, #0x15
	beq _080D68A2
	cmp r4, #0x14
	beq _080D68A2
	cmp r4, #0x13
	beq _080D68A2
	movs r1, #0xfb
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D68A2
	movs r4, #0x12
_080D68A2:
	subs r0, r4, #2
	cmp r0, #0x1e
	bhi _080D6942
	lsls r0, r0, #2
	ldr r1, _080D68B4 @ =_080D68B8
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080D68B4: .4byte _080D68B8
_080D68B8: @ jump table
	.4byte _080D69D4 @ case 0
	.4byte _080D69D4 @ case 1
	.4byte _080D6934 @ case 2
	.4byte _080D693E @ case 3
	.4byte _080D693E @ case 4
	.4byte _080D69D4 @ case 5
	.4byte _080D693E @ case 6
	.4byte _080D693E @ case 7
	.4byte _080D693E @ case 8
	.4byte _080D693E @ case 9
	.4byte _080D693E @ case 10
	.4byte _080D69D4 @ case 11
	.4byte _080D693E @ case 12
	.4byte _080D69D4 @ case 13
	.4byte _080D693E @ case 14
	.4byte _080D69D4 @ case 15
	.4byte _080D693E @ case 16
	.4byte _080D693E @ case 17
	.4byte _080D693E @ case 18
	.4byte _080D693E @ case 19
	.4byte _080D69D4 @ case 20
	.4byte _080D69D4 @ case 21
	.4byte _080D69D4 @ case 22
	.4byte _080D69D4 @ case 23
	.4byte _080D6942 @ case 24
	.4byte _080D6942 @ case 25
	.4byte _080D6942 @ case 26
	.4byte _080D6942 @ case 27
	.4byte _080D6942 @ case 28
	.4byte _080D6942 @ case 29
	.4byte _080D693E @ case 30
_080D6934:
	adds r0, r5, #0
	bl FUN_080d664c
	cmp r0, #0
	bne _080D69D4
_080D693E:
	movs r4, #0
	b _080D69D4
_080D6942:
	ldr r2, _080D697C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D695A
	ldr r3, _080D6980 @ =0x00000442
	adds r0, r5, r3
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D695A
	movs r1, #1
_080D695A:
	cmp r1, #0
	beq _080D6984
	movs r1, #0xa4
	lsls r1, r1, #2
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D693E
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r0, r5, r3
	ldr r0, [r0]
	ldrh r1, [r0]
	b _080D69C8
	.align 2, 0
_080D697C: .4byte 0x00000446
_080D6980: .4byte 0x00000442
_080D6984:
	movs r1, #0xa3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r2, [r0]
	ldrh r1, [r2, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D699A
	movs r4, #3
	b _080D69D4
_080D699A:
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D69B4
	adds r0, r5, #0
	adds r0, #0x24
	bl MapItemManager_TryOpen
	lsls r0, r0, #0x18
	movs r4, #7
	cmp r0, #0
	beq _080D69D4
	b _080D693E
_080D69B4:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r5, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D693E
	ldrh r1, [r2]
_080D69C8:
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D693E
	movs r4, #1
_080D69D4:
	adds r0, r4, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d69dc
FUN_080d69dc: @ 0x080D69DC
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r4, [r0]
	cmp r4, #0
	bne _080D6A10
	adds r0, r5, #0
	movs r1, #0x10
	bl FUN_080cc3d4
	cmp r0, #0
	bne _080D6A0E
	ldr r0, [r5, #0x3c]
	cmp r0, #0
	bne _080D6A10
	movs r2, #0xde
	lsls r2, r2, #1
	adds r4, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	adds r0, r4, #0
	bl FUN_0823280c
_080D6A0E:
	str r4, [r5, #0x3c]
_080D6A10:
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_0823b4b8
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A34
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r5, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _080D6A52
_080D6A34:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r5, r1
	ldrh r1, [r2]
	ldr r0, _080D6A6C @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r1, r5, #0
	adds r1, #0x2c
	movs r2, #0
	bl Hitbox_SetPos
_080D6A52:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A70
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080D6A7C
	.align 2, 0
_080D6A6C: .4byte 0x0000FFFB
_080D6A70:
	adds r0, r5, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080D6A7C:
	str r1, [r0]
	adds r4, r0, #0
	adds r0, r5, #0
	movs r1, #2
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6A96
	ldr r0, [r4]
	movs r1, #0x80
	lsls r1, r1, #2
	orrs r0, r1
	b _080D6A9C
_080D6A96:
	ldr r0, [r4]
	ldr r1, _080D6AB8 @ =0xFFFFFDFF
	ands r0, r1
_080D6A9C:
	str r0, [r4]
	adds r0, r5, #0
	movs r1, #0x40
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6ABC
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080D6AC6
	.align 2, 0
_080D6AB8: .4byte 0xFFFFFDFF
_080D6ABC:
	adds r0, r5, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080D6AC6:
	str r1, [r0]
	adds r0, r5, #0
	movs r1, #4
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D6AE4
	ldr r1, _080D6AE0 @ =0x0000060C
	adds r0, r5, r1
	bl ParticleShadow_Hide
	b _080D6AEC
	.align 2, 0
_080D6AE0: .4byte 0x0000060C
_080D6AE4:
	ldr r2, _080D6B1C @ =0x0000060C
	adds r0, r5, r2
	bl ParticleShadow_Show
_080D6AEC:
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	ldrh r2, [r5, #0x2e]
	adds r0, r0, r2
	strh r0, [r5, #0x2e]
	adds r2, r5, #0
	adds r2, #0xa8
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	adds r1, r5, #0
	adds r1, #0xaa
	ldr r2, _080D6B20 @ =0x000003F6
	adds r0, r5, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080D6B1C: .4byte 0x0000060C
_080D6B20: .4byte 0x000003F6

	thumb_func_start FUN_080d6b24
FUN_080d6b24: @ 0x080D6B24
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _080D6B3C
	b _080D6E7C
_080D6B3C:
	cmp r0, #2
	bhi _080D6B46
	cmp r0, #1
	beq _080D6B4E
	b _080D6E98
_080D6B46:
	cmp r0, #8
	bne _080D6B4C
	b _080D6E38
_080D6B4C:
	b _080D6E98
_080D6B4E:
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D6B82
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D6B82
	ldr r1, [r5, #0x18]
	ldr r0, _080D6B70 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D6B74
	movs r0, #0
	b _080D6B7A
	.align 2, 0
_080D6B70: .4byte 0x03002C68
_080D6B74:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D6B7A:
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_080d0394
_080D6B82:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d6804
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r1, _080D6C94 @ =0x085AD184
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r4, #0xe9
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6BC0
	movs r1, #0xea
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D6BC0:
	adds r0, r5, #0
	bl FUN_080d69dc
	ldr r2, _080D6C98 @ =0x000003CE
	adds r0, r5, r2
	movs r4, #0
	ldrsh r0, [r0, r4]
	cmp r0, #0
	beq _080D6BD8
	adds r0, r5, #0
	bl FUN_080cfb20
_080D6BD8:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	ldr r1, _080D6C9C @ =0x00000446
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6BFC
	ldr r2, _080D6CA0 @ =0x00000442
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6BFC
	movs r1, #1
_080D6BFC:
	cmp r1, #0
	beq _080D6C02
	b _080D6E98
_080D6C02:
	movs r4, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	bne _080D6C40
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _080D6C40
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6C40
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_080D6C40:
	cmp r4, #0
	bne _080D6C46
	b _080D6E2C
_080D6C46:
	ldr r0, _080D6CA4 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _080D6C5A
	b _080D6E98
_080D6C5A:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D6CA8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D6CAC
	asrs r2, r0, #0xc
	b _080D6CB2
	.align 2, 0
_080D6C94: .4byte 0x085AD184
_080D6C98: .4byte 0x000003CE
_080D6C9C: .4byte 0x00000446
_080D6CA0: .4byte 0x00000442
_080D6CA4: .4byte 0x000003BE
_080D6CA8: .4byte 0x085B0A08
_080D6CAC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6CB2:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6CDC @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D6CE0
	asrs r2, r0, #0xc
	b _080D6CE6
	.align 2, 0
_080D6CDC: .4byte 0xFFFF0000
_080D6CE0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D6CE6:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D6D28 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6D22
	cmp r1, #0
	blt _080D6D22
	ldr r0, _080D6D2C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6D22
	ldr r0, _080D6D30 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6D34
_080D6D22:
	movs r4, #0
	b _080D6D42
	.align 2, 0
_080D6D28: .4byte 0xFFFF0000
_080D6D2C: .4byte 0x030046A8
_080D6D30: .4byte 0x030046AC
_080D6D34:
	ldr r0, _080D6D54 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6D42:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D6D58
	adds r0, #4
	b _080D6D64
	.align 2, 0
_080D6D54: .4byte 0x030046A4
_080D6D58:
	ldr r0, _080D6D78 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6D64:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D6D7C
	cmp r2, #2
	beq _080D6D80
	b _080D6D84
	.align 2, 0
_080D6D78: .4byte 0x030046A4
_080D6D7C:
	ldrb r0, [r6, #4]
	b _080D6D82
_080D6D80:
	ldrb r0, [r6]
_080D6D82:
	subs r1, r1, r0
_080D6D84:
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	adds r0, #0xc8
	cmp r1, r0
	bhs _080D6D90
	b _080D6E98
_080D6D90:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D6DB8
	cmp r1, #0
	blt _080D6DB8
	ldr r0, _080D6DBC @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D6DB8
	ldr r0, _080D6DC0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D6DC4
_080D6DB8:
	movs r4, #0
	b _080D6DD2
	.align 2, 0
_080D6DBC: .4byte 0x030046A8
_080D6DC0: .4byte 0x030046AC
_080D6DC4:
	ldr r0, _080D6DE4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D6DD2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D6DE8
	adds r0, #4
	b _080D6DF4
	.align 2, 0
_080D6DE4: .4byte 0x030046A4
_080D6DE8:
	ldr r0, _080D6E24 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D6DF4:
	ldrh r2, [r0, #2]
	movs r3, #4
	ands r2, r3
	cmp r2, #0
	bne _080D6E98
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r4, _080D6E28 @ =0x000003BD
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	subs r4, #0x41
	adds r0, r5, r4
	strb r3, [r0]
	subs r1, #0x3f
	adds r0, r5, r1
	strb r2, [r0]
	b _080D6E98
	.align 2, 0
_080D6E24: .4byte 0x030046A4
_080D6E28: .4byte 0x000003BD
_080D6E2C:
	ldr r2, _080D6E34 @ =0x000003BE
	adds r0, r5, r2
	strh r4, [r0]
	b _080D6E98
	.align 2, 0
_080D6E34: .4byte 0x000003BE
_080D6E38:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0x1c
	bne _080D6E50
	adds r4, r0, #0
	b _080D6E5E
_080D6E50:
	ldr r1, _080D6E74 @ =0x000003D2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _080D6E5E
	movs r4, #0x1b
_080D6E5E:
	ldr r0, _080D6E78 @ =0x085AD184
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
	b _080D6E98
	.align 2, 0
_080D6E74: .4byte 0x000003D2
_080D6E78: .4byte 0x085AD184
_080D6E7C:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
_080D6E98:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d6ea0
FUN_080d6ea0: @ 0x080D6EA0
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0x80
	lsls r0, r0, #7
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #2
	bne _080D6EB8
	b _080D71EC
_080D6EB8:
	cmp r0, #2
	bhi _080D6EC2
	cmp r0, #1
	beq _080D6ECA
	b _080D7208
_080D6EC2:
	cmp r0, #8
	bne _080D6EC8
	b _080D71A8
_080D6EC8:
	b _080D7208
_080D6ECA:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D6EF4
	ldr r1, [r5, #0x18]
	ldr r0, _080D6EE0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D6EE4
	movs r0, #0
	b _080D6EEA
	.align 2, 0
_080D6EE0: .4byte 0x03002C68
_080D6EE4:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D6EEA:
	adds r1, r0, #1
	asrs r1, r1, #1
	adds r0, r5, #0
	bl FUN_080d0394
_080D6EF4:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d6804
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r1, _080D7004 @ =0x085AD204
	lsls r0, r4, #2
	adds r0, r0, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D6F32
	movs r2, #0xea
	lsls r2, r2, #2
	adds r0, r5, r2
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D6F32:
	adds r0, r5, #0
	bl FUN_080d69dc
	ldr r4, _080D7008 @ =0x000003CE
	adds r0, r5, r4
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080D6F4A
	adds r0, r5, #0
	bl FUN_080cfb20
_080D6F4A:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	ldr r2, _080D700C @ =0x00000446
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0
	cmp r0, #0
	beq _080D6F6E
	ldr r4, _080D7010 @ =0x00000442
	adds r0, r5, r4
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D6F6E
	movs r1, #1
_080D6F6E:
	cmp r1, #0
	beq _080D6F74
	b _080D7208
_080D6F74:
	movs r4, #0
	movs r1, #0xe5
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	bl FUN_080cfc78
	cmp r0, #0
	bne _080D6FB2
	movs r2, #0xdf
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrb r2, [r0]
	cmp r2, #1
	bne _080D6FB2
	movs r1, #0xde
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrb r1, [r0]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _080D6FB2
	movs r4, #0xba
	lsls r4, r4, #2
	adds r0, r5, r4
	ldrb r1, [r0]
	ands r1, r2
	rsbs r0, r1, #0
	orrs r0, r1
	lsrs r4, r0, #0x1f
_080D6FB2:
	cmp r4, #0
	bne _080D6FB8
	b _080D719C
_080D6FB8:
	ldr r0, _080D7014 @ =0x000003BE
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	beq _080D6FCC
	b _080D7208
_080D6FCC:
	ldr r0, [r5, #0x2c]
	ldr r1, [r5, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D7018 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	movs r0, #0x32
	muls r0, r1, r0
	adds r4, r2, #0
	cmp r0, #0
	blt _080D701C
	asrs r2, r0, #0xc
	b _080D7022
	.align 2, 0
_080D7004: .4byte 0x085AD204
_080D7008: .4byte 0x000003CE
_080D700C: .4byte 0x00000446
_080D7010: .4byte 0x00000442
_080D7014: .4byte 0x000003BE
_080D7018: .4byte 0x085B0A08
_080D701C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D7022:
	mov r0, sp
	ldrh r1, [r0]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D704C @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r4
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _080D7050
	asrs r2, r0, #0xc
	b _080D7056
	.align 2, 0
_080D704C: .4byte 0xFFFF0000
_080D7050:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080D7056:
	mov r0, sp
	ldrh r1, [r0, #4]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D7098 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	mov r6, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r6, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D7092
	cmp r1, #0
	blt _080D7092
	ldr r0, _080D709C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D7092
	ldr r0, _080D70A0 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D70A4
_080D7092:
	movs r4, #0
	b _080D70B2
	.align 2, 0
_080D7098: .4byte 0xFFFF0000
_080D709C: .4byte 0x030046A8
_080D70A0: .4byte 0x030046AC
_080D70A4:
	ldr r0, _080D70C4 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D70B2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D70C8
	adds r0, #4
	b _080D70D4
	.align 2, 0
_080D70C4: .4byte 0x030046A4
_080D70C8:
	ldr r0, _080D70E8 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D70D4:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080D70EC
	cmp r2, #2
	beq _080D70F0
	b _080D70F4
	.align 2, 0
_080D70E8: .4byte 0x030046A4
_080D70EC:
	ldrb r0, [r6, #4]
	b _080D70F2
_080D70F0:
	ldrb r0, [r6]
_080D70F2:
	subs r1, r1, r0
_080D70F4:
	movs r4, #0x2e
	ldrsh r0, [r5, r4]
	adds r0, #0xc8
	cmp r1, r0
	bhs _080D7100
	b _080D7208
_080D7100:
	mov r1, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D7128
	cmp r1, #0
	blt _080D7128
	ldr r0, _080D712C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D7128
	ldr r0, _080D7130 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D7134
_080D7128:
	movs r4, #0
	b _080D7142
	.align 2, 0
_080D712C: .4byte 0x030046A8
_080D7130: .4byte 0x030046AC
_080D7134:
	ldr r0, _080D7154 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D7142:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D7158
	adds r0, #4
	b _080D7164
	.align 2, 0
_080D7154: .4byte 0x030046A4
_080D7158:
	ldr r0, _080D7194 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D7164:
	ldrh r2, [r0, #2]
	movs r3, #4
	ands r2, r3
	cmp r2, #0
	bne _080D7208
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r1, [r0]
	ldr r4, _080D7198 @ =0x000003BD
	adds r0, r5, r4
	strb r1, [r0]
	movs r1, #0xef
	lsls r1, r1, #2
	adds r0, r5, r1
	strb r2, [r0]
	subs r4, #0x41
	adds r0, r5, r4
	strb r3, [r0]
	subs r1, #0x3f
	adds r0, r5, r1
	strb r2, [r0]
	b _080D7208
	.align 2, 0
_080D7194: .4byte 0x030046A4
_080D7198: .4byte 0x000003BD
_080D719C:
	ldr r2, _080D71A4 @ =0x000003BE
	adds r0, r5, r2
	strh r4, [r0]
	b _080D7208
	.align 2, 0
_080D71A4: .4byte 0x000003BE
_080D71A8:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r4, #0xdf
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrb r0, [r1]
	cmp r0, #0x1c
	bne _080D71C0
	adds r4, r0, #0
	b _080D71CE
_080D71C0:
	ldr r1, _080D71E4 @ =0x000003D2
	adds r0, r5, r1
	ldrb r0, [r0]
	movs r4, #0x1a
	cmp r0, #0
	beq _080D71CE
	movs r4, #0x1b
_080D71CE:
	ldr r0, _080D71E8 @ =0x085AD204
	lsls r1, r4, #2
	adds r1, r1, r0
	ldr r1, [r1]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
	b _080D7208
	.align 2, 0
_080D71E4: .4byte 0x000003D2
_080D71E8: .4byte 0x085AD204
_080D71EC:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d69dc
_080D7208:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080d7210
FUN_080d7210: @ 0x080D7210
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r2, [r0]
	movs r3, #0xa3
	lsls r3, r3, #2
	adds r5, r4, r3
	ldr r0, [r5]
	ldrh r1, [r0, #2]
	movs r0, #0x80
	lsls r0, r0, #2
	ands r0, r1
	cmp r0, #0
	beq _080D7238
	adds r0, r4, #0
	bl FUN_080ced90
	adds r2, r0, #0
_080D7238:
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7248
	movs r2, #0x18
	b _080D72A0
_080D7248:
	cmp r2, #0x18
	beq _080D72A0
	cmp r2, #0x14
	beq _080D72A0
	cmp r2, #0x13
	beq _080D72A0
	cmp r2, #0x17
	beq _080D72A0
	cmp r2, #4
	beq _080D72A0
	cmp r2, #0xd
	beq _080D72A0
	ldr r2, [r5]
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7280
	adds r0, r4, #0
	adds r0, #0x24
	bl MapItemManager_TryOpen
	lsls r0, r0, #0x18
	movs r2, #4
	cmp r0, #0
	beq _080D72A0
_080D727C:
	movs r2, #0
	b _080D72A0
_080D7280:
	movs r3, #0xa4
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	beq _080D727C
	ldrh r1, [r2]
	movs r0, #0x80
	lsls r0, r0, #1
	ands r0, r1
	cmp r0, #0
	bne _080D727C
	movs r2, #1
_080D72A0:
	adds r0, r2, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d72a8
FUN_080d72a8: @ 0x080D72A8
	push {r4, lr}
	adds r4, r0, #0
	adds r0, #0x24
	bl FUN_0823b4b8
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D72CE
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r2, r4, r0
	ldrh r1, [r2]
	movs r0, #4
	orrs r0, r1
	strh r0, [r2]
	b _080D72EC
_080D72CE:
	movs r1, #0xb9
	lsls r1, r1, #1
	adds r2, r4, r1
	ldrh r1, [r2]
	ldr r0, _080D7304 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	movs r2, #0xb6
	lsls r2, r2, #1
	adds r0, r4, r2
	adds r1, r4, #0
	adds r1, #0x2c
	movs r2, #0
	bl Hitbox_SetPos
_080D72EC:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D7308
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	b _080D7314
	.align 2, 0
_080D7304: .4byte 0x0000FFFB
_080D7308:
	adds r0, r4, #0
	adds r0, #0xe8
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
_080D7314:
	str r1, [r0]
	adds r0, r4, #0
	movs r1, #0x40
	bl FUN_080cc3d4
	cmp r0, #0
	beq _080D7330
	adds r0, r4, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	b _080D733A
_080D7330:
	adds r0, r4, #0
	adds r0, #0x90
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
_080D733A:
	str r1, [r0]
	movs r1, #0xfe
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	ldrh r2, [r4, #0x2e]
	adds r0, r0, r2
	strh r0, [r4, #0x2e]
	movs r0, #0x82
	lsls r0, r0, #1
	adds r2, r4, r0
	ldr r0, [r4, #0x2c]
	ldr r1, [r4, #0x30]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x83
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r2, _080D7370 @ =0x000003F6
	adds r0, r4, r2
	ldrh r0, [r0]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_080D7370: .4byte 0x000003F6

	thumb_func_start FUN_080d7374
FUN_080d7374: @ 0x080D7374
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #0xb
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _080D738E
	cmp r0, #2
	beq _080D7420
	b _080D743C
_080D738E:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D73B6
	ldr r1, [r5, #0x18]
	ldr r0, _080D73A4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D73A8
	movs r0, #0
	b _080D73AE
	.align 2, 0
_080D73A4: .4byte 0x03002C68
_080D73A8:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D73AE:
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_080d0394
_080D73B6:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d7210
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r0, _080D7418 @ =0x085AD280
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D73F2
	adds r1, #4
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D73F2:
	adds r0, r5, #0
	bl FUN_080d72a8
	ldr r1, _080D741C @ =0x000003CE
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080D740A
	adds r0, r5, #0
	bl FUN_080cfb20
_080D740A:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	b _080D743C
	.align 2, 0
_080D7418: .4byte 0x085AD280
_080D741C: .4byte 0x000003CE
_080D7420:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d72a8
_080D743C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d7444
FUN_080d7444: @ 0x080D7444
	push {r4, r5, lr}
	movs r1, #0
	ldr r5, _080D7460 @ =0x03002BE0
	ldrh r3, [r0, #0xa]
	movs r4, #1
	adds r2, r5, #0
_080D7450:
	adds r0, r3, #0
	asrs r0, r1
	ands r0, r4
	cmp r0, #0
	beq _080D7464
	ldr r0, [r2]
	b _080D746E
	.align 2, 0
_080D7460: .4byte 0x03002BE0
_080D7464:
	adds r2, #4
	adds r1, #1
	cmp r1, #3
	ble _080D7450
	ldr r0, [r5]
_080D746E:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080d7474
FUN_080d7474: @ 0x080D7474
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _080D74DC
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _080D7494
	movs r2, #1
_080D7494:
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r5, [r1]
	adds r3, r5, r2
	ldr r6, _080D74B0 @ =0x00000366
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r3, r0
	ble _080D74B4
	subs r2, r0, r5
	strh r0, [r1]
	b _080D74B6
	.align 2, 0
_080D74B0: .4byte 0x00000366
_080D74B4:
	strh r3, [r1]
_080D74B6:
	cmp r2, #0
	ble _080D74DC
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r3, r4, #0
	adds r3, #0x2c
	movs r5, #0x97
	lsls r5, r5, #4
	adds r1, r4, r5
	str r1, [sp]
	ldr r6, _080D74E4 @ =0x00000978
	adds r1, r4, r6
	ldrb r1, [r1]
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #1
	bl FUN_0805fe7c
_080D74DC:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D74E4: .4byte 0x00000978

	thumb_func_start FUN_080d74e8
FUN_080d74e8: @ 0x080D74E8
	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _080D754C
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _080D7506
	movs r2, #1
_080D7506:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r5, [r1]
	adds r3, r5, r2
	ldr r6, _080D7520 @ =0x0000036A
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r3, r0
	ble _080D7524
	subs r2, r0, r5
	strh r0, [r1]
	b _080D7526
	.align 2, 0
_080D7520: .4byte 0x0000036A
_080D7524:
	strh r3, [r1]
_080D7526:
	cmp r2, #0
	ble _080D754C
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r3, r4, #0
	adds r3, #0x2c
	movs r5, #0x97
	lsls r5, r5, #4
	adds r1, r4, r5
	str r1, [sp]
	ldr r6, _080D7554 @ =0x00000978
	adds r1, r4, r6
	ldrb r1, [r1]
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #1
	bl FUN_0805fe7c
_080D754C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7554: .4byte 0x00000978

	thumb_func_start FUN_080d7558
FUN_080d7558: @ 0x080D7558
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0xc
	adds r4, r0, #0
	adds r5, r1, #0
	adds r7, r2, #0
	ldrh r0, [r5, #0x3c]
	cmp r0, #0
	ble _080D7576
	adds r0, r5, #0
	adds r1, r7, #0
	bl Hitbox_ApplyDamageAlt
	b _080D757A
_080D7576:
	movs r0, #0
	strh r0, [r7, #0x3e]
_080D757A:
	adds r0, r5, #0
	adds r0, #0x44
	ldrh r1, [r0]
	adds r0, r7, #0
	adds r0, #0x44
	strh r1, [r0]
	movs r0, #0
	mov r8, r0
	adds r0, r5, #0
	adds r0, #0x40
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D75AC
	ldr r1, _080D75A4 @ =0x000003D6
	adds r0, r4, r1
	mov r2, r8
	strh r2, [r0]
	ldr r0, _080D75A8 @ =0x00000446
	adds r6, r4, r0
	b _080D761C
	.align 2, 0
_080D75A4: .4byte 0x000003D6
_080D75A8: .4byte 0x00000446
_080D75AC:
	ldr r2, _080D7664 @ =0x000003D6
	adds r1, r4, r2
	movs r0, #0xe6
	strh r0, [r1]
	movs r6, #0xd6
	lsls r6, r6, #2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D75DA
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xd
	bne _080D75DA
	subs r2, #0x56
	adds r0, r4, r2
	movs r1, #1
	strb r1, [r0]
	adds r6, #0x29
	adds r0, r4, r6
	strb r1, [r0]
_080D75DA:
	ldr r1, _080D7668 @ =0x00000446
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0
	adds r6, r0, #0
	cmp r1, #0
	beq _080D75F4
	ldr r1, _080D766C @ =0x00000442
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #6
	bne _080D75F4
	movs r2, #1
_080D75F4:
	cmp r2, #0
	beq _080D7612
	ldr r2, _080D766C @ =0x00000442
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #4
	adds r0, r4, r2
	strh r1, [r0]
	adds r2, r4, #0
	adds r2, #0xe8
	ldr r0, [r2]
	ldr r1, _080D7670 @ =0xFFFFFBFF
	ands r0, r1
	str r0, [r2]
_080D7612:
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r7, #0
	bl FUN_080cc4f4
_080D761C:
	movs r1, #0x10
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7630
	adds r0, r4, #0
	adds r0, #0x2c
	ldr r1, [r4, #0x18]
	bl FUN_081df698
_080D7630:
	ldrh r0, [r6]
	movs r1, #0
	cmp r0, #0
	beq _080D7644
	ldr r2, _080D766C @ =0x00000442
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D7644
	movs r1, #1
_080D7644:
	cmp r1, #0
	beq _080D7674
	movs r0, #0
	strh r0, [r7, #0x3e]
	movs r6, #0
	movs r1, #0x80
	lsls r1, r1, #0xb
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	bne _080D765C
	b _080D784E
_080D765C:
	adds r0, r4, #0
	bl FUN_080cdda8
	b _080D784E
	.align 2, 0
_080D7664: .4byte 0x000003D6
_080D7668: .4byte 0x00000446
_080D766C: .4byte 0x00000442
_080D7670: .4byte 0xFFFFFBFF
_080D7674:
	ldrh r0, [r6]
	movs r1, #0
	cmp r0, #0
	beq _080D7688
	ldr r6, _080D76DC @ =0x00000442
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r0, #5
	bne _080D7688
	movs r1, #1
_080D7688:
	cmp r1, #0
	bne _080D76A4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #2
	beq _080D76A4
	movs r2, #0xd6
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #3
	bne _080D76A8
_080D76A4:
	movs r6, #1
	add r8, r6
_080D76A8:
	movs r0, #4
	ldr r1, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D76EC
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D773C
	ldr r1, _080D76E0 @ =0x000003D2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D76D2
	ldr r2, _080D76E4 @ =0x000003D6
	adds r1, r4, r2
	ldr r0, _080D76E8 @ =0x00000191
	strh r0, [r1]
_080D76D2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08063288
	b _080D773C
	.align 2, 0
_080D76DC: .4byte 0x00000442
_080D76E0: .4byte 0x000003D2
_080D76E4: .4byte 0x000003D6
_080D76E8: .4byte 0x00000191
_080D76EC:
	movs r0, #8
	ands r0, r1
	cmp r0, #0
	beq _080D772C
	adds r0, r7, #0
	adds r0, #0x43
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D773C
	ldr r6, _080D7720 @ =0x000003D2
	adds r0, r4, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _080D7714
	ldr r0, _080D7724 @ =0x000003D6
	adds r1, r4, r0
	ldr r0, _080D7728 @ =0x00000133
	strh r0, [r1]
_080D7714:
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08063288
	b _080D773C
	.align 2, 0
_080D7720: .4byte 0x000003D2
_080D7724: .4byte 0x000003D6
_080D7728: .4byte 0x00000133
_080D772C:
	movs r0, #0x80
	lsls r0, r0, #0xb
	ands r1, r0
	cmp r1, #0
	beq _080D773C
	adds r0, r4, #0
	bl FUN_080cdda8
_080D773C:
	movs r1, #0x80
	lsls r1, r1, #8
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7754
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08063574
_080D7754:
	movs r1, #0x80
	lsls r1, r1, #0xd
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D776C
	movs r2, #0xe1
	lsls r2, r2, #2
	adds r0, r4, #0
	movs r1, #2
	bl FUN_08063574
_080D776C:
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D77FA
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _080D77A8 @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080D77AC
	asrs r0, r0, #0xc
	b _080D77B2
	.align 2, 0
_080D77A8: .4byte 0x085B0A08
_080D77AC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D77B2:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xc8
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #4]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080D77D4
	asrs r0, r0, #0xc
	b _080D77DA
_080D77D4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080D77DA:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _080D786C @ =0xFFFF0000
	ldr r0, [sp, #8]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #8]
	adds r0, r4, #0
	adds r0, #0x2c
	movs r1, #1
	str r1, [sp]
	add r1, sp, #4
	movs r2, #0
	movs r3, #0
	bl FUN_080dc0b8
_080D77FA:
	ldrh r6, [r7, #0x3e]
	mov r0, r8
	lsls r6, r0
	movs r0, #0
	strh r0, [r7, #0x3e]
	ldr r0, [r5, #0x34]
	movs r1, #0x10
	ands r0, r1
	cmp r0, #0
	bne _080D7844
	movs r1, #0xf
	ldrh r0, [r5, #0xa]
	ands r0, r1
	cmp r0, #0
	beq _080D7844
	movs r1, #0x20
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D782E
	adds r0, r5, #0
	bl FUN_080d7444
	adds r1, r6, #0
	bl FUN_080d7474
_080D782E:
	movs r1, #2
	ldr r0, [r5, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080D7844
	adds r0, r5, #0
	bl FUN_080d7444
	adds r1, r6, #0
	bl FUN_080d74e8
_080D7844:
	ldr r2, _080D7870 @ =0x00000376
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, r0, r6
	strh r0, [r1]
_080D784E:
	ldrh r1, [r5, #0xa]
	ldr r2, _080D7874 @ =0x0000045A
	adds r0, r4, r2
	strh r1, [r0]
	ldr r0, _080D7878 @ =0x0000045C
	adds r1, r4, r0
	ldr r0, [r5, #0x34]
	str r0, [r1]
	adds r0, r6, #0
	add sp, #0xc
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080D786C: .4byte 0xFFFF0000
_080D7870: .4byte 0x00000376
_080D7874: .4byte 0x0000045A
_080D7878: .4byte 0x0000045C

	thumb_func_start FUN_080d787c
FUN_080d787c: @ 0x080D787C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	ldr r1, [r5, #0x1c]
	cmp r1, #1
	bne _080D78D4
	movs r0, #0x80
	lsls r0, r0, #2
	ldrh r3, [r6, #6]
	ands r0, r3
	cmp r0, #0
	beq _080D78AC
	movs r0, #0x46
	adds r0, r0, r4
	mov ip, r0
	ldrb r2, [r0]
	ands r1, r2
	cmp r1, #0
	beq _080D78D4
	movs r0, #0xfe
	ands r0, r2
	mov r1, ip
	strb r0, [r1]
_080D78AC:
	movs r0, #0x80
	lsls r0, r0, #3
	ands r3, r0
	cmp r3, #0
	beq _080D78CA
	adds r3, r4, #0
	adds r3, #0x46
	ldrb r1, [r3]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080D78D4
	movs r0, #2
	orrs r0, r1
	strb r0, [r3]
_080D78CA:
	adds r0, r5, #0
	adds r1, r6, #0
	adds r2, r4, #0
	bl FUN_080d7558
_080D78D4:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d78dc
FUN_080d78dc: @ 0x080D78DC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r5, r0, #0
	ldrh r0, [r5, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #0x30]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080D790A
	cmp r1, #0
	blt _080D790A
	ldr r0, _080D7910 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080D790A
	ldr r0, _080D7914 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080D7918
_080D790A:
	movs r4, #0
	b _080D7926
	.align 2, 0
_080D7910: .4byte 0x030046A8
_080D7914: .4byte 0x030046AC
_080D7918:
	ldr r0, _080D7938 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080D7926:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080D793C
	adds r0, #4
	b _080D7948
	.align 2, 0
_080D7938: .4byte 0x030046A4
_080D793C:
	ldr r0, _080D7978 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080D7948:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080D79B0
	movs r1, #0xe4
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D79B0
	movs r1, #0x80
	lsls r1, r1, #6
	ldr r0, _080D797C @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _080D7980 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080D7984
	movs r0, #1
	b _080D7986
	.align 2, 0
_080D7978: .4byte 0x030046A4
_080D797C: .4byte 0x030046A0
_080D7980: .4byte 0x00000934
_080D7984:
	movs r0, #0
_080D7986:
	cmp r0, #0
	beq _080D7996
	adds r0, r5, #0
	movs r1, #0x1d
	movs r2, #0
	bl FUN_080cc348
	b _080D79A0
_080D7996:
	adds r0, r5, #0
	movs r1, #0x1c
	movs r2, #0
	bl FUN_080cc348
_080D79A0:
	ldr r4, _080D79AC @ =0x00000376
	adds r1, r5, r4
	movs r0, #0
	strh r0, [r1]
	b _080D7B40
	.align 2, 0
_080D79AC: .4byte 0x00000376
_080D79B0:
	movs r7, #0
	mov r8, r7
	ldr r1, _080D79CC @ =0x00000376
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D79EC
	ldr r0, _080D79D0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D79D4
	movs r1, #1
	rsbs r1, r1, #0
	b _080D79D8
	.align 2, 0
_080D79CC: .4byte 0x00000376
_080D79D0: .4byte 0x03002C68
_080D79D4:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080D79D8:
	ldr r4, _080D7ADC @ =0x0000045A
	adds r0, r5, r4
	movs r7, #0
	ldrsh r0, [r0, r7]
	asrs r0, r1
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D79EC
	mov r8, r1
_080D79EC:
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D7A08
	adds r0, r5, #0
	bl FUN_080cfdec
	ldr r4, _080D7AE0 @ =0x00000376
	adds r2, r5, r4
	ldrh r1, [r2]
	adds r1, r1, r0
	strh r1, [r2]
_080D7A08:
	movs r7, #0xd8
	lsls r7, r7, #1
	adds r0, r5, r7
	ldrh r3, [r0]
	cmp r3, #0
	bne _080D7A84
	ldr r1, _080D7AE4 @ =0x0000043E
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7A3E
	movs r4, #0xf6
	lsls r4, r4, #2
	adds r2, r5, r4
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080D7A3E
	ldr r7, _080D7AE0 @ =0x00000376
	adds r1, r5, r7
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	strh r3, [r2]
_080D7A3E:
	ldr r1, _080D7AE8 @ =0x000004C5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080D7A84
	ldr r4, _080D7AEC @ =0x000004C7
	adds r2, r5, r4
	ldrb r0, [r2]
	cmp r0, #0
	beq _080D7A84
	movs r1, #0x80
	lsls r1, r1, #2
	ldr r0, [r5, #0x20]
	orrs r0, r1
	str r0, [r5, #0x20]
	ldr r7, _080D7AF0 @ =0x000003DA
	adds r6, r5, r7
	ldrh r4, [r6]
	adds r4, #1
	strh r4, [r6]
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldrb r1, [r2]
	movs r0, #0x3c
	bl Div
	cmp r4, r0
	blt _080D7A84
	ldr r1, _080D7AE0 @ =0x00000376
	adds r0, r5, r1
	ldrh r1, [r0]
	adds r1, #0xa
	strh r1, [r0]
	movs r0, #0
	strh r0, [r6]
_080D7A84:
	ldr r2, _080D7AE0 @ =0x00000376
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7B00
	ldr r4, _080D7AF4 @ =0x00000446
	adds r0, r5, r4
	ldrh r0, [r0]
	movs r6, #0
	cmp r0, #0
	beq _080D7AA6
	ldr r7, _080D7AF8 @ =0x00000442
	adds r0, r5, r7
	ldrh r0, [r0]
	cmp r0, #3
	bne _080D7AA6
	movs r6, #1
_080D7AA6:
	cmp r6, #0
	bne _080D7B00
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r2, _080D7AE0 @ =0x00000376
	adds r4, r5, r2
	ldrh r1, [r4]
	adds r3, r5, #0
	adds r3, #0x2c
	movs r7, #0x97
	lsls r7, r7, #4
	adds r2, r5, r7
	str r2, [sp]
	str r6, [sp, #4]
	movs r2, #0
	bl FUN_0805fe7c
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r5, r0
	ldrh r2, [r1]
	ldrh r0, [r4]
	cmp r2, r0
	bhs _080D7AFC
	strh r6, [r1]
	b _080D7B00
	.align 2, 0
_080D7ADC: .4byte 0x0000045A
_080D7AE0: .4byte 0x00000376
_080D7AE4: .4byte 0x0000043E
_080D7AE8: .4byte 0x000004C5
_080D7AEC: .4byte 0x000004C7
_080D7AF0: .4byte 0x000003DA
_080D7AF4: .4byte 0x00000446
_080D7AF8: .4byte 0x00000442
_080D7AFC:
	subs r0, r2, r0
	strh r0, [r1]
_080D7B00:
	ldr r1, _080D7B38 @ =0x00000376
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	mov r2, r8
	cmp r2, #0
	beq _080D7B26
	ldrh r0, [r5, #0x24]
	movs r4, #0xd9
	lsls r4, r4, #2
	adds r1, r5, r4
	ldrh r1, [r1]
	ldr r7, _080D7B3C @ =0x00000366
	adds r2, r5, r7
	ldrh r2, [r2]
	str r3, [sp]
	movs r3, #0xa
	bl FUN_0809c344
_080D7B26:
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080D7B40
	movs r0, #0
	b _080D7B42
	.align 2, 0
_080D7B38: .4byte 0x00000376
_080D7B3C: .4byte 0x00000366
_080D7B40:
	movs r0, #1
_080D7B42:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080d7b50
FUN_080d7b50: @ 0x080D7B50
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r5, [r0]
	cmp r5, #0
	ble _080D7BA4
	adds r0, r4, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r1, #0xd6
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080D7BA4
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _080D7BA4
	cmp r0, #0x19
	beq _080D7BA4
	subs r5, #1
	cmp r5, #0
	beq _080D7B9C
	asrs r0, r5, #2
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080D7B9C
	adds r0, r4, #0
	movs r1, #5
	bl FUN_080cc3c4
_080D7B9C:
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r4, r1
	strh r5, [r0]
_080D7BA4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080d7bac
FUN_080d7bac: @ 0x080D7BAC
	push {lr}
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _080D7BBC
	movs r0, #0
	b _080D7BC0
_080D7BBC:
	bl Script_GetValue
_080D7BC0:
	pop {r1}
	bx r1

	thumb_func_start FUN_080d7bc4
FUN_080d7bc4: @ 0x080D7BC4
	ldr r3, _080D7BD8 @ =0x0000095E
	adds r2, r0, r3
	strh r1, [r2]
	movs r1, #0x96
	lsls r1, r1, #4
	adds r0, r0, r1
	movs r1, #0x20
	strh r1, [r0]
	bx lr
	.align 2, 0
_080D7BD8: .4byte 0x0000095E

