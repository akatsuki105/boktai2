	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_08019388
FUN_08019388: @ 0x08019388
	push {lr}
	movs r2, #0
	ldrh r1, [r0, #0x24]
	cmp r2, r1
	bge _080193AA
	adds r3, r1, #0
	adds r1, r0, #0
	adds r1, #0x34
_08019398:
	ldrb r0, [r1]
	cmp r0, #1
	bne _080193A2
	movs r0, #1
	b _080193AC
_080193A2:
	adds r1, #0x30
	adds r2, #1
	cmp r2, r3
	blt _08019398
_080193AA:
	movs r0, #0
_080193AC:
	pop {r1}
	bx r1

	thumb_func_start FUN_080193b0
FUN_080193b0: @ 0x080193B0
	push {r4, lr}
	adds r2, r0, #0
	adds r3, r1, #0
	ldrh r0, [r3, #6]
	adds r4, r0, #0
	cmp r4, #0
	bne _08019400
	ldr r1, [r2, #0x1c]
	cmp r1, #0
	blt _080193CA
	ldr r0, [r2, #0x18]
	cmp r0, r1
	bge _08019404
_080193CA:
	movs r0, #1
	strb r0, [r3]
	ldr r2, _080193F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080193F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080193FC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	strb r0, [r3, #1]
	strh r4, [r3, #2]
	ldr r0, [r3, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r3, #8]
	b _08019404
	.align 2, 0
_080193F4: .4byte 0x030046B8
_080193F8: .4byte 0x000003FF
_080193FC: .4byte 0x0203B400
_08019400:
	subs r0, #1
	strh r0, [r3, #6]
_08019404:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801940c
FUN_0801940c: @ 0x0801940C
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r1, #0
	ldrh r0, [r6, #0x20]
	ldrh r1, [r5, #2]
	adds r0, r0, r1
	strh r0, [r5, #2]
	ldrh r3, [r5, #6]
	movs r0, #3
	ands r0, r3
	cmp r0, #0
	bne _08019438
	adds r0, r5, #0
	adds r0, #8
	ldr r1, [r6, #0x28]
	ldrh r2, [r6, #0x26]
	lsrs r3, r3, #2
	movs r4, #1
	ands r3, r4
	adds r2, r2, r3
	bl FUN_0822dafc
_08019438:
	ldrh r0, [r5, #6]
	adds r0, #1
	strh r0, [r5, #6]
	ldrh r0, [r5, #2]
	ldrh r1, [r6, #0x22]
	cmp r0, r1
	blo _0801945E
	movs r0, #0
	strb r0, [r5]
	ldr r0, [r5, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #8]
	ldrh r1, [r6, #0x24]
	movs r0, #8
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #4
	strh r0, [r5, #6]
_0801945E:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08019464
FUN_08019464: @ 0x08019464
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov r8, r0
	ldrh r1, [r5, #0x24]
	cmp r8, r1
	bge _0801951A
	movs r2, #0x54
	adds r2, r2, r5
	mov sl, r2
	movs r0, #0x34
	adds r0, r0, r5
	mov sb, r0
	mov r4, sb
_08019488:
	mov r1, sb
	ldrb r0, [r4]
	cmp r0, #0
	bne _08019498
	adds r0, r5, #0
	bl FUN_080193b0
	b _0801949E
_08019498:
	adds r0, r5, #0
	bl FUN_0801940c
_0801949E:
	mov r3, sl
	ldrb r6, [r4, #1]
	ldrh r7, [r4, #4]
	ldr r2, _080194C0 @ =0x085B0A08
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r7, r0
	cmp r0, #0
	blt _080194C4
	asrs r1, r0, #0xc
	b _080194CA
	.align 2, 0
_080194C0: .4byte 0x085B0A08
_080194C4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080194CA:
	movs r0, #0
	strh r1, [r3]
	strh r0, [r3, #2]
	lsls r0, r6, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r7, r0
	cmp r0, #0
	blt _080194E2
	asrs r0, r0, #0xc
	b _080194E8
_080194E2:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080194E8:
	strh r0, [r3, #4]
	ldrh r1, [r4, #2]
	ldrh r0, [r4, #0x22]
	adds r1, r1, r0
	strh r1, [r4, #0x22]
	ldrh r0, [r5, #0x2c]
	ldrh r2, [r4, #0x20]
	adds r0, r0, r2
	strh r0, [r4, #0x20]
	ldrh r0, [r5, #0x2e]
	adds r1, r1, r0
	strh r1, [r4, #0x22]
	ldrh r0, [r5, #0x30]
	ldrh r1, [r4, #0x24]
	adds r0, r0, r1
	strh r0, [r4, #0x24]
	movs r2, #0x30
	add sl, r2
	adds r4, #0x30
	add sb, r2
	movs r0, #1
	add r8, r0
	ldrh r1, [r5, #0x24]
	cmp r8, r1
	blt _08019488
_0801951A:
	ldrh r2, [r5, #0x24]
	mov r8, r2
	cmp r2, #7
	bgt _08019542
	movs r2, #1
	mov r1, r8
	lsls r0, r1, #1
	add r0, r8
	lsls r0, r0, #4
	adds r0, #0x3c
	adds r1, r0, r5
_08019530:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x30
	movs r0, #1
	add r8, r0
	mov r0, r8
	cmp r0, #7
	ble _08019530
_08019542:
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	ldr r1, [r5, #0x1c]
	cmp r1, #0
	ble _08019562
	cmp r0, r1
	blt _08019562
	adds r0, r5, #0
	bl FUN_08019388
	cmp r0, #0
	bne _08019562
	adds r0, r5, #0
	bl KillEntity
_08019562:
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019574
FUN_08019574: @ 0x08019574
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x3c
	movs r5, #7
_0801957C:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _0801957C
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019594
FUN_08019594: @ 0x08019594
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	str r2, [sp]
	mov r8, r3
	ldr r7, [sp, #0x24]
	ldr r0, [sp, #0x28]
	cmp r0, #8
	bhi _08019654
	lsls r0, r0, #2
	ldr r1, _080195BC @ =_080195C0
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080195BC: .4byte _080195C0
_080195C0: @ jump table
	.4byte _08019654 @ case 0
	.4byte _080195E4 @ case 1
	.4byte _08019654 @ case 2
	.4byte _080195F4 @ case 3
	.4byte _08019604 @ case 4
	.4byte _08019614 @ case 5
	.4byte _08019624 @ case 6
	.4byte _08019634 @ case 7
	.4byte _08019644 @ case 8
_080195E4:
	ldr r0, _080195F0 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0
	b _0801965E
	.align 2, 0
_080195F0: .4byte 0x00001C1E
_080195F4:
	ldr r0, _08019600 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #4
	b _0801965E
	.align 2, 0
_08019600: .4byte 0x00001C1E
_08019604:
	ldr r0, _08019610 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #6
	b _0801965E
	.align 2, 0
_08019610: .4byte 0x00001C1E
_08019614:
	ldr r0, _08019620 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #8
	b _0801965E
	.align 2, 0
_08019620: .4byte 0x00001C1E
_08019624:
	ldr r0, _08019630 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xa
	b _0801965E
	.align 2, 0
_08019630: .4byte 0x00001C1E
_08019634:
	ldr r0, _08019640 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xc
	b _0801965E
	.align 2, 0
_08019640: .4byte 0x00001C1E
_08019644:
	ldr r0, _08019650 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #0xe
	b _0801965E
	.align 2, 0
_08019650: .4byte 0x00001C1E
_08019654:
	ldr r0, _08019694 @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r6, #0x28]
	movs r0, #2
_0801965E:
	strh r0, [r6, #0x26]
	ldr r0, [r4]
	ldr r1, [r4, #4]
	str r0, [r6, #0x2c]
	str r1, [r6, #0x30]
	adds r5, r6, #0
	adds r5, #0x2c
	ldrh r0, [r6, #0x2c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08019690
	cmp r1, #0
	blt _08019690
	ldr r0, _08019698 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08019690
	ldr r0, _0801969C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080196A0
_08019690:
	movs r4, #0
	b _080196AE
	.align 2, 0
_08019694: .4byte 0x00001C1E
_08019698: .4byte 0x030046A8
_0801969C: .4byte 0x030046AC
_080196A0:
	ldr r0, _080196C0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080196AE:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080196C4
	adds r0, #4
	b _080196D0
	.align 2, 0
_080196C0: .4byte 0x030046A4
_080196C4:
	ldr r0, _080196E4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080196D0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080196E8
	cmp r2, #2
	beq _080196EC
	b _080196F0
	.align 2, 0
_080196E4: .4byte 0x030046A4
_080196E8:
	ldrb r0, [r5, #4]
	b _080196EE
_080196EC:
	ldrb r0, [r5]
_080196EE:
	subs r1, r1, r0
_080196F0:
	movs r2, #0x2e
	ldrsh r0, [r6, r2]
	cmp r0, r1
	bge _080196FA
	strh r1, [r6, #0x2e]
_080196FA:
	movs r0, #0
	str r0, [r6, #0x18]
	mov r3, r8
	str r3, [r6, #0x1c]
	movs r0, #0x14
	strh r0, [r6, #0x20]
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r6, #0x22]
	cmp r7, #7
	ble _08019712
	movs r7, #8
_08019712:
	strh r7, [r6, #0x24]
	adds r7, r6, #0
	adds r7, #0x34
	movs r0, #0
	mov r8, r0
	mov sb, r0
	ldr r1, _080197A0 @ =0x085B0A08
	mov sl, r1
	adds r5, r7, #0
_08019724:
	adds r4, r7, #0
	adds r4, #8
	mov r2, sb
	strb r2, [r5]
	ldr r2, _080197A4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080197A8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r3, _080197AC @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	subs r0, #0x20
	strb r0, [r5, #1]
	mov r0, sb
	strh r0, [r5, #2]
	mov r1, sp
	ldrh r1, [r1]
	strh r1, [r5, #4]
	mov r2, r8
	lsls r0, r2, #2
	strh r0, [r5, #6]
	ldr r1, [r6, #0x28]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r1, [r6, #0x28]
	ldrh r2, [r6, #0x26]
	adds r0, r4, #0
	bl FUN_0822dafc
	adds r0, r4, #0
	movs r1, #1
	bl FUN_0822dadc
	ldrb r2, [r5, #1]
	ldrh r3, [r5, #4]
	adds r0, r2, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080197B0
	asrs r0, r0, #0xc
	b _080197B6
	.align 2, 0
_080197A0: .4byte 0x085B0A08
_080197A4: .4byte 0x030046B8
_080197A8: .4byte 0x000003FF
_080197AC: .4byte 0x0203B400
_080197B0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080197B6:
	strh r0, [r5, #0x20]
	mov r0, sb
	strh r0, [r5, #0x22]
	lsls r0, r2, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080197CE
	asrs r2, r0, #0xc
	b _080197D4
_080197CE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080197D4:
	strh r2, [r5, #0x24]
	ldrh r1, [r5, #2]
	ldrh r3, [r5, #0x22]
	adds r1, r1, r3
	strh r1, [r5, #0x22]
	ldrh r0, [r6, #0x2c]
	ldrh r3, [r5, #0x20]
	adds r0, r0, r3
	strh r0, [r5, #0x20]
	ldrh r0, [r6, #0x2e]
	adds r1, r1, r0
	strh r1, [r5, #0x22]
	ldrh r0, [r6, #0x30]
	adds r0, r2, r0
	strh r0, [r5, #0x24]
	movs r0, #1
	strb r0, [r5, #0x17]
	add r8, r0
	adds r5, #0x30
	adds r7, #0x30
	mov r0, r8
	cmp r0, #7
	ble _08019724
	movs r0, #0
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019814
FUN_08019814: @ 0x08019814
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r6, r0, #0
	adds r7, r1, #0
	mov r8, r2
	adds r5, r3, #0
	movs r1, #0xda
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019864
	ldr r1, _0801985C @ =FUN_08019464
	ldr r2, _08019860 @ =FUN_08019574
	bl SetEntityRoutine
	str r5, [sp]
	ldr r0, [sp, #0x20]
	str r0, [sp, #4]
	adds r0, r4, #0
	adds r1, r6, #0
	adds r2, r7, #0
	mov r3, r8
	bl FUN_08019594
	cmp r0, #0
	bge _08019864
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019866
	.align 2, 0
_0801985C: .4byte FUN_08019464
_08019860: .4byte FUN_08019574
_08019864:
	adds r0, r4, #0
_08019866:
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_08019874
FUN_08019874: @ 0x08019874
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	movs r1, #0xda
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r7, r0, #0
	cmp r7, #0
	beq _08019940
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080198D4
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _080198CC @ =0xFFFF0000
	ldr r1, [sp, #8]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _080198D0 @ =0x0000FFFF
	ldr r1, [sp, #8]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #8]
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	b _080198DE
	.align 2, 0
_080198CC: .4byte 0xFFFF0000
_080198D0: .4byte 0x0000FFFF
_080198D4:
	ldr r1, _08019934 @ =0xFFFF0000
	str r0, [sp, #8]
	ldr r0, [sp, #0xc]
	ands r0, r1
	str r0, [sp, #0xc]
_080198DE:
	movs r4, #0x80
	lsls r4, r4, #1
	movs r0, #0x64
	adds r1, r4, #0
	bl VM_GetKeywordValue
	mov r8, r0
	movs r0, #0x74
	adds r1, r4, #0
	bl VM_GetKeywordValue
	adds r6, r0, #0
	movs r0, #0x6e
	movs r1, #8
	bl VM_GetKeywordValue
	adds r5, r0, #0
	movs r0, #0x54
	movs r1, #0
	bl VM_GetKeywordValue
	adds r4, r0, #0
	ldr r1, _08019938 @ =FUN_08019464
	ldr r2, _0801993C @ =FUN_08019574
	adds r0, r7, #0
	bl SetEntityRoutine
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r7, #0
	add r1, sp, #8
	mov r2, r8
	adds r3, r6, #0
	bl FUN_08019594
	cmp r0, #0
	bge _08019940
	adds r0, r7, #0
	bl KillEntity
	movs r0, #0
	b _08019942
	.align 2, 0
_08019934: .4byte 0xFFFF0000
_08019938: .4byte FUN_08019464
_0801993C: .4byte FUN_08019574
_08019940:
	adds r0, r7, #0
_08019942:
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity82B7_Update
Entity82B7_Update: @ 0x08019950
	push {r4, r5, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x18]
	ldrh r1, [r4, #0x20]
	ldrh r2, [r4, #0x22]
	bl Video_SetBLDCNTDirect
	movs r1, #0x1b
	ldrsb r1, [r4, r1]
	ldr r0, [r4, #0x24]
	muls r0, r1, r0
	ldr r1, [r4, #0x28]
	bl Div
	movs r1, #0x19
	ldrsb r1, [r4, r1]
	adds r5, r1, r0
	ldrb r0, [r4, #0x18]
	cmp r0, #1
	bne _08019994
	movs r1, #0x1c
	ldrsb r1, [r4, r1]
	ldr r0, [r4, #0x24]
	muls r0, r1, r0
	ldr r1, [r4, #0x28]
	bl Div
	movs r1, #0x1a
	ldrsb r1, [r4, r1]
	adds r1, r1, r0
	adds r0, r5, #0
	bl Video_SetBLDALPHADirect
	b _0801999A
_08019994:
	adds r0, r5, #0
	bl Video_SetBLDYDirect
_0801999A:
	ldr r1, [r4, #0x24]
	ldr r0, [r4, #0x28]
	cmp r1, r0
	blo _080199A8
	adds r0, r4, #0
	bl KillEntity
_080199A8:
	ldr r0, [r4, #0x24]
	adds r0, #1
	str r0, [r4, #0x24]
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity82B7_Destroy
Entity82B7_Destroy: @ 0x080199B8
	movs r0, #0
	bx lr

	thumb_func_start Entity82B7_Init
Entity82B7_Init: @ 0x080199BC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r0, #0x6d
	movs r1, #1
	bl VM_GetKeywordValue
	strb r0, [r5, #0x18]
	movs r0, #0x69
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080199FC
	adds r7, r5, #0
	adds r7, #0x19
	movs r0, #0x1b
	adds r0, r0, r5
	mov r8, r0
	adds r4, r7, #0
_080199E4:
	bl VM_GetPC
	cmp r0, #0
	beq _080199F0
	bl Script_GetValue
_080199F0:
	strb r0, [r4]
	adds r4, #1
	adds r0, r7, #1
	cmp r4, r0
	ble _080199E4
	b _08019A16
_080199FC:
	adds r7, r5, #0
	adds r7, #0x19
	movs r0, #0x1b
	adds r0, r0, r5
	mov r8, r0
	adds r1, r7, #0
	movs r2, #0
	adds r0, r5, #0
	adds r0, #0x1a
_08019A0E:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08019A0E
_08019A16:
	movs r0, #0x61
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _08019A42
	movs r6, #0
	mov r4, r8
_08019A24:
	bl VM_GetPC
	cmp r0, #0
	beq _08019A36
	bl Script_GetValue
	adds r1, r7, r6
	ldrb r1, [r1]
	subs r0, r0, r1
_08019A36:
	strb r0, [r4]
	adds r4, #1
	adds r6, #1
	cmp r6, #1
	ble _08019A24
	b _08019A50
_08019A42:
	mov r1, r8
	movs r2, #0
	adds r0, r1, #1
_08019A48:
	strb r2, [r0]
	subs r0, #1
	cmp r0, r1
	bge _08019A48
_08019A50:
	movs r0, #0x73
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r5, #0x20]
	movs r0, #0x64
	movs r1, #0
	bl VM_GetKeywordValue
	strh r0, [r5, #0x22]
	movs r0, #0x74
	movs r1, #0x3c
	bl VM_GetKeywordValue
	str r0, [r5, #0x28]
	str r4, [r5, #0x24]
	cmp r0, #0
	bne _08019A7A
	movs r0, #0x3c
	str r0, [r5, #0x28]
_08019A7A:
	ldrb r0, [r5, #0x18]
	ldrh r1, [r5, #0x20]
	ldrh r2, [r5, #0x22]
	bl Video_SetBLDCNTDirect
	ldrb r0, [r5, #0x18]
	cmp r0, #1
	bne _08019A98
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	movs r1, #0x1a
	ldrsb r1, [r5, r1]
	bl Video_SetBLDALPHADirect
	b _08019AA0
_08019A98:
	movs r0, #0x19
	ldrsb r0, [r5, r0]
	bl Video_SetBLDYDirect
_08019AA0:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity82B7_Create
Entity82B7_Create: @ 0x08019AAC
	push {r4, lr}
	movs r0, #0xb
	movs r1, #0x2c
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _08019AE0
	ldr r1, _08019AD8 @ =Entity82B7_Update
	ldr r2, _08019ADC @ =Entity82B7_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity82B7_Init
	cmp r0, #0
	bge _08019AE0
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _08019AE2
	.align 2, 0
_08019AD8: .4byte Entity82B7_Update
_08019ADC: .4byte Entity82B7_Destroy
_08019AE0:
	adds r0, r4, #0
_08019AE2:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_08019ae8
FUN_08019ae8: @ 0x08019AE8
	ldr r1, _08019AF0 @ =0x03000090
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_08019AF0: .4byte 0x03000090

	thumb_func_start FUN_08019af4
FUN_08019af4: @ 0x08019AF4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	mov r8, r0
	adds r4, r1, #0
	movs r6, #0
	strb r6, [r4]
	str r6, [r4, #4]
	movs r0, #1
	mov sb, r0
	mov r0, sb
	strb r0, [r4, #2]
	strb r6, [r4, #1]
	adds r5, r4, #0
	adds r5, #8
	movs r0, #0x80
	lsls r0, r0, #1
	add r8, r0
	mov r0, r8
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x13
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	mov r0, r8
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0x33
	bl FUN_0822dafc
	mov r0, sb
	strb r0, [r4, #0x17]
	strh r6, [r4, #0x30]
	strh r6, [r4, #0x32]
	strh r6, [r4, #0x34]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_08019b54
FUN_08019b54: @ 0x08019B54
	push {lr}
	adds r0, r1, #0
	adds r0, #8
	bl Particle_Remove
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019b64
FUN_08019b64: @ 0x08019B64
	push {lr}
	adds r2, r1, #0
	ldrb r0, [r2, #2]
	cmp r0, #0
	beq _08019B76
	movs r0, #0
	strb r0, [r2, #2]
	movs r0, #1
	b _08019B78
_08019B76:
	movs r0, #0
_08019B78:
	cmp r0, #0
	beq _08019B84
	ldr r0, [r2, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r2, #8]
_08019B84:
	ldr r0, [r2, #4]
	adds r0, #1
	str r0, [r2, #4]
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019b90
FUN_08019b90: @ 0x08019B90
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _08019BA2
	movs r0, #0
	strb r0, [r6, #2]
_08019BA2:
	mov r5, sp
	movs r0, #0x30
	adds r0, r0, r6
	mov ip, r0
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	mov r1, ip
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019BC8
	asrs r0, r0, #8
	b _08019BCE
_08019BC8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019BCE:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019BE0
	asrs r0, r0, #8
	b _08019BE6
_08019BE0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019BE6:
	adds r4, r0, #0
	mov r2, ip
	movs r3, #2
	ldrsh r1, [r2, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019BFC
	asrs r0, r0, #8
	b _08019C02
_08019BFC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019C02:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019C80 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	adds r5, r7, #0
	adds r5, #0x18
	mov r4, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	movs r2, #0x18
	ldrsh r1, [r7, r2]
	subs r0, r0, r1
	movs r3, #4
	ldrsh r1, [r4, r3]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #1]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	movs r3, #0x18
	ldrsh r0, [r7, r3]
	subs r2, r2, r0
	movs r1, #4
	ldrsh r0, [r4, r1]
	movs r3, #4
	ldrsh r1, [r5, r3]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r4, r0, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r1, r1, r0
	ldr r0, _08019C84 @ =0x00000FFF
	cmp r1, r0
	bls _08019C74
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019C88
_08019C74:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	b _08019CEC
	.align 2, 0
_08019C80: .4byte 0x030047C8
_08019C84: .4byte 0x00000FFF
_08019C88:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019CB4 @ =0x085B0A08
	ldrb r3, [r6, #1]
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
	cmp r0, #0
	blt _08019CB8
	asrs r0, r0, #0xc
	b _08019CBE
	.align 2, 0
_08019CB4: .4byte 0x085B0A08
_08019CB8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019CBE:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019CD6
	asrs r0, r0, #0xc
	b _08019CDC
_08019CD6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019CDC:
	adds r0, #0x50
	movs r1, #0
	strh r0, [r6, #0x22]
	strh r1, [r6, #0x24]
	ldrb r1, [r6, #1]
	movs r0, #0xa0
	subs r0, r0, r1
	strb r0, [r6, #0xf]
_08019CEC:
	ldr r0, [r6, #4]
	cmp r0, #0xb3
	bls _08019CFC
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #2]
_08019CFC:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_08019d0c
FUN_08019d0c: @ 0x08019D0C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x10
	mov r8, r0
	adds r6, r1, #0
	ldrb r0, [r6, #2]
	cmp r0, #0
	beq _08019D26
	movs r0, #0
	strb r0, [r6, #2]
	movs r0, #1
	b _08019D28
_08019D26:
	movs r0, #0
_08019D28:
	cmp r0, #0
	bne _08019D2E
	b _08019E56
_08019D2E:
	mov r5, sp
	adds r7, r6, #0
	adds r7, #0x30
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019D50
	asrs r0, r0, #8
	b _08019D56
_08019D50:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D56:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019D68
	asrs r0, r0, #8
	b _08019D6E
_08019D68:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D6E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r7, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019D82
	asrs r0, r0, #8
	b _08019D88
_08019D82:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019D88:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019E2C @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	mov r5, r8
	adds r5, #0x18
	mov r4, sp
	mov r0, sp
	movs r1, #0
	ldrsh r0, [r0, r1]
	mov r2, r8
	movs r3, #0x18
	ldrsh r1, [r2, r3]
	subs r0, r0, r1
	movs r2, #4
	ldrsh r1, [r4, r2]
	movs r3, #4
	ldrsh r2, [r5, r3]
	subs r1, r1, r2
	bl ArcTan2_8
	strb r0, [r6, #1]
	mov r0, sp
	movs r1, #0
	ldrsh r2, [r0, r1]
	mov r3, r8
	movs r1, #0x18
	ldrsh r0, [r3, r1]
	subs r2, r2, r0
	movs r3, #4
	ldrsh r0, [r4, r3]
	movs r4, #4
	ldrsh r1, [r5, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08019E30 @ =0x00000FFF
	cmp r1, r0
	bhi _08019DF6
	b _08019F08
_08019DF6:
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019E02
	b _08019F08
_08019E02:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019E34 @ =0x085B0A08
	ldrb r3, [r6, #1]
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
	cmp r0, #0
	blt _08019E38
	asrs r0, r0, #0xc
	b _08019E3E
	.align 2, 0
_08019E2C: .4byte 0x030047C8
_08019E30: .4byte 0x00000FFF
_08019E34: .4byte 0x085B0A08
_08019E38:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019E3E:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019E54
	b _08019F66
_08019E54:
	b _08019F6A
_08019E56:
	add r5, sp, #8
	adds r7, r6, #0
	adds r7, #0x30
	ldrh r0, [r6, #0x30]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	mov ip, r5
	cmp r0, #0
	blt _08019E7A
	asrs r0, r0, #8
	b _08019E80
_08019E7A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019E80:
	strh r0, [r5]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _08019E92
	asrs r0, r0, #8
	b _08019E98
_08019E92:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019E98:
	adds r4, r0, #0
	movs r3, #2
	ldrsh r1, [r7, r3]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _08019EAC
	asrs r0, r0, #8
	b _08019EB2
_08019EAC:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_08019EB2:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _08019F14 @ =0x030047C8
	ldrh r0, [r5]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r5]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r5, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r5, #4]
	add r0, sp, #8
	movs r4, #0
	ldrsh r2, [r0, r4]
	mov r1, r8
	movs r3, #0x18
	ldrsh r0, [r1, r3]
	subs r2, r2, r0
	mov r4, ip
	movs r1, #4
	ldrsh r0, [r4, r1]
	mov r3, r8
	movs r4, #0x1c
	ldrsh r1, [r3, r4]
	subs r0, r0, r1
	adds r1, r2, #0
	muls r1, r2, r1
	adds r2, r0, #0
	muls r2, r0, r2
	adds r0, r2, #0
	adds r1, r1, r0
	ldr r0, _08019F18 @ =0x00000FFF
	cmp r1, r0
	bls _08019F08
	ldr r0, [r6, #4]
	movs r1, #0x1f
	ands r0, r1
	cmp r0, #0x10
	bls _08019F1C
_08019F08:
	ldr r0, [r6, #8]
	movs r1, #1
	orrs r0, r1
	str r0, [r6, #8]
	b _08019F80
	.align 2, 0
_08019F14: .4byte 0x030047C8
_08019F18: .4byte 0x00000FFF
_08019F1C:
	ldr r0, [r6, #8]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r6, #8]
	ldr r2, _08019F48 @ =0x085B0A08
	ldrb r3, [r6, #1]
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
	cmp r0, #0
	blt _08019F4C
	asrs r0, r0, #0xc
	b _08019F52
	.align 2, 0
_08019F48: .4byte 0x085B0A08
_08019F4C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019F52:
	adds r0, #0x78
	strh r0, [r6, #0x20]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x32
	muls r0, r1, r0
	cmp r0, #0
	blt _08019F6A
_08019F66:
	asrs r0, r0, #0xc
	b _08019F70
_08019F6A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08019F70:
	adds r0, #0x50
	movs r1, #0
	strh r0, [r6, #0x22]
	strh r1, [r6, #0x24]
	ldrb r1, [r6, #1]
	movs r0, #0xa0
	subs r0, r0, r1
	strb r0, [r6, #0xf]
_08019F80:
	ldr r0, [r6, #4]
	cmp r0, #0x3b
	bls _08019F90
	movs r0, #0
	strb r0, [r6]
	str r0, [r6, #4]
	movs r0, #1
	strb r0, [r6, #2]
_08019F90:
	ldr r0, [r6, #4]
	adds r0, #1
	str r0, [r6, #4]
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity4B15_Update
Entity4B15_Update: @ 0x08019FA4
	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r6, r0, #0
	mov r1, sp
	ldr r0, _08019FDC @ =0x08251B58
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	adds r4, r6, #0
	adds r4, #0x20
	movs r5, #3
_08019FB8:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, sp
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	subs r5, #1
	adds r4, #0x38
	cmp r5, #0
	bge _08019FB8
	movs r0, #0
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_08019FDC: .4byte 0x08251B58

	thumb_func_start Entity4B15_Destroy
Entity4B15_Destroy: @ 0x08019FE0
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_08019FEA:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08019b54
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _08019FEA
	movs r1, #0
	ldr r0, _0801A008 @ =0x03000090
	str r1, [r0]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A008: .4byte 0x03000090

	thumb_func_start Entity4B15_Init
Entity4B15_Init: @ 0x0801A00C
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _0801A04C @ =0x03000090
	str r5, [r0]
	ldr r0, _0801A050 @ =0x00001C1A
	bl GetParticleGroup
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r5, r2
	str r0, [r1]
	movs r1, #0
	movs r0, #0x78
	strh r0, [r5, #0x18]
	movs r0, #0x50
	strh r0, [r5, #0x1a]
	strh r1, [r5, #0x1c]
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_0801A034:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08019af4
	adds r4, #0x38
	subs r6, #1
	cmp r6, #0
	bge _0801A034
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801A04C: .4byte 0x03000090
_0801A050: .4byte 0x00001C1A

	thumb_func_start Entity4B15_Create
Entity4B15_Create: @ 0x0801A054
	push {r4, lr}
	ldr r0, _0801A08C @ =0x03000090
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A09A
	movs r1, #0x82
	lsls r1, r1, #1
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A098
	ldr r1, _0801A090 @ =Entity4B15_Update
	ldr r2, _0801A094 @ =Entity4B15_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity4B15_Init
	cmp r0, #0
	bge _0801A098
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A09A
	.align 2, 0
_0801A08C: .4byte 0x03000090
_0801A090: .4byte Entity4B15_Update
_0801A094: .4byte Entity4B15_Destroy
_0801A098:
	adds r0, r4, #0
_0801A09A:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801a0a0
FUN_0801a0a0: @ 0x0801A0A0
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _0801A0C0 @ =0x03000090
	ldr r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801A100
	ldr r0, _0801A0C4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A0C8
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A0CC
	.align 2, 0
_0801A0C0: .4byte 0x03000090
_0801A0C4: .4byte 0x03002C68
_0801A0C8:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0801A0CC:
	cmp r0, r3
	beq _0801A100
	lsls r4, r3, #3
	subs r4, r4, r3
	lsls r4, r4, #3
	adds r4, #0x20
	ldr r2, [r2]
	adds r4, r2, r4
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
	ldr r1, [r2]
	movs r2, #0x33
	bl FUN_0822dafc
	movs r1, #1
	movs r0, #0
	strb r1, [r4]
	str r0, [r4, #4]
	strb r1, [r4, #2]
_0801A100:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_0801a108
FUN_0801a108: @ 0x0801A108
	push {r4, r5, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r0, _0801A128 @ =0x03000090
	ldr r1, [r0]
	adds r2, r0, #0
	cmp r1, #0
	beq _0801A16A
	ldr r0, _0801A12C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _0801A130
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A134
	.align 2, 0
_0801A128: .4byte 0x03000090
_0801A12C: .4byte 0x03002C68
_0801A130:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_0801A134:
	cmp r0, r3
	beq _0801A16A
	lsls r4, r3, #3
	subs r4, r4, r3
	lsls r4, r4, #3
	adds r4, #0x20
	ldr r2, [r2]
	adds r4, r2, r4
	ldr r0, [r5]
	ldr r1, [r5, #4]
	str r0, [r4, #0x30]
	str r1, [r4, #0x34]
	adds r0, r4, #0
	adds r0, #8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r2, r1
	ldr r1, [r2]
	movs r2, #0x35
	bl FUN_0822dafc
	movs r0, #2
	movs r1, #0
	strb r0, [r4]
	str r1, [r4, #4]
	movs r0, #1
	strb r0, [r4, #2]
_0801A16A:
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_0801a170
FUN_0801a170: @ 0x0801A170
	bx lr
	.align 2, 0

	thumb_func_start FUN_0801a174
FUN_0801a174: @ 0x0801A174
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov r8, r0
	adds r7, r1, #0
	movs r1, #0xa
	ldrsh r0, [r7, r1]
	mov r2, r8
	movs r3, #0x1e
	ldrsh r1, [r2, r3]
	ldrb r5, [r7, #5]
	adds r1, r1, r5
	subs r1, r0, r1
	movs r0, #0x96
	lsls r0, r0, #3
	cmp r1, r0
	ble _0801A1B8
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	movs r1, #1
	movs r4, #2
_0801A1A8:
	ldr r0, [r6]
	orrs r0, r1
	str r0, [r6]
	subs r4, #1
	adds r6, #0x28
	cmp r4, #0
	bge _0801A1A8
	b _0801A3A0
_0801A1B8:
	cmp r1, #0x18
	bgt _0801A1BE
	b _0801A2FA
_0801A1BE:
	ldrh r0, [r7, #0xa]
	subs r0, #0x18
	strh r0, [r7, #0xa]
	adds r6, r7, #0
	adds r6, #0x18
	ldr r0, [r7, #0x18]
	movs r1, #2
	rsbs r1, r1, #0
	mov sb, r1
	ands r0, r1
	str r0, [r7, #0x18]
	ldrb r0, [r7, #2]
	cmp r0, #0
	bne _0801A2AC
	movs r0, #0x18
	strb r0, [r7, #2]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	mov ip, r2
	orrs r1, r2
	str r1, [r0]
	ldrb r0, [r7, #1]
	adds r0, #1
	strb r0, [r7, #1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0801A204
	mov r3, ip
	strb r3, [r7, #1]
_0801A204:
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	ldr r5, _0801A2A0 @ =0x0203B400
	mov sl, r5
	ldr r4, _0801A2A4 @ =0x030046B8
	ldr r2, [r4]
	adds r2, #1
	ldr r3, _0801A2A8 @ =0x000003FF
	ands r2, r3
	lsls r1, r2, #1
	add r1, sl
	ldrh r1, [r1]
	mov r5, ip
	ands r1, r5
	subs r1, #4
	adds r2, #1
	ands r2, r3
	str r2, [r4]
	lsls r2, r2, #1
	add r2, sl
	ldrh r2, [r2]
	ands r2, r5
	subs r2, #4
	bl Particle_SetOffset
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl FUN_0822dafc
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	mov r5, sb
	ands r1, r5
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	orrs r1, r2
	str r1, [r0]
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r7, #8]
	ldr r2, [r7, #0xc]
	str r1, [r0, #0x18]
	str r2, [r0, #0x1c]
	b _0801A3A0
	.align 2, 0
_0801A2A0: .4byte 0x0203B400
_0801A2A4: .4byte 0x030046B8
_0801A2A8: .4byte 0x000003FF
_0801A2AC:
	subs r0, #1
	strb r0, [r7, #2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x16
	bne _0801A2E0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r6, r0
	mov r2, r8
	ldr r1, [r2, #0x28]
	movs r2, #2
	bl FUN_0822dafc
	ldrb r0, [r7, #1]
	lsls r1, r0, #2
	adds r1, r1, r0
	lsls r1, r1, #3
	adds r1, r1, r6
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r1, #0xe]
_0801A2E0:
	ldrb r0, [r7, #2]
	cmp r0, #0x14
	bne _0801A3A0
	ldrb r1, [r7, #1]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r0, r0, r6
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0801A3A0
_0801A2FA:
	movs r1, #0
	movs r0, #2
	strb r0, [r7]
	strh r1, [r7, #6]
	ldr r2, _0801A3B8 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r5, _0801A3C0 @ =0x0203B400
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #1
	ands r0, r1
	adds r0, #4
	strb r0, [r7, #3]
	adds r6, r7, #0
	adds r6, #0x18
	movs r4, #0
	movs r0, #0x10
	adds r0, r0, r7
	mov sl, r0
	movs r1, #0x13
	adds r1, r1, r7
	mov sb, r1
	adds r5, r2, #0
_0801A332:
	ldr r1, [r6]
	movs r0, #0x80
	lsls r0, r0, #2
	orrs r1, r0
	movs r0, #2
	rsbs r0, r0, #0
	ands r1, r0
	str r1, [r6]
	mov r2, r8
	ldr r1, [r2, #0x28]
	adds r0, r6, #0
	movs r2, #2
	bl FUN_0822dafc
	mov r3, r8
	ldr r0, [r3, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r6, #0xe]
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r6, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r6, #0x18]
	str r1, [r6, #0x1c]
	mov r0, sl
	adds r1, r0, r4
	movs r0, #1
	strb r0, [r1]
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _0801A3BC @ =0x000003FF
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	ldr r1, _0801A3C0 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, sb
	adds r2, r3, r4
	movs r0, #3
	ands r1, r0
	strb r1, [r2]
	adds r4, #1
	adds r6, #0x28
	cmp r4, #2
	ble _0801A332
	ldr r0, _0801A3C4 @ =0x03002BE0
	ldr r0, [r0]
	bl FUN_0807a8e0
_0801A3A0:
	ldr r0, [r7, #8]
	ldr r1, [r7, #0xc]
	str r0, [r7, #0x30]
	str r1, [r7, #0x34]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A3B8: .4byte 0x030046B8
_0801A3BC: .4byte 0x000003FF
_0801A3C0: .4byte 0x0203B400
_0801A3C4: .4byte 0x03002BE0

	thumb_func_start FUN_0801a3c8
FUN_0801a3c8: @ 0x0801A3C8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	mov sl, r0
	adds r6, r1, #0
	ldrb r0, [r6, #4]
	mov sb, r0
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #0
	mov r8, r1
_0801A3E4:
	mov r0, sb
	adds r0, #0x40
	movs r2, #0xff
	ands r0, r2
	lsls r0, r0, #1
	ldr r7, _0801A424 @ =0x085B0A08
	adds r0, r0, r7
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r7, [r4, #0x18]
	adds r0, r0, r7
	strh r0, [r4, #0x18]
	ldrh r0, [r6, #6]
	cmp r0, #0x18
	bhi _0801A43A
	lsls r0, r0, #2
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r2, _0801A424 @ =0x085B0A08
	adds r0, r0, r2
	movs r7, #0
	ldrsh r0, [r0, r7]
	lsls r0, r0, #6
	cmp r0, #0
	blt _0801A428
	asrs r1, r0, #0xc
	b _0801A42E
	.align 2, 0
_0801A424: .4byte 0x085B0A08
_0801A428:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0801A42E:
	mov r2, sl
	ldrh r0, [r2, #0x1e]
	adds r0, r0, r1
	ldrb r7, [r6, #5]
	adds r0, r0, r7
	b _0801A43E
_0801A43A:
	ldrh r0, [r4, #0x1a]
	subs r0, #0xa
_0801A43E:
	strh r0, [r4, #0x1a]
	mov r1, sb
	lsls r0, r1, #1
	ldr r2, _0801A524 @ =0x085B0A08
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	ldrb r0, [r6, #3]
	muls r0, r1, r0
	asrs r0, r0, #0xc
	ldrh r1, [r4, #0x1c]
	adds r0, r0, r1
	movs r2, #0
	mov ip, r2
	strh r0, [r4, #0x1c]
	adds r0, r6, #0
	adds r0, #0x13
	mov r7, r8
	adds r5, r0, r7
	ldrb r1, [r5]
	adds r1, #1
	strb r1, [r5]
	movs r2, #0xff
	mov r0, sp
	strb r2, [r0]
	lsls r1, r1, #0x18
	ldr r2, _0801A528 @ =0x085AA970
	adds r0, r6, #0
	adds r0, #0x10
	adds r3, r0, r7
	ldrb r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r2
	lsrs r1, r1, #0x18
	ldrh r0, [r0]
	cmp r1, r0
	blo _0801A4B6
	mov r7, ip
	strb r7, [r5]
	ldrb r0, [r3]
	adds r0, #1
	strb r0, [r3]
	mov r1, sp
	ldrb r1, [r1]
	ands r0, r1
	cmp r0, #1
	bls _0801A4A0
	mov r2, ip
	strb r2, [r3]
_0801A4A0:
	mov r7, sl
	ldr r1, [r7, #0x28]
	ldrb r2, [r3]
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
	strb r0, [r4, #0xe]
_0801A4B6:
	ldr r2, _0801A52C @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _0801A530 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A534 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	adds r1, #0x4c
	mov r2, sb
	lsls r0, r2, #0x18
	asrs r0, r0, #0x18
	adds r0, r0, r1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	mov sb, r0
	movs r7, #1
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #2
	bgt _0801A4EC
	b _0801A3E4
_0801A4EC:
	ldrh r0, [r6, #6]
	cmp r0, #0x1f
	bls _0801A514
	adds r4, r6, #0
	adds r4, #0x18
	movs r1, #1
	movs r2, #2
	mov r8, r2
_0801A4FC:
	ldr r0, [r4]
	orrs r0, r1
	str r0, [r4]
	movs r7, #1
	rsbs r7, r7, #0
	add r8, r7
	adds r4, #0x28
	mov r0, r8
	cmp r0, #0
	bge _0801A4FC
	movs r0, #0
	strb r0, [r6]
_0801A514:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801A524: .4byte 0x085B0A08
_0801A528: .4byte 0x085AA970
_0801A52C: .4byte 0x030046B8
_0801A530: .4byte 0x000003FF
_0801A534: .4byte 0x0203B400

	thumb_func_start Entity4F5C_Update
Entity4F5C_Update: @ 0x0801A538
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	movs r1, #0xee
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r5, #0x1c]
	str r1, [r5, #0x20]
	movs r7, #0
	adds r4, r5, #0
	adds r4, #0x2c
	ldr r0, _0801A568 @ =0x085AA974
	mov r8, r0
	movs r6, #2
_0801A55C:
	ldrb r0, [r4]
	cmp r0, #0
	bne _0801A56C
	adds r7, #1
	b _0801A582
	.align 2, 0
_0801A568: .4byte 0x085AA974
_0801A56C:
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	adds r1, r4, #0
	bl _call_via_r2
	ldrh r0, [r4, #6]
	adds r0, #1
	strh r0, [r4, #6]
_0801A582:
	subs r6, #1
	adds r4, #0x90
	cmp r6, #0
	bge _0801A55C
	cmp r7, #3
	bne _0801A5A4
	ldrh r0, [r5, #0x1a]
	cmp r0, #0
	beq _0801A59E
	movs r1, #0
	bl Script_ExecById
	movs r0, #0
	strh r0, [r5, #0x1a]
_0801A59E:
	adds r0, r5, #0
	bl KillEntity
_0801A5A4:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity4F5C_Destroy
Entity4F5C_Destroy: @ 0x0801A5B0
	push {r4, r5, r6, r7, lr}
	adds r0, #0x2c
	movs r1, #0
_0801A5B6:
	adds r6, r1, #1
	adds r7, r0, #0
	adds r7, #0x90
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #2
_0801A5C2:
	adds r0, r4, #0
	bl Particle_Remove
	adds r4, #0x28
	subs r5, #1
	cmp r5, #0
	bge _0801A5C2
	adds r1, r6, #0
	adds r0, r7, #0
	cmp r1, #2
	ble _0801A5B6
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start Entity4F5C_Init
Entity4F5C_Init: @ 0x0801A5E0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r7, r0, #0
	ldr r0, _0801A604 @ =0x03002BE0
	ldr r0, [r0]
	movs r1, #0xee
	lsls r1, r1, #1
	adds r5, r7, r1
	str r0, [r5]
	cmp r0, #0
	bne _0801A608
	movs r0, #1
	rsbs r0, r0, #0
	b _0801A7FA
	.align 2, 0
_0801A604: .4byte 0x03002BE0
_0801A608:
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	movs r4, #0
	strh r0, [r7, #0x1a]
	ldr r3, [r5]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r0, r2, #0x10
	movs r1, #0x96
	lsls r1, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #0x10
	ldr r1, _0801A6E4 @ =0x0000FFFF
	ands r2, r1
	orrs r2, r0
	str r2, [sp]
	ldr r0, [r3, #0x2c]
	ldr r1, [r3, #0x30]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	strh r4, [r7, #0x18]
	ldr r0, _0801A6E8 @ =0x00001C1C
	bl GetParticleGroup
	str r0, [r7, #0x24]
	ldr r0, _0801A6EC @ =0x00001C1E
	bl GetParticleGroup
	str r0, [r7, #0x28]
	adds r5, r7, #0
	adds r5, #0x2c
	mov r8, r4
	ldr r2, _0801A6F0 @ =0x030046B8
	mov sl, r2
_0801A656:
	adds r4, r5, #0
	adds r4, #0x18
	movs r0, #1
	strb r0, [r5]
	strb r0, [r5, #1]
	mov r3, sl
	ldr r0, [r3]
	adds r0, #1
	ldr r1, _0801A6F4 @ =0x000003FF
	ands r0, r1
	str r0, [r3]
	lsls r0, r0, #1
	ldr r2, _0801A6F8 @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xf
	ands r0, r1
	strb r0, [r5, #2]
	movs r3, #0
	strb r3, [r5, #3]
	mov r1, r8
	lsls r0, r1, #8
	movs r1, #3
	bl Div
	mov r3, sl
	ldr r2, [r3]
	adds r2, #1
	ldr r1, _0801A6F4 @ =0x000003FF
	ands r2, r1
	str r2, [r3]
	lsls r1, r2, #1
	ldr r3, _0801A6F8 @ =0x0203B400
	adds r1, r1, r3
	ldrh r1, [r1]
	movs r3, #0x3f
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r5, #4]
	movs r0, #0
	strh r0, [r5, #6]
	ldrb r1, [r5, #4]
	adds r2, #1
	ldr r3, _0801A6F4 @ =0x000003FF
	ands r2, r3
	mov r0, sl
	str r2, [r0]
	lsls r2, r2, #1
	ldr r3, _0801A6F8 @ =0x0203B400
	adds r2, r2, r3
	ldrh r2, [r2]
	movs r0, #0x3f
	adds r3, r5, #0
	adds r3, #8
	adds r6, r1, #0
	ands r2, r0
	adds r0, r6, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r1, _0801A6FC @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0801A700
	asrs r0, r0, #0xc
	b _0801A706
	.align 2, 0
_0801A6E4: .4byte 0x0000FFFF
_0801A6E8: .4byte 0x00001C1C
_0801A6EC: .4byte 0x00001C1E
_0801A6F0: .4byte 0x030046B8
_0801A6F4: .4byte 0x000003FF
_0801A6F8: .4byte 0x0203B400
_0801A6FC: .4byte 0x085B0A08
_0801A700:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801A706:
	strh r0, [r3]
	movs r0, #0
	strh r0, [r3, #2]
	lsls r0, r6, #1
	ldr r1, _0801A720 @ =0x085B0A08
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _0801A724
	asrs r0, r0, #0xc
	b _0801A72A
	.align 2, 0
_0801A720: .4byte 0x085B0A08
_0801A724:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0801A72A:
	strh r0, [r3, #4]
	mov r2, sl
	ldr r0, [r2]
	adds r0, #1
	ldr r3, _0801A7A8 @ =0x000003FF
	ands r0, r3
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801A7AC @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	subs r0, #0x24
	strb r0, [r5, #5]
	mov r2, sp
	ldrh r0, [r2]
	ldrh r3, [r5, #8]
	adds r0, r0, r3
	strh r0, [r5, #8]
	ldr r1, _0801A7B0 @ =0x085AA980
	mov r2, r8
	lsls r0, r2, #1
	adds r0, r0, r1
	ldr r3, [sp]
	asrs r1, r3, #0x10
	ldrh r0, [r0]
	adds r1, r1, r0
	ldrh r0, [r5, #0xa]
	adds r0, r0, r1
	strh r0, [r5, #0xa]
	mov r1, sp
	ldrh r0, [r1, #4]
	ldrh r2, [r5, #0xc]
	adds r0, r0, r2
	strh r0, [r5, #0xc]
	movs r6, #0
	movs r3, #1
	add r8, r3
	movs r0, #0x90
	adds r0, r0, r5
	mov sb, r0
_0801A77E:
	ldr r1, [r7, #0x24]
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r4, #0
	adds r1, r2, #0
	bl Particle_SetOffset
	cmp r6, #0
	bne _0801A7B4
	ldr r1, [r7, #0x24]
	adds r0, r4, #0
	movs r2, #0x1c
	bl FUN_0822dafc
	ldr r0, [r7, #0x24]
	ldrh r0, [r0, #6]
	b _0801A7C4
	.align 2, 0
_0801A7A8: .4byte 0x000003FF
_0801A7AC: .4byte 0x0203B400
_0801A7B0: .4byte 0x085AA980
_0801A7B4:
	ldr r1, [r7, #0x28]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, [r7, #0x28]
	ldrb r0, [r0, #6]
	adds r0, #1
_0801A7C4:
	strb r0, [r4, #0xe]
	ldrh r0, [r5, #8]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r0, [r5, #0xa]
	ldrh r2, [r4, #0x1a]
	adds r0, r0, r2
	strh r0, [r4, #0x1a]
	ldrh r0, [r5, #0xc]
	ldrh r3, [r4, #0x1c]
	adds r0, r0, r3
	strh r0, [r4, #0x1c]
	adds r6, #1
	adds r4, #0x28
	cmp r6, #2
	ble _0801A77E
	mov r5, sb
	mov r0, r8
	cmp r0, #2
	bgt _0801A7F0
	b _0801A656
_0801A7F0:
	movs r0, #0x9f
	lsls r0, r0, #2
	bl PlaySound_082406e0
	movs r0, #0
_0801A7FA:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start Entity4F5C_Create
Entity4F5C_Create: @ 0x0801A80C
	push {r4, lr}
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r0, #0xa
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801A844
	ldr r1, _0801A83C @ =Entity4F5C_Update
	ldr r2, _0801A840 @ =Entity4F5C_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity4F5C_Init
	cmp r0, #0
	bge _0801A844
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801A846
	.align 2, 0
_0801A83C: .4byte Entity4F5C_Update
_0801A840: .4byte Entity4F5C_Destroy
_0801A844:
	adds r0, r4, #0
_0801A846:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityFBE5_Update
EntityFBE5_Update: @ 0x0801A84C
	push {r4, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, [r4, #0x18]
	cmp r1, #7
	bhi _0801A868
	movs r0, #3
	ands r1, r0
	cmp r1, #0
	beq _0801A880
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0801A888
_0801A868:
	cmp r1, #0xf
	bhi _0801A87C
	movs r0, #3
	ands r1, r0
	cmp r1, #1
	bls _0801A880
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	b _0801A888
_0801A87C:
	cmp r1, #0x10
	bne _0801A88A
_0801A880:
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
_0801A888:
	str r0, [r4, #0x44]
_0801A88A:
	ldr r0, [r4, #0x18]
	cmp r0, #0x1e
	bne _0801A8A4
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	movs r2, #0
	str r2, [sp]
	movs r2, #0x19
	movs r3, #1
	bl MainSprite_SetAnim
_0801A8A4:
	ldr r2, [r4, #0x18]
	cmp r2, #0x59
	bls _0801A8E2
	cmp r2, #0x69
	bhi _0801A8C0
	movs r0, #3
	ands r0, r2
	cmp r0, #1
	bhi _0801A8DA
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0801A8E0
_0801A8C0:
	cmp r2, #0x7e
	bhi _0801A8D6
	movs r0, #3
	ands r0, r2
	cmp r0, #0
	bne _0801A8DA
	ldr r0, [r4, #0x44]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _0801A8E0
_0801A8D6:
	cmp r2, #0x7f
	bne _0801A8E2
_0801A8DA:
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
_0801A8E0:
	str r0, [r4, #0x44]
_0801A8E2:
	cmp r2, #0xb4
	bne _0801A900
	ldr r0, [r4, #0x44]
	movs r1, #1
	orrs r0, r1
	str r0, [r4, #0x44]
	adds r0, r4, #0
	adds r0, #0x9c
	ldr r0, [r0]
	cmp r0, #0
	beq _0801A912
	movs r1, #0
	bl Script_ExecById
	b _0801A912
_0801A900:
	adds r0, r4, #0
	adds r0, #0x3c
	adds r1, r4, #0
	adds r1, #0x1c
	bl MainSprite_AdvanceAnim
	ldr r0, [r4, #0x18]
	adds r0, #1
	str r0, [r4, #0x18]
_0801A912:
	movs r0, #0
	add sp, #4
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start EntityFBE5_Destroy
EntityFBE5_Destroy: @ 0x0801A91C
	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _0801A93C @ =FUN_0822db5c
	ldr r2, _0801A940 @ =FUN_0822aaac
	ldr r3, _0801A944 @ =MainSprite_DrawList
	movs r0, #0
	bl Video_SetDrawPasses
	adds r4, #0x3c
	adds r0, r4, #0
	bl MainSprite_Remove
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0801A93C: .4byte FUN_0822db5c
_0801A940: .4byte FUN_0822aaac
_0801A944: .4byte MainSprite_DrawList

	thumb_func_start EntityFBE5_Init
EntityFBE5_Init: @ 0x0801A948
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x2c
	adds r6, r0, #0
	ldr r0, _0801A968 @ =0x0000CB05
	ldr r1, _0801A96C @ =0x0000D3DA
	bl GetFile
	adds r2, r0, #0
	cmp r2, #0
	bne _0801A970
	movs r0, #1
	rsbs r0, r0, #0
	b _0801AA84
	.align 2, 0
_0801A968: .4byte 0x0000CB05
_0801A96C: .4byte 0x0000D3DA
_0801A970:
	adds r1, r6, #0
	adds r1, #0x1c
	adds r0, r2, #0
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4, r5}
	stm r1!, {r3, r4, r5}
	ldm r0!, {r3, r4}
	stm r1!, {r3, r4}
	adds r4, r6, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r2, #0
	bl OpenMainSpriteFile
	movs r0, #0x70
	bl VM_SeekToKeyword
	adds r7, r4, #0
	cmp r0, #0
	beq _0801A9CC
	bl Script_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0801A9C4 @ =0xFFFF0000
	ldr r1, [sp, #0x24]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x24]
	bl Script_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0801A9C8 @ =0x0000FFFF
	ldr r1, [sp, #0x24]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r4
	b _0801A9E8
	.align 2, 0
_0801A9C4: .4byte 0xFFFF0000
_0801A9C8: .4byte 0x0000FFFF
_0801A9CC:
	ldr r2, _0801AA90 @ =0xFFFF0000
	ldr r0, [sp, #0x24]
	ands r0, r2
	movs r1, #0x78
	orrs r0, r1
	ldr r1, _0801AA94 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xa0
	lsls r1, r1, #0xf
	orrs r0, r1
	str r0, [sp, #0x24]
	add r1, sp, #0x24
	ldr r0, [r1, #4]
	ands r0, r2
_0801A9E8:
	str r0, [r1, #4]
	mov r8, r1
	movs r0, #0x65
	movs r1, #0
	bl VM_GetKeywordValue
	adds r1, r6, #0
	adds r1, #0x9c
	str r0, [r1]
	movs r4, #0
	str r4, [r6, #0x18]
	adds r5, r6, #0
	adds r5, #0x3c
	ldr r3, _0801AA98 @ =0x00002011
	str r4, [sp]
	str r4, [sp, #4]
	movs r0, #0x3c
	str r0, [sp, #8]
	mov r0, r8
	str r0, [sp, #0xc]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0
	bl MainSprite_Add
	str r4, [sp]
	adds r0, r5, #0
	adds r1, r7, #0
	movs r2, #0x18
	movs r3, #1
	bl MainSprite_SetAnim
	ldr r1, _0801AA9C @ =FUN_0822e424
	ldr r2, _0801AAA0 @ =FUN_0822af38
	ldr r3, _0801AAA4 @ =FUN_0822f264
	movs r0, #0
	bl Video_SetDrawPasses
	movs r0, #2
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	movs r0, #0x1f
	str r0, [sp, #0x18]
	str r0, [sp, #0x1c]
	str r0, [sp, #0x20]
	movs r0, #3
	movs r1, #5
	add r2, sp, #0x10
	bl FUN_08002800
	movs r2, #0
	adds r4, r6, #0
	adds r4, #0xa0
	movs r1, #0x76
	adds r1, r1, r6
	mov ip, r1
	adds r5, #0x48
	adds r6, r4, #0
	ldr r1, _0801AAA8 @ =0x00001084
_0801AA60:
	lsls r0, r2, #5
	adds r3, r2, #1
	movs r2, #0xf
	adds r0, r0, r6
	adds r0, #0x1e
_0801AA6A:
	strh r1, [r0]
	subs r0, #2
	subs r2, #1
	cmp r2, #0
	bge _0801AA6A
	adds r2, r3, #0
	cmp r2, #0xf
	ble _0801AA60
	ldr r0, _0801AAAC @ =0x00006541
	mov r3, ip
	strh r0, [r3]
	str r4, [r5]
	movs r0, #0
_0801AA84:
	add sp, #0x2c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801AA90: .4byte 0xFFFF0000
_0801AA94: .4byte 0x0000FFFF
_0801AA98: .4byte 0x00002011
_0801AA9C: .4byte FUN_0822e424
_0801AAA0: .4byte FUN_0822af38
_0801AAA4: .4byte FUN_0822f264
_0801AAA8: .4byte 0x00001084
_0801AAAC: .4byte 0x00006541

	thumb_func_start EntityFBE5_Create
EntityFBE5_Create: @ 0x0801AAB0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa8
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AAEC
	ldr r1, _0801AAE4 @ =EntityFBE5_Update
	ldr r2, _0801AAE8 @ =EntityFBE5_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl EntityFBE5_Init
	cmp r0, #0
	bge _0801AAEC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AAEE
	.align 2, 0
_0801AAE4: .4byte EntityFBE5_Update
_0801AAE8: .4byte EntityFBE5_Destroy
_0801AAEC:
	adds r0, r4, #0
_0801AAEE:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_0801aaf4
FUN_0801aaf4: @ 0x0801AAF4
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	movs r0, #8
	adds r0, r0, r1
	mov sb, r0
	ldr r0, [r1, #8]
	movs r3, #2
	rsbs r3, r3, #0
	ands r0, r3
	str r0, [r1, #8]
	movs r0, #0
	mov r8, r0
	movs r6, #1
	movs r0, #1
	strb r0, [r1]
	ldr r5, _0801ABA4 @ =0x0203B400
	ldr r3, _0801ABA8 @ =0x030046B8
	ldr r0, [r3]
	adds r0, #1
	ldr r4, _0801ABAC @ =0x000003FF
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	ands r2, r6
	adds r2, #3
	ands r0, r6
	adds r2, r2, r0
	strb r2, [r1, #1]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #3
	ands r0, r2
	adds r0, #5
	ldrb r2, [r1, #1]
	subs r0, r0, r2
	asrs r0, r0, #2
	strb r0, [r1, #2]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r2, #7
	ands r0, r2
	adds r0, #1
	strb r0, [r1, #3]
	mov r2, r8
	strb r2, [r1, #4]
	mov r0, r8
	strh r0, [r1, #6]
	ldr r0, [r3]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r1, r0, #1
	adds r1, r1, r5
	ldrb r1, [r1]
	subs r1, #0x10
	mov r2, sb
	strh r1, [r2, #0x1c]
	adds r0, #1
	ands r0, r4
	str r0, [r3]
	lsls r0, r0, #1
	adds r0, r0, r5
	ldrh r0, [r0]
	movs r1, #0x7f
	ands r0, r1
	adds r0, #0xa0
	strh r0, [r2, #0x1e]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABA4: .4byte 0x0203B400
_0801ABA8: .4byte 0x030046B8
_0801ABAC: .4byte 0x000003FF

	thumb_func_start FUN_0801abb0
FUN_0801abb0: @ 0x0801ABB0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r5, r0, #0
	adds r6, r1, #0
	mov r8, r2
	adds r4, r6, #0
	adds r4, #8
	adds r1, r5, #0
	adds r1, #0x1c
	adds r0, r4, #0
	movs r2, #0x11
	bl AuxSprite_Add
	ldr r1, _0801ABF0 @ =0x085AA988
	movs r0, #3
	mov r2, r8
	ands r0, r2
	adds r0, r0, r1
	ldrb r0, [r0]
	strh r0, [r4, #0x10]
	movs r0, #1
	strb r0, [r4, #7]
	adds r0, r5, #0
	adds r1, r6, #0
	bl FUN_0801aaf4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0801ABF0: .4byte 0x085AA988

	thumb_func_start FUN_0801abf4
FUN_0801abf4: @ 0x0801ABF4
	push {lr}
	adds r0, r1, #0
	adds r0, #8
	bl AuxSprite_Remove
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity78C9_Update
Entity78C9_Update: @ 0x0801AC04
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	adds r4, r7, #0
	adds r4, #0x38
	movs r6, #0
	ldr r0, _0801ACC8 @ =0x030046B8
	mov sl, r0
	ldr r1, _0801ACCC @ =0x085B0A08
	mov sb, r1
	movs r2, #0xff
	mov r8, r2
_0801AC22:
	ldrb r0, [r4]
	cmp r0, #0
	beq _0801ACB0
	adds r5, r4, #0
	adds r5, #8
	mov r1, sl
	ldr r0, [r1]
	adds r0, #1
	ldr r1, _0801ACD0 @ =0x000003FF
	ands r0, r1
	mov r2, sl
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0801ACD4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #1
	ands r2, r0
	ldrb r1, [r4, #3]
	adds r1, r1, r2
	ldrb r0, [r4, #4]
	adds r0, r0, r1
	strb r0, [r4, #4]
	movs r3, #4
	ldrsb r3, [r4, r3]
	cmp r3, #0
	bge _0801AC5A
	rsbs r3, r3, #0
_0801AC5A:
	adds r0, r3, #0
	adds r0, #0x40
	mov r2, r8
	ands r0, r2
	lsls r0, r0, #1
	add r0, sb
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #2
	ldrsb r0, [r4, r0]
	adds r2, r1, #0
	muls r2, r0, r2
	mov r0, r8
	ands r3, r0
	lsls r0, r3, #1
	add r0, sb
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x11
	movs r1, #0x80
	lsls r1, r1, #4
	adds r0, r0, r1
	ldrb r1, [r4, #1]
	muls r1, r0, r1
	asrs r1, r1, #0xc
	asrs r2, r2, #0xc
	ldrh r0, [r5, #0x1c]
	adds r2, r2, r0
	strh r2, [r5, #0x1c]
	ldrh r0, [r5, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x14
	rsbs r1, r1, #0
	cmp r0, r1
	bgt _0801ACB0
	adds r0, r7, #0
	adds r1, r4, #0
	adds r2, r6, #0
	bl FUN_0801aaf4
_0801ACB0:
	adds r6, #1
	adds r4, #0x34
	cmp r6, #0x1f
	ble _0801AC22
	movs r0, #0
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0801ACC8: .4byte 0x030046B8
_0801ACCC: .4byte 0x085B0A08
_0801ACD0: .4byte 0x000003FF
_0801ACD4: .4byte 0x0203B400

	thumb_func_start Entity78C9_Destroy
Entity78C9_Destroy: @ 0x0801ACD8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	movs r4, #0
_0801ACE2:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0801abf4
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801ACE2
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity78C9_Init
Entity78C9_Init: @ 0x0801ACFC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r5, r6, #0
	adds r5, #0x38
	adds r0, #0x1c
	ldr r1, _0801AD28 @ =0x00002E7B
	bl Video_GetAuxSprite
	movs r4, #0
_0801AD0E:
	adds r0, r6, #0
	adds r1, r5, #0
	adds r2, r4, #0
	bl FUN_0801abb0
	adds r4, #1
	adds r5, #0x34
	cmp r4, #0x1f
	ble _0801AD0E
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801AD28: .4byte 0x00002E7B

	thumb_func_start Entity78C9_Create
Entity78C9_Create: @ 0x0801AD2C
	push {r4, lr}
	movs r1, #0xd7
	lsls r1, r1, #3
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0801AD64
	ldr r1, _0801AD5C @ =Entity78C9_Update
	ldr r2, _0801AD60 @ =Entity78C9_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity78C9_Init
	cmp r0, #0
	bge _0801AD64
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0801AD66
	.align 2, 0
_0801AD5C: .4byte Entity78C9_Update
_0801AD60: .4byte Entity78C9_Destroy
_0801AD64:
	adds r0, r4, #0
_0801AD66:
	pop {r4}
	pop {r1}
	bx r1
